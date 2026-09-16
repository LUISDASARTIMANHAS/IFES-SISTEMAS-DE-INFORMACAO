import 'package:flutter/material.dart';
import 'package:somawebservice/services/resposta_servico.dart';
import 'package:somawebservice/services/soma_service.dart';
import 'package:somawebservice/util/caixa_alerta.dart';
import 'package:somawebservice/widget/botao_azul.dart';
import 'package:somawebservice/widget/campo_edicao_double.dart';

class TabSoma extends StatefulWidget {
  @override
  _TabSomaState createState() => _TabSomaState();
}

class _TabSomaState extends State<TabSoma> {
  final _controladorValor1 = TextEditingController();

  final _controladorValor2 = TextEditingController();

  String _resultado = "";

  bool _mostrarProgress = false;

  @override
  Widget build(BuildContext context) {
    return Container(
      // Define as margens do Container
      margin: EdgeInsets.only(top: 40, left: 10, right: 10),
      height: 400,
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
              controlador: _controladorValor1,
              texto_dica: "Digite o valor 1:",
            ),
          ),
          Expanded(
            flex: 1,
            child: CampoEdicaoDouble(
              controlador: _controladorValor2,
              texto_dica: "Digite o valor 2:",
            ),
          ),
          Expanded(
            flex: 1,
            child: BotaoAzul(
                texto: "Somar",
                mostrar_progress: _mostrarProgress,
                ao_clicar: () async {
                  setState(() {
                    _mostrarProgress = true;
                  });

                  RespostaServico resposta = await SomaService.somar(_controladorValor1.text,
                      _controladorValor2.text);

                  setState(() {
                    _mostrarProgress = false;
                    if(resposta.sucesso)
                      _resultado = resposta.resultado;
                    else{
                      CaixaAlerta.mostrarMensagemErro(context, resposta.mensagemErro);
                      _resultado = "";
                    }
                  });
                }
            ),
          ),
          Expanded(
            flex: 2,
            child: Container(
              margin: EdgeInsets.only(top: 20),
              child: Text(
                _resultado,
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
