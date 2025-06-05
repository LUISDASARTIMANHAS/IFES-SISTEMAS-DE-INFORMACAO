#include "processador.h"

class ProcessadorB : public ProcessadorImplementado {
public:
    void executarInstrucoes() override {
        std::cout << "Processador B executando instruções.\n";
    }
};