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
	    <head> <title>Informatica II</title> </head>
	    <body>
	    	<h1>Humedad y temperatura [DHT11]</h1>
	    	<div>
	    		<table border="1" bgcolor="#909090"> 
	            	<tr>
	               		<th>Pin</th><th>Value</th>
	            	</tr> %s
	            	<script type="text/javascript">
	  					function actualizar(){location.reload(true);}
  						setInterval("actualizar()",1000);
					</script>
	        	</table>
	       	</div>	       
	    </body>
	    
	</html>
	"""

	addr = socket.getaddrinfo('192.168.1.37', 80)[0][-1]

	s = socket.socket()
	s.bind(addr)
	s.listen(1)

	print('listening on', addr)

	while True:
	    cl, addr = s.accept()
	    print('client connected from', addr)
	    cl_file = cl.makefile('rwb', 0)
	    
	    time.sleep(1)

	    while True:
	        line = cl_file.readline()
	        if not line or line == b'\r\n':
	            break
		
	    flag = pin.value(not pin.value())

	    if flag :
	        rows = ['<tr><td>%s</td><td bgcolor="#FF0000">%d</td></tr>' % (str(pin), pin.value())]
	    else:
	    	rows = ['<tr><td>%s</td><td bgcolor="#00FF00">%d</td></tr>' % (str(pin), pin.value())]
	      
	    response = html % '\n'.join(rows)
	    cl.send(response)
	    cl.close()

do_connect()
http_server()