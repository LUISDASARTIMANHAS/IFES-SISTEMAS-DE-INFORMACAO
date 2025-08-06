// loader-secoes.js
import { renderCard } from "./render.js";

document.addEventListener("DOMContentLoaded", () => {
  fetch("src/data/top-movies.json") 
    .then(res => res.json())
    .then(data => {
      renderCarouselCards(data, "carousel-cards-em-alta");
    })
    .catch(err => console.error("Erro ao carregar os filmes:", err));
});

function renderCarouselCards(data, containerId) {
  const container = document.getElementById(containerId);
  const cardsPorSlide = 5;
  let currentSlide = null;

  data.forEach((filme, index) => {
    if (index % cardsPorSlide === 0) {
      currentSlide = document.createElement("div");
      currentSlide.className = `carousel-item ${index === 0 ? "active" : ""}`;

      const row = document.createElement("div");
      row.className = "row justify-content-between gap-3";
      currentSlide.appendChild(row);
      container.appendChild(currentSlide);
    }

    const rowAtual = currentSlide.querySelector(".row");
    renderCard(filme, rowAtual, filme.id);
  });
}


