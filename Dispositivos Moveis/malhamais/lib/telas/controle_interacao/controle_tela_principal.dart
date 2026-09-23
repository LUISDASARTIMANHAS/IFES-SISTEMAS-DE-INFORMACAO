import 'package:flutter/material.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:nalista2/dominio/item.dart';
import 'package:nalista2/dominio/usuario.dart';
import 'package:nalista2/util/nav.dart';

import '../tela_edicao_item.dart';
import '../tela_login.dart';

class ControleTelaPrincipal{
  Usuario usuario;
  List<Item>? itens;
  List<DocumentSnapshot>? document_itens;


  ControleTelaPrincipal(this.usuario);

  CollectionReference<Map<String, dynamic>> get _collection_itens => FirebaseFirestore.instance.collection('itens');
  Stream<QuerySnapshot> get stream => _collection_itens.where("id_usuario", isEqualTo: usuario.id).snapshots();

  void obterItens(QuerySnapshot data){
    document_itens = data.docs;
    itens = document_itens!.map((DocumentSnapshot  document) {
      Map<String, dynamic> data = document.data()! as Map<String, dynamic>;
      return Item.fromMap(data);
    }).toList();
  }

  void excluirItem(int index){
    DocumentSnapshot documentSnapshot = document_itens![index];
    documentSnapshot.reference.delete();
  }


  void sair(BuildContext context){
    FirebaseAuth.instance.signOut();
    push(context, TelaLogin(), replace: true);
  }

  void irParaTelaEdicaoItem(BuildContext context) {
    push(context, TelaEdicaoItem(usuario));
  }

}