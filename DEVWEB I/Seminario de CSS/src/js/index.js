const inputs = document.querySelectorAll("input");
const box = document.getElementById("box");

inputs.forEach((input) => {
  input.addEventListener("input", () => {
    alterarUnidade(input.value);
  });
});

function alterarUnidade(value) {
  if (value == "vh") {
    box.style.height = `100${value}`;
    box.style.height = `Unidade Atual: ${box.style.height}`;
  } else if (value == "ex") {
    box.style.fontSize = `7${value}`;
    box.textContent = `Unidade Atual: ${box.style.fontSize}`;
    box.style.width = "95%";
  } else {
    box.style.width = "100" + value;
    box.textContent = `Unidade Atual: ${box.style.width}`;
    box.style.height = "100px";
    box.style.fontSize = `16px`;
  }
}
