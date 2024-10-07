<!DOCTYPE html>
<html lang="ru">
<head>
   <meta charset="UTF-8">
   <meta http-equiv="X-UA-Compatible" content="IE=edge">
   <meta name="viewport" content="width=device-width, initial-scale=1.0">
   <title>Вход</title>
   <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.3.1/dist/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
</head>
<body>
   <div class="container mt-4" align="center">
       <h1>Вход</h1>
       <form method="POST" action="/login.php">
           <input class="form-control" type="text" name="username" placeholder="Username">
           <input class="form-control" type="password" name="password" placeholder="Password">
           <br>
           <button type="submit" class="btn btn-success" name="submit">Продолжить</button>
       </form>
   </div>
</body>
</html>
 
<?php
require_once('db.php');
 
if (isset($_COOKIE['User'])) {
    header("Location: index.php");
}
 
$link = mysqli_connect('127.0.0.1', 'root', 'tragernout', 'website');
 
if (isset($_POST['submit'])) {
   $username = $_POST['username'];
   $pass = $_POST['password'];
   if (!$username || !$pass) die("Please, input all values!");
   // SQL-запрос, который возвращает всех пользователей с именем и паролем, которые
   // были использованы в форме логина
   $sql = "SELECT * FROM users WHERE username='$username' AND pass='$pass'";
   $results = mysqli_query($link, $sql);
   // Если результаты были найдены, то устанавливается куки файл, который действует один час,
   // а затем идет редирект с помощью функции header на файл profile.php
   if (mysqli_num_rows($results) == 1) {
     setcookie("User", $username, time()+3600);
     header('location: profile.php');
   } else {
       echo "Wrong username or password";
   }
}
?>
