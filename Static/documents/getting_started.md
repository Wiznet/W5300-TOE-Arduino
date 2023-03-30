# Getting Started

These sections will guide you through a series of steps from configuring development environment to running W5300 TOE examples.

- [**Hardware Requirements**](#hardware_requirements)
- [**Development Environment Configuration**](#development_environment_configuration)
   - [**Setup ST-LINK**](#setup_st-link)
- [**Example Structure**](#example_structure)
- [**Example Testing**](#example_testing)



<a name="hardware_requirements"></a>
## Hardware Requirements

- **W5300 TOE Shield**
- **NUCLEO-F429ZI**
- **Desktop or Laptop**
- **USB Type-B Micro 5 Pin Cable**
-
* Currently, W5300 TOE examples only support NUCLEO-F429ZI.

## Pin Diagram

**`STM32F429ZI`**
This document is based on STM32F429ZI. If you use other STM board, Please edit it to your HW configuration.
![][link-stm_pinmap]
 - FMC Data pin (0-8 or 0-16)
 - FMC Address pin (0-10)
 - FMC Control GPIO pin (NE, NWE, NOE)
 - WIZChip Control GPIO pin (INT, RST)
 - UART3 pin(connect to ST-LINK) 
  -- Be changed for use the FMC on the Nucleoboard. Pin D8,D9 -> Pin C10,C11

------

**※ Currently, W5300 TOE examples only support NUCLEO-F429ZI, so please refer to this.**



<a name="development_environment_configuration"></a>
## Development Environment Configuration



<a name="setup_st-link"></a>
### Setup ST-LINK

The ST-LINK pin was changed due to overlapping use of the FMC(Flexible Memory controller) data pin to control the W5300 built in the W5300 TOE Shield and the ST-LINK pin of the STM32 Nucleo-144 board.

- STLK_RX[STM32F103CBT6_PA3] : PD8 → **PC10**
- STLK_TX[STM32F103CBT6_PA2] : PD9 → **PC11**

Therefore, in order to use the ST-LINK of the STM32 Nucleo-144 board, minor settings are required for the W5300 TOE Shield and STM32 Nucleo-144 board.

1. Remove SB5 and SB6 from the top of the STM32 Nucleo-144 board.

<p align="center"><img src="https://github.com/Wiznet/W5300-TOE-Arduino/blob/main/Static/images/getting_started/stm32_nucleo-144_board_sb5_sb6.png"></p>

2. With the W5300 TOE Shield and STM32 Nucleo-144 board combined, connect PC10, PC11 of the W5300 TOE Shield and CN5 TX, RX of the top of the STM32 Nucleo-144 board with jumper cables.

- W5300 TOE Shield : **PC10** - STM32 Nucleo-144 board : **RX**
- W5300 TOE Shield : **PC11** - STM32 Nucleo-144 board : **TX**

3. Modify STM32 packages' variants code for Serial
-  ARDUINO:"C:\Users\Eric\AppData\Local\Arduino15\packages\STMicroelectronics\hardware\stm32\2.4.0\variants\STM32F4xx\F427Z(G-I)T_F429ZET_F429Z(G-I)(T-Y)_F437Z(G-I)T_F439Z(G-I)(T-Y)"

- PlatformIO: "C:\Users\_YOUR_NAME_\ .platformio\packages\framework-arduinoststm32\variants\STM32F4xx\F427Z(G-I)T_F429ZET_F429Z(G-I)(T-Y)_F437Z(G-I)T_F439Z(G-I)(T-Y)\variant_NUCLEO_F429ZI.h"

  <br>#define PIN_SERIAL_RX           **PC11**
  <br>#define PIN_SERIAL_TX           **PC10**

<p align="center"><img src="https://github.com/Wiznet/W5300-TOE-Arduino/blob/main/Static/images/getting_started/stm32_nucleo-144_board_cn5_tx_rx.png"></p>



<a name="example_structure"></a>
## Example Structure

- [**AdvancedChatServer**][link-AdvancedChatServer]
- [**DNS**][link-DNS]
- [**DhcpAddressPrinter**][link-DhcpAddressPrinter]
- [**NTPClient**][link-NTPClient]
- [**UDP_Loopback**][link-UDP_Loopback]
- [**WebServer**][link-WebServer]


<a name="example_testing"></a>
##  How to use W5300 TOE shield in Arduino IDE
This article is a guide on how to use the W5300 TOE Shield with the Arduino IDE, specifically with the STM32 Nucleo-F429ZI board. In this article, we will provide a step-by-step tutorial on how to configure the Arduino IDE

### Step1. Add additonal boards manager URLs
 To access the "Additional Boards Manager URLs" in the Arduino IDE, [File] -> [Preferences].
you can find the option to add a new URL by copying and pasting the [Additional Board Manager URLs]
>https://github.com/stm32duino/BoardManagerFiles/raw/main/package_stmicroelectronics_index.json

<p align="center"><img src="https://github.com/Wiznet/W5300-TOE-Arduino/blob/main/Static/images/getting_started/stm_arduino_json.png"></p>


### Step2. Add libraryes
 To copy the **Ethernet** and **FMC** folders from the repository, paste them into the [Arduino15] directory on your computer.
 *The location depending on the PC environment
>C:\Users_YOUR_NAME_\AppData\Local\Arduino15\libraries

<p align="center"><img src="https://github.com/Wiznet/W5300-TOE-Arduino/blob/main/Static/images/getting_started/copy_to_lib.png"></p>

###Step3. Install the Library and Change Board to Nucleo-144
Install the **STM32core** library through the board manager
[Tools] -> [Board] -> [Board Manager...] -> serching [STM32] -> install [STM32 Cores]

<p align="center"><img src="https://github.com/Wiznet/W5300-TOE-Arduino/blob/main/Static/images/getting_started/arduino_stm32core_setting.png"></p>

Then change the board to Necleo-144.
[Tools] -> [Board] -> [STM32 Boards] => [Necleo-144]

<p align="center"><img src="https://github.com/Wiznet/W5300-TOE-Arduino/blob/main/Static/images/getting_started/arduino_necleo_setting.png"></p>

###step4. Make an Arduino sketch
Once you have completed the above steps, you can find examples for the Nucleo-144 in the Examples section of the Arduino IDE. To confirm that Ethernet is functioning.

<p align="center"><img src="https://github.com/Wiznet/W5300-TOE-Arduino/blob/main/Static/images/getting_started/arduino_select_example.png"></p>


<!--
Link
-->

[link-w5300_toe_shield]: fill_in_the_blank
[link-nucleo-f429zi]: https://www.st.com/en/evaluation-tools/nucleo-f429zi.html

[link-AdvancedChatServer]: https://github.com/Wiznet/W5300-TOE-Arduino/tree/main/Ethernet/examples/AdvancedChatServer
[link-DNS]: https://github.com/Wiznet/W5300-TOE-Arduino/tree/main/Ethernet/examples/DNS
[link-DhcpAddressPrinter]: https://github.com/Wiznet/W5300-TOE-Arduino/tree/main/Ethernet/examples/DhcpAddressPrinter
[link-NTPClient]: https://github.com/Wiznet/W5300-TOE-Arduino/tree/main/Ethernet/examples/NTPClient
[link-UDP_Loopback]: https://github.com/Wiznet/W5300-TOE-Arduino/tree/main/Ethernet/examples/UDP_Loopback
[link-WebServer]: https://github.com/Wiznet/W5300-TOE-Arduino/tree/main/Ethernet/examples/WebServer

[link-stm_pinmap]:https://github.com/Wiznet/W5300-TOE-Arduino/blob/main/static/images/stm_pimmap.png
