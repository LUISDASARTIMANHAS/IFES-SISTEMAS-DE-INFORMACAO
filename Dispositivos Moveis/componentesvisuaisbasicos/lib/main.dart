import 'package:componentesvisuaisbasicos/Btn.dart';
import 'package:componentesvisuaisbasicos/TabBarDemo.dart';
import 'package:componentesvisuaisbasicos/campoEdicao.dart';
import 'package:flutter/material.dart';

void main() {
  // runApp(const MyApp());
  runApp(const TabBarDemo());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      debugShowCheckedModeBanner: false,
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.orange),
      ),
      home: const MyHomePage(),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key});

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Theme.of(context).colorScheme.inversePrimary,
        title: Text("Usando Container"),
      ),
      body:
          _body(), // This trailing comma makes auto-formatting nicer for build methods.
    );
  }

  final formkey = GlobalKey<FormState>();
  final controlador1 = TextEditingController();
  final controlador2 = TextEditingController();
  FocusNode foco = FocusNode();

  _body() {
    Form formulario = Form(
      key: formkey,
      child: Container(
        margin: EdgeInsets.all(16),
        child: ListView(
          children: [
            CampoEdicao(
              "Campo 1",
              controlador: controlador1,
              recebedor_foco: foco,
            ), // CampoEdicao
            CampoEdicao(
              "Campo 2",
              controlador: controlador2,
              marcador_foco: foco,
            ), // CampoEdicao
            SizedBox(height: 10), // SizedBox
            Btn(
              "Imprime campos",
              aoClicar: () {
                if (formkey.currentState!.validate()) {
                  print(
                    "0 valor do campol é ${controlador1.text} e"
                    "o valor do campo 2 é ${controlador2.text}",
                  );
                }
              },
            ), // ElevatedButton
          ],
        ), // ListView
      ), // Container
    ); // Form
    Container crossAxisAlignment = Container(
      color: Colors.yellow,
      height: 50,
      // usado pra dar uma rolada caso não tenha espaço
      child: SingleChildScrollView(
        scrollDirection: Axis.horizontal,
        child: Row(
          mainAxisAlignment: MainAxisAlignment.spaceBetween,
          crossAxisAlignment: CrossAxisAlignment.end,
          children: <Widget>[Text("Texto1"), Text("Texto2"), Text("Texto3")],
        ),
      ),
    );

    Container ConDecoration = Container(
      margin: EdgeInsets.only(top: 16, left: 40, right: 20),
      padding: EdgeInsets.all(10),
      color: Colors.yellow,
      alignment: Alignment.centerRight,
      child: Container(
        decoration: BoxDecoration(
          color: Colors.green,
          borderRadius: BorderRadius.circular(10.0),
          border: Border.all(
            color: Colors.red,
            style: BorderStyle.solid,
            width: 2.50,
          ), // Border.all
          // BoxDecoration
        ),
      ), // Container
    ); // Container

    ListView lista = ListView(
      children: [
        TextFormField(),
        TextFormField(),
        SizedBox(height: 10),
        ElevatedButton(
          onPressed: () {
            print("Clicou no botão");
          },
          style: ElevatedButton.styleFrom(
            foregroundColor: Colors.yellow,
            backgroundColor: Colors.black,
          ),
          child: Icon(Icons.all_inclusive),
        ),
        // ElevatedButton
      ],
    ); // ListView

    Container conLista = Container(
      margin: EdgeInsets.only(top: 16, left: 40, right: 20),
      padding: EdgeInsets.all(10),
      color: Colors.yellow,
      alignment: Alignment.centerRight,

      child: lista,
    ); // Container

    InkWell inkWell = InkWell(
      onTap: () {
        print("Olá Mundo!!!");
      },
      child: Text(
        "Olá Mundo, Olá Mundo, Olá Mundo, Olá Mundo, Olá Mundo",
        textAlign: TextAlign.justify,
        overflow: TextOverflow.ellipsis,
        maxLines: 2,
        style: TextStyle(fontWeight: FontWeight.bold, fontSize: 30),
      ),
    );

    // child: TextFormField(
    //   // Estilo da fonte
    //   style: TextStyle(fontSize: 25, color: Colors.deepOrange), // TextStyle
    //   decoration: InputDecoration(
    //     border: OutlineInputBorder(borderRadius: BorderRadius.circular(10)),
    //     // Outline InputBorder
    //     labelText: "Texto inicial",
    //     // Estilo de LabelText
    //     labelStyle: TextStyle(fontSize: 25, color: Colors.grey),
    //     // TextStyle
    //     hintText: "Essa é a dica!!!",
    //     // Estilo do hintText
    //     hintStyle: TextStyle(fontSize: 10, color: Colors.green), // TextStyle
    //   ), // InputDecoration
    // ),
    // // TextFormField
    // child: ElevatedButton(
    //   onPressed: () {
    //     print("Clicou no botão");
    //   },
    //   style: ElevatedButton.styleFrom(
    //     backgroundColor: Colors.lightGreenAccent,
    //     foregroundColor: Colors.red,
    //   ),
    //   child: Text("Clique aqui!!!"),
    // ), // ElevatedButton
    // child: Center(
    //   child: ElevatedButton(
    //     onPressed: () {
    //       print("Clicou no botão");
    //     },
    //     style: ElevatedButton.styleFrom(backgroundColor: Colors.yellowAccent),
    //     child: const Icon(
    //       Icons.all_inclusive,
    //       color: Colors.blueAccent,
    //     ), // Icon
    //   ), // ElevatedButton
    // ), // Center

    Container expandido = Container(
      color: Colors.yellow,
      height: 50,
      child: Row(
        children: <Widget>[
          Expanded(
            flex: 2,
            child: Container(
              color: Colors.red,
              child: Text("Texto1", textAlign: TextAlign.center), // Text
            ), // Container
          ), // Expanded
          Expanded(child: Text("Texto2", textAlign: TextAlign.center)),
          Expanded(
            child: Container(
              color: Colors.blue,
              child: Text("Texto3", textAlign: TextAlign.center), // Text
            ), // Container
          ), // Expanded
        ], // <Widget>[]
      ), // Row
    ); // Container

    Column coluna = Column(
      mainAxisAlignment: MainAxisAlignment.spaceBetween,
      children: [
        CampoEdicao("Primeiro Elemento"),
        Text("Segundo Elemento"),
        CampoEdicao("Terceiro Elemento"),
      ],
    ); // Column
    Container conColuna = Container(child: coluna);

    Column ColumnRow = Column(
      mainAxisAlignment: MainAxisAlignment.start,
      children: <Widget>[
        Container(
          color: Colors.green,
          child: CampoEdicao("Primeiro Elemento"),
        ), // Container
        Row(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            Text("Texto1"),
            Text("Texto2"),
            Text("Texto3"),
          ], // <Widget>[]
        ), // Row
        Container(
          color: Colors.red,
          child: CampoEdicao("Terceiro Elemento"),
        ), // Container
      ], // <Widget>[]
    ); // Column

    Column ColumnExpanded = Column(
      children: <Widget>[
        Expanded(
          child: Container(
            color: Colors.indigo,
            alignment: Alignment.center,
            child: Icon(Icons.ac_unit),
          ),
        ), // Container, Expanded
        Expanded(
          child: Container(
            color: Colors.deepOrangeAccent,
            alignment: Alignment.centerRight,
            child: Icon(Icons.access_alarm),
          ),
        ), // Container, Expanded
        Expanded(
          child: Container(
            color: Colors.brown,
            alignment: Alignment.centerLeft,
            child: Icon(Icons.accessibility),
          ),
        ), // Container, Expanded
      ], // <Widget>[]
    ); // Column

    Column ColumnRowExpanded = Column(
      children: <Widget>[
        Expanded(
          child: Container(
            color: Colors.indigo,
            alignment: Alignment.center,
            child: Icon(Icons.ac_unit),
          ),
        ), // Container, Expanded
        Expanded(
          child: Container(
            color: Colors.deepOrangeAccent,
            alignment: Alignment.centerRight,
            child: Icon(Icons.access_alarm),
          ),
        ), // Container, Expanded
        Expanded(
          child: Container(
            color: Colors.brown,
            alignment: Alignment.centerLeft,
            child: Row(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: <Widget>[
                Icon(Icons.accessibility_new),
                Icon(Icons.accessible),
                Icon(Icons.accessible_forward),
              ], // <Widget>[]
            ), // Row
          ), // Container
        ), // Expanded
      ], // <widget>[]
    ); // Column;

    Stack imagemStack = Stack(
      fit: StackFit.expand,
      children: <Widget>[
        Image.asset("assets/mar.jpg", fit: BoxFit.cover),
      ], // <Widget>[]
    ); // Stack;

    Stack Empilhado = Stack(
      fit: StackFit.expand,
      children: <Widget>[
        Image.asset("assets/mar.jpg", fit: BoxFit.cover),
        Container(
          alignment: Alignment.bottomCenter,
          child: Container(
            alignment: Alignment.center,
            height: 40,
            color: Colors.green,
            child: Row(
              mainAxisAlignment: MainAxisAlignment.center,
              children: <Widget>[
                Text(
                  "Flutter é muito legal",
                  style: TextStyle(
                    fontSize: 20,
                    color: Colors.white,
                  ), // TextStyle
                ), // Text
              ], // <Widget>[]
            ), // Row
          ), // Container
        ), // Container
      ], // <Widget>[]
    ); // Stack

    PageView carrossel = PageView(
      children: <Widget>[
        Image.asset(
          "assets/OceanImageBank_RenataRomeo_53.webp",
          fit: BoxFit.cover,
        ),
        Image.asset("assets/mar.jpg", fit: BoxFit.cover),
      ], // <Widget>[]
    ); // PageView
    return carrossel;

    // return Form(
    //   key: formkey,
    //   child: Container(
    //     margin: EdgeInsets.all(16),
    //     child: ListView(
    //       children: [
    //         TextFormField(
    //           validator: (String? texto) {
    //             if (texto!.isEmpty)
    //               return "O campo está vazio e necessita ser preenchido";
    //             return null;
    //           },
    //           controller: controlador1,
    //         ), // TextFormField
    //         TextFormField(
    //           validator: (String? texto) {
    //             if (texto!.isEmpty)
    //               return "O campo está vazio e necessita ser preenchido";
    //             return null;
    //           },
    //           controller: controlador2,
    //         ), // TextFormField
    //         SizedBox(height: 10),
    //         ElevatedButton(
    //           onPressed: () {
    //             if (formkey.currentState!.validate()) {
    //               print(
    //                 "0 valor do campol é ${controlador1.text} e"
    //                 "o valor do campo 2 é ${controlador2.text}",
    //               );
    //             }
    //           },
    //           child: Text("Imprime campos"),
    //           // ElevatedButton
    //         ),
    //       ],
    //     ), // ListView
    //   ), // Container
    // ); // Form
  }
}
