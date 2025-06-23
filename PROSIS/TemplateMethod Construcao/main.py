obras = [Casa(), Predio(), Galpao()]

for obra in obras:
    print(f"\nIniciando construção: {obra.__class__.__name__}")
    obra.construir()
