// Architectures/Microcontrolador.cpp
// Implementação concreta da interface HardwareArchitecture para microcontroladores

#ifndef MICRO_HPP
#define MICRO_HPP

#include "../HardwareArchitecture.hpp"
#include <iostream>

class Microcontrolador : public HardwareArchitecture {
public:
    // Implementa o método executarInstrucao específico para microcontroladores
    // Exibe no console a instrução que está sendo executada
    void executarInstrucao(const std::string& instrucao) override {
        std::cout << "[MICRO] Executando: " << instrucao << std::endl;
    }
};

#endif
