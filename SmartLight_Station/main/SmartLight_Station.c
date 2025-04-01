#include <stdio.h>
#include "esp_wifi.h"

#define WIFI_SSID "Raider Nation"
#define WIFI_PSWD "donkeykong"

void station_init(){
  wifi_config_t station_config;

  station_config.sta = {
    .ssid = WIFI_SSID,
    .password = WIFI_PSWD,
  }


  ESP_ERROR_CHECK(esp_wifi_init(&station_config));
  ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
  ESP_ERROR_CHECK(esp_wifi_start());
}


void app_main(void){

}
