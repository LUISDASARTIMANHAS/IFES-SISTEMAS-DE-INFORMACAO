import 'package:flutter/material.dart';


class CampoEdicaoDouble extends StatelessWidget {
  String texto_label;
  String texto_dica;
  bool password;
  TextEditingController? controlador;
  FormFieldValidator<String>? validador;
  TextInputType? teclado;
  FocusNode? marcador_foco;
  FocusNode? recebedor_foco;
  TextAlign alinhamento;


  CampoEdicaoDouble({
      this.texto_label = "",
      this.texto_dica = "",
      this.password = false,
      this.controlador = null,
      this.validador = null,
      this.marcador_foco = null,
      this.recebedor_foco = null,
      this.alinhamento = TextAlign.center}){
    
      if (this.validador == null){
        validador = (String? text){
          if (text == null) return "Não preenchido";
          if((text.isEmpty) || (text.trim().isEmpty))
            return "Não preenchido";
          try{
            // Validando se consegue converter para número
            double.parse(controlador!.text);
            // Return null significa que a validação respondeu
            // ok!!!
            return null;
          }on FormatException{
            return "Digite um número";
          }
        };
      }
  }

  @override
  Widget build(BuildContext context) {
    return TextFormField(
      textAlign: alinhamento,
      validator: validador,
      obscureText: password,
      controller: controlador,
      // Teclado numérico
      keyboardType: TextInputType.number,
      // Vai possibilitar avançar o foco para o objeto visual que tiver como
      // marcador_foco o recebedor_foco desse objeto
      textInputAction: TextInputAction.next,
      focusNode: marcador_foco,
      onFieldSubmitted: (String text){
        FocusScope.of(context).requestFocus(recebedor_foco);
      },
      // Estilo da fonte
      style: TextStyle(
        color: Colors.black,
      ),
      decoration: InputDecoration(
        hintText: texto_dica,
        hintStyle: TextStyle(
          fontSize: 14,
          color: Colors.black12,
        ),
        labelText: texto_label,
        labelStyle: TextStyle(
          fontSize: 15,
          color: Colors.grey,
        ),
      ),
    );
  }
}
