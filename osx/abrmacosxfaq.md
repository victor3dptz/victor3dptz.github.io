---
layout: page
title: ABRs Mac OS X FAQ: Advanced
---



### Чиним доступ по AFP c классики на 10.4.9 и выше

Останавливаем AFP

В Терминале пишем: 

```shell
sudo defaults write /Library/Preferences/com.apple.AppleFileServer TCPQuantum -int 327680
```

Включаем AFP

Если на Mac OS X Server, то проще:

```shell
sudo serveradmin stop afp
sudo serveradmin settings afp:TCPQuantum = 327680
sudo serveradmin start afp
```

### Эппл Скрипт. Скрипт метронома

Cохранить как программу. При сохранении выбрать Stay Open

Будет бумкать каждые 5 секунд.

```applescript 
global numberOfBeeps
on idle
		beep numberOfBeeps
		return 5
end idle
on run
		set numberOfBeeps to 1
end run
```

### Эппл Скрипт. Цепляем шары с PC

Разумеется, шифрование пароля отключено. В СкриптЭдиторе пишем

```applescript
try
mount volume "smb://username:password@10.0.0.10/Media 1 HD"
end try
```

Сохраняем как программу и имеем щасте. Опять же, username, пароль, адрес пицука и название шары пишем реальные, а не отсюда, где они для примера

### Команды с sudo через Эппл Скрипт

Долго мучился, пока не нашел решение. Писал об этом в хелп мумака, но там запрятали так, что не найдешь. Ну и фих с ним.

Иногда бывает необходимо выполнять повторяющиеся терминальные команды на своем компе от имени root-a. Для этого можно испольновать приведенный ниже эпплскрипт, сохранив его в формате Application как run only (чтоб из него нельзя было увидеть админский пароль) 

```applescript
set LF to ASCII character 10 (1) 
set yourScr to "Ваше_Терминальное_Заклинание_без_слова_sudo" 
set passwordStr to "ВашПароль" as string 
set sudoScr to "sudo " & yourScr & "; sudo -k" (2) 
do shell script "sudo -v" & " << ++" & LF & passwordStr & LF (3) 
do shell script sudoScr (4) 
```

1. * так мы определяем перевод каретки, он же Энтер *
1. * тут мы формируем консольную команду, которая выполнится со словом sudo, а по завершении выполнения системе указывается, что в следующий раз надо давать запрос на ввод пароля после команды с sudo *
1. * тут мы говорим системе, чтобы она ближайшие 5 минут выполняла команды sudo без ввода пароля; при этом, однако вводим пароль как если бы мы это делали вручную*
1. *а тут мы собственно и выполняем сформированную ранее консольную команду*

### Изменение локали
Каждая из трех строк дает свою локаль 

```shell
defaults write 'Apple Global Domain' AppleLocale ru_RU
defaults write 'Apple Global Domain' AppleLocale en_RU
defaults write 'Apple Global Domain' AppleLocale en_EN
```

Это важно при русификации КроссОвера. С полностью английской локалью у меня не получалось преключение языков

Для программ можно пробовать (на примере GyazMail-a) 

```shell
defaults write jp.gyazsquare.GyazMail AppleLanguages '(ru,English)'
```

### Меняем MAC-address

#### В макОС 7-9
Открываем файл System ResEditом Создаём ресурс типа eadr В нём создаём ресурс с ID=номеру NuBus слота, в котором стоит сетевая карта (Если сетевая карта не NuBus, а например PDS, то ID=0) Содержимое ресурса - 6 байт в виде HEX - желаемый MAC-адрес!!!! ВСЁ!!!

#### В Mac OS X
```shell
sudo ifconfig en0 ether aa:bb:cc:dd:ee:ff
```

### Отключаем Дашборд в Тигре

В терминале пишем 

```shell
defaults write com.apple.dashboard mcx-disabled -boolean YES
```

Чтобы снова включить:

```shell
defaults delete com.apple.dashboard mcx-disabled
defaults write com.apple.dashboard mcx-disabled -boolean NO
```

### Отключаем Spotlight в Тигре

В терминале пишем

```shell
sudo pico /etc/hostconfig
```

вслепую пароль, Энтер

Там ищем строку

```
SPOTLIGHT=-YES-
```

и меняем ее на 

```
SPOTLIGHT=-NO-
```

Сохраняемся через Контрол-О и выходим через Контрол-Х

Теперь отключаем индексирование основного диска: 

```shell
sudo mdutil -i off /
```

Удаляем индексы спотлайта с этого диска 

```shell
sudo mdutil -E /
```

Энтер

Прибиваем окончательно базы спотлайта 

```shell
sudo rm -fr /.Spotlight-V100
```

и делаем это с каждым диском

Теперь убираем спотлайт из меню

```shell
sudo mv /System/Library/CoreServices/Search.bundle /System/Library/CoreServices/DisabledSearch.bundle
```

Рестарт

Чтобы снова включить меняем все назад 

### Отключаем невозможность обновлений системы после русификации

На самом деле установке нерусских программ после "русификации" системы средстваи IMC Apple.ru мешает невидимый файлик .AppleTier3Language, спрятаный в невидимой папке. Для его удаления в терминале пишем 

```shell
sudo rm -f /var/db/.AppleTier3Language
```

Энтер, вслепую пароль, энтер.

Теперь можно ставить нерусифицированные программы, оно будет работать.

### Терминал: ловим измененные файлы

```shell
/usr/bin/find ~/Library -mmin -1 
```
Получаем cписок файлофф измененных за 1 (одну) последнюю минуту. И ващще: man find

### Ломаем пароль рута в 10.5 в Single-User
#### Рецепт для 10.5:
```shell
mount -uw /
launchctl load /System/Library/LaunchDaemons/com.apple.securityd.plist
passwd root
```
**Вариант 2**: подгружаем DirectoryServices, как указано выше, после чего 

```shell
dscl . -passwd /Users/root new_password
```

Таким образом можо менять пароль любого юзера

**Примечание**: В 10.4 надо делать так:

```shell
 mount -uw /
 launchctl load /private/etc/mach_init.d/securityd.plist
 passwd root
 ```
 
### Прячем аккаунты в Тигре

Одна из замечательных возможностей OS X заключается в том, что аккаунты пользователей создаются очень легко. И вы можете иметь столько аккаунтов, сколько нужно, например, рабочий аккаунт, аккаунт для разрешения системных проблем, аккаунт для игр в котором выставлено меньшее разрешение монитора и отключена автозагрузка некоторых дополнений, персональные аккаунты для всех членов вашей семьи, и даже гостевой аккаунт для всех остальных пользователей. Это все удобно и хорошо, но появляется другая проблема - бесконечное окно Login Window, перемещаться по которому нужно прокруткой. К счастью, в OS X 10.4 вы можете спрятать аккаунты которые используются редко. 

Чтобы сделать это, придется проделать не очень сложные действия в Терминале. Но в начале, вы должны знать короткие имена всех аккаунтов которые хотите спрятать. Зайдите в System Preferences > Accounts, кликните по имени учетной записи и посмотрите в поле Short Name. Запишите или запомните нужные короткие имена. Откройте Терминал, и введите следующую команду (все в одну строчку):

```shell
sudo defaults write /Library/Preferences/com.apple.loginwindow HiddenUsersList -array -add account_name1 account_name2 account_name3
```

В приведенном примере account_name1 account_name2 account_name3 ? это короткие имена аккаунтов которые нужно спрятать. Таким образом вы можете спрятать так много учетных записей, сколько захотите, только отделяйте их пробелами когда вводите команду. Нажмите ентер когда будете готовы.

Теперь выйдите из системы (меню Яблоко > Log Out), и посмотрите на окно Login Window. Вы заметите два изменения. Первое, имена пользователей которых вы спрятали более не отображаются. И второе: - есть новая запись: "Other" . Кликните на Other и вам предоставится возможность ввести имя пользователя и пароль для любой из спрятанных учетных записей. Аккаунты, спрятанные таким образом, также не будут показываться в меню быстрого переключения пользователей (кроме случая если пользователь в системе). 

Вы можете снова отобразить все имеющиеся учетные записи в окне Login Window, введя в Терминале следующую команду:

```shell
sudo defaults write /Library/Preferences/com.apple.loginwindow HiddenUsersList -array -add 
```

Не указывая никаких имен в параметрах команды, вы сбросите список спрятанных аккаунтов и когда следующий раз будете входить в систему то увидите полный список.

### Интернет-шаринг руками

В этом примере 195.16.153.30 - внешний, полученый через ВПН адрес (ppp0)

Внутренний - en1 192.168.2.1 

сведения об интерфейсах брались тупо из 

```shell
ifconfig -a
```

Для начала врубаем фаервол. 

В /etc/hostconfig из-под sudo -s прописать строчку

```
IPFORWARDING=-YES-
```

Далее пишем (первая строка для смелых и ленивых, не желающих настраивать фаервол)

```shell
root# ipfw add 1200 pass all from any to any 
root# sysctl -w net.inet.ip.forwarding=1
root# ipfw add 1280 divert 8868 all from 192.168.2.1 to any out via en1 
root# ipfw add 1290 divert 8868 all from any to 195.16.153.30 out via ppp0 
root# natd -s -m -u -dynamic -clamp_mss -a 195.16.153.30 -p 8868 
```

ключ -dynamic можно убрать, если тебе при установке соединения назначается статический IP адрес; ключ -u убираешь, если для машин в локальной сети ты назначил адреса не из стандартных диапазонов 192.168.0.0/16, 10.0.0.0/8

### Перекидываем своп виртуальной памяти

Размещение виртуальной памяти указано в /etc/rc

Поэтому редактируем его через

```shell
sudo pico /etc/rc
```

Там ищем 

```
echo "Starting virtual memory"
swapdir=/private/var/vm
```

и меняем swapdir на то, что нам надо. Например

```
echo "Starting virtual memory"
swapdir=/Volumes/swap/vm
```

Диск со свапом можно сделать маленький, например размером с удвоенное количество установленной оперативки.

#### Второй способ.

Создаем соответствующий диск, называем его "vm" и монтируем сразу на место для обычного свопа. 

Для этого сперва узнаем его BSD-название. Можно через

```shell
df -k 
```

Будет, например, disk0s3

Теперь узнаем UUID этого диска: 

```shell
diskutil info disk0s3
```

Будет, например, 4236231D-1117-333F-8899-3235F9B8000E

Зная UUID, редактируем fstab, чтобы наш своповый диск смонтировался куда надо: 

```shell
sudo pico -w /etc/fstab
```

и там прописываем

```
UUID=4236231D-1117-333F-8899-3235F9B8000E /private/var/vm hfs rw 1 2
```

Теория говорит, что вместо опции rw на своп надо ставить sw, тогда строка будет

```
UUID=4236231D-1117-333F-8899-3235F9B8000E /private/var/vm hfs sw 1 2
```

После рестарта наш своп на новом диске, который нам не мешает

В принципе, редактируя fstab, мы можем подмонтировать любой диск при стартапе куда угодно, например диск с домашними папками юзеров сразу в /Users

За наводку с UUID спасибо IGYLA.

Иными словами, man fstab 

### Перетаскиваем положение юзерской папки "tester" загрузившись в Single-User

```shell
mount -uw /
launchctl load /System/Library/LaunchDaemons/com.apple.DirectoryServices.plist
dscl . -delete /Users/tester home
dscl . -create /Users/tester home /Volumes/Home/Users/tester
reboot
```

И домашняя папка пользователя "tester" переехала на диск Home 

Вместо последних трех строк можно написать: 

```shell
dscl . -change /Users/tester home /Users/tester /Volumes/Home/Users/tester && reboot
```

Кстати, чтобы юзера tester сделать админом, надо написать: 

```shell
dscl . -append /Groups/admin GroupMembership tester
```

### Печатаем напрямую в постскрипт или PDD для кварковских PS

Вызовите диалог печати и настройте все необходимые опции

Сохраните пресет, назвав его, скажем, "PS"

Найдите и откройте для редактирования файл "/Users/<имя пользователя>/Library/Preferences/com.apple.print.custompresets.plist"

Найдите там сделанный вами пресет ("PS")

Найдите в опциях этого пресета свойство com.apple.print.PrintSettings.PMDestinationType

Измените значение параметра DestinationType с "1" на "2" (1 = to printer, 2 = to PS file)

Сохраните файл "com.apple.print.custompresets.plist" и закройте его.

### Чиним скорость на SMB

В файл /etc/sysctl.conf добавляем строчку 

```
net.inet.tcp.delayed_ack=0
```

Это даст указание ядру не задерживать пакеты. 

The reason the slow down occurs is that when you are not sending anything to the Samba server, but attempting to copy a huge file from it, your computer will queue up a bunch of acks, and then send them after a bit. This causes the Samba server to stop sending files as fast, and then you end up going only a few kilobytes per second. 

Если вы хотите попробовать, как это работает, а после перезагрузки восстанаовилось в прежнее состояние, то в терминале наберите 

```shell
sudo sysctl -w net.inet.tcp.delayed_ack=0
```

### Включаем ARD через SSH

```shell
/System/Library/CoreServices/RemoteManagement/ARDAgent.app/Contents/Resources/kickstart -activate -configure -access -on -privs -all -restart -agent
```

### Выключаем ARD через SSH
```shell 
/System/Library/CoreServices/RemoteManagement/ARDAgent.app/Contents/Resources/kickstart -deactivate -stop
```

### Русификация терминала

Создай в домашней папке файл с именем ".inputrc" (без кавычек) со следующим содержанием: 

```
set meta-flag on 
set output-meta on 
set convert-meta off 
```

В настройках Terminal выбери кодировку UTF-8 (Window Settings > Display > Сharacter Set Encoding). Выбери подходящий тебе шрифт. 

Можешь поиграться с двумя настройками, которые начинаются на "Wide glyphs...", как тебе удобнее (когда всё остальное настроишь). У меня маркеры (галочки) с них сняты. Введи в командной строке "export LANG=ru_RU.KOI8-R" без кавычек. Всё, работай с русским языком (можешь читать и вводить на русском языке). Неудобства есть, но они терпимы. 

P.S. Дополнительно, чтобы не вводить "export LANG=ru_RU.KOI8-R" в каждой сессии Terminal, можно добавить в файл /etc/profile следующие строки: 

```LANG=ru_RU.KOI8-R 
export LANG
```

#### 2 способ 
1. Поставить кодировку Unicode (UTF8) 
1. Выбрать unicode шрифт (мне нравится Lucida Console с включенным anti-aliasing). 
1. Установить shell для терминала /bin/bash (в Preferences... для терминала или в Netinfo для пользователя). 
1, Создать в домашнем каталоге файл .inputrc , с содержимым: 

```
set meta-flag on
set output-meta on 
set convert-meta off
```

Если использовать терминал для работы с удаленным Linux-сом, и нужен русский (в mutt например), то на стороне Linux-са настройте локаль ru_RU.UTF8 и сделайте "export LANG=ru_RU.UTF8" 

### Автостарт VPN

В /etc/rc.local прописать строчку

```shell
pppd plugin PPTP.ppp remoteaddress <VPN srvr> logfile /var/log/ppp.log user <VPNlogin> password <VPNpasswd> defaultroute usepeerdns persist maxfail 0
```
