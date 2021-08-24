#include "lis3dh_odr.h"

lis3dh_error_t lis3dh_set_odr(lis3dh_t *sensor, lis3dh_odr_t odr)
{
    uint8_t ctrl_reg1 = 0;
    lis3dh_error_t error = lis3dh_read_register(sensor, LIS3DH_CTRL_REG1_ADDR, &ctrl_reg1);

    uint8_t configured = ctrl_reg1 & ~LIS3DH_ODR_MASK;
    configured |= odr;
    
    error = lis3dh_write_register(sensor, LIS3DH_CTRL_REG1_ADDR, configured);

    return error;
}

lis3dh_error_t lis3dh_power_down(lis3dh_t *sensor)
{
    return lis3dh_set_odr(sensor, LIS3DH_ODR_PWDN);
}