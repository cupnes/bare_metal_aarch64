	.globl	_start
_start:
	mov	sp, #0x80000

	bl	main

	b	.
