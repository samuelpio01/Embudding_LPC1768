Setting up Keil
1) Download Keil MDK - v5
2) Open Keil
3) Select Project->Manage->Pack Installer
	- Select Board and search for LPC1768
	- On the right half of this same page, on TAB Device specific you will see Install option, this means it is set to install
	- Click

![Alt text](https://github.com/hosamanisachin/IOT_VIsual-Studio-Code/blob/IOT/Debugg_window.png)
*Debugg_window.jpg*
![Alt text](https://github.com/hosamanisachin/IOT_VIsual-Studio-Code/blob/IOT/Debugg_window.png)
*Debugg_window.jpg*

-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------

Writing a program
1) Create new project
2) Make a new folder and name the project and save
3) Select the device -> Arm Cortex M3
Note: Once this is setup either an option to add startup file will pop-up, if not then keep reading else skip to step 5
4) Select Project->Manage->Manage Run-Time Environment
	- Select CMSIS and tick mark CORE
	- Select Device and select startup (If we are using GPIO ports then select GPIO)
	- And similarly select whichever parts of the ARM kits you will be using, as it will get its driver files while compiling.
Note: If you have external header files to be added to the project keep reading, else skip to step 6
5)	Right click Source Group 1-> Manage Project Items
	- Add files
	- Files -> core_cm3.c, LP17xx.h, system_LPC17xx.core_cm3
	- Click Add
	- Click ok
6) New file -> Write your code
NOTE: These all comes under source group 1 branch in keil
6a) Option - Target-> Create hex file should be marked.
7) Compile -> Resolve all errors and warning if any
8) Create HEX file




-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------

You can power the board through USB/Adatper supply. 
Connect DB-9 cable to J5/first RS-232 prot on the board.
NOTE: We have multiple set-up's(half-duplex/full-duplex) if normal config does not work, then use only Tx,Rx,Gnd pin of the RS-232 cable
and connect to respective pins of the board's RS-232 interface.
To test if the cable is working fine, short tx and rx pins and open putty/terminal(select the appropriate COM port and baud rate
and test by entering keyboard inputs on the putty console.


Open Flash magic(during installation it might have asked to select if NXP drivers are needed, select this option)
1) Select device LPC1768
2) Select COM
3) Set baud rate between 9600 to 38400
4) Browse to the directory where .hex file is present
4a) Press SW2 and SW3 simulatneously on the board while powered ON, release SW3 first then SW2, this gets the board into flashing mode.
5) Select verify after programming and hit Start
NOTE: If it says Error:Verifying There is a difference in the Hex file value and the stored value.(address 0x000000040).
This means some memory location could not be read, please make a note of that memory location and at the top left corner of
Flash magic we have Erase memory block option. Check which memory location did this error arise for and select/highligh that option and 
hit start.
5a) At the bottom a message indicating the progress will be shown and once completed it will show Finished.
6) Press SW3 - reset the boards and the program is runnning.

[img]