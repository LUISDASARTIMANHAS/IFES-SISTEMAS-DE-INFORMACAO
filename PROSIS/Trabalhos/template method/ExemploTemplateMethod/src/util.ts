// util.ts

export function mostrarMensagemNaTela(texto: string): void {
  const resumo = document.getElementById("resumo");
  if (resumo) {
    const p = document.createElement("p");
    p.innerText = texto;
    resumo.appendChild(p);
  }
  console.log(`[INFO] ${texto}`);
}
