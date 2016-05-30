#define PL011_UARTDR		(*(volatile unsigned int *)0x09000000)
#define PL011_UARTFR		(*(volatile unsigned int *)0x09000018)
#define PL011_UARTFR_TXFF	(1U << 5)
#define PL011_UARTFR_RXFE	(1U << 4)

int main(void)
{
	volatile char ch;

	while (1) {
		while (PL011_UARTFR & PL011_UARTFR_RXFE);
		ch = (char)PL011_UARTDR;

		while (PL011_UARTFR & PL011_UARTFR_TXFF);
		PL011_UARTDR = (unsigned int)ch;
	}

	return 0;
}
