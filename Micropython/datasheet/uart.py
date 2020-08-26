from machine import UART

def uart0Inic():
	uart0 = UART(0, 115200)
	uart0.init(115200, bits=8, parity=None, stop=1)