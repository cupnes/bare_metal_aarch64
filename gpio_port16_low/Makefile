CFLAGS	=	-Wall -Wextra
CFLAGS	+=	-nostdinc -nostdlib -fno-builtin -c
CFLAGS	+=	-Iinclude

gpio_port16_low.bin: gpio_port16_low.elf
	aarch64-linux-gnu-objcopy -O binary $< $@

gpio_port16_low.elf: boot.o main.o
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
