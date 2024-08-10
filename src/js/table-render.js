(() => {
  function getData() {
    const url = "https://pingobras-sg.glitch.me/api/ifes/horarios";
    const date = new Date();
    const id = Math.floor(Math.random() * 20242002);
    const options = {
      method: "GET",
      mode: "cors",
      headers: {
        "content-type": "application/json;charset=utf-8",
        Authorization: "API KEY IFES",
        key: date.getUTCHours() * date.getFullYear() * id,
        id: id,
      },
    };

    fetch(url, options)
      .then((response) => {
        if (response.ok) {
          return response.json();
        } else {
          return response.text().then((errorText) => {
            throw new Error("Erro ao fazer login: " + errorText);
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
    
    createTableTitulo(tabela, database[0].horarios);
    loading.hidden = true;

    for (let i = 0; i < database.length; i++) {
      const data = database[i];
      const dia = data.dia;
      const horarios = data.horarios;

      var trLine = document.createElement("tr");
      var tdElementDia = document.createElement("td");

      tdElementDia.innerHTML = dia;

      trLine.appendChild(tdElementDia);
      createTDMateria(trLine, horarios);

      tabela.appendChild(trLine);
    }

    function createTDMateria(trLine, database) {
      for (let h = 0; h < database.length; h++) {
        const materia = database[h];
        var tdElementMateria = document.createElement("td");

        tdElementMateria.innerHTML = materia.materia;
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

        thElementHorario.innerHTML = horario.horario;
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
