# Universal-Remote-IOT
My IOT project - Internet-controlled Universal Remote.

It consists of two physical components: a NodeMCU and an Arduino Uno. The Arduino board was necessary for supplying enough voltage to the receiver and to the IR diode itself, and NodeMCU was used to connect to Wi-Fi and Google's Firebase itself.

The user would have to scan codes off of whatever remote they want (providing it does work with IR) and "program" them into the JS script provided in the HTML file.
The HTML page, along with some CSS to make it pretty and JS to make it function, is what controls the IR diode that's connected to the Arduino board. When the corresponding button is clicked, JS stores the hardcoded hex value of the button in the database. NodeMCU then grabs the value, deletes it from the database, and sends it to the Arduino board via TX-RX pins. There, the signal is cast and used via the IR diode to command whatever device the user wants.
