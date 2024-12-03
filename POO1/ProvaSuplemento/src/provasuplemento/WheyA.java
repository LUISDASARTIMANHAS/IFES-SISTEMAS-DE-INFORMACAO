/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package provasuplemento;

/**
 *
 * @author 2023122760328
 */
public class WheyA extends Whey {
//    WheyA e WheyB são Whey. Creatina é um Suplemento;;
//    • Um WheyA possui quantidade de proteína fixa em 45 e quantidade de carboidrato fixo em 5. O
//    efeito (obterEfeito) de um WheyA é "Força e musculatura";

    
    // Todo WheyA é criado com código, fabricante e nome do produto, nessa ordem
    // Todo WheyA possui 45.0 de proteína e 5.0 de carboidrato
    public WheyA(String codigo, String nomeProduto, String fabricante) {
        super(45, 5, codigo, nomeProduto, fabricante);
    }

//    Whey é um Suplemento e todo Whey possui quantidade de proteína e quantidade de carboidrato.
//    Um Whey forte possui (quantidade de proteína / quantidade de carboidrato) > 5;
    @Override
    public String obterEfeito() {
            return "Força e musculatura";
    }

}
