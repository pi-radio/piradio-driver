obj-m := piradio.o
KDIR := /spare/linux/
PWD := $(shell pwd)

default:
#	$(MAKE) -C $(KDIR) M=$(PWD) modules
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
install:
	#$(MAKE) -C $(KDIR) M=$(PWD) modules_install
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules_install
clean:
	#$(MAKE) -C $(KDIR) M=$(PWD) clean
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	rm -rf Module.markers module.order module.sysvers 


