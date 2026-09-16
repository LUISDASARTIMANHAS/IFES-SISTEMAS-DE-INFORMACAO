import 'package:flutter/material.dart';

class PostCard extends StatelessWidget {
  String? userId;
  String? id;
  String? title;
  String? body;


  PostCard({this.userId, this.id, this.title, this.body});

  @override
  Widget build(BuildContext context) {
    return Card(
      child: Column(
        children: <Widget>[
          Text(
            "Usuário: $userId",
            style: TextStyle(
              color: Colors.black,
              fontSize: 14,
            ),
          ),
          Text(
            "Id: $id",
            style: TextStyle(
              color: Colors.black,
              fontSize: 14,
            ),
          ),
          Align(
            alignment: Alignment.bottomLeft,
            child: Text(
              "Título: $title",
              style: TextStyle(
                color: Colors.black,
                fontSize: 14,
              ),
            ),
          ),
          Align(
            alignment: Alignment.bottomLeft,
            child: Text(
              "Corpo: $body",
              textAlign: TextAlign.left,
              style: TextStyle(
                color: Colors.black,
                fontSize: 14,
              ),
            ),
          ),
        ],
      ),
    );
  }
}
