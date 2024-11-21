/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package larc_2016;

/**
 *
 * @author 2023122760328
 */
public class LARC_2016 {

    public static void main(String[] args) {
        /* Toda Equipe tem quantidade de membros atual e a quantidade máxima
 esses são os 2 últimos parâmetros dos construtores abaixo
 Equipes Soccer2D também tem o caminho da logo (primeiro parâmetro)
 Equipes SEK também tem a quantidade de robôs (primeiro parâmetro)
 Ex: equipe1 tem caminho c:/ e equipe2 tem 3 robos
         */
        Asimov2D equipe1 = new Asimov2D("c:/", 7, 10);
        AsimovSEK equipe2 = new AsimovSEK(3, 6, 6);
        ITADroids equipe3 = new ITADroids("c:/ita", 6, 8);
        Mexico equipe4 = new Mexico(1, 4, 5);

        System.out.println(equipe1.jogar(equipe3));
        System.out.println(equipe1.jogar(equipe3));
        System.out.println(equipe1.jogar(equipe3));
        System.out.println(equipe1.jogar(equipe3));

        System.out.println(equipe2.jogar(equipe4));
        System.out.println(equipe2.jogar(equipe4));
        System.out.println(equipe2.jogar(equipe4));
        System.out.println(equipe2.jogar(equipe4));
    }
}
