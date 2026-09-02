import 'package:calculadoraimcflutter/tabs/tab_imc.dart';
import 'package:calculadoraimcflutter/tabs/tab_simples_calc.dart';
import 'package:flutter/material.dart';

void main() => runApp(Calculadora());

class Calculadora extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      theme: ThemeData(
        // Definindo padrão para a AppBar
        appBarTheme: AppBarTheme(
            // Cor de fundo da AppBar
            backgroundColor: Colors.blue,
            // Cor do texto e ícones da AppBar
            foregroundColor: Colors.white),
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
        )),
        // Definindo padrào para TabBar
        tabBarTheme: const TabBarThemeData(
            // Cor da Tab selecionada
            labelColor: Colors.white,
            // Cor de Tab não selecionada
            unselectedLabelColor: Colors.white),
        colorScheme: ColorScheme.fromSeed(
          seedColor: Colors.blue,
          primary: Colors.blue,
        ),
        // Define o tema para claro ou escuro
        brightness: Brightness.light,
        // Define a cor de fundo padrão para Containers
        scaffoldBackgroundColor: Colors.white,
      ),
      home: HomePage(),
    );
  }
}

class HomePage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return DefaultTabController(
      length: 2,
      child: Scaffold(
        appBar: AppBar(
          centerTitle: true,
          title: Text("Calculadora"),
          bottom: TabBar(
            tabs: <Widget>[
              Tab(
                  child: Text(
                "IMC",
                style: TextStyle(
                  fontSize: 40,
                ),
              )),
              Tab(
                text: "Simples Calc",
                icon: Icon(Icons.calculate),
              ),
            ],
          ),
        ),
        body: TabBarView(
          children: <Widget>[
            TabIMC(),
            TabSimplesCalc(),
          ],
        ),
      ),
    );
  }
}
