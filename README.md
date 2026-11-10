<h1 align="center">Привет, я Мовсар 👋</h1>
<h3 align="center">Data Analyst · A/B-тесты · Simulation & What-if анализ · ML</h3>

<p align="center">
  <a href="https://t.me/zang1ew"><img src="https://img.shields.io/badge/Telegram-@zang1ew-26A5E4?style=for-the-badge&logo=telegram&logoColor=white"/></a>
  <a href="mailto:z4ng1ew@gmail.com"><img src="https://img.shields.io/badge/Email-z4ng1ew@gmail.com-EA4335?style=for-the-badge&logo=gmail&logoColor=white"/></a>
  <a href="https://www.kaggle.com/nyzprocent"><img src="https://img.shields.io/badge/Kaggle-nyzprocent-20BEFF?style=for-the-badge&logo=kaggle&logoColor=white"/></a>
  <a href="https://huggingface.co/V1ncy"><img src="https://img.shields.io/badge/HuggingFace-V1ncy-FFD21E?style=for-the-badge&logo=huggingface&logoColor=black"/></a>
</p>

---

## 🔍 Обо мне

Дата-аналитик. Превращаю данные в решения: проектирую **A/B-тесты**, пишу **SQL**-витрины, строю **прогнозные модели** и **имитационные модели** для what-if анализа.

- 🧪 **Эксперименты:** дизайн A/B-тестов, MDE и sample size, CUPED, bootstrap, стратификация
- 📐 **Causal inference:** diff-in-diff, synthetic control, propensity score
- 🏭 **Simulation:** дискретно-событийное моделирование (SimPy), поиск узких мест, валидация модели аналитическим расчётом
- 🤖 **ML & LLM:** классификация, прогнозирование, LLM-пайплайны с валидацией выхода кодом
- 🏆 Капитан команды на хакатонах **Ozon Tech «Робозон»** и **«Точка сборки» 2026**
- 🎓 Школа 21 (Сбер): Data Analyst, математическая статистика, ML

---

## 🛠 Стек

**Анализ данных и статистика**

![Python](https://img.shields.io/badge/Python-3776AB?style=flat-square&logo=python&logoColor=white)
![Pandas](https://img.shields.io/badge/Pandas-150458?style=flat-square&logo=pandas&logoColor=white)
![NumPy](https://img.shields.io/badge/NumPy-013243?style=flat-square&logo=numpy&logoColor=white)
![SciPy](https://img.shields.io/badge/SciPy-8CAAE6?style=flat-square&logo=scipy&logoColor=white)
![statsmodels](https://img.shields.io/badge/statsmodels-4051B5?style=flat-square)
![Matplotlib](https://img.shields.io/badge/Matplotlib-11557C?style=flat-square)
![Plotly](https://img.shields.io/badge/Plotly-3F4F75?style=flat-square&logo=plotly&logoColor=white)
![Jupyter](https://img.shields.io/badge/Jupyter-F37626?style=flat-square&logo=jupyter&logoColor=white)

**Базы данных и Big Data**

![SQL](https://img.shields.io/badge/SQL-4479A1?style=flat-square&logo=postgresql&logoColor=white)
![PostgreSQL](https://img.shields.io/badge/PostgreSQL-4169E1?style=flat-square&logo=postgresql&logoColor=white)
![ClickHouse](https://img.shields.io/badge/ClickHouse-FFCC01?style=flat-square&logo=clickhouse&logoColor=black)
![PySpark](https://img.shields.io/badge/PySpark-E25A1C?style=flat-square&logo=apachespark&logoColor=white)

**ML / DL / LLM**

![scikit-learn](https://img.shields.io/badge/scikit--learn-F7931E?style=flat-square&logo=scikitlearn&logoColor=white)
![TensorFlow](https://img.shields.io/badge/TensorFlow-FF6F00?style=flat-square&logo=tensorflow&logoColor=white)
![PyTorch](https://img.shields.io/badge/PyTorch-EE4C2C?style=flat-square&logo=pytorch&logoColor=white)
![HuggingFace](https://img.shields.io/badge/Transformers-FFD21E?style=flat-square&logo=huggingface&logoColor=black)
![Prophet](https://img.shields.io/badge/Prophet-0668E1?style=flat-square)

**Simulation, визуализация, инфраструктура**

![SimPy](https://img.shields.io/badge/SimPy-DES-2E8B57?style=flat-square)
![Streamlit](https://img.shields.io/badge/Streamlit-FF4B4B?style=flat-square&logo=streamlit&logoColor=white)
![FastAPI](https://img.shields.io/badge/FastAPI-009688?style=flat-square&logo=fastapi&logoColor=white)
![Docker](https://img.shields.io/badge/Docker-2496ED?style=flat-square&logo=docker&logoColor=white)
![Git](https://img.shields.io/badge/Git-F05032?style=flat-square&logo=git&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=flat-square&logo=linux&logoColor=black)

---

## 🚀 Избранные проекты

### 🏭 [Имитационная модель сортировочного центра · Ozon Tech «Робозон»](https://github.com/z4ng1ew/robot-docker-simulation-blender)
**Капитан команды.** Дискретно-событийная модель сортировки на **100 000 товаров/час** по 400 направлениям.
- 8 what-if сценариев: пик +15%, отказы роботов и портов, перекос спроса, стресс-тест до предела ~109 000 шт/ч
- **Валидация** модели независимым аналитическим расчётом, отклонение ≤ 3,3%
- Метрики: пропускная способность, p95 времени обработки, точность 99,958%
- Дашборд результатов на Streamlit, полная воспроизводимость в Docker

`Python` `SimPy` `Pandas` `Streamlit` `Docker` `what-if анализ`

### 📞 [Здравушка: голосовой ИИ-ассистент регистратуры · хакатон «Точка сборки» 2026](https://github.com/z4ng1ew/Zdravushka)
Ассистент, который принимает звонки в поликлинику: запись, перенос, отмена, напоминания.
- **Анализ данных заказчика:** 17 772 звонка и 35 470 записей. Нашёл 20,7% пропущенных звонков и 11,5% неявок, на этом построена бизнес-логика продукта
- Медианная задержка ответа снижена с 4–11 с до **~2,4 с**
- LLM только классифицирует фразу в JSON, решения принимает код: модель не может «выдумать» врача или время
- **119 автотестов**, отказоустойчивость, соответствие 152-ФЗ

`Python` `FastAPI` `LLM` `Whisper` `TypeScript` `Asterisk`

### 🪪 [Классификация документов клиентов банка · CNN + Transfer Learning](https://github.com/z4ng1ew/Bank-document-classifier)
Автоматизация KYC: определение типа документа по фото на датасете MIDV-500.
- Сравнение трёх архитектур: CNN с нуля, MobileNetV2, ResNet50
- Лучшая **accuracy 99,24%**, инференс < 100 мс на GPU
- EDA, стратифицированный сплит, confusion matrix, воспроизводимость (seed)

`TensorFlow` `Keras` `scikit-learn` `EDA` `Computer Vision`

### 💳 [Прогнозирование кредитного дефолта · бинарная классификация](https://github.com/z4ng1ew/lab4.1-4.3_5.1-5.2_plus_final_certification/tree/develop/4.3%20-%20credit-default-prediction)
Оценка вероятности дефолта клиента на датасете UCI Credit Card.
- EDA и feature engineering
- Работа с **несбалансированными классами**: SMOTE
- Сравнение Logistic Regression, Random Forest и XGBoost по **ROC-AUC** и confusion matrix

`scikit-learn` `XGBoost` `imbalanced-learn` `ROC-AUC` `credit risk`

### 📈 [Статистическое моделирование · statsmodels](https://github.com/z4ng1ew/statistical-modeling-and-data-analysis)
Линейная регрессия с интерпретацией R², p-значений и коэффициентов, плюс EDA реального датасета.

`statsmodels` `pandas` `регрессионный анализ`

### 🗄 [SQL Bootcamp · PostgreSQL от основ до DWH](https://github.com/z4ng1ew/sql-bootcamp)
Курс SQL в Школе 21 (Сбер): 10+ модулей задач на PostgreSQL.
- **Оконные функции, CTE, рекурсивные запросы:** задача коммивояжёра (TSP) решена чистым SQL через recursive CTE
- **OLAP и DWH:** агрегации, витрины, основы хранилищ данных, snapshots
- **Производительность:** индексы, `EXPLAIN ANALYZE`, уровни изоляции транзакций
- Функции и процедуры на PL/pgSQL

`PostgreSQL` `SQL` `window functions` `recursive CTE` `OLAP` `DWH`

### 🧭 [Maze AI · Reinforcement Learning](https://github.com/z4ng1ew/py-maze-ai)
Генерация лабиринтов (алгоритм Эллера) и пещер (клеточные автоматы), агент на **Q-learning** ищет кратчайший путь. Десктопный и веб-интерфейс.

`Python` `Q-learning` `RL` `алгоритмы`

---

## 📊 GitHub-статистика

<p align="center">
  <img height="160" src="https://github-readme-stats.vercel.app/api?username=z4ng1ew&show_icons=true&theme=tokyonight&hide_border=true"/>
  <img height="160" src="https://github-readme-stats.vercel.app/api/top-langs/?username=z4ng1ew&layout=compact&theme=tokyonight&hide_border=true"/>
</p>

<p align="center"><i>Открыт к предложениям: Data Analyst · Product Analyst · A/B-тесты · Ad-hoc аналитика</i></p>
