##
## Auto Generated makefile by CDK
## Do not modify this file, and any manual changes will be erased!!!   
##
## BuildSet
ProjectName            :=Demo
ConfigurationName      :=BuildSet
WorkspacePath          :=./
ProjectPath            :=./
IntermediateDirectory  :=Obj
OutDir                 :=$(IntermediateDirectory)
User                   :=luhy
Date                   :=30/08/2023
CDKPath                :=D:/C-Sky/CDK
ToolchainPath          :=D:/C-Sky/CDKRepo/Toolchain/XTGccElfNewlib/V2.6.1/R/
LinkerName             :=riscv64-unknown-elf-gcc
LinkerNameoption       :=
SIZE                   :=riscv64-unknown-elf-size
READELF                :=riscv64-unknown-elf-readelf
CHECKSUM               :=crc32
SharedObjectLinkerName :=
ObjectSuffix           :=.o
DependSuffix           :=.d
PreprocessSuffix       :=.i
DisassemSuffix         :=.asm
IHexSuffix             :=.ihex
BinSuffix              :=.bin
ExeSuffix              :=.elf
LibSuffix              :=.a
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
ElfInfoSwitch          :=-hlS
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
UnPreprocessorSwitch   :=-U
SourceSwitch           :=-c 
ObjdumpSwitch          :=-S
ObjcopySwitch          :=-O ihex
ObjcopyBinSwitch       :=-O binary
OutputFile             :=$(ProjectName)
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=Demo.txt
MakeDirCommand         :=mkdir
LinkOptions            :=   -nostartfiles  -Wl,--gc-sections  -T../board/gcc_flash.ld  -mabi=ilp32e -mtune=e902 -march=rv32ecxtheadse 
LinkOtherFlagsOption   :=   
IncludePackagePath     :=
IncludeCPath           :=$(IncludeSwitch)../components/chip/include $(IncludeSwitch)../components/chip/drivers/sys $(IncludeSwitch)../board/include $(IncludeSwitch)../components/console/include $(IncludeSwitch)../components/csi/include $(IncludeSwitch)../components/csi/include/core $(IncludeSwitch)../components/csi/include/drv  $(IncludeSwitch)include $(IncludeSwitch). $(IncludeSwitch)src/include/  
IncludeAPath           :=$(IncludeSwitch)../components/chip/include $(IncludeSwitch)../components/chip/drivers/sys $(IncludeSwitch)../board/include $(IncludeSwitch)../components/console/include $(IncludeSwitch)../components/csi/include $(IncludeSwitch)../components/csi/include/core $(IncludeSwitch)../components/csi/include/drv  $(IncludeSwitch)include $(IncludeSwitch). $(IncludeSwitch)src/include/  
Libs                   := -Wl,--start-group $(LibrarySwitch)_103tkey_c_0_90 $(LibrarySwitch)apt32f103x_chip $(LibrarySwitch)apt32f103x_evb $(LibrarySwitch)apt_console $(LibrarySwitch)apt_csi  -Wl,--end-group  
ArLibs                 := 
PackagesLibPath        :=$(LibraryPathSwitch)../components/chip/drivers 
LibPath                :=$(LibraryPathSwitch)Obj  $(PackagesLibPath) 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       :=riscv64-unknown-elf-ar rcu
CXX      :=riscv64-unknown-elf-g++
CC       :=riscv64-unknown-elf-gcc
AS       :=riscv64-unknown-elf-gcc
OBJDUMP  :=riscv64-unknown-elf-objdump
OBJCOPY  :=riscv64-unknown-elf-objcopy
CXXFLAGS := $(PreprocessorSwitch)USE_APT32F103X_CHIP $(PreprocessorSwitch)USE_APT32F103X_EVB $(PreprocessorSwitch)USE_APT_CONSOLE $(PreprocessorSwitch)USE_APT_CSI $(PreprocessorSwitch)USE_SDK_103X  -O1  -g3  -Wall  -ffunction-sections -Wno-unused-function -Og  -g  -Wall  -ffunction-sections -nostdlib -Wpointer-arith -Wl,-EL -fdata-sections -fdata-sections -g $(PreprocessorSwitch)CONFIG_ARCH_INTERRUPTSTACK=2048 $(PreprocessorSwitch)CONFIG_DEBUG_MODE=1 $(PreprocessorSwitch)CONFIG_KERNEL_NONE=1 $(PreprocessorSwitch)CONFIG_SUPPORT_TSPEND=1   -mabi=ilp32e -mtune=e902 -march=rv32ecxtheadse   -Os  -g  -Wall  -ffunction-sections  -fdata-sections 
CFLAGS   := $(PreprocessorSwitch)USE_APT32F103X_CHIP $(PreprocessorSwitch)USE_APT32F103X_EVB $(PreprocessorSwitch)USE_APT_CONSOLE $(PreprocessorSwitch)USE_APT_CSI $(PreprocessorSwitch)USE_SDK_103X  -O1  -g3  -Wall  -ffunction-sections -Wno-unused-function -Og  -g  -Wall  -ffunction-sections -nostdlib -Wpointer-arith -Wl,-EL -fdata-sections -fdata-sections -g $(PreprocessorSwitch)CONFIG_ARCH_INTERRUPTSTACK=2048 $(PreprocessorSwitch)CONFIG_DEBUG_MODE=1 $(PreprocessorSwitch)CONFIG_KERNEL_NONE=1 $(PreprocessorSwitch)CONFIG_SUPPORT_TSPEND=1   -mabi=ilp32e -mtune=e902 -march=rv32ecxtheadse   -Os  -g  -Wall  -ffunction-sections  -fdata-sections 
ASFLAGS  := $(PreprocessorSwitch)USE_APT32F103X_CHIP $(PreprocessorSwitch)USE_APT32F103X_EVB $(PreprocessorSwitch)USE_APT_CONSOLE $(PreprocessorSwitch)USE_APT_CSI $(PreprocessorSwitch)USE_SDK_103X  -Wa,--gdwarf2 -Wa,--gdwarf2 $(PreprocessorSwitch)CONFIG_ARCH_INTERRUPTSTACK=2048 $(PreprocessorSwitch)CONFIG_DEBUG_MODE=1 $(PreprocessorSwitch)CONFIG_KERNEL_NONE=1 $(PreprocessorSwitch)CONFIG_SUPPORT_TSPEND=1   -mabi=ilp32e -mtune=e902 -march=rv32ecxtheadse   -Wa,--gdwarf2 


Objects0=$(IntermediateDirectory)/src_bootloader$(ObjectSuffix) $(IntermediateDirectory)/src_main$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all
all: $(IntermediateDirectory)/$(OutputFile)

$(IntermediateDirectory)/$(OutputFile):  $(Objects) Always_Link 
	$(LinkerName) $(OutputSwitch) $(IntermediateDirectory)/$(OutputFile)$(ExeSuffix) $(LinkerNameoption) -Wl,-Map=$(ProjectPath)/Lst/$(OutputFile).map  @$(ObjectsFileList)  $(LinkOptions) $(LibPath) $(Libs) $(LinkOtherFlagsOption)
	-@mv $(ProjectPath)/Lst/$(OutputFile).map $(ProjectPath)/Lst/$(OutputFile).temp && $(READELF) $(ElfInfoSwitch) $(ProjectPath)/Obj/$(OutputFile)$(ExeSuffix) > $(ProjectPath)/Lst/$(OutputFile).map && echo ====================================================================== >> $(ProjectPath)/Lst/$(OutputFile).map && cat $(ProjectPath)/Lst/$(OutputFile).temp >> $(ProjectPath)/Lst/$(OutputFile).map && rm -rf $(ProjectPath)/Lst/$(OutputFile).temp
	$(OBJCOPY) $(ObjcopySwitch) $(ProjectPath)/$(IntermediateDirectory)/$(OutputFile)$(ExeSuffix)  $(ProjectPath)/Obj/$(OutputFile)$(IHexSuffix) 
	$(OBJDUMP) $(ObjdumpSwitch) $(ProjectPath)/$(IntermediateDirectory)/$(OutputFile)$(ExeSuffix)  > $(ProjectPath)/Lst/$(OutputFile)$(DisassemSuffix) 
	@echo size of target:
	@$(SIZE) $(ProjectPath)$(IntermediateDirectory)/$(OutputFile)$(ExeSuffix) 
	@echo -n checksum value of target:  
	@$(CHECKSUM) $(ProjectPath)/$(IntermediateDirectory)/$(OutputFile)$(ExeSuffix) 
	@$(ProjectName).modify.bat $(IntermediateDirectory) $(OutputFile)$(ExeSuffix) 

Always_Link:


##
## Objects
##
$(IntermediateDirectory)/src_bootloader$(ObjectSuffix): src/bootloader.c  
	$(CC) $(SourceSwitch) src/bootloader.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/src_bootloader$(ObjectSuffix) -MF$(IntermediateDirectory)/src_bootloader$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/src_bootloader$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/src_bootloader$(PreprocessSuffix): src/bootloader.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/src_bootloader$(PreprocessSuffix) src/bootloader.c

$(IntermediateDirectory)/src_main$(ObjectSuffix): src/main.c  
	$(CC) $(SourceSwitch) src/main.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/src_main$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/src_main$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/src_main$(PreprocessSuffix): src/main.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/src_main$(PreprocessSuffix) src/main.c


-include $(IntermediateDirectory)/*$(DependSuffix)
