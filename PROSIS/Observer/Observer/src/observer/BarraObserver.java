package observer;

public class BarraObserver extends DadosObserver {
    public BarraObserver(DadosSubject dados) {
        super(dados);
    }
    @Override
    public void update() {
        String barraA = "", barraB = "", barraC = "";
        for (int i = 0; i < dados.getState().valorA; i++) {
            barraA += '=';
        }
        for (int i = 0; i < dados.getState().valorB; i++) {
            barraB += '=';
        }
        for (int i = 0; i < dados.getState().valorC; i++) {
            barraC += '=';
        }
        System.out.println("Barras:\nValor A: " + barraA + "\nValor B: " + barraB + "\nValor C: " + barraC + "\n\n");
    }
}
