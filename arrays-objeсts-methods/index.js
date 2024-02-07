


// Дан массив строк, представляющих собой даты в формате "ГГГГ-ММ-ДД" (например, ["2023-01-15", "2023-02-20", "2023-03-25"]). Создайте новый массив, содержащий эти даты в формате "ДД.ММ.ГГГГ" (например, ["15.01.2023", "20.02.2023", "25.03.2023"]).

//через reverse


let data = ["2023-01-15", "2023-02-20", "2023-03-25"];

let dataReverses = [...data].reverse();

let formattedDates = dataReverses.map(date => {
    let [year, month, day] = date.split("-");
    return `${day}.${month}.${year}`;
});

console.log(formattedDates);







// Решение задачи


let data1 = ["2023-01-15", "2023-02-20", "2023-03-25"];

let formattedDates1 = data1.map(date => {
    let [year, month, day] = date.split("-");
    return `${day}.${month}.${year}`;
});

console.log(formattedDates1);







// Дан массив строк, представляющих собой телефонные номера в формате "XXX-XXX-XXXX" (например, ["123-456-7890", "987-654-3210", "555-123-4567"]). Создайте новый массив, содержащий эти номера в формате "(XXX) XXX-XXXX" (например, ["(123) 456-7890", "(987) 654-3210", "(555) 123-4567"]).



let numbers = ["123-456-7890", "987-654-3210", "555-123-4567"];

let formattedNumbers = numbers.map(number => {
    let [one, two, three] = number.split("-");
    return `(${one}) ${two}-${three}`;
});

console.log(formattedNumbers);






// Дан массив цен. Тип значения number. Сформировать на его основании новый массив, где значения будут вида ‘100 р’ (цена и знак рубля, в виде строки) [100, 150, 200, 250]

let price = [100, 150, 200, 250];

let formattedprice = price.map(costs =>  `${costs} ₽`);


console.log(formattedprice);


//Использовал короткую форму записи стрелочной функции, которая подходит для случаев, когда тело функции состоит из одного выражения, как в вашем случае.


// .map(): Это метод массива в JavaScript, который создает новый массив, применяя указанную функцию к каждому элементу оригинального массива.

// costs => ${costs} ₽': Это стрелочная функция (arrow function). Она принимает один аргумент, который мы назвали costs. Затем используется шаблонная строка (выражение в обратных кавычках ``) для создания строки, включающей значение элемента массива (costs) и символ "₽".

// .map(costs => ${costs} ₽);: Этот вызов метода .map() применяет указанную функцию для каждого элемента массива price. Для каждого элемента создается новая строка вида 'значение ₽'.

// Итак, в результате этой операции мы получаем новый массив formattedprice, содержащий строки с ценами и символом "₽", соответствующим каждому элементу оригинального массива price.
































// Для того чтобы преобразовать цифровой тип данных (например, число) в строковый, вы можете воспользоваться методом преобразования типов, таким как toString() в JavaScript. Вот пример:


let numbers1 = [42, 43, 44, 45];

let formattedNumbers1 = numbers1.map(number => `${number} ₽`)



console.log(formattedNumbers1); // Выведет строку ["42 ₽", "43 ₽", "44 ₽", "45 ₽"].

// В данном примере переменная stringNumber содержит строковое представление числа 42. Вы можете использовать этот метод для преобразования чисел в строки.

// Если у вас есть другой тип данных, дайте знать, и я предоставлю более конкретный пример.















//ЗАДАЧА № 2


// Дан массив пользователей. Каждый пользователь представлен в виде массива, вида [‘alex’, 32]. Первое значение – имя (строкой), второе возраст, числом. Сформировать на его основе массив, где останутся только пользователя, старше 18 лет. [ [‘alex’, 32], [‘tomas’, 17], [‘olga’, 14], [‘andre’, 24] ] 



let people = [['alex', 32], ['tomas', 17], ['olga', 14], ['andre', 24]];

const ageVerification = people.filter(person  => person [1] >= 18);



console.log(ageVerification);

//ageVerification - массив, где останутся только пользователя, старше 18 лет







//2-ой способ решения. Через  деструктуризацию массива



let people1 = [['alex', 32], ['tomas', 17], ['olga', 14], ['andre', 24]];

const ageVerification1 = people1.filter(([_, age]) => age >= 18);

console.log(ageVerification1);


//ageVerification - массив, где останутся только пользователя, старше 18 лет. Также использована стрелочная функция с неявным возвращением (=> age >= 18), чтобы сократить запись. В данном коде использована деструктуризация в параметре функции filter, 













//Другая задача № 2.1



const mansAndGirls = [ 
    ['john', 8],
    ['emily', 22],
    ['peter', 5],
    ['lisa', 0],
    ['mike', 18]
]


const filterMansAndGirls = mansAndGirls.filter(mansAndGirls => mansAndGirls[1] >= 18 );


console.log(filterMansAndGirls);







//2-ой способ решения. Через  деструктуризацию массива


// Деструктуризация массива в JavaScript - это специальный синтаксис, который позволяет извлекать значения из массива и присваивать их переменным с использованием более компактного и удобного синтаксиса.





const mansAndGirls1 = [ 
    ['john', 8],
    ['emily', 22],
    ['peter', 5],
    ['lisa', 0],
    ['mike', 48]
]



const filterMansAndGirls1 = mansAndGirls1.filter(([name, age]) => age >= 18 && age <= 40);

console.log(filterMansAndGirls1);








// Задача № 3






let menu = [ 
    { title: "пицца", price: 200 }, 
    { title: "баранина", price: 300 }, 
    { title: "креветки", price: 400 } 

];


let allMenuPrice = 0;


for (let menuItem of menu){
    allMenuPrice += menuItem.price;
}



console.log(totalPrice);




// allMenuPrice += menuItem.price; - это как сказать компьютеру: "Возьми текущую сумму (allMenuPrice), добавь к ней цену текущего товара (menuItem.price), и сохрани результат обратно в переменной allMenuPrice".
// В каждой итерации цикла строка allMenuPrice += menuItem.price; увеличивает allMenuPrice на значение цены текущего товара menuItem.price. 
//После завершения цикла allMenuPrice содержит общую стоимость всех товаров в массиве menu.


// ЗАДАЧА № 3.1


let people2 = [
{ name: 'Игорь', age: 100 },
{ name: 'Семёе', age: 50 },
{ name: 'Oleg', age: 0 }
];


let all = 0;


for (let people0 of people2){
    all += people0.age;
}



let averageAge = all  / people2.length;
console.log(averageAge);