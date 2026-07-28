let horario = carregarHorario();

let materias = carregarMaterias();

const tabela = document.getElementById("grade");

render();

/**
 * Renderiza a tabela completa.
 */
function render() {
  tabela.innerHTML = "";

  criarCabecalho();

  criarCorpo();
}

/**
 * Cria cabeçalho com horários.
 */
function criarCabecalho() {
  const thead = document.createElement("thead");

  let html = "<tr>";

  html += "<th>Dia</th>";

  horario.horarios.forEach((item, index) => {
    html += `

        <th>

            ${index + 1}°

            <br>

            <small>

                ${item}

            </small>

        </th>

        `;
  });

  html += "</tr>";

  thead.innerHTML = html;

  tabela.appendChild(thead);
}

/**
 * Cria linhas dos dias.
 */
function criarCorpo() {
  const tbody = document.createElement("tbody");

  horario.semana.forEach((dia, diaIndex) => {
    let tr = document.createElement("tr");

    let html = `

        <th>
            ${dia.dia}
        </th>

        `;

    dia.materias.forEach((materia, horarioIndex) => {
      html += `

            <td>

                <select
                    class="form-select"
                    data-dia="${diaIndex}"
                    data-horario="${horarioIndex}">

                    ${gerarOptions(materia)}

                </select>

            </td>

            `;
    });

    tr.innerHTML = html;

    tbody.appendChild(tr);
  });

  tabela.appendChild(tbody);

  document.querySelectorAll("select[data-dia]").forEach((select) => {
    select.addEventListener("change", atualizarMateria);
  });
}

/**
 * Gera opções do select.
 *
 * @param {string} selecionada
 * @returns {string}
 */
function gerarOptions(selecionada) {
  let html = "";

  const lista = ["-", ...materias];

  lista.forEach((item) => {
    html += `

        <option
            value="${item}"
            ${item === selecionada ? "selected" : ""}>

            ${item}

        </option>

        `;
  });

  return html;
}

/**
 * Atualiza uma célula.
 *
 * @param {Event} event
 */
function atualizarMateria(event) {
  const dia = Number(event.target.dataset.dia);

  const horarioIndex = Number(event.target.dataset.horario);

  horario.semana[dia].materias[horarioIndex] = event.target.value;
}

/**
 * Salvar manual.
 */
document.getElementById("btnSalvar").addEventListener("click", () => {
  salvarHorario(horario);

  alert("Grade salva.");
});
/**
 * Limpa todas as células.
 */
document.getElementById("btnLimpar").addEventListener("click", () => {
  if (!confirm("Limpar toda a grade?")) {
    return;
  }

  horario.semana.forEach((dia) => {
    dia.materias = dia.materias.map(() => "-");
  });

  salvarHorario(horario);

  render();
});
