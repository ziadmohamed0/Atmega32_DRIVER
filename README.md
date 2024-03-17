<h1>Driver Atmega32 .</h1>
<h3>Eng : Ziad Mohammed Fathi </h3>
<p>
Description : 
  1 _ App folder : this folder is a Main Program -> 
                                                    1. Main_Prog.c -> Application.
                                                    2. Main_Iniit.h -> All includes of The layer underneath.
  
  2 _ Hall folder : this folder is a External peripherals -> 
                  1_ Led Folder : This folder has an LED interface (Functions To Control Leds).
                                                    1. Led_Prog.c -> Fanctions Definations.
                                                    2. Led_Iniit.h -> Fanctions Declarations , All includes of The layer underneath.

  3_ Mcal folder : this folder is a Internal peripherals -> 
                  1_ Dio Folder : This folder has an All Address And interface of digital input & Output pins.
                                                    1. dio_Prog.c -> Fanctions Definations . 
                                                    2. dio_Iniit.h -> Fanctions Declarations , Macros (Status , Directions) of Pins & Ports , All includes of The layer underneath. 
                                                    3. dio_Reg.h -> Address of Digital in/outputs Registers. 
  4 _ Serv folder : this folder is a Serves Files -> 
                                                    1. Bit_Math.c -> Macros o Bit Math (Set , Clear , Toggle , Get).
                                                    2. Std_Types.h -> To make the code more readable.
</p>
