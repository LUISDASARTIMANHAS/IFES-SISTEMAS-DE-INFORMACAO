// Architectures/ARM.cpp
// Implementação concreta da interface HardwareArchitecture para arquitetura ARM

#ifndef ARM_HPP
#define ARM_HPP

#include "../HardwareArchitecture.hpp"
#include <iostream>

class ARM : public HardwareArchitecture {
public:
    // Implementa o método executarInstrucao específico para ARM
    // Exibe no console a instrução que está sendo executada
    void executarInstrucao(const std::string& instrucao) override {
        std::cout << "[ARM] Executando: " << instrucao << std::endl;
    }
};

#endif
