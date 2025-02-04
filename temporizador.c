#include <stdio.h>
#include "pico/stdlib.h"


// Definindo os pinos dos leds (Utilizando o LED RGB - GPIOs 11, 12 e 13)
const uint led_pin_vermelho = 11; 
const uint led_pin_amarelo = 12;
const uint led_pin_verde = 13;

/*
Acionamento dos leds (sinais do semáforo)

1 - vermelho ligado, amarelo e verde desligados
2 - amarelo ligado, vermelho e verde desligados
3 - verde ligado, vermelho e amarelo desligados
*/
void semaforo(int estado){
    switch (estado){
        case 1: //vermelho
            gpio_put(led_pin_vermelho, 1);
            gpio_put(led_pin_amarelo, 0);
            gpio_put(led_pin_verde, 0);
            break;
        case 2: //amarelo
            gpio_put(led_pin_vermelho, 0);
            gpio_put(led_pin_amarelo, 1);
            gpio_put(led_pin_verde, 0);
            break;
        case 3: //verde
            gpio_put(led_pin_vermelho, 0);
            gpio_put(led_pin_amarelo, 0);
            gpio_put(led_pin_verde, 1);
            break;
    }
}

// Função de temporização (mudança de estado do LED) **copilot**
bool repeating_timer_callback (struct repeating_timer *t){
    static int estado = 1; //estado inicial
    semaforo(estado); //chama a função semáforo
    estado++; //incrementa o estado

    //se o estado for maior que 3, volta para 1
    if (estado > 3){ 
        estado = 1;
    }
    return true;
}

int main()
{
    stdio_init_all(); //inicializa a comunicação serial

    //inicializa os pinos dos leds
    gpio_init(led_pin_vermelho);
    gpio_set_dir(led_pin_vermelho, GPIO_OUT);
    gpio_init(led_pin_amarelo);
    gpio_set_dir(led_pin_amarelo, GPIO_OUT);
    gpio_init(led_pin_verde);
    gpio_set_dir(led_pin_verde, GPIO_OUT);

    //chamar as funções de temporização
    struct repeating_timer timer;
     
    // temporizador ajustado para um atraso de 3 segundos (3000 ms)
    // "com emprego da função add_repeating_timer_ms"
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Rotina principal
    while (true) {
        printf("Opa, passou 1 segundo!\n");
        sleep_ms(1000);
    }
}
