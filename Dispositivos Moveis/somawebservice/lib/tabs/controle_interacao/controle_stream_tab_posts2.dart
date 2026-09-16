import 'package:somawebservice/domain/post.dart';
import 'package:somawebservice/services/resposta_servico.dart';
import 'package:somawebservice/services/posts_service.dart';
import 'dart:async';

class ControleStreamTabPosts2{
  final _controlador = StreamController<RespostaServico>();
  Stream<RespostaServico> get fluxo => _controlador.stream;

  Future<RespostaServico<List<Post>>> obterPosts() async{

    // Obtendo os posts
    RespostaServico<List<Post>> resposta = await PostsService.obterPosts();

    // Atualizando o fluxo dos dados (vai fazer o StreamBuilder relacionado
    // a esse _controlador atualizar a visualização dos dados)
    _controlador.add(resposta);

    return resposta;
  }

  void dispose() {
    _controlador.close();
  }
}
