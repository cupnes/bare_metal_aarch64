#define PHY_BASE_ADDR	(0x3f000000)
#define GPIO_BASE	(0x00200000)
#define GPFSEL1		((volatile unsigned int *)(PHY_BASE_ADDR + GPIO_BASE + 0x04))
#define GPFSEL_ALT0	(0b100)
#define GPFSEL_ALT5	(0b010)
#define GPPUD		((volatile unsigned int *)(PHY_BASE_ADDR + GPIO_BASE + 0x94))
#define GPPUDCLK0	((volatile unsigned int *)(PHY_BASE_ADDR + GPIO_BASE + 0x98))
#define GPIO_TXD0	(14)
#define GPIO_PAD_WAIT	150
#define UART0_BASE	(0x00201000)
#define UART0_DR	((volatile unsigned int *)(PHY_BASE_ADDR + UART0_BASE + 0x00))
#define UART0_IBRD	((volatile unsigned int *)(PHY_BASE_ADDR + UART0_BASE + 0x24))
#define UART0_FBRD	((volatile unsigned int *)(PHY_BASE_ADDR + UART0_BASE + 0x28))
#define UART0_LCRH	((volatile unsigned int *)(PHY_BASE_ADDR + UART0_BASE + 0x2c))
#define UART0_CR	((volatile unsigned int *)(PHY_BASE_ADDR + UART0_BASE + 0x30))
#define AUX_BASE	(0x00215000)
#define AUX_ENABLES	((volatile unsigned int *)(PHY_BASE_ADDR + AUX_BASE + 0x04))
#define MU_BASE		(PHY_BASE_ADDR + 0x00215040)

struct bcm283x_mu_regs {
	unsigned int io;
	unsigned int ier;
	unsigned int iir;
	unsigned int lcr;
	unsigned int mcr;
	unsigned int lsr;
	unsigned int msr;
	unsigned int scratch;
	unsigned int cntl;
	unsigned int stat;
	unsigned int baud;
};

/* volatile unsigned int this_cpuid = (unsigned int)'0'; */

int main(void)
{
	volatile unsigned int i;
	struct bcm283x_mu_regs *mu = (struct bcm283x_mu_regs *)MU_BASE;
	char ch = 'A';

	/* this_cpuid++; */

	while (1) {
		for (i = 0; i < 5000000; i++);
		/* mu->io = this_cpuid; */
		mu->io = ch++;
		if (ch > 'Z')
			ch = 'A';
	}

	return 0;
}
