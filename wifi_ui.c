#include "user/wifi_ui.h"
#include "user/oled.h"
#include "user/buttons.h"
#include "osapi.h"
#include "user_interface.h"
#include "espconn.h"
#include <stdio.h>
#include <string.h>

static bool ap_hidden = false;
static bool ap_on = true;

static void show_status_screen(void) {
    struct ip_info info;
    wifi_get_ip_info(STATION_IF, &info);
    struct station_config conf;
    wifi_station_get_config_default(&conf);
    const char* ssid = conf.ssid[0] ? (char*)conf.ssid : "-";
    char ipbuf[16];
    os_sprintf(ipbuf, IPSTR, IP2STR(&info.ip));
    int rssi = wifi_station_get_rssi();
    oled_show_status(ssid, ipbuf, rssi, ap_on, ap_hidden);
}

void wifi_ui_init(void) {
    oled_init();
    buttons_init();
    show_status_screen();
}

void wifi_ui_tick(void) {
    int btn = buttons_check();
    if (btn==1) {
        // up pressed
    } else if (btn==2) {
        // down pressed
    } else if (btn==3) {
        // ok pressed
    } else if (btn==4) {
        // back pressed -> toggle hide
        ap_hidden = !ap_hidden;
        // set hidden flag in AP config if available
    }
    // periodic update
    static uint32_t last = 0;
    if (system_get_time() / 1000 - last > 5000) {
        last = system_get_time() / 1000;
        show_status_screen();
    }
}
