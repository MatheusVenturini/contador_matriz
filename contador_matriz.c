#include <stdio.h>
#include "pico/stdlib.h"
#include "matriz_rgb.h"
#include "hardware/timer.h"
void contador_matriz();


#define PINO_LED_VERMELHO 13  // LED vermelho no pino 13
#define PINO_LED_AZUL 12      // LED azul no pino 12
#define PINO_LED_VERDE 11     // LED verde no pino 11
const uint BOTAO_1 = 5;  // Botão 1 conectado ao pino 5
const uint BOTAO_2 = 6;  // Botão 2 conectado ao pino 6
#define INTERVALO 100   // Intervalo de tempo para piscar LED

// Variáveis globais
int contador = 0;
static volatile uint32_t ultimo_evento = 0;
bool botao_1_press = false;
bool botao_2_press = false;

// Função de interrupção para tratar os botões
void tratar_interrupcao(uint pino, uint32_t eventos) {
    uint32_t tempo_atual = to_us_since_boot(get_absolute_time());
    
    if (tempo_atual - ultimo_evento > 300000) { // Debounce de 300 ms
        ultimo_evento = tempo_atual;
        
        if (pino == BOTAO_1) {
            botao_1_press = true;
            printf("Botão 1 pressionado\n");
        } else if (pino == BOTAO_2) {
            botao_2_press = true;
            printf("Botão 2 pressionado\n");
        }
    }
}

int main() {
    // Inicialização do sistema
    stdio_init_all();
    npInit(LED_PIN);

    // Configuração dos LEDs como saída
    gpio_init(PINO_LED_VERMELHO);
    gpio_set_dir(PINO_LED_VERMELHO, GPIO_OUT);

    // Configuração dos botões como entrada com pull-up
    gpio_init(BOTAO_1);
    gpio_set_dir(BOTAO_1, GPIO_IN);
    gpio_pull_up(BOTAO_1);

    gpio_init(BOTAO_2);
    gpio_set_dir(BOTAO_2, GPIO_IN);
    gpio_pull_up(BOTAO_2);

    // Configuração das interrupções para os botões
    gpio_set_irq_enabled_with_callback(BOTAO_1, GPIO_IRQ_EDGE_FALL, true, &tratar_interrupcao);
    gpio_set_irq_enabled_with_callback(BOTAO_2, GPIO_IRQ_EDGE_FALL, true, &tratar_interrupcao);

    while (true) {
        if (botao_1_press) {
            if (contador > 0) contador--;
            printf("Contador = %d\n", contador);
            contador_matriz(contador);
            botao_1_press = false;
        }

        if (botao_2_press) {
            if (contador < 9) contador++;
            printf("Contador = %d\n", contador);
            contador_matriz(contador);
            botao_2_press = false;
        }

        // Pisca o LED vermelho como indicação de funcionamento
        gpio_put(PINO_LED_VERMELHO, 1);
        sleep_ms(INTERVALO);
        gpio_put(PINO_LED_VERMELHO, 0);
        sleep_ms(INTERVALO);
    }
}


void contador_matriz(int a){
        npClear();

        if (a == 0) {
                //frame 0 
                int frame[5][5][3] = {
                        {{0, 0, 0}, {0, 202, 179}, {0, 202, 179}, {0, 202, 179}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 202, 179}, {0, 0, 0}, {0, 202, 179}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 202, 179}, {0, 0, 0}, {0, 202, 179}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 202, 179}, {0, 0, 0}, {0, 202, 179}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 202, 179}, {0, 202, 179}, {0, 202, 179}, {0, 0, 0}}
                };
                desenho_sprite(frame);
        }

        else if (a == 1) {
                //frame 1 
                int frame[5][5][3] = {
                        {{0, 0, 0}, {0, 202, 179}, {0, 202, 179}, {0, 0, 0}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 0, 0}, {0, 202, 179}, {0, 0, 0}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 0, 0}, {0, 202, 179}, {0, 0, 0}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 0, 0}, {0, 202, 179}, {0, 0, 0}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 202, 179}, {0, 202, 179}, {0, 202, 179}, {0, 0, 0}}
                };
                desenho_sprite(frame);
        }

        else if (a == 2) {
                //frame 2 
                int frame[5][5][3] = {
                        {{0, 0, 0}, {0, 202, 179}, {0, 202, 179}, {0, 202, 179}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 202, 179}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 202, 179}, {0, 202, 179}, {0, 202, 179}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 202, 179}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 202, 179}, {0, 202, 179}, {0, 202, 179}, {0, 0, 0}}
                };
                desenho_sprite(frame);
        }

        else if (a == 3) {
                //frame 3 
                int frame[5][5][3] = {
                        {{0, 0, 0}, {0, 202, 179}, {0, 202, 179}, {0, 202, 179}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 202, 179}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 202, 179}, {0, 202, 179}, {0, 202, 179}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 202, 179}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 202, 179}, {0, 202, 179}, {0, 202, 179}, {0, 0, 0}}
                };
                desenho_sprite(frame);
        }
        
        else if (a == 4) {
                //frame 4 
                int frame[5][5][3] = {
                        {{0, 0, 0}, {0, 202, 179}, {0, 0, 0}, {0, 202, 179}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 202, 179}, {0, 0, 0}, {0, 202, 179}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 202, 179}, {0, 202, 179}, {0, 202, 179}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 202, 179}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 202, 179}, {0, 0, 0}}
                };
                desenho_sprite(frame);
        }

        else if (a == 5) {
                //frame 5 
                int frame[5][5][3] = {
                        {{0, 0, 0}, {0, 202, 179}, {0, 202, 179}, {0, 202, 179}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 202, 179}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 202, 179}, {0, 202, 179}, {0, 202, 179}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 202, 179}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 202, 179}, {0, 202, 179}, {0, 202, 179}, {0, 0, 0}}
                };
                desenho_sprite(frame);
        }

        else if (a == 6) {
                //frame 6 
                int frame[5][5][3] = {
                        {{0, 0, 0}, {0, 202, 179}, {0, 202, 179}, {0, 202, 179}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 202, 179}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 202, 179}, {0, 202, 179}, {0, 202, 179}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 202, 179}, {0, 0, 0}, {0, 202, 179}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 202, 179}, {0, 202, 179}, {0, 202, 179}, {0, 0, 0}}
                };
                desenho_sprite(frame);
        }

        else if (a == 7) {
                //frame 7 
                int frame[5][5][3] = {
                        {{0, 0, 0}, {0, 202, 179}, {0, 202, 179}, {0, 202, 179}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 202, 179}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 0, 0}, {0, 202, 179}, {0, 0, 0}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 0, 0}, {0, 202, 179}, {0, 0, 0}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 0, 0}, {0, 202, 179}, {0, 0, 0}, {0, 0, 0}}
                };
                desenho_sprite(frame);
        }

        else if (a == 8) {
                //frame 8 
                int frame[5][5][3] = {
                        {{0, 0, 0}, {0, 202, 179}, {0, 202, 179}, {0, 202, 179}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 202, 179}, {0, 0, 0}, {0, 202, 179}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 202, 179}, {0, 202, 179}, {0, 202, 179}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 202, 179}, {0, 0, 0}, {0, 202, 179}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 202, 179}, {0, 202, 179}, {0, 202, 179}, {0, 0, 0}}
                };
                desenho_sprite(frame);
        }

        else if (a == 9) {
                //frame 9 
                int frame[5][5][3] = {
                        {{0, 0, 0}, {0, 202, 179}, {0, 202, 179}, {0, 202, 179}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 202, 179}, {0, 0, 0}, {0, 202, 179}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 202, 179}, {0, 202, 179}, {0, 202, 179}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 202, 179}, {0, 0, 0}},
                        {{0, 0, 0}, {0, 202, 179}, {0, 202, 179}, {0, 202, 179}, {0, 0, 0}}
                };
                desenho_sprite(frame);
        }
 npWrite(); // Escreve os dados nos LEDs.  
}
