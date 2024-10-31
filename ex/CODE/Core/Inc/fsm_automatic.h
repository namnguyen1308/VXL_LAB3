/*
 * fsm_automatic.h
 *
 *  Created on: Oct 31, 2024
 *      Author: NAM NGUYEN
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_
#include "global.h"
#include "main.h"
#include "button.h"
#include "seven_segment_led.h"
#include "software_timer.h"

/* same works for automatic modes */
void automatic_run();

/* fsm for automatic modes */
void fsm_automatic_run();


#endif /* INC_FSM_AUTOMATIC_H_ */
