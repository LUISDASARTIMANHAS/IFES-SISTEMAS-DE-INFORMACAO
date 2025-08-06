let modelo;

async function carregarModelo() {
  modelo = await mobilenet.load();
  console.log("✅ Modelo carregado.");
}

function exibirImagem(file) {
  const img = document.getElementById("imagemSelecionada");
  img.src = URL.createObjectURL(file);
  img.style.display = "block";
}

function classificarImagem() {
  const img = document.getElementById("imagemSelecionada");

  modelo.classify(img).then(predicoes => {
    const lista = document.getElementById("listaResultados");
    lista.innerHTML = "";

    predicoes.forEach(pred => {
      const item = document.createElement("li");
      item.textContent = `${pred.className} — ${(pred.probability * 100).toFixed(2)}%`;
      lista.appendChild(item);
    });
  });
}

document.getElementById("inputImagem").addEventListener("change", function(event) {
  const file = event.target.files[0];
  if (!file) return;

  exibirImagem(file);

  // Espera um pequeno tempo para garantir que a imagem carregou no DOM
  setTimeout(() => {
    classificarImagem();
  }, 500);
});

carregarModelo();
