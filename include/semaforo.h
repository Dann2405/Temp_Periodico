#ifndef SEMAFORO
#define SEMAFORO

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h" // Inclui a biblioteca para gerenciamento de temporizadores de hardware.

// Declaração de uma estrutura de temporizador de repetição.
// Esta estrutura armazenará informações sobre o temporizador configurado.
struct repeating_timer timer;

bool repeating_timer_callback(struct repeating_timer *t); // prototipo da função callback para evitar erros na compilação
int state = 0; // variavel para alterar os estados dos LEDs

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

// função de callback do semaforo
bool repeating_timer_callback(struct repeating_timer *t)
{   
    // switch para trocar os estados dos LEDs
    switch (state)
    {
    case 0:
        gpio_put(LED_R, 1);
        gpio_put(LED_Y, 0);
        gpio_put(LED_G, 0);
        break;
    case 1:
        gpio_put(LED_R, 0);
        gpio_put(LED_Y, 1);
        gpio_put(LED_G, 0);
        break;
    case 2:
        gpio_put(LED_R, 0);
        gpio_put(LED_Y, 0);
        gpio_put(LED_G, 1);
        break;
    default:
        break;
    }

    state = (state + 1) % 3; // operação para o state ficar 0, 1 ou 2, criando um contador cíclico

    return true;
}

#endif


