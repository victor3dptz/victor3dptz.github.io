---
layout: page
title: Сети. Прочее
---

### Можно ли подключится к FIDO на Макинтоше?

Да. До последнего времени наиболее популярным вариантом для пойнта был комплекс программ "от Алексея Дьякова":

* Charon 0.9.9. (мейлер);
* MacWoof 1.5.3 (редактор);
* ZipIt (архиватор).

Свое неофициальное название набор получил из-за того, что основная заслуга в его адаптации принадлежит Алексею Дьякову (2:5020/180.11). Им созданы файлы клавиатур и шрифтов предназначенных для работы с альтернативной кодировкой русских букв, принятой в FIDO, а также некоторые важные патчи для MacWoof.

Сейчас наибольшее распространение получил пакет Ravel, разработанный питерским программистом Кириллом Мурзиным. Свободно распространяемая версия Lite полностью обеспечивает нужды пойнта. Существует и полная версия... но это - особый разговор.

### Что такое BinHex?

Это аналог UUencode/UUdecode. Для передачи двоичных файлов в текстовом виде. Чтобы маковские файлы нормально передавать. Он внутри хранит длинное имя, тип, создатель, Mac-овские атрибуты файла. Не использует коды <32 и >127.