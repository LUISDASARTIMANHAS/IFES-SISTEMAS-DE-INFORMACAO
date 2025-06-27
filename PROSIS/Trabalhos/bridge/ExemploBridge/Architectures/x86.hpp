// Architectures/x86.hpp
// Implementação concreta da interface HardwareArchitecture para arquitetura x86

#ifndef X86_HPP
#define X86_HPP

#include "../HardwareArchitecture.hpp"
#include <iostream>

class x86 : public HardwareArchitecture {
public:
    // Implementação do método executarInstrucao para a arquitetura x86
    // Exibe no console a instrução que está sendo executada
    void executarInstrucao(const std::string& instrucao) override {
        std::cout << "[x86] Executando: " << instrucao << std::endl;
    }
};

#endif
