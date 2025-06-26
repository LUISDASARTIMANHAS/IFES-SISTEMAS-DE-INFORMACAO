// File: app.ts

import { PagamentoCredito } from "./PagamentoCredito.js";
import { PagamentoPIX } from "./PagamentoPIX.js";
import { PagamentoBoleto } from "./PagamentoBoleto.js";
import { Pagamento } from "./Pagamento.js";
import { mostrarMensagemNaTela } from "./util.js";

declare global {
  interface Window {
    finalizarCompra: (forma: string) => void;
    finalizarSelecionado: () => void;
  }
}

window.finalizarCompra = function (forma: string): void {
  const valor = 100;
  let pagamento: Pagamento;

  switch (forma) {
    case "credito":
      pagamento = new PagamentoCredito(valor);
      break;
    case "pix":
      pagamento = new PagamentoPIX(valor);
      break;
    case "boleto":
      pagamento = new PagamentoBoleto(valor);
      break;
    default:
      alert("Forma de pagamento inválida");
      return;
  }

  pagamento.processar();
};

window.finalizarSelecionado = function () {
  const select = document.getElementById("forma-pagamento") as HTMLSelectElement;
  if (!select) return;
  const forma = select.value;
  window.finalizarCompra(forma);
};
