// Softwares/ControleEmbarcado.hpp
#ifndef CONTROLEEMBARCADO_HPP
#define CONTROLEEMBARCADO_HPP

#include "../Software.hpp"
#include <iostream>

class ControleEmbarcado : public Software {
public:
    // Construtor que recebe a arquitetura de hardware e passa para a classe base Software
    ControleEmbarcado(HardwareArchitecture* arquitetura) : Software(arquitetura) {}

    // Implementação do método abstrato 'rodar'
    void rodar() override {
        // Indica que o firmware está iniciando
        std::cout << "Iniciando Firmware..." << std::endl;

        // Delegação para a arquitetura de hardware para executar instruções relacionadas a I/O
        arquitetura->executarInstrucao("Enviando Comandos I/O");   // Envia comandos de entrada/saída
        arquitetura->executarInstrucao("Recebendo comandos I/O");  // Recebe comandos de entrada/saída
    }
};

#endif
