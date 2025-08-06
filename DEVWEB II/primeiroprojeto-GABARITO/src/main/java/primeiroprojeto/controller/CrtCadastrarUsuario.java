package primeiroprojeto.controller;

import java.io.IOException;
import primeiroprojeto.model.application.AplCadastrarUsuario;

/**
 * Servlet implementation class CrtCadastrarUsuario
 */
public class CrtCadastrarUsuario extends jakarta.servlet.http.HttpServlet {
	private static final long serialVersionUID = 1L;

    /**
     * Default constructor. 
     */
    public CrtCadastrarUsuario() {
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(jakarta.servlet.http.HttpServletRequest request, jakarta.servlet.http.HttpServletResponse response) throws jakarta.servlet.ServletException, IOException {
		
		 
		String nome = request.getParameter("txt_nome");
		
		System.out.println("wwwwwwwwwwwwwwwww");
		
		if (AplCadastrarUsuario.incluirUsuario(nome) == 0) {
			
			response.sendRedirect("mensagem.jsp?msg='Usuário incluído com sucesso!!!'");
			
		}else {
			
			response.sendRedirect("mensagem.jsp?msg='ERRO ao incluir usuário.'");
			
		}
		
				
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(jakarta.servlet.http.HttpServletRequest request, jakarta.servlet.http.HttpServletResponse response) throws jakarta.servlet.ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
