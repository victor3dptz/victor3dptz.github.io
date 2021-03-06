---
layout: page
title: PowerMac 6100 DOS Card
---

![Logo](/mac/powermac6100/img/12dos.gif) This page describes the options for running DOS or Windows on a Power Mac 6100 series computer.

### Introduction

For users who absolutely must run DOS or Windows on their beloved Macs, there are two major classes of options--hardware compatibility and software compatibility. Be forwarned--running a non-native operating system is brutally slow, and for the hassle and expense most people would be better off buying or resurrecting an old PC. But if for space or convenience reasons you really need to run both OS's on a single machine, read on.

### Hardware

If you do not have, and don't ever plan to have, a G3 card in your 6100, then your best bet is probably to use an Apple DOS compatibility card. This card installs into the PDS on your motherboard, and it includes what amounts to a small PC on a card. It contains a 486 CPU, a slot for RAM, a video controller, a game port and Soundblaster chip. It shares the Mac's power supply, disk drives, input devices, etc. on the motherboard, and it can also use the Mac's RAM in a pinch.

Once you've installed a DOS card, you must install a PC Setup control panel on your Mac and create a virtual hard drive. The virtual hard drive is a large "container" file that contains all the DOS-related files within it. You then install DOS and/or Windows onto/into that virtual hard drive and run it from there. You can toggle between the DOS and Mac environments with a keyboard combo, and you can copy and paste data between them. Performance is slower than a "real" 486-based PC would be, due to the overheard involved in sharing disk, RAM and I/O resourcse.

Apple's supplied PC Setup software ended its life at version 1.6.4, which was released to provide OS 8 compatibility. I don't know exactly where support ends for PC Setup. There was a small software development company that had licensed the source code from Apple and released an updated version that would run all the way through OS 9.x, but they appear to be offline right now due to "technical difficulties."

### VirtualPC

If you can't put a hardware x86 computer inside your Mac, you can put a software one inside. Enter the magic of software emulation. Virtual PC is a Macintosh application that "emulates," or behaves exactly like, an Intel Pentium-based computer.

Virtual PC is what's known as a "bare metal" emulator, in that it creates (or at least attempts to create) an exact replica of the hardware itself. Therefore, if you are using Virtual PC, you are not limited to running Windows. You can actually install a variety of operating systems that are x86 compatible. The following is a list of operating systems that have been more or less successfully run on top of Virtual PC:

* MS-DOS
* Windows 3.x
* Windows 95
* Windows 98
* Windows NT 4.x
* Windows 2000 Professional
* OPENStep
* Linux (various flavors)

