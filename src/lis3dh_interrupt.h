#ifndef LIS3DH_PORTABLE_LIBRARY_C_INTERRUPT_H
#define LIS3DH_PORTABLE_LIBRARY_C_INTERRUPT_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lis3dh_reg.h"
#include "lis3dh_sensor.h"

#define LIS3DH_INT_LATCH_MASK 10
#define LIS3DH_INT1_INT_MASK 254

#define LIS3DH_INT1_THS_MASK 127
#define LIS3DH_INT2_THS_MASK 127

#define LIS3DH_INT_POLARITY_MASK 2

typedef enum __lis3dh_int_latch_config_t
{
    LIS3DH_INT_LIR_INT2 = 2,
    LIS3DH_INT_LIR_INT1 = 8,
} lis3dh_int_latch_config_t;

typedef enum __lis3dh_int_t
{
    LIS3DH_INT1,
    LIS3DH_INT2,
} lis3dh_int_t;

typedef enum __lis3dh_int1_pad_interrupt_t
{
    LIS3DH_INT1_INT_FIFO_OVERRUN = 2,
    LIS3DH_INT1_INT_FIFO_WATERMARK = 4,
    LIS3DH_INT1_INT_321DA = 8,
    LIS3DH_INT1_INT_ZYXDA = 16,
    LIS3DH_INT1_INT_ACTIVITY2 = 32,
    LIS3DH_INT1_INT_ACTIVITY1 = 64,
    LIS3DH_INT1_INT_CLICK = 128,
} lis3dh_int1_pad_interrupt_t;

typedef enum __lis3dh_int_threshold_multiplier_t
{
    LIS3DH_INT_THRESHOLD_FS_2g = 16,
    LIS3DH_INT_THRESHOLD_FS_4g = 32,
    LIS3DH_INT_THRESHOLD_FS_8g = 62,
    LIS3DH_INT_THRESHOLD_FS_16g = 186
} lis3dh_int_threshold_multiplier_t;

typedef enum __lis3dh_interrupt_gen_config_t
{
    LIS3DH_INT_GENERATION_X_LOW = 1,
    LIS3DH_INT_GENERATION_X_HIGH = 2,
    LIS3DH_INT_GENERATION_Y_LOW = 4,
    LIS3DH_INT_GENERATION_Y_HIGH = 8,
    LIS3DH_INT_GENERATION_Z_LOW = 16,
    LIS3DH_INT_GENERATION_Z_HIGH = 32,
    LIS3DH_INT_GENERATION_6D = 64,
    LIS3DH_INT_GENERATION_AOI = 128,
} lis3dh_interrupt_gen_config_t;

typedef enum __lis3dh_interrupt_polarity_config_t
{
    LIS3DH_INT_POLARITY_ACTIVE_HIGH = 0,
    LIS3DH_INT_POLARITY_ACTIVE_LOW = 2,
} lis3dh_interrupt_polarity_config_t;

lis3dh_error_t lis3dh_set_int_latch_config(lis3dh_t *sensor, uint8_t latch);
lis3dh_error_t lis3dh_get_int_latch_config(lis3dh_t *sensor, uint8_t *latch);

lis3dh_error_t lis3dh_set_int1_interrupt_config(lis3dh_t *sensor, uint8_t int1);
lis3dh_error_t lis3dh_get_int1_interrupt_config(lis3dh_t *sensor, uint8_t *int1);

lis3dh_error_t lis3dh_set_int_threshold(lis3dh_t *sensor, lis3dh_int_t interrupt, uint8_t ths);
lis3dh_error_t lis3dh_get_int_threshold(lis3dh_t *sensor, lis3dh_int_t interrupt, uint8_t *ths);
lis3dh_error_t lis3dh_get_int_threshold_in_mg(lis3dh_t *sensor, lis3dh_int_t interrupt, uint16_t *mg);

lis3dh_error_t lis3dh_set_int_generation_config(lis3dh_t *sensor, lis3dh_int_t interrupt, uint8_t config);
lis3dh_error_t lis3dh_get_int_generation_config(lis3dh_t *sensor, lis3dh_int_t interrupt, uint8_t *config);

lis3dh_error_t lis3dh_set_int_polarity(lis3dh_t *sensor, lis3dh_interrupt_polarity_config_t polarity);
lis3dh_error_t lis3dh_get_int_polarity(lis3dh_t *sensor, lis3dh_interrupt_polarity_config_t *polarity);

#ifdef __cplusplus
}
#endif

#endif