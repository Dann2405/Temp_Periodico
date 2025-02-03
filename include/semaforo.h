#ifndef SEMAFORO
#define SEMAFORO

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h" // Inclui a biblioteca para gerenciamento de temporizadores de hardware.

const uint LED_R = 13; // Led vermelho definido na GPIO 13
const uint LED_Y = 12; // Led Amarelo definido na GPIO 12
const uint LED_G = 11; // Led Verde definido no GPIO 11

// função de inicialização dos PINOS GPIOs
void init_gpio()
{
    // inicialização das GPIOs dos Leds
    gpio_init(LED_R);
    gpio_init(LED_Y);
    gpio_init(LED_G);

    // Setando os LEDs como saida
    gpio_set_dir(LED_R, GPIO_OUT);
    gpio_set_dir(LED_Y, GPIO_OUT);
    gpio_set_dir(LED_G, GPIO_OUT);
}

#endif


