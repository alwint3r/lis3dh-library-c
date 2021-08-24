#ifndef LIS3DH_PORTABLE_LIBRARY_C_H
#define LIS3DH_PORTABLE_LIBRARY_C_H
#ifdef __cplusplus
extern "C"
{
#endif

#include "lis3dh_sensor.h"
#include "lis3dh_odr.h"
#include "lis3dh_fullscale.h"
#include "lis3dh_accelerometer.h"
#include "lis3dh_status.h"

lis3dh_t* lis3dh_init(lis3dh_i2c_read_t i2c_read, lis3dh_i2c_write_t i2c_write, uint8_t address);
lis3dh_error_t lis3dh_deinit(lis3dh_t* sensor);

#ifdef __cplusplus
}
#endif
#endif