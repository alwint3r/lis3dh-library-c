#include "lis3dh.h"

lis3dh_t* lis3dh_init(lis3dh_i2c_read_t i2c_read, lis3dh_i2c_write_t i2c_write, uint8_t address)
{
    lis3dh_i2c_config_t config = {
        .address = address
    };

    lis3dh_t *sensor = (lis3dh_t*)(malloc(sizeof(lis3dh_t)));
    sensor->i2c_read = i2c_read;
    sensor->i2c_write = i2c_write;
    sensor->config = config;

    return sensor;
}

lis3dh_error_t lis3dh_deinit(lis3dh_t *sensor)
{
    free(sensor);

    return LIS3DH_OK;
}

