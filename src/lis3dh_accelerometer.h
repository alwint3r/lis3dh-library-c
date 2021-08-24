#ifndef LIS3DH_PORTABLE_LIBRARY_C_ACCELEROMETER_H
#define LIS3DH_PORTABLE_LIBRARY_C_ACCELEROMETER_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lis3dh_reg.h"
#include "lis3dh_sensor.h"

#define LIS3DH_AXES_MASK 7

#define LIS3DH_HIGH_RES_MASK 8
#define LIS3DH_LOW_POWER_MASK 8

typedef enum __lis3dh_axes_t
{
    LIS3DH_AXES_X = 1,
    LIS3DH_AXES_Y = 2,
    LIS3DH_AXES_Z = 4
} lis3dh_axes_t;

typedef enum __lis3dh_operating_mode_t
{
    LIS3DH_OPMODE_LOW_POWER = 0,
    LIS3DH_OPMODE_NORMAL,
    LIS3DH_OPMODE_HIGH_RES,
} lis3dh_operating_mode_t;


lis3dh_error_t lis3dh_enable_axes(lis3dh_t *sensor, uint8_t axes);
lis3dh_error_t lis3dh_disable_axes(lis3dh_t *sensor, uint8_t axes);
lis3dh_error_t lis3dh_set_operating_mode(lis3dh_t *sensor, lis3dh_operating_mode_t opmode);
lis3dh_error_t lis3dh_get_operating_mode(lis3dh_t *sensor, lis3dh_operating_mode_t *opmode);
lis3dh_error_t lis3dh_get_axes(lis3dh_t *sensor, int16_t *axes);
lis3dh_error_t lis3dh_get_sensitivity(lis3dh_t *sensor, uint8_t *sensitivity);

#ifdef __cplusplus
}
#endif

#endif