import { renderScript } from "../lib/render.js";

(() => {
  const autoscripts = document.querySelector("autoscripts");
  const isGithubPages = location.hostname.includes("github.io");
  const fonteUser = isGithubPages
    ? `${window.location.origin}/IFES-SISTEMAS-DE-INFORMACAO/src`
    : "/src";

  const srcsModule = [
    "links",
    "ip-info",
  ];
  const srcsCJS = ["functions"];
  const bootstrapsJs = ["bootstrap@5.3.6", "popper@2.11.8"];

  srcsModule.forEach((srcModule) => {
    var url = `${fonteUser}/js/${srcModule}.js`;
    renderScript(autoscripts, url, true);

    console.log(`%c [SISTEMA]: Novo script ESM: ${url}`, "#00ff00");
  });

  srcsCJS.forEach((srcCJS) => {
    var url = `${fonteUser}/js/${srcCJS}.js`;

    renderScript(autoscripts, url);

    console.log(`%c [SISTEMA]: Novo script: ${url}`, "#00ff00");
  });

  bootstrapsJs.forEach((bootstrapJs) => {
    var url = `${fonteUser}/lib/${bootstrapJs}.js`;

    renderScript(autoscripts, url);

    console.log(
      `%c [SISTEMA ATM BR]: Novo script Bootstrap Js: ${url}`,
      "#ffaa00"
    );
  });
})();
