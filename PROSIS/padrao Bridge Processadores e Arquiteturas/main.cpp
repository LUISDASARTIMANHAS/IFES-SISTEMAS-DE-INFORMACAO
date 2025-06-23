#include "arquitetura.h"
#include "processador.h"
#include <iostream>

extern ArquiteturaAbstrata* novaX86(ProcessadorImplementado*);
extern ArquiteturaAbstrata* novaARM(ProcessadorImplementado*);
extern ProcessadorImplementado* novoProcessadorA();
extern ProcessadorImplementado* novoProcessadorB();

int main() {
    ArquiteturaAbstrata* sistema1 = novaX86(novoProcessadorA());
    sistema1->rodarPrograma();
    delete sistema1;

    std::cout << "\n";

    ArquiteturaAbstrata* sistema2 = novaARM(novoProcessadorB());
    sistema2->rodarPrograma();
    delete sistema2;

    return 0;
}
