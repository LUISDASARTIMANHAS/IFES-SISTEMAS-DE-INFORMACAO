; Multiplicar um número por 5 usando um loop de repetição
LDI R16, 5      ; Carrega o valor 5 para o registrador R16 (contador do loop)
LDI R17, 0      ; Inicializa o registrador R17 com zero (acumulador da multiplicação)
LDI R18, 10     ; Carrega o valor do número original para o registrador R18 (substitua 10 pelo número desejado)

multiply_loop:
    ADD R17, R18 ; Adiciona o número original ao acumulador
    DEC R16      ; Decrementa o contador do loop
    BRNE multiply_loop ; Pula de volta para multiply_loop se o contador for diferente de zero

MOV R20, R17    ; Move o resultado final para o registrador R20

; O resultado da multiplicação está no registrador R20
