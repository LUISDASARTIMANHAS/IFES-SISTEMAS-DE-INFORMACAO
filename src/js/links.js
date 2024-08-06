(() => {
  const url = "./src/data/info.json";
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
      // console.log("DATA RESPONSE: ");
      // console.log(data.hostname);
      importarCss(data);
    })
    .catch((error) => onErrorHostname(error));

  function onErrorHostname(error) {
    console.debug(error);
  }
})();

function importarCss(data) {
  const links = document.querySelector("links");
  const hostname = data.hostname || "betapingobras.glitch.me" || "pingobras.glitch.me"
  const protocol = document.location.protocol
  const fonte = `${protocol}//${hostname}/src/css/`
  const srcs = [
    "footer",
    "style",
    "btn",
    "head",
    "RGB",
    "main",
    "temas",
    "bootstrap"
  ];
  const srcsLinksFonts = [
    "4.7.0/css/font-awesome.min.css"
  ];

  for (let i = 0; i < srcs.length; i++) {
    const src = srcs[i];
    const link = fonte + src + ".css"
    var newLink = document.createElement("link");

    newLink.setAttribute("href", link);
    newLink.rel = "stylesheet";
    links.appendChild(newLink);

    console.log("Carregando css: " + link);
  }

  for (let i = 0; i < srcsLinksFonts.length; i++) {
    const head = document.querySelector("head");
    var newLink = document.createElement("link");

    newLink.setAttribute("href", "https://stackpath.bootstrapcdn.com/font-awesome/" + srcsLinksFonts[i]);
    newLink.rel = "stylesheet";
    head.appendChild(newLink);

    console.log("Novo Link de fonte css Num: " + srcsLinksFonts[i]);
  }

}
