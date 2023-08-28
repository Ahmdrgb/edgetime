/*
 * Timer.h
 *
 *  Created on: Aug 28, 2023
 *      Author: mtear
 */

#ifndef MCAL_TIMER_TIMER_H_
#define MCAL_TIMER_TIMER_H_

/**
 * Mode of the timer.
 */
volatile char Pressed=0;
typedef enum timMode
{
    oneshot, periodic, edgeTime, PWM
}timerMode;

/**
 * Which timer block to use.
 */
typedef enum timBlock
{
    Timer0, Timer1, Timer2, Timer3, Timer4, Timer5,
    wTimer0, wTimer1, wTimer2, wTimer3, wTimer4, wTimer5
}timerBlock;

/**
 * Count direction of the timer.
 */
typedef enum countDirec
{
    up, down
}countDirection;

/**
 * Which subtimer to use or both in concatenated mode.
 */
typedef enum timesuse
{
    timerA, timerB, concatenated
}timerstate;
typedef enum
{
    positive, nigative, none
}edge;

void timer_Init(timerBlock timer,timerMode mode ,countDirection direction,timerstate block,long loadregister,edge edge_state);
#endif /* 1_MCAL_TIMER_TIMER_H_ */
