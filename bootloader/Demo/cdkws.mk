.PHONY: clean All Project_Title apt32f103x_chip apt32f103x_evb apt_console apt_csi Project_Build

All: Project_Title apt32f103x_chip apt32f103x_evb apt_console apt_csi Project_Build

Project_Title:
	@echo "----------Building project:[ Demo - BuildSet ]----------"

apt32f103x_chip:
	@make -r -f Obj/BuildSet/Packages/apt32f103x_chip/v0.0.1/Makefile -j 12 -C  ./ 

apt32f103x_evb:
	@make -r -f Obj/BuildSet/Packages/apt32f103x_evb/v0.0.1/Makefile -j 12 -C  ./ 

apt_console:
	@make -r -f Obj/BuildSet/Packages/apt_console/v0.0.0/Makefile -j 12 -C  ./ 

apt_csi:
	@make -r -f Obj/BuildSet/Packages/apt_csi/v0.0.1/Makefile -j 12 -C  ./ 


Project_Build:
	@make -r -f Demo.mk -j 12 -C  ./ 


clean:
	@echo "----------Cleaning project:[ Demo - BuildSet ]----------"

