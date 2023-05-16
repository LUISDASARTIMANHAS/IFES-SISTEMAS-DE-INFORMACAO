#Faça um programa que peça a hora atual e mostre uma mensagemna tela deacordocomos intervalos abaixo:
hora = int(input("Insira As Horas.(14): "))

#0 <= Hora < 5  “VAI DORMIR...” 
if(0 <= hora):
    msm = "VAI DORMIR... "
elif(hora < 5):
    msm="VAI DORMIR..."

# 5 <= Hora < 12  “BOM DIA” 
elif(hora < 12):
    msm = "BOM DIA"

# 12 <= Hora < 18  “BOA TARDE” 
elif(hora < 18):
    msm = "BOA TARDE"

# 18 <= Hora < 24  “BOA NOITE” 
elif(hora < 24):
    msm = "BOA NOITE"

# Outro valor  “HORA INVÁLIDA”
else:
    msm = "HORA INVÁLIDA"

print(msm)