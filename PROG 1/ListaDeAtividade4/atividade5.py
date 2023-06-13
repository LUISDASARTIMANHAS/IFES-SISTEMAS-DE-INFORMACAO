# Faça um programa, usando funções, para imprimir:
import presets

def main():
    presets.head()
    n = presets.validNum()
    m = presets.validNum()
    o = m-n
    nFat= presets.fatorial(n)
    mFat = presets.fatorial(m)
    oFat = presets.fatorial(o)
    calc = mFat/(oFat*nFat)
    presets.data("Fatorial de N","Fatorial de M","Fatorial de O","Total",nFat,mFat,oFat,calc )
    presets.copy()

main()