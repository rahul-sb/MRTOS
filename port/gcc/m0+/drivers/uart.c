#include <stddef.h>

#include "drivers/port_rcc.h"
#include "drivers/gpio.h"
#include "drivers/port_uart.h"

typedef volatile struct __attribute__((__packed__)) {
  uint8_t UE     : 1;
  uint8_t UESM   : 1;
  uint8_t RE     : 1;
  uint8_t TE     : 1;
  uint8_t IDLEIE : 1;
  uint8_t RXNEIE : 1;
  uint8_t TCIE   : 1;
  uint8_t TXEIE  : 1;
  uint8_t PEIE   : 1;
  uint8_t PS     : 1;
  uint8_t PCE    : 1;
  uint8_t WAKE   : 1;
  uint8_t M0     : 1;
  uint8_t MME    : 1;
  uint8_t CMIE   : 1;
  uint8_t OVER8  : 1;
  uint8_t DEDT   : 5;
  uint8_t DEAT   : 5;
  uint8_t RTOIE  : 1;
  uint8_t EOBIE  : 1;
  uint8_t M1     : 1;
  uint8_t _reserved : 3;
} USARTx_CR1_t;

typedef volatile struct __attribute__((__packed__)) {
  uint8_t _reserved1 : 4;
  uint8_t ADDM7    : 1;
  uint8_t LBDL     : 1;
  uint8_t LBDIE    : 1;
  uint8_t _reserved2 : 1;
  uint8_t LBCL     : 1;
  uint8_t CPHA     : 1;
  uint8_t CPOL     : 1;
  uint8_t CLKEN    : 1;
  uint8_t STOP     : 2;
  uint8_t LINEN    : 1;
  uint8_t SWAP     : 1;
  uint8_t RXINV    : 1;
  uint8_t TXINV    : 1;
  uint8_t DATAINV  : 1;
  uint8_t MSBFIRST : 1;
  uint8_t ABREN    : 1;
  uint8_t ABRMOD   : 2;
  uint8_t RTOEN    : 1;
  uint8_t ADD      : 8;
} USARTx_CR2_t;

typedef volatile struct __attribute__((__packed__)) {
  uint8_t EIE      : 1;
  uint8_t IREN     : 1;
  uint8_t IRLP     : 1;
  uint8_t HDSEL    : 1;
  uint8_t NACK     : 1;
  uint8_t SCEN     : 1;
  uint8_t DMAR     : 1;
  uint8_t DMAT     : 1;
  uint8_t RTSE     : 1;
  uint8_t CTSE     : 1;
  uint8_t CTSIE    : 1;
  uint8_t ONEBIT   : 1;
  uint8_t OVRDIS   : 1;
  uint8_t DDRE     : 1;
  uint8_t DEM      : 1;
  uint8_t DEP      : 1;
  uint8_t _reserved1 : 1;
  uint8_t SCARCNT  : 3;
  uint8_t WUS      : 2;
  uint8_t WUFIE    : 1;
  uint16_t _reserved2 : 9;
} USARTx_CR3_t;

typedef volatile struct __attribute__((__packed__)) {
  uint8_t PSC : 8;
  uint8_t GT  : 8;
  uint16_t _reserved : 16;
} USARTx_GTPR_t;

typedef volatile struct __attribute__((__packed__)) {
  uint32_t RTO  : 24;
  uint8_t  BLEN : 7;
} USARTx_RTOR_t;

typedef volatile struct __attribute__((__packed__)) {
  uint8_t ABRRQ : 1;
  uint8_t SBKRQ : 1;
  uint8_t MMRQ  : 1;
  uint8_t RXFRQ : 1;
  uint8_t TXFRQ : 1;
  uint32_t _reserved : 27;
} USARTx_RQR_t;

typedef volatile struct __attribute__((__packed__)) {
  uint8_t PE     : 1;
  uint8_t FE     : 1;
  uint8_t NF     : 1;
  uint8_t ORE    : 1;
  uint8_t IDLE   : 1;
  uint8_t RXNE   : 1;
  uint8_t TC     : 1;
  uint8_t TXE    : 1;
  uint8_t LBDF   : 1;
  uint8_t CTSIF  : 1;
  uint8_t CTS    : 1;
  uint8_t RTOF   : 1;
  uint8_t EOBF   : 1;
  uint8_t _reserved1 : 1;
  uint8_t ABRE   : 1;
  uint8_t ABRF   : 1;
  uint8_t BUSY   : 1;
  uint8_t CMF    : 1;
  uint8_t SBKF   : 1;
  uint8_t RWU    : 1;
  uint8_t WUF    : 1;
  uint8_t TEACK  : 1;
  uint8_t REACK  : 1;
  uint16_t _reserved2 : 9;
} USARTx_ISR_t;

typedef volatile struct __attribute__((__packed__)) {
  uint8_t PECF    : 1;
  uint8_t FECF    : 1;
  uint8_t NCF     : 1;
  uint8_t ORECF   : 1;
  uint8_t IDLECF  : 1;

  uint8_t _reserved1 : 1;

  uint8_t TCCF    : 1;

  uint8_t _reserved2 : 1;

  uint8_t LBDCF   : 1;
  uint8_t CTSCF   : 1;

  uint8_t _reserved3 : 1;

  uint8_t RTOCF   : 1;
  uint8_t EOBCF   : 1;

  uint8_t _reserved4 : 4;

  uint8_t CMCF    : 1;

  uint8_t _reserved5 : 2;

  uint8_t WUCF    : 1;

  uint16_t _reserved6 : 11;
} USARTx_ICR_t;



typedef volatile struct __attribute__((__packed__)) {
  USARTx_CR1_t USARTx_CR1;
  USARTx_CR2_t USARTx_CR2;
  USARTx_CR3_t USARTx_CR3;

  uint16_t     USARTx_BRR;
  uint16_t     _reserved1;

  USARTx_GTPR_t USARTx_GTPR;

  USARTx_RTOR_t USARTx_RTOR;

  USARTx_RQR_t USARTx_RQR;
  USARTx_ISR_t USARTx_ISR;
  USARTx_ICR_t USARTx_ICR;

  uint8_t USARTx_RDR;
  uint8_t _reserved2;
  uint8_t _reserved3;
  uint8_t _reserved4;

  uint8_t USARTx_TDR;
  uint8_t _reserved5;
  uint8_t _reserved6;
  uint8_t _reserved7;
} USARTx_t;

// @TODO: Use more than just UART1
static USARTx_t volatile * const USART1 = (USARTx_t volatile * const)(0x40013800);
// Pin B6  = USART1_TX (AF0)
// Pin B7  = USART1_RX (AF0)
// Pin A8  = USART1_CK (AF4)
// Pin A9  = USART1_TX (AF4)
// Pin A10 = USART1_RX (AF4)

static USARTx_t volatile * const USART2 = (USARTx_t volatile * const)(0x40004400);

void uart_init() {
  // Enable USART1 clock
  RCC->RCC_APB2ENR |= (1 << 14);

  // Set USART1 clock to system clock
  RCC->RCC_CCIPR &= ~(0x3);
  RCC->RCC_CCIPR |= 0x1;

  // Set TX and RX as pullup and AF4
  // TX
  gpio_set_mode(GPIOA, 9, GPIO_OUTPUT_MODE);
  gpio_set_pull(GPIOA, 9, GPIO_PULLUP);
  gpio_set_alt_func(GPIOA, 9, GPIO_AF4);
  // RX
  gpio_set_mode(GPIOA, 10, GPIO_INPUT_MODE);
  gpio_set_pull(GPIOA, 10, GPIO_PULLUP);
  gpio_set_alt_func(GPIOA, 10, GPIO_AF4);

  // USART CK
  gpio_set_mode(GPIOA, 8, GPIO_OUTPUT_MODE);
  gpio_set_alt_func(GPIOA, 8, GPIO_AF4);

  // Set word length (USARTx_CR1)
  USART1->USARTx_CR1.M1 = 0;
  USART1->USARTx_CR1.M0 = 0;

  // Disable parity
  USART1->USARTx_CR1.PCE = 0;

  // Set baud rate (USARTx_BRR)
  // Setting to 9600
  USART1->USARTx_BRR = 0xD05;

  // Set number of stop bits (USARTx_CR2)
  USART2->USARTx_CR2.STOP = 0x00;

  // Enable USART (write UE bit in USARTx_CR1 to 1)
  USART1->USARTx_CR1.UE = 1;
}

void uart_send(uint8_t* data, size_t len) {
  size_t cnt = 0;

  while (cnt < len) {
    // Set TE bit in UARTx_CR1 to send an idle frame as first transmission
    USART1->USARTx_CR1.TE = 1;

    while (!USART1->USARTx_ISR.TEACK)
      ;

    // Write data to send in USARTx_TDR
    USART1->USARTx_TDR = *data;

    data++;
    cnt++;
  }

  // Wait for TC = 1
  while (!USART1->USARTx_ISR.TC)
    ;
}
