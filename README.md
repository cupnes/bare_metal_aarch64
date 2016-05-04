# Bare Metal Samples (AArch64)

## Set up the Raspberry Pi 3

### Upgrade all the VideoCore firmware

download `firmware_armstub.zip`,

- https://github.com/raspberrypi/firmware/issues/579#issuecomment-205525205

uncompress and upgrade.

	[PC]$ unzip firmware_armstub.zip
	[PC]$ sudo mount /dev/mmcblk0p1 /mnt/tmp
	[PC]$ sudo cp firmware_armstub/* /mnt/tmp/

## Where to get a compiler

### from Linaro

- https://releases.linaro.org/components/toolchain/binaries/latest-5/aarch64-linux-gnu/

### from APT

	[PC]$ sudo apt-get install gcc-aarch64-linux-gnu

## How to use

compile, copy config.txt and *.bin to microSD.

	[PC]$ cd <sample_source_dir>
	[PC]$ make
	[PC]$ sudo cp ocnfig.txt /mnt/tmp/
	[PC]$ sudo cp *.bin /mnt/tmp/kernel8.img

## Reference

- https://github.com/swarren/rpi-3-aarch64-demo
