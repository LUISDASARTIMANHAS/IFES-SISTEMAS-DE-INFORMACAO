/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package provasuplemento;

/**
 *
 * @author 2023122760328
 */
public class Creatina extends Suplemento {
//    • WheyA e WheyB são Whey. Creatina é um Suplemento;
//    Uma Creatina é um suplemento que possui quantidade de arginina, quantidade de glicina e;
//    quantidade de metionina. O efeito de uma Creatina é "Energia para células musculares";
//    O grau de pureza (obterPureza) de uma Creatina é dado por quantidade de arginina * 10 +;
//    quantidade de glicina * 5 + quantidade de metionina

    private int qtArginina;
    private int qtGlicina;
    private int qtMetionina;

    // codigo, fabricante, nome do produto, qt aginina,glicina,qtMetionina ;
// new Creatina("4", "Creatine Labs", "Creatine 100", 50, 20, 40);
    public Creatina(String codigo, String fabricante, String nomeProduto, int qtArginina, int qtGlicina, int qtMetionina) {
        super(codigo, nomeProduto, fabricante);
        this.qtArginina = qtArginina;
        this.qtGlicina = qtGlicina;
        this.qtMetionina = qtMetionina;
    }

    @Override
    public String obterEfeito() {
        return "Energia para células musculares";
    }
    
    public int obterPureza(){
//    (obterPureza) de uma Creatina é dado por quantidade de arginina * 10 +;;
//    quantidade de glicina * 5 + quantidade de metionina
        return qtArginina * 10 + qtGlicina * 5 + qtMetionina;
    }
}
