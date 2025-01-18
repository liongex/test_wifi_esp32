#include <stdio.h>
#include <stdlib.h>

//bibliotecas da conexão sem fio
#include "wifi.h"
#include "MQTT_lib.h"

// Includes FreeRTOS
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

// Includes ESP-IDF
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_err.h"
#include "driver/gpio.h"
#include <esp_system.h>

void app_main(void)
{       //teste de wifi
        nvs_flash_init();
        wifi_init_sta();
}
