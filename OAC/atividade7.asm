; Atividade 7: Some os valores de $100 a $10A e coloque em R20. Lembre-se trabalhe com valores pequenos para evitar overflow. Inicie com alguns valores os endereços indicados antes de executar o código.

; Somar os valores de $100 a $10A e colocar o resultado em R20
LDI R20, 0       ; Inicializa o registrador R20 com zero (acumulador da soma)
LDI R16, $100    ; Inicializa o registrador R16 com o endereço de memória $100 (endereço inicial)
LDI R17, $10B    ; Inicializa o registrador R17 com o endereço de memória $10B (endereço final + 1)

loop:
    LD R18, R16  ; Carrega o valor do endereço apontado por R16 para R18
    ADD R20, R18 ; Adiciona o valor de R18 ao acumulador R20
    INC R16      ; Incrementa o valor de R16 para o próximo endereço de memória
    CPI R16, R17 ; Compara o valor de R16 com o valor de R17 (condição de parada do loop)
    BRNE loop    ; Pula de volta para o loop se o valor de R16 for diferente de R17

; O resultado da soma está armazenado no registrador R20