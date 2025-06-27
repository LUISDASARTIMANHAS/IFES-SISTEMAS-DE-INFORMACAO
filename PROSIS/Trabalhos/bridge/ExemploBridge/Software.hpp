// Software.hpp
// A classe Software é a abstração do padrão Bridge
#ifndef SOFTWARE_HPP
#define SOFTWARE_HPP

#include "HardwareArchitecture.hpp"

class Software {
protected:
    HardwareArchitecture* arquitetura; // Ponteiro para a implementação (hardware)

public:
    // Construtor recebe a implementação concreta da arquitetura de hardware
    Software(HardwareArchitecture* arquitetura) : arquitetura(arquitetura) {}

    // Método abstrato que será implementado pelas subclasses (refinamentos da abstração)
    virtual void rodar() = 0;

    // Destrutor virtual para garantir destruição correta nas subclasses
    virtual ~Software() = default;
};

#endif
