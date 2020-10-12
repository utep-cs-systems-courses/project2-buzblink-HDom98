#include <msp430.h>
#include "stateMachines.h"
#include "buzzer.h"
void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  if (++blink_count <= 4) {
    //buzzer_set_period(1000);
    stay_red();
    red_off();
    //blink_count = 0;
  }else if (++blink_count == 125)
    {
      buzzer_set_period(1000);
      stay_red();
      red_off();
      blink_count = 0;
    }
}
