#include <ESP8266WiFi.h>
#include "wifi_color_light.h"
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
	WiFi.begin(ssid,password);

	while(WiFi.status() != WL_CONNECTED)
	{
		delay(500);
		Serial.print(".");
	}
	Serial.println("\nW iFi connected");

	server.begin();
	Serial.println("Server started");
}

// The loop function is called in an endless loop
void loop()
{

//Add your repeated code here
	WiFiClient client = server.available();
		  if (!client) {
		    return;
		  }
	  Serial.println("new client");
	    while(!client.available()){
	      delay(1);
	    }
	     String req = client.readStringUntil('\r');
	     Serial.println(req);
	     client.flush();
	     int val;
	     String routerSsid;
	     String routerPassword;
	     int ssidIndex = req.indexOf("ssid:");
	     int passwordIndex = req.indexOf("password:");
	     if (ssidIndex != -1 && passwordIndex != -1)
	     {
	    	 for (int i = 0; i < passwordIndex - ssidIndex ;i++)
	    		routerSsid += req[ssidIndex+i];
	    	 Serial.println(routerSsid);
	     }
}
