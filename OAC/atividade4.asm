; Somar dois números em R10 e R11 e aplicar a lógica de subtração ou multiplicação por 2
ADD R20, R10    ; Adiciona o conteúdo de R10 ao conteúdo de R20
ADC R20, R11    ; Adiciona o conteúdo de R11 ao conteúdo de R20, considerando o carry

CP R20, 30      ; Compara o conteúdo de R20 com o valor 30
BRSH multiply   ; Pula para o rótulo "multiply" se a soma for maior que 30

SUBI R20, 10    ; Subtrai 10 do conteúdo de R20 (caso a soma seja menor ou igual a 30)
JMP end         ; Pula para o rótulo "end"

multiply:
MOV R16, R20    ; Copia o valor de R20 para R16
ADD R20, R16    ; Adiciona o conteúdo de R16 ao conteúdo de R20 (multiplica por 2)

end:
; O resultado final está armazenado no registrador R20
