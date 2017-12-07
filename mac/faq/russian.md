---
layout: page
title: Использование русского языка
---

### В каком диапазоне находятся FONT ID шрифтов для кириллического скрипта?

Для кириллических шрифтов FOND ресурс шрифта лежит в диапазоне от 19456 до 19967.

### Есть вордовский файл сделаный в WinWord 6, а теперь его требуется перенести его на Мак.

Идешь на http://www.macintosh.ru и выбираешь на странице download. В этом списке скачиваешь программу называется типа Word 6.0.1 Patch - увидишь, их там немного.

На Маке ставишь по новой Word, и применяешь оный патч. Опа! Теперь MS Word корректно открывает документы, подоготовленные на Win.

Только для того, чтобы увидеть нормально русские буквы надо будет сменить шрифт в документе с виндовозного на кириллический маковский, например, Латинский.

Word 98 может корректно открывать файлы WinWord 6, содержащие русские буквы, без каких-либо дополнительных операций.

### Зачем нужен Language Kit Register?

UCS Setup (до 1.5.3) не дает полноценной регистрации по скриптам - Language Kit Register делает это не в пример лучше, особенно в тяжелых случаях типа FreeHand 8-9. Рекомендовано самими производителями UCS :)

### Как в Word 5 открыть полученный с Windows RTF-файл?

Если получен RTF файл с Windows, то его следует открывать, предварительно пропустив через Simple Convertor или Code Master 2.0.

### Как деинсталлировать Dialect?

Его, действительно, простым удалением из системной папки не выкинуть, но и систему сносить не надо.

Для удаления следов диалекта нужно поместить пульт диалекта в папку пультов (если он оттуда уже убран), перезагрузить систему и, открыв пульт диалекта выключить его. Потом можно убрать его из системной папки и перезагрузить машину.

### Как изменить FONT ID шрифтов, чтоб он попал в кириллический диапазон?

Воспользуйтесь для этого программой ReIDer от одного из создателей UCS Олега Козлова - http://www.apple.ru/fonts/FontsReIDer1.0.sit. Просто натащите на эту программку шрифты и ReIDer поменяет их ID на кириллические.

### Как нормально прочесть кириллические документы, набранные в Office 98 на Макинтоше без кириллического скрипта?

Документ ворда 98, созданный без использования русских языковых ресурсов (скрипта, шрифтов и т.п.) нужно открыть на Маке, где нет русского скрипта в системе, в ворде 98 и сохранить этот докумет, например, как ворд 6.0 Потом открытьэтот документ на маке, где есть русский скрипт в системе.

### Как перенести на Windows документ, сделанный в Word 5?

Этот документ следует сохранить формате RTF и пропустить через Simple Convertor или Code Master 2.0.

### Как пользоваться русскими названиями слоев в ImageReady? (и не только)

Вспомнилось мне, что в макхэлпе обсуждалась подобное с iTunes. Кто-то, не помню кто, посоветовал открыть ResEdit'ом программу и убить в ней ресурс FOND. Мол, в нем все дело, а без оного прога будет использовать системные шрифты. Теперь ImageReady отлично обзывает русскими буквами слои. И никаких глюков пока не наблюдается. Мораль: может таким макаром и решать подобные проблемы, а не заморачиваться всякими подстановками? Простите за многословие! 

### Как сделать так чтоб Photoshop 5.02 под UCS 1.52 мог в названиях файлов и слоев использовать русские буквы?

Открываешь UCS Setup и в разделе "Подстановки" устанавливаешь для Photoshop использование Романского скрипта.

Далее идешь в Photoshop, нажимаешь 4 клавиши Ctrl+Option+Cmd+F. Откроется окно подстановки шрифтов. Нажимаешь на кнопку "Add" и для подстановки вместо шрифтов System Font, Application Font и .Espiago указываешь русскоязычные аналоги.

### Можно ли установить UCS на Mac OS 9?

Ставишь 1.5.2, как обычно, и потом заменяешь пульт и расширение на 1.5.3. Да, language kit extension больше не нужен - уже встроен по умолчанию.

Кстати, сейчас есть уже UCS 2

### Нужно ли что-то дополнительно для корректной работы MS Word 98, если в системе установлен UCS?

К сожалению да, если есть желание, чтобы ворд'98 корректно открывал файлы старых вордов (например, маковской 5-ки). Библиотечка зовется (если не путаю) Dialect Office 98 Patch и должна находиться в той же папке, что и ворд'98. Есть одно "Но" при таком раскладе -- для безгеморройного использования, эта библиотека должна браться из диалекта 4.0 (или 4.0.1). Hачиная с какой-то версии, в этой библиотеке присутствует код, проверяющий наличие Диалекта в системе. Если Диалект не стоит, то и библиотека не работает (хотя Диалект ей не нужен). Сей факт мы обнаружили с Алексеем Дьяковым совершенно случайно, когда кто-то начал ему жаловаться на проблемы ворда и UCS'а. Кстати, этот самый Dialect Office 98 Patch вещь весьма элегантная и простая - уж на что я Диалект не люблю, но эта штука мне понравилась. Досадно, что они решили вбить такой "костыль", конечно, но что делать - единственный коммерческий русификатор, толкают... :)))

### Получил текстовый файл в какой-то непонятной кодировке. Как его прочесть?

Наиболее совершенным конвертором русскоязычных текстов в настоящее время является Code Master 2.0 Олега Козлова. В нем встроены 18 кодировок, существует возможность автораспознавания исходной кодировки (и даже возможность"расшифровки" текста после трех последовательных ошибочных перекодировок), работа с RTF, а также еще ряд полезных моментов.

### Почему мне не удается создать в одной папке файлы или папки с именами "М" и "Б"?

В HFS+ имя хранится в Unicode. Когда ты создаёшь файл в Finder, он конвертирует его имя в Unicode в соответствии с тем, к какому скрипту относится его шрифт (или текущая клавиатура, точно не знаю). Соответственно, если шрифт/скрипт не те, он неправильно перекодирует имя. Потом, когда проверяет, есть ли уже файл, он делает case-insensitive проверку, а Б и М это как раз большая и маленькая "A с кружком" в романских шрифтах. Если создавать файл не в Finder, а из других программ, то тут всё зависит от того, как они написаны. Некоторые создают файлы всегда в системном скрипте, т.е. им для создания таких папок нужно, чтобы системный скрипт был кириллический.

### Почему Photoshop 6 некоторыми шрифтами по-русски набирает, а некоторыми -- нет?

Нужно установить русскую раскладку в романский скрипт (например из cRussify или раскладка US-Russian от UCS), и с ее помощью легко набирается текст шрифтами с любыми некириллическими ID в Photoshop, Illustrator и всех прочих программах, ориентированных на "правильную" работу со шрифтами.

Другой вариант -- сменить ID этих шрифтов на принадлежащий к кириллическому диапазону с помощью Font ReIDer.

### Что можно использовать, чтобы работать с русским текстом в некириллической Mac OS?

Корректно установить в систему кириллический скрипт может Ultimate Cyrillic Script (UCS). Кроме собственно скрипта он добавляет еще несколько чрезвычайно приятных вещей. Очень рекомендую.

Хотя, если Вы - любитель острых ощущений, можете воспользоваться "руссификаторами", обманывающими (или пытающимися обмануть ;-) ) Систему (cRussify, первые версии Dialect'а и т.п).

Замечу, что в состав Mac OS 9 включены Language Kit'ы (и кириллический в том числе)

### Что сделать, чтобы iTunes 2 правильно показывал русские теги в MP3?

Выяснилось что перекодировку iTunes выполняет в соответствии с текущей кодовой страницей, - если основной скрипт Кирилик, то всё перекодируется и сортируется нормально. Подстановка скрипта UCS не прокатывает. Перекодировка ведётся Text Encoding Converter-ами ОС. Их патчить не удается (машина перестаёт грузиться при малейшем изменении). Данные тэгов хранятся в Unicode. Если использовать патч, то в перекодированных тэгах окажется просто испорченный юникод, который никто уже, кроме запатченного iTunes, не поймёт. Использование патча приводит к тому, что русский текст "АБВ" преобразуется iTunes в "0080 0081 0082", то есть плосская, русская, маковская раскладка лоб-в-лоб перенесённая в "западную" страницу юникода. Это, сами понимаете, не русский. Русские "АБВ" в юникоде выглядят как "0410 0411 0412", и начиная с буквы "Р" русская раскладка пересекает символы пунктуации и цифры, и захватывает половину заглавных английских литер западной таблицы. То есть, простая подмена таблиц в юникодной системе не пройдёт. Вывод: либо ставьте основным скриптом в UCS Кирилик и пускайте воспроизведение всех русских песен подряд (там сначала всё в давно полюбившихся по микрософтовскии продуктам вопросиках будет, но после первого прослушивания вопросы заменятся нормальным русским текстом), либо придётся довольствоватся iTunes 1.1.

