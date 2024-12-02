
package provasuplemento;

public class ProvaSuplemento {

    public static void main(String[] args) {
        
        // Todo WheyA é criado com código, fabricante e nome do produto, nessa ordem
        // Todo WheyA possui 45.0 de proteína e 5.0 de carboidrato
        Suplemento whey1 = new WheyA("1", "Max Titanium", "100% Whey");
        WheyA whey2 = new WheyA("1", "Max", "100 Whey");
        // São iguais se os códigos forem iguais
        if(whey1.equals(whey2)){
            System.out.println("Apesar do fabricante e do nome do produto serem diferentes, "+
                    " são o mesmo Whey: ");
            System.out.println(whey1);
            System.out.println(whey2);
        }
        // Todo WheyB é criado com quantidade de carboidrato, código, fabricante e nome do 
        // produto, nessa ordem.
        // Todo WheyB possui 30.0 de proteína
        Whey whey3 = new WheyB(20.0, "2", "Supra Max Best Whey", "1000% Whey" );
        Suplemento whey4 = new WheyB(5.0, "3", "Simple Whey", "Good Whey" );
        System.out.println("**  Vamos ver os efeitos dos Whey:  **");
        System.out.println(whey1.obterEfeito());
        System.out.println(whey2.obterEfeito());
        System.out.println(whey3.obterEfeito());
        System.out.println(whey4.obterEfeito());
        System.out.println("******");
        
        Creatina creatina = new Creatina("4", "Creatine Labs", "Creatine 100", 50, 20, 40);
        System.out.println("O grau de pureza da creatina " + creatina.getNomeProduto() + 
                " é " + creatina.obterPureza());
        System.out.println("**  Vamos ver o efeito da creatina:  **");
        System.out.println(creatina.obterEfeito());
        System.out.println("******");
        
        System.out.println("Foram criados " + Suplemento.getQt() + " suplementos");
    }
}
