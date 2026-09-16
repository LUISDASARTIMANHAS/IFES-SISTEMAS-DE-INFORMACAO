import 'package:flutter/material.dart';
import 'package:somawebservice/tabs/tab_cep.dart';
import 'package:somawebservice/tabs/tab_posts.dart';
import 'package:somawebservice/tabs/tab_posts2.dart';
import 'package:somawebservice/tabs/tab_soma.dart';

void main() => runApp(MyApp());

class MyApp extends StatelessWidget {
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
          foregroundColor: Colors.white
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
            backgroundColor: WidgetStatePropertyAll<Color>(Colors.green),
          )
      ),
      // Definindo padrào para TabBar
      tabBarTheme: TabBarThemeData(
        // Cor da Tab selecionada
          labelColor: Colors.white,
          // Cor de Tab não selecionada
          unselectedLabelColor: Colors.white
      ),
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

// Precisei colocar como StatefulWidget ao invés de StatelessWidget
// para que a última aba não recarregue os dados todas as vezes que for acessada
// ou seja, para que ela armazene em memória os dados obtidos anterioremente
class HomePage extends StatefulWidget {
  @override
  _HomePageState createState() => _HomePageState();
}

// Esse "with SingleTickerProviderStateMixin<HomePage>" vai ser usado para não recarregar
// os dados da aba "Sem botão"
class _HomePageState extends State<HomePage> with SingleTickerProviderStateMixin<HomePage>{
  @override
  Widget build(BuildContext context) {
    return DefaultTabController(
      length: 4,
      child: Scaffold(
          appBar: AppBar(
            centerTitle: true,
            title: Text("Soma Web Service"),
            bottom: TabBar(
              tabs: <Widget>[
                Tab(
                  text: "Soma",
                ),
                Tab(text: "CEP"),
                Tab(text: "Com botão"),
                Tab(text: "Sem botão"),
              ],
            ),
          ),
          body: Builder(builder: (context) {
            return TabBarView(
              children: <Widget>[
                TabSoma(),
                TabCep(),
                TabPosts(),
                TabPosts2(),
              ], //await _buildSomaService(),
            );
          }),
        ),
    );
  }
}
