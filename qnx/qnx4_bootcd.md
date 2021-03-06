---
layout: page
title: Создание bootable CD для QNX 4.25
---

В форуме несколько раз возникал вопрос о создании загрузочного CD. Особого внимания на него не обращал, пока сам не столкнулся с этой проблемой. Решение найдено следующее, возможно, чего–то где-то я не понял, но схема работает. Итак, для начала нам понадобится Windows с какой - нибудь утилитой для записи на CD, умеющей разворачивать на болванку ISO – образ, так как именно с ISO – образами мы будем работать (я использовал Adaptec Easy Creator 4.01), утилита mkisofs (можно взять на ftp://ftp.qnx.com/usr/free/qnx4/os/utils/misc/mkisofs-1.11.1.tgz, болванка CD-RW, CD-R привод, и немного терпения.

Первым делом нужно создать каталог и переписать в него программы, которые Вы хотели бы видеть на CD (каталог назовем для примера /qnx_cd_boot ). Обычный минимум это каталоги: /bin, /usr, /etc. Не забудьте /usr/lib/terminfo. В принципе, болванка большая, как правило, больше всего QNX со всеми Watcom, TCPIP, Apache, архивами, и т.д., так что переписывайте, не стесняйтесь. Линки оставляйте линками, как файлы переписывать не надо.

Следующим шагом необходимо создать загрузочный образ для записи на CD. Нужно создать файл /boot/build/boot_cd. Для его изготовления можно использовать следующий пример (взял с http://www.qnx.com/support/sd_bok/solution.qnx?10345 и чуть подправил):

```
sys/boot
$ boot -v

sys/Proc32
$ Proc32 

sys/Slib32
$ Slib32

sys/Slib16
$ Slib16

/bin/Fsys
$ Fsys -r 1024

/bin/Fsys.eide
$ Fsys.eide -v

/bin/Iso9660fsys
$ Iso9660fsys /=/dev/cd0

/bin/sinit
$ sinit -s /bin/sh -i /etc/config/sysinit TERM=qnx
```

Дальше – как обычно, поднимаемся в /boot, делаем `make b=boot_cd`, получаем файл - загрузочный образ /boot/images/boot_cd. Кто делал это один раз – повторит с закрытыми глазами. Главное – не переусердствовать, полученный файл не должен превышать 640 К. Так что в файл /boot/build/boot_cd можно добавить еще пару строчек типа Fsys.floppy, если очень надо, и на этом остановиться. Внимательно смотрите на сообщения, выдаваемые при make – сообщений ‘warning’ быть не должно. Тут есть неприятный момент. Дело в том, что по документации файл .boot в QNX 4.25 не может быть больше 640 К, на самом деле уже при 512 К могут начаться проблемы. При загрузке появляется сообщение ‘missing operation system’ со всеми вытекающими последствиями. Ну, это отдельная тема для разговора. Так что будьте бдительны.

Для использования mkisofs нужен образ загрузочной дискеты. Я опишу способ, проверенный лично мною, вы добавьте еще. Образ должен быть объемом 1,44 Мб (возможны и другие размеры, но остановимся на этом). Берем чистую дискету, отформатированную и инициализированную под QNX, монтируем (например, точка монтирования /dev/fd0, устройство /fd0), делаем `cp /boot/images/boot_cd /fd0/.boot` . Теперь – с дискеты получаем образ : `cat /dev/fd0 > /qnx_cd_boot/boot.flp` .

Далее – подправить для своих нужд файл /qnx_cd_boot/etc/config/sysinit – именно он будет загружаться при запуске системы с CD, и можно переходить непосредственно к созданию ISO – образа диска при помощи утилиты mkisofs. Это стандартная утилита для Unix и Linux систем, по ней есть manpages (например, http://www.fokus.gmd.de/research/cc/glone/employees/joerg.schilling/private/man/mkisofs-1.13.html) – многое из описанного там не работает в QNX, но это лучше, чем тот набор символов, который появляется при запуске mkisofs в QNX. С другой стороны, есть исходники, так что – дерзайте. Итак, mkisofs скачали, распаковали, для простоты лучше переписать исполняемый файл mkisofs в / . Далее набираем `mkisofs –b boot.flp –o cd_image.iso –l –R /qnx_cd_boot` , где boot.flp – полученный нами образ дискеты (1,44Мб), cd_image.iso – имя файла образа CD, -l(el) – сохраняют файлы и каталоги, начинающиеся с точки (.photon), -R – сохраняет символьные линки. Этих ключей вполне достаточно для создания полноценного образа CD. Полученный файл cd_image.iso, используя Fatfsys, переписать в windows и в Вашей программе для записи CD сделать File->CreateCDFromISOImage, а в BIOS – загрузка с CD-ROM, естественно. Болванка с QNX готова, можно загружаться. Несложные манипуляции со скриптами позволяют автоматизировать процесс установки QNX на винчестер, поле для творчества здесь безгранично.

Если все прошло гладко, и наш труд венчает строка login, то это еще не повод для отдыха, а только промежуточная победа. Хочется mqc, vp, Photon, наконец. mqc не запускается – в процессе работы он создает временные файлы, а у нас файловая система read-only. Для этого создаем RAM диск (в загрузчике Fsys –r1024, 1024К – объем виртуального диска). В sysinit инициализируем RAM – диск, монтируем как /ram , в нем создаем каталоги /ram/etc/config/trap – для файла crt графического драйвера Photon, /ram/tmp – для временных файлов mqc. В /etc/profile прописываем TMPDIR=${TMPDIR:-/ram/tmp}. Теперь после перезагрузки mqc будет запускаться без проблем и временные файлы записывать в /ram/tmp. Можно с CD загрузить Photon, без обращения к винчестеру. Например, сделать демонстрационный CD, демонстрирующий ваши программы, написанные под Photon. Основная проблема здесь – файл /etc/config/trap/crt.# . Я решил эту задачу, что называется, в лоб, наверняка есть более изящное решение. Изначально каталог /etc/config/trap в каталоге /qnx_cd_boot создается как символьный линк на такой же каталог в RAM. Например, /qnx_cd_boot/etc/config/trap -> //1/ram/etc/config/trap. Таким образом, получаем в нашей файловой системе каталог, в котором можем создавать, редактировать и удалять файлы. Далее – для демо – диска не очень подходит окошко, которое выводит программа phgrafx при первом запуске Photon. Для этого я немного подправил /qnx_cd_boot/qnx4/photon/bin/ph – скрипт, который и запускает Photon. В нем закомментировал все строчки, содержащие команду phgrafx, а лучше – всю конструкцию if…else..fi, в котрой проверяется, вызывать эту команду или нет. Все будет работать, но в разрешении 640*480, что не очень хорошо. Я за рабочее принял разрешение 1024*768, полагая, что большинство мониторов и видеокарт покажут такую картинку без труда. Для этого, пройдя по всему скрипту /qnx_cd_boot/qnx4/photon/bin/ph, находя команду crttrap, добавляем ей параметр –g1024,768 (crttrap –g1024*768 trap и т.д., для crttrap safe можно параметры не добавлять). Все. Собираем все на CD, перегружаемся, если все правильно сделали, то радуемся.Проблемы возникают с новыми видеокартами, на которые нет драйверов в QNX 4.25E.

Надеюсь, у Вас все получится, возможно, не с первого раза, но для чего же тогда придумали CD-RW?
