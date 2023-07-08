; Somar 5 com 5 e salvar o resultado em um registrador diferente
LDI R16, 5    ; Carrega o valor 5 para o registrador R16
LDI R17, 6    ; Carrega o valor 6 para o registrador R17
ADD R18, R16  ; Adiciona o valor de R16 ao registrador R18
ADD R18, R17  ; Adiciona o valor de R17 ao registrador R18

; O resultado da soma está no registrador R18
