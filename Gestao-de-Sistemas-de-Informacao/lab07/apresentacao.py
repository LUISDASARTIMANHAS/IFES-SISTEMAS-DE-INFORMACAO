def exibir_dashboard(base):
    print("\n" + "="*75)
    print(f"{'DASHBOARD DE POPULARIDADE':^75}")
    print("="*75)
    print(f"{'ID':<4} | {'TÍTULO':<35} | {'POPULARIDADE'}")
    print("-"*75)

    for item in base:
        barra = "█" * (item['acessos'] // 10)
        print(f"{item['id']:<4} | {item['titulo']:<35} | {barra} ({item['acessos']})")

    print("="*75)