const inputs = document.querySelectorAll("input");
const box = document.getElementById("box");

inputs.forEach((input) => {
  input.addEventListener("input", () => {
    alterarUnidade(input.value);
  });
});

function alterarUnidade(value) {
  if (value == "vh") {
    box.style.height = "100" + value;
  } else {
    box.style.width = "100" + value;
    box.textContent = `Unidade Atual: ${box.style.width}`;
    box.style.height = "100px";
  }
}
