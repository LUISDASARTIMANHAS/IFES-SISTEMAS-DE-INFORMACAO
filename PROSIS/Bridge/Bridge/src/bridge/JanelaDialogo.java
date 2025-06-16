package bridge;

public class JanelaDialogo extends JanelaAbstrata {

    public JanelaDialogo(JanelaImplementada j) {
        super(j);
    }

    @Override
    public void desenhar() {
        desenharJanela("\n\nJanela de Diálogo");
        desenharBotao("Botão Sim");
        desenharBotao("Botão Não");
        desenharBotao("Botão Cancelar");
    }

}
