#include "lis3dh_interrupt.h"
#include "lis3dh_fullscale.h"

lis3dh_error_t lis3dh_set_int_latch_config(lis3dh_t *sensor, uint8_t latch)
{
    uint8_t ctrl_reg5 = 0;
    lis3dh_error_t error = lis3dh_read_register(sensor, LIS3DH_CTRL_REG5_ADDR, &ctrl_reg5);
    if (error == LIS3DH_ERROR)
    {
        return error;
    }

    uint8_t new_ctrl_reg5 = ctrl_reg5 & ~LIS3DH_INT_LATCH_MASK;
    new_ctrl_reg5 |= latch;

    return lis3dh_write_register(sensor, LIS3DH_CTRL_REG5_ADDR, new_ctrl_reg5);
}

lis3dh_error_t lis3dh_get_int_latch_config(lis3dh_t *sensor, uint8_t *latch)
{
    uint8_t ctrl_reg5 = 0;
    lis3dh_error_t error = lis3dh_read_register(sensor, LIS3DH_CTRL_REG5_ADDR, &ctrl_reg5);
    if (error == LIS3DH_ERROR)
    {
        return error;
    }

    *latch = ctrl_reg5 & LIS3DH_INT_LATCH_MASK;

    return LIS3DH_OK;
}

lis3dh_error_t lis3dh_set_int1_interrupt_config(lis3dh_t *sensor, uint8_t int1)
{
    uint8_t ctrl_reg3 = 0;
    lis3dh_error_t error = lis3dh_read_register(sensor, LIS3DH_CTRL_REG3_ADDR, &ctrl_reg3);
    if (error == LIS3DH_ERROR)
    {
        return error;
    }

    uint8_t new_ctrl_reg3 = ctrl_reg3 & ~LIS3DH_INT1_INT_MASK;
    new_ctrl_reg3 |= int1;

    return lis3dh_write_register(sensor, LIS3DH_CTRL_REG5_ADDR, new_ctrl_reg3);
}

lis3dh_error_t lis3dh_get_int1_interrupt_config(lis3dh_t *sensor, uint8_t *int1)
{
    uint8_t ctrl_reg3 = 0;
    lis3dh_error_t error = lis3dh_read_register(sensor, LIS3DH_CTRL_REG3_ADDR, &ctrl_reg3);
    if (error == LIS3DH_ERROR)
    {
        return error;
    }

    *int1 = ctrl_reg3 & LIS3DH_INT1_INT_MASK;

    return LIS3DH_OK;
}

lis3dh_error_t lis3dh_set_int_threshold(lis3dh_t *sensor, lis3dh_int_t interrupt, uint8_t ths)
{
    uint8_t address = interrupt == LIS3DH_INT1 ? LIS3DH_INT1_THS_ADDR : LIS3DH_INT2_THS_ADDR;

    return lis3dh_write_register(sensor, address, ths);
}

lis3dh_error_t lis3dh_get_int_threshold(lis3dh_t *sensor, lis3dh_int_t interrupt, uint8_t *ths)
{
    uint8_t address = interrupt == LIS3DH_INT1 ? LIS3DH_INT1_THS_ADDR : LIS3DH_INT2_THS_ADDR;
    uint8_t mask = interrupt == LIS3DH_INT1 ? LIS3DH_INT1_THS_MASK : LIS3DH_INT2_THS_MASK;

    lis3dh_error_t error = lis3dh_read_register(sensor, address, ths);
    if (error == LIS3DH_ERROR)
    {
        return error;
    }

    return LIS3DH_OK;
}

lis3dh_error_t lis3dh_get_int_threshold_in_mg(lis3dh_t *sensor, lis3dh_int_t interrupt, uint16_t *mg)
{
    uint8_t address = interrupt == LIS3DH_INT1 ? LIS3DH_INT1_THS_ADDR : LIS3DH_INT2_THS_ADDR;

    uint8_t int_ths = 0;
    lis3dh_error_t error = lis3dh_read_register(sensor, address, &int_ths);
    if (error == LIS3DH_ERROR)
    {
        return error;
    }

    lis3dh_fs_t fs;
    error = lis3dh_get_fs(sensor, &fs);
    if (error == LIS3DH_ERROR)
    {
        return error;
    }

    switch (fs)
    {
    case LIS3DH_FS_2g:
        *mg = int_ths * LIS3DH_INT_THRESHOLD_FS_2g;
        break;
    case LIS3DH_FS_4g:
        *mg = int_ths * LIS3DH_INT_THRESHOLD_FS_4g;
        break;
    case LIS3DH_FS_8g:
        *mg = int_ths * LIS3DH_INT_THRESHOLD_FS_16g;
        break;
    case LIS3DH_FS_16g:
        *mg = int_ths * LIS3DH_INT_THRESHOLD_FS_16g;
        break;
    }

    return LIS3DH_OK;
}

lis3dh_error_t lis3dh_set_int_generation_config(lis3dh_t *sensor, lis3dh_int_t interrupt, uint8_t config)
{
    uint8_t address = interrupt == LIS3DH_INT1 ? LIS3DH_INT1_CFG_ADDR : LIS3DH_INT2_CFG_ADDR;
    return lis3dh_write_register(sensor, address, config);
}

lis3dh_error_t lis3dh_get_int_generation_config(lis3dh_t *sensor, lis3dh_int_t interrupt, uint8_t *config)
{
    uint8_t address = interrupt == LIS3DH_INT1 ? LIS3DH_INT1_CFG_ADDR : LIS3DH_INT2_CFG_ADDR;
    return lis3dh_read_register(sensor, address, config);
}

lis3dh_error_t lis3dh_set_int_polarity(lis3dh_t *sensor, lis3dh_interrupt_polarity_config_t polarity)
{
    uint8_t ctrl_reg6 = 0;
    lis3dh_error_t error = lis3dh_read_register(sensor, LIS3DH_CTRL_REG6_ADDR, &ctrl_reg6);
    if (error == LIS3DH_ERROR)
    {
        return error;
    }

    uint8_t new_ctrl_reg6 = ctrl_reg6 & ~LIS3DH_INT_POLARITY_MASK;
    new_ctrl_reg6 |= polarity;

    return lis3dh_write_register(sensor, LIS3DH_CTRL_REG6_ADDR, new_ctrl_reg6);
}

lis3dh_error_t lis3dh_get_int_polarity(lis3dh_t *sensor, lis3dh_interrupt_polarity_config_t *polarity)
{
    uint8_t ctrl_reg6 = 0;
    lis3dh_error_t error = lis3dh_read_register(sensor, LIS3DH_CTRL_REG6_ADDR, &ctrl_reg6);
    if (error == LIS3DH_ERROR)
    {
        return error;
    }

    *polarity = ctrl_reg6 & LIS3DH_INT_POLARITY_MASK;

    return LIS3DH_OK;
}