import 'dart:async';
import 'package:flutter/material.dart';
import 'package:somawebservice/services/resposta_servico.dart';
import 'package:somawebservice/widget/botao_azul.dart';

class BotaoAzulServicoWeb extends StatefulWidget {
  final String texto;
  final double? tamanho_fonte;
  final Color? cor_fonte;
  final bool Function()? pre_servico;
  final Future<RespostaServico> Function() acionar_servico;
  final Function(RespostaServico resposta)? pos_servico;
  final FocusNode? marcador_foco;

  BotaoAzulServicoWeb(
      {this.texto = "",
      this.tamanho_fonte,
      this.cor_fonte,
      this.pre_servico = null,
      required this.acionar_servico,
      this.pos_servico = null,
      this.marcador_foco});

  @override
  _BotaoAzulServicoWebState createState() => _BotaoAzulServicoWebState();
}

class _BotaoAzulServicoWebState extends State<BotaoAzulServicoWeb> {
  final _streamController = StreamController<bool>();

  @override
  void initState() {
    // TODO: implement initState
    super.initState();
  }

  @override
  void dispose() {
    // TODO: implement dispose
    super.dispose();
    _streamController.close();
  }


  @override
  Widget build(BuildContext context) {
    return StreamBuilder<bool>(
      stream: _streamController.stream,
      initialData: false,
      builder: (context, snapshot){
        return BotaoAzul(
          texto: widget.texto,
          mostrar_progress: snapshot.data!,
          ao_clicar: () async {
            if (widget.pre_servico == null) return null;
            else {
              // Se pre_servico retorna false simplemente retorna (não aciona
              // o serviço)
              if (!(widget.pre_servico!())){
                return;
              }
            }
            // Vai colocar o progress visível
            _streamController.add(true);

            // Aciona o serviço
            RespostaServico resposta = await widget.acionar_servico();

            // Vai voltar com o texto para o botão
            _streamController.add(false);

            // Vai atualizar a tela com os resultados obtidos no serviço
            widget.pos_servico!(resposta);
          },
        );
      },
    );
  }
}
