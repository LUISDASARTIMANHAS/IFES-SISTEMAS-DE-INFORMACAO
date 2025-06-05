#include "arquitetura.h"
#include <iostream>


class ArquiteturaX86 : public ArquiteturaAbstrata {
public:
    ArquiteturaX86(ProcessadorImplementado* proc) : ArquiteturaAbstrata(proc) {}

    void rodarPrograma() override {
        std::cout << "Arquitetura x86 iniciando...\n";
        processador->executarInstrucoes();
    }
};

class ArquiteturaARM : public ArquiteturaAbstrata {
public:
    ArquiteturaARM(ProcessadorImplementado* proc) : ArquiteturaAbstrata(proc) {}

    void rodarPrograma() override {
        std::cout << "Arquitetura ARM iniciando...\n";
        processador->executarInstrucoes();
    }
};

ArquiteturaAbstrata* novaX86(ProcessadorImplementado* proc) {
    return new ArquiteturaX86(proc);
}

ArquiteturaAbstrata* novaARM(ProcessadorImplementado* proc) {
    return new ArquiteturaARM(proc);
}
