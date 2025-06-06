/**
  ******************************************************************************
  * @file    stm32u3xx_hal_ramcfg.h
  * @author  MCD Application Team
  * @brief   Header file of RAMCFG HAL module.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32U3xx_HAL_RAMCFG_H
#define STM32U3xx_HAL_RAMCFG_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32u3xx_hal_def.h"

/** @addtogroup STM32U3xx_HAL_Driver
  * @{
  */

/** @addtogroup RAMCFG
  * @{
  */

/* Exported types ------------------------------------------------------------*/

/** @defgroup RAMCFG_Exported_Types RAMCFG Exported Types
  * @brief    RAMCFG Exported Types
  * @{
  */

/**
  * @brief  HAL RAMCFG State Enumeration Definition
  */
typedef enum
{
  HAL_RAMCFG_STATE_RESET             = 0x00U,  /*!< RAMCFG not yet initialized or disabled */
  HAL_RAMCFG_STATE_READY             = 0x01U,  /*!< RAMCFG initialized and ready for use   */
  HAL_RAMCFG_STATE_BUSY              = 0x02U,  /*!< RAMCFG process is ongoing              */
  HAL_RAMCFG_STATE_ERROR             = 0x03U,  /*!< RAMCFG error state                     */
} HAL_RAMCFG_StateTypeDef;

#if (USE_HAL_RAMCFG_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL RAMCFG Callbacks IDs Enumeration Definition
  */
typedef enum
{
  HAL_RAMCFG_MSPINIT_CB_ID           = 0x00U,  /*!< RAMCFG MSP Init Callback ID            */
  HAL_RAMCFG_MSPDEINIT_CB_ID         = 0x01U,  /*!< RAMCFG MSP DeInit Callback ID          */
  HAL_RAMCFG_PE_DETECT_CB_ID         = 0x02U,  /*!< RAMCFG Parity Error Detect Callback ID */
  HAL_RAMCFG_ALL_CB_ID               = 0x03U,  /*!< RAMCFG All callback ID                 */
} HAL_RAMCFG_CallbackIDTypeDef;
#endif /* USE_HAL_RAMCFG_REGISTER_CALLBACKS */

/**
  * @brief  RAMCFG Handle Structure Definition
  */
#if (USE_HAL_RAMCFG_REGISTER_CALLBACKS == 1U)
typedef struct __RAMCFG_HandleTypeDef
#else
typedef struct
#endif /* (USE_HAL_RAMCFG_REGISTER_CALLBACKS) */
{
  RAMCFG_TypeDef                  *Instance;                                   /*!< RAMCFG Register Base Address        */
  __IO HAL_RAMCFG_StateTypeDef    State;                                       /*!< RAMCFG State                        */
  __IO uint32_t                   ErrorCode;                                   /*!< RAMCFG Error Code                   */
#if (USE_HAL_RAMCFG_REGISTER_CALLBACKS == 1U)
  void (* MspInitCallback)(struct __RAMCFG_HandleTypeDef *hramcfg);            /*!< RAMCFG MSP Init Callback            */
  void (* MspDeInitCallback)(struct __RAMCFG_HandleTypeDef *hramcfg);          /*!< RAMCFG MSP DeInit Callback          */
  void (* DetectParityErrorCallback)(struct __RAMCFG_HandleTypeDef *hramcfg);  /*!< RAMCFG Parity Error Detect Callback */
#endif  /* USE_HAL_RAMCFG_REGISTER_CALLBACKS */
} RAMCFG_HandleTypeDef;
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/

/** @defgroup RAMCFG_Exported_Constants RAMCFG Exported Constants
  * @brief    RAMCFG Exported Constants
  * @{
  */

/** @defgroup RAMCFG_Error_Codes RAMCFG Error Codes
  * @brief    RAMCFG Error Codes
  * @{
  */
#define HAL_RAMCFG_ERROR_NONE             0x00000000U  /*!< RAMCFG No Error         */
#define HAL_RAMCFG_ERROR_TIMEOUT          0x00000001U  /*!< RAMCFG Timeout Error    */
#define HAL_RAMCFG_ERROR_BUSY             0x00000002U  /*!< RAMCFG Busy Error       */
#if (USE_HAL_RAMCFG_REGISTER_CALLBACKS == 1U)
#define HAL_RAMCFG_ERROR_INVALID_CALLBACK 0x00000003U  /*!< Invalid Callback error  */
#endif  /* USE_HAL_RAMCFG_REGISTER_CALLBACKS */
/**
  * @}
  */

/** @defgroup RAMCFG_Interrupt RAMCFG Interrupts
  * @brief    RAMCFG Interrupts
  * @{
  */
#define RAMCFG_IT_PARITYERR     RAMCFG_IER_PEIE     /*!< RAMCFG Parity Error Interrupt                   */
#define RAMCFG_IT_NMIERR        RAMCFG_IER_PENMI    /*!< RAMCFG Parity Error redirected to NMI Interrupt */
#define RAMCFG_IT_ALL           (RAMCFG_IER_PEIE | \
                                 RAMCFG_IER_PENMI)  /*!< RAMCFG All RAMCFG interrupt                     */
/**
  * @}
  */

/** @defgroup RAMCFG_FLAG RAMCFG Monitor Flags
  * @brief    RAMCFG Monitor Flags
  * @{
  */
#define RAMCFG_FLAG_PARITYERR   RAMCFG_ISR_PED        /*!< RAMCFG Parity Error Detected Flag */
#define RAMCFG_FLAG_SRAMBUSY    RAMCFG_ISR_SRAMBUSY   /*!< RAMCFG SRAM busy Flag             */
#define RAMCFG_FLAGS_ALL        (RAMCFG_ISR_PED | \
                                 RAMCFG_ISR_SRAMBUSY) /*!< RAMCFG All Flags                  */
/**
  * @}
  */

/** @defgroup RAMCFG_Keys RAMCFG Keys
  * @brief    RAMCFG Keys
  * @{
  */
#define RAMCFG_ERASE_KEY1  (0xCAU) /*!< RAMCFG launch Erase Write Protection Key 1 */
#define RAMCFG_ERASE_KEY2  (0x53U) /*!< RAMCFG launch Erase Write Protection Key 2 */

#define RAMCFG_PARITY_KEY1 (0xAEU) /*!< RAMCFG launch Parity Write Protection Key 1 */
#define RAMCFG_PARITY_KEY2 (0x75U) /*!< RAMCFG launch PArity Write Protection Key 2 */
/**
  * @}
  */


/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/

/** @defgroup RAMCFG_Exported_Macros RAMCFG Exported Macros
  * @brief    RAMCFG Exported Macros
  * @{
  */

/**
  * @brief  Enable the specified RAMCFG interrupts.
  * @param  __HANDLE__   : Specifies RAMCFG handle.
  * @param  __INTERRUPT__: Specifies the RAMCFG interrupt sources to be enabled.
  *         This parameter can be one of the following values:
  *           @arg RAMCFG_IT_PARITYERR    : Parity Error Interrupt Mask.
  *           @arg RAMCFG_IT_NMIERR       : Parity Error Interrupt redirection to NMI Mask.
  *           @arg RAMCFG_IT_ALL          : All Interrupt Mask.
  * @retval None
  */
#define __HAL_RAMCFG_ENABLE_IT(__HANDLE__, __INTERRUPT__) ((__HANDLE__)->Instance->IER |= (__INTERRUPT__))

/**
  * @brief  Disable the specified RAMCFG interrupts.
  * @note   This macros is used only to disable RAMCFG_IT_PARITYERR interrupt.
  *         RAMCFG_IT_NMIERR interrupt can only be disabled by global
  *         peripheral reset or system reset.
  * @param  __HANDLE__   : Specifies RAMCFG handle.
  * @param  __INTERRUPT__: Specifies the RAMCFG interrupt sources to be disabled.
  *         This parameter can be one of the following values:
  *           @arg RAMCFG_IT_PARITYERR    : Parity Error Interrupt Mask.
  * @retval None
  */
#define __HAL_RAMCFG_DISABLE_IT(__HANDLE__, __INTERRUPT__) ((__HANDLE__)->Instance->IER &= ~(__INTERRUPT__))

/**
  * @brief  Check whether the specified RAMCFG interrupt source is enabled or not.
  * @param  __HANDLE__    : Specifies the RAMCFG Handle.
  * @param  __INTERRUPT__ : Specifies the RAMCFG interrupt source to check.
  *          This parameter can be one of the following values:
  *           @arg RAMCFG_IT_PARITYERR    : Parity Error Interrupt Mask.
  *           @arg RAMCFG_IT_NMIERR       : Parity Error Interrupt redirection to NMI Mask.
  * @retval The new state of __INTERRUPT__ (SET or RESET).
  */
#define __HAL_RAMCFG_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) ((((__HANDLE__)->Instance->IER\
                                                                 & (__INTERRUPT__)) == (__INTERRUPT__)) ? 1U : 0U)

/**
  * @brief  Get the RAMCFG pending flags.
  * @param  __HANDLE__   : Specifies RAMCFG handle.
  * @param  __FLAG__     : Specifies the flag to be checked.
  *         This parameter can be one of the following values:
  *            @arg RAMCFG_FLAG_PARITYERR  : Parity Error Detected Flag.
  *            @arg RAMCFG_FLAG_SRAMBUSY   : SRAM Busy Flag.
  * @retval The state of FLAG (SET or RESET).
  */
#define __HAL_RAMCFG_GET_FLAG(__HANDLE__, __FLAG__) (READ_BIT((__HANDLE__)->Instance->ISR, (__FLAG__)) == (__FLAG__))

/**
  * @brief  Clear the RAMCFG pending flags.
  * @param  __HANDLE__   : Specifies RAMCFG handle.
  * @param  __FLAG__     : Specifies the flag to be cleared.
  *          This parameter can be any combination of the following values:
  *            @arg RAMCFG_FLAG_PARITYERR  : Parity Error Detected and Flag.
  * @retval None.
  */
#define __HAL_RAMCFG_CLEAR_FLAG(__HANDLE__, __FLAG__) (WRITE_REG((__HANDLE__)->Instance->ICR, (__FLAG__)))

/** @brief  Reset the RAMCFG handle state.
  * @param  __HANDLE__    : Specifies the RAMCFG Handle.
  * @retval None.
  */
#if (USE_HAL_RAMCFG_REGISTER_CALLBACKS == 1)
#define __HAL_RAMCFG_RESET_HANDLE_STATE(__HANDLE__) do{\
                                                        (__HANDLE__)->State = HAL_RAMCFG_STATE_RESET; \
                                                        (__HANDLE__)->MspInitCallback   = NULL;       \
                                                        (__HANDLE__)->MspDeInitCallback = NULL;       \
                                                      }while(0)
#else
#define __HAL_RAMCFG_RESET_HANDLE_STATE(__HANDLE__) do{\
                                                        (__HANDLE__)->State = HAL_RAMCFG_STATE_RESET; \
                                                      }while(0)
#endif /* USE_HAL_RAMCFG_REGISTER_CALLBACKS */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/

/** @defgroup RAMCFG_Exported_Functions RAMCFG Exported Functions
  * @brief    RAMCFG Exported Functions
  * @{
  */

/** @defgroup RAMCFG_Exported_Functions_Group1 Initialization and De-Initialization Functions
  * @brief    Initialization and De-Initialization Functions
  * @{
  */
HAL_StatusTypeDef HAL_RAMCFG_Init(RAMCFG_HandleTypeDef *hramcfg);
HAL_StatusTypeDef HAL_RAMCFG_DeInit(RAMCFG_HandleTypeDef *hramcfg);
void HAL_RAMCFG_MspInit(RAMCFG_HandleTypeDef *hramcfg);
void HAL_RAMCFG_MspDeInit(RAMCFG_HandleTypeDef *hramcfg);
/**
  * @}
  */

/** @defgroup RAMCFG_Exported_Functions_Group2 Parity Error Detection Functions
  * @brief    Parity Error Detection Functions
  * @{
  */
HAL_StatusTypeDef HAL_RAMCFG_EnableParityErrorDetection(RAMCFG_HandleTypeDef *hramcfg);
HAL_StatusTypeDef HAL_RAMCFG_DisableParityErrorDetection(RAMCFG_HandleTypeDef *hramcfg);
HAL_StatusTypeDef HAL_RAMCFG_LatchParityErrorAddress(RAMCFG_HandleTypeDef *hramcfg);
HAL_StatusTypeDef HAL_RAMCFG_UnlatchParityErrorAddress(RAMCFG_HandleTypeDef *hramcfg);
HAL_StatusTypeDef HAL_RAMCFG_EnableNotification(RAMCFG_HandleTypeDef *hramcfg, uint32_t Notifications);
HAL_StatusTypeDef HAL_RAMCFG_DisableNotification(RAMCFG_HandleTypeDef *hramcfg, uint32_t Notifications);
uint32_t HAL_RAMCFG_IsParityErrorDetected(const RAMCFG_HandleTypeDef *hramcfg);
uint32_t HAL_RAMCFG_GetParityErrorAddress(const RAMCFG_HandleTypeDef *hramcfg);
/**
  * @}
  */

/** @defgroup RAMCFG_Exported_Functions_Group3 Write Protection Functions
  * @brief    Write Protection Functions
  * @{
  */
HAL_StatusTypeDef HAL_RAMCFG_EnableWriteProtection(RAMCFG_HandleTypeDef *hramcfg, uint32_t StartPage, uint32_t NbPage);
/**
  * @}
  */

/** @defgroup RAMCFG_Exported_Functions_Group4 Erase Operation Functions
  * @brief    Erase Operation Functions
  * @{
  */
HAL_StatusTypeDef HAL_RAMCFG_Erase(RAMCFG_HandleTypeDef *hramcfg);
/**
  * @}
  */

/** @defgroup RAMCFG_Exported_Functions_Group5 Handle Interrupt and Callbacks Functions
  * @brief    Handle Interrupt and Callbacks Functions
  * @{
  */
void              HAL_RAMCFG_IRQHandler(RAMCFG_HandleTypeDef *hramcfg);
void              HAL_RAMCFG_DetectParityErrorCallback(RAMCFG_HandleTypeDef *hramcfg);
#if (USE_HAL_RAMCFG_REGISTER_CALLBACKS == 1)
HAL_StatusTypeDef HAL_RAMCFG_RegisterCallback(RAMCFG_HandleTypeDef *hramcfg,
                                              HAL_RAMCFG_CallbackIDTypeDef CallbackID,
                                              void (* pCallback)(RAMCFG_HandleTypeDef *_hramcfg));
HAL_StatusTypeDef HAL_RAMCFG_UnRegisterCallback(RAMCFG_HandleTypeDef *hramcfg, HAL_RAMCFG_CallbackIDTypeDef CallbackID);
#endif /* USE_HAL_RAMCFG_REGISTER_CALLBACKS */
/**
  * @}
  */

/** @defgroup RAMCFG_Exported_Functions_Group6 State and Error Functions
  * @brief    State and Error Functions
  * @{
  */
uint32_t HAL_RAMCFG_GetError(const RAMCFG_HandleTypeDef *hramcfg);
HAL_RAMCFG_StateTypeDef HAL_RAMCFG_GetState(const RAMCFG_HandleTypeDef *hramcfg);
/**
  * @}
  */

/**
  * @}
  */

/* Private Constants ---------------------------------------------------------*/

/** @defgroup RAMCFG_Private_Constants RAMCFG Private Defines and Constants
  * @brief    RAMCFG Private Defines and Constants
  * @{
  */
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/

/** @defgroup RAMCFG_Private_Macros RAMCFG Private Macros
  * @brief    RAMCFG Private Macros
  * @{
  */
#define IS_RAMCFG_INTERRUPT(INTERRUPT)  (((INTERRUPT) != 0U) &&\
                                         (((INTERRUPT) & ~(RAMCFG_IT_PARITYERR | RAMCFG_IT_NMIERR)) == 0U))

#define IS_RAMCFG_WRITEPROTECTION_PAGE(PAGE)   ((PAGE) <= 64U)
/**
  * @}
  */





/* Private functions ---------------------------------------------------------*/

/** @defgroup RAMCFG_Private_Functions RAMCFG Private Functions
  * @brief    RAMCFG Private Functions
  * @{
  */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif


#endif /* STM32U3xx_HAL_RAMCFG_H */

