/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package criando_excecoes;

public class ParException extends NumeroException {

    public ParException(int num) {
        super(num);
    }
    
    @Override
    public String getMessage() {
        return "O número "+ num +" é par e deveria ser Impar";
    }
}
