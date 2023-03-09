# W5300 TOE Examples

- [W5300 TOE Examples](#w5300-toe-examples)
  - [Overview](#overview)
  - [Directory Structure](#directory-structure)
  - [Getting Started](#getting-started)
  - [Appendix](#appendix)
    - [Datasheet](#datasheet)
    - [Other Examples](#other-examples)



<a name="overview"></a>
## Overview

The W5300 TOE examples use **W5300 TOE Shield** - ethernet I/O shield compatible with STM32 Nucleo-144 board built on WIZnet's [**W5300**][link-w5300] ethernet chip, and STM32 Nucleo-144 board.

- [**W5300 TOE Shield**][link-w5300_toe_shield]

<p align="center"><img src="https://github.com/Wiznet/W5300-TOE-C/blob/main/Static/images/w5300_toe_shield_main.png"></p>

STM32 Nucleo-144 boards support the list below.

- [**NUCLEO-F429ZI**][link-nucleo-f429zi]

And W5300 TOE Examples supports two IDEs.

**※ Please select and use the IDE according to the environment you are using.**


<table>
  <tr>
    <td align=center>Board</td>
    <td align=center>Example</td>
    <td align=center>Description</td>
  </tr>
  <tr>
    <td align=center rowspan="2">NUCLEO-F429ZI</td>
    <td align=center><a href="https://github.com/Wiznet/W5300-TOE-ARDUINO/tree/main/Ethernet/examples"><b>ARDUINO W5300</b></td>
    <td>INO-based example implemented using <a href="https://www.arduino.cc/en/software">ARDUINO IDE.</td>
  </tr>
  <tr>
    <td align=center><a href="https://github.com/Wiznet/W5300-TOE-ARDUINO/tree/main/Ethernet/examples/PlatformIO_CPP_Examples"><b>Platform IO W5300</b>
    </td>
    <td>CPP-based example implemented using <a href="https://platformio.org">PlatformIO.  
    </td>
  </tr>
</table>

<br></br>
- **ARDUINO for STM32 Project**

1. Reference: https://github.com/stm32duino/Arduino_Core_STM32/blob/main/README.md
This repo is available as a package usable with **Arduino Boards Manager**.

2. **Add this link** in the "**Additional Boards Managers URLs**" field:
https://github.com/stm32duino/BoardManagerFiles/raw/main/package_stmicroelectronics_index.json
![][link-stm-json-path]

3. Replace existing Ethernet and FMC library with this W5300 library.
  path: C:\Users\_YOUR_NAME_\AppData\Local\Arduino15\libraries
  
  ![][link-ethernet-path]

<br></br>
- **PlatformIO for STM32 Project**

1. Make PlatformIO Project for  STM32F4 Series (for example: select **NUCLEO-F429ZI** board).

2. Follow the README in the PlatformIO's directory and folder.

3. This library have to locate in lib  path.

<a name="directory_structure"></a>
## Directory Structure

```
W5300-TOE-ARDUINO
  ┃
  ┣ Etherent
  ┃   ┣ example
  ┃   ┃   ┣ LinkStatus
  ┃   ┃   ┣ ChatServer
  ┃   ┃   ┣ DhcpAddressPrinter
  ┃   ┃   ┣ UDPSendReceiveString
  ┃   ┃   ┣ AdvancedChatServer
  ┃   ┃   ┣ WebServer
  ┃   ┃   ┣ BarometricPressureWebServer
  ┃   ┃   ┗ PlatformIO_CPP_Examples (CPP Example files for PlatformIO)
  ┃   ┃
  ┃   ┗ src (W5300 ioLibrary for ARDUINO)
  ┗ FMC
  ┃   ┗ (STM32F's FMC Register Settup files)
  ┗ Static
       ┣ documents
       ┗ images
```


<a name="getting_started"></a>
## Getting Started

Please refer to [**Getting Started**][link-getting_started] for how to configure development environment or examples usage.



<a name="appendix"></a>
## Appendix



<a name="datasheet"></a>
### Datasheet

- [**W5300**][link-datasheet_w5300]
- [**W5300 TOE Shield**][link-datasheet_w5300_toe_shield]



<a name="other_examples"></a>
### Other Examples

- W5300 TOE C
    - [**W5300-TOE-C**][link-w5300-toe-C]
- W5300 TOE MicroPython
    - [**W5300-TOE-MicroPython**][link-w5300-toe-micropython]



<!--
Link
-->

[link-w5300]: https://docs.wiznet.io/Product/iEthernet/W5300
[link-w5300_toe_shield]: fill_in_the_blank
[link-nucleo-f429zi]: https://www.st.com/en/evaluation-tools/nucleo-f429zi.html
[link-getting_started]: https://github.com/Wiznet/W5300-TOE-Arduino/blob/main/Static/documents/getting_started.md
[link-datasheet_w5300]: https://docs.wiznet.io/img/products/w5300/W5300_DS_V134E.pdf
[link-datasheet_w5300_toe_shield]: fill_in_the_blank
[link-w5300-toe-C]: https://github.com/Wiznet/W5300-TOE-C
[link-w5300-toe-micropython]: https://github.com/Wiznet/W5300-TOE-MicroPython
[link-ethernet-path]: https://github.com/Wiznet/W5300-TOE-Arduino/blob/main/Static/iamges/arduino_ethernet_path.jpg
[link-stm-json-path]: https://github.com/Wiznet/W5300-TOE-Arduino/blob/main/Static/iamges/getting_started/stm_arduino_json.png
