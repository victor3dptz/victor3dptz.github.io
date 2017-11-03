---
layout: page
title: Power Mac 6100 Peripherals
---

![Logo](/mac/powermac6100/img/14periphs.gif) This page describes various peripherals that I've attached to my Power Mac 6100. This list is not all-encompassing, because neither is my budget. But it covers most of the categories that people use and have asked me about. I've listed the makes/models that I've owned, since that's all that I have experience with. Obviously, lots of other models and types work as well, but I don't have any information on them.

### Introduction

Generally speaking, peripherals can be attached to the PowerMac 6100 by using the following ports:

* **Two GeoPort high-speed serial ports** - Working at speeds of up to 230 Kbps (or higher, if externally clocked), the Printer and Modem ports can be used for AppleTalk printers, serial printers, Webcams, low-speed scanners, MIDI devices, and even for low-speed networking (LocalTalk). If you need more than two serial ports, you can use a serial port expander.
* **One SCSI port** - Working at speeds up to 5MBps, the SCSI port is primarily intended for the connection of hard drives, removable storage (Zip and CD/CD-R/CD-RW) and scanners.
* **Stereo mini-jack in** - Pipe in sound from a microphone or an external line-in source like a tape deck or CD player
* **Stereo mini-jack out** - Send sound out to external speakers or to a tape deck
* **ADB port** - Beyond your mouse and keyboard, you can add trackballs, drawing tablets, joysticks and other game controllers, or even home-automation devices.
* **Ethernet port** - Besides connecting to other computers and the WWW, you can also connect to shared peripherals, such as printers, scanners, and storage. 

### Printers

Since buying my 6100 back in 1995 I've successfully printed to the following printers:

* **Apple Color Stylewriter 2400** - This is QuickDraw printer that can be used only with a Mac. It's primarily a single-user printer, but it can be shared over a network if you buy the optional LocalTalk module, the optional Ethernet module, or if you use Apple's built-in ColorShare software. This printer had pretty good quality for its era, but there were quality-control issues, too. Mine started malfunctioning after less than a year (after mis-feeding a large stack of envelopes) and never printed properly after that. Another common problem is a refusal to acknowledge the presence of ink cartridges (often correctable by resetting the firmware). A common driver for the 2400/2500 is still available from Apple. Mechanically, the 2400 has the same print engine as the Canon Bubblejet BJC-4000. You can't use it with a PC (because they don't speak QuickDraw), but you can use ink tanks made for the Canon.
* **Epson Stylus Color 740** - Another pretty decent printer. It's a bit finicky in that the heads clog easily, but if you print to it every few days it's usually OK. Print quality is good, and they're very affordable if you can find them. It's a serial printer, but you can also use it over a network using EpsonShare ($24 shareware from NiceBoy Software) or by using the $140 Axis 1440 External Print Server from Axis and Epson. I use the latter, and it works pretty well. As a local printer, it's got a parallel port, a serial port, and a USB port. The latter port also enables you to share the Epson 740 using Apple's USB Printer Sharing software, although not from a 6100.
* **HP DeskJet Pro** - One of the first "pro" inkjets, the DeskJet Pro didn't even have a model number. Nor did it have a black ink tank; it just mixed the other colors into a muddy brown. But the DeskJet did have pretty good print speed, multi-platform support, and a heating element to make sure that pages were dry when they popped out of the printer.
* **Apple Stylewriter** - One of the early inkjets, which is also based on a Canon engine. Not a bad little printer, although mine has long since lived out its life. Drivers are still available from Apple, though, and this printer can take ink made for its Canon siblings. 

There are tons of other printers that will work just fine with a 6100. Just beware that modern applications and printer drivers require a lot more horsepower than earlier ones did. For example, Adobe Acrobat Reader 4.x can generate spool files up to 10-15 MB per page! These require a ton of free hard drive space and will bring a non-accelerated 6100 to its knees.

### Fax Modems

Most, if not all, Performa 611x's shipped with a Global Village Teleport FaxModem of some flavor:

* Bronze - a zippy 4800 baud
* Silver - 9600 baud
* Gold - 14.4 Kbps
* Platinum - 28.8 Kbps
* Mercury - 33.6 Kbps 

Mine came with a TelePort Gold IIP, where the "P" means Performa. This modem draws power from the GeoPort serial port, which means two things. On the plus side, there's no power brick/wall wart to deal with. On the downside, there's no power switch, so it can be inconvenient to reset the modem (you have to unplug it from the computer). This modem can be hacked to take an external power supply and work with earlier Macs (that did not supply power in their serial ports), but this is a fairly involved hack.

Later, I upgraded to a US Robotics Sportser Voice 28.8/33.6, and then later to a Global Village Platinum.

Modems can actually be plugged into either serial port, but the modem port has a higher interrupt priority, so if you're going to use your modem for incoming modem or fax calls, you probably should attach it to the modem port.

You can use just about any Mac-compatible, serial (i.e. not USB) modem with a 6100. You can even use some PC-compatible serial modems. Don't ask me how to do the latter, though. It has to be a "hardware handshaking" modem, and you'll need to make or buy a serial cable adapter. I know it can be done; I've just never done it.

Software-wise, you don't need much to use a modem as a modem. Apple's Remote Access or PPP software is pretty much it, although Rockstar's FreePPP works well, too. Modem scripts for all Global Village modems are included in both packages.

You can actually use two Macs' modems to connect them directly to each other, which is useful if you don't have any removable storage (i.e. you have an iMac), and you don't have Ethernet. This is documented in an Apple TIL article.

The Global Village ones come with a pretty decent fax application (GlobalFax), but some versions are intolerant of some system software versions. I originally got version 2.1.2 with my Teleport Gold IIP, which is updatable to version 2.1.5, but it was incompatible with OS 8.6. So I downloaded 2.6.8 from Global Village. But that was incompatible with my Gold, so I had to buy a Platinum off ebay to make it all work.

### PDAs

My first PDA was a PalmPilot Personal edition, upgraded with a 2MB/Infrared card. It was a great little PDA, until I left it on the roof of my car and drove away :(

Now I have a Palm Vx (for my wife) and an IBM WorkPad 3c (which is the same thing) for myself.

Any model of Palm will work with a Mac--all you need is Palm's freely downloadable Palm Desktop software for the Mac and a serial cable adapter. The current version of the software is 2.6.1, which is functionally equivalent to 2.5, but has a bugfix to correct problems when syncing to a USB-equipped Mac running OS 9.

In fact, the Palm Desktop Software for the Mac is a pretty decent little PIM (personal information manager) all by itself, and you don't need a Palm device in order to use it. And it's free.

Other than the software, the only other thing you'll need for a 6100 is a serial adapter to convert the PC-style serial connector to a Mac-style serial connector. This is included in the $7 Mac Pac, or you can build or buy one yourself.

As described below in the port sharing section, many users will not be able to dedicate a serial port to their PDA, because their ports are tied up with their other peripherals. If your PDA is not always connected to an active serial port, you can leave the Hotsync Manager/Serial Port Monitor off, and then turn it on only when you need it by using a neat little freeware AppleScript called LaunchQuit Hotsync.

### Webcams

I have a Connectix Color QuickCam (serial). These are really hard to find, not only because they've been discontinued, but also because the QuickCam product line got purchased by Logitech. Logitech still makes Mac-compatible QuickCams, but they're all USB these days, so you can't use one of the new ones with a 6100.

But the serial guys are still available on ebay. I bought mine from a seller named blankcdmedia, who proved to be a very good seller.

I call them webcams because their most popular use is internet-based video-conferencing or webcam sites. The image and video quality from these cameras is decent, considering the affordability of these cameras ($20-$150).

For videoconferencing, I use iVisit. It's freely available while in beta, and it's cross-platform. It's also got a peer-to-peer connection model, so you're not so dependent on servers or reflectors to make connections (although you are highly reliant on a directory server to find people in the first place).

Other videoconferencing software:

* CU-SeeMe - Formerly freeware from Cornell University, it is now commercialware from CU-SeeMe Networks (nee White Pine Software). The older, free versions are still floating around the web. CU-SeeMe is cross-platform.
* ClearPhone - Relatively new, but cross-platform
* NetMeeting - Microsoft's free offering. There's no Mac version. 

The Connectix serial driver has a conflict with Mac OS 9. In short, it doesn't work at all. There is a third-party patch freely available, but its effect on other stuff is unknown. I wasn't thrilled with the stability of OS 9, especially with legacy stuff like this, so I downgraded back to 8.6.

I'm assuming that Connectix's USB driver works fine with Mac OS 9, but I'll have to wait until I get my new G4 before I can see for myself!

### External Speakers

I have a three-piece Atlantic Multimedia speaker system which I like a lot, especially given the $99 price when I bought it three years ago. Since then, prices have dropped dramatically, so I bought another pair of these guys for my office for $50.

Most recently I bought a pair of Monsoon MM700's. This is a three-piece system with flat-panel satellites! The satellites look way cool, take up very little space, and sound awesome. They're point-focused, so they won't really fill a room with sound, but they are divine when you're sitting in front of them. CDs, MP3s and Quake all sound phenomenal. $114 plus shipping!

### Microphones

The microphone jack on most modern Macs is a bit of an oddity. Although it looks like a regular stereo minijack, it's not. It requires a line-level input, which means that all those PC microphones you see on the shelves are incompatible.

The only mic I know to be compatible out of the box is Apple's PlainTalk microphone. The PlainTalk mic has an extra long plug, and the tip of that plug draws power from the Mac to drive a little inline pre-amp.

Unfortunately, the PlainTalk mic is not the best mic for all purposes. It's omni-directional, and it's not very useful for speech recognition or dictation.

If you do want to use other microphones, you may be able to use them in conjunction with Griffin Technology's NE Mic adapter, a $29 inline pre-amp that brings a standard mic input up to line level.

You can also use RCA-stereo minijack adapters to connect the output of an audio device (e.g. stereo equipment like a tape player or turntable) to your Mac.

### Zip Drives

Had a Zip. Got it stolen. Got a Zip Plus. Zip Plus had technical flaws with SCSI chains. Went back to the regular ol' Zip. Been happy ever since.

Although the Zip drive's unique value has dropped a lot since CD writers and media became so cheap, they still have their place. They're cross-platform, reasonably fast, they're re-writable, and you can make 'em bootable without a lot of hassle.

Iomega has the latest version of its drivers and utilities freely avaiable for download. It's important to geta recent version, since it corrects a serious omission from previous versions--the ability to create a DOS-formatted Zip disk from a Mac.

### Scanners

I have a Umax Astra 600S, although I also have some "SCSI voodoo" issues. I can't seem to have my scanner and my CD-RW plugged in at the same time. I've tried all the various ID numbering, termination, logical and physical re-ordering of the devices, and nothing seems to help. So I have to use one at a time.

But the scanner by itself works just fine. With the bundled software I can make (slow) copies in B&W or color, and I can even fax things.

Umax has removed their nifty little "Copier" app in favor of something far more complicated, but I've posted it here and maintained the hope that no one will sue me.

Future scanners from Umax had one-button scanning, which is cool for copy/fax applications.

### Serial Port Expanders

If you count up the devices, you'll see that I've run out of serial ports! I have my fax/modem plugged into the modem port, which leaves me with one port for three devices--my Epson printer, my QuickCam and my Palm V cradle.

MacAlly's PortXpander was my solution to the problem. It's not perfect, but it works. I have the PortXpander plugged into my printer port, and the three devices plugged into the PortXpander. I can only use one device at a time, but at least I don't have to manually plug/unplug the devices.

Some issues/bugs with PortXpander:

* Not AppleScriptable - This makes it somewhat inconvenient to switch among the ports, since non-Comm Toolbox-savvy apps can't to this automagically. Instead, I have to use the Control Strip module. It would be nice to be able to write AppleScripts which could set the PortXpander to a particular port, and also to query the PortXpander driver to determine the current setting. The PortXpander is not being actively developed any more, but maybe MacAlly will open-source the driver.
* Control Strip fights with the Control Panel for "naming" of the ports. By default the three available ports are named Port1, Port2, and Port3, which is not terribly useful to the user. So I've named my ports Printer, PalmCradle and QuickCam. But it wasn't very easy! The ostensible way to rename the ports is to open the Control Panel and type in the new names. But if the Control Strip module is enabled, the changes don't stick, and the names revert back to the defaults. The only way tot change the names is to disable the entire Control Strip, reboot, change the names, and then re-enable the Control Strip and reboot again. Pain in the neck. 

If I were to do this all over, I'd probably just get a cheap manual switchbox. Manual switchboxes require no software, so they will always be compatible. They're somewhat less elegant than automagic switchboxes, but then again the automagic ones are less functional when they don't work.
