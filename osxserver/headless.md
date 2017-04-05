---
layout: page
title: Headless Mac mini OSX Server installation
---

I bought a Mac mini some time ago and a version of OSX server to experiment with. It sits in a closet without peripherals attached and I would like to keep it that way. In fact, while I could use the mouse an keyboard from my iMac, I don’t even have a monitor. And I am certainly not buying one for the mini server.

However since it is meant to experiment with, there is some need to reinstall the machine sometimes. While it took a little Internet research to find all information it turned out to be relatively easy. Some experience with ssh and unix commands come in helpful though.

Basically it these these steps:

* Determine the mini’s ip adress
* Log in with ssh
* Start the installation
* Activate Apple Remote Desktop
* Perform software update

### Determine the mini’s ip adress
Make sure you have DHCP running to handout IP-addresses. Turn on the mini with the install cd loaded. Wait a few minutes, it will then have obtained an IP-address. Check in your DHCP server the last address given out.

### Log in with SSH
When the system has started up with the install cd you can login to it with ssh root@ip-address. As password use the first eight digits from the computer’s built-in hardware serial number. It will be at a label on the computer. For older computers without built-in hardware serial use 12345678. This works with XServer as well as other models. I did it with a Mac mini.

### Start the installation
Just assuming you would like to install the system on the same volume as before, there is no need to repartition. Also assuming you are using a single dvd version., so there’s no disk switching involved. Just start the installation with

```shell
/usr/sbin/installer –verboseR –pkg \ /Volumes/Mac\ OS\ X\ Server\ Install\ Disc/System/Installation/Packages/OSInstall.mpkg -target /Volumes/Server/
```

The installer will locate the Package and start the installation. The progress will display in your terminal window. When finished, you will get a message saying the installation was successful.

Eject the install disk by issuing the following command: 

```shell
drutil eject
```

Now restart the server by issuing the following command: 

```shell
shutdown -r now
```

### Activate Apple Remote Desktop
The easiest way to remotely manage the server is of course with the Server Tools. However there are situations that can be done easier with Remote Desktop, like configuring first time. Therefore we will activate ARD for root user. Just log in as you did in step 2 and on the command line type

```shell
/System/Library/CoreServices/RemoteManagement/ARDAgent.app/Contents/Resources/kickstart \ -activate -configure -access -on -users root -privs -all -restart -agent –menu
```

Open ARD on your computer and connect to the server. Use the same username and password as for ssh. You should see Server Assistant now being open on your server. Configure the server. When you do so make sure you select ARD to enable on startup or it be disabled upon completion of the configuration.

### Run software update
For the installation it is not necessary to do it on the command line but running software update this way is nice. Just login with ssh again, now with the user you set as administrator in Server Assistant and type:

```shell
sudo softwareupdate –i –r
```

*Source: Apple Server Documentation, specifically the document on Command-Line Administration and the Excellent Tutorial from AFP548. It is a bit dated on some file locations but nothing I couldn’t solve easily.*
