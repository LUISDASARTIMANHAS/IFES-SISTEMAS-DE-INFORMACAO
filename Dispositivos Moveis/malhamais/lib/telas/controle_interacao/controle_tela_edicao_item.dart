import 'package:flutter/material.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:nalista2/dominio/item.dart';
import 'package:nalista2/dominio/usuario.dart';

import '../../util/nav.dart';



class ControleTelaEdicaoItem {
  Usuario usuario;

  ControleTelaEdicaoItem(this.usuario);

  CollectionReference<Map<String, dynamic>> get _collection_itens => FirebaseFirestore.instance.collection('itens');


  // Controlador de formulário (para fazer validações)
  final formkey = GlobalKey<FormState>();

  // Controladores de edição
  final controlador_nome = TextEditingController();
  final controlador_quantidade = TextEditingController();

  bool eh_urgente = false;


  // Controladores de foco
  final focus_quantidade = FocusNode();
  final focus_botao_salvar = FocusNode();

  void inicializar_campos_edicao() {
    controlador_nome.text = "";
    controlador_quantidade.text = "";
    eh_urgente = false;
  }

  void trocar_eh_urgente(bool value){
    eh_urgente = value;
  }

  void _inserir_item() {
    int quantidade = int.tryParse(controlador_quantidade.text) ?? 0;
    Item item = Item(
      nome: controlador_nome.text,
      quantidade: quantidade,
      id_usuario: usuario.id,
      eh_urgente: eh_urgente,
    );
    // Salvando no serviço de armazenamento
    DocumentReference docRef = _collection_itens.doc();
    docRef.set(item.toMap());
  }

  void salvar_item(BuildContext context) {
    if (formkey.currentState!.validate()) {
      _inserir_item();
      pop(context);
    }
  }
}
