/*
 * button.cpp
 *
 *  Created on: 2017Äê11ÔÂ12ÈÕ
 *      Author: HP
 */

#include "button.h"
#include <Arduino.h>
#include <stdint.h>
#include "time.h"
static Button::Event btEvent;
static uint32_t lastTime = 0;
static uint32_t currentTime = 0;
static uint32_t pressTime = 0;
static uint32_t releaseTime = 0;
#define BUTTON_PIN D14
void buttonEvent()
{
	if (digitalRead(BUTTON_PIN) == 0)
		pressTime = micros();
	else if(digitalRead(BUTTON_PIN) == 1)
	{
		releaseTime = micros();
		if ((releaseTime - pressTime) > 1000000)
			btEvent = Button::press;
		else
		{
			btEvent = Button::click;
			lastTime = currentTime;
			currentTime = micros();
			if ((currentTime - lastTime) < 1000000)
				btEvent = Button::doubleClick;
		}

	}

}
void buttonInitialization()
{
	pinMode(BUTTON_PIN,INPUT_PULLUP);
	attachInterrupt(BUTTON_PIN,buttonEvent,CHANGE);
}
void setButtonEvent(Button::Event event)
{
	btEvent = event;
	//pin_mode
}
Button::Event checkButtonEvent()
{
	//btEvent = Button::press;
	return btEvent;
}
void clearButtonEvent()
{
	btEvent = Button::clear;
}

