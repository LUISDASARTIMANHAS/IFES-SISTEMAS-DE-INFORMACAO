function [fog, gof] = avalia_composta(x)
    % f(x) = 5*x + 1
    % g(x) = x^2
    % (f o g)(x) = f(g(x)) = 5*(x^2) + 1
    % (g o f)(x) = g(f(x)) = (5*x + 1)^2

    fog = 5 * (x .^ 2) + 1;
    gof = (5 * x + 1) .^ 2;
endfunction
