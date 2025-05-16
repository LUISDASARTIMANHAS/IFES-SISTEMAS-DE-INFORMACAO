package decorator;

public class Decorator {
    public static void main(String[] args) {
        Coquetel meuCoquetel = new Rum();
        System.out.println(meuCoquetel.getNome() + " = " + meuCoquetel.getPreco());

        System.out.println(meuCoquetel instanceof Rum);

        meuCoquetel = new Refrigerante(meuCoquetel);
        System.out.println(meuCoquetel.getNome() + " = "
                + meuCoquetel.getPreco());

        meuCoquetel = new Suco(meuCoquetel);
        System.out.println(meuCoquetel.getNome() + " = "
                + meuCoquetel.getPreco());

        meuCoquetel = new Acucar(meuCoquetel);
        System.out.println(meuCoquetel.getNome() + " = "
                + meuCoquetel.getPreco());

        meuCoquetel = new Acucar(meuCoquetel);
        System.out.println(meuCoquetel.getNome() + " = "
                + meuCoquetel.getPreco());

        // Problema? Pode ser
        System.out.println(meuCoquetel instanceof Rum);
    }
}
