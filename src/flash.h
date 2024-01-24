/*
 * Copyright (c) 2021 Golioth, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __APP_FLASH_H__
#define __APP_FLASH_H__

#ifdef CONFIG_BOOTLOADER_MCUBOOT

#include <dfu/flash_img.h>
#include <dfu/mcuboot.h>
#include <zephyr/types.h>

/**
 * @file
 * @brief Application-specific flash handling header
 */

/**
 * @brief Prepares the flash image for an update
 *
 * This function prepares the flash image for an update based on the
 * configuration specified in the flash image context.
 *
 * @param flash Flash image context
 * @return 0 on success, negative error code on failure
 */
int flash_img_prepare(struct flash_img_context *flash);

/**
 * @brief String to store the current firmware version
 */
extern char current_version_str[sizeof("255.255.65535")];

#else /* CONFIG_BOOTLOADER_MCUBOOT */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/**
 * @brief Structure representing the context for flash image handling
 */
struct flash_img_context {
    /* empty */
};

/**
 * @brief Prepares the flash image for an update
 *
 * This is a placeholder function for platforms not using the MCUBOOT bootloader.
 *
 * @param flash Flash image context (unused)
 * @return Always returns 0
 */
static inline int flash_img_prepare(struct flash_img_context *flash)
{
    return 0;
}

/**
 * @brief Writes data to the flash image buffer
 *
 * This is a placeholder function for platforms not using the MCUBOOT bootloader.
 *
 * @param ctx Flash image context (unused)
 * @param data Pointer to the data to be written
 * @param len Length of the data to be written
 * @param flush Flag indicating whether to flush the buffer (unused)
 * @return Always returns 0
 */
static inline
int flash_img_buffered_write(struct flash_img_context *ctx, const uint8_t *data,
                             size_t len, bool flush)
{
    return 0;
}

/** Boot upgrade request modes */
#define BOOT_UPGRADE_TEST       0 /**< Test upgrade mode */
#define BOOT_UPGRADE_PERMANENT  1 /**< Permanent upgrade mode */

/**
 * @brief Requests a boot upgrade with specified mode
 *
 * This is a placeholder function for platforms not using the MCUBOOT bootloader.
 *
 * @param permanent Upgrade mode (0 for test, 1 for permanent)
 * @return Always returns 0
 */
static inline int boot_request_upgrade(int permanent)
{
    return 0;
}

/**
 * @brief Checks if the image is confirmed
 *
 * This is a placeholder function for platforms not using the MCUBOOT bootloader.
 *
 * @return Always returns true
 */
static inline bool boot_is_img_confirmed(void)
{
    return true;
}

/**
 * @brief Writes the image confirmation
 *
 * This is a placeholder function for platforms not using the MCUBOOT bootloader.
 *
 * @return Always returns 0
 */
static inline int boot_write_img_confirmed(void)
{
    return 0;
}

/**
 * @brief String to store the current firmware version
 */
static char current_version_str[sizeof("255.255.65535")] = "1.0.0";

#endif /* CONFIG_BOOTLOADER_MCUBOOT */

#endif /* __APP_FLASH_H__ */
