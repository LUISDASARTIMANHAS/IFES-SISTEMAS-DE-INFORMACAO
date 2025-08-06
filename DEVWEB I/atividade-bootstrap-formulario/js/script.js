// Aqui você pode adicionar futura validação ou interações JS
console.log("Formulário carregado com sucesso.");


document.addEventListener("DOMContentLoaded", function () {
  const celular = document.getElementById("celular");
  const telefone = document.getElementById("telefone");
  const cep = document.getElementById("cep");

  function aplicarMascara(input, mascara) {
    input.addEventListener("input", () => {
      let i = input.value.replace(/\D/g, "");
      let m = mascara;
      let resultado = "";
      let j = 0;

      for (let k = 0; k < m.length && j < i.length; k++) {
        if (m[k] === "X") {
          resultado += i[j++];
        } else {
          resultado += m[k];
        }
      }

      input.value = resultado;
    });
  }

  aplicarMascara(celular, "(XX) 9XXXX-XXXX");
  aplicarMascara(telefone, "(XX) XXXX-XXXX");
  aplicarMascara(cep, "XXXXX-XXX");
});
