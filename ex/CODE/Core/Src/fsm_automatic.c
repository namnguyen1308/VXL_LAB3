/*
 * fsm_automatic.c
 *
 *  Created on: Oct 31, 2024
 *      Author: NAM NGUYEN
 */
#include "fsm_automatic.h"

/* same works for automatic modes */
void automatic_run(){
	automatic_update_7SEG();

	/* switch to manual modes */
	if(is_button_pressed(0)){
		HAL_GPIO_WritePin(RED_LED_0_GPIO_Port, RED_LED_0_Pin, SET);
		HAL_GPIO_WritePin(RED_LED_1_GPIO_Port, RED_LED_1_Pin, SET);

		HAL_GPIO_WritePin(YELLOW_LED_0_GPIO_Port, YELLOW_LED_0_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_LED_1_GPIO_Port, YELLOW_LED_1_Pin, SET);

		HAL_GPIO_WritePin(GREEN_LED_0_GPIO_Port, GREEN_LED_0_Pin, SET);
		HAL_GPIO_WritePin(GREEN_LED_1_GPIO_Port, GREEN_LED_1_Pin, SET);

		status = MAN_RED;
		set_timer0(TIMER_CYCLE);
		manual_duration = 1000;
	}
}

/* fsm for automatic modes */
void fsm_automatic_run(){
	switch (status) {
		case INIT:
			status = AUTO_RED_RED_0;
			set_timer0(2000);
			set_timer7SEG();

			automatic_duration_0 = 11000;
			automatic_duration_1 = 2000;
			break;
		case AUTO_RED_RED_0:
			/* road 1 RED, road 2 RED */
			HAL_GPIO_WritePin(RED_LED_0_GPIO_Port, RED_LED_0_Pin, RESET);
			HAL_GPIO_WritePin(RED_LED_1_GPIO_Port, RED_LED_1_Pin, RESET);

			HAL_GPIO_WritePin(YELLOW_LED_0_GPIO_Port, YELLOW_LED_0_Pin, SET);
			HAL_GPIO_WritePin(YELLOW_LED_1_GPIO_Port, YELLOW_LED_1_Pin, SET);

			HAL_GPIO_WritePin(GREEN_LED_0_GPIO_Port, GREEN_LED_0_Pin, SET);
			HAL_GPIO_WritePin(GREEN_LED_1_GPIO_Port, GREEN_LED_1_Pin, SET);

			automatic_run();

			if(timer0_flag == 1){
				status = AUTO_RED_GREEN;
				set_timer0(5000);

				automatic_duration_1 = 5000;
			}
			break;
		case AUTO_RED_GREEN:
			/* road 1 RED, road 2 GREEN */
			HAL_GPIO_WritePin(RED_LED_0_GPIO_Port, RED_LED_0_Pin, RESET);
			HAL_GPIO_WritePin(RED_LED_1_GPIO_Port, RED_LED_1_Pin, SET);

			HAL_GPIO_WritePin(YELLOW_LED_0_GPIO_Port, YELLOW_LED_0_Pin, SET);
			HAL_GPIO_WritePin(YELLOW_LED_1_GPIO_Port, YELLOW_LED_1_Pin, SET);

			HAL_GPIO_WritePin(GREEN_LED_0_GPIO_Port, GREEN_LED_0_Pin, SET);
			HAL_GPIO_WritePin(GREEN_LED_1_GPIO_Port, GREEN_LED_1_Pin, RESET);

			automatic_run();

			if(timer0_flag == 1){
				status = AUTO_RED_YELLOW;
				set_timer0(2000);

				automatic_duration_1 = 2000;
			}
			break;
		case AUTO_RED_YELLOW:
			/* road 1 RED, road 2 YELLOW */
			HAL_GPIO_WritePin(RED_LED_0_GPIO_Port, RED_LED_0_Pin, RESET);
			HAL_GPIO_WritePin(RED_LED_1_GPIO_Port, RED_LED_1_Pin, SET);

			HAL_GPIO_WritePin(YELLOW_LED_0_GPIO_Port, YELLOW_LED_0_Pin, SET);
			HAL_GPIO_WritePin(YELLOW_LED_1_GPIO_Port, YELLOW_LED_1_Pin, RESET);

			HAL_GPIO_WritePin(GREEN_LED_0_GPIO_Port, GREEN_LED_0_Pin, SET);
			HAL_GPIO_WritePin(GREEN_LED_1_GPIO_Port, GREEN_LED_1_Pin, SET);

			automatic_run();

			if(timer0_flag == 1){
				status = AUTO_RED_RED_1;
				set_timer0(2000);

				automatic_duration_1 = 11000;
			}
			break;


		case AUTO_RED_RED_1:
			/* road 1 RED, road 2 RED */
			HAL_GPIO_WritePin(RED_LED_0_GPIO_Port, RED_LED_0_Pin, RESET);
			HAL_GPIO_WritePin(RED_LED_1_GPIO_Port, RED_LED_1_Pin, RESET);

			HAL_GPIO_WritePin(YELLOW_LED_0_GPIO_Port, YELLOW_LED_0_Pin, SET);
			HAL_GPIO_WritePin(YELLOW_LED_1_GPIO_Port, YELLOW_LED_1_Pin, SET);

			HAL_GPIO_WritePin(GREEN_LED_0_GPIO_Port, GREEN_LED_0_Pin, SET);
			HAL_GPIO_WritePin(GREEN_LED_1_GPIO_Port, GREEN_LED_1_Pin, SET);

			automatic_run();

			if(timer0_flag == 1){
				status = AUTO_GREEN_RED;
				set_timer0(5000);

				automatic_duration_0 = 5000;
			}
			break;
		case AUTO_GREEN_RED:
			/* road 1 GREEN, road 2 RED */
			HAL_GPIO_WritePin(RED_LED_0_GPIO_Port, RED_LED_0_Pin, SET);
			HAL_GPIO_WritePin(RED_LED_1_GPIO_Port, RED_LED_1_Pin, RESET);

			HAL_GPIO_WritePin(YELLOW_LED_0_GPIO_Port, YELLOW_LED_0_Pin, SET);
			HAL_GPIO_WritePin(YELLOW_LED_1_GPIO_Port, YELLOW_LED_1_Pin, SET);

			HAL_GPIO_WritePin(GREEN_LED_0_GPIO_Port, GREEN_LED_0_Pin, RESET);
			HAL_GPIO_WritePin(GREEN_LED_1_GPIO_Port, GREEN_LED_1_Pin, SET);

			automatic_run();

			if(timer0_flag == 1){
				status = AUTO_YELLOW_RED;
				set_timer0(2000);

				automatic_duration_0 = 2000;
			}
			break;
		case AUTO_YELLOW_RED:
			/* road 1 YELLOW, road 2 RED */
			HAL_GPIO_WritePin(RED_LED_0_GPIO_Port, RED_LED_0_Pin, SET);
			HAL_GPIO_WritePin(RED_LED_1_GPIO_Port, RED_LED_1_Pin, RESET);

			HAL_GPIO_WritePin(YELLOW_LED_0_GPIO_Port, YELLOW_LED_0_Pin, RESET);
			HAL_GPIO_WritePin(YELLOW_LED_1_GPIO_Port, YELLOW_LED_1_Pin, SET);

			HAL_GPIO_WritePin(GREEN_LED_0_GPIO_Port, GREEN_LED_0_Pin, SET);
			HAL_GPIO_WritePin(GREEN_LED_1_GPIO_Port, GREEN_LED_1_Pin, SET);

			automatic_run();

			if(timer0_flag == 1){
				status = AUTO_RED_RED_0;
				set_timer0(2000);

				automatic_duration_0 = 11000;
			}
			break;
		default:
			break;
	}
}

