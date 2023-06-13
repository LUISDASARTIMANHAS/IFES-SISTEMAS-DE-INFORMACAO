import presets

def main():
    n = presets.validNum()
    
    cont = 1
    while(cont <= n):
        seq = False
        while(seq == False):
            seq = presets.sequencia(cont)
        
        cont = cont + 1

main()
