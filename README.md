<img width=100% src="https://capsule-render.vercel.app/api?type=waving&color=02A6F4&height=120&section=header"/>
<h1 align="center">Embarcatech </h1>

## Objetivo do Projeto

O objetivo deste projeto é implementar um semáforo utilizando o microcontrolador Raspberry Pi Pico W, empregando a função add_repeating_timer_ms() do Pico SDK para criar um temporizador periódico. O semáforo terá temporização de 3 segundos para cada alteração de sinal (vermelho, azul (substituindo o amarelo) e verde), controlando 3 LEDs (vermelho, azul (substituindo o amarelo) e verde) com resistores de 330 Ω. O foco é aplicar a técnica de temporização e controlar os LEDs de forma eficiente, utilizando o Raspberry Pi Pico W como base para a simulação de um semáforo.

## 🗒️ Lista de requisitos

- **Inicialização no vermelho:** O semáforo deve começar no estado vermelho.  
- **Temporização de 3 segundos:** Cada estado deve durar exatamente 3 segundos.  
- **Função de callback:** A mudança de estado dos LEDs deve ser implementada na função de callback do temporizador.  
- **Feedback no terminal:** A cada segundo, uma mensagem deve ser enviada pela porta serial.  


## 🛠 Tecnologias

- **Microcontrolador:** Raspberry Pi Pico W  
- **LEDs:** RGB (Vermelho, Verde, Azul)  
  - 1x LED Vermelho  
  - 1x LED Azul (substituindo o amarelo do semáforo)
  - 1x LED Verde  
- **Resistores:** 3x Resistores de 330 Ω  
- **Ferramenta de Simulação:** Wokwi  
- **Linguagem de Programação:** C  
- **Frameworks:** Pico SDK

## 🔧 Funcionalidades Implementadas:

1. **Inicialização no vermelho:** O semáforo começa no estado vermelho.
2. **Alternância automática:** A cada 3 segundos, o semáforo muda para a próxima cor (vermelho → azul → verde).
3. **Feedback no terminal:** A cada mudança de estado, uma mensagem é exibida no terminal indicando a cor atual.
4. **Simulação no Wokwi:** O projeto pode ser simulado no Wokwi.

## 🚀 Passos para Compilação e Upload  

1. **Clonar o repositório** 

- sh
- git clone seu repositorio
- cd semaforo-pico


2. **Configurar e compilar o projeto**  

`mkdir build && cd build`
`cmake ..`
`make`

3. **Transferir o firmware para a placa**

- Conectar a placa BitDogLab ao computador
- Copiar o arquivo .uf2 gerado para o drive da placa

4. **Testar o projeto**

🛠🔧🛠🔧🛠🔧


## 🎥 Demonstração:

Durante os testes com a plaquinha física em mãos, foi realizado um printscreen da simulação no serial monitor, que pode ser visto abaixo:

![image](https://github.com/user-attachments/assets/a5e9b7a8-fecf-436e-bc19-2bd9109b0dff)

## 💻 Desenvolvedor
 
<table>
  <tr>
    <td align="center"><img style="" src="https://avatars.githubusercontent.com/u/191687774?v=4" width="100px;" alt=""/><br /><sub><b> José Vinicius </b></sub></a><br />👨‍💻</a></td>
  </tr>
</table>
