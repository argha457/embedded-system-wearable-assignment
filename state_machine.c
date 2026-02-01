#include <stdbool.h>
#include <stdint.h>

/* -------------------- Configuration -------------------- */
#define BUTTON_TIMEOUT 30   // seconds

/* -------------------- Device States -------------------- */
typedef enum {
    STATE_IDLE,
    STATE_LISTENING,
    STATE_ERROR
} device_state_t;

/* -------------------- Global Variables -------------------- */
static device_state_t current_state = STATE_IDLE;
static uint32_t button_hold_time = 0;

/* -------------------- Mock Function Declarations -------------------- */
/* (Assumed to be implemented elsewhere) */
bool is_button_pressed(void);
int  get_battery_level(void);
void set_led_color(int color);
void start_audio_stream(void);
void stop_audio_stream(void);

/* LED Color Definitions */
#define OFF   0
#define GREEN 1
#define RED   2

/* -------------------- Main State Machine -------------------- */
void device_loop(void)
{
    switch (current_state)
    {
        case STATE_IDLE:
            set_led_color(OFF);

            if (is_button_pressed())
            {
                if (get_battery_level() > 10)
                {
                    set_led_color(GREEN);
                    start_audio_stream();
                    button_hold_time = 0;
                    current_state = STATE_LISTENING;
                }
                else
                {
                    set_led_color(RED);
                    current_state = STATE_ERROR;
                }
            }
            break;

        case STATE_LISTENING:
            if (!is_button_pressed())
            {
                stop_audio_stream();
                set_led_color(OFF);
                current_state = STATE_IDLE;
            }
            else
            {
                button_hold_time++;

                if (button_hold_time >= BUTTON_TIMEOUT)
                {
                    stop_audio_stream();
                    set_led_color(OFF);
                    current_state = STATE_IDLE;
                }
            }
            break;

        case STATE_ERROR:
            set_led_color(RED);

            if (!is_button_pressed())
            {
                set_led_color(OFF);
                current_state = STATE_IDLE;
            }
            break;

        default:
            current_state = STATE_IDLE;
            break;
    }
}

