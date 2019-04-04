PWD_DIR := ${PWD}

CORE_DIR := ${PWD}/rtl/core/
PERIPS_DIR := ${PWD}/rtl/perips/

INST_RTL_CORE := ${PWD}/../cores/cortexm0_designstart_r2p0/logical/cortexm0_integration/verilog/*.v
INST_RTL_PERIPS := ${PWD}/../logical/cmsdk*/verilog/*.v
INST_RTL_PERIPS += ${PWD}/../logical/models/clkgate/*.v
INST_RTL_PERIPS += ${PWD}/../logical/models/memories/*.v
INST_RTL_PERIPS += ${PWD}/../systems/cortex_m0_mcu/verilog/*.v
INST_RTL_PERIPS += ${PWD}/../systems/fpga_testbench/verilog/*.v

install:
	cd ${PWD}/rtl ; mkdir -p core perips soc;
	cp ${INST_RTL_CORE} ${CORE_DIR}
	cp ${INST_RTL_PERIPS} ${PERIPS_DIR}

install_fpga:
	cd ${PWD}/fpga ; mkdir -p rtl run;
	cp ${CORE_DIR}/*.v ${PWD}/fpga/rtl/
	cp ${PERIPS_DIR}/*.v ${PWD}/fpga/rtl/

clean:
	rm *.log  ${CORE_DIR} ${PERIPS_DIR} ${PWD}/fpga/rtl/*.v -rf
