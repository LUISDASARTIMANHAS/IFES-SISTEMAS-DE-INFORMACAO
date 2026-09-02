import 'package:flutter/material.dart';

class SeletorOpcoes extends StatefulWidget {
  List<String>? opcoes;
  Icon? icone ;
  String? valor_selecionado;
  Function? ao_mudar_opcao;

  SeletorOpcoes({
    Key? key,
    this.opcoes,
    this.icone,
    this.valor_selecionado,
    this.ao_mudar_opcao
  }): super(key: key){
    if(this.opcoes == null) this.opcoes = <String>[];
    if(this.icone == null) this.icone = Icon(Icons.arrow_drop_down);

  }
  _SeletorOpcoesState createState() => _SeletorOpcoesState();
}

class _SeletorOpcoesState extends State<SeletorOpcoes> {
  @override
  Widget build(BuildContext context) {
    return DropdownButton<String>(
      value: widget.valor_selecionado,
      icon: widget.icone,
      iconSize: 24,
      elevation: 16,
      underline: Container(
        height: 2,
        color: Colors.blueAccent,
      ),
      items : widget.opcoes!.map((String dropDownStringItem) {
        return DropdownMenuItem<String>(
          value: dropDownStringItem,
          child: Text(dropDownStringItem),
        );
      }).toList(),
      onChanged: (String? novoItemSelecionado) {
        setState(() {
          widget.valor_selecionado = novoItemSelecionado;
          if(widget.ao_mudar_opcao != null)
            widget.ao_mudar_opcao!(novoItemSelecionado);
        });
      },
    );
  }
}
