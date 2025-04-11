
package dao;

import java.awt.List;

/**
 *
 * @author jean_
 */
public class CategoriaDAO {
          
    public void inserir(Categoria cat){
        // Insere todos os dados da categoria no banco de dados       
	// Observe que o parâmetro é um objeto do tipo Categoria, 
        // portanto você deverá ler de um Frame os dados, criar um objeto 
        // do tipo Categoria e passar como parâmetro para essa função
        //
        // O ID da categoria é auto numeração
	//
	// INSERT INTO nome_tabela (CAMPOS separados por virgula)  VALUES 
        //    ( VALORES separados por vírgula )
    }

    
    public List<Categoria> listar(){

	// Pesquisa no banco e retorna, através de um List,
        // todas as categorias
        // 	
        // No seu Frame, chame essa função e preencha o combobox com o
        //	resultado do List
        // SELECT * FROM nome_tabela 
        // return lista;
    }
    


    
}
