#pragma once
#include <stdint.h>

enum class bambubus_package_type
{
    error = -1,
    none = 0,
    filament_motion_short,
    filament_motion_long,
    online_detect,
    REQx6,
    NFC_detect,
    set_filament_info,
    MC_online,
    read_filament_info,
    set_filament_info_type2,
    version,
    serial_number,
    heartbeat,
    ETC,

    __BambuBus_package_packge_type_size
};

void bambubus_init(void);
void bambubus_heartbeat_seen_fast(void);

// ----------------- 新增：监听其他 AMS 状态结构体 -----------------
struct ams_snoop_status_t {
    bool online;               // 该编号的 AMS 是否有通信
    uint8_t active_channel;    // 当前使用的通道 (0-3，0xFF表示空闲/未加载)
    uint8_t statu_flag;        // 当前的主状态标识
    uint8_t motion_flag;       // 当前的运动标识
    float temperature;         // 箱体温度 (单位：℃)
    uint8_t humidity;          // 箱体湿度 (单位：%)
    uint32_t last_update_ms;   // 最后一次更新系统时间(用于判断是否离线掉线)
};

// 全局数组：保存 AMS0 到 AMS3 的状态 (ams_status[0] 即代表 AMS0)
extern ams_snoop_status_t ams_status[4];

extern bambubus_package_type bambubus_run();

