import 'package:componentesvisuaisbasicos/Btn.dart';
import 'package:componentesvisuaisbasicos/campoEdicao.dart';
import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
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
    return Form(
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
  // return Container(
  //   margin: EdgeInsets.only(top: 16, left: 40, right: 20),
  //   padding: EdgeInsets.all(10),
  //   color: Colors.yellow,
  //   alignment: Alignment.centerRight,
  //   child: Container(
  //     decoration: BoxDecoration(
  //       color: Colors.green,
  //       borderRadius: BorderRadius.circular(10.0),
  //       border: Border.all(
  //         color: Colors.red,
  //         style: BorderStyle.solid,
  //         width: 2.50,
  //       ), // Border.all
  //       // BoxDecoration
  //     ),
  //   ), // Container
  // ); // Container

  // return Container(
  //   margin: EdgeInsets.only(top: 16, left: 40, right: 20),
  //   padding: EdgeInsets.all(10),
  //   color: Colors.yellow,
  //   alignment: Alignment.centerRight,
  //
  //   // child: InkWell(
  //   //   onTap: () {
  //   //     print("Olá Mundo!!!");
  //   //   },
  //   //   child: Text(
  //   //     "Olá Mundo, Olá Mundo, Olá Mundo, Olá Mundo, Olá Mundo",
  //   //     textAlign: TextAlign.justify,
  //   //     overflow: TextOverflow.ellipsis,
  //   //     maxLines: 2,
  //   //     style: TextStyle(fontWeight: FontWeight.bold, fontSize: 30),
  //   //   ),
  //   // ),
  //   // child: TextFormField(
  //   //   // Estilo da fonte
  //   //   style: TextStyle(fontSize: 25, color: Colors.deepOrange), // TextStyle
  //   //   decoration: InputDecoration(
  //   //     border: OutlineInputBorder(borderRadius: BorderRadius.circular(10)),
  //   //     // Outline InputBorder
  //   //     labelText: "Texto inicial",
  //   //     // Estilo de LabelText
  //   //     labelStyle: TextStyle(fontSize: 25, color: Colors.grey),
  //   //     // TextStyle
  //   //     hintText: "Essa é a dica!!!",
  //   //     // Estilo do hintText
  //   //     hintStyle: TextStyle(fontSize: 10, color: Colors.green), // TextStyle
  //   //   ), // InputDecoration
  //   // ),
  //   // // TextFormField
  //   // child: ElevatedButton(
  //   //   onPressed: () {
  //   //     print("Clicou no botão");
  //   //   },
  //   //   style: ElevatedButton.styleFrom(
  //   //     backgroundColor: Colors.lightGreenAccent,
  //   //     foregroundColor: Colors.red,
  //   //   ),
  //   //   child: Text("Clique aqui!!!"),
  //   // ), // ElevatedButton
  //   // child: Center(
  //   //   child: ElevatedButton(
  //   //     onPressed: () {
  //   //       print("Clicou no botão");
  //   //     },
  //   //     style: ElevatedButton.styleFrom(backgroundColor: Colors.yellowAccent),
  //   //     child: const Icon(
  //   //       Icons.all_inclusive,
  //   //       color: Colors.blueAccent,
  //   //     ), // Icon
  //   //   ), // ElevatedButton
  //   // ), // Center
  //   // child: ListView(
  //   //   children: [
  //   //     TextFormField(),
  //   //     TextFormField(),
  //   //     SizedBox(height: 10),
  //   //     ElevatedButton(
  //   //       onPressed: () {
  //   //         print("Clicou no botão");
  //   //       },
  //   //       style: ElevatedButton.styleFrom(
  //   //         foregroundColor: Colors.yellow,
  //   //         backgroundColor: Colors.black,
  //   //       ),
  //   //       child: Icon(Icons.all_inclusive),
  //   //     ),
  //   //     // ElevatedButton
  //   //   ],
  //   // ), // ListView
  // ); // Container
}
