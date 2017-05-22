
/* 
 * File:   boot_data.h
 * Author: azarias
 *
 * Created on 29 avril 2017, 10:31
 */
#include "types.h"

#ifndef BOOT_DATA_H
#define BOOT_DATA_H



#define  BOOT_DATA_MEMORY 0x00000001
#define  BOOT_DATA_BOOT_PARTITION 0x00000002
#define  BOOT_DATA_COMMAND_LINE 0x00000004
#define  BOOT_DATA_MODULE 0x00000008
#define  BOOT_DATA_EXE32 0x00000010
#define  BOOT_DATA_ELF32 0x00000020
#define  BOOT_DATA_MEMORY_MAP 0x00000040
#define  BOOT_DATA_DISK 0x00000080
#define  BOOT_DATA_CONFIG 0x00000100
#define  BOOT_DATA_BOOTLOADER 0x00000200
#define  BOOT_DATA_APM 0x00000400
#define  BOOT_DATA_VIDEO 0x00000800

typedef struct
{
    uint32_t table_size;
    uint32_t string_size;
    uint32_t adress;
    uint32_t zero;
} table_symboles_exe32_t;

typedef struct
{
    uint32_t number;
    uint32_t size;
    uint32_t adress;
    uint32_t section;
} table_symboles_elf32_t;

typedef struct
{
    uint32_t flags;
    uint32_t low_adress;
    uint32_t hight_adress;
    uint32_t boot_partition;
    uint32_t command_line;
    uint32_t modules_number;
    uint32_t modules_adress;

    union
    {
        table_symboles_elf32_t elf32_symbols;
        table_symboles_elf32_t exe32_symbols;
    };

    uint32_t map_size;
    uint32_t map_adress;
    uint32_t disk_configuration;
    uint32_t bootloader_name;
    uint32_t apm_table;
    uint32_t videocontrol_data;
    uint32_t video_mode_data;
    uint16_t video_mode;
    uint16_t video_segment;
    uint16_t video_offset;
    uint16_t video_size;
} boot_data_t;

#endif /* BOOT_DATA_H */

