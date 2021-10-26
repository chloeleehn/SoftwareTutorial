#include "main.h"
#include "tim.h"


/* Private variables END */

/* Private function prototypes START */

/* Private function prototypes END */
typedef enum {
	BOTH_BTN, BTN1_ONLY, BTN2_ONLY, ALL_OFF,
} ButtonState;

typedef enum {
    BUTTON1, BUTTON2,

    //This trick means the NumButtons will equal how many buttons there are (how many enum values)
    //This works as long as the enum values are simple (count up from 0)
    NUM_BUTTON,
} Button;

typedef enum {
    LED1, LED2, LED3, LED4, NUM_LED,
} LED;

/**
 * @brief read the button state
 * return 1 if the button is pressed;
 * return 0 if the button is released;
 */
static inline uint8_t read_button(Button btn) {
    switch (btn) {
    case BUTTON1:
        return !btn_read(BTN1);
    case BUTTON2:
        return !btn_read(BTN2);
    default:
        return 0;
    }
}

ButtonState btnstate(void) {
    if (read_button(BUTTON1) && read_button(BUTTON2)) {
        return BOTH_BTN;
    } else if (read_button(BUTTON1)) {
        return BTN1_ONLY;
    } else if (read_button(BUTTON2)) {
        return BTN2_ONLY;
    } else {
        return ALL_OFF;
    }
}

/* Private variables START */


void pwm_init(void) {
	// init the pwm prescaler value and auto-reload value and start the pwm
	/* Your code start here */
//	MX_TIM5_Init();
	TIM5->ARR = 9999;    //set the timer1 auto-reload counter
	TIM5->PSC = 167;
	TIM5->CCR1 = 199;
	HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_1);
	/* Your code end here */
}

/*
void pwm_classwork(void) {
	// change the compare value
//
	static uint32_t last_ticks = 0;
	if((HAL_GetTick() - last_ticks) >= 1000 && (HAL_GetTick() - last_ticks) < 2000 ){
		TIM5->CCR1 = 199; // on time: 1.5ms, position: 0
	}
	if((HAL_GetTick() - last_ticks) >= 2000 && (HAL_GetTick() - last_ticks) < 3000 ){
		TIM5->CCR1 = 699; // on time: 2ms, position: 90
	}
	if ((HAL_GetTick() - last_ticks) >= 3000){
		TIM5->CCR1 = 1199; // on time: 2.5ms, position: 180
	}
	else
		TIM5->CCR1 = 0;
//
	for (int i=0; i<3; i++){
		static uint32_t last_ticks1 = 0;
		for (int i = 199; i < 1200; i+=50){
			if((HAL_GetTick() - last_ticks1) >= 100)
			{
				TIM5->CCR1 = i;
				last_ticks1 = HAL_GetTick();
			}
		}
	}

}
*/

// 199, 699, 1199
// 499, 749, 999

void pwm_homework(void) {
	uint32_t state = 0;
	if (btnstate() == BTN1_ONLY){
		static uint32_t last_ticks1 = 0;
		for (int i = 199; i < 1200; i+=50){
			if((HAL_GetTick() - last_ticks1) >= 100)
			{
				TIM5->CCR1 = i;
				last_ticks1 = HAL_GetTick();
			}
		}
	}
	else if (btnstate() == BTN2_ONLY)
	{
		static uint32_t last_ticks = 0;
		last_ticks = HAL_GetTick();
		state = 2;
		if((HAL_GetTick() - last_ticks) >= 1000 && (HAL_GetTick() - last_ticks) < 1500 ){
			TIM5->CCR1 = 119; // on time: 1.72ms, position: 40
			led_off(LED1);
			led_off(LED2);
			led_off(LED3);
			led_off(LED4);
		}
		while (btnstate() == BTN2_ONLY){
			if ((HAL_GetTick() - last_ticks) >= 1500 && (HAL_GetTick() - last_ticks) < 2000){
				led_on(LED1);
				led_off(LED2);
				led_off(LED3);
				led_off(LED4);
			}
			if ((HAL_GetTick() - last_ticks) >= 2000 && (HAL_GetTick() - last_ticks) < 2500){
				led_on(LED1);
				led_on(LED2);
				led_off(LED3);
				led_off(LED4);
			}
			if ((HAL_GetTick() - last_ticks) >= 2500 && (HAL_GetTick() - last_ticks) < 3000){
				led_on(LED1);
				led_on(LED2);
				led_on(LED3);
				led_off(LED4);
			}
			if ((HAL_GetTick() - last_ticks) >= 3000 && (HAL_GetTick() - last_ticks) < 3500){
				led_on(LED1);
				led_on(LED2);
				led_on(LED3);
				led_on(LED4);
				state = 1;
			}
		}
		led_off(LED1);
		led_off(LED2);
		led_off(LED3);
		led_off(LED4);

		if (state == 1){
			static uint32_t last_ticks2 = 0;
			for (int i= 0; i < 3; i++)
			{
					TIM5->CCR1 = 199;
					TIM5->CCR1 = 1199;
			}
		}
		else{
			TIM5->CCR1 = 199;
			TIM5->CCR1 = 1199;
		}

	}
}




