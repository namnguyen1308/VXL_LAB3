/*
 * seven_segment_led.h
 *
 *  Created on: Oct 31, 2024
 *      Author: NAM NGUYEN
 */

#ifndef INC_SEVEN_SEGMENT_LED_H_
#define INC_SEVEN_SEGMENT_LED_H_
#include "global.h"
#include "main.h"
#include "software_timer.h"

#define MAX_7SEG 4

/* show counter in automatic modes */
void automatic_update_7SEG();

/* show mode and duration in manual modes */
void manual_update_7SEG();

/* control EN pins */
void update7SEG(int index);

/* control SEG pins */
void display7SEG(int num);


#endif /* INC_SEVEN_SEGMENT_LED_H_ */
