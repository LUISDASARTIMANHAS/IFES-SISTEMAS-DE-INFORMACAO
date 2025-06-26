// File: PagamentoBoleto.ts

import { Pagamento } from "./Pagamento.js";
import { mostrarMensagemNaTela } from "./util.js";

export class PagamentoBoleto extends Pagamento {
  protected calcularDesconto(): number {
    const desconto = this.valorBase * 0.05;
    mostrarMensagemNaTela("Pagamento com Boleto - desconto de 5% aplicado.");
    return desconto;
  }
}
