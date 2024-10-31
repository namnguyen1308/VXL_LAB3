/*
 * button.c
 *
 *  Created on: Oct 31, 2024
 *      Author: NAM NGUYEN
 */

#include "button.h"


int button_flags[NO_OF_BUTTONS] = {0, 0, 0};

/* debounce 3 times */
int keys_0[NO_OF_BUTTONS];
int keys_1[NO_OF_BUTTONS];
int keys_2[NO_OF_BUTTONS];

int last_buttons[NO_OF_BUTTONS];

GPIO_TypeDef* buttons_port[NO_OF_BUTTONS] = {BUTTON_0_GPIO_Port, BUTTON_1_GPIO_Port, BUTTON_2_GPIO_Port};
uint16_t buttons[NO_OF_BUTTONS] = {BUTTON_0_Pin, BUTTON_1_Pin, BUTTON_2_Pin};

int timers_key_pressed[NO_OF_BUTTONS] = {200, 200, 200};


/* timer interrupt for button read */
void button_read(){
	for(int i = 0; i < NO_OF_BUTTONS; i++){
		keys_2[i] = keys_1[i];
		keys_1[i] = keys_0[i];
		keys_0[i] = HAL_GPIO_ReadPin(buttons_port[i], buttons[i]);

		if((keys_2[i] == keys_1[i]) && (keys_1[i] == keys_0[i])){
			if(last_buttons[i] != keys_2[i]){
				last_buttons[i] = keys_2[i];
				if(keys_2[i] == BUTTON_PRESSED){
					button_flags[i] = 1;
					timers_key_pressed[i] = 200;
				}
			}else{
				timers_key_pressed[i]--;
				if(timers_key_pressed[i] <= 0){
					if(keys_2[i] == BUTTON_PRESSED){
						button_flags[i] = 1;
					}
					timers_key_pressed[i] = 200;
				}
			}
		}
	}
}


/* check button pressed flag */
int is_button_pressed(int index){
	if(button_flags[index] == 1){
		button_flags[index] = 0;
		return 1;
	}
	return 0;
}
