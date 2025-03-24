/*  ∎|∎ network.c | includes waiting. */

#include <Twinbeam.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/event.h>

#define BUFFER_SIZE 100

#pragma recto kevent and iocp

struct ClientContext {
  int kq;
};

int HttpClientStartup(struct ClientContext * ctxt)
{
   ctxt->kq = kqueue();
   if (ctxt->kq == -1) { return -1; }
   return 0;
}

int HttpClientCleanup(struct ClientContext * ctxt)
{
   close(ctxt->kq);
   return 0;
}

struct Invocation { int sock; };

int
HttpClientRequest(
  char * hostname,
  uint16_t port,
  char * path,
  struct ClientContext * ctxt
)
{ struct sockaddr_in server_addr;
   struct hostent * host;
   char request[512];
   
   /* Resolve the hostname. */
   host = gethostbyname(hostname); /* WSAAsyncGetHostByName */
   if (!host) { return -1; }
   
   /* Create a socket. */
   struct Invocation * inv = 
    (struct Invocation *)malloc(sizeof(struct Invocation));
   inv->sock = socket(AF_INET,SOCK_STREAM,0);
   if (inv->sock < 0) { return -2; }
   
   /* Set up the server address. */
   server_addr.sin_family = AF_INET;
   server_addr.sin_port = htons(port);
   memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);
   
   /* Connect to the server. */
   if (connect(inv->sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
      close(inv->sock);
      return -3;
   }
   
   /* Prepare the HTTP GET request. */
   snprintf(request, sizeof(request),
      "GET %s HTTP/1.1\r\n"
      "Host: %s\r\n"
      "Connection: close\r\n\r\n",
      path, hostname);
   
   /* Send the request. */
   send(inv->sock, request, strlen(request), 0);
   
   /* Set up the kevent structure to monitor the socket for readability. */
   struct kevent change;
   EV_SET(&change, inv->sock, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, inv);
   struct timespec timeout; memset(&timeout,0,sizeof(struct timespec));
   kevent(ctxt->kq,&change,1,NULL,0,&timeout);
   
   return 0;
}

int
HttpClientPoll(struct ClientContext * ctxt)
{ struct kevent fired[10];
   struct timespec timeout; memset(&timeout,0,sizeof(struct timespec));
   ssize_t bytes_received; char buffer[BUFFER_SIZE];
   int count=kevent(ctxt->kq,NULL,0,fired,10,&timeout),closed=0;
   if (count < 0) { return -1; } /* Kevent failed. */
   else if (count > 0) {
      for (int i=0; i<count; i+=1) {
         if (fired[i].filter == EVFILT_READ) {
            /* Data is ready to be read. */
            struct Invocation * inv = (struct Invocation *)(fired[i].udata);
            bytes_received = recv(inv->sock, buffer, BUFFER_SIZE-1, 0);
            if (bytes_received > 0) {
               buffer[bytes_received] = '\0'; /* Null-terminate the data. */
               printf("%s", buffer);
            } else if (bytes_received == 0) {
               /* Connection closed by the server. */
               close(inv->sock);
               free(inv);
               closed+=1;
            } else {
               /* Error in recv. */
               close(inv->sock);
               free(inv);
            }
         }
      }
   }
   return closed;
}

#pragma recto main entry point

int
main(
  int argc,
  char ** argv
)
{ int stop=0,closed=0;
   char * hostname = "example.com";
   char * path = "/";
   print("Start download '⬚⬚'...\n\n", ﹟s7(hostname),﹟s7(path));
   struct ClientContext ctxt;
   if (HttpClientStartup(&ctxt)) { exit(1); }
   if (HttpClientRequest(hostname,80,path,&ctxt)) { exit(2); }
   if (HttpClientRequest(hostname,80,path,&ctxt)) { exit(3); }
   while (!stop) {
      int y = HttpClientPoll(&ctxt);
      if (y == -1) { print("kevent failed\n"); stop=1; }
      closed+=y;
      if (closed == 2) { stop=1; }
   }
   if (HttpClientCleanup(&ctxt)) { exit(4); }
   return 0;
}

/* clang -g -I../Twinbeam/ -o network '∎|∎ network.c' \
    ../Twinbeam/Release/libTwinbeam-macos.a */

