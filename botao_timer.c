#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

// Definição dos pinos dos LEDs
const uint LED_RED_PIN = 13;   // LED Vermelho no GPIO 13
const uint LED_BLUE_PIN = 12;  // LED Azul no GPIO 12
const uint LED_GREEN_PIN = 11; // LED Verde no GPIO 11

// Variável de controle do estado do semáforo
int semaforo_estado = 0; // 0: Vermelho, 1: Azul, 2: Verde
const char *cores[] = {"Vermelho", "Azul", "Verde"}; // Nome das cores

// Função de callback do temporizador periódico
bool repeating_timer_callback(struct repeating_timer *t) {
    // Desliga todos os LEDs antes de ligar o próximo
    gpio_put(LED_RED_PIN, false);
    gpio_put(LED_BLUE_PIN, false);
    gpio_put(LED_GREEN_PIN, false);

    // Alterna entre os estados do semáforo
    semaforo_estado = (semaforo_estado + 1) % 3; // 0 -> 1 -> 2 -> 0

    // Liga o LED correspondente
    switch (semaforo_estado) {
        case 0:
            gpio_put(LED_RED_PIN, true);
            break;
        case 1:
            gpio_put(LED_BLUE_PIN, true);
            break;
        case 2:
            gpio_put(LED_GREEN_PIN, true);
            break;
    }

    // Exibe a mudança de cor no Serial Monitor
    printf("\n--------------------------------\n");
    printf("MUDOU PARA O LED %s   :-)", cores[semaforo_estado]);
    printf("\n--------------------------------\n\n");

    return true; // Continua repetindo o temporizador
}

int main() {
    stdio_init_all();

    // Inicializa os pinos dos LEDs como saída
    gpio_init(LED_RED_PIN);
    gpio_set_dir(LED_RED_PIN, GPIO_OUT);
    gpio_init(LED_BLUE_PIN);
    gpio_set_dir(LED_BLUE_PIN, GPIO_OUT);
    gpio_init(LED_GREEN_PIN);
    gpio_set_dir(LED_GREEN_PIN, GPIO_OUT);

    // **Ajuste 1:** Liga imediatamente o LED vermelho no início
    gpio_put(LED_RED_PIN, true);
    printf("*SISTEMA INICIADO - LED VERMELHO ACESO*\n");

    // Configura o temporizador para chamar a função a cada 3 segundos
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop principal com contagem regressiva dinâmica
    while (true) {
        for (int i = 3; i > 0; i--) {
            printf("Sistema operando... Mudança para LED %s em %d segundo%s.\n", 
                   cores[(semaforo_estado + 1) % 3], i, (i == 1 ? "" : "s"));
            sleep_ms(1000);
        }
    }

    return 0;
}
