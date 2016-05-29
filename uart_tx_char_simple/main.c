#define MU_IO		(*(volatile unsigned int *)0x3f215040)
#define MU_LSR		(*(volatile unsigned int *)0x3f215054)
#define MU_LSR_TX_IDLE	(1U << 6)
#define MU_LSR_TX_EMPTY	(1U << 5)

int main(void)
{
	while (1) {
		while (!(MU_LSR & MU_LSR_TX_IDLE) && !(MU_LSR & MU_LSR_TX_EMPTY));
		MU_IO = (unsigned int)'A';
	}

	return 0;
}
