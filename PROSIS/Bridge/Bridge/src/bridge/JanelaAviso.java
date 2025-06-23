package bridge;

public class JanelaAviso extends JanelaAbstrata {
    public JanelaAviso(JanelaImplementada j) {
        super(j);
    }

    @Override
    public void desenhar() {
        desenharJanela("\n\nJanela de Aviso");
        desenharBotao("Ok");
    }
}
