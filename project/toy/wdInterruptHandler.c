#include <msp430.h>
#include "stateMachines.h"
#include "buzzer.h"
void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char count = 0;
  /* TODO use sb to determine what interrupt to do. Maybe use a switch statement?*/
  if ((++count % 25) == 0) siren_on();
  if (++count == 250)
    {
      siren_advance();
      count = 0;
    }
}
