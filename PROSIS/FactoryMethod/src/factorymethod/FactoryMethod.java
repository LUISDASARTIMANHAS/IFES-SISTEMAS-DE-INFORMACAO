package factorymethod;
public class FactoryMethod {
    public static void main(String[] args) {
		FabricaDeCarro fabrica = new FabricaFiat();
		Carro carro = fabrica.criarCarro();
		carro.exibirInfo();
		System.out.println();

		fabrica = new FabricaVolks();
		carro = fabrica.criarCarro();
		carro.exibirInfo();
		System.out.println();

		fabrica = new FabricaFord();
		carro = fabrica.criarCarro();
		carro.exibirInfo();
		System.out.println();

		fabrica = new FabricaChevrolet();
		carro = fabrica.criarCarro();
		carro.exibirInfo();    
    }
}
