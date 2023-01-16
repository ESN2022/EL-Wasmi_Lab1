#include "sys/alt_stdio.h"
#include "system.h"
#include "altera_avalon_pio_regs.h"

int main()
{
  alt_putstr("main led chaser with pooling !\n");
  while (IORD_ALTERA_AVALON_PIO_DATA(PUSH_BASE) == 1);
  while (1)
  {

    int speed = IORD_ALTERA_AVALON_PIO_DATA(SWITCH_BASE);


    for (int i = 0; i < 8; i++)
    {

      IOWR_ALTERA_AVALON_PIO_DATA(LEDS_BASE, 1 << i);
      speed = IORD_ALTERA_AVALON_PIO_DATA(SWITCH_BASE);

      usleep( speed*50000);
      while (IORD_ALTERA_AVALON_PIO_DATA(PUSH_BASE) == 0);
    }

  }

  return 0;
}
