(() => {
  const timestamp = new Date();
  const diaDaSemana = timestamp.getDay();
  const hora = timestamp.getHours();

  console.log("Dia da Semana:", diaDaSemana);
  console.log("hora:", hora);

  function getData() {
    const url = "./src/data/horarios.json";
    const date = new Date();
    const id = Math.floor(Math.random() * 20242002);
    const options = {
      method: "GET",
      mode: "cors",
      headers: {
        "content-type": "application/json;charset=utf-8",
      },
    };

    fetch(url, options)
      .then((response) => {
        if (response.ok) {
          return response.json();
        } else {
          return response.text().then((errorText) => {
            throw new Error("Erro ao carregar tabela de horarios: " + errorText);
          });
        }
      })
      .then((data) => {
        console.log("DATA RESPONSE: ");
        console.log(data);
        criarTabela(data);
      })
      .catch((error) => onError(error));
  }
  getData();

  function criarTabela(database) {
    const tabela = document.querySelector("tbody");
    const loading = document.getElementById("loadingTable");
    const horarios = database.horarios;
    const semanas = database.semana;

    createTableTitulo(tabela, horarios);
    loading.hidden = true;

    for (let i = 0; i < semanas.length; i++) {
      const semana = semanas[i];
      const dia = semana.dia;
      const materias = semana.materias;

      console.log("[criarTabela] Criando Dia:", `${i+1} - ${dia}`);

      var trLine = document.createElement("tr");
      var tdElementDia = document.createElement("td");

      if (diaDaSemana == i+1) {
        tdElementDia.style.backgroundColor = "red";
      }
      tdElementDia.innerHTML = dia;

      trLine.appendChild(tdElementDia);
      createTDMateria(trLine, materias);

      tabela.appendChild(trLine);
    }

    function createTDMateria(trLine, materias) {
      for (let h = 0; h < materias.length; h++) {
        const materia = materias[h];
        var tdElementMateria = document.createElement("td");

        tdElementMateria.innerHTML = materia;
        trLine.appendChild(tdElementMateria);
      }
    }

    function createTableTitulo(tabela, database) {
      var trLine = document.createElement("tr");
      var thElementDefault = document.createElement("th");

      thElementDefault.innerHTML = "HORARIOS";
      trLine.appendChild(thElementDefault);

      for (let h = 0; h < database.length; h++) {
        const horario = database[h];
        var thElementHorario = document.createElement("th");

        thElementHorario.innerHTML = horario;
        trLine.appendChild(thElementHorario);
      }
      tabela.appendChild(trLine);
    }
  }

  function onError(error) {
    console.debug(error);
    alert(error);
  }
})();
