class Post{
  int? userId;
  int? id;
  String? title;
  String? body;

  Post.fromJson(Map<String, dynamic> map){
    userId = map["userId"];
    id = map["id"];
    title = map["title"];
    body = map["body"];
  }

  @override
  String toString() {
    return 'Post{userId: $userId, id: $id, title: $title, body: $body}';
  }

}