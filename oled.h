#ifndef USER_OLED_H
#define USER_OLED_H

#include <stdint.h>
#include <stdbool.h>

void oled_init(void);
void oled_clear(void);
void oled_draw_text(int x, int y, const char* str);
void oled_show_lines(const char* l1, const char* l2, const char* l3, const char* l4);
void oled_show_status(const char* ssid_up, const char* ip, int rssi, bool ap_on, bool hidden);
void oled_scroll_message(const char* msg);

#endif // USER_OLED_H
