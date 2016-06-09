all:
	aarch64-linux-gnu-as -o start.o start.S
	aarch64-linux-gnu-gcc -Wall -Wextra -c -o main.o main.c
	aarch64-linux-gnu-ld -Ttext 0x40080000 -o out.elf start.o main.o
	aarch64-linux-gnu-objcopy -O binary out.elf out.img
	qemu-system-aarch64 -cpu cortex-a57 -M virt -kernel out.img
