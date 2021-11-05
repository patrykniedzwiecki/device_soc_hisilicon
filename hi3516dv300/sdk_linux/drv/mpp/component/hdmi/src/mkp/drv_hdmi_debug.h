/*
 * Copyright (C) 2021 HiSilicon (Shanghai) Technologies CO., LIMITED.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#ifndef __DRV_HDMI_DEBUG_H__
#define __DRV_HDMI_DEBUG_H__

#include "hi_type.h"
#include "hdmi_product_define.h"
#include "drv_hdmi_edid.h"

hi_s32 drv_hdmi_debug_source_write(hdmi_proc_entry *file, const char *buf, hi_u32 count, hi_s64 *data);

hi_s32 drv_hdmi_debug_edid_raw_read(hdmi_edid_updata_mode mode, hi_u8 *data, hi_u32 len);

#endif /* __DRV_HDMI_DEBUG_H__ */

