# README - Semáforo com Raspberry Pi Pico

Este projeto implementa um sistema de semáforo utilizando o Raspberry Pi Pico e LEDs RGB conectados aos pinos GPIO 11, 12 e 13. O código alterna entre três estados de semáforo (vermelho, amarelo e verde) a cada 3 segundos.

## 📌 Requisitos

- **Raspberry Pi Pico**
- **3 LEDs** (Vermelho, Amarelo e Verde) ou um LED RGB com controle individual de cores
- **3 resistores** apropriados para os LEDs
- **Fios e protoboard**
- **SDK do Raspberry Pi Pico** instalado no ambiente de desenvolvimento

## 🔧 Instalação e Configuração

1. **Configuração do ambiente**
   - Instale o SDK do Raspberry Pi Pico conforme a [documentação oficial](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf).
   - Conecte o Raspberry Pi Pico ao computador via USB.
   - Compile o código utilizando um compilador compatível (exemplo: `cmake` e `make`).

2. **Montagem do circuito**
   - Conecte os LEDs aos seguintes pinos GPIO:
     - **Vermelho** → GPIO 11
     - **Amarelo** → GPIO 12
     - **Verde** → GPIO 13
   - O terminal negativo dos LEDs deve ser conectado ao **GND** do Raspberry Pi Pico.

## 🚦 Funcionamento do Programa

1. **Inicialização**
   - O programa inicializa a comunicação serial e configura os pinos GPIO como saída.

2. **Alternância do semáforo**
   - Um temporizador altera o estado do semáforo a cada **3 segundos**, seguindo a sequência:
     1. **Vermelho ligado**, Amarelo e Verde desligados.
     2. **Amarelo ligado**, Vermelho e Verde desligados.
     3. **Verde ligado**, Vermelho e Amarelo desligados.

3. **Execução contínua**
   - O programa exibe uma mensagem no terminal a cada segundo (`"Opa, passou 1 segundo!"`).

## ▶️ Como Executar

1. Compile o código com o SDK do Raspberry Pi Pico.
2. Carregue o arquivo `.uf2` no Raspberry Pi Pico.
3. Conecte ao terminal serial para visualizar as mensagens do programa.
