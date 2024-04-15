/*
 * LED blink with FreeRTOS
 */
#include <FreeRTOS.h>
#include <task.h>
#include <semphr.h>
#include <queue.h>

#include <string.h>

#include "pico/stdlib.h"
#include <stdio.h>

#include "hc06.h"

const int BTN_PIN_1 = 21;
const int BTN_PIN_2 = 20;
const int BTN_PIN_3 = 19;
const int BTN_PIN_4 = 18;
const int BTN_PIN_5 = 17;
const int BTN_PIN_6 = 16;

QueueHandle_t xQueueBtn;

void gpio_callback(uint gpio, uint32_t events) {
    int btn;
    if (gpio == BTN_PIN_1){
            btn = 1;
            xQueueSendFromISR(xQueueBtn, &btn, 0);
    }
    if (gpio == BTN_PIN_2){
            btn = 2;
            xQueueSendFromISR(xQueueBtn, &btn, 0);
    }
    if (gpio == BTN_PIN_3){
            btn = 3;
            xQueueSendFromISR(xQueueBtn, &btn, 0);
    }
    if (gpio == BTN_PIN_4){
            btn = 4;
            xQueueSendFromISR(xQueueBtn, &btn, 0);
    }
    if (gpio == BTN_PIN_5){
            btn = 5;
            xQueueSendFromISR(xQueueBtn, &btn, 0);
    }
    if (gpio == BTN_PIN_6){
            btn = 6;
            xQueueSendFromISR(xQueueBtn, &btn, 0);
    }
}

void oled_btn_init(void) {
    // Inicializa botões
    gpio_init(BTN_PIN_1);
    gpio_set_dir(BTN_PIN_1, GPIO_IN);
    gpio_pull_up(BTN_PIN_1);
    gpio_set_irq_enabled_with_callback(
        BTN_PIN_1, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);

    gpio_init(BTN_PIN_2);
    gpio_set_dir(BTN_PIN_2, GPIO_IN);
    gpio_pull_up(BTN_PIN_2);
    gpio_set_irq_enabled_with_callback(
        BTN_PIN_2, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);

    gpio_init(BTN_PIN_3);
    gpio_set_dir(BTN_PIN_3, GPIO_IN);
    gpio_pull_up(BTN_PIN_3);
    gpio_set_irq_enabled_with_callback(
        BTN_PIN_3, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);

    gpio_init(BTN_PIN_4);  // Adicionado
    gpio_set_dir(BTN_PIN_4, GPIO_IN);
    gpio_pull_up(BTN_PIN_4);
    gpio_set_irq_enabled_with_callback(
        BTN_PIN_4, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);

    gpio_init(BTN_PIN_5);  // Adicionado
    gpio_set_dir(BTN_PIN_5, GPIO_IN);
    gpio_pull_up(BTN_PIN_5);
    gpio_set_irq_enabled_with_callback(
        BTN_PIN_5, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);

    gpio_init(BTN_PIN_6);  // Adicionado
    gpio_set_dir(BTN_PIN_6, GPIO_IN);
    gpio_pull_up(BTN_PIN_6);
    gpio_set_irq_enabled_with_callback(
        BTN_PIN_6, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);
}


// void hc06_task(void *p) {
//     uart_init(HC06_UART_ID, HC06_BAUD_RATE);
//     gpio_set_function(HC06_TX_PIN, GPIO_FUNC_UART);
//     gpio_set_function(HC06_RX_PIN, GPIO_FUNC_UART);
//     hc06_init("aps2_legal", "1234");

//     while (true) {
//         uart_puts(HC06_UART_ID, "OLAAA ");
//         vTaskDelay(pdMS_TO_TICKS(100));
//     }
// }

void btns_task(void *p) {
    oled_btn_init();
    int btn;
    while (1) {
        if (xQueueReceive(xQueueBtn, &btn, portMAX_DELAY)){
            printf("Botão %d apertado!\n", btn);
        }
    }
}

int main() {
    stdio_init_all();

    printf("Start bluetooth task\n");

    xQueueBtn = xQueueCreate(32, sizeof(int));

    //xTaskCreate(hc06_task, "UART_Task 1", 4096, NULL, 1, NULL);
    xTaskCreate(btns_task, "btns_task", 4095, NULL, 1, NULL);

    vTaskStartScheduler();

    while (true)
        ;
}
