# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 1.5.1)
set(toolchainVersion 13_2_Rel1)
set(picotoolVersion 2.0.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Inicializa o pico_sdk
include(pico_sdk_import.cmake)

# Define o nome do projeto
project(contador_matriz_pio C CXX ASM)

# Inicializa o Raspberry Pi Pico SDK
pico_sdk_init()

# Adiciona o executável (referenciando o novo arquivo .c)
add_executable(contador_matriz_pio contador_matriz.c)

pico_set_program_name(contador_matriz_pio "contador_matriz_pio")
pico_set_program_version(contador_matriz_pio "0.1")

# Gerar cabeçalho PIO, se necessário
pico_generate_pio_header(contador_matriz_pio ${CMAKE_CURRENT_LIST_DIR}/ws2818b.pio)

# Ativa saída via UART/USB
pico_enable_stdio_uart(contador_matriz_pio 0)
pico_enable_stdio_usb(contador_matriz_pio 1)

# Adiciona a biblioteca padrão ao build
target_link_libraries(contador_matriz_pio pico_stdlib)

# Inclui os diretórios necessários
target_include_directories(contador_matriz_pio PRIVATE ${CMAKE_CURRENT_LIST_DIR})

# Adiciona bibliotecas específicas
target_link_libraries(contador_matriz_pio 
        hardware_pio
        hardware_clocks
)

# Gera arquivos binários adicionais (UF2, bin, hex)
pico_add_extra_outputs(contador_matriz_pio)
