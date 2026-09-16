class Endereco {
  String? complemento;
  String? bairro;
  String? localidade;
  String? logradouro;
  String? uf;

  Endereco.fromJson(Map<String, dynamic> map){
    complemento = map["complemento"];
    bairro = map["bairro"];
    localidade = map["localidade"];
    logradouro = map["logradouro"];
    uf = map["uf"];
  }

  Endereco({this.complemento,
            this.bairro,
            this.localidade,
            this.logradouro,
            this.uf});

  @override
  String toString() {
    return 'Endereco{complemento: $complemento, '
        'bairro: $bairro, cidade: $localidade, '
        'logradouro: $logradouro, estado: $uf}';
  }
}
