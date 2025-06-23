function inserirContato() {
  const form = document.getElementById("formulario");
  if (!form.checkValidity()) {
    Swal.fire({
      icon: 'error',
      title: 'Campos obrigatórios!',
      text: 'Por favor, preencha todos os campos antes de inserir.',
    });
    return;
  }

  const nome = document.getElementById("nome").value.trim();
  const telefone = document.getElementById("telefone").value.trim();
  const email = document.getElementById("email").value.trim();

  const tabela = document.getElementById("tabelaContatos");
  const novaLinha = tabela.insertRow();

  novaLinha.innerHTML = `
    <td>${nome}</td>
    <td>${telefone}</td>
    <td>${email}</td>
    <td class="acoes">
      <button class="editar" onclick="editarContato(this)">Editar</button>
      <button class="excluir" onclick="excluirContato(this)">Excluir</button>
    </td>
  `;

  form.reset();

  Swal.fire({
    icon: 'success',
    title: 'Contato adicionado!',
    text: 'O contato foi inserido com sucesso.',
    timer: 1500,
    showConfirmButton: false
  });
}

function excluirContato(botao) {
  Swal.fire({
    title: 'Tem certeza?',
    text: "Você deseja excluir este contato?",
    icon: 'warning',
    showCancelButton: true,
    confirmButtonColor: '#e74c3c',
    cancelButtonColor: '#7f8c8d',
    confirmButtonText: 'Sim, excluir!',
    cancelButtonText: 'Cancelar'
  }).then((result) => {
    if (result.isConfirmed) {
      const linha = botao.parentNode.parentNode;
      linha.remove();

      Swal.fire({
        title: 'Excluído!',
        text: 'O contato foi removido.',
        icon: 'success',
        timer: 1500,
        showConfirmButton: false
      });
    }
  });
}


function editarContato(botao) {
  const linha = botao.parentNode.parentNode;
  const colunas = linha.querySelectorAll("td");

  const nomeAtual = colunas[0].textContent;
  const telefoneAtual = colunas[1].textContent;
  const emailAtual = colunas[2].textContent;

  colunas[0].innerHTML = `<input type="text" name="nome" value="${nomeAtual}">`;
  colunas[1].innerHTML = `<input type="tel" name="tel" id="tel-edicao" value="${telefoneAtual}">`;
  colunas[2].innerHTML = `<input type="email" name="email" value="${emailAtual}">`;
  colunas[3].innerHTML = `
    <button class="salvar" onclick="salvarEdicao(this)">Salvar</button>
    <button class="cancelar" onclick="cancelarEdicao(this, '${nomeAtual}', '${telefoneAtual}', '${emailAtual}')">Cancelar</button>
  `;

  // Aplica máscara ao input de telefone da edição
  const telEdit = document.getElementById('tel-edicao');
  IMask(telEdit, {
    mask: '(00)00000-0000'
  });
}


function salvarEdicao(botao) {
  const linha = botao.parentNode.parentNode;
  const inputs = linha.querySelectorAll("input");

  const novoNome = inputs[0].value.trim();
  const novoTelefone = inputs[1].value.trim();
  const novoEmail = inputs[2].value.trim();

  // Validação básica
  if (!novoNome || !novoTelefone || !novoEmail) {
    Swal.fire({
      icon: 'error',
      title: 'Campos vazios!',
      text: 'Todos os campos devem ser preenchidos.',
    });
    return;
  }

  // Validação de telefone (deve conter pelo menos 11 dígitos)
  const telefoneLimpo = novoTelefone.replace(/\D/g, "");
  if (telefoneLimpo.length < 11) {
    Swal.fire({
      icon: 'error',
      title: 'Telefone inválido!',
      text: 'O telefone deve conter 11 dígitos (com DDD).',
    });
    return;
  }

  // Validação simples de e-mail
  if (!novoEmail.includes("@") || !novoEmail.includes(".")) {
    Swal.fire({
      icon: 'error',
      title: 'E-mail inválido!',
      text: 'Digite um e-mail válido contendo "@" e "."',
    });
    return;
  }

  linha.innerHTML = `
    <td>${novoNome}</td>
    <td>${novoTelefone}</td>
    <td>${novoEmail}</td>
    <td class="acoes">
      <button class="editar" onclick="editarContato(this)">Editar</button>
      <button class="excluir" onclick="excluirContato(this)">Excluir</button>
    </td>
  `;

  Swal.fire({
    icon: 'success',
    title: 'Contato atualizado!',
    timer: 1200,
    showConfirmButton: false
  });
}


function cancelarEdicao(botao, nome, telefone, email) {
  const linha = botao.parentNode.parentNode;

  linha.innerHTML = `
    <td>${nome}</td>
    <td>${telefone}</td>
    <td>${email}</td>
    <td class="acoes">
      <button class="editar" onclick="editarContato(this)">Editar</button>
      <button class="excluir" onclick="excluirContato(this)">Excluir</button>
    </td>
  `;
}

// Máscara para o campo de telefone
const telefoneInput = document.getElementById('telefone');

IMask(telefoneInput, {
  mask: '(00)00000-0000'
});