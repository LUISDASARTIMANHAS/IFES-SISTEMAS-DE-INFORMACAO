LDI R16, 0        ; Inicializa o registrador R16 com zero (acumulador)
LDI R17, 0        ; Inicializa o registrador R17 com zero (contador)
LDI R18, 200      ; Carrega a constante 200 em R18 (limite da soma)

LDI R27, $FF      ; Carrega o valor máximo na parte alta do registrador R27
LDI R26, $10      ; Carrega o fimereço de memória em formato hexadecimal na parte baixa do registrador R26

verificar:
    LD R20, Z       ; Carrega o valor da memória apontada por Z em R20
    ADD R16, R20    ; Soma o valor de R20 ao acumulador em R16 (sem considerar carry)
    INC R17         ; Incrementa o contador em R17

    CP R16, R18     ; Compara o valor do acumulador com o limite em R18
    BRSH fim
    INC R26         ; Incrementa o fimereço de memória para apontar para o próximo número
    jmp verificar

fim:
    nop
    ; O valor final da soma estará em R16
