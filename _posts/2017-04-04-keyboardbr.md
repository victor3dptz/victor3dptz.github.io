---
layout: post
title: International (Brazilian) keyboard configuration
---

Add pt_BR.UTF-8 locale:

```shell
sudo dpkg-reconfigure locales
```

Edit file /etc/default/keyboard

```
XKBMODEL="pc105"
XKBLAYOUT="us,ru"
XKBVARIANT="intl,"
XKBOPTIONS="grp:ctrl_shift_toggle,lv3:ralt_alt"

BACKSPACE="guess"
```

Commit changes

```shell
sudo service keyboard-setup restart
sudo udevadm trigger --subsystem-match=input --action=change
```

Some nice fellow decided that an accented c (“ć”) is more importante than the c with a cedilla (“ç”), so the default behavior for pressing ‘ + c in international keyboards with deadkeys is now “ć”. Since I’m Brazilian and not Romanian or something, that definetly bothers me. ‘ + c used to output “ç” once upon a time.

To fix it, edit as root the file /usr/lib/i386-linux-gnu/gtk-2.0/2.10.0/gtk.immodules, find this line:

```
"cedilla" "Cedilla" "gtk20" "/usr/share/locale" "az:ca:co:fr:gv:oc:pt:sq:tr:wa"
```

And add :en after :wa, so it looks like this:

```
"cedilla" "Cedilla" "gtk20" "/usr/share/locale" "az:ca:co:fr:gv:oc:pt:sq:tr:wa:en"
```

Do the same with file /usr/lib/i386-linux-gnu/gtk-3.0/3.0.0/immodules.cache as above.
