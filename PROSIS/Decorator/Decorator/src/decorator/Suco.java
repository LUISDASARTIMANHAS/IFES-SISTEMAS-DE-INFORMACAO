package decorator;

public class Suco extends CoquetelDecorator {

	public Suco(Coquetel umCoquetel) {
		super(umCoquetel);
		nome = "Suco";
		preco = 0.8;
	}

}

