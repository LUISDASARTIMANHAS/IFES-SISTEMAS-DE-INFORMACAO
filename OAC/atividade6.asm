; Atividade 6: Carregue valores na memória, começando do endereço $100 os valores de 1 a 10. Utilize o comando de repetição para isso.

; Carregar valores de 1 a 10 na memória, a partir do endereço $100
LDI R16, 1      ; Inicializa o registrador R16 com o valor 1 (valor inicial)
LDI R17, $100   ; Inicializa o registrador R17 com o endereço de memória $100 (endereço inicial)

loop:
    ST R16, R17 ; Armazena o valor de R16 na memória no endereço apontado por R17
    INC R16     ; Incrementa o valor de R16 para o próximo número
    INC R17     ; Incrementa o valor de R17 para o próximo endereço de memória
    CPI R16, 11 ; Compara o valor de R16 com o valor 11 (condição de parada do loop)
    BRNE loop   ; Pula de volta para o loop se o valor de R16 for diferente de 11

; Os valores de 1 a 10 estão armazenados na memória, a partir do endereço $100