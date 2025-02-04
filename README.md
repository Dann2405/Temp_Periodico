# Temp_Periodico

## Visão Geral do Projeto

O **Temp_Periodico** é um projeto desenvolvido para demonstrar a implementação de temporização periódica utilizando a função `add_repeating_timer_ms()` do **Pico SDK** no microcontrolador **RP2040**. O objetivo principal é o controle de um sistema semafórico, proporcionando uma aplicação prática e didática da funcionalidade de temporizadores em sistemas embarcados.

Este projeto pode ser executado tanto no **Wokwi Simulator** (integrado ao **VS Code**) quanto em hardware real, utilizando a placa de desenvolvimento **BitDogLab**.

### Principais Funcionalidades

- **Controle de Semáforo:** Alterna o estado de três LEDs em um ciclo de 3 segundos, simulando o funcionamento de um semáforo convencional:
  - Nos primeiros 3 segundos (contando a partir do numero 0 até o 2 (0,1,2)), todos os leds permanecem apagados. (Válido apenas na inicialização do programa.)
  - Após os três segundos iniciais o LED **vermelho** acende enquanto os demais permanecem apagados.
  - Após 3 segundos, o LED **amarelo** acende e os outros são desligados.
  - Depois de mais 3 segundos, o LED **verde** acende e os demais são desligados.
  - Sempre que um LED do semaforo ascende, o estado do mesmo é exibido no terminal.
  - O ciclo se repete continuamente.

---

## Requisitos do Sistema

- **Microcontrolador:** Raspberry Pi Pico ou Raspberry Pi Pico W (opcional para execução em hardware real).
- **Placa de Desenvolvimento:** BitDogLab (opcional).
- **Simulador:** [Wokwi Simulator](https://wokwi.com/) (necessário para testes em ambiente virtual).
- **Ambiente de Desenvolvimento:** Visual Studio Code (VS Code) com extensões adequadas.
- **SDK do Raspberry Pi Pico** corretamente configurado.

---

## Guia de Instalação e Uso

### 1. Clonando o Repositório

Para obter o código-fonte do projeto, utilize o seguinte comando:

```bash
git clone https://github.com/Dann2405/Temp_Periodico.git
cd Temp_Periodico
```

---

### 2. Configuração do Ambiente

Certifique-se de que o **SDK do Raspberry Pi Pico** está corretamente instalado e configurado no **VS Code**. Além disso, instale as seguintes extensões recomendadas:

- **C/C++** (Microsoft).
- **CMake Tools**.
- **Wokwi Simulator** (necessário para simulação no VS Code).
- **[Raspberry Pi Pico W](https://marketplace.visualstudio.com/items?itemName=raspberry-pi.raspberry-pi-pico)**.

---

### 3. Configuração do Projeto no VS Code

1. Abra o projeto no **Visual Studio Code**.
2. Confirme a instalação das extensões recomendadas.
3. Compile o projeto através da interface da extensão do Raspberry Pi Pico:
    - Clique em **"Compile Project"**.
    - O processo gerará um arquivo `.uf2`, necessário para a execução em hardware real e simulação no Wokwi.

---

### 4. Execução no Simulador Wokwi

Para testar o projeto no **Wokwi Simulator**, siga os passos abaixo:

1. Abra o arquivo `diagram.json` no **VS Code**.
2. Clique no botão **"Play"** para iniciar a simulação.
3. O comportamento esperado do semáforo é:
   - A cada 3 segundos, um LED diferente acende (vermelho, amarelo e verde), enquanto os demais permanecem apagados, sempre exibindo o estado do semaforo no terminal.
   - O terminal exibirá a mensagem "1 segundo se passou" periodicamente, permitindo a monitoração do funcionamento da temporização.

---

### 5. Teste em Hardware Real

#### Configuração na Placa **BitDogLab** com **Raspberry Pi Pico W**

1. **Modo de Programação:**
   - Conecte a placa ao computador e entre no modo **BOOTSEL**:
     - Pressione e segure o botão **BOOTSEL** (localizado na parte traseira da placa).
     - Pressione rapidamente o botão **RESET** (frontal da placa).
     - Após alguns segundos, solte o botão **RESET** primeiro e depois o **BOOTSEL**.
     - A placa será reconhecida como uma unidade de armazenamento.

2. **Compilação e Upload:**
   - No **VS Code**, utilize a extensão do [Raspberry Pi Pico W](https://marketplace.visualstudio.com/items?itemName=raspberry-pi.raspberry-pi-pico):
     - Clique em **"Compile Project"**.
     - Em seguida, clique em **"Run Project USB"** para transferir o código para a placa.

3. **Configuração de Hardware Alternativa:**
   Se não estiver utilizando a BitDogLab, é possível montar o circuito utilizando uma protoboard ou outro microcontrolador, conforme a seguinte pinagem:

   | **Periférico**      | **Pino GPIO** |
   |---------------------|--------------|
   | LED Vermelho        | GP13         |
   | LED Amarelo         | GP12         |
   | LED Verde           | GP11         |

4. **Observação:**
   - Se estiver utilizando a placa **BitDogLab**, o **LED Azul** substituirá o LED Amarelo do semáforo.

---

## Considerações Finais

Este projeto ilustra a aplicação de temporizadores no **Raspberry Pi Pico**, sendo útil para sistemas embarcados que demandam controle preciso de eventos cíclicos. O uso do **Wokwi Simulator** permite a validação da lógica sem a necessidade de hardware físico.


