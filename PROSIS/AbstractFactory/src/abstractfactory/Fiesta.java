package abstractfactory;

public class Fiesta implements CarroPopular {

	@Override
	public void exibirInfoPopular() {
		System.out.println("Modelo: Fiesta\nFábrica: Ford\nCategoria:Popular\n\n");
	}

}
