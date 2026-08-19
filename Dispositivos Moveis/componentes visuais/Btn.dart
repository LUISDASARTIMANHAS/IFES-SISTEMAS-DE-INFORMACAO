import 'package:flutter/material.dart';

class Btn extends StatelessWidget {
  String titulo;
  VoidCallback? aoClicar;

  Btn(this.titulo, {required this.aoClicar});

  @override
  Widget build(BuildContext context) {
    return ElevatedButton(onPressed: aoClicar, child: Text(titulo));

    //  return ElevatedButton(

    //           onPressed: () {
    //   if (formkey.currentState!.validate()) {
    //         print(
    //         "0 valor do campol é ${controlador1.text} e"
    //         "o valor do campo 2 é ${controlador2.text}",
    //         );
    //   }
    // },
    //child: titulo,
    //); // ElevatedButton;
  }
}
