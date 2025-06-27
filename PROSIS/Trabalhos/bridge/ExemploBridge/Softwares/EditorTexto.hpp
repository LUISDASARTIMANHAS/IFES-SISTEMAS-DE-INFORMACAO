// Softwares/EditorTexto.hpp
#ifndef EDITORTEXTO_HPP
#define EDITORTEXTO_HPP

#include "../Software.hpp"
#include <iostream>

class EditorTexto : public Software {
public:
    // Construtor repassa a arquitetura para a classe base
    EditorTexto(HardwareArchitecture* arquitetura) : Software(arquitetura) {}

    // Implementação do método abstrato rodar()
    void rodar() override {
        std::cout << "Abrindo Editor de Texto..." << std::endl;

        // Delegação da execução para a implementação da arquitetura de hardware
        arquitetura->executarInstrucao("abrir_editor");
        arquitetura->executarInstrucao("escrever_texto");
    }
};

#endif
