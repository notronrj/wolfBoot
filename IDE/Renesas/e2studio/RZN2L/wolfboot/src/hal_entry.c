
/* hal_entry.c
 *
 * Custom configuration for wolfCrypt/wolfSSL.
 * Enabled via WOLFSSL_USER_SETTINGS.
 *
 *
 * Copyright (C) 2024 wolfSSL Inc.
 *
 * This file is part of wolfBoot.
 *
 * wolfBoot is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * wolfBoot is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1335, USA
 */
#include "hal_data.h"
#include <stdlib.h>
#include <wolfssl/wolfcrypt/ecc.h>

FSP_CPP_HEADER
void R_BSP_WarmStart(bsp_warm_start_event_t event)
BSP_PLACE_IN_SECTION(".warm_start");
FSP_CPP_FOOTER

int loader_main(void);

/***************************************************************************//**
 * main() is generated by the FSP Configuration editor
 * and is used to generate threads if an RTOS is used.  This function
 * is called by main() when no RTOS is used.
 ******************************************************************************/
void hal_entry(void)
{
    /* */
    loader_main();
}

/***************************************************************************//**
 * This function is called at various points during the startup process.
 * This implementation uses the event that is
 * called right before main() to set up the pins.
 *
 * @param[in]  event   Where at in the start up process the code is currently at
 ******************************************************************************/
void R_BSP_WarmStart(bsp_warm_start_event_t event)
{
    if (BSP_WARM_START_RESET == event)
    {
        /* Pre clock initialization */
    }

    if (BSP_WARM_START_POST_C == event)
    {
        /* C runtime environment and system clocks are setup. */

        /* Configure pins. */
        R_IOPORT_Open (&g_ioport_ctrl, &g_bsp_pin_cfg);
    }
}
