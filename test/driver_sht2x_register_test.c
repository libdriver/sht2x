/**
 * Copyright (c) 2015 - present LibDriver All rights reserved
 * 
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. 
 *
 * @file      driver_sht2x_register_test.c
 * @brief     driver sht2x register test source file
 * @version   1.0.0
 * @author    Shifeng Li
 * @date      2025-04-30
 *
 * <h3>history</h3>
 * <table>
 * <tr><th>Date        <th>Version  <th>Author      <th>Description
 * <tr><td>2025/04/30  <td>1.0      <td>Shifeng Li  <td>first upload
 * </table>
 */
 
#include "driver_sht2x_register_test.h"

static sht2x_handle_t gs_handle;        /**< sht2x handle */

/**
 * @brief  register test
 * @return status code
 *         - 0 success
 *         - 1 test failed
 * @note   none
 */
uint8_t sht2x_register_test(void)
{
    uint8_t res;
    uint8_t sn[8];
    sht2x_status_t status;
    sht2x_bool_t enable;
    sht2x_info_t info;
    sht2x_mode_t mode;
    sht2x_resolution_t resolution;
    
    /* link functions */
    DRIVER_SHT2X_LINK_INIT(&gs_handle, sht2x_handle_t);
    DRIVER_SHT2X_LINK_IIC_INIT(&gs_handle, sht2x_interface_iic_init);
    DRIVER_SHT2X_LINK_IIC_DEINIT(&gs_handle, sht2x_interface_iic_deinit);
    DRIVER_SHT2X_LINK_IIC_READ_COMMAND(&gs_handle, sht2x_interface_iic_read_command);
    DRIVER_SHT2X_LINK_IIC_READ(&gs_handle, sht2x_interface_iic_read);
    DRIVER_SHT2X_LINK_IIC_READ_WITH_WAIT(&gs_handle, sht2x_interface_iic_read_with_wait);
    DRIVER_SHT2X_LINK_IIC_READ_ADDRESS16(&gs_handle, sht2x_interface_iic_read_address16);
    DRIVER_SHT2X_LINK_IIC_WRITE_COMMAND(&gs_handle, sht2x_interface_iic_write_command);
    DRIVER_SHT2X_LINK_IIC_WRITE(&gs_handle, sht2x_interface_iic_write);
    DRIVER_SHT2X_LINK_DELAY_MS(&gs_handle, sht2x_interface_delay_ms);
    DRIVER_SHT2X_LINK_DEBUG_PRINT(&gs_handle, sht2x_interface_debug_print);
    
    /* sht2x info */
    res = sht2x_info(&info);
    if (res != 0)
    {
        sht2x_interface_debug_print("sht2x: get info failed.\n");
       
        return 1;
    }
    else
    {
        /* print chip information */
        sht2x_interface_debug_print("sht2x: chip is %s.\n", info.chip_name);
        sht2x_interface_debug_print("sht2x: manufacturer is %s.\n", info.manufacturer_name);
        sht2x_interface_debug_print("sht2x: interface is %s.\n", info.interface);
        sht2x_interface_debug_print("sht2x: driver version is %d.%d.\n", info.driver_version / 1000, (info.driver_version % 1000) / 100);
        sht2x_interface_debug_print("sht2x: min supply voltage is %0.1fV.\n", info.supply_voltage_min_v);
        sht2x_interface_debug_print("sht2x: max supply voltage is %0.1fV.\n", info.supply_voltage_max_v);
        sht2x_interface_debug_print("sht2x: max current is %0.2fmA.\n", info.max_current_ma);
        sht2x_interface_debug_print("sht2x: max temperature is %0.1fC.\n", info.temperature_max);
        sht2x_interface_debug_print("sht2x: min temperature is %0.1fC.\n", info.temperature_min);
    }
    
    /* start register test */
    sht2x_interface_debug_print("sht2x: start register test.\n");
    
    /* sht2x init */
    res = sht2x_init(&gs_handle);
    if (res != 0)
    {
        sht2x_interface_debug_print("sht2x: init failed.\n");
       
        return 1;
    }
    
    /* sht2x_set_mode/sht2x_get_mode test */
    sht2x_interface_debug_print("sht2x: sht2x_set_mode/sht2x_get_mode test.\n");
    
    /* set hold master mode */
    res = sht2x_set_mode(&gs_handle, SHT2X_MODE_HOLD_MASTER);
    if (res != 0)
    {
        sht2x_interface_debug_print("sht2x: set mode failed.\n");
        (void)sht2x_deinit(&gs_handle);
        
        return 1;
    }
    sht2x_interface_debug_print("sht2x: set hold master mode.\n");
    res = sht2x_get_mode(&gs_handle, &mode);
    if (res != 0)
    {
        sht2x_interface_debug_print("sht2x: get mode failed.\n");
        (void)sht2x_deinit(&gs_handle);
        
        return 1;
    }
    sht2x_interface_debug_print("sht2x: check mode %s.\n", (mode == SHT2X_MODE_HOLD_MASTER) ? "ok" : "error");
    
    /* set no hold master mode */
    res = sht2x_set_mode(&gs_handle, SHT2X_MODE_NO_HOLD_MASTER);
    if (res != 0)
    {
        sht2x_interface_debug_print("sht2x: set mode failed.\n");
        (void)sht2x_deinit(&gs_handle);
        
        return 1;
    }
    sht2x_interface_debug_print("sht2x: set no hold master mode.\n");
    res = sht2x_get_mode(&gs_handle, &mode);
    if (res != 0)
    {
        sht2x_interface_debug_print("sht2x: get mode failed.\n");
        (void)sht2x_deinit(&gs_handle);
        
        return 1;
    }
    sht2x_interface_debug_print("sht2x: check mode %s.\n", (mode == SHT2X_MODE_NO_HOLD_MASTER) ? "ok" : "error");
    
    /* sht2x_set_resolution/sht2x_get_resolution test */
    sht2x_interface_debug_print("sht2x: sht2x_set_resolution/sht2x_get_resolution test.\n");
    
    /* set resolution rh 12bit, t 14bit */
    res = sht2x_set_resolution(&gs_handle, SHT2X_RESOLUTION_RH_12BIT_T_14BIT);
    if (res != 0)
    {
        sht2x_interface_debug_print("sht2x: set resolution failed.\n");
        (void)sht2x_deinit(&gs_handle);
        
        return 1;
    }
    sht2x_interface_debug_print("sht2x: set resolution rh 12bit, t 14bit.\n");
    res = sht2x_get_resolution(&gs_handle, &resolution);
    if (res != 0)
    {
        sht2x_interface_debug_print("sht2x: get resolution failed.\n");
        (void)sht2x_deinit(&gs_handle);
        
        return 1;
    }
    sht2x_interface_debug_print("sht2x: check resolution %s.\n", (resolution == SHT2X_RESOLUTION_RH_12BIT_T_14BIT) ? "ok" : "error");
    
    /* set resolution rh 8bit, t 12bit */
    res = sht2x_set_resolution(&gs_handle, SHT2X_RESOLUTION_RH_8BIT_T_12BIT);
    if (res != 0)
    {
        sht2x_interface_debug_print("sht2x: set resolution failed.\n");
        (void)sht2x_deinit(&gs_handle);
        
        return 1;
    }
    sht2x_interface_debug_print("sht2x: set resolution rh 8bit, t 12bit.\n");
    res = sht2x_get_resolution(&gs_handle, &resolution);
    if (res != 0)
    {
        sht2x_interface_debug_print("sht2x: get resolution failed.\n");
        (void)sht2x_deinit(&gs_handle);
        
        return 1;
    }
    sht2x_interface_debug_print("sht2x: check resolution %s.\n", (resolution == SHT2X_RESOLUTION_RH_8BIT_T_12BIT) ? "ok" : "error");
    
    /* set resolution rh 10bit, t 13bit */
    res = sht2x_set_resolution(&gs_handle, SHT2X_RESOLUTION_RH_10BIT_T_13BIT);
    if (res != 0)
    {
        sht2x_interface_debug_print("sht2x: set resolution failed.\n");
        (void)sht2x_deinit(&gs_handle);
        
        return 1;
    }
    sht2x_interface_debug_print("sht2x: set resolution rh 10bit, t 13bit.\n");
    res = sht2x_get_resolution(&gs_handle, &resolution);
    if (res != 0)
    {
        sht2x_interface_debug_print("sht2x: get resolution failed.\n");
        (void)sht2x_deinit(&gs_handle);
        
        return 1;
    }
    sht2x_interface_debug_print("sht2x: check resolution %s.\n", (resolution == SHT2X_RESOLUTION_RH_10BIT_T_13BIT) ? "ok" : "error");
    
    /* set resolution rh 11bit, t 11bit */
    res = sht2x_set_resolution(&gs_handle, SHT2X_RESOLUTION_RH_11BIT_T_11BIT);
    if (res != 0)
    {
        sht2x_interface_debug_print("sht2x: set resolution failed.\n");
        (void)sht2x_deinit(&gs_handle);
        
        return 1;
    }
    sht2x_interface_debug_print("sht2x: set resolution rh 11bit, t 11bit.\n");
    res = sht2x_get_resolution(&gs_handle, &resolution);
    if (res != 0)
    {
        sht2x_interface_debug_print("sht2x: get resolution failed.\n");
        (void)sht2x_deinit(&gs_handle);
        
        return 1;
    }
    sht2x_interface_debug_print("sht2x: check resolution %s.\n", (resolution == SHT2X_RESOLUTION_RH_11BIT_T_11BIT) ? "ok" : "error");
    
    /* sht2x_set_heater/sht2x_get_heater test */
    sht2x_interface_debug_print("sht2x: sht2x_set_heater/sht2x_get_heater test.\n");
    
    /* enable heater */
    res = sht2x_set_heater(&gs_handle, SHT2X_BOOL_TRUE);
    if (res != 0)
    {
        sht2x_interface_debug_print("sht2x: set heater failed.\n");
        (void)sht2x_deinit(&gs_handle);
        
        return 1;
    }
    sht2x_interface_debug_print("sht2x: enable heater.\n");
    res = sht2x_get_heater(&gs_handle, &enable);
    if (res != 0)
    {
        sht2x_interface_debug_print("sht2x: get heater failed.\n");
        (void)sht2x_deinit(&gs_handle);
        
        return 1;
    }
    sht2x_interface_debug_print("sht2x: check heater %s.\n", (enable == SHT2X_BOOL_TRUE) ? "ok" : "error");
    
    /* disable heater */
    res = sht2x_set_heater(&gs_handle, SHT2X_BOOL_FALSE);
    if (res != 0)
    {
        sht2x_interface_debug_print("sht2x: set heater failed.\n");
        (void)sht2x_deinit(&gs_handle);
        
        return 1;
    }
    sht2x_interface_debug_print("sht2x: disable heater.\n");
    res = sht2x_get_heater(&gs_handle, &enable);
    if (res != 0)
    {
        sht2x_interface_debug_print("sht2x: get heater failed.\n");
        (void)sht2x_deinit(&gs_handle);
        
        return 1;
    }
    sht2x_interface_debug_print("sht2x: check heater %s.\n", (enable == SHT2X_BOOL_FALSE) ? "ok" : "error");
    
    /* sht2x_set_disable_otp_reload/sht2x_get_disable_otp_reload test */
    sht2x_interface_debug_print("sht2x: sht2x_set_disable_otp_reload/sht2x_get_disable_otp_reload test.\n");
    
    /* enable disable otp reload */
    res = sht2x_set_disable_otp_reload(&gs_handle, SHT2X_BOOL_TRUE);
    if (res != 0)
    {
        sht2x_interface_debug_print("sht2x: set disable otp reload failed.\n");
        (void)sht2x_deinit(&gs_handle);
        
        return 1;
    }
    sht2x_interface_debug_print("sht2x: enable disable otp reload.\n");
    res = sht2x_get_disable_otp_reload(&gs_handle, &enable);
    if (res != 0)
    {
        sht2x_interface_debug_print("sht2x: get disable otp reload failed.\n");
        (void)sht2x_deinit(&gs_handle);
        
        return 1;
    }
    sht2x_interface_debug_print("sht2x: check disable otp reload %s.\n", (enable == SHT2X_BOOL_TRUE) ? "ok" : "error");
    
    /* disable disable otp reload */
    res = sht2x_set_disable_otp_reload(&gs_handle, SHT2X_BOOL_FALSE);
    if (res != 0)
    {
        sht2x_interface_debug_print("sht2x: set disable otp reload failed.\n");
        (void)sht2x_deinit(&gs_handle);
        
        return 1;
    }
    sht2x_interface_debug_print("sht2x: disable disable otp reload.\n");
    res = sht2x_get_disable_otp_reload(&gs_handle, &enable);
    if (res != 0)
    {
        sht2x_interface_debug_print("sht2x: get disable otp reload failed.\n");
        (void)sht2x_deinit(&gs_handle);
        
        return 1;
    }
    sht2x_interface_debug_print("sht2x: check disable otp reload %s.\n", (enable == SHT2X_BOOL_FALSE) ? "ok" : "error");
    
    /* sht2x_get_status test */
    sht2x_interface_debug_print("sht2x: sht2x_get_status test.\n");
    
    /* get status */
    res = sht2x_get_status(&gs_handle, &status);
    if (res != 0)
    {
        sht2x_interface_debug_print("sht2x: get status failed.\n");
        (void)sht2x_deinit(&gs_handle);
        
        return 1;
    }
    sht2x_interface_debug_print("sht2x: check vdd 2.25v status %s.\n", (status == SHT35_STATUS_VDD_OVER_2P25V) ? "over" : "less");
    
    /* sht2x_get_serial_number test */
    sht2x_interface_debug_print("sht2x: sht2x_get_serial_number test.\n");
    
    /* get serial number */
    res = sht2x_get_serial_number(&gs_handle, sn);
    if (res != 0)
    {
        sht2x_interface_debug_print("sht2x: get serial number failed.\n");
        (void)sht2x_deinit(&gs_handle);
        
        return 1;
    }
    sht2x_interface_debug_print("sht2x: sn 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X.\n", 
                                sn[0], sn[1], sn[2], sn[3], sn[4], sn[5], sn[6], sn[7]);
    
    /* sht2x_soft_reset test */
    sht2x_interface_debug_print("sht2x: sht2x_soft_reset test.\n");
    
    /* soft reset */
    res = sht2x_soft_reset(&gs_handle);
    if (res != 0)
    {
        sht2x_interface_debug_print("sht2x: soft reset failed.\n");
        (void)sht2x_deinit(&gs_handle);
        
        return 1;
    }
    sht2x_interface_debug_print("sht2x: soft reset.\n");
    
    /* finish register test */
    sht2x_interface_debug_print("sht2x: finish register test.\n");
    (void)sht2x_deinit(&gs_handle);
    
    return 0;
}
