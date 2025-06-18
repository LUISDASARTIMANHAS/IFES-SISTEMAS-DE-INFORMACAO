//render.js

export function renderDiv(element, classe, text) {
  var div = document.createElement("div");
  // configuracoes do span Categoria
  div.setAttribute("class", classe);
  div.textContent = text;
  element.appendChild(div);
  return div;
}

export function renderA(element, classe, href, text, target) {
  var a = document.createElement("a");
  // configuracoes do span Categoria
  a.setAttribute("class", classe);
  a.setAttribute("href", href);
  a.setAttribute("target", target);
  a.textContent = text;
  element.appendChild(div);
}

export function renderButton(element, classe, text) {
  var button = document.createElement("button");
  // configuracoes do span Categoria
  button.setAttribute("class", classe);
  button.textContent = text;
  element.appendChild(button);
}

export function renderSpan(element, classe, text) {
  var span = document.createElement("span");
  // configuracoes do span Categoria
  span.setAttribute("class", classe);
  span.textContent = text;
  element.appendChild(span);
}

export function renderH2(element, classe, nome) {
  var h2 = document.createElement("h2");
  // configuracoes do titulo h2
  h2.setAttribute("class", classe);
  h2.textContent = nome;
  element.appendChild(h2);
  return h2;
}

export function renderIMG(picture, classe, src, alt) {
  var img = document.createElement("img");
  img.setAttribute("class", classe);
  img.setAttribute("src", src);
  img.setAttribute("alt", alt);
  picture.appendChild(img);
  return img;
}

export function renderSource(picture, srcSet, minWidth) {
  // configuracoes de source
  var source = document.createElement("source");
  source.setAttribute("srcset", srcSet);
  source.setAttribute("media", `(min-width: ${minWidth}px)`);
  picture.appendChild(source);
  return source;
}

export function renderPicture(element, srcSet, nome) {
  var picture = document.createElement("picture");
  renderSource(picture, srcSet, 768);
  renderIMG(picture, srcSet, nome);
  element.appendChild(picture);
  return picture;
}

export function renderAWa(element, classe, number, textWA, text) {
  const href = `https://wa.me/${number}?text=${textWA}`;
  const classeWA = `fa-whatsapp whatsapp ${classe}`;
  renderA(element, classeWA, href, text, "_blank");
}


export function renderCard(filme, container, id) {
  const col = document.createElement("div");
  col.className = "col-8 col-sm-6 col-md-4 col-lg-3 col-xl-2 mb-3";

  col.innerHTML = `
    <div class="card bg-dark text-light border-0 h-100">
      <img id="img-${id}" src="${filme.image}" class="card-img-top" alt="${filme.title}" style="cursor: pointer;">
      <div class="card-body p-2">
        <h6 class="card-title mb-0 text-truncate">${filme.title}</h6>
      </div>

      <div class="accordion accordion-flush d-none mt-2" id="accordion-${id}">
        <div class="accordion-item">
          <h2 class="accordion-header">
            <button class="accordion-button collapsed bg-secondary text-white" type="button"
              data-bs-toggle="collapse" data-bs-target="#flush-collapse-${id}" aria-expanded="false">
              Detalhes
            </button>
          </h2>
          <div id="flush-collapse-${id}" class="accordion-collapse collapse show">
            <div class="accordion-body">
              <p><strong>Sinopse:</strong> Este é um resumo fictício para "${filme.title}".</p>
				<button class="btn btn-outline-light btn-sm mt-2" style="display: inline-block;"data-bs-toggle="modal" data-bs-target="#modal-${id}">
				Saber mais
				</button>
            </div>
          </div>
        </div>
      </div>
    </div>

    <!-- Modal -->
    <div class="modal fade" id="modal-${id}" tabindex="-1" aria-labelledby="modalLabel-${id}" aria-hidden="true">
      <div class="modal-dialog modal-dialog-centered modal-lg">
        <div class="modal-content bg-dark text-light">
          <div class="modal-header">
            <h5 class="modal-title" id="modalLabel-${id}">${filme.fullTitle}</h5>
            <button type="button" class="btn-close btn-close-white" data-bs-dismiss="modal"></button>
          </div>
          <div class="modal-body d-flex gap-3 flex-wrap">
            <img src="${filme.image}" class="img-fluid rounded" style="max-width: 200px;" />
            <div>
              <p><strong>Elenco:</strong> ${filme.crew}</p>
              <p><strong>Ano:</strong> ${filme.year}</p>
              <p><strong>Nota IMDb:</strong> ${filme.imDbRating}</p>
              <p><strong>Popularidade:</strong> ${filme.imDbRatingCount} votos</p>
              <p><strong>Descrição:</strong> Sinopse fictícia de exemplo para "${filme.title}".</p>
            </div>
          </div>
          <div class="modal-footer">
            <button class="btn btn-success">Assistir agora</button>
            <button class="btn btn-outline-light salvar-depois" data-filme='${JSON.stringify(filme)}'>
              Salvar para depois
            </button>
          </div>
        </div>
      </div>
    </div>
  `;

  	container.appendChild(col);

  	const img = col.querySelector(`#img-${id}`);
	img.addEventListener("click", () => {
	// Fecha todos os accordions antes
	document.querySelectorAll(".accordion").forEach(acc => acc.classList.add("d-none"));

	// Mostra o accordion correspondente ao card clicado
	const accordion = document.getElementById(`accordion-${id}`);
	accordion.classList.remove("d-none");
	});

}


function toggleAccordion(id) {
  const allAccordions = document.querySelectorAll(".accordion");
  allAccordions.forEach(acc => acc.classList.add("d-none"));

  const current = document.getElementById(`accordion-${id}`);
  current.classList.remove("d-none");
}


export function mostrarAccordion(id) {
  const accordion = document.getElementById(`accordion-${id}`);
  accordion.classList.toggle("d-none");

}


