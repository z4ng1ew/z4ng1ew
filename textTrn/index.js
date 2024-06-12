const textarea = document.querySelector(".text");
const btn = document.querySelector(".btn");
const box = document.querySelector(".box");
const boxTrain = document.querySelector(".boxTrain");
const textTrainPrint = document.querySelector(".textTrainPrint");
const boxfinish = document.querySelector(".boxfinish");
const numberOfMistakes = document.querySelector(".numberOfMistakes");
const numberOftime = document.querySelector(".numberOftime");
const textTrainLeft = document.querySelector(".textTrainLeft");

let textValue = "";
let point = 0;
let err = 0;
let textRem = "";

function textCont() {
  if (textarea.value.length > 0) {
    textValue = textarea.value.trim().replace(/\s{2,}/g, " ");
    box.classList.add("redyText");
    textTrainPrint.textContent = textValue;
    boxTrain.classList.add("boxTrainFlex");
    document.addEventListener("keydown", handleKeyPress); // Изменено на keydown
    count();
  } else {
    textarea.placeholder = "Введите текст)";
  }
}

function handleKeyPress(e) {
  if (e.key === textValue[point] && point < textValue.length) {
    if (textTrainLeft.textContent.length >= 23) {
      textRem = textTrainLeft.textContent.substring(1);
    }
    textTrainPrint.textContent = textValue.substring(point + 1); // Удаление первого символа строки
    textRem += e.key;
    textTrainLeft.textContent = textRem;
    point++;
    if (textTrainPrint.textContent.length === 0) {
      boxTrain.classList.remove("boxTrainFlex");
      boxfinish.classList.add("boxfinishFlex");
      let time = i;
      numberOfMistakes.textContent = `Количество ошибок: ${err}`;
      numberOftime.textContent = `Время: ${time}`;
      return;
    }
    textTrainPrint.style.borderColor = "green";
    textTrainLeft.style.borderColor = "green";
  } else {
    err++;
    textTrainPrint.style.borderColor = "red";
    textTrainLeft.style.borderColor = "red";
  }
}

let i = 0;
function count() {
  i++;
  setTimeout(count, 1000); // задержка 1000 миллисекунд (1 секунда)
}

btn.addEventListener("click", textCont);
