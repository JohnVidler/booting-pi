
ARMGNU ?= arm-none-eabi

COPS = -Wall -O2 -nostdlib -nostartfiles -ffreestanding 

gcc : booting_pi.hex booting_pi.bin

all : gcc

clean :
	rm -f *.o
	rm -f *.bin
	rm -f *.hex
	rm -f *.elf
	rm -f *.list
	rm -f *.img

vectors.o : vectors.s
	$(ARMGNU)-as vectors.s -o vectors.o

video.o: video.c
	$(ARMGNU)-gcc $(COPS) -c video.c -o video.o

booting_pi.o : booting_pi.c
	$(ARMGNU)-gcc $(COPS) -c booting_pi.c -o booting_pi.o

booting_pi.elf : memmap vectors.o video.o booting_pi.o
	$(ARMGNU)-ld vectors.o video.o booting_pi.o -T memmap -o booting_pi.elf
	$(ARMGNU)-objdump -D booting_pi.elf > booting_pi.list

booting_pi.bin : booting_pi.elf
	$(ARMGNU)-objcopy booting_pi.elf -O binary booting_pi.bin

booting_pi.hex : booting_pi.elf
	$(ARMGNU)-objcopy booting_pi.elf -O ihex booting_pi.hex
