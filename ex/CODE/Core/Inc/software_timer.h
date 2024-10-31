/*
 * software_timer.h
 *
 *  Created on: Oct 31, 2024
 *      Author: NAM NGUYEN
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_
#include "global.h"
#include "main.h"
#include "button.h"
#include "seven_segment_led.h"

/* timer for traffic LEDs */
extern int timer0_flag;
extern int timer0_counter;
void set_timer0(int duration);
void timer0_run();

/* timer for 7SEG */
extern int timer7SEG_flag;
extern int timer7SEG_counter;
void set_timer7SEG();
void timer7SEG_run();

/* timer for manual modes, switch to auto after manual_duration seconds */
extern int timer_manual_duration_flag;
extern int timer_manual_duration_counter;
void set_timer_manual_duration();
void timer_manual_duration_run();

/* timer interrupt ISR */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);


#endif /* INC_SOFTWARE_TIMER_H_ */
