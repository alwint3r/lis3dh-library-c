#ifndef LIS3DH_PORTABLE_LIBRARY_C_STATUS_H
#define LIS3DH_PORTABLE_LIBRARY_C_STATUS_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lis3dh_reg.h"
#include "lis3dh_sensor.h"

#define LIS3DH_STATUS_ZYXOR 128
#define LIS3DH_STATUS_ZYXDA 4

typedef struct __lis3dh_status_t
{
    uint8_t data_ready;
    uint8_t data_overrun;
} lis3dh_status_t;



lis3dh_error_t lis3dh_get_status(lis3dh_t *sensor, lis3dh_status_t *status);

#ifdef __cplusplus
}
#endif

#endif