#include "lis3dh_odr.h"
#include "lis3dh_accelerometer.h"

lis3dh_error_t lis3dh_set_odr(lis3dh_t *sensor, lis3dh_odr_t odr)
{
    uint8_t ctrl_reg1 = 0;
    lis3dh_error_t error = lis3dh_read_register(sensor, LIS3DH_CTRL_REG1_ADDR, &ctrl_reg1);
    if (error == LIS3DH_ERROR)
    {
        return error;
    }

    uint8_t configured = ctrl_reg1 & ~LIS3DH_ODR_MASK;
    configured |= odr;

    error = lis3dh_write_register(sensor, LIS3DH_CTRL_REG1_ADDR, configured);

    return error;
}

lis3dh_error_t lis3dh_power_down(lis3dh_t *sensor)
{
    return lis3dh_set_odr(sensor, LIS3DH_ODR_PWDN);
}

lis3dh_error_t lis3dh_get_odr(lis3dh_t *sensor, lis3dh_odr_t *odr)
{
    uint8_t ctrl_reg1 = 0;
    lis3dh_error_t error = lis3dh_read_register(sensor, LIS3DH_CTRL_REG1_ADDR, &ctrl_reg1);
    if (error == LIS3DH_ERROR)
    {
        return error;
    }

    *odr = ctrl_reg1 & LIS3DH_ODR_MASK;

    return LIS3DH_OK;
}

lis3dh_error_t lis3dh_get_odr_frequency(lis3dh_t *sensor, uint16_t *frequency)
{
    lis3dh_odr_t odr;
    lis3dh_error_t error = lis3dh_get_odr(sensor, &odr);
    if (error == LIS3DH_ERROR)
    {
        return error;
    }

    lis3dh_operating_mode_t mode;
    error = lis3dh_get_operating_mode(sensor, &mode);
    if (error == LIS3DH_ERROR)
    {
        return error;
    }

    switch (odr)
    {
    case LIS3DH_ODR_1Hz:
        *frequency = 1;
        break;
    case LIS3DH_ODR_10Hz:
        *frequency = 10;
        break;
    case LIS3DH_ODR_25Hz:
        *frequency = 25;
        break;
    case LIS3DH_ODR_50Hz:
        *frequency = 50;
        break;
    case LIS3DH_ODR_100Hz:
        *frequency = 100;
        break;
    case LIS3DH_ODR_200Hz:
        *frequency = 200;
        break;
    case LIS3DH_ODR_400Hz:
        *frequency = 400;
        break;
    case LIS3DH_ODR_LP_1_60KHz:
        *frequency = 1600;
        break;
    case LIS3DH_ODR_HR_1_344KHz:
        if (mode == LIS3DH_OPMODE_LOW_POWER)
        {
            *frequency = 5376;
        }
        else
        {
            *frequency = 1344;
        }
        break;
    }

    return LIS3DH_OK;
}