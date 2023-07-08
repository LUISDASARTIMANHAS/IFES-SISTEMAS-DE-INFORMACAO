; Atividade 10: Carregue 10 valores , começando em $100 e ordene estes valores de forma crescente

; Carregar 10 valores na memória a partir do endereço $100 e ordená-los em ordem crescente
LDI R16, $100    ; Inicializa o registrador R16 com o endereço de memória $100 (endereço inicial)
LDI R17, 10      ; Inicializa o registrador R17 com o valor 10 (número de elementos)
LDI R18, 1       ; Inicializa o registrador R18 com o valor 1 (flag de troca)

outer_loop:
    MOV R16, R19  ; Reinicializa o registrador R16 para o endereço inicial
    MOV R18, R20  ; Reinicializa o registrador R18 para a flag de troca

    inner_loop:
        LD R20, R16  ; Carrega o primeiro valor para R20
        LD R21, R16+1  ; Carrega o próximo valor para R21
        CP R20, R21  ; Compara os valores de R20 e R21
        BRSH skip_swap  ; Pula para skip_swap se R20 for maior ou igual a R21

        ST R20, R16+1  ; Armazena o valor de R20 no próximo endereço
        ST R21, R16  ; Armazena o valor de R21 no endereço atual
        MOV R18, 1  ; Define a flag de troca como 1

    skip_swap:
        INC R16  ; Incrementa o endereço para o próximo par de valores
        DEC R17  ; Decrementa o contador do loop interno
        CPI R17, 1  ; Compara o contador com 1
        BRNE inner_loop  ; Pula de volta para inner_loop se o contador for diferente de 1

    DEC R17  ; Decrementa o contador do loop externo
    CPI R17, 1  ; Compara o contador com 1
    BRNE outer_loop  ; Pula de volta para outer_loop se o contador for diferente de 1

; Os valores foram carregados na memória a partir do endereço $100 e estão ordenados em ordem crescente