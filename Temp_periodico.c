#include <stdio.h>
#include "pico/stdlib.h"
#include "include/semaforo.h"


int main()
{
    stdio_init_all();
    init_gpio();

    // Configura o temporizador para chamar a função de callback a cada 3 segundos.
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (true) {
        // Pausa de 1 segundos para reduzir o uso da CPU.
        sleep_ms(1000);
        printf("1 Segundo se passou!\n");
    }
}
