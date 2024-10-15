/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package criando_excecoes;

public class NumeroBicomposto {

    int par, impar;

    private void setPar(int numero) throws
            ImparException {
        if ((numero % 2) != 0) {
            throw new ImparException(numero);
        }
        this.par = numero;
    }

    private void setImpar(int numero) throws
            ParException {
        if ((numero % 2) == 0) {
            throw new ParException(numero);
        }
        this.impar = numero;
    }

    NumeroBicomposto(int par, int impar) throws
            ParException, ImparException {
        this.setPar(par);
        this.setImpar(impar);
    }
}
