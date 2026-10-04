idf_component_register(SRCS "main.c"
                    INCLUDE_DIRS "."
                    REQUIRES nvs_flash esp_wifi esp_event esp_http_server
                    PRIV_REQUIRES esp_driver_gpio esp_adc)