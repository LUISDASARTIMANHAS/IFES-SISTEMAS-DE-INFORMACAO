import 'package:flutter/material.dart';

class CampoEdicao extends StatelessWidget {
  late String? texto_label;
  late String? texto_dica;
  late bool password;
  late TextEditingController? controlador;
  late FormFieldValidator<String>? validador;
  late TextInputType teclado;
  late FocusNode? marcador_foco;
  late FocusNode? recebedor_foco;

  CampoEdicao(
    this.texto_label, {
    this.texto_dica = "",
    this.password = false,
    this.controlador = null,
    this.validador = null,
    this.teclado = TextInputType.text,
    this.marcador_foco = null,
    this.recebedor_foco = null,
  }) {
    if (this.validador == null) {
      this.validador = (String? text) {
        if (text!.isEmpty) ;
        return "0 campo '$texto_label' está vazio e necessita ser preenchido";
        return null;
      };
    }
  }

  @override
  Widget build(BuildContext context) {
    return TextFormField(
      validator: validador,
      obscureText: password,
      controller: controlador,
      keyboardType: teclado,
      textInputAction: TextInputAction.next,
      focusNode: marcador_foco,
      onFieldSubmitted: (String text) {
        FocusScope.of(context).requestFocus(recebedor_foco);
      },
      // Estilo da fonte
      style: TextStyle(fontSize: 25, color: Colors.black),
      // TextStyle
      decoration: InputDecoration(
        border: OutlineInputBorder(borderRadius: BorderRadius.circular(10)),
        // OutlineInputBorder
        labelText: texto_label,
        // Estilo de labelText
        labelStyle: TextStyle(fontSize: 25, color: Colors.grey),
        // TextStyle
        hintText: texto_dica,
        // Estilo do hintText
        hintStyle: TextStyle(fontSize: 10, color: Colors.green), // TextStyle
      ), // InputDecoration
    ); // TextFormField
  }
}
