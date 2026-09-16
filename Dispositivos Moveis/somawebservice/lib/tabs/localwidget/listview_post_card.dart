import 'package:flutter/material.dart';
import 'package:somawebservice/domain/post.dart';
import 'package:somawebservice/tabs/localwidget/post_card.dart';

class ListViewPostCard extends StatelessWidget {
  List<Post>? posts;

  ListViewPostCard(this.posts);

  @override
  Widget build(BuildContext context) {
    return Container(
      margin: EdgeInsets.only(top: 40, left: 10, right: 10),
      child: ListView.builder(
        // Se a lista de posts for nula
          itemCount: posts != null ? posts!.length : 0,
          itemBuilder: (context, index) {
            return PostCard(
              userId: posts![index].userId.toString(),
              id: posts![index].id.toString(),
              title: posts![index].title!,
              body: posts![index].body!,
            );
          }),
    );
  }
}
