package factorymethod;

public class FabricaChevrolet implements FabricaDeCarro {

	@Override
	public Carro criarCarro() {
		return new Celta();
	}

}
