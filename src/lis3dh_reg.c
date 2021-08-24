#include "lis3dh_reg.h"

lis3dh_error_t lis3dh_read_register(lis3dh_t *sensor, uint8_t reg, uint8_t *output)
{
    lis3dh_error_t error = sensor->i2c_write(&sensor->config, &reg, 1);
    if (error == LIS3DH_ERROR)
    {
        return error;
    }

    return sensor->i2c_read(&sensor->config, output, 1);
}

lis3dh_error_t lis3dh_write_register(lis3dh_t *sensor, uint8_t reg, uint8_t value)
{
    const uint8_t data[2] = {reg, value};
    return sensor->i2c_write(&sensor->config, data, 2);
}