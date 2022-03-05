/*
 * Copyright (c) 2022 HiSilicon (Shanghai) Technologies CO., LIMITED.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __HI_MIPI_TX_H__
#define __HI_MIPI_TX_H__

#define CMD_MAX_NUM    4
#define LANE_MAX_NUM   4
#define MIPI_TX_DISABLE_LANE_ID (-1)
#define MIPI_TX_SET_DATA_SIZE 800
#define MIPI_TX_GET_DATA_SIZE 160

typedef enum {
    OUTPUT_MODE_CSI            = 0x0, /* csi mode */
    OUTPUT_MODE_DSI_VIDEO      = 0x1, /* dsi video mode */
    OUTPUT_MODE_DSI_CMD        = 0x2, /* dsi command mode */

    OUTPUT_MODE_BUTT
} output_mode_t;

typedef enum {
    BURST_MODE                      = 0x0,
    NON_BURST_MODE_SYNC_PULSES      = 0x1,
    NON_BURST_MODE_SYNC_EVENTS      = 0x2,

    VIDEO_DATA_MODE_BUTT
} video_mode_t;

typedef enum {
    OUT_FORMAT_RGB_16_BIT          = 0x0,
    OUT_FORMAT_RGB_18_BIT          = 0x1,
    OUT_FORMAT_RGB_24_BIT          = 0x2,
    OUT_FORMAT_YUV420_8_BIT_NORMAL = 0x3,
    OUT_FORMAT_YUV420_8_BIT_LEGACY = 0x4,
    OUT_FORMAT_YUV422_8_BIT        = 0x5,

    OUT_FORMAT_BUTT
} output_format_t;

typedef struct {
    unsigned short  vid_pkt_size;
    unsigned short  vid_hsa_pixels;
    unsigned short  vid_hbp_pixels;
    unsigned short  vid_hline_pixels;
    unsigned short  vid_vsa_lines;
    unsigned short  vid_vbp_lines;
    unsigned short  vid_vfp_lines;
    unsigned short  vid_active_lines;
    unsigned short  edpi_cmd_size;
} sync_info_t;

typedef struct {
    unsigned int        devno;                 /* device number */
    short               lane_id[LANE_MAX_NUM]; /* lane_id: -1 - disable */
    output_mode_t       output_mode;           /* output mode: CSI/DSI_VIDEO/DSI_CMD */
    video_mode_t        video_mode;
    output_format_t     output_format;
    sync_info_t         sync_info;
    unsigned int        phy_data_rate;         /* mbps */
    unsigned int        pixel_clk;             /* KHz */
} combo_dev_cfg_t;

typedef struct {
    unsigned int        devno;  /* device number */
    unsigned short      data_type;
    unsigned short      cmd_size;
    unsigned char       *cmd;
} cmd_info_t;

typedef struct {
    unsigned int        devno;          /* device number */
    unsigned short      data_type;      /* DSI data type */
    unsigned short      data_param;     /* data param,low 8 bit:first param.high 8 bit:second param, set 0 if not use */
    unsigned short      get_data_size;  /* read data size */
    unsigned char       *get_data;      /* read data memory address, should  malloc by user */
} get_cmd_info_t;

#define HI_MIPI_TX_IOC_MAGIC   't'

#define HI_MIPI_TX_SET_DEV_CFG              _IOW(HI_MIPI_TX_IOC_MAGIC, 0x01, combo_dev_cfg_t)
#define HI_MIPI_TX_SET_CMD                  _IOW(HI_MIPI_TX_IOC_MAGIC, 0x02, cmd_info_t)
#define HI_MIPI_TX_ENABLE                   _IO(HI_MIPI_TX_IOC_MAGIC, 0x03)
#define HI_MIPI_TX_GET_CMD                  _IOWR(HI_MIPI_TX_IOC_MAGIC, 0x04, get_cmd_info_t)
#define HI_MIPI_TX_DISABLE                  _IO(HI_MIPI_TX_IOC_MAGIC, 0x05)

#endif
