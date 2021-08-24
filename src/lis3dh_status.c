#include "lis3dh_status.h"

lis3dh_error_t lis3dh_get_status(lis3dh_t *sensor, lis3dh_status_t *status)
{
    uint8_t status_reg = 0;
    lis3dh_error_t error = lis3dh_read_register(sensor, LIS3DH_STATUS_REG_ADDR, &status_reg);
    if (error == LIS3DH_ERROR)
    {
        return error;
    }

    status->data_overrun = (status_reg & LIS3DH_STATUS_ZYXOR);
    status->data_ready = (status_reg & LIS3DH_STATUS_ZYXDA);

    return LIS3DH_OK;
}