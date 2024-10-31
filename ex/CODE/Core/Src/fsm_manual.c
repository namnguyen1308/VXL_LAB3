/*
 * fsm_manual.c
 *
 *  Created on: Oct 31, 2024
 *      Author: NAM NGUYEN
 */

#include "fsm_manual.h"

/* same works for manual modes */
int increase_manual_duration_flag = 1;
void manual_run(){
	manual_update_7SEG();

	if(is_button_pressed(1)){
		if(manual_duration <= 99000 && increase_manual_duration_flag == 1)
			manual_duration += 1000;
	}

	if(is_button_pressed(2) && increase_manual_duration_flag == 1){
		increase_manual_duration_flag = 0;
		set_timer_manual_duration();
	}
}

/* fsm for manual modes */
void fsm_manual_run(){
	switch (status) {
		case MAN_RED:
			if(timer0_flag == 1){
				HAL_GPIO_TogglePin(RED_LED_0_GPIO_Port, RED_LED_0_Pin);
				HAL_GPIO_TogglePin(RED_LED_1_GPIO_Port, RED_LED_1_Pin);

				HAL_GPIO_WritePin(YELLOW_LED_0_GPIO_Port, YELLOW_LED_0_Pin, SET);
				HAL_GPIO_WritePin(YELLOW_LED_1_GPIO_Port, YELLOW_LED_1_Pin, SET);

				HAL_GPIO_WritePin(GREEN_LED_0_GPIO_Port, GREEN_LED_0_Pin, SET);
				HAL_GPIO_WritePin(GREEN_LED_1_GPIO_Port, GREEN_LED_1_Pin, SET);

				set_timer0(500);
			}

			manual_run();

			if(is_button_pressed(0)){
				status = MAN_YELLOW;
			}

			if(timer_manual_duration_flag == 1){
				timer_manual_duration_flag = 0;

				increase_manual_duration_flag = 1;
				manual_duration = 1000;

				status = MAN_YELLOW;
			}
			break;
		case MAN_YELLOW:
			if(timer0_flag == 1){
				HAL_GPIO_WritePin(RED_LED_0_GPIO_Port, RED_LED_0_Pin, SET);
				HAL_GPIO_WritePin(RED_LED_1_GPIO_Port, RED_LED_1_Pin, SET);

				HAL_GPIO_TogglePin(YELLOW_LED_0_GPIO_Port, YELLOW_LED_0_Pin);
				HAL_GPIO_TogglePin(YELLOW_LED_1_GPIO_Port, YELLOW_LED_1_Pin);

				HAL_GPIO_WritePin(GREEN_LED_0_GPIO_Port, GREEN_LED_0_Pin, SET);
				HAL_GPIO_WritePin(GREEN_LED_1_GPIO_Port, GREEN_LED_1_Pin, SET);

				set_timer0(500);
			}
			manual_run();

			if(is_button_pressed(0)){
				status = MAN_GREEN;
			}
			if(timer_manual_duration_flag == 1){
				timer_manual_duration_flag = 0;

				increase_manual_duration_flag = 1;
				manual_duration = 1000;

				status = MAN_GREEN;
			}
			break;
		case MAN_GREEN:
			if(timer0_flag == 1){
				HAL_GPIO_WritePin(RED_LED_0_GPIO_Port, RED_LED_0_Pin, SET);
				HAL_GPIO_WritePin(RED_LED_1_GPIO_Port, RED_LED_1_Pin, SET);

				HAL_GPIO_WritePin(YELLOW_LED_0_GPIO_Port, YELLOW_LED_0_Pin, SET);
				HAL_GPIO_WritePin(YELLOW_LED_1_GPIO_Port, YELLOW_LED_1_Pin, SET);

				HAL_GPIO_TogglePin(GREEN_LED_0_GPIO_Port, GREEN_LED_0_Pin);
				HAL_GPIO_TogglePin(GREEN_LED_1_GPIO_Port, GREEN_LED_1_Pin);

				set_timer0(500);
			}
			manual_run();

			if(is_button_pressed(0)){
				/* INIT setup switching to automatic modes */
				status = INIT;
			}

			if(timer_manual_duration_flag == 1){
				timer_manual_duration_flag = 0;

				increase_manual_duration_flag = 1;
				manual_duration = 1000;

				/* INIT setup switching to automatic modes */
				status = INIT;
			}
			break;
		default:
			break;
	}
}
