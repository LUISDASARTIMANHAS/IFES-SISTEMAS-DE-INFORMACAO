function buscaCEP(elem) {
  const cep = elem.value;
  if (cep.length == 8) {
    fetchViaCep(cep);
  } else {
    alert("CEP INVALIDO!");
  }
}

async function fetchViaCep(cep) {
  const url = `https://viacep.com.br/ws/${cep}/json`;
  const options = {
    method: "GET",
    mode: "cors",
    headers: {
      "content-type": "application/json;charset=utf-8",
    },
  };

  await fetch(url, options)
    .then((response) => {
      if (response.ok) {
        return response.json();
      } else {
        return response.text().then((errorText) => {
          throw new Error("Erro ao buscar CEP: " + errorText);
        });
      }
    })
    .then((data) => {
      if (data.erro) {
        throw new Error("Erro ao buscar CEP: CEP INVALIDO!");
      }
      console.log("DATA RESPONSE: ");
      console.log(data);
      renderData(data);
    })
    .catch((error) => onError(error));
}

function renderData(data) {
  const rua = document.getElementById("rua");
  const compl = document.getElementById("compl");
  const bairro = document.getElementById("bairro");
  const uf = document.getElementById("uf");
  const cid = document.getElementById("cid");

  rua.value = data.logradouro;
  compl.value = data.complemento;
  bairro.value = data.bairro;
  uf.value = data.uf;
  cid.value = data.localidade;
}

function onError(error) {
  alert(error);
  console.debug(error);
}

// {
//     "cep": "29707-377",
//     "logradouro": "Rua Marcelo Augusto da Silva Antolini",
//     "complemento": "",
//     "unidade": "",
//     "bairro": "Luiz Iglesias",
//     "localidade": "Colatina",
//     "uf": "ES",
//     "estado": "Espírito Santo",
//     "regiao": "Sudeste",
//     "ibge": "3201506",
//     "gia": "",
//     "ddd": "27",
//     "siafi": "5629"
// }
