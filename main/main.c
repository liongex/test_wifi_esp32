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

void app_main(void){
        //teste de wifi
        nvs_flash_init();
        wifi_init_sta();
        mqtt_start();
        float temperatura = 0, umidade = 0;

        while(true){
                char msg1[50];
                char msg2[50];
                snprintf(msg1, sizeof(msg1), "Temp: %.2f °C", temperatura);
                mqtt_publish("Temperature", msg1, 0, 0); 
                snprintf(msg2, sizeof(msg2), "Umid: %.2f%%", umidade);
                mqtt_publish("Humidity", msg2, 0, 0);
                temperatura += 5;
                umidade += 2;
                vTaskDelay(pdMS_TO_TICKS(2000));

        }
        

     

}
