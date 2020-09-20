/**
  ******************************************************************************
  * @file           : main.cpp
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 RoboJackets.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by RoboJackets under Apache License
  * 2.0; You may not use this file except in compliance with the License. You 
  * may obtain a copy of the License at: 
  *                    https://www.apache.org/licenses/LICENSE-2.0
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "mJackets.hpp"

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

int sampleFunction(int);

/* Private user code ---------------------------------------------------------*/

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* Standard Hal Initialization */
  MPU_Config();
  CPU_CACHE_Enable();
  HAL_Init();

  /* Clock Setup */
  ClockInitStruct init;
  init.ClockSource = CLOCK_SOURCE_HSE;
  init.SystemFrequency = SYS_FREQ_100MHZ;
  init.HSEMultiplier = 432;
  init.HSEDivider1 =  25;
  init.HSEDivider2 = RCC_PLLP_DIV2;
  init.HSE48CKDivider = 2;
  init.AHBClkDivider = RCC_SYSCLK_DIV1;
  init.APB1ClkDivider = RCC_HCLK_DIV4;
  init.APB2ClkDivider = RCC_HCLK_DIV2;
  init.FlashLatency = 7;
  SystemClock_Config(init);

  DWT_Config();

  /* GPIO Configuration */
  __HAL_RCC_GPIOE_CLK_ENABLE();  // This will eventually be handled automatically by the hardware manager
  DigitalOut led1(LED1, PullNone, PushPull);
  DigitalOut led2(LED2, PullNone, PushPull);
  DigitalOut led3(LED3, PullNone, PushPull);
  DigitalOut led4(LED4, PullNone, PushPull);

  uint32_t num = 0;

  /* Infinite loop */
  while (1)
  {
    led1.toggle();
    led4.toggle();
    HAL_Delay(200);
  }

}

/**
  * @brief  Function Description
  * @note Put any Notes Here
  * @param val Sample input argument
  * @retval Returns input argument
  */
int sampleFunction(int val)
{
    return val;
}

