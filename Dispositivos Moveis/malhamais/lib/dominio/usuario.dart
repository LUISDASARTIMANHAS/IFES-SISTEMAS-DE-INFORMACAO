class Usuario {
  String? id = null;
  String? email;

  @override
  String toString() {
    return 'Usuario{id: $id, email: $email}';
  }

  Usuario.fromMap(Map<String, dynamic> map) {
    email = map["email"];
  }

  Map<String, dynamic> toMap(){
    final Map<String, dynamic> data = Map<String, dynamic>();
    data['email'] = this.email;
    return data;
  }
}