/*
MIT License

Copyright (c) 2024 Society of Robotics and Automation

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include "sra_board.h"

#define TAG "MCPWM_SERVO_CONTROL"

servo_config servo_a = {
	.servo_pin = SERVO_A,
	.min_pulse_width = CONFIG_SERVO_A_MIN_PULSEWIDTH,
	.max_pulse_width = CONFIG_SERVO_A_MAX_PULSEWIDTH,
	.max_degree = CONFIG_SERVO_A_MAX_DEGREE,
	.mcpwm_num = MCPWM_UNIT_0,
	.timer_num = MCPWM_TIMER_0,
	.gen = MCPWM_OPR_A,
};

servo_config servo_b = {
	.servo_pin = SERVO_B,
	.min_pulse_width = CONFIG_SERVO_B_MIN_PULSEWIDTH,
	.max_pulse_width = CONFIG_SERVO_B_MAX_PULSEWIDTH,
	.max_degree = CONFIG_SERVO_B_MAX_DEGREE,
	.mcpwm_num = MCPWM_UNIT_0,
	.timer_num = MCPWM_TIMER_0,
	.gen = MCPWM_OPR_B,
};

servo_config servo_c = {
	.servo_pin = SERVO_C,
	.min_pulse_width = CONFIG_SERVO_C_MIN_PULSEWIDTH,
	.max_pulse_width = CONFIG_SERVO_C_MAX_PULSEWIDTH,
	.max_degree = CONFIG_SERVO_C_MAX_DEGREE,
	.mcpwm_num = MCPWM_UNIT_0,
	.timer_num = MCPWM_TIMER_1,
	.gen = MCPWM_OPR_A,
};

servo_config servo_d = {
	.servo_pin = SERVO_D,
	.min_pulse_width = CONFIG_SERVO_D_MIN_PULSEWIDTH,
	.max_pulse_width = CONFIG_SERVO_D_MAX_PULSEWIDTH,
	.max_degree = CONFIG_SERVO_D_MAX_DEGREE,
	.mcpwm_num = MCPWM_UNIT_0,
	.timer_num = MCPWM_TIMER_1,
	.gen = MCPWM_OPR_B,
};
servo_config servo_e = {
	.servo_pin = SERVO_E,
	.min_pulse_width = CONFIG_SERVO_E_MIN_PULSEWIDTH,
	.max_pulse_width = CONFIG_SERVO_E_MAX_PULSEWIDTH,
	.max_degree = CONFIG_SERVO_E_MAX_DEGREE,
	.mcpwm_num = MCPWM_UNIT_0,
	.timer_num = MCPWM_TIMER_1,
	.gen = MCPWM_OPR_B,
};
#ifdef CONFIG_ENABLE_OLED



#endif

static void mcpwm_servo_control(void *arg)
{
	enable_servo();

	while (1)
	{
		for (int i = 0; i < 130; i++)
		{
			set_angle_servo(&servo_a, i);
			set_angle_servo(&servo_b, i);
			set_angle_servo(&servo_c, i);
			set_angle_servo(&servo_d, i);
			set_angle_servo(&servo_e, i);
			vTaskDelay(5);
		}

		for (int i = 130; i > 0; i--)
		{
			set_angle_servo(&servo_a, i);
			set_angle_servo(&servo_b, i);
			set_angle_servo(&servo_c, i);
			set_angle_servo(&servo_d, i);
			set_angle_servo(&servo_e, i);
			vTaskDelay(5);
		}
	}
}

void app_main()
{
	ESP_LOGD(TAG, "Testing servo motors\n");



	xTaskCreatePinnedToCore(mcpwm_servo_control, "mcpwm_example_servo_control", 4096, NULL, 5, NULL, 1);
}
