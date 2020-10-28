#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"

static char up;

void stay_red() /*  set the red LED on */
{
  red_on = 1;
}

void red_off() /* set the red LED off */
{
  red_on = 0;
}

void stay_green()/* set the green LED on */
{
  green_on = 1;
}

void green_off()/* set the green LED off */
{
  green_on = 0;
}

void siren_on()/* activate the siren */
{
  double x;
  short cycles = 0;
  if(up) x += 225; /* x is 225 Hz  */
  else x += 450; /* x is 450 Hz*/
  
  x = (x / 1000) * 500;/* Converting x to kHz then into cycles */
  cycles += x;
  buzzer_set_period(cycles);
}

void buzz_off()/* Turns off buzzer */
{
  buzzer_set_period(0);
}

void siren_advance()/* alternate between toggling red & green */
{
  static char state = 0;
  switch(state)
    {
    case 0:/* state 1 green on, red off */
      /* if this doesnt work try making an update_led state that takes in the value of red and green on  */
      stay_green();
      red_off();
      up = 1;
      led_changed = 1;
      led_update();
      state++;
      break;
    case 1:/* state 2 red on, green off*/
      stay_red();
      green_off();
      up = 0;
      led_changed = 1;
      led_update();
      state = 0;
    default:
      break;
    }
}
