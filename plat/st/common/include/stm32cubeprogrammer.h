/*
 * Copyright (c) 2015-2020, STMicroelectronics - All Rights Reserved
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef STM32CUBEPROGRAMMER_H
#define STM32CUBEROGRAMMER_H

/* Phase definition */
#define PHASE_FLASHLAYOUT	0U
#define PHASE_FSBL1		1U
#define PHASE_FSBL2		2U
#define PHASE_SSBL		3U
#define PHASE_CMD		0xF1U
#define PHASE_RESET		0xFFU

/* Command definition */
#define GET_CMD_COMMAND		0x00U
#define GET_VER_COMMAND		0x01U
#define GET_ID_COMMAND		0x02U
#define PHASE_COMMAND		0x03U
#define START_COMMAND		0x21U
#define DOWNLOAD_COMMAND	0x31U

/* Answer defines  */
#define INIT_BYTE		0x7FU
#define ACK_BYTE		0x79U
#define NACK_BYTE		0x1FU
#define ABORT			0x5FU

#define DEVICE_ID_BYTE1		0x05U
#define DEVICE_ID_BYTE2		0x00U

/* Functions provided by plat */
uint8_t usb_dfu_get_phase(uint8_t alt);

int stm32cubeprog_usb_load(unsigned int image_id,
			   usb_handle_t *usb_core_handle,
			   uintptr_t flashlayout_base,
			   size_t flashlayout_len,
			   uintptr_t ssbl_base,
			   size_t ssbl_len);

#endif /* STM32CUBEROGRAMMER_H */