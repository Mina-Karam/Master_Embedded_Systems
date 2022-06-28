/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define Acc 1
#define NoAcc 0
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
CAN_HandleTypeDef hcan;

/* USER CODE BEGIN PV */
uint8_t Tx_Data[8];
uint8_t FrameNo = 0;
uint8_t Rx_Data[8];
uint16_t RxID, RxDLC, Acc_ON;
uint8_t Speed = 0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_CAN_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

//		*** Polling mode operation ***
//	      (#) Transmission:
//	            (++) Monitor the Tx mailboxes availability until at least one Tx
//	                 mailbox is free, using HAL_CAN_GetTxMailboxesFreeLevel().
//	            (++) Then request transmission of a message using
//	                 HAL_CAN_AddTxMessage().
void CAN_Tx(uint32_t ID, uint8_t DLC, uint8_t *payload, uint8_t pollingEnable)
{
	uint32_t pTxMailBox, noFreeTxMailBox = 0;
	CAN_TxHeaderTypeDef pHeader;

	pHeader.DLC = DLC;
	pHeader.IDE = CAN_ID_STD;
	pHeader.RTR = CAN_RTR_DATA;
	pHeader.StdId = ID;

//    (++) HAL_CAN_GetTxMailboxesFreeLevel() to get the number of free Tx
//         mailboxes.
	noFreeTxMailBox = HAL_CAN_GetTxMailboxesFreeLevel(&hcan);

	if(noFreeTxMailBox)
	{
//        (++) HAL_CAN_AddTxMessage() to request transmission of a new
//             message.
		if(HAL_CAN_AddTxMessage(&hcan, &pHeader, payload, &pTxMailBox) != HAL_OK)
		{
			Error_Handler();
		}
//        (++) HAL_CAN_IsTxMessagePending() to check if a message is pending
//             in a Tx mailbox.

		if(pollingEnable)
		{
			// Wait untill Tx MailBox is transmitted (Polling Mechanism).
			while(HAL_CAN_IsTxMessagePending(&hcan,pTxMailBox));
		}

	}

}

void CAN_Rx_Filter_Init(uint16_t STD_Filter_ID,uint16_t STD_Filter_Mask)
{
	CAN_FilterTypeDef sFilterConfig;

	sFilterConfig.FilterActivation = CAN_FILTER_ENABLE;
	sFilterConfig.FilterBank = 0;
	sFilterConfig.FilterFIFOAssignment = CAN_FILTER_FIFO0;
	sFilterConfig.FilterIdHigh = STD_Filter_ID << 5;
	sFilterConfig.FilterIdLow = 0x0000;
	sFilterConfig.FilterMaskIdHigh = STD_Filter_Mask << 5;
	sFilterConfig.FilterMaskIdLow = 0x0000;

	sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
	sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;

	if(HAL_CAN_ConfigFilter(&hcan, &sFilterConfig) != HAL_OK)
		Error_Handler();
}

//		*** Polling mode operation ***
//	  (#) Reception:
//	            (++) Monitor reception of message using HAL_CAN_GetRxFifoFillLevel()
//	                 until at least one message is received.
//	            (++) Then get the message using HAL_CAN_GetRxMessage().

//STD_ID
//Data Frame
void CAN_Rx(uint32_t* ID, uint8_t* DLC, uint8_t *payload, uint8_t pollingEnable)
{
	CAN_RxHeaderTypeDef pHeader;

	if(pollingEnable)
	{
		// Wait until receive CAN message on fifo 0
		while(HAL_CAN_GetRxFifoFillLevel(&hcan, CAN_FILTER_FIFO0) == 0);
	}

	if(HAL_CAN_GetRxMessage(&hcan, CAN_FILTER_FIFO0, &pHeader, payload) != HAL_OK)
		Error_Handler();

	*ID = pHeader.StdId;
	*DLC = pHeader.DLC;
}

/* Callbacks functions ********************************************************/
void HAL_CAN_TxMailbox0CompleteCallback(CAN_HandleTypeDef *hcan)
{
	// DO NOTHING
}
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
	// Receive Speed form ECU2
	CAN_Rx(&RxID, &RxDLC, Rx_Data, 0);
	// Note: If there is multiple ID we will put if condition with every ID
	Speed = Rx_Data[0];
}
void HAL_CAN_ErrorCallback(CAN_HandleTypeDef *hcan)
{
	/*!< TxMailbox 0 transmit failure due to transmit error    */
	if((hcan->ErrorCode & HAL_CAN_ERROR_TX_TERR0) == HAL_CAN_ERROR_TX_TERR0)
	{

	}
}


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_CAN_Init();
  /* USER CODE BEGIN 2 */

  //Rx filter
  CAN_Rx_Filter_Init(0x3AB, 0x7FF);

  // Interrupt CAN Notification
  if(HAL_CAN_ActivateNotification(&hcan, (CAN_IT_TX_MAILBOX_EMPTY | CAN_IT_RX_FIFO0_MSG_PENDING)) != HAL_OK)
  {
	  Error_Handler();
  }

  //Start CAN
  if(HAL_CAN_Start(&hcan) != HAL_OK)
  {
	  Error_Handler();
  }

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  Tx_Data[0] = Acc;
  while (1)
  {
    /* USER CODE END WHILE */
	HAL_Delay(1000);
	CAN_Tx(0x030, 1, Tx_Data, 0);
	Tx_Data[0] ^= 1; // 1 -> Acc, 0 -> NoAcc 0
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief CAN Initialization Function
  * @param None
  * @retval None
  */
static void MX_CAN_Init(void)
{

  /* USER CODE BEGIN CAN_Init 0 */

  /* USER CODE END CAN_Init 0 */

  /* USER CODE BEGIN CAN_Init 1 */

  /* USER CODE END CAN_Init 1 */
  hcan.Instance = CAN1;
  hcan.Init.Prescaler = 1;
  hcan.Init.Mode = CAN_MODE_NORMAL;
  hcan.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan.Init.TimeSeg1 = CAN_BS1_6TQ;
  hcan.Init.TimeSeg2 = CAN_BS2_1TQ;
  hcan.Init.TimeTriggeredMode = DISABLE;
  hcan.Init.AutoBusOff = DISABLE;
  hcan.Init.AutoWakeUp = DISABLE;
  hcan.Init.AutoRetransmission = DISABLE;
  hcan.Init.ReceiveFifoLocked = DISABLE;
  hcan.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN_Init 2 */

  /* USER CODE END CAN_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

