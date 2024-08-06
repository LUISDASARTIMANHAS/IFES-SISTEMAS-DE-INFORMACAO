(() => {
  const url = "/src/data/info.json";
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
      importJs(data);
    })
    .catch((error) => onErrorHostname(error));

  function onErrorHostname(error) {
    console.debug(error);
  }
})();


function importJs(data) {
  const autoscripts = document.querySelector("autoscripts");
  const hostname = data.hostname || "betapingobras.glitch.me" || "pingobras.glitch.me"
  const protocol = document.location.protocol
  const fonte = `${protocol}//${hostname}/src/js/`
  const srcs = [
    "network",
    "copyright",
    "functions",
    "relogio",
    "alterar-tema"
  ]


  for (let i = 0; i < srcs.length; i++) {
    const src = srcs[i]
    const link = fonte + src + ".js"
    var newScript = document.createElement('script');

    newScript.setAttribute('src', link);
    autoscripts.appendChild(newScript)

    console.log("Carregando script: " + link)
  }

}
