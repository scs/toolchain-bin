cmd_usr/initramfs_data.o := bfin-uclinux-gcc -Wp,-MD,usr/.initramfs_data.o.d  -nostdinc -isystem /backup/uClinux/bfin-uclinux/bin/../lib/gcc/bfin-uclinux/4.1.2/include -D__KERNEL__ -Iinclude  -include include/linux/autoconf.h -D__ASSEMBLY__ -mno-fdpic -mcpu=bf537-0.2    -c -o usr/initramfs_data.o usr/initramfs_data.S

deps_usr/initramfs_data.o := \
  usr/initramfs_data.S \

usr/initramfs_data.o: $(deps_usr/initramfs_data.o)

$(deps_usr/initramfs_data.o):
