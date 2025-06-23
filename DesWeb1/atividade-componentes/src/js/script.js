document.addEventListener("DOMContentLoaded", () => {
  fetch("./src/data/TopMovies.json")
  .then(res => res.json())
  .then(data => {
    console.log("Filmes carregados:", data); // 👈 Verifique no console
    const container = document.getElementById("secao-em-alta");

    data.forEach(filme => {
      renderCard(filme, container, filme.id);
    });
  })
  .catch(err => console.error("Erro ao carregar os filmes:", err));
});

window.toggleAccordion = function (id) {
  const accordion = document.getElementById(`accordion-${id}`);
  accordion.classList.toggle("d-none");
};
