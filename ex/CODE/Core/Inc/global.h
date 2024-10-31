/*
 * global.h
 *
 *  Created on: Oct 31, 2024
 *      Author: NAM NGUYEN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define TIMER_CYCLE 10

/* mode status */
extern int status;

/* show traffic countdown value in automatic modes of road 0 on 7SEG*/
extern int automatic_duration_0;

/* show traffic countdown value in automatic modes of road 1 on 7SEG*/
extern int automatic_duration_1;

/* duration value in manual modes */
extern int manual_duration;


/* Automatic Modes:
 * INIT
 *
 * -> AUTO_RED_RED_0 2s
 * -> AUTO_RED_GREEN 5s
 * -> AUTO_RED_YELLOW 2s
 *
 * -> AUTO_RED_RED_1 2s
 * -> AUTO_GREEN_RED 5s
 * -> AUTO_YELLOW_RED 2s
 *
 * -> ...
 */
#define INIT 1

#define AUTO_RED_RED_0 11 /* road 0 RED, road 1 RED */
#define AUTO_RED_GREEN 12 /* road 0 RED, road 1 GREEN */
#define AUTO_RED_YELLOW 13 /* road 0 RED, road 1 YELLOW */

#define AUTO_GREEN_RED 21 /* road 0 GREEN, road 1 RED */
#define AUTO_YELLOW_RED 31 /* road 0 YELLOW, road 1 RED */
#define AUTO_RED_RED_1 41 /* road 0 RED, road 1 RED */

/*
 * Manual modes: BUTTON_0_Pin pressed
 * -> MAN_RED
 * -> MAN_YELLOW
 * -> MAN_GREEN
 * -> INIT (automatic modes)
 * -> ...
 */
#define MAN_RED 51
#define MAN_YELLOW 61
#define MAN_GREEN 71


#endif /* INC_GLOBAL_H_ */
