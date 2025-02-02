📌 Contador Matriz - Raspberry Pi Pico
📖 Sobre o Projeto
O contador_matriz é um programa desenvolvido para a Raspberry Pi Pico que utiliza uma matriz de LEDs RGB (NeoPixel) para exibir uma contagem numérica. A contagem pode ser controlada através de dois botões físicos (botão A e botão B), permitindo incrementar e decrementar o valor exibido.

O código utiliza:

GPIOs para leitura dos botões físicos
Interrupções para detecção eficiente dos eventos de pressionamento
Temporização (Debounce) para evitar leituras indesejadas
Matriz RGB (NeoPixel) para exibição visual da contagem
LEDs de status para indicar a atividade do sistema

🕹 Como Usar
1️⃣ Ligar a Raspberry Pi Pico

O LED vermelho piscará, indicando que o sistema está rodando.
2️⃣ Controlar a contagem

Pressione o botão A (GPIO 5) para diminuir a contagem.
Pressione o botão B (GPIO 6) para aumentar a contagem.
A matriz NeoPixel exibirá o número correspondente à contagem.
3️⃣ Visualização

O LED vermelho pisca para indicar que o sistema está funcionando.
A contagem é limitada de 0 a 9.

Pré-requisitos para abrir o projeto:

Para configurar o ambiente de desenvolvimento, siga as instruções abaixo:

1. Instalar o Visual Studio Code
Acesse o site oficial e faça o download: Visual Studio Code.
Instale o programa e configure conforme necessário.
Adicione a extensão Wokwi e faça sua integração com o VS CODE para simular o hardware.

2. Instalar o CMake
Baixe o instalador do CMake: CMake.
Durante a instalação, marque a opção "Add CMake to the system PATH".
Conclua a instalação.

3. Instalar o GCC para ARM
Baixe o compilador ARM GNU em: GCC ARM Toolchain.
Após a instalação, adicione o diretório do executável ao PATH:
Vá para Configurações do Sistema > Variáveis de Ambiente.
Edite a variável Path e adicione:
C:\Program Files (x86)\Arm GNU Toolchain\<versão>\bin
Substitua <versão> pela versão instalada.

4. Instalar o Git
Faça o download: Git para Windows.
Instale o programa e configure-o.
Abra o terminal (Git Bash ou CMD) e configure seu nome e e-mail:
git config --global user.name "Seu Nome"
git config --global user.email "seu.email@exemplo.com"

5. Instale o Raspberry Pi Pico SDK
Faça o download aqui: Pico Setup Windows.
Para testar o projeto em uma placa fisica siga as seguintes instruções:
Instale o Zadig para configuração de drivers
Para a comunicação serial baixe o PuTTY
