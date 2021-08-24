#include "lis3dh_accelerometer.h"
#include "lis3dh_fullscale.h"
#include <string.h>

lis3dh_error_t lis3dh_enable_axes(lis3dh_t *sensor, uint8_t axes)
{
    uint8_t ctrl_reg1 = 0;
    lis3dh_error_t error = lis3dh_read_register(sensor, LIS3DH_CTRL_REG1_ADDR, &ctrl_reg1);
    if (error == LIS3DH_ERROR)
    {
        return error;
    }

    uint8_t new_config = ctrl_reg1 & ~LIS3DH_AXES_MASK;
    new_config |= axes;

    error = lis3dh_write_register(sensor, LIS3DH_CTRL_REG1_ADDR, new_config);
    if (error == LIS3DH_ERROR)
    {
        return error;
    }

    return error;
}

lis3dh_error_t lis3dh_disable_axes(lis3dh_t *sensor, uint8_t axes)
{
    uint8_t ctrl_reg1 = 0;
    lis3dh_error_t error = lis3dh_read_register(sensor, LIS3DH_CTRL_REG1_ADDR, &ctrl_reg1);
    if (error == LIS3DH_ERROR)
    {
        return error;
    }

    uint8_t new_config = ctrl_reg1 & ~axes;
    error = lis3dh_write_register(sensor, LIS3DH_CTRL_REG1_ADDR, new_config);
    if (error == LIS3DH_ERROR)
    {
        return error;
    }

    return error;
}

lis3dh_error_t lis3dh_set_operating_mode(lis3dh_t *sensor, lis3dh_operating_mode_t opmode)
{
    uint8_t ctrl_reg1 = 0;
    lis3dh_error_t error = lis3dh_read_register(sensor, LIS3DH_CTRL_REG1_ADDR, &ctrl_reg1);
    if (error == LIS3DH_ERROR)
    {
        return error;
    }

    uint8_t ctrl_reg4 = 0;
    error = lis3dh_read_register(sensor, LIS3DH_CTRL_REG4_ADDR, &ctrl_reg4);
    if (error == LIS3DH_ERROR)
    {
        return error;
    }

    uint8_t new_ctrl_reg1 = ctrl_reg1;
    uint8_t new_ctrl_reg4 = ctrl_reg4;

    switch (opmode)
    {
    case LIS3DH_OPMODE_HIGH_RES:
        new_ctrl_reg1 &= ~LIS3DH_LOW_POWER_MASK;
        new_ctrl_reg4 |= LIS3DH_HIGH_RES_MASK;

        sensor->axes_resolution = 12;
        break;
    case LIS3DH_OPMODE_NORMAL:
        new_ctrl_reg1 &= ~LIS3DH_LOW_POWER_MASK;
        new_ctrl_reg4 &= ~LIS3DH_HIGH_RES_MASK;

        sensor->axes_resolution = 10;
        break;
    case LIS3DH_OPMODE_LOW_POWER:
        new_ctrl_reg1 |= LIS3DH_LOW_POWER_MASK;
        new_ctrl_reg4 &= ~LIS3DH_HIGH_RES_MASK;

        sensor->axes_resolution = 8;
        break;
    }

    error = lis3dh_write_register(sensor, LIS3DH_CTRL_REG1_ADDR, new_ctrl_reg1);
    if (error == LIS3DH_ERROR)
    {
        return error;
    }

    error = lis3dh_write_register(sensor, LIS3DH_CTRL_REG4_ADDR, new_ctrl_reg4);
    if (error == LIS3DH_ERROR)
    {
        return error;
    }

    return LIS3DH_OK;
}

lis3dh_error_t lis3dh_get_operating_mode(lis3dh_t *sensor, lis3dh_operating_mode_t *opmode)
{
    uint8_t ctrl_reg1 = 0;
    lis3dh_error_t error = lis3dh_read_register(sensor, LIS3DH_CTRL_REG1_ADDR, &ctrl_reg1);
    if (error == LIS3DH_ERROR)
    {
        return error;
    }

    uint8_t ctrl_reg4 = 0;
    error = lis3dh_read_register(sensor, LIS3DH_CTRL_REG4_ADDR, &ctrl_reg1);
    if (error == LIS3DH_ERROR)
    {
        return error;
    }

    if ((ctrl_reg1 & LIS3DH_LOW_POWER_MASK) == LIS3DH_LOW_POWER_MASK && (ctrl_reg4 & LIS3DH_HIGH_RES_MASK) == 0)
    {
        sensor->axes_resolution = 8;
        *opmode = LIS3DH_OPMODE_LOW_POWER;
    }
    else if ((ctrl_reg1 & LIS3DH_LOW_POWER_MASK) == 0 && (ctrl_reg4 & LIS3DH_HIGH_RES_MASK) == 0)
    {
        sensor->axes_resolution = 10;
        *opmode = LIS3DH_OPMODE_NORMAL;
    }
    else if ((ctrl_reg1 & LIS3DH_LOW_POWER_MASK) == 0 && (ctrl_reg4 & LIS3DH_HIGH_RES_MASK) == LIS3DH_HIGH_RES_MASK)
    {
        sensor->axes_resolution = 12;
        *opmode = LIS3DH_OPMODE_HIGH_RES;
    }
    else if ((ctrl_reg1 & LIS3DH_LOW_POWER_MASK) == LIS3DH_LOW_POWER_MASK && (ctrl_reg4 & LIS3DH_HIGH_RES_MASK) == LIS3DH_HIGH_RES_MASK)
    {
        return LIS3DH_ERROR;
    }

    return LIS3DH_OK;
}

lis3dh_error_t lis3dh_get_sensitivity(lis3dh_t *sensor, uint8_t *sensitivity)
{
    lis3dh_fs_t fs = LIS3DH_FS_2g;
    lis3dh_error_t err = lis3dh_get_fs(sensor, &fs);
    if (err == LIS3DH_ERROR)
    {
        return err;
    }

    lis3dh_operating_mode_t opmode = LIS3DH_OPMODE_NORMAL;
    err = lis3dh_get_operating_mode(sensor, &opmode);
    if (err == LIS3DH_ERROR)
    {
        return err;
    }

    if (fs == LIS3DH_FS_2g && opmode == LIS3DH_OPMODE_HIGH_RES)
    {
        *sensitivity = 1;
    }
    else if (fs == LIS3DH_FS_2g && opmode == LIS3DH_OPMODE_NORMAL)
    {
        *sensitivity = 4;
    }
    else if (fs == LIS3DH_FS_2g && opmode == LIS3DH_OPMODE_LOW_POWER)
    {
        *sensitivity = 16;
    }
    else if (fs == LIS3DH_FS_4g && opmode == LIS3DH_OPMODE_HIGH_RES)
    {
        *sensitivity = 2;
    }
    else if (fs == LIS3DH_FS_4g && opmode == LIS3DH_OPMODE_NORMAL)
    {
        *sensitivity = 8;
    }
    else if (fs == LIS3DH_FS_4g && opmode == LIS3DH_OPMODE_LOW_POWER)
    {
        *sensitivity = 32;
    }
    else if (fs == LIS3DH_FS_8g && opmode == LIS3DH_OPMODE_HIGH_RES)
    {
        *sensitivity = 4;
    }
    else if (fs == LIS3DH_FS_8g && opmode == LIS3DH_OPMODE_NORMAL)
    {
        *sensitivity = 16;
    }
    else if (fs == LIS3DH_FS_8g && opmode == LIS3DH_OPMODE_LOW_POWER)
    {
        *sensitivity = 64;
    }
    else if (fs == LIS3DH_FS_16g && opmode == LIS3DH_OPMODE_HIGH_RES)
    {
        *sensitivity = 12;
    }
    else if (fs == LIS3DH_FS_16g && opmode == LIS3DH_OPMODE_NORMAL)
    {
        *sensitivity = 48;
    }
    else if (fs == LIS3DH_FS_16g && opmode == LIS3DH_OPMODE_LOW_POWER)
    {
        *sensitivity = 192;
    }

    return LIS3DH_OK;
}

lis3dh_error_t lis3dh_get_axes(lis3dh_t *sensor, int16_t *axes)
{
    uint8_t raw_axes[6] = {0};
    lis3dh_error_t err = LIS3DH_OK;

    for (uint8_t i = 0; i < 6; i++)
    {
        uint8_t axis_byte = 0;
        err = lis3dh_read_register(sensor, LIS3DH_OUT_X_L_ADDR + i, &axis_byte);
        if (err == LIS3DH_ERROR)
        {
            return err;
        }

        raw_axes[i] = axis_byte;
    }

    uint8_t sensitivity = 1;
    err = lis3dh_get_sensitivity(sensor, &sensitivity);
    if (err == LIS3DH_ERROR)
    {
        return err;
    }

    int16_t processed_axes[3] = {0};
    uint8_t shift = 16 - sensor->axes_resolution;
    uint8_t axes_index = 0;
    for (uint8_t i = 0; i < 6; i += 2)
    {
        int16_t axis = (raw_axes[i] | (raw_axes[i + 1] << 8)) >> shift;
        processed_axes[axes_index++] = sensitivity * axis;
    }

    memcpy(axes, processed_axes, sizeof(processed_axes));

    return LIS3DH_OK;
}