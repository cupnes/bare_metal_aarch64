#define DR	(*(volatile unsigned int *)0x09000000)
#define FR	(*(volatile unsigned int *)0x09000018)

void put_char(char ch)
{
	while (FR & (1U << 5));
	DR = (unsigned int)ch;
}

void put_str(char *str)
{
	while (*str != '\0')
		put_char(*str++);
}

int main(void)
{
	put_str("Hello world!");
	while (1);
	return 0;
}
