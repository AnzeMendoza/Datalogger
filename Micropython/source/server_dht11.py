import network
import socket
import time 
from dht import DHT11
from machine import Pin

def do_connect():
	wlan = network.WLAN(network.STA_IF)
	wlan.active(True)
	wlan.connect('Anze', 'franquito')
	time.sleep(3)
	data_wlan = wlan.ifconfig()
	return (data_wlan[0])

def do_connect_AC():
	wlan = network.WLAN(network.AP_IF)
	wlan.active(True)
	time.sleep(3)
	data_wlan = wlan.ifconfig()
	return (data_wlan[0])

def configDHT11():
	d = DHT11(Pin(14))
	return d

def http_server(d, ip_server):
	html =  """<!DOCTYPE html>
					<html>
					    <head> <title>H y T</title>
					    	<script type="text/javascript">
								setInterval("my_function();",15000); 
								function my_function(){window.location = location.href;}
							</script>
					    </head>

					    <body> 
					      <h1>Humedad y temperatura DHT11</h1>
						  
						    <table border="1" bgcolor="#909090"> 
					            <tr>
					                <th>Temperatura</th><th>Humedad</th><th>contador</th>
					            </tr>
					            <tr>
					            	%s
					            </tr>
					  		</table>
					    </body>
					    
					</html>
			"""

	addr = socket.getaddrinfo(ip_server, 80)[0][-1]

	s = socket.socket()
	s.bind(addr)
	s.listen(3)
	count = 0
	print('listening on', addr)

	while True:
	   	cl, addr = s.accept() #cliente addres
	   	print('client connected from', addr)
	   	cl_file = cl.makefile('rwb', 0)
	   	count += 1
	   	d.measure()
	   	time.sleep(2)

	   	rows = ['<td>%d</td><td>%d</td><td>%d</td>' % (d.temperature(),d.humidity(), count)]
		response = html % '\n'.join(rows)
		cl.send(response)
		time.sleep(5)
		cl.close()

if __name__ == "__main__":
	data_sensor = configDHT11()
	ip_server = do_connect_AC()
	http_server(data_sensor, ip_server)
