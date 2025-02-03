#include <stdio.h>
#include "pico/stdlib.h"
#include "include/semaforo.h"


int main()
{
    stdio_init_all();
    init_gpio();

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
