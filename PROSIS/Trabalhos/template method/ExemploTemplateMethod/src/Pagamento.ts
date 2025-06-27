// File: Pagamento.ts
export abstract class Pagamento {
  constructor(protected valorBase: number) {}

  public processar(): void {
    const desconto = this.calcularDesconto();
    const total = this.valorBase - desconto;
    this.exibirResumo(total);
  }

  protected abstract calcularDesconto(): number;

  protected exibirResumo(total: number): void {
    const div = document.getElementById("resumo");
    if (div) {
      div.innerHTML = `Valor com desconto: <strong>R$ ${total.toFixed(2)}</strong>`;
    }
    console.log(`[RESUMO] Valor final: R$ ${total.toFixed(2)}`);
  }
}


