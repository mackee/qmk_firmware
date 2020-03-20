/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/*
 * This file has been automatically generated using ChibiStudio board
 * generator plugin. Do not edit manually.
 */

#ifndef BOARD_H
#define BOARD_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*
 * Setup for Pulsar Rev2.
 */

/*
 * Board identifier.
 */
#define BOARD_PULSER_REV2
#define BOARD_NAME                  "Pulsar Rev.2"

/*
 * Board oscillators-related settings.
 * NOTE: LSE not fitted.
 */
#if !defined(STM32_LSECLK)
#define STM32_LSECLK                0U
#endif

#define STM32_LSEDRV                (3U << 3U)

#if !defined(STM32_HSECLK)
#define STM32_HSECLK                0U
#endif

#define STM32_HSE_BYPASS

/*
 * MCU type as defined in the ST header.
 */
#define STM32F072xB

/*
 * IO pins assignments.
 */
#define GPIOA_SW1                   0U
#define GPIOA_SW2                   1U
#define GPIOA_SW3                   2U
#define GPIOA_SW4                   3U
#define GPIOA_SW5                   4U
#define GPIOA_SW6                   5U
#define GPIOA_SW7                   6U
#define GPIOA_SW8                   7U
#define GPIOA_SW9                   8U
#define GPIOA_SW10                  9U
#define GPIOA_SW11                  10U
#define GPIOA_USB_DM                11U
#define GPIOA_USB_DP                12U
#define GPIOA_SWDIO                 13U
#define GPIOA_SWCLK                 14U

#define GPIOB_ROT_A                 0U
#define GPIOB_ROT_B                 1U
#define GPIOB_LEV_1                 8U
#define GPIOB_LEV_2                 9U
#define GPIOB_LEV_T                 10U
#define GPIOB_LEV_3                 11U
#define GPIOB_LEV_4                 12U
#define GPIOB_LED_DATA              13U

/*
 * IO lines assignments.
 */
#define LINE_USB_DM                 PAL_LINE(GPIOA, 11U)
#define LINE_USB_DP                 PAL_LINE(GPIOA, 12U)
#define LINE_SWDIO                  PAL_LINE(GPIOA, 13U)
#define LINE_SWDCLK                 PAL_LINE(GPIOA, 14U)

#define LINE_LED_DATA               PAL_LINE(GPIOB, 13U)

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 * Please refer to the STM32 Reference Manual for details.
 */
#define PIN_MODE_INPUT(n)           (0U << ((n) * 2U))
#define PIN_MODE_OUTPUT(n)          (1U << ((n) * 2U))
#define PIN_MODE_ALTERNATE(n)       (2U << ((n) * 2U))
#define PIN_MODE_ANALOG(n)          (3U << ((n) * 2U))
#define PIN_ODR_LOW(n)              (0U << (n))
#define PIN_ODR_HIGH(n)             (1U << (n))
#define PIN_OTYPE_PUSHPULL(n)       (0U << (n))
#define PIN_OTYPE_OPENDRAIN(n)      (1U << (n))
#define PIN_OSPEED_VERYLOW(n)       (0U << ((n) * 2U))
#define PIN_OSPEED_LOW(n)           (1U << ((n) * 2U))
#define PIN_OSPEED_MEDIUM(n)        (2U << ((n) * 2U))
#define PIN_OSPEED_HIGH(n)          (3U << ((n) * 2U))
#define PIN_PUPDR_FLOATING(n)       (0U << ((n) * 2U))
#define PIN_PUPDR_PULLUP(n)         (1U << ((n) * 2U))
#define PIN_PUPDR_PULLDOWN(n)       (2U << ((n) * 2U))
#define PIN_AFIO_AF(n, v)           ((v) << (((n) % 8U) * 4U))

/*
 * GPIOA setup:
 * SW1    (input pullup)
 * SW2    (input pullup)
 * SW3    (input pullup)
 * SW4    (input pullup)
 * SW5    (input pullup)
 * SW6    (input pullup)
 * SW7    (input pullup)
 * SW8    (input pullup)
 * SW9    (input pullup)
 * SW10   (input pullup)
 * SW11   (input pullup)
 * USB_DM (input floating)
 * USB_DP (input floating)
 * SWDIO  (alternate 0)
 * SWCLK  (alternate 0)
 */
#define VAL_GPIOA_MODER             (PIN_MODE_INPUT(GPIOA_SW1) |            \
                                     PIN_MODE_INPUT(GPIOA_SW2) |            \
                                     PIN_MODE_INPUT(GPIOA_SW3) |            \
                                     PIN_MODE_INPUT(GPIOA_SW4) |            \
                                     PIN_MODE_INPUT(GPIOA_SW5) |            \
                                     PIN_MODE_INPUT(GPIOA_SW6) |            \
                                     PIN_MODE_INPUT(GPIOA_SW7) |            \
                                     PIN_MODE_INPUT(GPIOA_SW8) |            \
                                     PIN_MODE_INPUT(GPIOA_SW9) |            \
                                     PIN_MODE_INPUT(GPIOA_SW10) |           \
                                     PIN_MODE_INPUT(GPIOA_SW11) |           \
                                     PIN_MODE_INPUT(GPIOA_USB_DM) |         \
                                     PIN_MODE_INPUT(GPIOA_USB_DP) |         \
                                     PIN_MODE_ALTERNATE(GPIOA_SWDIO) |      \
                                     PIN_MODE_ALTERNATE(GPIOA_SWCLK))
#define VAL_GPIOA_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOA_SW1) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SW2) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SW3) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SW4) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SW5) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SW6) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SW7) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SW8) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SW9) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SW10) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SW11) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_USB_DM) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOA_USB_DP) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SWDIO) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SWCLK))
#define VAL_GPIOA_OSPEEDR           (PIN_OSPEED_VERYLOW(GPIOA_SW1) |        \
                                     PIN_OSPEED_VERYLOW(GPIOA_SW2) |        \
                                     PIN_OSPEED_VERYLOW(GPIOA_SW3) |        \
                                     PIN_OSPEED_VERYLOW(GPIOA_SW4) |        \
                                     PIN_OSPEED_VERYLOW(GPIOA_SW5) |        \
                                     PIN_OSPEED_VERYLOW(GPIOA_SW6) |        \
                                     PIN_OSPEED_VERYLOW(GPIOA_SW7) |        \
                                     PIN_OSPEED_VERYLOW(GPIOA_SW8) |        \
                                     PIN_OSPEED_VERYLOW(GPIOA_SW9) |        \
                                     PIN_OSPEED_VERYLOW(GPIOA_SW10) |       \
                                     PIN_OSPEED_VERYLOW(GPIOA_SW11) |       \
                                     PIN_OSPEED_VERYLOW(GPIOA_USB_DM) |     \
                                     PIN_OSPEED_VERYLOW(GPIOA_USB_DP) |     \
                                     PIN_OSPEED_HIGH(GPIOA_SWDIO) |         \
                                     PIN_OSPEED_HIGH(GPIOA_SWCLK))
#define VAL_GPIOA_PUPDR             (PIN_PUPDR_PULLUP(GPIOA_SW1) |          \
                                     PIN_PUPDR_PULLUP(GPIOA_SW2) |          \
                                     PIN_PUPDR_PULLUP(GPIOA_SW3) |          \
                                     PIN_PUPDR_PULLUP(GPIOA_SW4) |          \
                                     PIN_PUPDR_PULLUP(GPIOA_SW5) |          \
                                     PIN_PUPDR_PULLUP(GPIOA_SW6) |          \
                                     PIN_PUPDR_PULLUP(GPIOA_SW7) |          \
                                     PIN_PUPDR_PULLUP(GPIOA_SW8) |          \
                                     PIN_PUPDR_PULLUP(GPIOA_SW9) |          \
                                     PIN_PUPDR_PULLUP(GPIOA_SW10) |         \
                                     PIN_PUPDR_PULLUP(GPIOA_SW11) |         \
                                     PIN_PUPDR_FLOATING(GPIOA_USB_DM) |     \
                                     PIN_PUPDR_FLOATING(GPIOA_USB_DP) |     \
                                     PIN_PUPDR_PULLUP(GPIOA_SWDIO) |        \
                                     PIN_PUPDR_PULLUP(GPIOA_SWCLK))
#define VAL_GPIOA_ODR               (PIN_ODR_HIGH(GPIOA_SW1) |              \
                                     PIN_ODR_HIGH(GPIOA_SW2) |              \
                                     PIN_ODR_HIGH(GPIOA_SW3) |              \
                                     PIN_ODR_HIGH(GPIOA_SW4) |              \
                                     PIN_ODR_HIGH(GPIOA_SW5) |              \
                                     PIN_ODR_HIGH(GPIOA_SW6) |              \
                                     PIN_ODR_HIGH(GPIOA_SW7) |              \
                                     PIN_ODR_HIGH(GPIOA_SW8) |              \
                                     PIN_ODR_HIGH(GPIOA_SW9) |              \
                                     PIN_ODR_HIGH(GPIOA_SW10) |             \
                                     PIN_ODR_HIGH(GPIOA_SW11) |             \
                                     PIN_ODR_HIGH(GPIOA_USB_DM) |           \
                                     PIN_ODR_HIGH(GPIOA_USB_DP) |           \
                                     PIN_ODR_HIGH(GPIOA_SWDIO) |            \
                                     PIN_ODR_HIGH(GPIOA_SWCLK))
#define VAL_GPIOA_AFRL              (PIN_AFIO_AF(GPIOA_SW1, 0U) |           \
                                     PIN_AFIO_AF(GPIOA_SW2, 0U) |           \
                                     PIN_AFIO_AF(GPIOA_SW3, 0U) |           \
                                     PIN_AFIO_AF(GPIOA_SW4, 0U) |           \
                                     PIN_AFIO_AF(GPIOA_SW5, 0U) |           \
                                     PIN_AFIO_AF(GPIOA_SW6, 0U) |           \
                                     PIN_AFIO_AF(GPIOA_SW7, 0U))
#define VAL_GPIOA_AFRH              (PIN_AFIO_AF(GPIOA_SW8, 0U) |           \
                                     PIN_AFIO_AF(GPIOA_SW9, 0U) |           \
                                     PIN_AFIO_AF(GPIOA_SW10, 0U) |          \
                                     PIN_AFIO_AF(GPIOA_SW11, 0U) |          \
                                     PIN_AFIO_AF(GPIOA_USB_DM, 0U) |        \
                                     PIN_AFIO_AF(GPIOA_USB_DP, 0U) |        \
                                     PIN_AFIO_AF(GPIOA_SWDIO, 0U) |         \
                                     PIN_AFIO_AF(GPIOA_SWCLK, 0U))
/*
 * GPIOB setup:
 *
 * ROT_A                            (input pullup)
 * ROT_B                            (input pullup)
 * LEV_1                            (input pullup)
 * LEV_2                            (input pullup)
 * LEV_T                            (input pullup)
 * LEV_3                            (input pullup)
 * LEV_4                            (input pullup)
 * LED_DATA                         (output pushpull maximum)
 */
#define VAL_GPIOB_MODER             (PIN_MODE_INPUT(GPIOB_ROT_A) |          \
                                     PIN_MODE_INPUT(GPIOB_ROT_B) |          \
                                     PIN_MODE_INPUT(GPIOB_LEV_1) |          \
                                     PIN_MODE_INPUT(GPIOB_LEV_2) |          \
                                     PIN_MODE_INPUT(GPIOB_LEV_T) |          \
                                     PIN_MODE_INPUT(GPIOB_LEV_3) |          \
                                     PIN_MODE_INPUT(GPIOB_LEV_4) |          \
                                     PIN_MODE_OUTPUT(GPIOB_LED_DATA))
#define VAL_GPIOB_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOB_ROT_A) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOB_ROT_B) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOB_LEV_1) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOB_LEV_2) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOB_LEV_T) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOB_LEV_3) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOB_LEV_4) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOB_LED_DATA))
#define VAL_GPIOB_OSPEEDR           (PIN_OSPEED_VERYLOW(GPIOB_ARD_A3) |     \
                                     PIN_OSPEED_VERYLOW(GPIOB_ROT_B) |      \
                                     PIN_OSPEED_VERYLOW(GPIOB_LEV_1) |      \
                                     PIN_OSPEED_VERYLOW(GPIOB_LEV_2) |      \
                                     PIN_OSPEED_VERYLOW(GPIOB_LEV_T) |      \
                                     PIN_OSPEED_VERYLOW(GPIOB_LEV_3) |      \
                                     PIN_OSPEED_VERYLOW(GPIOB_LEV_4) |      \
                                     PIN_OSPEED_HIGH(GPIOB_LED_DATA))
#define VAL_GPIOB_PUPDR             (PIN_PUPDR_PULLUP(GPIOB_ROT_A) |        \
                                     PIN_PUPDR_PULLUP(GPIOB_ROT_B) |        \
                                     PIN_PUPDR_PULLUP(GPIOB_LEV_1) |        \
                                     PIN_PUPDR_PULLUP(GPIOB_LEV_2) |        \
                                     PIN_PUPDR_PULLUP(GPIOB_LEV_T) |        \
                                     PIN_PUPDR_PULLUP(GPIOB_LEV_3) |        \
                                     PIN_PUPDR_PULLUP(GPIOB_LEV_4) |        \
                                     PIN_PUPDR_FLOATING(GPIOB_LED_DATA))
#define VAL_GPIOB_ODR               (PIN_ODR_HIGH(GPIOB_ROT_A) |            \
                                     PIN_ODR_HIGH(GPIOB_ROT_B) |            \
                                     PIN_ODR_HIGH(GPIOB_LEV_1) |            \
                                     PIN_ODR_HIGH(GPIOB_LEV_2) |            \
                                     PIN_ODR_HIGH(GPIOB_LEV_T) |            \
                                     PIN_ODR_HIGH(GPIOB_LEV_3) |            \
                                     PIN_ODR_HIGH(GPIOB_LEV_4) |            \
                                     PIN_ODR_LOW(GPIOB_LED_DATA))
#define VAL_GPIOB_AFRL              (PIN_AFIO_AF(GPIOB_ROT_A, 0U) |         \
                                     PIN_AFIO_AF(GPIOB_ROT_B, 0U))
#define VAL_GPIOB_AFRH              (PIN_AFIO_AF(GPIOB_LEV_1, 0U) |         \
                                     PIN_AFIO_AF(GPIOB_LEV_2, 0U) |         \
                                     PIN_AFIO_AF(GPIOB_LEV_T, 0U) |         \
                                     PIN_AFIO_AF(GPIOB_LEV_3, 0U) |         \
                                     PIN_AFIO_AF(GPIOB_LEV_4, 0U) |         \
                                     PIN_AFIO_AF(GPIOB_LED_DATA, 0U))

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* BOARD_H */
