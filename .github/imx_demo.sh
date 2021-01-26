#!/bin/bash

export ARCH=arm
export CROSS_COMPILE=arm-linux-gnueabihf-

make imx_v6_v7_defconfig

make uImage LOADADDR=0x10008000 KCFLAGS=-mno-android -j6
make modules LOADADDR=0x10008000 KCFLAGS=-mno-android -j6
make dtbs LOADADDR=0x10008000 KCFLAGS=-mno-android -j6

CURRENT_DIR=$(pwd)

mkdir -p ${CURRENT_DIR}/linux_dir/images/
cp ${CURRENT_DIR}/arch/arm/boot/uImage ${CURRENT_DIR}/linux_dir/images/
cp ${CURRENT_DIR}/arch/arm/boot/zImage ${CURRENT_DIR}/linux_dir/images/

mkdir -p ${CURRENT_DIR}/linux_dir/dtbs/
cp ${CURRENT_DIR}/arch/arm/boot/dts/imx6q-sabresd.dtb ${CURRENT_DIR}/linux_dir/dtbs/
cp ${CURRENT_DIR}/arch/arm/boot/dts/imx6qp-sabresd.dtb ${CURRENT_DIR}/linux_dir/dtbs/
cp ${CURRENT_DIR}/arch/arm/boot/dts/imx6q-sabreauto.dtb ${CURRENT_DIR}/linux_dir/dtbs/
cp ${CURRENT_DIR}/arch/arm/boot/dts/imx6q-icore-mipi.dtb ${CURRENT_DIR}/linux_dir/dtbs/
cp ${CURRENT_DIR}/arch/arm/boot/dts/imx6q-gw53xx.dtb ${CURRENT_DIR}/linux_dir/dtbs/
cp ${CURRENT_DIR}/arch/arm/boot/dts/imx6q-gw560x.dtb ${CURRENT_DIR}/linux_dir/dtbs/
cp ${CURRENT_DIR}/arch/arm/boot/dts/imx6q-wandboard.dtb ${CURRENT_DIR}/linux_dir/dtbs/

mkdir -p ${CURRENT_DIR}/linux_dir/
make modules_install INSTALL_MOD_PATH=${CURRENT_DIR}/linux_dir/
