// Softwares/NavegadorWeb.hpp
#ifndef NAVEGADORWEB_HPP
#define NAVEGADORWEB_HPP

#include "../Software.hpp"
#include <iostream>

class NavegadorWeb : public Software {
public:
    // Construtor que recebe a implementação da arquitetura de hardware e passa para a classe base Software
    NavegadorWeb(HardwareArchitecture* arquitetura) : Software(arquitetura) {}

    // Implementação do método abstrato 'rodar' da classe Software
    void rodar() override {
        // Mensagem indicando que o navegador web está sendo aberto
        std::cout << "Abrindo Navegador Web..." << std::endl;

        // Delegação das ações à arquitetura de hardware, executando instruções específicas
        arquitetura->executarInstrucao("carregar_pagina");  // Carrega a página web
        arquitetura->executarInstrucao("renderizar_html");  // Renderiza o conteúdo HTML da página
    }
};

#endif
