/*  七².cpp | utanpåliggande verk i klar 'epoxy', röd mepps och vävt band. */

import Pic32mzda;

/* alias mips-cc='../../mips-tools/11.0.1/clang-11'; 
mips-cc @ccargs_mz -o 七 -DSHA1GIT=`git log -1 '--pretty=format:%h'` '🥽 七.cpp'
*/

namespace one₋to₋seven { auxiliary, 
  deca₋hour, hour, sexa₋minute, minute, sexa₋second, second 
};

/*                                                                 
             ⑴    ⑵    ⑶       ⑷   ⑸       ⑺    ⑻              
           ┌─┬─┐ ┌─┬─┐ ┌─┬─┐   ┌─┬─┐ ┌─┬─┐   ┌─┬─┐ ┌─┬─┐            
           │╲│╱│ │╲│╱│ │╲│╱│ ╽ │╲│╱│ │╲│╱│ ╽ │╲│╱│ │╲│╱│            
           ├─┼─┤ ├─┼─┤ ├─┼─┤   ├─┼─┤ ├─┼─┤   ├─┼─┤ ├─┼─┤            
           │╱│╲│ │╱│╲│ │╱│╲│ ╿ │╱│╲│ │╱│╲│ ╿ │╱│╲│ │╱│╲│            
           └─┴─┘ └─┴─┘ └─┴─┘   └─┴─┘ └─┴─┘   └─┴─┘ └─┴─┘            
                           ﹙𝟷𝟷﹚          ⑼                         
                                                                    
      ┌─────╥─────┐                                                 
      │ ╲   ║   | │                                                 
      │─ ╲ ─║─ | ─│                                                 
      │   ╲ ║ |   │                                                 
      ╞═════╬═════╡                                                 
      │   ╱ ║ ╲   │                                                 
      │─ ╱ ─║─ ╲ ─│                                                 
      │ ╱   ║   ╲ │                                                 
      ┕─────╨─────┘                                                 
                                                                    
 */

int flank(int one₋to₋seven, int one₋to₋eleven) { return 0; }
int linear(int one₋to₋seven, int one₋to₋eleven) { return 0; }
int upvector₋classic₋traditional() { return 0; }               ﹙𝟷𝟷﹚

𝟄₋int₁ local₋irqTimer1₋8fpc₋ticktock() { bye 0; }
𝟄₋int₁ local₋irqExtern1₋8fpc₋halleffect() { bye 0; }

struct { int32_t irq₋unfound=0; } panel₂;

extern "C" void Isr()
{
  Interrupt curr₋Ɀ = 🔎IRQ() & PIC32MZDA_INTSTAT_SIRQ_8̄;
  int32_t ﹟irq = (int32_t)curr₋Ɀ; 𝟄₋int₁::Waiver reference;
  if (Scheduler::Process(﹟irq,&reference)) { PULT💡(panel₂.irq₋unfound); }
  Resume(reference.address());
}

int
main(
  int argc, 
  const char * argv[]
)
{ ᵗᵚⁱⁿᵝᵉᵃᵐInit(101); Scheduler::Init();
   auto node₋alloc = ^(int bytes) { return Alloc(bytes); };
   if (Incubate(&err₋irqTimer1,Timer1,node₋alloc) { return 1; }
   if (Incubate(&err₋irqExtern1,ExternalInt0,node₋alloc) { return 1; }
   𝟄₋int₁ err₋irqTimer1 = co₋await local₋irqTimer1₋8fpc₋ticktock();
   𝟄₋int₁ err₋irqExtern1 = co₋await local₋irqExtern1₋8fpc₋halleffect();
   while (1) { wait; }
   return 0;
}


