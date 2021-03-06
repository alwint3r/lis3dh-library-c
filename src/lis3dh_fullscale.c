#include "lis3dh_fullscale.h"

lis3dh_error_t lis3dh_set_fs(lis3dh_t *sensor, lis3dh_fs_t fs)
{
    uint8_t ctrl_reg4 = 0;
    lis3dh_error_t error = lis3dh_read_register(sensor, LIS3DH_CTRL_REG4_ADDR, &ctrl_reg4);
    if (error == LIS3DH_ERROR)
    {
        return error;
    }

    uint8_t configured = ctrl_reg4 & ~LIS3DH_FS_MASK;
    configured |= fs;

    error = lis3dh_write_register(sensor, LIS3DH_CTRL_REG4_ADDR, configured);

    return error;
}

lis3dh_error_t lis3dh_get_fs(lis3dh_t *sensor, lis3dh_fs_t *fs)
{
    uint8_t ctrl_reg4 = 0;
    lis3dh_error_t error = lis3dh_read_register(sensor, LIS3DH_CTRL_REG4_ADDR, &ctrl_reg4);
    if (error == LIS3DH_ERROR)
    {
        return error;
    }

    *fs =  (lis3dh_fs_t)ctrl_reg4 & LIS3DH_FS_MASK;

    return LIS3DH_OK;
}