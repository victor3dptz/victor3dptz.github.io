---
layout: post
title: Создание iso-образа из папки с именами файлов в русской кодировке для Windows
---

Команда ниже создает iso образ из файлов в папке files. На записанном диске в Windows будут корректные имена файлов.

```shell
genisoimage -input-charset utf-8 -output-charset cp1251 -J -joliet-long -U -o disk.iso ./files
```

Записать полученный образ можно следующей командой

```shell
sudo wodim driveropts=burnfree -eject -dao -v speed=0 dev=4,0,0 disk.iso
```

Вместо `dev=4,0,0` вставить параметры вашего CD-ROM, полученные командой

```shell
sudo wodim -scanbus
```
