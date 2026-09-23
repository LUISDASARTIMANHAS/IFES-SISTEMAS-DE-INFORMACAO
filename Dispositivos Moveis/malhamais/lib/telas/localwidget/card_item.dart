import 'package:flutter/material.dart';
import 'package:nalista2/dominio/item.dart';
import 'package:nalista2/telas/controle_interacao/controle_tela_principal.dart';
import 'package:nalista2/util/widget/botao_icone.dart';


class CardItem extends StatelessWidget {
  ControleTelaPrincipal controle;
  int index;
  Item item;

  CardItem(this.item, this.controle, this.index);

  @override
  Widget build(BuildContext context) {
    return Card(
      child: Container(
        padding: EdgeInsets.all(10),
        height: 120,
        child: Row(
          children: <Widget>[
            Expanded(
              flex: 3,
              child: Center(
                child: Text(
                  item.nome!,
                  style: TextStyle(
                    fontSize: 14,
                    color: item.eh_urgente! ? Colors.red : Colors.black,
                    fontWeight: item.eh_urgente!  ? FontWeight.bold : FontWeight.normal,
                  ),
                ),
              ),
            ),
            Expanded(
              flex: 2,
              child: Center(
                child: Text(
                  item.quantidade.toString(),
                  style: TextStyle(
                    fontSize: 14,
                    color: item.eh_urgente! ? Colors.red : Colors.black,
                    fontWeight: item.eh_urgente!  ? FontWeight.bold : FontWeight.normal,
                  ),
                ),
              ),
            ),
            Expanded(
              flex: 3,
              child: BotaoIcone(
                texto: "Comprado",
                ao_clicar: () async {
                  controle.excluirItem(index);
                },
                cor: Colors.red,
                icone: Icons.delete,
              ),
            ),
          ],
        ),
      ),
    );
  }
}
