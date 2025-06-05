#include "processador.h"
#include <iostream>

class ProcessadorA : public ProcessadorImplementado {
public:
    void executarInstrucoes() override {
        std::cout << "Processador A executando instruções.\n";
    }
};
