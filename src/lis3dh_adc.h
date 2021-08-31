#ifndef LIS3DH_PORTABLE_LIBRARY_C_ADC_H
#define LIS3DH_PORTABLE_LIBRARY_C_ADC_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lis3dh_reg.h"
#include "lis3dh_sensor.h"

#define LIS3DH_ADC_ADC_ENABLE_MASK 0x80
#define LIS3DH_ADC_TEMP_ENABLE_MASK 0x40
#define LIS3DH_ADC_BDU_MASK 0x80

typedef enum __lis3dh_adc_pin_t
{
    LIS3DH_ADC_PIN_1,
    LIS3DH_ADC_PIN_2,
    LIS3DH_ADC_PIN_3,
    LIS3DH_ADC_PIN_MAX,
} lis3dh_adc_pin_t;

lis3dh_error_t lis3dh_get_adc_resolution(lis3dh_t *sensor, uint8_t *result);
lis3dh_error_t lis3dh_enable_adc(lis3dh_t *sensor);
lis3dh_error_t lis3dh_disable_adc(lis3dh_t *sensor);
lis3dh_error_t lis3dh_read_adc(lis3dh_t *sensor, lis3dh_adc_pin_t pin, uint16_t *result);

#ifdef __cplusplus
}
#endif

#endif