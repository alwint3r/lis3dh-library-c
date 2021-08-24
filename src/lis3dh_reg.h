#ifndef LIS3DH_PORTABLE_LIBRARY_C_REG_H
#define LIS3DH_PORTABLE_LIBRARY_C_REG_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lis3dh_sensor.h"

#define LIS3DH_CTRL_REG1_ADDR 0x20
#define LIS3DH_CTRL_REG4_ADDR 0x23
#define LIS3DH_REFERENCE_ADDR 0x26
#define LIS3DH_STATUS_REG_ADDR 0x27
#define LIS3DH_OUT_X_L_ADDR 0x28
#define LIS3DH_OUT_X_H_ADDR 0x29
#define LIS3DH_OUT_Y_L_ADDR 0x2A
#define LIS3DH_OUT_Y_H_ADDR 0x2B
#define LIS3DH_OUT_Z_L_ADDR 0x2C
#define LIS3DH_OUT_Z_H_ADDR 0x2D

lis3dh_error_t lis3dh_read_register(lis3dh_t *sensor, uint8_t reg, uint8_t *output);
lis3dh_error_t lis3dh_write_register(lis3dh_t *sensor, uint8_t reg, uint8_t value);

#ifdef __cplusplus
}
#endif

#endif