TARGET=kernel8
CROSS=aarch64-linux-gnu-
CFLAGS=-c -Wall -Wextra
OBJS=start.o main.o
STEXT=0x80000

$(TARGET).img: $(TARGET).elf
	$(CROSS)objcopy -O binary $< $@
$(TARGET).elf: $(OBJS)
	$(CROSS)ld -Ttext $(STEXT) -o $(TARGET).elf $+
.S.o:
	$(CROSS)as -o $@ $<
.c.o:
	$(CROSS)gcc $(CFLAGS) -o $@ $<

clean:
	rm -f *~ *.o *.bin *.elf *.map

.PHONY: clean
