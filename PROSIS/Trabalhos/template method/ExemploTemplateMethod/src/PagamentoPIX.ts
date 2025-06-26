// PagamentoPIX.ts

import { Pagamento } from "./Pagamento.js";
import { mostrarMensagemNaTela } from "./util.js";

export class PagamentoPIX extends Pagamento {
  protected calcularDesconto(): number {
    const desconto = this.valorBase * 0.10;
    mostrarMensagemNaTela("Pagamento com PIX - desconto de 10% aplicado.");
    return desconto;
  }
}
