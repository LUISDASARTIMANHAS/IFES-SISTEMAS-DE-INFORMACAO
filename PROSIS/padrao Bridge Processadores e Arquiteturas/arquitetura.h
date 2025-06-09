// arquitetura.h
#ifndef ARQUITETURA_H
#define ARQUITETURA_H
ArquiteturaAbstrata* novaX86(ProcessadorImplementado* proc);
ArquiteturaAbstrata* novaARM(ProcessadorImplementado* proc);

#include "processador.h"

class ArquiteturaAbstrata {
protected:
    ProcessadorImplementado* processador;

public:
    ArquiteturaAbstrata(ProcessadorImplementado* proc) : processador(proc) {}
    virtual void rodarPrograma() = 0;
    virtual ~ArquiteturaAbstrata() {
        delete processador;
    }
};

#endif
