import 'package:flutter/material.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:nalista2/dominio/usuario.dart';
import 'package:nalista2/util/nav.dart';
import 'package:nalista2/util/toast.dart';
import 'package:email_validator/email_validator.dart';

import '../tela_principal.dart';

class ControleTelaLogin {
  // Controles de edição do login e senha
  final controlador_login = TextEditingController();
  final controlador_senha = TextEditingController();

  // Controlador de formulário (para fazer validações)
  final formkey = GlobalKey<FormState>();

  // Controladores de foco
  final focus_senha = FocusNode();
  final focus_botao = FocusNode();

  // Autenticação
  final FirebaseAuth _auth = FirebaseAuth.instance;

  CollectionReference<Map<String, dynamic>> get _collection_usuarios =>
      FirebaseFirestore.instance.collection('usuarios');

  void logar(BuildContext context) async {
    if (formkey.currentState!.validate()) {
      String login = controlador_login.text.trim();
      String senha = controlador_senha.text.trim();

      if (EmailValidator.validate(login)) {
        try {
          // Logando
          UserCredential userCredential = await _auth
              .signInWithEmailAndPassword(email: login, password: senha);
          _irParaTelaPrincipal(userCredential.user, context);
        } on FirebaseAuthException catch (e) {
          if (e.code == 'user-not-found') {
            MensagemAlerta(
                context, "Erro: Usuário não encontrado para o email informado");
          } else if (e.code == 'wrong-password') {
            MensagemAlerta(
              context,
              "Erro: Password inválido!!!",
            );
            print('Wrong password provided for that user.');
          }
        }
      } else {
        MensagemAlerta(context, "Erro: Email informado com formato inválido");
      }
    }
  }

  void _irParaTelaPrincipal(User? user, BuildContext context) {
    // Buscando o usuário no serviço de armazenamento e chamando a tela Principal
    _collection_usuarios
        .where("email", isEqualTo: "${user!.email}")
        .snapshots()
        .listen((data) {
      Usuario usuario = Usuario.fromMap(data.docs[0].data());
      usuario.id = data.docs[0].id;
      push(context, TelaPrincipal(usuario), replace: true);
    });
  }

  void cadastrar(BuildContext context) async {
    if (formkey.currentState!.validate()) {
      String login = controlador_login.text.trim();
      String senha = controlador_senha.text.trim();

      if (EmailValidator.validate(login)) {
        try {
          UserCredential userCredential = await FirebaseAuth.instance
              .createUserWithEmailAndPassword(email: login, password: senha);

          // No serviço de armazenamento
          _collection_usuarios
              .add({
                'email': login,
              })
              .then(
                  (value) => _irParaTelaPrincipal(userCredential.user, context))
              .catchError(
                  (error) => print("Falha ao adicionar o usuário: $error"));
        } on FirebaseAuthException catch (e) {
          if (e.code == 'weak-password') {
            MensagemAlerta(context, "Erro: A senha fornecida é muito fraca");
          } else if (e.code == 'email-already-in-use') {
            MensagemAlerta(
                context, "Erro: Já existe conta com o email informado");
          }
        } catch (e) {
          print(e);
        }
      } else {
        MensagemAlerta(context, "Erro: Email informado com formato inválido");
      }
    }
  }
}
