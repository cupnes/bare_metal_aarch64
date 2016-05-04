## How to use

compile and run `qemu-system-aarch64`.

	[PC]$ cd uart_tx_char_qemu
	[PC]$ make
	[PC]$ qemu-system-aarch64 -cpu cortex-a57 -M virt -kernel uart_tx_char.bin
