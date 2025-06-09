// processador.h
#ifndef PROCESSADOR_H
#define PROCESSADOR_H
ProcessadorImplementado* novoProcessadorA();
ProcessadorImplementado* novoProcessadorB();
#include <iostream>

class ProcessadorImplementado {
public:
    virtual void executarInstrucoes() = 0;  // método obrigatório
    virtual void diagnostico() {
        std::cout << "Executando diagnóstico padrão do processador.\n";
    }
    virtual ~ProcessadorImplementado() = default;
};


#endif