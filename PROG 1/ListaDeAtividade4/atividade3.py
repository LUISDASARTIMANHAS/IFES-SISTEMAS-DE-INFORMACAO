import presets

def main():
    cont = 1
    n = presets.validNum()
    while(cont <= n):
        presets.imprimirLinha(cont)
        cont = cont +1

main()
