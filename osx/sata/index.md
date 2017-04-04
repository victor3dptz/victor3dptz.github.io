---
layout: page
title: How to enable Serial-ATA support in PowerMac G4
---
 
Here you'll discover how to flash a cheap Serial-ATA controller for mac support. 

### Buy a cheap Serial-ATA controller based on Sil3512
I've got ST-Lab A-390 (Sata150, 2 int/Raid, PCI) for 568 rub. You may also buy a controller with Sil3112 chip too.
![Sata card](/osx/sata/card.jpg)

### Insert your Serial-ATA controller card to the PowerMac G4
![Inside](/osx/sata/inside.jpg)

### Download a firmware [here](http://wiki.victor3d.com.br/osx/sata/sata.zip)
![Sata1](http://wiki.victor3d.com.br/osx/sata/sata1.png)

### Run a FlashTool
Be careful, this operation may destroy your card. But don't worry, it was cheap! There is option to restore an original BIOS to use it in PC.
![Sata2](http://wiki.victor3d.com.br/osx/sata/sata2.png)

### Reboot your Mac
It isn't necessary, but if you enter single-mode, you'll see messages containing our new Serial-ATA port and it's extension.
![Console](http://wiki.victor3d.com.br/osx/sata/console.jpg)

### Done!
After reboot you won't see any change in the Serial-ATA section:
![Sata3](http://wiki.victor3d.com.br/osx/sata/sata3.png)

Don't worry, there are two additional ATA buses that you may use.
![Sata4](http://wiki.victor3d.com.br/osx/sata/sata4.png)

You may connect Serial-ATA drives to your PowerMac and use it. You may even install the Mac OS X and it will boot from the Serial-ATA drive.
