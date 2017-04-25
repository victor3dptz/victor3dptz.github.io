---
layout: page
title: Bootstrap your vintage Ethernet equipped Mac from your Windows PC
---

### Overview

So, back in the day you used to be a Mac user huh, but at some point you switched to the dark side. Never mind, you have realised the error of your ways and have purchased the Mac of your youth off ebay, but now, your only modern computer being a Windows based PC, you are wondering how to get software onto (and off of) your shinny new (old) Mac. Possibly you even need to install or upgrade its Mac operating system. Lucky you finding this page.

The process that will be described here is hopefully relatively straight forward, and will require the following:

* Some time and enthusiasm for life and computing
* An Ethernet equipped Macintosh with a 1.4MB "super" drive that is capable of running MacOS 7.5 (note your Ethernet adaptor needs to be compatible with the Apple driver)
* An Ethernet equipped Windows XP PC with 512MB RAM and min 1GB free disk (prefer 3GB) space with a 1.4MB floppy drive
* An ethernet network and something that hands out DHCP addresses
* A copy of VMware Server or VMware Player (both free) for your XP machine
* A copy of the Linintosh server VM appliance
* A copy of RAWRITE2 and the associated RAWRITE2 Apple network access disk image
* A error free 1.4MB floppy disk

One of the major challenges here is simply having the necessary software. You should find the Linintosh server, a copy of RAWRITE2 and the required boot disk image in a single convenient package [right here](http://www.mininova.org/tor/1280998). (You will need a bittorrent client)

With this stuff we are going to

* Create a universal Mac network access disk on our PC to boot our Mac with
* Fire up our Linintosh Virtual Appliance to serve files to our Macintosh (this handy little server contains a number of MacOS installation sources) over Ethertalk
* Boot our Mac with the boot floppy we made earlier and install an OS from the Linintosh server over Ethertalk

### Disclaimer

You should basically assume that I know nothing and everything described here is the result of a prolonged bourbon drinking binge. I encourage you to use common sense (your own) and judgement (your own) when attempting this procedure. I personally have performed this miracle with my own LC475, but as with all things, your mileage may vary. If you are not comfortable with any of the procedures described here, I recommend you don't try - you'll just end up cursing me, your Mac, and (quite rightly) your PC.

Righto -Lets get started!

### Creating a Mac boot floppy on your PC

Those crazy guys at Apple figured us crazy users would want an easy way to build our Mac's across the network. Lucky for us they produced the "Network Access Disk", which in our case is a cut down version of MacOS 7.5 that fits on a boot floppy and will boot any Mac with a 1.4MB AND provides both LocalTalk and EtherTalk networking - woohoo! This is the good news, along with the fact that the disk is freely downloadable from the Apple Web Site. The bad news for us people who actually use PC's in their everyday lives is that its not easy to extract the provided image onto a disk when all you have is a PC to work with.

No problem. Fortunately for us, there is a RAWRITE image of this disk - RAWRITE is a floppy image writer/creator that runs on the PC (amongst other platforms). All we need to do is write the Mac Network Access Disk image to a floppy. Easy.

* Start a command prompt on your XP machine by choosing "Command Prompt" from the start menu, or alternatively (if its not in your start menu), by choosing the "RUN" option in your start menu, and then typing "cmd" (without the quotes) into the resultant "Run" dialogue box. Click OK.

![Start](/mac/bootpc/1.jpg)

![Run](/mac/bootpc/2.jpg)

* Format the floppy disk you are going to use to write the Network Access Disk image to by using the command "format a: /u" (without quotes), where a: is the drive letter of your floppy device. If formatting fails, throw the disk away and try another one - the disk needs to be formatted before use with RAWRITE2, and any dodgy disks will just give us trouble.

![Format](/mac/bootpc/3.jpg)

* In your command window, change the working directory to that of the RAWRITE2 application. Use the command "CD". i.e. CD e:\vintagemac\rawrite2

![rawrite](/mac/bootpc/4.gif)

* Assuming you got this RAWRITE from the Linintosh server package, it will contain the required image file (MacNWAcc.img). Write the image to your newly formatted floppy by using the command "rawrite2 macnwacc.img a:" (again without the quotes), where a: is the drive letter of your floppy device.

![floppy](/mac/bootpc/5.jpg)

Notice how the command prompt has gone wacky - rawrite isnt used to non 8.3 naming formats - dont worry about (in this context). Anyhoo, your boot disk should be ready. Pop it into your Mac and turn on - If it worked (why wouldn't it), your machine will boot from the Floppy and load MacOS 7.5 - yay.

### The Linintosh Server

If your anything like me, getting to this point hasn't achieved you a lot. Assuming your Mac ethernet card is supported, you now have ethertalk connectivity, but without anything to talk to, thats pretty useless. Windows XP itself has no ability to serve Macintosh clients so our best bet is the open source package Netatalk (http://netatalk.sourceforge.net/). Netatalk does indeed rock, however for the average Windows user, it may be a little daunting. Thats where the Linintosh server comes into play.

The Linintosh server itself is a VMWare appliance (in the loosest possible sense). It is simply a Linux virtual machine that has been configured with a minimal(ish) Linux environment AND a preconfigured Netatalk and Samba (we'll talk more about Samba in a minute) instance. The idea being you turn on this virtual appliance and it provides preconfigured network connectivity between both Windows XP clients (natively) and Macintosh clients (natively). In fact, the Linintosh server is configured to serve up the same network volume to both Windows and Macintosh clients simultaneously - sounds handy for transferring files huh.

In addition to being useful as a file transfer mechanism, the Linintosh server also comes prepopulated with a bunch of useful software. Most notably the stuff you are likely to need to install a vintage OS onto your vintage Mac now that you can boot it with a network access disk - hey that sounds like a handy thing to have!

The preconfigured software comes on a Volume called "Apple System Software" so you may be able to guess whats on it. If not, heres a list. 

```
System 6.0.8
System 7.0
System 7.0.1
System 7 Tune Up 1.1.1
System 7 Update 3
System 7.5.3
System 7.5.5 Update
Network Access Disk 7.5
MacTCP 2.0.6
Open Transport 1.1.2

Fetch 3.0.1 (FTP)
iCab Pre2.99b 68k (Web Browser)
Netscape 4.0.3 68k (Web Browser)
WhatRoute 68k (TCPIP tool - ping etc)

Binhex 4
Disinfectant
Diskcopy 4.2
MacBinary II+ 1.0.2
MiniSubstitute 1.7.1
Apple HD SC Setup 7.3.5
Disk Copy 6
Disk First Aid
ResEdit
Stuffit Expander 3.5.2
Stuffit Expander 4.0.2
TeachText
```

### Welcome to Linintosh

In order to use the Linintosh server you will need a virtual machine player. Your free choices are VMware server or VMware player. If you are not familiar with VMware or virtualisation, I would recommend you download and install VMware player - its just a basic player for virtual machines, no bells and whistles but does the trick. I'll describe here the process to load the Linintosh server with VMWare player - note, you will have to figure out how to install the VMware player yourself (its so hard, click next, next, next, install).

Right!

* Start your VMPlayer application
* Click on the "Open" Icon

![Vmware](/mac/bootpc/6.jpg)

* Browse to the "Linintosh Server" directory (in this example e:\VintageMac\Linintosh Server), select the "Linintosh Server.vmx" file and click "Open"

![Open](/mac/bootpc/7.jpg)

* You will more than likely be presented with a dialogue suggesting that you have either moved or copied this virtual machine. VMPlayer will want to know which one it is - well lie. Tell VMPlayer that you moved the virtual machine. If you say you copied it, return to go and start again (i.e. it wont work).

![Ask](/mac/bootpc/8.jpg)

* Once you click OK, the Virtual Machine should start to boot.

You will then see a bunch of stuff scrolling up the screen as the Linintosh Server appliance loads up. At this point you will need a DHCP server active on your network to provide the Linintosh Server an IP Address (if you want to be able to access it via your Windows XP machine). Once the virtual machine has booted, you should see a screen that looks similar to this

![Boot](/mac/bootpc/9.gif)

Examining this advanced graphic we can see that

1. Hey, I got an IP address - cool
1. Hey, I'm a Windows network server - ahh, is that really cool?
1. Hey, I'm an Appletalk network server - cool
1. Hey, I'm actually a OpenSUSE 10.3 linux server - now that is cool

If everything has gone to plan and your onto your 6th shot, I mean you've got this far you should now be able to "PING" your Linintosh. Remember your friend the command prompt? Well, head back there and type this command "ping linintosh". Through the magic of rainbow you should get a response that looks like this

![Ping](/mac/bootpc/10.jpg)

The IP address you see will be dependant on your network and what your DHCP server has been configured to hand out - the main thing is, the Linintosh is responding.

### Show me the Windows Share

Ok, wanna see something cool? Remember that whole "Start", "Run" thing? Yeah, well do it again, but this time in the "Run" dialogue type the command "\\linintosh" and click "OK"

![Browse](/mac/bootpc/11.jpg)

If things are all good, you should see something that looks a bit like this

![Samba](/mac/bootpc/12.jpg)

Double click on the "mac" share, go on, I know you want to. This time you should be presented with a login dialogue box. The username is "macuser" and the password is "password" (no quotes on either of these).

![Connect](/mac/bootpc/13.jpg)

After clicking OK, you should see the share below.

![Files](/mac/bootpc/14.jpg)

Some things to note about this share.

* Dont mess with the hidden files and folders created by Netatalk on the Linintosh server (.AppleDB .AppleDesktop .AppleDouble), you WILL break your Mac files (stink)
* You have access rights to copy stuff onto this volume, this stuff will be visible on your Mac on this same volume. Make sure you copy stuff that your Mac will understand - like .SIT and .BIN files, anything else is likely to get lost in translation

### Show me the Mac Volume

Ok, now for the good part. Power up that Mac of yours, if necessary, use the network access disk we created earlier. Lets connect.

* Go to the network control panel and ensure your Mac is set to "Ethertalk" as opposed to "Localtalk"

![Network](/mac/bootpc/15.jpg)

* Go to the chooser and click on the Appleshare icon, your linintosh server should appear in the list of servers (note that the Netatalk services do start in the background on the Linintosh Server and so it can be a minute or so after the virtual machine has booted before it becomes available). When you see it, select it and click OK

![Chooser](/mac/bootpc/16.jpg)

* You will be prompted for a username and password, now, let me think, what could it be..... I know! try username "macuser" password "password" (minus the quotes - do I really need to keep telling you that?)

![Chooser Connect](/mac/bootpc/17.jpg)

* Ok, now select the Volume to Connect to. On the Mac side its called "Macintosh System Software".

![Mac Volume](/mac/bootpc/18.jpg)

Once you click "OK", you should be done and ready to roll.

![Connected](/mac/bootpc/19.jpg)

Check that out - nicccccccce. Now full your boots and install the OS your after, the upgrade you want, or the software you just copied into the Volume from your PC.

### How to shutdown safely

You may be wondering how to shut down this beast without breaking anything. Good question. By default the VMplayer will "suspend" your virtual machine when you exit - thats ok, but your miliage may vary with this approach. I prefer to actually shut the Linintosh server down to avoid any unexpected issues. There are two ways to do this.

The easiest way is probably to simply modify the exit behavior of the VMPlayer

* Maximise the VMPlayer application that is running your Linintosh server
* Click on the VMPlayer drop down menu, select the "Preferences" option

![Shutdown](/mac/bootpc/20.gif)

* Once in preferences, select the "Power off Virtual Machine" under the "When exiting" section and click OK

![Dialog](/mac/bootpc/21.jpg)

Now when you exit the VMPlayer, the Linintosh server will be shut down gracefully. Just make sure you have closed all your open connections from both your Windows and Mac clients.

### About Linintosh

Linintosh is built on OpenSUSE 10.3. Its a reasonably minimal install with only the packages needed to be installed, installed. Its still rather big, but thats probably because its an end user platform and I've used YAST for everything - but that keeps it simple. There is no X and no back doors (that I've put in anyway!). I would not recommend you run this on a public network because all the passwords are "password". Should be great for a home LAN however.

There are two accounts that I have configured:

```
root - password = password (full admin user)
macuser - password = password (limited access user)
```

### Troubleshooting

Ummm, did none. Things off the top of my head.

* Dont choose copied over moved in the VMware configuration - it will break the networking in the virtual machine - fixable, but you need to know something about Linux (just re-extract the Linintosh Server Directory from the zip file if this happens)
* If you want to have network access from your Windows box to the Linintosh, make sure there is a DHCP server on your network that will give Linintosh an address
* Got a problem? Got a firewall? Firewalls are always causing problems - check that out
* If you cant see linintosh from your Mac, perhaps your Ethernet adaptor is not supported by the apple driver
