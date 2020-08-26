html = """<!DOCTYPE html>
	<html>
	    <head> <title>Pi4IoT</title> </head>
	    <body> 
	      <h1>ESP8266 - Pi4IoT</h1>
	        <table border="1" bgcolor="#909090"> 
	            <tr>
	                <th>Pin</th><th>Value</th>
	            </tr>
	            <tr>
	            	%s 
	            </tr>
	        </table>
	    </body>
	    
	</html>
	"""
print(html)

rows = ['<td>%s</td> <td bgcolor="#FF0000">%d</td>' % ("Pin2", True)]	

response = html % '\n'.join(rows)

print(response)
