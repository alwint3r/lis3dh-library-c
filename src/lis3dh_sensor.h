#ifndef LIS3DH_PORTABLE_LIBRARY_C_SENSOR_H
#define LIS3DH_PORTABLE_LIBRARY_C_SENSOR_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdlib.h>
#include <stdint.h>

typedef enum __lis3dh_error_t
{
    LIS3DH_OK,
    LIS3DH_ERROR,
} lis3dh_error_t;

typedef struct __lis3dh_i2c_config_t
{
    uint8_t address;
} lis3dh_i2c_config_t;

typedef lis3dh_error_t (*lis3dh_i2c_write_t)(lis3dh_i2c_config_t*, const uint8_t*, size_t);
typedef lis3dh_error_t (*lis3dh_i2c_read_t)(lis3dh_i2c_config_t*, uint8_t*, size_t);

typedef struct __lis3dh_t
{
    lis3dh_i2c_read_t i2c_read;
    lis3dh_i2c_write_t i2c_write;
    lis3dh_i2c_config_t config;

    uint8_t axes_resolution;
} lis3dh_t;

#ifdef __cplusplus
}
#endif

#endif