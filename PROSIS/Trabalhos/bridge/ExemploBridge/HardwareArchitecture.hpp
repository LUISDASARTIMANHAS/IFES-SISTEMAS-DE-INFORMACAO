// HardwareArchitecture.hpp
// Interface da implementação (Implementador no padrão Bridge)
#ifndef HARDWAREARCHITECTURE_HPP
#define HARDWAREARCHITECTURE_HPP

#include <string>

class HardwareArchitecture {
public:
    // Método abstrato que deve ser implementado pelas arquiteturas concretas
    // Recebe uma instrução na forma de string e executa a operação correspondente
    virtual void executarInstrucao(const std::string& instrucao) = 0;

    // Destrutor virtual para garantir destruição correta das subclasses
    virtual ~HardwareArchitecture() = default;
};

#endif
