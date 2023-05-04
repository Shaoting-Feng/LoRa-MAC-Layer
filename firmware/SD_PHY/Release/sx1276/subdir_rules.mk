################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
sx1276/%.obj: ../sx1276/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"D:/CCS/Install/ccs/tools/compiler/ti-cgt-msp430_20.2.2.LTS/bin/cl430" -vmspx --data_model=restricted -O2 --use_hw_mpy=F5 --include_path="D:/CCS/Install/ccs/ccs_base/msp430/include" --include_path="D:/Common_File/Wireless_COM/OTA/firmware/SD_PHY2" --include_path="D:/Common_File/Wireless_COM/OTA/firmware/SD_PHY2/driverlib/MSP430FR5xx_6xx" --include_path="D:/CCS/Install/ccs/tools/compiler/ti-cgt-msp430_20.2.2.LTS/include" --advice:power="none" --advice:hw_config=all --define=__MSP430FR5969__ --define=_MPU_ENABLE --define=DEPRECATED --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="sx1276/$(basename $(<F)).d_raw" --obj_directory="sx1276" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


