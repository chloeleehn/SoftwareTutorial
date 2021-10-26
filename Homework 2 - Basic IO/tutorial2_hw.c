#include "main.h"
#include "lcd/lcd.h"
#include "lcd/lcd_graphics.h"

/** Design ideologies:
 * More small functions >>> Few giant functions
 * Reusability and Extendability is most important (Dont-Repeat-Yourself)
 * then Readability (comments are good, self documenting code is best)
 * No "magic numbers", use defines, constants, variables etc
 * ALWAYS INDENT CORRECTLY
 * No blocking (long while loops, HAL_Delay)
 */

// Enums are always good
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

ButtonState btn_state(void) {
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

ButtonState state = ALL_OFF;

/* Private variables END */

/* Private function prototypes START */

/* Private function prototypes END */

/*
void gpio_classwork(void) {

	led_off(LED1);
	led_off(LED2);
	led_off(LED3);
	led_off(LED4);

	if (btn_state() == BTN1_ONLY){
		led_on(LED1);
	}
	else if (btn_state() == BTN2_ONLY){
		while (btn_state() == BTN2_ONLY) {
			static uint32_t last_ticks = 0;
			if((HAL_GetTick() - last_ticks) >= 50){
				gpio_toggle(LED2);
				last_ticks = HAL_GetTick();
			}
		}
	}
	else if (btn_state() == BOTH_BTN){

		led_on(LED1);
		led_on(LED3);
		led_off(LED2);
		led_off(LED4);
		while(btn_state()== BOTH_BTN){
				//This variable keeps its stored value through every iteration
			static uint32_t last_ticks = 0;

			while(((HAL_GetTick() - last_ticks) >= 1000 && (HAL_GetTick() - last_ticks) <= 2000)){
				gpio_toggle(LED1);
				gpio_toggle(LED3);
				gpio_toggle(LED2);
				gpio_toggle(LED4);
			}
			last_ticks = HAL_GetTick();
		}

	}

}

void tft_classwork(void) {

	tft_init(PIN_ON_TOP, BLACK, WHITE, RED, DARK_GREEN);
	for (int8_t j = 0; j<20; j++)
		for (int8_t i = 0; i < 5; i++){
			switch()
			{
				case 1:
					color = "RED";
					break;
				case 2:
					color = "GREEN";
					break;
				case 3:
					color = "BLUE";
					break;
				case 4:
					color = "GRAY";
					break;

			}
			tft_print_pixel(color, 50,  50);
		}

	}
*/
    /* Your code end here */

void tutorial2_homework(void) {
    /* Your code start here */

	static uint32_t state = 0;
/*
	if (btn_state() != ALL_OFF)
	{
		led_off(LED1);
		led_off(LED2);
		led_off(LED3);
		led_off(LED4);
		while (btn_state() != ALL_OFF)
		{
			if (tft_update(50)== 0)
				tft_prints(0, 0, "Hello, Chloe");
		}
		state = 1;
		if (tft_update(50)== 0)
			tft_prints(0, 0, " ");
	}
	static uint32_t last_ticks = 0;
	while(btn_state() == ALL_OFF && state == 1)
	{
		if (tft_update(50)== 0)
			tft_prints(0, 0, " ");
		if((HAL_GetTick() - last_ticks) >= 50)
		{
			gpio_toggle(LED1);
			gpio_toggle(LED2);
			gpio_toggle(LED3);
			gpio_toggle(LED4);
			last_ticks = HAL_GetTick();
		}
	}

}
*/


// Tasks 2
	static uint32_t last_ticks1 = 0;
	if (btn_state() != ALL_OFF && state == 0)
	{
		led_off(LED1);
		led_off(LED2);
		led_off(LED3);
		led_off(LED4);
		state = 1;
		while (btn_state() != ALL_OFF){
			last_ticks1 = HAL_GetTick();
			while((HAL_GetTick() - last_ticks1) >= 0 && (HAL_GetTick() - last_ticks1) <= 1000)
			{
				if (tft_update(50)== 0)
				{
					tft_prints(0, 0, "Hello, Chloe");
					state = 1;
				}
				if (btn_state() == ALL_OFF)
				{
					state = 2;
					break;
				}
			}

		}
		// last_ticks1 = HAL_GetTick();
		if (tft_update(50)== 0 && state == 1)
			tft_prints(0, 0, " ");
	}
	static uint32_t last_ticks = 0;
	last_ticks1 = HAL_GetTick();
	while ((HAL_GetTick() - last_ticks1) >= 0 && (HAL_GetTick() - last_ticks1) < 1000 && state==2)
	{
		if (tft_update(50) == 0 && state == 2 )
			tft_prints(0, 0, "Hello, Chloe");
		if((HAL_GetTick() - last_ticks) >= 50)
		{
			gpio_toggle(LED1);
			gpio_toggle(LED2);
			gpio_toggle(LED3);
			gpio_toggle(LED4);
			last_ticks = HAL_GetTick();
		}
	}
	while ((HAL_GetTick() - last_ticks1) >= 0 && (HAL_GetTick() - last_ticks1) < 1000 && state==1)
	{
		if (tft_update(50) == 0)
			tft_prints(0, 0, "  ");
		if((HAL_GetTick() - last_ticks) >= 50)
		{
			gpio_toggle(LED1);
			gpio_toggle(LED2);
			gpio_toggle(LED3);
			gpio_toggle(LED4);
			last_ticks = HAL_GetTick();
		}
	}
	while(btn_state() == ALL_OFF)
	{
		if (tft_update(50) == 0)
		{
			tft_prints(0, 0, " ");
		}
		led_off(LED1);
		led_off(LED2);
		led_off(LED3);
		led_off(LED4);
	}
	state = 0;

}






// You can define your helper functions down below
// You can also modify the function definition above as long as your move is reasonable
