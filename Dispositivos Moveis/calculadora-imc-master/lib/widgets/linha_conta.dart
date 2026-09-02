import 'package:calculadoraimcflutter/widgets/botao_azul.dart';
import 'package:calculadoraimcflutter/widgets/controlador_linha_conta.dart';
import 'package:calculadoraimcflutter/widgets/seletor_opcoes.dart';
import 'package:flutter/material.dart';
import 'package:ftoast/ftoast.dart';

import 'campo_edicao_double.dart';

class LinhaConta extends StatefulWidget {
  // Controlador para esse objeto em si (utilizado para acessar os valores externamente)
  ControladorLinhaConta controladorLinhaConta;

  LinhaConta({Key? key, required this.controladorLinhaConta}) : super(key: key);

  @override
  _LinhaContaState createState() => _LinhaContaState();
}

class _LinhaContaState extends State<LinhaConta> {
  // Controladores para os campos de edição
  final _controladorValor1 = TextEditingController();
  final _controladorValor2 = TextEditingController();

  // Boolenao para informar se já foi executada a operação de "=",
  // isso serve para sabermos se é para modificar uma gravação de resultado anterior
  // ou gerar um novo resultado
  bool _resultado_ja_adicionado = false;

  // Dados para o DropdownButton
  var _operacoes = ["+", "-", "x", "/"];
  var _operacao_selecionada = "+";

  // Texto da resposta das contas
  var _resultado = "";

  // Controladores de foco
  final _focoValor2 = FocusNode();
  final _focoBotaoIgual = FocusNode();

  // Variável utilizada para validar os campos do formulário
  final _formkey = GlobalKey<FormState>();

  @override
  Widget build(BuildContext context) {
    _inicializarValor1();
    return Form(
      // Com o formulário conseguimos acionar os validadores de cada um dos campos de
      // edição
      key: _formkey,
      child: Container(
        margin: EdgeInsets.only(left: 5, right: 5, top: 5, bottom: 5),
        child: Row(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            Expanded(
              // Peso desse componente (como no Android)
              flex: 3,
              child: CampoEdicaoDouble(
                controlador: _controladorValor1,
                texto_label: "Valor 1",
                recebedor_foco: _focoValor2,
              ),
            ),
            Expanded(
              // Peso desse componente (como no Android)
              flex: 1,
              child: Center(
                child: SeletorOpcoes(
                  opcoes: _operacoes,
                  valor_selecionado: _operacao_selecionada,
                  ao_mudar_opcao: (String novoItemSelecionado) {
                    _operacao_selecionada = novoItemSelecionado;
                    _resultado = "";
                  },
                ),
              ),
            ),
            Expanded(
              // Peso desse componente (como no Android)
              flex: 3,
              child: CampoEdicaoDouble(
                controlador: _controladorValor2,
                texto_label: "Valor 2",
                marcador_foco: _focoValor2,
                recebedor_foco: _focoBotaoIgual,
                validador: (String? text) {
                  if (text == null) return null;
                  if ((text.isEmpty) || (text.trim().isEmpty))
                    return "Não preenchido";
                  try {
                    double valor2 = double.parse(_controladorValor2.text);
                    if ((_operacao_selecionada == "/") && (valor2 == 0)) {
                      _makeToast("Não é possível dividir por 0");
                      return "Divisão por 0";
                    } else
                      return null;
                  } on FormatException catch (erro) {
                    return "Digite um número";
                  }
                },
              ),
            ),
            Expanded(
              // Peso desse componente (como no Android)
              flex: 1,
              child: BotaoAzul(
                texto: "=",
                ao_clicar: () {
                  setState(() {
                    // Chamando os validadores dos campos de edição
                    bool formOk = _formkey.currentState!.validate();
                    if (formOk) {
                      _executarOperacao();
                      if (_resultado_ja_adicionado) {
                        widget.controladorLinhaConta
                            .modificarUltimoResultado(_resultado);
                      } else {
                        widget.controladorLinhaConta
                            .adicionarNovoResultado(_resultado);
                        _resultado_ja_adicionado = true;
                      }
                    }
                  });
                },
                marcador_foco: _focoBotaoIgual,
              ),
            ),
            Expanded(
              // Peso desse componente (como no Android)
              flex: 2,
              child: Container(
                child: Text(
                  _resultado,
                  textAlign: TextAlign.right,
                ),
              ),
            ),
          ],
        ),
      ),
    );
  }

  void _inicializarValor1() {
    if ((widget.controladorLinhaConta.obterQuantidadeResultados() > 0) &&
        (_resultado == ""))
      _controladorValor1.text =
          widget.controladorLinhaConta.obterUltimoResultado();
  }

  void _executarOperacao() {
    try {
      double valor1 = double.parse(_controladorValor1.text);
      double valor2 = double.parse(_controladorValor2.text);
      double resultado = 0;
      switch (_operacao_selecionada) {
        case "+":
          resultado = valor1 + valor2;
          break;
        case "-":
          resultado = valor1 - valor2;
          break;
        case "x":
          resultado = valor1 * valor2;
          break;
        case "/":
          resultado = valor1 / valor2;
          break;
      }
      // 2 casas depois da vírgula
      _resultado = resultado.toStringAsFixed(2);
    } on Exception catch (erro) {
      _makeToast(erro.toString());
    }
  }

  _makeToast(String mensagem) {
    FToast.toast(context,
        msg: "Erro: $mensagem",
        color: Colors.red,
        duration: 5000,
        msgStyle: TextStyle(
          color: Colors.white,
          fontSize: 16.0,
        ));
  }
}
