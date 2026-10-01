// Para chamar Firebase.initializeApp()
import 'package:firebase_core/firebase_core.dart';
import 'package:flutter/material.dart';
import 'package:malhamais/telas/tela_abertura.dart';

Future<void> main() async {
  WidgetsFlutterBinding.ensureInitialized();
  await Firebase.initializeApp();
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      theme: ThemeData(
        // Definindo padrão para a AppBar
        appBarTheme: AppBarTheme(
          // Cor de fundo da AppBar
          backgroundColor: Colors.green,
          // Cor do texto e ícones da AppBar
          foregroundColor: Colors.white,
        ),
        // Definindo padrão para o Drawer
        drawerTheme: DrawerThemeData(
          // Cor de fundo do Drawer
          backgroundColor: Colors.white,
        ),
        // Definindo padrao para FloatingActionButton
        floatingActionButtonTheme: FloatingActionButtonThemeData(
          // Cor do texto do floatingActionButton
          foregroundColor: Colors.white,
          // Cor de fundo do floatingActionButton
          backgroundColor: Colors.green,
          // Botão circular
          shape: CircleBorder(),
        ),
        // Definindo padrão para ElevatedButton
        elevatedButtonTheme: ElevatedButtonThemeData(
          style: ButtonStyle(
            backgroundColor: MaterialStatePropertyAll<Color>(Colors.green),
          ),
        ),
        colorScheme: ColorScheme.fromSeed(
          seedColor: Colors.green,
          primary: Colors.green,
        ),
        // Define o tema para claro ou escuro
        brightness: Brightness.light,
        // Define a cor de fundo padrão para Containers
        scaffoldBackgroundColor: Colors.white,
      ),
      home: TelaAbertura(),
    );
  }
}
