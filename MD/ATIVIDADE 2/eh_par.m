function resultado = eh_par(n)
% Exercício 4: Verificador de Paridade

  if mod(n, 2) == 0
    fprintf('O número %d é PAR.\n', n);
    resultado = true;
  else
    fprintf('O número %d é ÍMPAR.\n', n);
    resultado = false;
  end
endfunction
