---
layout: post
title: Virtual console blank screen no login prompt
---

After booting to the GUI, I attempt to move to the virtual terminal (or shell, or tty) via Ctrl-Alt-F1 (F1 through F6), and the screen remains blank. I'm tried all 6 tty instances and the results are the same. Ctrl-alt-F7 brings me back to the GUI without a problem.
This is usually caused because the graphical text-mode resolution set at boot up is not compatible with your video card. The solution is to switch to true text-mode by configuring Grub appropriately:

Open the terminal with Ctrl+Alt+T
Paste the below, and enter your password when asked:
```shell
sudo sed -i -e 's/#GRUB_TERMINAL/GRUB_TERMINAL/g' /etc/default/grub
```

Then type
```shell
sudo update-grub
```

Reboot and the virtual terminals should now work.
