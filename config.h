/*
 * config.h
 *
 *  Created on: 2017��11��6��
 *      Author: HP
 */

#ifndef CONFIG_H_
#define CONFIG_H_
#include <EEPROM.h>
typedef struct RouterInfo
{
	char ssid[32];
	char password[32];
}RouterInfo;
#endif /* CONFIG_H_ */
