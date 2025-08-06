const corhexa = document.getElementById("corhexa");


changeBackgroundColor("#333333");

function saudacao() {
  var nome = document.getElementById("nomecompleto");
  alert("Seja bem vindo: " + nome.value);
}

function mudaCor(elem) {
  corhexa.innerHTML = elem.value;
  changeBackgroundColor(elem.value);
}

function mudaIdade(elem) {
	const idadeValue = document.getElementById("idadeValue");
  idadeValue.textContent = elem.value;
}

function contarTexto(elem){
	const maxTexto = document.getElementById("maxTexto");
	var tam = elem.value.length;
	maxTexto.textContent = tam + "/100"
}

function mostrarSenha(button){
	const passInp = document.getElementById("password");
	if (passInp.type == "password") {
		passInp.type = "text"
		button.value = "Ocultar Senha"
	} else {
		passInp.type = "password"
		button.value = "Mostrar Senha"
	}
}

function changeBackgroundColor(color) {
	const body = document.body;
  body.style.background = color;
	corhexa.textContent = color;
}
