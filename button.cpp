/*
 * button.cpp
 *
 *  Created on: 2017��11��12��
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
