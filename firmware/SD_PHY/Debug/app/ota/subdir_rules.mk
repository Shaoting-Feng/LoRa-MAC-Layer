################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
app/ota/%.obj: ../app/ota/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/TI/ccs1020/ccs/tools/compiler/ti-cgt-msp430_20.2.2.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="D:/TI/CCS10_FR5969/SD_PHY/system" --include_path="D:/TI/CCS10_FR5969/SD_PHY" --include_path="C:/TI/ccs1020/ccs/ccs_base/msp430/include" --include_path="D:/TI/CCS10_FR5969/SD_PHY/app/ota" --include_path="D:/TI/CCS10_FR5969/SD_PHY/sx1276" --include_path="D:/TI/CCS10_FR5969/SD_PHY/utils" --include_path="D:/TI/CCS10_FR5969/SD_PHY" --include_path="D:/TI/CCS10_FR5969/SD_PHY/driverlib/MSP430FR5xx_6xx" --include_path="C:/TI/ccs1020/ccs/tools/compiler/ti-cgt-msp430_20.2.2.LTS/include" --advice:power="none" --advice:hw_config=all --define=__MSP430FR5969__ --define=_MPU_ENABLE --define=DEPRECATED -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="app/ota/$(basename $(<F)).d_raw" --obj_directory="app/ota" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


