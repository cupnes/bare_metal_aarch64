CFLAGS	=	-g -Wall -Wextra
CFLAGS	+=	-nostdinc -nostdlib -fno-builtin -c

uart_tx_char.bin: uart_tx_char.elf
	aarch64-linux-gnu-objcopy -O binary $< $@

uart_tx_char.elf: boot.o main.o
	aarch64-linux-gnu-ld -o $@ $+ -Map System.map -s -T sys.ld -x

boot.o: boot.S
main.o: main.c

.S.o:
	aarch64-linux-gnu-gcc $(CFLAGS) -o $@ $<
.c.o:
	aarch64-linux-gnu-gcc $(CFLAGS) -o $@ $<

clean:
	rm -f *~ *.o *.bin *.elf *.map

.PHONY: clean
