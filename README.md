# DesktopLigthFixture

This is the code for the Desktop Light Fixture project.

The code is written in the Arduino IDE and it is intended for an Arduino
mini pro board. This board does not contain a FTDI chip to convert the UART 
port of the ATMEGA 328P controller into a 232 serial bus. An additional FTDI232 
breakout board is needed. A an AVR MKII ICSP can be used also connecting the SPI
like this to the board:

	11: MOSI
	12: MISO
	13: SCK
