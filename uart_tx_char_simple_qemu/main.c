#define PL011_UARTDR		(*(volatile unsigned int *)0x09000000)
#define PL011_UARTFR		(*(volatile unsigned int *)0x09000018)
#define PL011_UARTFR_TXFF	(1U << 5)

int main(void)
{
	while (1) {
		while (PL011_UARTFR & PL011_UARTFR_TXFF);
		PL011_UARTDR = (unsigned int)'A';
	}

	return 0;
}
