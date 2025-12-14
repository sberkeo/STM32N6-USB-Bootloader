
STM32N6 USB DFU Bootloader Package
=================================

This package provides a production-ready USB DFU bootloader
for STM32N6 series microcontrollers.

Features:
- USB DFU firmware update
- No ST-Link required
- CRC validation
- Safe application jump
- Recovery mode

Flash Layout:
Bootloader: 0x08000000 - 0x0801FFFF
Application: 0x08020000+
