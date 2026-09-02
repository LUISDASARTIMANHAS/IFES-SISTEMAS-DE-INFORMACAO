import 'package:calculadoraimcflutter/widgets/botao_azul.dart';
import 'package:calculadoraimcflutter/widgets/campo_edicao_double.dart';
import 'package:flutter/material.dart';

class TabIMC extends StatefulWidget {

  @override
  _TabIMCState createState() => _TabIMCState();
}

class _TabIMCState extends State<TabIMC> {
  final controladorPeso = TextEditingController();
  final controladorAltura = TextEditingController();
  String valor_imc = "";
  String situacao_imc = "";

  @override
  void initState() {
    // TODO: implement initState
    super.initState();
  }

  @override
  void dispose() {
    // TODO: implement dispose
    super.dispose();
  }

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
              controlador: controladorAltura,
              texto_dica: "Informe a altura aqui:",
            ),
          ),
          Expanded(
            flex: 1,
            child: CampoEdicaoDouble(
              controlador: controladorPeso,
              texto_dica: "Informe o peso aqui:",
            ),
          ),
          Expanded(
            flex: 1,
            child: BotaoAzul(
              texto: "Calcular",
              ao_clicar: () {
                setState(() {
                  double? imc = _calcularIMC();
                  if(imc == null) {
                    valor_imc = "";
                    situacao_imc = "";
                  }else {
                    valor_imc = imc.toString();
                    situacao_imc = _determinarSituacaoIMC(imc);
                  }
                });
              },
            ),
          ),
          Expanded(
            flex: 2,
            child: Container(
              margin: EdgeInsets.only(top: 20),
              child: Text(
                valor_imc,
                style: TextStyle(
                  color: Colors.black,
                  fontSize: 30,
                ),
              ),
            ),
          ),
          Expanded(
            flex: 2,
            child: Text(
              situacao_imc,
              style: TextStyle(
                color: Colors.black,
                fontSize: 50,
              ),
            ),
          ),
        ],
      ),
    );
  }

  String _determinarSituacaoIMC(double imc) {
    if (imc < 18.5)
      return "Abaixo do peso";
    else if (imc < 24.9)
      return "Peso normal";
    else if (imc < 29.9)
      return "Sobrepeso";
    else if (imc < 34.9)
      return"Obesidade grau 1";
    else if (imc < 39.9)
      return "Obesidade grau 2";
    else
      return "Obesidade grau 3";
  }

  double? _calcularIMC() {
    try {
      double altura = double.parse(controladorAltura.text);
      double peso = double.parse(controladorPeso.text);
      double imc = peso / (altura * altura);
      return imc;
    } on FormatException catch (erro) {
      // O ScnackBar precisa de um context definido dentro do Scaffold
      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(
          content: Text("Erro: $erro"),
          duration: Duration(seconds: 5),
          action: SnackBarAction(
            textColor: Colors.yellow,
            label: "Ok",
            onPressed: () {
              setState(() {
                _reinicializarCampos();
              });
            },
          ),
        ),
      );
    }
  }

  void _reinicializarCampos() {
    controladorPeso.text = "";
    controladorAltura.text = "";
    valor_imc = "";
    situacao_imc = "";
  }
}
