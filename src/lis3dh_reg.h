#ifndef LIS3DH_PORTABLE_LIBRARY_C_REG_H
#define LIS3DH_PORTABLE_LIBRARY_C_REG_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lis3dh_sensor.h"

#define LIS3DH_OUT_ADC1_L_ADDR 0x08
#define LIS3DH_OUT_ADC1_H_ADDR 0x09
#define LIS3DH_OUT_ADC2_L_ADDR 0x0A
#define LIS3DH_OUT_ADC2_H_ADDR 0x0B
#define LIS3DH_OUT_ADC3_L_ADDR 0x0C
#define LIS3DH_TEMP_CFG_REG_ADDR 0x1F
#define LIS3DH_CTRL_REG1_ADDR 0x20
#define LIS3DH_CTRL_REG2_ADDR 0x21
#define LIS3DH_CTRL_REG3_ADDR 0x22
#define LIS3DH_CTRL_REG4_ADDR 0x23
#define LIS3DH_CTRL_REG5_ADDR 0x24
#define LIS3DH_CTRL_REG6_ADDR 0x25
#define LIS3DH_REFERENCE_ADDR 0x26
#define LIS3DH_STATUS_REG_ADDR 0x27
#define LIS3DH_OUT_X_L_ADDR 0x28
#define LIS3DH_OUT_X_H_ADDR 0x29
#define LIS3DH_OUT_Y_L_ADDR 0x2A
#define LIS3DH_OUT_Y_H_ADDR 0x2B
#define LIS3DH_OUT_Z_L_ADDR 0x2C
#define LIS3DH_OUT_Z_H_ADDR 0x2D
#define LIS3DH_INT1_CFG_ADDR 0x30
#define LIS3DH_INT1_SRC_ADDR 0x31
#define LIS3DH_INT1_THS_ADDR 0x32
#define LIS3DH_INT1_DURATION_ADDR 0x33
#define LIS3DH_INT2_CFG_ADDR 0x34
#define LIS3DH_INT2_SRC_ADDR 0x35
#define LIS3DH_INT2_THS_ADDR 0x36
#define LIS3DH_ACT_THS_ADDR 0x3E
#define LIS3DH_ACT_DUR_ADDR 0x3F

lis3dh_error_t lis3dh_read_register(lis3dh_t *sensor, uint8_t reg, uint8_t *output);
lis3dh_error_t lis3dh_write_register(lis3dh_t *sensor, uint8_t reg, uint8_t value);

#ifdef __cplusplus
}
#endif

#endif