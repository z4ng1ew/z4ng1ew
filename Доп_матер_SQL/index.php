<!DOCTYPE html>
<html lang="ru">
<head>
   <meta charset="UTF-8">
   <meta http-equiv="X-UA-Compatible" content="IE=edge">
   <meta name="viewport" content="width=device-width, initial-scale=1.0">
   <title>Главная страница</title>
   <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.3.1/dist/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
</head>
<body>
   <div class="container mt-4" align="center">
       <h1>Главная страница</h1>
       <?php
       // Тут мы добавляем условную конструкцию, которая проверяет то, авторизован ли пользователь или нет
       // Если пользователь не авторизован, то ему будет предложено зарегистрироваться или войти
       if (!isset($_COOKIE['User'])) {
       ?>
           <a href="/registration.php">Зарегистрируйтесь</a> или <a href="/login.php">войдите</a>, чтобы просматривать контент!
       <?php
       // Если авторизован, то он увидит посты
       } else {
           // Уже знакомая вам функция подключения к БД
           $link = mysqli_connect('127.0.0.1', 'root', 'tragernout', 'website');
          
           // SQL-запрос, который получает все посты, которые написали пользователи
           $sql = "SELECT * FROM posts";
           $res = mysqli_query($link, $sql);
           // Вывод всех постов в виде ссылок
           while ($rows = mysqli_fetch_array($res)) {
               echo "<a href='/posts.php?id=" . $rows["id"] . "'>" . $rows['title'] . "</a><br>";
           }
       }
       ?>
   </div>
</body>
</html>
