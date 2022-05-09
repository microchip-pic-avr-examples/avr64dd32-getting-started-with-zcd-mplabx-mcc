<!-- Please do not change this html logo with link -->

<a href="https://www.microchip.com" rel="nofollow"><img src="images/microchip.png" alt="MCHP" width="300"/></a>

# Zero-Cross Detector (ZCD) in Two Different Modes Using the AVR64DD32 Microcontroller Generated with MCC Melody

<br>The repository contains two MPLAB® X projects:

1.  [Free-Running Mode](#1-free-running-mode) – This example shows how to use the ZCD to detect when the zero value of an analog signal is reached.
2.  [AC Signal Frequency Detection](#2-ac-signal-frequency-detection) – This example describes how to use the ZCD together with a timer to measure the pulse duration and/or the
period of analog signals with minimal intervention of the CPU.


## Related Documentation

More details and code examples on the AVR64DD32 can be found at the following links:

- [AVR64DD32 Product Page](https://www.microchip.com/wwwproducts/en/AVR64DD32)
- [AVR64DD32 Code Examples on GitHub](https://github.com/microchip-pic-avr-examples?q=AVR64DD32)
- [AVR64DD32 Project Examples in START](https://start.atmel.com/#examples/AVR64DD32CuriosityNano)

## Software Used

- [MPLAB® X IDE](http://www.microchip.com/mplab/mplab-x-ide) v6.00 or newer
- [MPLAB® XC8](http://www.microchip.com/mplab/compilers) v2.36 or newer
- [AVR-Dx Series Device Pack](https://packs.download.microchip.com/) v2.0.152 or newer

## Hardware Used

- The AVR64DD32 Curiosity Nano Development board is used as a test platform
  <br><img src="images/AVR64DD32.PNG" width="500">

## Operation

To program the Curiosity Nano board with this MPLAB® X project, follow the steps provided in the [How to Program the Curiosity Nano Board](#how-to-program-the-curiosity-nano-board) chapter.<br><br>

## 1. Free-Running Mode

This example shows how to use the ZCD to detect when the zero value of an analog signal is reached (e.g., the zero-cross of the Alternating Current (AC) mains electricity).

### 1.1 Setup


<br>The following configurations must be made for this project:

<br>ZCD:
 - Enable the ZCD
 - Enable the output of the ZCD

| Pin          | Configuration                                         |
| :----------: | :---------------------------------------------------: |
|  PA7         | Digital output                                        |
|  PC2         | ZCD input interrupt and digital input buffer disabled |

### 1.2 Demo


<br>ZCD_OUT is represented by channel 1 (orange) and ZCD_IN by channel 3 (blue), in the screenshot below.
<br><img src="images/AVR-DA_ZCD_use_case_1_results.png" width="800">

### 1.3 Summary

This code example shows how to configure the ZCD to detect when the zero value of an analog signal is reached.<br><br>
[Back to top](#zero-cross-detector-zcd-in-two-different-modes-using-the-avr64dd32-microcontroller-generated-with-mcc-melody)<br>

## 2. AC Signal Frequency Detection

This example describes how to use the ZCD together with a timer to measure the pulse duration and/or the period of analog signals with minimal intervention of the CPU. To enable frequency measurement, the Timer/Counter type B (TCB) is configured in Frequency Measurement mode, having the Event System (EVSYS) as input, which is used to route the ZCD0 output through event channel 0 to the TCB event input. In the Input Capture Frequency Measurement mode, the TCB captures the counter value and restarts on either a positive or negative edge of the event input signal. The CAPT Interrupt flag is automatically cleared after the low byte of the Compare/Capture (TCBn.CCMP) register has been read. An OVF interrupt and event is generated when the CNT reaches maximum value.

### 2.1 Setup

<br>The following configurations must be made for this project:

<br>TCB0:
 - Input capture frequency
 - Event input enable: enabled
 - Capture or timeout: enabled
 - CLK_PER/2 (from prescaler)
 - TCB enabled
 - Run Standby: enabled

<br>EVSYS:
 - ZCD0 output is linked to event channel 0
 - TCB uses event channel 0

<br>ZCD:
 - Enable the ZCD
 - Enable the output of the ZCD

|  Pin         | Configuration                                          |
| :----------: | :----------------------------------------------------: |
|  PA7         | Digital output                                         |
|  PC2         | ZCD input; interrupt and digital input buffer disabled |

<br><img src="images/AC Signal Frequency Measurement.png" width="800">


### 2.2 Summary

This code example shows how to configure the ZCD and TCB peripherals to implement a frequency detection measurement.<br><br>
[Back to top](#zero-cross-detector-zcd-in-two-different-modes-using-the-avr64dd32-microcontroller-generated-with-mcc-melody)<br>


## How to Program the Curiosity Nano Board

This chapter demonstrates how to use the MPLAB® X IDE to program an AVR® device with an Example_Project.X. This can be applied for any other projects.

1.  Connect the board to the PC.

2.  Open the Example_Project.X project in MPLAB® X IDE.

3.  Set the Example_Project.X project as main project.
    <br>Right click the project in the **Projects** tab and click **Set as Main Project**.
    <br><img src="images/Program_Set_as_Main_Project.PNG" width="800">

4.  Clean and build the Example_Project.X project.
    <br>Right click the **Example_Project.X** project and select **Clean and Build**.
    <br><img src="images/Program_Clean_and_Build.PNG" width="800">

5.  Select the **AVRxxxxx Curiosity Nano** in the Connected Hardware Tool section of the project settings:
    <br>Right click the project and click **Properties**.
    <br>Click the arrow under the Connected Hardware Tool.
    <br>Select **AVRxxxxx Curiosity Nano** (click the **SN**), click **Apply** and then **OK**:
    <br><img src="images/Program_Tool_Selection.PNG" width="800">

6.  Program the project to the board.
    <br>Right click on the project and then **Make and Program Device**.
    <br><img src="images/Program_Make_and_Program_Device.PNG" width="800">

    <br>

- [Back to 1. Free Running Mode](#1-free-running-mode)
- [Back to 2. AC Signal Frequency Detection](#2-ac-signal-frequency-detection)
- [Back to top](#zero-cross-detector-zcd-in-two-different-modes-using-the-avr64dd32-microcontroller-generated-with-mcc-melody)
