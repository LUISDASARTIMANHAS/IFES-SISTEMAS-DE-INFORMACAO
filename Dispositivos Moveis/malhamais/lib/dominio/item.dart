
class Item{
  String? id;
  String? nome;
  int? quantidade;
  bool? eh_urgente;
  String? id_usuario;


  Item({this.id = null, this.nome, this.quantidade, this.eh_urgente, this.id_usuario});

  Item.fromMap(Map<String, dynamic> map) {
    nome = map["nome"];
    quantidade = map["quantidade"];
    eh_urgente = map["eh_urgente"];
    id_usuario = map["id_usuario"];
  }

  Map<String, dynamic> toMap(){
    final Map<String, dynamic> data = Map<String, dynamic>();
    data['nome'] = this.nome;
    data['quantidade'] = this.quantidade;
    data['eh_urgente'] = this.eh_urgente;
    data['id_usuario'] = this.id_usuario;
    return data;
  }


}