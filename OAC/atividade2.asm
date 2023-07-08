;  Atividade 2: Ordenar dois números (Os números ordenados deverão ficar no registrador R20 e R21)
LDI R0 = 3
LDI R1 = 2
LDI R3 = R1

loop: CP R0,R1
BRLO jmp ini_if
jmp fim

ini_if:
LDI R3 = R0


fim:
nop