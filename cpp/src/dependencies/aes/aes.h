/********************************************************************************************
* Header file defining the APIs for AES functions
*********************************************************************************************/

#ifndef __AES_H
#define __AES_H

#include <stdint.h>
#include <stdlib.h>
#include "../../config.h"


/**
 * Function to fill a key schedule given an initial key.
 *
 * @param key            Initial Key.
 * @param schedule       Abstract data structure for a key schedule.
 */
void AES128_load_schedule(const uint8_t *key, uint8_t *schedule);

/**
 * Same as AES128_ECB_enc() except a schedule generated by
 * AES128_load_schedule() is passed rather than a key. This is faster
 * if the same schedule is used for multiple encryptions since it does
 * not have to be regenerated from the key.
 */
void AES128_enc(const uint8_t *plaintext, const uint8_t *schedule, uint8_t *ciphertext, const size_t ciphertext_len);

/**
 * Function to free a key schedule.
 *
 * @param schedule       Schedule generated with AES128_load_schedule().
 */
void AES128_free_schedule(uint8_t *schedule);


#endif