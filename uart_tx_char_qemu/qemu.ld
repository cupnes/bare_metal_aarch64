SECTIONS
{
	. = 0x40080000;
	.text	: {*(.text*)}
	.rodata	: {
		*(.strings*)
		*(.rodata*)
		*(.rodata.*)
	}
	.data	: {*(.data*)}
	.bss	: {*(.bss*)}
}
