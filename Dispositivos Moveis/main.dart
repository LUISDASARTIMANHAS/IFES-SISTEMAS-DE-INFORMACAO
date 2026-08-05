class Pessoa {
  late String nome;
  late int idade;
}

// gets e sets
class PessoaGetESets {
  String nome = "";
  int _idade = 0;

  String get idade {
    return "$_idade anos";
  }

  set idade(valor) {
    _idade = valor;
  }
}

// Classes – construtor padrão
class PessoaConstrutora {
  String nome;
  int idade;

  PessoaConstrutora(this.nome, this.idade);
}

// Classes – construtores nomeados
class PessoaConstrutoraNomeada {
  late String nome;
  int idade;

  PessoaConstrutoraNomeada(this.nome, this.idade);

  PessoaConstrutoraNomeada.anonima(this.idade) {
    this.nome = "Anonima";
  }
  
  //   Sobrescrita - toString
  String toString() {
    return "Nome: $nome, Idade: $idade";
  }
}

// Herança
class PessoaFisica extends PessoaConstrutoraNomeada {
  late String cpf;

  PessoaFisica(nome, idade, this.cpf) : super(nome, idade);

  PessoaFisica.anonima(idade, {cpf = "0000"}) : super.anonima(idade) {
    this.cpf = cpf;
  }

  //   Sobrescrita - toString
  String toString() {
    return "CPF: $cpf " + super.toString();
  }
}

// Classes – Métodos estáticos
class PessoaStatic {
  late String nome;
  late int idade;

  static void imprimirNomeClasse() {
    print("pessoa");
  }
}

void main() {
  //   quick start
  for (var i = 0; i < 10; i++) {
    print('hello ${i + 1}');
  }

  int v1 = -10;
  int v2 = v1.abs();
  print(v2);

  tiposDeDados();
  functions();
  listas();
  structures();
  argumentosOpcionais();
  classes();
  construtores();
  heranca();
  sobrescrita();
  mixins();
}

void mixins(){
  
}

// Sobrescrita - toString
void sobrescrita() {
  PessoaFisica pl = PessoaFisica("Pedro", 38, "999.999.999-99");
  print(pl);
}

// ========= Herança =========
void heranca() {
  PessoaFisica p1 = PessoaFisica("Pedro", 30, "999.999.999-99");
  PessoaFisica p2 = PessoaFisica.anonima(30, cpf: "xxx");
  PessoaFisica p3 = PessoaFisica.anonima(40);

  print("${p1.nome} tem ${p1.idade} e cpf ${p1.cpf}");
  print("${p2.nome} tem ${p2.idade} e cpf ${p2.cpf}");
  print("${p3.nome} tem ${p3.idade} e cpf ${p3.cpf}");
}

void construtores() {
  //   Classes – construtor padrão
  PessoaConstrutora pc1 = new PessoaConstrutora("Pedro", 30);
  PessoaConstrutora pc2 = PessoaConstrutora('Ana', 28);
  print("${pc1.nome} tem ${pc1.idade}");
  print("${pc2.nome} tem ${pc2.idade}");

  //   Classes – construtores nomeados
  PessoaConstrutoraNomeada pcn1 = new PessoaConstrutoraNomeada("pedro", 30);
  PessoaConstrutoraNomeada pcn2 = PessoaConstrutoraNomeada("pedro", 20);
  PessoaConstrutoraNomeada pcn3 = PessoaConstrutoraNomeada.anonima(50);

  print("${pcn1.nome} tem ${pcn1.idade}");
  print("${pcn2.nome} tem ${pcn2.idade}");
  print("${pcn3.nome} tem ${pcn3.idade}");

  //   gets e sets
  PessoaGetESets pGS1 = PessoaGetESets();
  pGS1.idade = 20;
  print(pGS1.idade);
  PessoaGetESets pGS2 = PessoaGetESets();
  pGS2.idade = 30;
  print(pGS2.idade);
}

// ========= Classes – Declaração e new
void classes() {
  Pessoa p1 = Pessoa();
  Pessoa p2 = new Pessoa();

  p1.nome = "Pedro";
  p1.idade = 30;

  p2.nome = "Ana";
  p2.idade = 68;

  print("A idade de ${p1.nome} é ${p1.idade}");
  print("A idade de ${p2.nome} ${p2.idade}");

  //   Classes – Métodos estáticos
  PessoaStatic.imprimirNomeClasse();
}

// ========= Funções – Argumentos nomeados - required
double areaRequired(double l1, {required double l2}) {
  return l1 * l2;
}

// ========= Funções – Argumento padrão
double areaPadrao(double l1, [double l2 = 7]) {
  return l1 * l2;
}

//  ========= Funções – Argumentos Opcionais
double area(double l1, [double? l2]) {
  if (l2 == null)
    return l1 * l1;
  else
    return l1 * l2;
}

int soma(int n1, [int? n2, int? n3]) {
  if (n2 == null || n3 == null)
    return 0;
  else
    return n1 + n2 + n3;
}

void argumentosOpcionais() {
  print("A área e ${area(3, 4)}");
  print("A área é ${area(3)}");

  int x = soma(2, 3, 4);
  int y = soma(3, 4);
  int z = soma(5);
  print("Os números são $x, $y, $z");
}

// ========= Tipos de dados - Map ==========
void structures() {
  Map structure = {"Fruta": "Manga", "Carro": "Duster", "Telefone": "Motorola"};

  print('O carro é ${structure["Carro"]}');
  print('A fruta é ${structure["Fruta"]}');
  print('0 telefone é ${structure["Telefone"]}');

  structure["Computador"] = "Dell";
  structure[3] = "Número 3";
  print(structure["Computador"]);
  print(structure[3]);
}

// ========= Tipo de dados - List ==========
void listas() {
  List lista1 = [];
  lista1.add("A");
  lista1.add("B");
  print("$lista1");
  for (String s in lista1) print("\n O valor é $s");

  for (int i = 0; i < lista1.length; i++) print("\n O valor é ${lista1[i]}");

  List lista2 = [1, 2, 3];
  print("$lista2");

  List lista3 = lista2.map((valor) {
    return valor * 10;
  }).toList();
  print("$lista3");

  List lista4 = lista2.map((valor) => valor * 20).toList();
  print("\n $lista4");
}

// ========= FUNÇÕES ==========
void functions() {
  Function minhaFuncao = imprime;
  Function(int, int, Function) f2 = imprimeSoma; // prende a função com tipos

  imprimeSoma(4, 5, minhaFuncao);
  f2(10, 20, minhaFuncao);
}

imprimeSoma(int n1, int n2, Function funcaoImprimir) {
  int soma = n1 + n2;
  funcaoImprimir(soma.toString());
}

void imprime(String s) {
  print("O valor de S é $s");
}

// ========= Tipos de dados ==========

void tiposDeDados() {
  //   Tipos de dados
  num n1 = 10.4;
  int i1 = n1.ceil();
  print(i1);

  double d1 = n1.toDouble();
  print(d1);

  n1 = -d1;
  if (n1.isNegative)
    print(n1);
  else
    print("O número é positivo");

  strings();
  bools();
  dynamics();
}

void strings() {
  //   Tipos de dados - String

  String s = "Pedro";
  String s_upper = s.toUpperCase();
  String s_lower = s.toLowerCase();
  print("$s em caixa alta é $s_upper");
  print("$s em caixa baixa é $s_lower");
  int tam = s_upper.length;
  String s_aux = s_upper.substring(1, 4);
  print('0 tamanho é $tam');
  print('A substring é $s_aux');
}

void bools() {
  bool eh_legal = false;
  if (!eh_legal) eh_legal = true;
  print("Agora ficou legal. Certo? $eh_legal");
}

void dynamics() {
  dynamic d = 10;
  print("O valor de d é $d");
  d = "Pedro";
  print("O valor de d é $d");
  d = 20;
  d = d + 10;
  print("O valor de d é $d");
}
