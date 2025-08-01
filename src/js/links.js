import { renderLinkCss } from "../lib/render.js";
const isGithubPages = location.hostname.includes("github.io");
const localFonte = isGithubPages
    ? `${window.location.origin}/IFES-SISTEMAS-DE-INFORMACAO/src`
    : "/src/";
(() => {
  const url = `${localFonte}/data/info.json`;
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
          throw new Error("Erro ao fazer buscar hostname: " + errorText);
        });
      }
    })
    .then((data) => {
      importarCss(data);
    })
    .catch((error) => onErrorHostname(error));

  function onErrorHostname(error) {
    console.debug(error);
  }
})();

function importarCss(data) {
  const linksContainer = document.querySelector("links");
  const head = document.querySelector("head");
  const hostname =
    data.hostname ||
    "luisdasartimanhas.github.io/PINGOBRAS" ||
    "betapingobras.onrender.me";
  const fonte = `https://${hostname}/src/css/`;
  const srcs = [
    "footer",
    "style",
    "btn",
    "head",
    "RGB",
    "main",
    "temas",
    "bootstrap",
  ];
  const srcsLinksIfes = [
    "html/mod_banners/css/banner-rotativo-home",
    "bootstrap/css/bootstrap.min",
    "css/custom",
    "font-awesome/css/font-awesome.min",
    "css/icones-bmp-verde",
    "css/template-verde",
  ];
  const srcsLinksLocal = ["k2", "reset", "simple-line-icons@2.4.1"];

  srcs.forEach((src) => {
    const link = fonte + src + ".css";
    renderLinkCss(linksContainer, link);

    console.log(`%c [SISTEMA]: Carregando CSS: ${link}`, "color: #ff00ff");
  });

  srcsLinksLocal.forEach((src) => {
    const link = `${localFonte}/css/${src}.css`;
    renderLinkCss(head, link);

    console.log(
      `%c [SISTEMA]: Carregando CSS Local: ${link}`,
      "color: #00ff00"
    );
  });

  // srcsLinksIfes
  // https://ifes.edu.br/templates/padraogoverno01/
  srcsLinksIfes.forEach((src) => {
    const link = `https://ifes.edu.br/templates/padraogoverno01/${src}.css`;
    renderLinkCss(head, link);

    console.log(
      `%c [SISTEMA]: Carregando CSS BY IFES: ${link}`,
      "color: #00ff00"
    );
  });
}
