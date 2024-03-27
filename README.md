# LORA-Programming

Over-the-air programmability is an important capability for ultra-low power softwaredefined radio nodes, which allows nodes to be free of wired interfaces and accessing to a wired network. And it is critical to achieve the goal of a large-scale wide area test platform. LoRa is an ideal OTA communication protocol for ultra-low power software defined radio nodes due to its advantages of long range, low power consumption and anti-interference. LoRa's PHY layer is fixed, but the MAC layer is open. In order to propagate updates across the test bed or to specific nodes, we need to design a MAC layer for LoRa PHY and implement it on the hardware platform. At the same time, in order to minimize the power consumption of the system, the nodes need to work in intermittent mode. This project studies OTA system implementation of ultra low power software defined radio.

User-interface is the QT interface for receiver. SD_PHY is the MCU codes for receiver. 

original2.3.new is the QT interface for transmitter. LoRa_transmit is the MCU codes for transmitter. 
