<!DOCTYPE html>
<html lang="ru">
<head>
   <meta charset="UTF-8">
   <meta http-equiv="X-UA-Compatible" content="IE=edge">
   <meta name="viewport" content="width=device-width, initial-scale=1.0">
   <title>Профиль</title>
   <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.3.1/dist/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
</head>
<body>
   <div class="container mt-4" align="center">
       <!-- Выводим значение из массива $_COOKIE, в нашем случае - это имя пользователя, чтобы сделать приветствие -->
       <h1> Welcome, <?php echo $_COOKIE['User']; ?> </h1>
       <form method="POST" action="profile.php">
           <input class="form-control" type="text" name="title" placeholder="Title">
           <textarea class="form-control" rows="3" name="text" placeholder="Write something..."></textarea>
           <button type="submit" class="btn btn-success" name="submit">Продолжить</button>
       </form>
   </div>
</body>
</html>
 
<?php
require_once('db.php');
 
if (!isset($_COOKIE['User'])) { 
    header("Location: login.php");
 }
 

$link = mysqli_connect('127.0.0.1', 'root', 'tragernout', 'website');
 
if (isset($_POST['submit'])) {
   $title = $_POST['title'];	
   $main_text = $_POST['text'];
   if (!$title || !$main_text) die("Please, input all values!");
   $sql = "INSERT INTO posts (title, main_text) VALUES ('$title', '$main_text')";
   if(!mysqli_query($link, $sql)) die("Can't add post");
}
?>
