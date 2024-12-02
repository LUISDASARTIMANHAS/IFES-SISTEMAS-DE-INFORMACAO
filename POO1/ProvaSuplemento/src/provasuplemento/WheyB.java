/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package provasuplemento;

/**
 *
 * @author 2023122760328
 */
public class WheyB extends Whey{
//    WheyA e WheyB são Whey. Creatina é um Suplemento;;
//    Um WheyB possui quantidade de proteína fixa em 30. Se um WheyB for forte ele tem o efeito
//    (obterEfeito) "Força e musculatura quase tão boa quanto WheyA" se não for forte "Um pouco de
//    força e musculatura, mas nem tanto assim";

    
    // Todo WheyB é criado com quantidade de carboidrato, código, fabricante e nome do 
    // produto, nessa ordem.
    // Todo WheyB possui 30.0 de proteína
    public WheyB(double qtCarboidrato, String codigo, String nomeProduto, String fabricante) {
        super(30, qtCarboidrato, codigo, nomeProduto, fabricante);
    }

    @Override
    public String obterEfeito() {
//        Um Whey forte possui (quantidade de proteína / quantidade de carboidrato) > 5;

//        Se um WheyB for forte ele tem o efeito
//        (obterEfeito) "Força e musculatura quase tão boa quanto WheyA" 
//        se não for forte "Um pouco de força e musculatura, mas nem tanto assim";
        if((this.qtProteina / this.qtCarboidrato) > 5){
            return "Força e musculatura quase tão boa quanto WheyA";
        }else{
            return "Um pouco de força e musculatura, mas nem tanto assim";
        }
    }
    
    
}
