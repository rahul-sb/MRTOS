#include "rcc.h"
#include "vector.h"

extern unsigned _stack;
extern unsigned _data_loadaddr, _data, _edata, _ebss;
extern void timer_handler(void);

void blocking_handler(void);
void null_handler(void);
void hard_fault_handler(void);
void main(void);

void  __attribute__ ((interrupt ("IRQ"))) reset_handler(void);

__attribute__ ((section(".vectors")))
vector_table_t vector_table = {
  .initial_sp_value = &_stack,
  .reset = reset_handler,
  .nmi = null_handler,
  .hard_fault = hard_fault_handler,
  .sv_call = null_handler,
  .pend_sv = null_handler,
  .systick = null_handler,
  .IRQ = {
    blocking_handler, // 0
    blocking_handler, // 1
    blocking_handler, // 2
    blocking_handler, // 3
    blocking_handler, // 4
    blocking_handler, // 5
    blocking_handler, // 6
    blocking_handler, // 7
    blocking_handler, // 8
    blocking_handler, // 9
    blocking_handler, // 10
    blocking_handler, // 11
    blocking_handler, // 12
    blocking_handler, // 13
    blocking_handler, // 14
    blocking_handler, // 15
    blocking_handler, // 16
    blocking_handler, // 17
    blocking_handler, // 18
    timer_handler    // 19
  }
};

void  __attribute__ ((interrupt ("IRQ"))) reset_handler(void)
{
  volatile unsigned *src, *dest;

  for (src = &_data_loadaddr, dest = &_data; dest < &_edata; src++, dest++) {
    *dest = *src;
  }

  while (dest < &_ebss) {
    *dest++ = 0;
  }

  rcc_hsi16_enable();
  rcc_switch_sys_clk(SYSCLK_HSI16);


  main();

  while (1);
}

void  __attribute__ ((interrupt ("IRQ"))) blocking_handler(void) {
  while (1);
}

void  __attribute__ ((interrupt ("IRQ"))) null_handler(void) {

}

void  __attribute__ ((interrupt ("IRQ"))) hard_fault_handler(void) {
  while (1);
}

void set_irq_handler(IRQn_t IRQn, vector_table_entry_t handler) {
  vector_table.IRQ[IRQn] = handler;
}
