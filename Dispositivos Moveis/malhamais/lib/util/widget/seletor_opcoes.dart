import 'package:flutter/material.dart';

class SeletorOpcoes extends StatefulWidget {
  List<String> opcoes;
  Icon? icone = Icon(Icons.arrow_drop_down);
  String? valor_selecionado;
  Function ao_mudar_opcao;
  bool expandir;
  FocusNode? marcador_foco;
  double tamanho_fonte;

  SeletorOpcoes({
    Key? key,
    required this.opcoes,
    this.icone,
    this.valor_selecionado,
    required this.ao_mudar_opcao,
    this.marcador_foco,
    this.expandir = true,
    this.tamanho_fonte = 25,
    }): super(key: key);

  _SeletorOpcoesState createState() => _SeletorOpcoesState();

}

class _SeletorOpcoesState extends State<SeletorOpcoes> {

  @override
  Widget build(BuildContext context) {
    return Container(
      height: 70,
      decoration: BoxDecoration(
        borderRadius: BorderRadius.circular(10.0),
        border: Border.all(
            color: Colors.black26, style: BorderStyle.solid, width: 1.50),
      ),
      child: DropdownButton<String>(
        focusNode: widget.marcador_foco,
        value: widget.valor_selecionado,
        isExpanded: widget.expandir,
        icon: widget.icone,
        iconSize: 24,
        elevation: 16,
        items : widget.opcoes.map((String dropDownStringItem) {
          return DropdownMenuItem<String>(
            value: dropDownStringItem,
            child: Text(
              dropDownStringItem,
              style: TextStyle(
                fontSize: widget.tamanho_fonte,
                color: Colors.black,
              ),),
          );
        }).toList(),
        onChanged: (String? novoItemSelecionado) {
          setState(() {
            widget.valor_selecionado = novoItemSelecionado;
            widget.ao_mudar_opcao(novoItemSelecionado);
          });
        },
      ),
    );
  }
}
