import 'package:flutter/material.dart';
import 'package:somawebservice/domain/post.dart';
import 'package:somawebservice/services/resposta_servico.dart';
import 'package:somawebservice/services/posts_service.dart';
import 'package:somawebservice/tabs/localwidget/listview_post_card.dart';
import 'package:somawebservice/util/caixa_alerta.dart';
import 'package:somawebservice/widget/botao_azul_servico_web.dart';


class TabPosts extends StatefulWidget {
  @override
  _TabPostsState createState() => _TabPostsState();
}

class _TabPostsState extends State<TabPosts> {
  List<Post> _lista_posts = <Post>[]; // List<Post>();

  @override
  Widget build(BuildContext context) {
    return Container(
      margin: EdgeInsets.only(top: 40, left: 10, right: 10),
      child: Column(
        children: <Widget>[
          Expanded(
            flex: 1,
            child: BotaoAzulServicoWeb(
              texto: "Obter Post Cards",
              // Aqui poderíamos ter a validação de um formulário, por exemplo
              pre_servico: (){
                return true;
                // return _formkey.currentState.validade();
              },
              // Chamando o serviço de obtenção de Posts
              acionar_servico: PostsService.obterPosts,
              // Chamado para atualizar a tab depois do serviço
              // A animação do botão é tratada pelo próprio BotaoAzulServicoWeb
              // Mas para que a listagem seja atualizada e o método build seja
              // chamado é necessário usar o setState()
              pos_servico: (RespostaServico resposta){
                setState(() {
                  if (resposta.sucesso)
                    _lista_posts = resposta.resultado;
                  else {
                    CaixaAlerta.mostrarMensagemErro(context, resposta.mensagemErro);
                  }
                });
              },
            ),
          ),
          Expanded(
            flex: 10,
            child: ListViewPostCard(_lista_posts),
          ),
        ],
      ),
    );
  }
}
