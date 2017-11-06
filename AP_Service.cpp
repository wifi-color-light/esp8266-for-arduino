/*
 * AP_Service.cpp
 *
 *  Created on: 2017Äê11ÔÂ6ÈÕ
 *      Author: guihui
 */
#include "WString.h"
#include "ESP8266WiFi.h"
#include "AP_Service.h"
#include "config.h"
/**
 *
 */
int AP_Service(const char* ssid,const char* password,unsigned int port)
{
	static WiFiServer wifiServer(port);
	static WiFiClient client;
	if (WiFi.getMode() != WIFI_AP)
	{
		WiFi.mode(WIFI_AP);
		WiFi.softAP(ssid,password,1,0);
		Serial.println(WiFi.softAPIP());
	}
	if (wifiServer.status() == CLOSED){
		wifiServer.begin();
		Serial.println("server start");
	}

	while (1)
	{
		client = wifiServer.available();

		if (!client)
			continue;
		Serial.println("new client");
		while(!client.available()){
			delay(1);
		}
		String req = client.readString();
		Serial.println(req);
		client.flush();
		int val;
		int ssidIndex = req.indexOf("ssid:");
		int passwordIndex = req.indexOf("password:");
		int endFlgIndex = req.indexOf("HTTP/");

		 Serial.println(endFlgIndex);
		if (ssidIndex != -1 && passwordIndex != -1)
		{
			RouterInfo routerinfo = {0};
			 for (int i = 0; i < passwordIndex - ssidIndex -strlen("SSID:");i++)
				routerinfo.ssid[i] = req[ssidIndex+i+strlen("SSID:")];
			 Serial.print("SSID:");
			 Serial.print(routerinfo.ssid);
			 for (int i = 0;i <  endFlgIndex - passwordIndex - strlen("password:");i++)
				 routerinfo.password[i] = req[passwordIndex+i+strlen("password:")];
			 Serial.print("password");
			 Serial.println(routerinfo.password);
			 Serial.println(sizeof(RouterInfo));
			 EEPROM.begin(512);
			 uint8_t *p = (uint8_t*)&routerinfo;
			 for (int i = 0;i < sizeof(RouterInfo);i++)
				 EEPROM.write(i,*p++);
			 EEPROM.commit();
			 RouterInfo eepromRouterInfo = {0};
			 p = (uint8_t*)&eepromRouterInfo;
			 for (int i = 0;i  < sizeof(RouterInfo);i++)
				*p++ = EEPROM.read(i);
			 Serial.print("eepromRouterInfo->SSID:");
			 Serial.print(eepromRouterInfo.ssid);
			 Serial.print("\tpassword:");
			 Serial.println(eepromRouterInfo.password);
			 client.flush();
			 String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\n";
			 s += "configuration successful";
			 s += "</html>\n";
			 client.println(s);
			 client.flush();
			 wifiServer.close();
			 return 0;
		}
		else
		{
			 client.flush();
			 String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\n";
			 s +="configuration ailed";
			 s += "</html>\n";
			 client.println(s);
			 client.flush();
		}
	}
	return -1;
}


