#define PHY_BASE_ADDR	(0)
#define UART0_BASE	(0x09000000)
#define UART0_DR	((volatile unsigned int *)(PHY_BASE_ADDR + UART0_BASE + 0x00))

int main(void)
{
	volatile unsigned int i;

	while (1) {
		for (i = 0; i < 5000000; i++);
		*UART0_DR = 'A';
	}

	return 0;
}
