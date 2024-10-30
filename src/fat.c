#include "fat.h"
#include "sd.h"
#include <string.h>

struct boot_sector boot;
uint16_t* fat_table;
uint32_t root_dir_start;

int fatInit() {
    // Load boot sector
    if (sd_readblock(0, (unsigned char*)&boot, 1) != 512) {
        return -1;
    }

    // Calculate FAT and root directory locations
    fat_table = (uint16_t*)malloc(boot.num_sectors_per_fat * boot.bytes_per_sector);
    root_dir_start = boot.num_reserved_sectors + (boot.num_fat_tables * boot.num_sectors_per_fat);

    // Load FAT table
    for (int i = 0; i < boot.num_sectors_per_fat; i++) {
        if (sd_readblock(boot.num_reserved_sectors + i, (unsigned char*)&fat_table[i * 256], 1) != 512) {
            return -1;
        }
    }
    return 0;
}

int fatOpen(const char* filename, struct root_directory_entry* file_entry) {
    struct root_directory_entry entries[16];
    for (int i = 0; i < boot.num_root_dir_entries; i += 16) {
        if (sd_readblock(root_dir_start + i / 16, (unsigned char*)entries, 1) != 512) {
            return -1;
        }
        for (int j = 0; j < 16; j++) {
            if (strncmp(entries[j].file_name, filename, 8) == 0) {
                *file_entry = entries[j];
                return 0;
            }
        }
    }
    return -1;
}

int fatRead(struct root_directory_entry* file_entry, unsigned char* buffer, int size) {
    int bytesRead = 0;
    uint16_t cluster = file_entry->cluster;
    while (bytesRead < size && cluster < 0xFFF8) {
        uint32_t sector = root_dir_start + (cluster - 2) * boot.num_sectors_per_cluster;
        if (sd_readblock(sector, buffer + bytesRead, boot.num_sectors_per_cluster) != boot.bytes_per_sector * boot.num_sectors_per_cluster) {
            return -1;
        }
        bytesRead += boot.bytes_per_sector * boot.num_sectors_per_cluster;
        cluster = fat_table[cluster];
    }
    return bytesRead;
}
