package decorator;

public class Acucar extends CoquetelDecorator {

	public Acucar(Coquetel umCoquetel) {
		super(umCoquetel);
		nome = "Acucar";
		preco = 0.5;
	}

}