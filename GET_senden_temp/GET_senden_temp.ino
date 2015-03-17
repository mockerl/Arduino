#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
// if you don't want to use DNS (and reduce your sketch size)
// use the numeric IP instead of the name for the server:
IPAddress server(10, 0, 0, 20);  // numeric IP for Google (no DNS)
//char server[] = "localhost";    // name address for Google (using DNS)

// Set the static IP address to use if the DHCP fails to assign
IPAddress ip(10, 0, 0, 43);

// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
EthernetClient client;
int data;
String text;
void setup() {
	Serial.begin(9600);
	delay(1000);
}

void loop()
{
	data = analogRead(5);
	Serial.println(data);
	send(data);
	delay(1000);
}


void send(int temp)
{
	text = String(temp)+"";
	if (Ethernet.begin(mac) == 0) {
		Serial.println("Failed to configure Ethernet using DHCP");
		// no point in carrying on, so do nothing forevermore:
		// try to congifure using IP address instead of DHCP:
		Ethernet.begin(mac, ip);
	}
	// give the Ethernet shield a second to initialize:
	delay(1000);
	Serial.println("connecting...");

	// if you get a connection, report back via serial:
	if (client.connect(server, 80)) {
		Serial.println("connected");
		// Make a HTTP request:
		client.println("GET ?seg="+text+" HTTP/1.1");
		client.println("Host: localhost");
		client.println("Connection: close");
		client.println();
		Serial.println("Gesendet: >>" + text + "<<");
		client.stop();
	}
	else {
		// kf you didn't get a connection to the server:
		Serial.println("connection failed");
	}

}