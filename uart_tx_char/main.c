#define PHY_BASE_ADDR	(0x3f000000)
#define AUX_BASE	(0x00215000)
#define AUX_ENABLES	((volatile unsigned int *)(PHY_BASE_ADDR + AUX_BASE + 0x04))
#define MU_BASE		(PHY_BASE_ADDR + 0x00215040)
#define MU_LSR_TX_IDLE	(1U << 6)
#define MU_LSR_TX_EMPTY	(1U << 5)

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

int main(void)
{
	volatile struct bcm283x_mu_regs *mu = (struct bcm283x_mu_regs *)MU_BASE;
	char ch = 'A';

	while (1) {
		while (!(mu->lsr && MU_LSR_TX_IDLE) && !(mu->lsr && MU_LSR_TX_EMPTY));
		mu->io = ch++;
		if (ch > 'Z')
			ch = 'A';
	}

	return 0;
}
