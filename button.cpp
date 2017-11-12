/*
 * button.cpp
 *
 *  Created on: 2017Äê11ÔÂ12ÈÕ
 *      Author: HP
 */

#include "button.h"

static Button::Event btEvent;
void setButtonEvent(Button::Event event)
{
	btEvent = event;
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
