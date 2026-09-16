class RespostaServico<R>{
  bool get sucesso => mensagemErro == null;
  String? mensagemErro = null;
  R? resultado = null;

  RespostaServico(this.resultado);
  RespostaServico.erro(String this.mensagemErro);
}