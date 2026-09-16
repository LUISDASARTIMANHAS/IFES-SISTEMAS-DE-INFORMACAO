import 'package:ftoast/ftoast.dart';
import 'package:flutter/material.dart';

class CaixaAlerta {

  static void mostrarToast(BuildContext context, String msg) {
    FToast.toast(
      context,
      msg: msg,
      color: Colors.red ,
      duration: 5000,
      msgStyle: TextStyle(
        color: Colors.white,
        fontSize: 16.0,
      ),

    );
  }

  static void mostrarMensagemErro(context, msg) {
    showDialog(
      context: context,
      builder: (BuildContext context) {
        // retorna um objeto do tipo Dialog
        return AlertDialog(
          title: new Text("Erro"),
          content: new Text(msg),
          actions: <Widget>[
            // define os botões na base do dialogo
            new TextButton(
              child: new Text("Fechar"),
              onPressed: () {
                Navigator.of(context).pop();
              },
            ),
          ],
        );
      },
    );
  }
}