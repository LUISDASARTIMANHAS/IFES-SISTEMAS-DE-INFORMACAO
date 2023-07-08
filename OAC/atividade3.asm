; Atividade 3: Somar dois números, caso a soma dê mais de 30, subtrair 10, caso contrário, adicionar o valor atual da soma (isso equivale a multiplicar a soma atual por 2). Salvar o resultado no R20.

; Somar dois números em R10 e R11 e aplicar a lógica de subtração ou multiplicação por 2
ADC R20, R10    ; Adiciona o conteúdo de R10 ao conteúdo de R20, considerando o carry
ADD R20, R11    ; Adiciona o conteúdo de R11 ao conteúdo de R20, sem considerar o carry

CP R20, 30      ; Compara o conteúdo de R20 com o valor 30
BRCC multiply   ; Pula para o rótulo "multiply" se a soma for menor ou igual a 30

SUBI R20, 10    ; Subtrai 10 do conteúdo de R20 (caso a soma seja maior que 30)
JMP end         ; Pula para o rótulo "end"

multiply:
ADD R20, R20    ; Adiciona o conteúdo de R20 ao próprio conteúdo de R20 (multiplica por 2)

end:
; O resultado final está armazenado no registrador R20
