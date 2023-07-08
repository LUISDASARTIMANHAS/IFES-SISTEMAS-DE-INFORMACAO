; Atividade 8: Some 8 valores da memória e tire a média (dica, divisão por potência de 2 é só deslocar os bits para a direita)

; Somar 8 valores da memória consecutivamente e calcular a média
LDI R16, 8        ; Inicializa o registrador R16 com o valor 8 (contador do loop)
LDI R17, $100     ; Inicializa o registrador R17 com o endereço de memória inicial
LDI R18, 0        ; Inicializa o registrador R18 com zero (acumulador da soma)

loop:
    LD R19, R17   ; Carrega o valor do endereço apontado por R17 para R19
    ADD R18, R19  ; Adiciona o valor de R19 ao acumulador R18
    INC R17       ; Incrementa o valor de R17 para o próximo endereço de memória
    DEC R16       ; Decrementa o contador do loop
    BRNE loop     ; Pula de volta para o loop se o contador for diferente de zero

LSR R18, 3        ; Desloca os bits de R18 3 posições para a direita (divide por 8)

; O resultado da média está armazenado no registrador R18