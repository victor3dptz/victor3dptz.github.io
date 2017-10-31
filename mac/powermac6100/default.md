---
layout: page
title: PowerMac 6100 Default Configuration
---

This page describes the as-shipped configurations of the Power Mac 6100 series, as well as some of the alternative configurations.

### Introduction

The PowerMac 61xx series includes all four digit model numbers that begin with "61." This group comprises variants of the Power Macintosh 6100, the Performa 61xx series, and the WorkGroup Server 6150 series. They all are essentially the same machine, sharing a common case, motherboard and ROM. There are minor variations in the native CPU/bus speed (60 vs 66 MHz), but all other features are user-installable. In other words, except for the CPU/bus speed, every member of this family can be upgraded or configured the same way.

This series is also closely related to the Power Macintosh 7100 and 8100. The whole family are collectively known as the Nubus PowerMacs. The first generation of Power Computing clones--the Power 80, Power 100, Power 110 and Power 120--are based on the same archictecture, as are the original Radius clones--the Radius 81/100 and 81/110

Many users are confused by the term "Performa," and believe that a Performa is not a "real" PowerMac. This certainly is not the case--the "Performa" moniker was a marketing designation only. All Macintoshes with 4 digit model numbers are powered by PowerPC chips and, thus, are Power Macintoshes.

In addition to the features listed below, all members of the Power Mac 6100 series also shipped with built-in Ethernet, built-in SCSI, two Geoport serial ports, stereo audio in and out, one ADB port, and unswitched monitor AC power. All Performas and some of the PowerMacs shipped with ADB mouse and keyboard, but some of the early PowerMacs did not. All Performa models also shipped with a Global Village modem.

The "My Configuration" row describes the current configuration of my machine, and the "Max Configuration" row describes the maximum supported feature set for the given criterion.

The information below is taken from the online Apple Spec Database, and is believed to be accurate. Occasionally, Apple has shipped the indicated models in slightly different configurations, usually to the benefit of the user. For example, my Performa 6115 CD was spec'd with a 350 MB hard drive, but I was pleasantly surprised to boot the machine and find a 500 MB hard drive installed.

### CPU, HD and RAM

Model | Date Disc. | CPU / Speed | Bus Speed | L1 Cache | L2 Cache | RAM | HD | CD-ROM | OS
----- | ---------- | ----------- | --------- | -------- | -------- | --- | -- | ------ | --
PM 6100/60 | 1/3/95 | 601/60 | 30 MHz | 32 K | 0 K | 8 MB | 250 MB | Opt'l | Mac OS 7.1.2
PM 6100/60 AV | 9/12/94 | 601/60 | 30 MHz | 32 K | 256 K | 8 MB | 350 MB | Opt'l | Mac OS 7.1.2
PM 6100/66 | 10/14/95 | 601/66 | 33 MHz | 32 K | 256 K | 8 MB | 350 MB | Opt'l | Mac OS 7.5
PM 6100/66 AV | 4/3/95 | 601/66 | 33 MHz | 32 K | 256 K | 8 MB | 350 MB | Opt'l | Mac OS 7.5
PM 6100/66 DOS | 5/18/96 | 601/66 | 33 MHz | 32 K | 0 K or 256 K | 8 MB | 250 or 500 MB | Opt'l | Mac OS 7.5, MS-DOS 6.22
Performa 6110 CD | ?? | 601/60 | 30 MHz | 32 K | 0 K | 8 MB | 250 MB | 2x | Mac OS 7.5
Performa 6112 CD | ?? | 601/60 | 30 MHz | 32 K | 0 K | 8 MB | 250 MB | 2x | Mac OS 7.5
Performa 6115 CD | ?? | 601/60 | 30 MHz | 32 K | 0 K | 8 MB | 350 MB | 2x | Mac OS 7.5
Performa 6116 CD | ?? | 601/60 | 30 MHz | 32 K | 0 K | 8 MB | 700 MB | 2x | Mac OS 7.5.1
Performa 6117 CD | ?? | 601/60 | 30 MHz | 32 K | 0 K | 8 MB | 350 MB | 2x | Mac OS 7.5
Performa 6118 CD | ?? | 601/60 | 30 MHz | 32 K | 0 K | 8 MB | 500 MB | 2x | Mac OS 7.5
WG Server 6150 | 4/17/95 | 601/60 | 30 MHz | 32 K | 0 K | 8 MB | 500 MB | 2x | Mac OS 7.1.2
WG Server 6150/66 | ?? | 601/60 | 33 MHz | 32 K | 0 K | 8 MB | 700 MB | 2x | Mac OS 7.5
My Configuration | NA | G3/210 | 30 MHz | 64 K | 512 K | 136 MB | 4.5 GB | 2x int., 4x4x16 CD-RW ext. |	Mac OS 8.6, MkLinux DR3
Max. Configuration | NA | G4/300 | 42 MHz* | 64 K | 1 MB | 264 MB | ??** | 24x | Mac OS 9.x*** , MkLinux DR3, Virtual PC ****

*Bus speeds above 33 MHz achieved by over-clocking. Overclocking is potentially damaging to your system. 

**Maximum HD size is determined only by the maximum size currently shipped by HD manufacturers in the standard 1" form factor. IBM currently is shipping 73GB drives, and drive sizes will continue to increase over time. Most modern drives require a SCSI adapter to work inside a 6100, which makes it somewhat more difficult to use a video card in tandem, but it can be done. The largest drive I know of that has a 50 pin connector (i.e. it does not need an adapter) is the 18 GB Seagate Barracuda 9LP.

***Mac OS 9 will run on a 6100, and the next release (9.1 or 9.5) will probably as well. Sonnet's G3/G4 driver is OS 9 compatible, and an OS 9 compatible version of Newer's G3 driver is currently in beta

****While VirtualPC is not an operating system, it permits you to run many PC (i.e. x86) operating systems in emulation on the Macintosh. MS-DOS, Windows 3.x, Win9x, WinNT, Linux, OPENStep and OS/2 have been run successfully on top of VirtualPC.

### Supported video input and output

Model | Motherboard Video | Secondary (PDS) Video | Adapter cables | Bundled Monitor | 2nd Monitor
----- | ----------------- | --------------------- | -------------- | --------------- | -----------
PM 6100/60 | 640 K DRAM | None | HDI45-DB15 | None | None
PM 6100/60 AV | 640 K DRAM | 2 MB AV | S Video-Composite I/O | None | None
PM 6100/66 | 640 K DRAM | None | HDI45-DB15 | None | None
PM 6100/66 AV | 640 K DRAM | 2 MB AV | S Video-Composite I/O | None | None
PM 6100/60 DOS | 640 K DRAM | 512K VGA*** | HDI45-DB15 | None | None
Performa 6110 CD | 640 K DRAM | None | HDI45-DB15 | Apple Multiple Scan 15" | None
Performa 6112 CD | 640 K DRAM | None | HDI45-DB15 | Apple Multiple Scan 15" | None
Performa 6115 CD | 640 K DRAM | None | HDI45-DB15 | Apple Multiple Scan 15" | None
Performa 6116 CD | 640 K DRAM | None | HDI45-DB15 | Apple Multiple Scan 15" | None
Performa 6117 CD | 640 K DRAM | None | HDI45-DB15 | Apple Multiple Scan 15" | None
Performa 6118 CD | 640 K DRAM | None | HDI45-DB15 | Apple Multiple Scan 15" | None
WG Server 6150/60 | 640 K DRAM | None | HDI45-DB15 | Apple Multiple Scan 15" | None
WG Server 6150/66 | 640 K DRAM | None | HDI45-DB15 | Apple Multiple Scan 15" | None
My Configuration | 640 K DRAM | 2 MB AV | S Video-Composite I/O + HDI45-DB15 | Apple Multiple Scan 15" | Sony 17"
Max. Configuration | 640 K DRAM | 2 MB AV or 4 MB HPV* | S Video-Composite I/O + HDI45-DB15 | 17 "** | 21"

*One PDS card can be installed in the 6100 series. The HPV cards provide slightly higher graphics performance, but the AV card provides S-video input and output.

**The primary (DRAM) video output will drive resolutions up to 832x624. A 4MB HPV card installed in the PDS will drive resolutions up to 1152x870

***The secondary video is for the DOS side only, e.g. if you're using a DOS card you can have the DOS display either on a shared display or on a separate display. But you can't use the second display on the Mac side.
