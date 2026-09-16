import 'package:flutter/material.dart';
import 'package:somawebservice/domain/endereco.dart';
import 'package:somawebservice/services/resposta_servico.dart';
import 'package:somawebservice/services/cep_service.dart';
import 'package:somawebservice/util/caixa_alerta.dart';
import 'package:somawebservice/widget/botao_azul.dart';
import 'package:somawebservice/widget/campo_edicao_double.dart';


class TabCep extends StatefulWidget {
  @override
  _TabCepState createState() => _TabCepState();
}

class _TabCepState extends State<TabCep> {
  final _controladorCep = TextEditingController();

  String _complemento = "Complemento";
  String _bairro = "Bairro";
  String _cidade = "Cidade";
  String _logradouro = "Logradouro";
  String _estado = "Estado";

  bool _mostrarProgress = false;

  @override
  Widget build(BuildContext context) {
    return Container(
      // Define as margens do Container
      margin: EdgeInsets.only(top: 40, left: 10, right: 10),
      child: Column(
        // No eixo y (principal da coluna) vai colocar os objetos no topo
        mainAxisAlignment: MainAxisAlignment.start,
        children: <Widget>[
          Expanded(
            // Peso desse componente (como no Android)
            flex: 1,
            // Notar que, como não estamos num formulário, o
            // validador desse campo não será acionado
            child: CampoEdicaoDouble(
              controlador: _controladorCep,
              texto_dica: "Digite o CEP",
            ),
          ),
          Expanded(
            flex: 1,
            child: BotaoAzul(
                texto: "Buscar Endereço",
                mostrar_progress: _mostrarProgress,
                ao_clicar: () async {
                  setState(() {
                    _mostrarProgress = true;
                  });

                  RespostaServico resposta =
                      await CepService.obterCep(_controladorCep.text);

                  setState(() {
                    _mostrarProgress = false;
                    if (resposta.sucesso) {
                      Endereco endereco = resposta.resultado;
                      if(endereco.complemento != null)
                          _complemento = endereco.complemento!;
                      else
                          _complemento = "Não tem complemento";
                      _bairro = endereco.bairro!;
                      _cidade = endereco.localidade!;
                      _logradouro = endereco.logradouro!;
                      _estado = endereco.uf!;
                    } else {
                      _complemento = "";
                      _bairro = "";
                      _cidade = "";
                      _logradouro = "";
                      _estado = "";
                      CaixaAlerta.mostrarToast(context, resposta.mensagemErro!);
                    }
                  });
                }),
          ),
          Expanded(
            flex: 1,
            child: Container(
              margin: EdgeInsets.only(top: 20),
              child: Text(
                _complemento,
                style: TextStyle(
                  color: Colors.black,
                  fontSize: 20,
                ),
              ),
            ),
          ),
          Expanded(
            flex: 1,
            child: Container(
              margin: EdgeInsets.only(top: 20),
              child: Text(
                _bairro,
                style: TextStyle(
                  color: Colors.black,
                  fontSize: 20,
                ),
              ),
            ),
          ),
          Expanded(
            flex: 1,
            child: Container(
              margin: EdgeInsets.only(top: 20),
              child: Text(
                _cidade,
                style: TextStyle(
                  color: Colors.black,
                  fontSize: 20,
                ),
              ),
            ),
          ),
          Expanded(
            flex: 1,
            child: Container(
              margin: EdgeInsets.only(top: 20),
              child: Text(
                _logradouro,
                style: TextStyle(
                  color: Colors.black,
                  fontSize: 20,
                ),
              ),
            ),
          ),
          Expanded(
            flex: 1,
            child: Container(
              margin: EdgeInsets.only(top: 20),
              child: Text(
                _estado,
                style: TextStyle(
                  color: Colors.black,
                  fontSize: 20,
                ),
              ),
            ),
          ),
        ],
      ),
    );
  }
}
