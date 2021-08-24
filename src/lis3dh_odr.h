#ifndef LIS3DH_PORTABLE_LIBRARY_C_ODR_H
#define LIS3DH_PORTABLE_LIBRARY_C_ODR_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lis3dh_reg.h"
#include "lis3dh_sensor.h"

#define LIS3DH_ODR_MASK 240

typedef enum __lis3dh_odr_t
{
    LIS3DH_ODR_PWDN = 0,
    LIS3DH_ODR_1Hz = 16,
    LIS3DH_ODR_10Hz = 32,
    LIS3DH_ODR_25Hz = 48,
    LIS3DH_ODR_50Hz = 64,
    LIS3DH_ODR_100Hz = 80,
    LIS3DH_ODR_200Hz = 96,
    LIS3DH_ODR_400Hz = 112,
    LIS3DH_ODR_LP_1_60KHz = 128,
    LIS3DH_ODR_HR_1_344KHz = 144,
} lis3dh_odr_t;

lis3dh_error_t lis3dh_set_odr(lis3dh_t *sensor, lis3dh_odr_t odr);
lis3dh_error_t lis3dh_power_down(lis3dh_t *sensor);
lis3dh_error_t lis3dh_get_odr(lis3dh_t *sensor, lis3dh_odr_t *odr);
lis3dh_error_t lis3dh_get_odr_frequency(lis3dh_t *sensor, uint16_t *frequency);

#ifdef __cplusplus
}
#endif

#endif