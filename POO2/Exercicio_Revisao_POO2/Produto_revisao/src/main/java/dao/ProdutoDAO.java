
package dao;

/**
 *
 * @author jean_
 */
public class ProdutoDAO {
          
    public void inserir(Produto prod){
        // Insere todos os dados do produto no banco de dados       
	// Observe que o parâmetro é um objeto do tipo Produto (prod), 
        // portanto você deverá ler de um Frame os dados, criar um objeto 
        // do tipo Produto e passar como parâmetro para essa função
        //
        // O ID do produto é auto numeração
	//
	// INSERT INTO nome_tabela (CAMPOS separados por virgula)  VALUES 
        //    ( VALORES separados por vírgula )
    }

    
    public void alterar (Produto prod){

	// Altera no banco os dados do produto
        // O código do produto deve ser um produto já inserido
        // Os demais campos são os novos dados
        // UPDATE nome_tabela SET campos = novos_valores
        //	WHERE campo_codigo = cod

    }

    public Produto pesquisar (int id ){

	// Pesquisa no banco pelo ID passado como parâmetro 
        //  e retorna um objeto do tipo Produto.
        //  Antes de retornar deve criar um objeto do tipo Produto.
        // SELECT * FROM nome_tabela WHERE campo_codigo = cod_pesquisa
    }    

    public List<Produto> listar(int limite){

	// Pesquisa no banco e retorna, através de um List, 
        // todos os produtos que estão com a quantidade abaixo
        // 	do limite
        // No seu Frame, chame essa função e preencha a tabela com o
        //	resultado do List
        // SELECT * FROM nome_tabela  WHERE qtde < limite
        // return lista;
    }

    public List<Produto> listar(){

	// Pesquisa no banco e retorna, através de um List,
        // todos os produtos
        // 	
        // No seu Frame, chame essa função e preencha a tabela com o
        //	resultado do List
        // SELECT * FROM nome_tabela 
        // return lista;
    }
    
    public List<Produto> listar(Categoria cat){

	// Pesquisa no banco e retorna, através de um List,
        // todos os produtos de uma determinada categoria
        // 	
        // No seu Frame, chame essa função e preencha a tabela com o
        //	resultado do List
        // SELECT * FROM nome_tabela WHERE idCategoria = id_parametro_pesq
        // return lista;
    }

    
}
