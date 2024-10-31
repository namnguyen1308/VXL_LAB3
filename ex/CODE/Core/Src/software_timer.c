/*
 * software_timer.c
 *
 *  Created on: Oct 31, 2024
 *      Author: NAM NGUYEN
 */

#include "software_timer.h"


/* timer for traffic LEDs */
int timer0_flag = 0;
int timer0_counter = 0;
void set_timer0(int duration){
	timer0_flag = 0;
	timer0_counter = duration / TIMER_CYCLE;
}
void timer0_run(){
	if(timer0_counter > 0){
		timer0_counter--;
		if(timer0_counter <= 0) timer0_flag = 1;
	}
}


/* timer for 7SEG, scan frequency 1Hz */
int timer7SEG_flag = 0;
int timer7SEG_counter = 0;
void set_timer7SEG(){
	timer7SEG_flag = 0;
	timer7SEG_counter = (1000 / MAX_7SEG) / TIMER_CYCLE;
}
void timer7SEG_run(){
	if(timer7SEG_counter > 0){

		automatic_duration_0 -= TIMER_CYCLE;
		automatic_duration_1 -= TIMER_CYCLE;
		timer7SEG_counter--;

		if(timer7SEG_counter <= 0) timer7SEG_flag = 1;
	}
}

//
///* timer for showing 7SEG in automatic modes of road 1 */
//int timer_automatic_duration_0_flag = 0;
//int timer_automatic_duration_0_counter = 0;
//void set_timer_automatic_duration_0(){
//	timer_automatic_duration_0_flag = 0;
//	timer_automatic_duration_0_counter = automatic_duration_0 / TIMER_CYCLE;
//}
//void timer_automatic_duration_0_run(){
//	if(timer_automatic_duration_0_counter > 0){
//
//		timer_automatic_duration_0 -= TIMER_CYCLE;
//		timer_automatic_duration_0_counter--;
//
//		if(timer_automatic_duration_0_counter <= 0) timer_automatic_duration_0_flag = 1;
//	}
//}
//
//
///* timer for manual modes, switch to auto after manual_duration seconds */
//int timer_automatic_duration_0_flag = 0;
//int timer_automatic_duration_0_counter = 0;
//void set_timer_automatic_duration_0(){
//	timer_automatic_duration_0_flag = 0;
//	timer_automatic_duration_0_counter = automatic_duration_0 / TIMER_CYCLE;
//}
//void timer_automatic_duration_0_run(){
//	if(timer_automatic_duration_0_counter > 0){
//
//		timer_automatic_duration_0 -= TIMER_CYCLE;
//		timer_automatic_duration_0_counter--;
//
//		if(timer_automatic_duration_0_counter <= 0) timer_automatic_duration_0_flag = 1;
//	}
//}


/* timer for manual modes, switch to auto after manual_duration seconds */
int timer_manual_duration_flag = 0;
int timer_manual_duration_counter = 0;
void set_timer_manual_duration(){
	timer_manual_duration_flag = 0;
	timer_manual_duration_counter = manual_duration / TIMER_CYCLE;
}
void timer_manual_duration_run(){
	if(timer_manual_duration_counter > 0){

		manual_duration -= TIMER_CYCLE;
		timer_manual_duration_counter--;

		if(timer_manual_duration_counter <= 0) timer_manual_duration_flag = 1;
	}
}


/* timer interrupt ISR */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	button_read();
	timer0_run();
	timer7SEG_run();
	timer_manual_duration_run();
}
