/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package adapterclass;

/**
 *
 * @author Giovany
 */
public class AdapterClass {
    public static void main(String[] args) {
	ImagemTarget imagem = new SDLImagemAdapter();
	imagem.carregarImagem("teste.png");
	imagem.desenharImagem(0, 0, 10, 10);

	imagem = new OpenGLImageAdapter();
	imagem.carregarImagem("teste.png");
	imagem.desenharImagem(0, 0, 10, 10);

    }
}
