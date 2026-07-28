let data = carregarHorario();

const lista = document.getElementById("listaDias");

render();

/**
 * Renderiza os dias.
 */
function render() {

    lista.innerHTML = "";

    data.semana.forEach((dia, index) => {

        const row = document.createElement("div");

        row.className = "input-group mb-2";

        row.innerHTML = `
            <span class="input-group-text">
                ${index + 1}
            </span>

            <input
                class="form-control"
                value="${dia.dia}">

            <button
                class="btn btn-danger">

                Remover

            </button>
        `;

        const input = row.querySelector("input");

        input.addEventListener("input", () => {

            data.semana[index].dia = input.value;

        });

        row.querySelector("button").addEventListener("click", () => {

            removerDia(index);

        });

        lista.appendChild(row);

    });

}

/**
 * Novo dia.
 */
document
.getElementById("btnNovoDia")
.addEventListener("click", () => {

    data.semana.push({

        dia: "Novo Dia",

        materias: criarMaterias()

    });

    render();

});

/**
 * Remove um dia.
 */
function removerDia(index) {

    if (!confirm("Deseja remover este dia?")) {

        return;

    }

    data.semana.splice(index, 1);

    render();

}

/**
 * Salvar.
 */
document
.getElementById("btnSalvar")
.addEventListener("click", () => {

    salvarHorario(data);

    alert("Dias salvos.");

});