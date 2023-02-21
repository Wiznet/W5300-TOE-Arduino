# Getting Started

These sections will guide you through a series of steps from configuring development environment to running W5300 TOE examples.

- [**Hardware Requirements**](#hardware_requirements)
- [**Development Environment Configuration**](#development_environment_configuration)
    - [**Setup ST-LINK**](#setup_st-link)
- [**Example Structure**](#example_structure)
- [**Example Testing**](#example_testing)



<a name="hardware_requirements"></a>
## Hardware Requirements

- [**W5300 TOE Shield**][link-w5300_toe_shield]
- **One of the STM32 Nucleo-144 Boards**
    - [**NUCLEO-F429ZI**][link-nucleo-f429zi]
- **Desktop or Laptop**
- **USB Type-B Micro 5 Pin Cable**

-------

<a name="hardware_requirements"></a>

# Hardware requirements

 The ethernet examples use **NUCLEO-F429ZI** build on STM32 MCU with WIZnet's [**W5300**][link-w5300] ethernet chip.
If you use other STM board, supported board of STMicroelectronics micropython in [**LIST**][link-suppoted_stm]
and check that the board supports FMC 16bit data

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

- [**Linkstatus**][link-Linkstatus]
- [**ChatServer**][link-ChatServer]
- [**AdvancedChatServer**][link-AdvancedChatServer]
- [**WebServer**][link-WebServer]
- [**BarometricPressureWebServer**][link-BarometricPressureWebServer]
- [**PlatformIO_CPP_Examples**][link-PlatformIO_CPP_Examples]


<a name="example_testing"></a>
## Example Testing

Please refer to 'README.md' in each example directory to detail guide for testing examples.



<!--
Link
-->

[link-w5300_toe_shield]: fill_in_the_blank
[link-nucleo-f429zi]: https://www.st.com/en/evaluation-tools/nucleo-f429zi.html

[link-Linkstatus]: https://github.com/Wiznet/W5300-TOE-Arduino/tree/main/Ethernet/examples/LinkStatus
[link-ChatServer]: https://github.com/Wiznet/W5300-TOE-Arduino/tree/main/Ethernet/examples/ChatServer
[link-AdvancedChatServer]: https://github.com/Wiznet/W5300-TOE-Arduino/tree/main/Ethernet/examples/AdvancedChatServer
[link-WebServer]: https://github.com/Wiznet/W5300-TOE-Arduino/tree/main/Ethernet/examples/WebServer
[link-BarometricPressureWebServer]: https://github.com/Wiznet/W5300-TOE-Arduino/tree/main/Ethernet/examples/BarometricPressureWebServer
[link-PlatformIO_CPP_Examples]: https://github.com/Wiznet/W5300-TOE-Arduino/tree/main/Ethernet/examples/PlatformIO_CPP_Examples

[link-stm_pinmap]:https://github.com/Wiznet/W5300-TOE-Arduino/blob/main/static/images/stm_pimmap.png
