// main.cpp
#include <iostream>

// Inclusão das implementações concretas de hardware
#include "Architectures/Microcontrolador.hpp"
#include "Architectures/ARM.hpp"
#include "Architectures/x86.hpp"

// Inclusão dos softwares que representam as abstrações refinadas
#include "Softwares/EditorTexto.hpp"
#include "Softwares/NavegadorWeb.hpp"
#include "Softwares/ControleEmbarcado.hpp"

int main() {
    // Criação de implementações concretas da arquitetura de hardware
    HardwareArchitecture* arm = new ARM();
    HardwareArchitecture* x86arch = new x86();
    HardwareArchitecture* micro = new Microcontrolador();

    // Criação das abstrações associadas às arquiteturas (software + hardware)
    // Software* editorARM = new EditorTexto(arm);
    Software* navegador = new NavegadorWeb(x86arch);
    // Software* contoleDePortaEletronica = new ControleEmbarcado(micro);

    // Executa o software associado à arquitetura (descomente para usar)
    // editorARM->rodar();
    // std::cout << "-----------------------------" << std::endl;
    navegador->rodar();
    // std::cout << "-----------------------------" << std::endl;
    // contoleDePortaEletronica->rodar();

    // Libera memória dos objetos criados
    // delete editorARM;
    delete navegador;
    // delete contoleDePortaEletronica;
    delete arm;
    delete x86arch;
    delete micro;

    return 0;
}
