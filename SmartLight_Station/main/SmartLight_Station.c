#include <stdio.h>
#include "esp_wifi.h"
#include "nvs_flash.h"
#include "esp_log.h"

#define WIFI_SSID "Raider Nation"
#define WIFI_PSWD "donkeykong"

static const char* TAG = "Wifi Station";

void station_init(void){
  
  wifi_init_config_t wifi_cfg = WIFI_INIT_CONFIG_DEFAULT();
  ESP_ERROR_CHECK(esp_wifi_init(&wifi_cfg));


  wifi_config_t station_cfg = {
    .sta = {
      .ssid = WIFI_SSID,
      .password = WIFI_PSWD,
    },
  };


  ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
  ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &station_cfg));
  ESP_ERROR_CHECK(esp_wifi_start());
  ESP_ERROR_CHECK(esp_wifi_connect());
}


void app_main(void){
  // Initialize NVS
  esp_err_t nvs_ret = nvs_flash_init();

  if(nvs_ret == ESP_ERR_NVS_NO_FREE_PAGES || nvs_ret == ESP_ERR_NVS_NEW_VERSION_FOUND){
    ESP_ERROR_CHECK(nvs_flash_erase());
    nvs_ret = nvs_flash_init();
  }
  ESP_ERROR_CHECK(nvs_ret);

  ESP_LOGI(TAG, "WIFI_STATION_MODE");
  station_init();
}
