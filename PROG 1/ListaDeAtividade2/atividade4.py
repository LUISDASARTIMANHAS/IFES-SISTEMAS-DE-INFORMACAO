hora = int(input("Insira As Horas.(14): "))

if(0 <= hora):
    msm = "VAI DORMIR... "
elif(hora < 5):
    msm="VAI DORMIR..."

elif(hora < 12):
    msm = "BOM DIA"

elif(hora < 18):
    msm = "BOA TARDE"

elif(hora < 24):
    msm = "BOA NOITE"

else:
    msm = "HORA INVÁLIDA"

print(msm)