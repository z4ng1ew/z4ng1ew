<?php
// Опять подключаемся к БД
$link = mysqli_connect('127.0.0.1', 'root', 'tragernout', 'website');
 
// Берем значения id из GET-запроса, то есть то, что лежит в URL в ?id=<значение>
$id = $_GET['id'];
// SQL-запрос, который ищет в таблице постов пост со значением id из URL
$sql = "SELECT * FROM posts WHERE id=$id";
// Результат запроса
$res = mysqli_query($link, $sql);
// Достаем значения из $res и отправляем их в переменные $title и $main_text
$rows = mysqli_fetch_array($res);
$title = $rows['title'];
$main_text = $rows['main_text'];
?>
 
<!DOCTYPE html>
<html lang="ru">
<head>
   <meta charset="UTF-8">
   <meta http-equiv="X-UA-Compatible" content="IE=edge">
   <meta name="viewport" content="width=device-width, initial-scale=1.0">
   <title>Пост</title>
   <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.3.1/dist/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
</head>
<body>
   <div class="container mt-4" align="center">
       <?php
       // Выводим то, что вернул SQL-запрос
       echo "<h1> $title </h1>";
       echo "<p> $main_text </p>";
       ?>
   </div>
</body>
</html>
