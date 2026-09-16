import 'package:flutter/material.dart';

class BotaoAzul extends StatelessWidget {
  final String texto;
  final double tamanho_fonte;
  final Color cor_fonte;
  final VoidCallback? ao_clicar;
  final FocusNode? marcador_foco;
  final bool mostrar_progress;

  BotaoAzul({
    this.texto = "",
    this.tamanho_fonte = 20,
    this.cor_fonte = Colors.white,
    required this.ao_clicar,
    this.marcador_foco = null,
    this.mostrar_progress = false,
  });

  @override
  Widget build(BuildContext context) {
    return Container(
      width: 300,
      child: ElevatedButton(
        style: ElevatedButton.styleFrom(
          backgroundColor: Colors.blue,
          shape: RoundedRectangleBorder(
              borderRadius: new BorderRadius.circular(10.0)),
        ),
        child: mostrar_progress
            ? Center(
                child: CircularProgressIndicator(
                  valueColor: AlwaysStoppedAnimation<Color>(Colors.white),
                ),
              )
            : Text(texto,
                style: TextStyle(color: cor_fonte, fontSize: tamanho_fonte)),
        onPressed: ao_clicar,
        focusNode: marcador_foco,
      ),
    );
  }
}
