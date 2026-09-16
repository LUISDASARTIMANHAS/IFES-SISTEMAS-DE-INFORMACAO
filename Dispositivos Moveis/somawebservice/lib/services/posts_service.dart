import 'dart:convert';
import 'package:http/http.dart' as http;
import 'package:somawebservice/domain/post.dart';
import 'package:somawebservice/services/resposta_servico.dart';

class PostsService{
  static Future<RespostaServico<List<Post>>> obterPosts() async {
    try {
      var _url = "https://jsonplaceholder.typicode.com/posts/";
    // var _url = "https://jsonnnnnnplaceholder.typicode.com/posts/";

      print("GET --> $_url");

      final _myUri = Uri.parse(_url);

      // Headers para evitar bloqueio pelo serviço de segurança Cloudflare
      // Cloudflare é um serviço de segurança e CDN
      // (Content Delivery Network) que fica na frente
      // de muitos sites para protegê-los contra ataques (como DDoS)
      // e melhorar o desempenho.
      var _headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36',
        // Opcionalmente, adicione outros cabeçalhos que um navegador enviaria
        'Accept': 'application/json, text/plain, */*',
        'Accept-Language': 'en-US,en;q=0.9',
        // 'Connection': 'keep-alive', // O http package geralmente lida com isso
      };

      var _response = await http.get(_myUri, headers: _headers);

      // Solicitação feita com sucesso
      if(_response.statusCode == 200){
        List listMapResponse = json.decode(_response.body);
        final listPosts = listMapResponse.map<Post>((mapPost) => Post.fromJson(mapPost)).toList();
        return RespostaServico(listPosts);
      }else
        print("Erro HTTP: ${_response.statusCode}");
        print("Corpo da Resposta: ${_response.body}"); // Importante para depuração
        print("Cabeçalhos da Resposta: ${_response.headers}");
        return RespostaServico.erro("Status do erro emitido pelo servidor: ${_response.statusCode}");

    } on Exception catch (erro){
      return  RespostaServico.erro("Erro na conexão: ${erro.toString()}");
    }
  }
}
