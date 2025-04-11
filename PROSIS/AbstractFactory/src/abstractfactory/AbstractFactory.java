package abstractfactory;
public class AbstractFactory {
	public static void main(String[] args) 
        {
                FabricaDeCarro fabrica;                
                CarroSedan sedan;
                CarroPopular popular;
                
                fabrica = new FabricaFiat();
                
                sedan       = fabrica.criarCarroSedan();
		sedan.exibirInfoSedan();                                 
                
                popular     = fabrica.criarCarroPopular();
                popular.exibirInfoPopular();
		
                fabrica = new FabricaFord();
                
                sedan       = fabrica.criarCarroSedan();
		sedan.exibirInfoSedan();  
                
                popular     = fabrica.criarCarroPopular();
                popular.exibirInfoPopular();
	}
}
