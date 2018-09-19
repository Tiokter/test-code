# test-code
Test app (Condi)
## Руководство оператора

Данное Программное обеспечение (ПО) состоит из двух программных модулей:

1. Приложение, в котором разработан внешний вид (графический интерфейс пользователя),
    ориентированного для работы на сенсорном дисплее и предназначенного для управления и контроля
    системой кондиционирования (далее – панель управления);
2. Приложение, имитирующее работу устройства (далее — имитатор).


## 1. Панель управления


###  **_Поле включения/выключения блоков (1, 2, 3) кондиционера_**

```
При нажатии кнопки включения (1, 2, 3) будет подан сигнал имитатору на включение данного блока.
Ниже в окне отображения состояние системы кондиционирования - квадрат, символизирующий данный
блок, станет зелёным, комплексный признак так же отобразится зелёным ( кондиционер работает ).
При выключении кнопки - блок станет красным, если ВСЕ блоки кондиционера тоже выключены, то
комплексный признак так же отобразится красным ( кондиционер НЕ работает ).
```
###  **_Изменение температуры и направления подачи воздуха (угол поворота)_**

```
При нажатии на кнопку будет понижаться значение параметра, при нажатии на повышаться.
o Температура – шаг 0,5 °C, диапазон от - 50° до +80° C
o Угол поворота – шаг 10°, диапазон от 50 до 130°
```

###  Изменение стиля оформления интерфейса: светлый и темный вариант

```
При нажатии на кнопку будет применён тёмный стиль оформления, при нажатии на светлый.
```
###  Настройка шкалы температуры (градусы Цельсия, Фаренгейта, по Кельвину)

```
При нажатии на кнопку на панели инструментов (туул бар) с соответствующим текстом будет произведён
перерасчёт значения текущей температуры в градусы Цельсия, Фаренгейта, или по Кельвину.
Также возможность выбора шкалы реализована через меню : Настройки - Изменение шкалы температуры.
```
###  **_Настройка вывода давления (Па, мм.рт.ст.)_**

```
При нажатии на кнопку на панели инструментов (туул бар) с соответствующим текстом будет произведён
перерасчёт значения текущего давления в Паскали или мм.рт.ст.
Также возможность выбора шкалы реализована через меню : Настройки - Изменение шкалы давления.
```

## 2. Имитатор

```
Включает в себя панель включения блоков кондиционера.
Включённый блок выделяется синим цветом.
А также 4 поля для ввода информации
(температура, влажность, давление и угол поворота).

Значения можно вводить 2-умя способами:
o Нажатием на стрелочки вверх/вниз рядом с соответствующими полями;
o Введением значения с клавиатуры (при нажатии на само поле).
Поле Шаг Диапазон
Температура 0,5 - 50 – +
Влажность 1 0 – 100
Давление 1 700 – 800
Угол поворота 10 50 – 130
```