#include "lis3dh_adc.h"
#include "lis3dh_accelerometer.h"

lis3dh_error_t lis3dh_get_adc_resolution(lis3dh_t *sensor, uint8_t *result)
{
    lis3dh_operating_mode_t opmode;
    lis3dh_error_t err = lis3dh_get_operating_mode(sensor, &opmode);
    if (err == LIS3DH_ERROR)
    {
        return err;
    }

    if (opmode == LIS3DH_OPMODE_LOW_POWER)
    {
        *result = 8;
    }
    else
    {
        *result = 10;
    }

    return LIS3DH_OK;
}

lis3dh_error_t lis3dh_enable_adc(lis3dh_t *sensor)
{
    uint8_t ctrl_reg4 = 0;
    lis3dh_error_t err = lis3dh_read_register(sensor, LIS3DH_CTRL_REG4_ADDR, &ctrl_reg4);
    if (err == LIS3DH_ERROR)
    {
        return err;
    }

    ctrl_reg4 |= LIS3DH_ADC_BDU_MASK;

    err = lis3dh_write_register(sensor, LIS3DH_CTRL_REG4_ADDR, ctrl_reg4);
    if (err == LIS3DH_ERROR)
    {
        return err;
    }

    uint8_t temp_cfg = 0;
    err = lis3dh_read_register(sensor, LIS3DH_TEMP_CFG_REG_ADDR, &temp_cfg);
    if (err == LIS3DH_ERROR)
    {
        return err;
    }

    temp_cfg |= LIS3DH_ADC_ADC_ENABLE_MASK;

    err = lis3dh_write_register(sensor, LIS3DH_TEMP_CFG_REG_ADDR, temp_cfg);
    if (err == LIS3DH_ERROR)
    {
        return err;
    }

    return LIS3DH_OK;
}

lis3dh_error_t lis3dh_disable_adc(lis3dh_t *sensor)
{
    uint8_t ctrl_reg4 = 0;
    lis3dh_error_t err = lis3dh_read_register(sensor, LIS3DH_CTRL_REG4_ADDR, &ctrl_reg4);
    if (err == LIS3DH_ERROR)
    {
        return err;
    }

    ctrl_reg4 &= ~LIS3DH_ADC_BDU_MASK;

    err = lis3dh_write_register(sensor, LIS3DH_CTRL_REG4_ADDR, ctrl_reg4);
    if (err == LIS3DH_ERROR)
    {
        return err;
    }

    uint8_t temp_cfg = 0;
    err = lis3dh_read_register(sensor, LIS3DH_TEMP_CFG_REG_ADDR, &temp_cfg);
    if (err == LIS3DH_ERROR)
    {
        return err;
    }

    temp_cfg &= ~LIS3DH_ADC_ADC_ENABLE_MASK;

    err = lis3dh_write_register(sensor, LIS3DH_TEMP_CFG_REG_ADDR, temp_cfg);
    if (err == LIS3DH_ERROR)
    {
        return err;
    }

    return LIS3DH_OK;
}

lis3dh_error_t lis3dh_read_adc(lis3dh_t *sensor, lis3dh_adc_pin_t pin, uint16_t *result)
{
    uint8_t resolution = 0;
    lis3dh_error_t err = lis3dh_get_adc_resolution(sensor, &resolution);
    if (err == LIS3DH_ERROR)
    {
        return err;
    }

    uint8_t temp_bytes[2] = {0};

    for (int i = 0; i < 2; i++)
    {
        uint8_t address = LIS3DH_OUT_ADC1_L_ADDR + (2 * pin) + i;
        err = lis3dh_read_register(sensor, address, &temp_bytes[i]);
        if (err == LIS3DH_ERROR)
        {
            return err;
        }
    }

    uint8_t shift = 16 - resolution;
    *result = (temp_bytes[0] | ((uint16_t)temp_bytes[1] << 8)) >> shift;

    return LIS3DH_OK;
}