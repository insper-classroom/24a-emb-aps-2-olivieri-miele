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

#include "hardware/adc.h"

const int BTN_PIN_1 = 12;
const int BTN_PIN_2 = 13;
const int BTN_PIN_3 = 14;
const int BTN_PIN_4 = 15;
const int BTN_PIN_5 = 16;
const int BTN_PIN_6 = 17;
const int BTN_PIN_7 = 18;
const int BTN_PIN_8 = 19;
const int BTN_PIN_9 = 20;
const int BTN_PIN_10 = 21;
const int BTN_PIN_11 = 22;

const int PIN_X = 26;
const int PIN_Y = 27;

QueueHandle_t xQueueBtn;
QueueSetHandle_t xQueueAdc;

typedef struct adc {
    int axis;
    int val;
} adc_t;

void write_package(adc_t data){
    int val = data.val;
    int msb = val >> 8;
    int lsb = val & 0xFF;
    uart_putc_raw(uart0, data.axis);
    uart_putc_raw(uart0, lsb);
    uart_putc_raw(uart0, msb);
    uart_putc_raw(uart0, -1);
}

void gpio_callback(uint gpio, uint32_t events) {
    adc_t btn;
    if (gpio == BTN_PIN_1){
        if (events == 0x4) { //fall edge
            btn.axis = 11;
            btn.val = 1;
        } else { //rise edge
            btn.axis = 11;
            btn.val = 1;
        }
        xQueueSendFromISR(xQueueBtn, &btn, 0);
    }
    if (gpio == BTN_PIN_2){
        if (events == 0x4) { //fall edge
            btn.axis = 12;
            btn.val = 1;
        } else { //rise edge
            btn.axis = 12;
            btn.val = 1;
        }
        xQueueSendFromISR(xQueueBtn, &btn, 0);
    }
    if (gpio == BTN_PIN_3){
        if (events == 0x4) { //fall edge
            btn.axis = 13;
            btn.val = 1;
        } else { //rise edge
            btn.axis = 13;
            btn.val = 1;
        }
        xQueueSendFromISR(xQueueBtn, &btn, 0);
    }
    if (gpio == BTN_PIN_4){
        if (events == 0x4) { //fall edge
            btn.axis = 14;
            btn.val = 1;
        } else { //rise edge
            btn.axis = 14;
            btn.val = 1;
        }
        xQueueSendFromISR(xQueueBtn, &btn, 0);
    }
    if (gpio == BTN_PIN_5){
        if (events == 0x4) { //fall edge
            btn.axis = 15;
            btn.val = 1;
        } else { //rise edge
            btn.axis = 15;
            btn.val = 1;
        }
        xQueueSendFromISR(xQueueBtn, &btn, 0);
    }
    if (gpio == BTN_PIN_6){
        if (events == 0x4) { //fall edge
            btn.axis = 16;
            btn.val = 1;
        } else { //rise edge
            btn.axis = 16;
            btn.val = 1;
        }
        xQueueSendFromISR(xQueueBtn, &btn, 0);
    }
    if (gpio == BTN_PIN_7){
        if (events == 0x4) { //fall edge
            btn.axis = 17;
            btn.val = 1;
        } else { //rise edge
            btn.axis = 17;
            btn.val = 1;
        }
        xQueueSendFromISR(xQueueBtn, &btn, 0);
    }
    if (gpio == BTN_PIN_8){
        if (events == 0x4) { //fall edge
            btn.axis = 18;
            btn.val = 1;
        } else { //rise edge
            btn.axis = 18;
            btn.val = 1;
        }
        xQueueSendFromISR(xQueueBtn, &btn, 0);
    }
    if (gpio == BTN_PIN_9){
        if (events == 0x4) { //fall edge
            btn.axis = 19;
            btn.val = 1;
        } else { //rise edge
            btn.axis = 19;
            btn.val = 1;
        }
        xQueueSendFromISR(xQueueBtn, &btn, 0);
    }
    if (gpio == BTN_PIN_10){
        if (events == 0x4) { //fall edge
            btn.axis = 20;
            btn.val = 1;
        } else { //rise edge
            btn.axis = 20;
            btn.val = 1;
        }
        xQueueSendFromISR(xQueueBtn, &btn, 0);
    }
    if (gpio == BTN_PIN_11){
        if (events == 0x4) { //fall edge
            btn.axis = 21;
            btn.val = 1;
        } else { //rise edge
            btn.axis = 21;
            btn.val = 1;
        }
        xQueueSendFromISR(xQueueBtn, &btn, 0);
    }
    
}

void oled_btn_init(void) {
    // Inicializa botões
    gpio_init(BTN_PIN_1);
    gpio_set_dir(BTN_PIN_1, GPIO_IN);
    gpio_pull_up(BTN_PIN_1);
    gpio_set_irq_enabled_with_callback(
        BTN_PIN_1, GPIO_IRQ_EDGE_FALL | GPIO_IRQ_EDGE_RISE, true, &gpio_callback);

    gpio_init(BTN_PIN_2);
    gpio_set_dir(BTN_PIN_2, GPIO_IN);
    gpio_pull_up(BTN_PIN_2);
    gpio_set_irq_enabled_with_callback(
        BTN_PIN_2, GPIO_IRQ_EDGE_FALL | GPIO_IRQ_EDGE_RISE, true, &gpio_callback);

    gpio_init(BTN_PIN_3);
    gpio_set_dir(BTN_PIN_3, GPIO_IN);
    gpio_pull_up(BTN_PIN_3);
    gpio_set_irq_enabled_with_callback(
        BTN_PIN_3, GPIO_IRQ_EDGE_FALL | GPIO_IRQ_EDGE_RISE, true, &gpio_callback);

    gpio_init(BTN_PIN_4);  // Adicionado
    gpio_set_dir(BTN_PIN_4, GPIO_IN);
    gpio_pull_up(BTN_PIN_4);
    gpio_set_irq_enabled_with_callback(
        BTN_PIN_4, GPIO_IRQ_EDGE_FALL | GPIO_IRQ_EDGE_RISE, true, &gpio_callback);

    gpio_init(BTN_PIN_5);  // Adicionado
    gpio_set_dir(BTN_PIN_5, GPIO_IN);
    gpio_pull_up(BTN_PIN_5);
    gpio_set_irq_enabled_with_callback(
        BTN_PIN_5, GPIO_IRQ_EDGE_FALL | GPIO_IRQ_EDGE_RISE, true, &gpio_callback);

    gpio_init(BTN_PIN_6);  // Adicionado
    gpio_set_dir(BTN_PIN_6, GPIO_IN);
    gpio_pull_up(BTN_PIN_6);
    gpio_set_irq_enabled_with_callback(
        BTN_PIN_6, GPIO_IRQ_EDGE_FALL |GPIO_IRQ_EDGE_RISE, true, &gpio_callback);
        
    gpio_init(BTN_PIN_7);  // Adicionado
    gpio_set_dir(BTN_PIN_7, GPIO_IN);
    gpio_pull_up(BTN_PIN_7);
    gpio_set_irq_enabled_with_callback(
        BTN_PIN_7, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);
    
    gpio_init(BTN_PIN_8);  // Adicionado
    gpio_set_dir(BTN_PIN_8, GPIO_IN);
    gpio_pull_up(BTN_PIN_8);
    gpio_set_irq_enabled_with_callback(
        BTN_PIN_8, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);

    gpio_init(BTN_PIN_9);  // Adicionado
    gpio_set_dir(BTN_PIN_9, GPIO_IN);
    gpio_pull_up(BTN_PIN_9);
    gpio_set_irq_enabled_with_callback(
        BTN_PIN_9, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);

    gpio_init(BTN_PIN_10);  // Adicionado
    gpio_set_dir(BTN_PIN_10, GPIO_IN);
    gpio_pull_up(BTN_PIN_10);
    gpio_set_irq_enabled_with_callback(
        BTN_PIN_10, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);

    gpio_init(BTN_PIN_11);  // Adicionado
    gpio_set_dir(BTN_PIN_11, GPIO_IN);
    gpio_pull_up(BTN_PIN_11);
    gpio_set_irq_enabled_with_callback(
        BTN_PIN_11, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);
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
    adc_t btn;
    while (1) {
        if (xQueueReceive(xQueueBtn, &btn, portMAX_DELAY)){
            write_package(btn);
        }
    }
}

int transform_to_centered_scale(uint16_t adc_value) {
    // Transforma de 0-4095 para -2047 a +2047
    return adc_value - 2048;
}

int reduce_resolution(int centered_value) {
    // Mapeia de -2047 a +2047 para -255 a +255
    // Isto pode ser feito dividindo o valor centralizado por 8, assumindo que a relação de escala é linear
    return centered_value / 8;
}

int apply_dead_zone(int reduced_value) {
    // Se o valor estiver dentro de -30 a +30, defina como zero
    if (reduced_value >= -30 && reduced_value <= 30) {
        return 0;
    }
    return reduced_value;
}

void x_task(void  *p) {
    adc_init();
    adc_gpio_init(PIN_X);


    const int windowSize = 5; // Tamanho da janela para a média móvel
    float window[5] = {0,0,0,0,0}; // Inicializa a janela com 0
    float windowSum = 0; // Soma dos valores na janela
    int dataIndex = 0; // Índice atual na janela


    while (1) {
        adc_select_input(0); // Select ADC input 0 (GPIO26)
        uint16_t result;
        result = adc_read();

        // Aplica as transformações de escala
        int centered_value = transform_to_centered_scale(result);
        int reduced_value = reduce_resolution(centered_value);
        int dead_zone_value = apply_dead_zone(reduced_value);

        // Subtrai o valor antigo e adiciona o novo valor à soma da janela
        windowSum -= window[dataIndex];
        window[dataIndex] = dead_zone_value;
        windowSum += dead_zone_value;

        // Calcula a média móvel
        float movingAverage = windowSum / windowSize;

        // Imprime a tensão média
        //printf("X: %f V\n", movingAverage);

        adc_t x;
        x.axis = 0;
        x.val = movingAverage;

        xQueueSend(xQueueAdc, &x, 0);

        // Avança o índice da janela circularmente
        dataIndex = (dataIndex + 1) % windowSize;

        vTaskDelay(pdMS_TO_TICKS(200));
    }
}

void y_task(void *p) {
    adc_init();
    adc_gpio_init(PIN_Y);


    const int windowSize = 5; // Tamanho da janela para a média móvel
    float window[5] = {0,0,0,0,0}; // Inicializa a janela com 0
    float windowSum = 0; // Soma dos valores na janela
    int dataIndex = 0; // Índice atual na janela


    while (1) {
        adc_select_input(1); // Select ADC input 0 (GPIO26)
        uint16_t result;
        result = adc_read();

        // Aplica as transformações de escala
        int centered_value = transform_to_centered_scale(result);
        int reduced_value = reduce_resolution(centered_value);
        int dead_zone_value = apply_dead_zone(reduced_value);

        // Subtrai o valor antigo e adiciona o novo valor à soma da janela
        windowSum -= window[dataIndex];
        window[dataIndex] = dead_zone_value;
        windowSum += dead_zone_value;

        // Calcula a média móvel
        float movingAverage = windowSum / windowSize;

        // Imprime a tensão média
        //printf("Y: %f V\n", movingAverage);

        adc_t y;
        y.axis = 1;
        y.val = movingAverage;

        xQueueSend(xQueueAdc, &y, 0);

        // Avança o índice da janela circularmente
        dataIndex = (dataIndex + 1) % windowSize;

        vTaskDelay(pdMS_TO_TICKS(200));
    }
}


void uart_task(void *p) {
    adc_t data;

    while (1) {
        if (xQueueReceive(xQueueAdc, &data, portMAX_DELAY)){
            write_package(data);
        }
    }
}

    int main() {
    stdio_init_all();

    //printf("Start bluetooth task\n");

    xQueueBtn = xQueueCreate(32, sizeof(adc_t));
    xQueueAdc = xQueueCreate(32, sizeof(adc_t));

    xTaskCreate(x_task, "x_task", 4096, NULL, 1, NULL);
    xTaskCreate(y_task, "y_task", 4096, NULL, 1, NULL);
    xTaskCreate(uart_task, "uart_task", 4096, NULL, 1, NULL);

    //xTaskCreate(hc06_task, "UART_Task 1", 4096, NULL, 1, NULL);
    xTaskCreate(btns_task, "btns_task", 4095, NULL, 1, NULL);

    vTaskStartScheduler();

    while (true)
        ;
}
