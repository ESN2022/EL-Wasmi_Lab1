#include "sys/alt_stdio.h"
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_irq.h"

int speed = 50000;
int led = 0;
int chaser_state=0 ;

static void irqhandler_push_button(void* context);
static void irqhandler_switch(void* context);
int main()
{
    alt_putstr("main started\n");
    IOWR_ALTERA_AVALON_PIO_IRQ_MASK(PUSH_BASE, 0b1);
    IOWR_ALTERA_AVALON_PIO_IRQ_MASK(SWITCH_BASE, 0b1111);
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PUSH_BASE, 0x0);
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(SWITCH_BASE, 0x0);
    alt_ic_isr_register(PUSH_IRQ_INTERRUPT_CONTROLLER_ID, PUSH_IRQ, (void*)irqhandler_push_button, NULL, NULL);
    alt_ic_isr_register(SWITCH_IRQ_INTERRUPT_CONTROLLER_ID, SWITCH_IRQ, (void*)irqhandler_switch, NULL, NULL);


    while (1) {

        if (chaser_state){

            IOWR_ALTERA_AVALON_PIO_DATA(LEDS_BASE, (1 << led));
            led = (led + 1) % 8;
        }
        usleep(speed);
    }
    return 0;
}

static void irqhandler_push_button(void* context)
{
    alt_putstr("push button interruption\n");

    	chaser_state = !chaser_state;
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PUSH_BASE, 0x0);
}

static void irqhandler_switch(void* context)
{
    alt_putstr("switch interuption\n");
    speed = IORD_ALTERA_AVALON_PIO_DATA(SWITCH_BASE) * 50000;
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(SWITCH_BASE, 0x0);
}
