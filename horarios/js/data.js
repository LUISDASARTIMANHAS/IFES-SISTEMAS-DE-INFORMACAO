/**
 * ==============================================
 * Editor de Horários
 * Arquivo compartilhado
 * ==============================================
 */

const STORAGE_KEY = "editor-horarios";
const STORAGE_MATERIAS = "editor-materias";

/**
 * JSON padrão
 */
const DEFAULT_DATA = {
    horarios: [
        "13:00 - 13:49",
        "13:50 - 14:39",
        "14:40 - 15:30",
        "15:50 - 16:39",
        "16:40 - 17:29",
        "17:30 - 18:20",
        "18:40 - 19:29",
        "19:30 - 20:19",
        "20:20 - 21:09",
        "21:10 - 22:00"
    ],

    semana: [
        {
            dia: "Segunda",
            materias: ["-","-","-","-","-","-","-","-","-","-"]
        },
        {
            dia: "Terça",
            materias: ["-","-","-","-","-","-","-","-","-","-"]
        },
        {
            dia: "Quarta",
            materias: ["-","-","-","-","-","-","-","-","-","-"]
        },
        {
            dia: "Quinta",
            materias: ["-","-","-","-","-","-","-","-","-","-"]
        },
        {
            dia: "Sexta",
            materias: ["-","-","-","-","-","-","-","-","-","-"]
        }
    ]
};

/**
 * Carrega o horário.
 */
function carregarHorario() {

    const json = localStorage.getItem(STORAGE_KEY);

    if (!json) {

        salvarHorario(DEFAULT_DATA);

        return structuredClone(DEFAULT_DATA);

    }

    try {

        return JSON.parse(json);

    } catch {

        salvarHorario(DEFAULT_DATA);

        return structuredClone(DEFAULT_DATA);

    }

}

/**
 * Salva o horário.
 */
function salvarHorario(data) {

    localStorage.setItem(
        STORAGE_KEY,
        JSON.stringify(data)
    );

}

/**
 * Carrega catálogo de matérias.
 */
function carregarMaterias() {

    const json = localStorage.getItem(STORAGE_MATERIAS);

    if (!json) {

        return [];

    }

    try {

        return JSON.parse(json);

    } catch {

        return [];

    }

}

/**
 * Salva catálogo de matérias.
 */
function salvarMaterias(lista) {

    localStorage.setItem(
        STORAGE_MATERIAS,
        JSON.stringify(lista)
    );

}

/**
 * Exporta o JSON.
 */
function exportarJSON() {

    const data = carregarHorario();

    const blob = new Blob(
        [
            JSON.stringify(data, null, 2)
        ],
        {
            type: "application/json"
        }
    );

    const url = URL.createObjectURL(blob);

    const a = document.createElement("a");

    a.href = url;

    a.download = "horarios.json";

    a.click();

    URL.revokeObjectURL(url);

}

/**
 * Importa JSON.
 */
function importarJSON(event) {

    const file = event.target.files[0];

    if (!file) {

        return;

    }

    const reader = new FileReader();

    reader.onload = () => {

        try {

            const json = JSON.parse(reader.result);

            salvarHorario(json);

            alert("JSON importado com sucesso.");

            location.reload();

        } catch {

            alert("Arquivo inválido.");

        }

    };

    reader.readAsText(file);

}

/**
 * Cria vetor de matérias.
 */
function criarMaterias() {

    const data = carregarHorario();

    return new Array(data.horarios.length).fill("-");

}

/**
 * Garante integridade do JSON.
 */
function normalizarHorario() {

    const data = carregarHorario();

    const total = data.horarios.length;

    data.semana.forEach(dia => {

        while (dia.materias.length < total) {

            dia.materias.push("-");

        }

        while (dia.materias.length > total) {

            dia.materias.pop();

        }

    });

    salvarHorario(data);

}

normalizarHorario();