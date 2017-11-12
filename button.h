/*
 * button.h
 *
 *  Created on: 2017��11��12��
 *      Author: HP
 */

#ifndef BUTTON_H_
#define BUTTON_H_

namespace Button
{
	enum Event
	{
		click,
		press,
		doubleClick,
		clear,
	};
}

void setButtonEvent(Button::Event event);
Button::Event checkButtonEvent();
void clearButtonEvent();



#endif /* BUTTON_H_ */
