import 'package:flutter/material.dart';
import 'package:nalista2/dominio/usuario.dart';
import 'package:nalista2/util/widget/botao.dart';
import 'package:nalista2/util/widget/campo_edicao.dart';
import 'package:nalista2/util/widget/campo_edicao_int_maior_que_zero.dart';

import 'controle_interacao/controle_tela_edicao_item.dart';



class TelaEdicaoItem extends StatefulWidget {
  Usuario usuario;


  TelaEdicaoItem(this.usuario);

  @override
  _TelaEdicaoItemState createState() => _TelaEdicaoItemState();
}

class _TelaEdicaoItemState extends State<TelaEdicaoItem> {
  late ControleTelaEdicaoItem _controle;

  @override
  void initState() {
    // TODO: implement initState
    super.initState();
    _controle = ControleTelaEdicaoItem(widget.usuario);
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("Inclusão de Item para Compra"),
      ),
      body: _body(),
    );
  }


  _body() {
    return Form(
      key: _controle.formkey,
      child: SingleChildScrollView(
        child: Container(
          padding: EdgeInsets.all(10),
          child: Column(
            mainAxisAlignment: MainAxisAlignment.start,
            children: <Widget>[
              CampoEdicao(
                "Nome:",
                controlador: _controle.controlador_nome,
                recebedor_foco: _controle.focus_quantidade,
                teclado: TextInputType.text,
              ),
              SizedBox(
                height: 10,
              ),
              CampoEdicaoIntMaiorQueZero(
                "Quantidade:",
                controlador: _controle.controlador_quantidade,
                marcador_foco: _controle.focus_quantidade,
                recebedor_foco: _controle.focus_botao_salvar,
                teclado: TextInputType.number,
              ),
              SizedBox(
                height: 10,
              ),
              CheckboxListTile(
                value: _controle.eh_urgente,
                onChanged: (value){
                  setState(() {
                    _controle.trocar_eh_urgente(value!);
                  });
                },
                title: new Text('Urgente', style: TextStyle(fontSize: 25),),
                controlAffinity: ListTileControlAffinity.leading,
                subtitle: new Text('Acabou ou vai acabar'),
                activeColor: Colors.green,
              ),
              Container(
                margin: EdgeInsets.only(top: 5),
                child: Row(
                  mainAxisAlignment: MainAxisAlignment.end,
                  children: <Widget>[
                    Botao(
                      texto: "Salvar",
                      cor: Colors.green,
                      ao_clicar: () {
                        _controle.salvar_item(context);
                      },
                    ),
                    SizedBox(
                      width: 5,
                    ),
                    Botao(
                      texto: "Cancelar",
                      cor: Colors.green,
                      ao_clicar: () {
                        _controle.inicializar_campos_edicao();
                      },
                    ),
                  ],
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }
}
