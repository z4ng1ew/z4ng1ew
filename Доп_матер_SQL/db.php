<?php
 
// Тут мы объявляем переменные, которые будут использоваться для подключения
// к MariaDB
$servername = "127.0.0.1";  // IP, на котором работает MariaDB
$username = "root";  // Имя пользователя
$password = "tragernout";  // Пароль
$dbName = "website";  // Название базы данных
 
// Подключаемся к MariaDB
$link = mysqli_connect($servername, $username, $password);
 
if (!$link) {
 // В случае неуспешного подключения используем die и выводим ошибку
 die("Connection failed: " . mysqli_connect_error());
}
 
// Данный SQL-запрос означает "СОЗДАТЬ ТАБЛИЦУ, ЕСЛИ ЕЁ НЕ СУЩЕСТВУЕТ"
$sql = "CREATE DATABASE IF NOT EXISTS $dbName";
 
// Выводим сообщение об ошибке, если не удалось создать базу данных
if (!mysqli_query($link, $sql)) {
 echo "Can't create database";
}
 
// Закрываем соединение с MariaDB, чтобы потом уже подключиться к самой БД
mysqli_close($link);
 
// Подключаемся к базе данных "website"
$link = mysqli_connect($servername, $username, $password, $dbName);
 
// SQL-запрос, который создает таблицу users, если её не существует
// id - целочисленный тип данных, который с каждой новой записью
// увеличивается на 1 и являвется основным ключом.
// username - имя пользователя - максимальная длина 50 различных символов
// email - электронная почта - максимальная длина 50 различных символов
// pass - пароль - максимальная длина 50 различных символов
$sql = "CREATE TABLE IF NOT EXISTS users(
   id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
   username VARCHAR(50) NOT NULL,
   email VARCHAR(50) NOT NULL,
   pass VARCHAR(50) NOT NULL
)";
 
// Выполняем запрос и в случае неудачи выводим ошибку
if(!mysqli_query($link, $sql)){
   echo "Can't create table users";
}
 
// Тут также, как и с запросом выше
$sql = "CREATE TABLE IF NOT EXISTS posts(
 id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
 title VARCHAR(20) NOT NULL,
 main_text VARCHAR(400) NOT NULL
)";
 
if(!mysqli_query($link, $sql)){
 echo "Can't create table posts";
}
 
// Закрываем соединение с БД
mysqli_close($link);
?>
