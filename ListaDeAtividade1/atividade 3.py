# dias, horas, minutos e segundos
#Calcule o total em segundos.

dias = int(input("Insira o dia: "))
horas = int(input("Insira as horas: "))
minutos = int(input("Insira os minutos: "))
segunbdos = int(input("Insira os segundos: "))

diaSeg = dias*24*60*60
horaSeg = horas*60*60
minutosSeg = minutos*60

totalSeg = segunbdos+minutosSeg+horaSeg+diaSeg
print(totalSeg)
