import 'dart:async';

import 'package:http/http.dart' as http;
import 'package:somawebservice/services/resposta_servico.dart';

class SomaService {
  static Future<RespostaServico<String>> somar(
    String valor1,
    String valor2,
  ) async {
    try {
      // http://10.0.2.2/ ip da máquina onde o emulador roda
      var _url = "http://10.0.2.2/soma.php";

      Map _params = {'numero1': valor1, 'numero2': valor2};

      final _myUri = Uri.parse(_url);
      var _response = await http
          .post(_myUri, body: _params)
          .timeout(Duration(seconds: 3));

      // Solicitação feita com sucesso
      if (_response.statusCode == 200)
        return RespostaServico(_response.body);
      else
        return RespostaServico.erro(
          "Status do erro emitido pelo servidor: ${_response.statusCode}",
        );
    } on TimeoutException {
      return RespostaServico.erro("Tempo limite excedido");
    } on Exception catch (erro) {
      return RespostaServico.erro("Erro na conexão: ${erro.toString()}");
    }
  }
}
