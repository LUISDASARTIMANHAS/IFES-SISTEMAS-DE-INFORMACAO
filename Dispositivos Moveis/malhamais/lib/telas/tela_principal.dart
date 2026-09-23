import 'package:flutter/material.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:nalista2/dominio/item.dart';
import 'package:nalista2/dominio/usuario.dart';

import 'controle_interacao/controle_tela_principal.dart';
import 'localwidget/card_item.dart';

class TelaPrincipal extends StatefulWidget {
  Usuario usuario;


  TelaPrincipal(this.usuario);

  @override
  _TelaPrincipalState createState() => _TelaPrincipalState();
}

class _TelaPrincipalState extends State<TelaPrincipal> {
  late ControleTelaPrincipal _controle;

  @override
  void initState() {
    // TODO: implement initState
    super.initState();
    _controle = ControleTelaPrincipal(widget.usuario);
  }


  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("Lista de Compras"),
        actions: <Widget>[
          IconButton(
            icon: Icon(Icons.exit_to_app),
            onPressed: () {
              _controle.sair(context);
            },
          ),
        ],
      ),
      body: _body(),
      floatingActionButton: FloatingActionButton(
        child: Icon(Icons.add),
        onPressed: ()  {
          _controle.irParaTelaEdicaoItem(context);
        },
      ),
    );
  }

  _body() {
    return _stream_builder();
  }

  Container _stream_builder() {
    return Container(
      padding: EdgeInsets.all(16),
      child: StreamBuilder<QuerySnapshot>(
          stream: _controle.stream,
          builder: (context, snapshot) {
            if(!snapshot.hasData){
              return Center(
                child: CircularProgressIndicator(),
              );
            }
            _controle.obterItens(snapshot.data!);
            return _listView();
          }
      ),
    );
  }

  ListView _listView() {
    return ListView.builder(
      itemCount: _controle.itens != null ? _controle.itens!.length : 0,
      itemBuilder: (context, index) {
        Item item = _controle.itens![index];
        return CardItem(item, _controle, index);
      },
    );
  }
}
