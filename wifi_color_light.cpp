#include <ESP8266WiFi.h>
#include <ESP.h>
#include <stdbool.h>
#include "button.h"
#include "wifi_color_light.h"
#include "osapi.h"
#include "user_interface.h"
#include "ets_sys.h"
#include "mem.h"
#include "AP_Service.h"
#include "STA_Service.h"
#include "time.h"
const char* ssid = "360WiFi-D9B905";
const char* password = "guihui1104.";

//The setup function is called once at startup of the sketch
WiFiServer server(80);
void setup()
{
// Add your initialization code here
	Serial.begin(115200);
	delay(10);
	int timezone = 3;
	int dst = 0;

	Serial.print("connecting to:");

	Serial.println(ssid);
	WiFi.mode(WIFI_STA);
	WiFi.begin(ssid,password);
	setButtonEvent(Button::clear);
	while(WiFi.status() != WL_CONNECTED)
	{
		delay(500);
		Serial.print(".");
	}
	Serial.println("\nW iFi connected");
	buttonInitialization();
	/*server.begin();
	Serial.println("Server started");*/


	//server.begin();

}
namespace User
{
	enum Mode
	{
		config,
		normal,
	};
}
// The loop function is called in an endless loop
void loop()
{
	static User::Mode mode = User::normal;

	if (checkButtonEvent() == Button::press)
	{
		mode = User::config;
		clearButtonEvent();
	}

//Add your repeated code here
	if (mode == User::config)
	{
		if(AP_Service("guihui","guihui00",80) == 0)
		{
			EspClass esp;
			esp.reset();
		}
	}
	else if (mode == User::normal)
	{
		//STA_Service();
		//Serial.println("STA_Service");
	}

	 time_t now = time(nullptr);
	 Serial.println(ctime(&now));
	 Serial.println(micros()/1000000);
	delay(3000);
}
