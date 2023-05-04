################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"D:/CCS/Install/ccs/tools/compiler/ti-cgt-msp430_20.2.2.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="D:/Common_File/Wireless_COM/OTA/firmware/SD_PHY2/system" --include_path="D:/Common_File/Wireless_COM/OTA/firmware/SD_PHY2/app" --include_path="D:/Common_File/Wireless_COM/OTA/firmware/SD_PHY2" --include_path="D:/CCS/Install/ccs/ccs_base/msp430/include" --include_path="D:/Common_File/Wireless_COM/OTA/firmware/SD_PHY2/app/ota" --include_path="D:/Common_File/Wireless_COM/OTA/firmware/SD_PHY2/sx1276" --include_path="D:/Common_File/Wireless_COM/OTA/firmware/SD_PHY2/utils" --include_path="D:/Common_File/Wireless_COM/OTA/firmware/SD_PHY2" --include_path="D:/Common_File/Wireless_COM/OTA/firmware/SD_PHY2/driverlib/MSP430FR5xx_6xx" --include_path="D:/CCS/Install/ccs/tools/compiler/ti-cgt-msp430_20.2.2.LTS/include" --advice:power="none" --advice:hw_config=all --define=__MSP430FR5969__ --define=DEPRECATED --define=_MPU_ENABLE -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


