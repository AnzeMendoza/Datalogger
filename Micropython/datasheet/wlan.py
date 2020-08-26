import network
from machine import Pin
import socket
import time 


def do_connect():
	wlan = network.WLAN(network.STA_IF)
	wlan.active(True)
	wlan.connect('Anze', 'franquito2011')
	print(wlan.ifconfig())

def http_server():
	pin = Pin(2, Pin.OUT)

	html = """<!DOCTYPE html>
	<html>
	    <head> <title>Pi4IoT</title> </head>
	    <body> 
	      <h1>ESP8266 - Pi4IoT</h1>
	        <table border="1" bgcolor="#909090"> 
	            <tr>
	                <th>Pin</th><th>Value</th>
	            </tr> %s 
	        </table>
	    </body>
	    
	</html>
	"""

	addr = socket.getaddrinfo('192.168.1.39', 80)[0][-1]

	s = socket.socket()
	s.bind(addr)
	s.listen(1)

	print('listening on', addr)

	while True:
	    cl, addr = s.accept()
	    print('client connected from', addr)
	    cl_file = cl.makefile('rwb', 0)
	    while True:
	        line = cl_file.readline()
	        if not line or line == b'\r\n':
	            break

	    time.sleep(1)

	    if not pin.value():        
	        rows = ['<tr><td>%s</td><td bgcolor="#FF0000">%d</td></tr>' % (str(pin), pin.value())]
	    else:
	        rows = ['<tr><td>%s</td><td bgcolor="#00FF00">%d</td></tr>' % (str(pin), pin.value())]
	      
	    response = html % '\n'.join(rows)
	    cl.send(response)
		time.sleep(3)
	    cl.close()