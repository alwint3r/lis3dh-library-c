#ifndef LIS3DH_PORTABLE_LIBRARY_C_FS_H
#define LIS3DH_PORTABLE_LIBRARY_C_FS_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lis3dh_reg.h"
#include "lis3dh_sensor.h"

#define LIS3DH_FS_MASK 48
#define LIS3DH_FS_SHIFT 4

typedef enum __lis3dh_fs_t
{
    LIS3DH_FS_2g = 0,
    LIS3DH_FS_4g = 16,
    LIS3DH_FS_8g = 32,
    LIS3DH_FS_16g = 48,
} lis3dh_fs_t;

lis3dh_error_t lis3dh_set_fs(lis3dh_t *sensor, lis3dh_fs_t fs);
lis3dh_error_t lis3dh_get_fs(lis3dh_t *sensor, lis3dh_fs_t *fs);

#ifdef __cplusplus
}
#endif

#endif