;  Atividade 2: Ordenar dois números (Os números ordenados deverão ficar no registrador R20 e R21)
LDI R0 = 3
LDI R1 = 2
LDI R3 = R1
; Ordenar dois números em R10 e R11 e salvar em R20 e R21
CP R0, R1    ; Compara o conteúdo de R10 com o conteúdo de R11
BRSH skip_swap  ; Pula para o rótulo "skip_swap" se R10 for maior ou igual a R11

; Troca os valores de R10 e R11
MOV R16, R10   ; Salva temporariamente o valor de R10 em R16
MOV R10, R11   ; Copia o valor de R11 para R10
MOV R11, R16   ; Restaura o valor original de R10 (salvo em R16) para R11

skip_swap:
MOV R20, R10   ; Armazena o valor ordenado de R10 em R20
MOV R21, R11   ; Armazena o valor ordenado de R11 em R21

; Os números foram ordenados e estão nos registradores R20 e R21
