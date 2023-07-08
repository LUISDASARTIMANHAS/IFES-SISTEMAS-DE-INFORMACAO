; Atividade 9: Carregue valores na memória, começando do endereço $100 os valores de 10 a 20. Depois subtraia de 3 cada endereço de memória

; Carregar valores de 10 a 20 na memória, a partir do endereço $100, e subtrair 3 de cada endereço
LDI R16, 10     ; Inicializa o registrador R16 com o valor 10 (primeiro valor a ser armazenado)
LDI R17, $100   ; Inicializa o registrador R17 com o endereço de memória $100 (endereço inicial)
LDI R18, 20     ; Inicializa o registrador R18 com o valor 20 (último valor a ser armazenado + 1)

load_loop:
    ST R16, R17  ; Armazena o valor de R16 na memória no endereço apontado por R17
    INC R16      ; Incrementa o valor de R16 para o próximo valor
    INC R17      ; Incrementa o valor de R17 para o próximo endereço de memória
    CPI R16, R18 ; Compara o valor de R16 com o valor de R18 (condição de parada do loop)
    BRNE load_loop ; Pula de volta para load_loop se o valor de R16 for diferente de R18

; Subtrair 3 de cada endereço de memória a partir de $100
LDI R17, $100   ; Reinicializa o registrador R17 com o endereço de memória $100 (endereço inicial)
LDI R19, 3      ; Inicializa o registrador R19 com o valor 3 (valor a ser subtraído)

subtract_loop:
    LD R16, R17  ; Carrega o valor do endereço apontado por R17 para R16
    SUB R16, R19 ; Subtrai o valor de R19 do valor de R16
    ST R16, R17  ; Armazena o valor resultante na memória no mesmo endereço apontado por R17
    INC R17      ; Incrementa o valor de R17 para o próximo endereço de memória
    CPI R17, R18 ; Compara o valor de R17 com o valor de R18 (condição de parada do loop)
    BRNE subtract_loop ; Pula de volta para subtract_loop se o valor de R17 for diferente de R18

; Os valores de 10 a 20 foram carregados na memória a partir do endereço $100
; e subtraídos 3 em cada endereço