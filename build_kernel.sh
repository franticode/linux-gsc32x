
export ARCH=arm
export CROSS_COMPILE=arm-linux-gnueabihf-

if [ "$1" = "plus" ]; then
	#plus
	echo "****************** build imx6q plus ******************"
	cd arch/arm/boot/dts
	cp imx6qp-topeet_10.1inch.dts topeet_10.1inch.dts
	cp imx6qp-topeet_7inch.dts topeet_7inch.dts
	cp imx6qp-topeet_9.7inch.dts topeet_9.7inch.dts
	cd -
else
	#6q
	echo "****************** build imx6q ******************"
	cd arch/arm/boot/dts
	cp imx6q-topeet_10.1inch.dts topeet_10.1inch.dts
	cp imx6q-topeet_7inch.dts topeet_7inch.dts
	cp imx6q-topeet_9.7inch.dts topeet_9.7inch.dts
	cd -
fi

make imx_v7_linux_defconfig

make uImage LOADADDR=0x10008000 KCFLAGS=-mno-android -j4

make modules LOADADDR=0x10008000 KCFLAGS=-mno-android

make dtbs LOADADDR=0x10008000 KCFLAGS=-mno-android
