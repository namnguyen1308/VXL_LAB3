/*
 * fsm_manual.h
 *
 *  Created on: Oct 31, 2024
 *      Author: NAM NGUYEN
 */

#ifndef INC_FSM_MANUAL_H_
#define INC_FSM_MANUAL_H_
#include "global.h"
#include "main.h"
#include "button.h"
#include "seven_segment_led.h"
#include "software_timer.h"

/* same works for manual modes */
void manual_run();

/* fsm for manual modes */
void fsm_manual_run();


#endif /* INC_FSM_MANUAL_H_ */
