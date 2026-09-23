

import 'package:flutter/material.dart';
import 'package:nalista2/util/widget/botao.dart';
import 'package:nalista2/util/widget/campo_edicao.dart';

import 'controle_interacao/controle_tela_login.dart';



class TelaLogin extends StatefulWidget {
  @override
  _TelaLoginState createState() => _TelaLoginState();
}

class _TelaLoginState extends State<TelaLogin> {
  late ControleTelaLogin _controle;

  @override
  void initState() {
    // TODO: implement initState
    super.initState();
    _controle = ControleTelaLogin();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("Login"),
      ),
      body: _body(),
    );
  }

  _body() {
    return Form(
      key: _controle.formkey,
      child: Container(
        // Margem padrão no Material Design
        padding: EdgeInsets.all(16),
        child: ListView(
          children: <Widget>[
            CampoEdicao(
              "Login",
              texto_dica: "Digite o Login",
              controlador: _controle.controlador_login,
              teclado: TextInputType.emailAddress,
              recebedor_foco: _controle.focus_senha,
            ),
            SizedBox(
              height: 10,
            ),
            CampoEdicao(
              "Senha",
              texto_dica: "Digite a senha",
              passaword: true,
              validador: (String? text){
                if(text!.isEmpty)
                  return "O campo '$text' está vazio e necessita ser preenchido";
                else if (text.length < 6)
                  return "A senha precisa ter no mínimo 6 caracteres";
                return null;
              },
              controlador: _controle.controlador_senha,
              marcador_foco: _controle.focus_senha,
              recebedor_foco: _controle.focus_botao,
            ),
            SizedBox(
              height: 20,
            ),
            Botao(
              texto: "Login",
              cor: Colors.green,
              ao_clicar: (){
                _controle.logar(context);
              },
              marcador_foco: _controle.focus_botao,
            ),
            Container(
              height: 46,
              margin: EdgeInsets.only(top: 20),
              child: InkWell(
                onTap: (){
                  _controle.cadastrar(context);
                },
                child: Text(
                  "Novo Usuário",
                  textAlign: TextAlign.center,
                  style: TextStyle(
                    fontSize: 22,
                    color: Colors.green,
                    decoration: TextDecoration.underline,
                  ),
                ),
              ),
            )
          ],
        ),
      ),
    );
  }
}
