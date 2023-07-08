# Atividade 4: Ordenar três números em ordem crescente, Salvar ordenado nos registradores R20, R21 e R22.
x=3
y=7
z=1
R22=y
R21=z
R20=x


if(R20>R21):
    R20=x
if(R21>R22):
    R22 = z
if(R20>R21):
    R20 = x

print(R21)
print(R20)
print(R22)

