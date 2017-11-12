/*
 * STA_Service.cpp
 *
 *  Created on: 2017Äê11ÔÂ12ÈÕ
 *      Author: HP
 */
#include "STA_Service.h"
#include "config.h"
#include "ESP8266WiFi.h"
#include "WiFiUdp.h"
int STA_Service(void)
{
	if(WiFi.status() != WL_CONNECTED)
	{
		RouterInfo routerInfo = {.ssid = {0},.password = {0}};
		readRouterInfo(&routerInfo);
		WiFi.mode(WIFI_STA);
		WiFi.begin(routerInfo.ssid,routerInfo.password);
	}
	RouterInfo routerInfo = {.ssid = {0},.password = {0}};
	readRouterInfo(&routerInfo);
	Serial.println(routerInfo.ssid);
	Serial.println(routerInfo.password);
	static WiFiUDP udp;
	udp.begin(1314);
	udp.beginPacket("255.255.255.255",1314);
	Serial.println(WiFi.localIP());
	char str[64] = {0};
	WiFi.localIP().toString().toCharArray(str,64,0);
	udp.write(str,strlen(str));
	udp.endPacket();

	return 0;
}


