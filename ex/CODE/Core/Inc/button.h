/*
 * button.h
 *
 *  Created on: Oct 31, 2024
 *      Author: NAM NGUYEN
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_


#include "global.h"
#include "main.h"

#define BUTTON_RELEASED GPIO_PIN_SET
#define BUTTON_PRESSED GPIO_PIN_RESET

#define NO_OF_BUTTONS 3

/* timer interrupt for button read */
void button_read();

/* check button pressed flag */
int is_button_pressed(int index);

#endif /* INC_BUTTON_H_ */

