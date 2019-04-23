/*
 * dtw_helper.c
 *
 *  Created on: Feb 25, 2019
 *      Author: dizcza
 */

#include <stdio.h>
#include "stm32f429i_discovery_lcd.h"
#include "char_pattern.h"
#include "Preprocess/preprocess.h"

void CharPattern_PrintResult(const CharPattern_PredictedInfo* resultInfo) {
	uint8_t message[20];
	uint16_t start_line = 0;
	const float fps = 1000.f / resultInfo->duration;
	sprintf((char*) message, "You wrote: %c", (char) resultInfo->predicted_char);
	BSP_LCD_DisplayStringAtLine(start_line++, message);
	sprintf((char*) message, "FPS: %.2f", fps);
	BSP_LCD_DisplayStringAtLine(start_line++, message);
	sprintf((char*) message, "Probability: %.5f", resultInfo->probability);
	BSP_LCD_DisplayStringAtLine(start_line++, message);
}

void CharPattern_Draw(const CharPattern* pattern) {
	assert_param(pattern->size <= PATTERN_SIZE);
	uint16_t bufferX[PATTERN_SIZE], bufferY[PATTERN_SIZE];
	uint32_t i;
	BBox screen_box = {0.f, 0.f, BSP_LCD_GetXSize(), BSP_LCD_GetYSize() };
	Preprocess_NormalizeInverse(pattern, bufferX, bufferY, &screen_box);
	BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
	for (i = 1; i < pattern->size; i++) {
		BSP_LCD_DrawLine(bufferX[i-1], bufferY[i-1], bufferX[i], bufferY[i]);
	}
	BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
}
