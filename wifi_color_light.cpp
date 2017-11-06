#include <ESP8266WiFi.h>
#include "wifi_color_light.h"
#include "AP_Service.h"
const char* ssid = "360WiFi-D9B905";
const char* password = "guihui1104.";
//The setup function is called once at startup of the sketch
WiFiServer server(80);
void setup()
{
// Add your initialization code here
	Serial.begin(115200);
	delay(10);

	Serial.print("connecting to:");

	Serial.println(ssid);
	/*WiFi.begin(ssid,password);

	while(WiFi.status() != WL_CONNECTED)
	{
		delay(500);
		Serial.print(".");
	}
	Serial.println("\nW iFi connected");

	server.begin();
	Serial.println("Server started");*/


	//server.begin();

}

// The loop function is called in an endless loop
void loop()
{

//Add your repeated code here
	AP_Service("guihui","guihui00",80);

	delay(500);
}
