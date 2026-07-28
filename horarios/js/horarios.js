let data = carregarHorario();

const lista = document.getElementById("listaHorarios");

render();

/**
 * Renderiza todos os horários.
 */
function render() {

    lista.innerHTML = "";

    data.horarios.forEach((horario, index) => {

        const row = document.createElement("div");

        row.className = "input-group mb-2";

        row.innerHTML = `
            <span class="input-group-text">
                ${index + 1}°
            </span>

            <input
                type="text"
                class="form-control"
                value="${horario}">

            <button
                class="btn btn-danger">

                Remover

            </button>
        `;

        const input = row.querySelector("input");

        input.addEventListener("input", () => {

            data.horarios[index] = input.value;

        });

        row.querySelector("button").addEventListener("click", () => {

            removerHorario(index);

        });

        lista.appendChild(row);

    });

}

/**
 * Adiciona horário.
 */
document
.getElementById("btnNovoHorario")
.addEventListener("click", () => {

    data.horarios.push("Novo Horário");

    data.semana.forEach(dia => {

        dia.materias.push("-");

    });

    render();

});

/**
 * Remove horário.
 */
function removerHorario(index) {

    if (!confirm("Deseja remover este horário?")) {

        return;

    }

    data.horarios.splice(index, 1);

    data.semana.forEach(dia => {

        dia.materias.splice(index, 1);

    });

    render();

}

/**
 * Salva.
 */
document
.getElementById("btnSalvar")
.addEventListener("click", () => {

    salvarHorario(data);

    alert("Horários salvos com sucesso.");

});