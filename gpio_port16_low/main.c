#define GPFSEL1	0x3F200004
#define GPCLR0  0x3F200028

int main(void)
{
	*(volatile unsigned int *)GPFSEL1 = 0x01 << (3 * 6);

	*(volatile unsigned int *)GPCLR0 = 0x01 << 16;

	while (1);

	return 0;
}
