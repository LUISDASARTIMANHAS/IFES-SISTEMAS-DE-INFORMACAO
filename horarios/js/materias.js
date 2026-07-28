let materias = carregarMaterias();

const lista = document.getElementById("listaMaterias");

render();

/**
 * Renderiza lista.
 */
function render() {

    lista.innerHTML = "";

    materias.forEach((materia, index) => {

        const row = document.createElement("div");

        row.className = "input-group mb-2";

        row.innerHTML = `
            <span class="input-group-text">
                ${index + 1}
            </span>

            <input
                type="text"
                class="form-control"
                value="${materia}"
                placeholder="Nome da matéria">

            <button
                class="btn btn-danger">

                Remover

            </button>
        `;

        const input = row.querySelector("input");

        input.addEventListener("input", () => {

            materias[index] = input.value;

        });

        row
            .querySelector("button")
            .addEventListener("click", () => {

                removerMateria(index);

            });

        lista.appendChild(row);

    });

}

/**
 * Nova matéria.
 */
document
.getElementById("btnNovaMateria")
.addEventListener("click", () => {

    materias.push("Nova Matéria");

    render();

});

/**
 * Remove matéria.
 */
function removerMateria(index) {

    if (!confirm("Deseja remover esta matéria?")) {

        return;

    }

    materias.splice(index, 1);

    render();

}

/**
 * Salva.
 */
document
.getElementById("btnSalvar")
.addEventListener("click", () => {

    materias = materias
        .map(m => m.trim())
        .filter(m => m.length > 0);

    materias = [...new Set(materias)];

    salvarMaterias(materias);

    render();

    alert("Matérias salvas com sucesso.");

});