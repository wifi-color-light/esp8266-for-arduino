/*
 * config.cpp
 *
 *  Created on: 2017Äê11ÔÂ12ÈÕ
 *      Author: HP
 */

#include "config.h"
#include "ESP8266WiFi.h"

int saveRouterInfo(RouterInfo info)
{
	uint8_t* p = (uint8_t*)&info;

	EEPROM.begin(512);
	for (int i = 0;i < sizeof(RouterInfo);i++)
		EEPROM.write(i,*p++);
	EEPROM.commit();
	return 0;
}

int readRouterInfo(RouterInfo *info)
{
	uint8_t*p = (uint8_t*)info;
	EEPROM.begin(512);
	for (int i = 0;i < sizeof(RouterInfo);i++)
		*p = EEPROM.read(i);

}
