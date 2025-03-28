const inputs = document.querySelectorAll("input");
const box = document.getElementById("box");

inputs.forEach((input) => {
  input.addEventListener("input", () => {
    alterarUnidade(input.value);
  });
});

function alterarUnidade(value) {
  if (value == "vh") {
    box.style.height = `100${value}`;
    box.style.height = `Unidade Atual: ${box.style.height}`;
  } else if (value == "ex") {
    box.style.fontSize = `7${value}`;
    box.textContent = `Unidade Atual: ${box.style.fontSize}`;
    box.style.width = "95%";
  } else {
    box.style.width = "100" + value;
    box.textContent = `Unidade Atual: ${box.style.width}`;
    box.style.height = "100px";
    box.style.fontSize = `16px`;
  }
}



// ============== 
const listaSelecao = document.querySelectorAll("input");

listaSelecao.forEach(function (item) {
  item.addEventListener("click",()=>{
    esconderCartaoPokedev();
    const idPokedevSelecionado = mostrarCartaoPokedevSelecionado(pokedev);
    desativarPokedevSelecionadoNaListagem();
    ativarPokedevSelecionadoNaListagem(idPokedevSelecionado);
  });
})

function ativarPokedevSelecionadoNaListagem(idPokedevSelecionado) {
  const pokedevSelecionadoNaListagem = document.getElementById(idPokedevSelecionado);
  pokedevSelecionadoNaListagem.classList.add("ativo");
}

function desativarPokedevSelecionadoNaListagem() {
  const pokedevAtivoNaListagem = document.querySelector(".ativo");
  pokedevAtivoNaListagem.classList.remove("ativo");
}

function mostrarCartaoPokedevSelecionado(pokedev) {
  const idPokedevSelecionado = pokedev.attributes.id.value;
  const idDoCartaoPokedevParaAbrir = `cartao-${idPokedevSelecionado}`;
  const cartaoPokedevParaAbrir = document.getElementById(idDoCartaoPokedevParaAbrir);
  cartaoPokedevParaAbrir.classList.add("aberto");
  return idPokedevSelecionado;
}

function esconderCartaoPokedev() {
  const cartaoPokedevAberto = document.querySelector(".aberto");
  cartaoPokedevAberto.classList.remove("aberto");
}