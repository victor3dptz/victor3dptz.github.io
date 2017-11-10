---
layout: page
title: The Definitive Guide to Connecting your SE/30
---

This guide will be an attempt to detail the steps necessary to connect an SE/30 for file sharing and Internet connection establishment. Although this guide will assume you have the same setup as the author, there are variations possible, so consider this approach to be just one way of doing it. 

### Part 1: Basic Requirements

#### 1.1 Hardware

A Macintosh SE/30 in good working order, with a hard drive, working floppy drive, preferably 32MB of memory for a 12-20MB RAM Disk, at least five floppy disks in good order, another Mac that can write floppy disks (or an external USB floppy drive), Ethernet cross-over cable, Ethernet standard cable, and (preferably) Ethernet RJ45 (8P8C type) network 030 PDS expansion card, a large tolerance for discomfort, emotional stamina, and a partridge in a pear tree. 

#### 1.2 Software

System 6.0.8: AppleShare WorkStation v.3.5, MacTCP v.2.0.6, Network Software Installer v.1.4.5, and Ethernet card drivers if required.

System 7.5.5: AppleShare Client 3.7.4, Chooser v.7.6.1, OpenTransport 1.1.2, OpenTransport 1.3, Network Software Selector, and your Ethernet card drivers if required. 

### Part 2: Installing the Software

Common convention among computers is to install the software before the hardware. We will march along that established route.

System 7.5.5 is the best for this platform for Internet access and is required to connect to Mac OS X computers. 

#### 2.1 Installing System 7.5.5

The easiest way to do this is using an older Mac that can connect to the Internet and share files using LocalTalk with a LocalTalk network between the two computers. The next step is download all 19 parts of System 7.5.3 CD Install [here](http://www.info.apple.com/support/oldersoftwarelist.html) and transfer it to the SE/30. However, the author did not have this luxury, and the Installer requires 45MB by itself, which wouldn't fit on a 40MB hard drive.

In order to install 7.5.3, you must have at least System 7.0 on a floppy drive or the hard drive. The floppy drive route is highly undesirable unless you have an external floppy drive hooked to your SE/30. If you do not, then you will be forced to play the FloppySwappyâ„¢ game, which requires the tedious job of swapping Install Disk 1 and your System 7 boot floppy six to eight times just to mount it on the desktop (a RAM Disk could be a possible boot option, but that only is pragmatic in System 6). The solution is to install a very basic System 7 install on the hard drive, which can be found [here](http://www.info.apple.com/support/oldersoftwarelist.html). The next problem is that the CD Install cannot fit on floppy disks, so you must take the next step by downloading the [Legacy Software Restore Disk](http://macintoshgarden.org/apps/apple-legacy-software-recovery-cd).

Your next step is then to mount all 19 floppy disk images. OS X can sometimes corrupt certain Mac OS 9 files, so the author did this work on an iBook G3 900MHz/32VRAM with a USB floppy drive booted into 9.2.2. Additionally, formatting a disk in OS X and using it creates additional invisible files, which reduce your practical working space from 1.3MB to 1.1 or even 1MB, which is not suitable. Using OS 9 prevents this problem.

Copy the contents of Install Disk 1 onto a freshly formatted floppy disk. The author's SE/30 could recognize disks created by it, but disks formatted by the external were hit and miss. Therefore, format all disks on the platform which works consistently on both platforms. Set this disk aside, and use the rest of your floppys to copy the contents of the rest of the Install Disks. The Installer tends to prefer that the contents of "Install Disk 3" match with the name of the floppy disk, although this is not always necessary. If you have fewer than 19 install disks (hey, it's been awhile since their heyday) then once the Installer is done with one disk, drag the contents of the floppy disk to the Trash on the transfer Mac and put the contents of the next disk on it.

Try to install only applications and so forth that are only required. An SE/30 has a 1 bit display, and unless you have a color or attached secondary monitor, you don't need Monitors. You don't need Color for the same reason. If you live in the US, you don't need Numbers, Text, Keyboard isn't really required, Easy Access if you're not handicapped, CloseView if you have good eyes (it's only useful on larger monitors with a higher resolution), Control Strip only works on PowerBooks, Energy Saver is not compatible with the SE/30, and so forth. Make sure to install all the Networking Software except A/ROSE, which you don't have or need. TokenRing is debatable as to its necessity. You don't need to double or triple-install software (ie: don't install TCP/IP under Control Panels, TCP/IP under Networking Software, and TCP/IP under Extensions...). Also install Network Software Selector.

The author found that the Installer would fail for unknown reasons if too much was selected to be installed at one time, so installation in steps was required: Base System Software for this Macintosh, then restart, then install Apple Menu Items, restart and install half the Control Panels you need, restart and install Extensions you need, and so on.

Once you have done so, install the 7.5.5 Update. This will involve the same work as above, but as before, always set Install Disk 1 aside and do not erase its contents since the Installer will ask for that specific disk back (just like Windows when it brings up the blue screen demanding that disk with serial number _____-_____ be inserted) to complete it. If you try putting the contents of Install Disk 1 as with the rest of the parts 2-19 on a different disk, rename it Install Disk 1, it still won't work -- so don't dig yourself a pit to fall into. 

#### 2.2 Installing the Additional Software for 7.5.5

At this point, the author suggests you make an backup of your System Folder in case it gets corrupted. [Compact Pro](http://www.cyclos.com/compactpro.htm) is a very good tool for this ([source](http://www.tidbits.com/static/html/TidBITS-042.html)) since it offers high compression and does so speedily. The author also segmented the archive into 6 parts that would fit onto 1.44MB floppies in case of an emergency (it was only about 9MB uncompressed -- a large portion can be save by not installing Apple Guide).

Then install OpenTransport 1.1.2, which can be found from the same location (You only need Install Disk 1 and 2; without OpenTransport 1.1.2, AppleShare 3.7.4 cannot be installed). Your next step is to install AppleShare Client 3.7.4 and Chooser 7.6.1 (optional). Chooser 7.6.1 can be fetched by using [TomeViewer](http://download.cnet.com/TomeViewer/3000-2072_4-4574.html) to search the Install Tomes under /Legacy Recovery/Mac OS/System Updates/Mac OS 7.6.1 Update/ and Extract it to a folder which is convenient, then drop it into the /MacintoshHD/System Folder/Apple Menu Items. AppleShare Client 3.7.4 can be fetched from here. While that is working, fetch OpenTransport 1.3 from /Legacy Recovery/Mac OS/System Updates/Mac OS 8.1 Update/Mac OS 8.1 Update.smi/Update Install Pieces/Software Installers/System Software/OpenTransport Software/. You also only need Install Disk 1 and 2 for this Macintosh. Install and restart the SE/30. All the drivers should be installed for your network card.

For a RAMDisk, the author recommends ramBunctious 1.3.1, as RAMDisk+ 3.23 (v.2.01 won't work with OS 7) would result in this: 

![1](/mac/se30-network/1.jpg)

*Could this work?*

...Yeah, we like to have a menubar in MacOS. The only way out of this hole is to use SystemPicker to restart the computer. The problem with ramBunctious is that is takes up a slot as an application, and only works when the application is open (can cause problems with Installer). (The author cannot retrace where 1.3.1 was downloaded from but later versions are [here](http://www.macintoshgarden.org/apps/rambunctious-162))

#### 2.3 Installing System 6.0.8

This is easier if you have the disk images intended for 1.44MB floppy drives [here](http://www.info.apple.com/support/oldersoftwarelist.html) instead of 800KB disks.

System 6 has a unique advantage when installing files. Create a boot 1.44MB disk by formatting a 1.44MB disk, then open Installer and install "Minimum System for this Macintosh" onto the floppy disk. There should be enough space to install RAMDisk+ 2.01. Eject the disk and lock it. Should you need to install software that cannot be on the same disk as the destination, use the RAMDisk to do so.

This procedure will be required if Installer files are copied over by network and not floppy disks. Install RAMDisk+ 2.01 on the hard drive, then open the application (Cannot create a RAMDisk under Multifinder: so move MultiFinder out of the System Folder or reboot without it by going to the Special menu and selecting Set Startup...) and hold down Option key to take control of the application. Set the size in KB to a size that is reasonable for use but leaves enough for applications (2048KB is 2MB, which is enough for just the System Folder). Click Continue then quickly press the mouse button again to stop auto-copying (makes sense if tried on a floppy since it automatically copies all contents and boots into the RAMDisk), then quit the application. Copy the System Folder and any other required bits to the RAMDisk. If you want MultiFinder back just Command+Option+double-click MultiFinder.

Head over to the System Folder on the RAMDisk, then hold down the Command and Option keys while double-clicking Finder. (Try this procedure with a modern OS) This is fantastic if you have to install with a floppy disk which has no room for a boot folder. 

#### 2.4 Additional Software for System 6.0.8

Start by installing Network Software Installer 1.4.5, which comes from [here](http://www.info.apple.com/support/oldersoftwarelist.html) or the Legacy Restore disk. You will also need your Ethernet card drivers if required. AppleShare Workstation 3.5 can be fetched from the previous link. MacTCP is the only way System 6 can connect to the Internet -- this can be acquired from the Legacy Restore CD under /Legacy Restore/Apple SW E-M/. Install all software with MacTCP coming last.

**Do not configure MacTCP or open it if you plan to upgrade MacTCP 2.1** (although you can erase the data in ResEdit). MacTCP v.2.1 can be found [here](http://www.mactcp.org.nz/mactcp.html). 

### Part 3: Hardware

Remove the four screws on the back of the SE/30 using a long T-15 Torx. Install the 030 PDS card and replace the cover. If you have a different device, such as a SCSI-Ethernet or a EtherTalk device, set it up as directed.

If you're connecting straight to a router, then a standard Ethernet cable will work. If you are connecting to another Mac using the Ethernet cable, you must use a crossover cable (The SE/30 is too old to have automatic straight or crossover switching). You can modify your own by slicing the cable open and switching two wires (search the Internet for this). If you are going into a router, plug the SE/30's cable into one of the proper slots on your router (not the Input for Internet), if you're going into a computer, just plug it into the other computers Ethernet port. 

### Part 4: Setup and Connecting

#### 4.1 Connecting with 7.5.5

##### 4.1.1 Mac OS 9 Connection

On the OS 9 computer (or really, any other computer 7.5.5 to 9.2.2) set TCP/IP to Ethernet, and Using DHCP Server. Make sure AppleTalk is set to Ethernet. Open File Sharing. Set machine and username if required. Start File Sharing. Right-click on the boot drive, or use Command+I to Get Info. Select Sharing, then set as you deem fit.

On the SE/30, open Network Software Selector, and tick Using OpenTransport Networking (Classic AppleTalk can also be used, but OpenTransport simplifies setup for OS X). Reboot the machine. Open AppleTalk. Select Ethernet from the drop down menu. Quit and open TCP/IP. From the top, select Ethernet, and then "Using DHCP Server". 

![2](/mac/se30-network/2.jpg)

*This is the selection you should use.*

![3](/mac/se30-network/3.jpg)

*OpenTransport selection.*

![4](/mac/se30-network/4.jpg)

![5](/mac/se30-network/5.jpg)

You can also set both computers up manually, like this: just use a different IP address in the same subnet (subnet is the 0 in this case, the third group of numbers) like 192.168.0.2.

Close and open Sharing Setup. Set machine name and username, and start File Sharing. Select the hard drive, head to /File/Sharing... and set as necessary. (If only Registered Users should connect, then leave these settings alone - you will need to enter the username and password of the other computer to mount it: otherwise if set so Everyone can mount see the drive, then Guests can have access privileges)

Now either computer can connect to either one using the Chooser. 

![6](/mac/se30-network/6.jpg)

This is the host computer's Chooser. The other side is identical.

##### 4.1.2 Mac OS X Connection

First set the SE/30 to the setup for Mac OS 9 shown above.

Shareway IP is a third-party application that can tunnel the AFP protocol through TCP/IP, thus allowing vintage computers to connect to OS X machines much easier. However, this does not mean that this application (~$50US) is required.

A note about Internet Sharing: If you already use a host machine for internet access over Wifi, you are in shape. If you only want to use the computers to connect to each other without regard to the Internet, then you can use the Ethernet ports. However, if you want to allow the SE/30 to connect also to the Internet, you must establish a connection from the SE/30 to your router using straight CAT 5e cable. If you are using Wifi for Internet, then follow the steps below to share the Internet to your SE/30 and file share at the same time. 

1. In the case of 10.0 or 10.1, please upgrade to 10.2.8. It is much more reliable and robust.
1. Mac OS X 10.2.8 can initiate a connection using Go from the Finder menu. The SE/30 can be mounted just as traditional file sharing did in the past.
1. 10.3 Panther should be the same, the author only verified access with 9.2.2, 10.2.8, 10.4.0 and 10.4.11; and as such only those methods are demonstrated below.
1. Mac OS 10.4.x cannot initiate a connection to your pre-OS 8.6 computer, because it cannot handle the AFP protocol.
1. For Mac OS 10.5 Leopard, reports indicate that you must use the "Server IP Address" in the Chooser -- this must be the IPv4 Internal address (eg: 192.168.0.6).

See [here](http://main.system7today.com/articles/leopard/tutorial1/index.html) for more on this.

##### 4.1.2a Mac OS 10.2.8 Jaguar

Open System Preferences. Click Network. Select "Show" to Built-in Ethernet. Set as shown below, and enable AppleTalk under the AppleTalk tab. 

![7](/mac/se30-network/7.jpg)

*Your settings should be identical to this.*

Then head to the Sharing pane. Turn on Personal File Sharing, select Personal Web Sharing if you intend to share the Internet connection (and enable it under the Internet tab). If you want Guests to connect, set the proper permissions under Get Info for the volume. Open the Go menu, and select Connect to Server...; the SE/30 should show up after a little bit. Double click it or click Connect and login. Easy as cake layered on pie; but that wasn't Apple approved for future versions. 

![8](/mac/se30-network/8.jpg)

![9](/mac/se30-network/9.jpg)

*Connection dialogue box.*

##### 4.1.2b Mac OS 10.4.x Tiger

Apparently Apple likes to keep pushing, and pushing hard. So with the next version of AppleShare, you will get this trying to connect to your SE/30:

![10](/mac/se30-network/10.jpg)

This is not optimal. (This appears whether you have the TCPQuantam hack or not).

Right. This doesn't work. But you can initiate it from the SE/30 end. To do this, first set up the OS X machine by using an Apple-sponsored TCPQuantum hack to do this.

Open System Preferences. Click Network. Select "Using DHCP" protocol. Click the AppleTalk tab, and make it active. If you cannot enable AppleTalk, then open Directory Access (Utilities folder) and enable it there, then go back and make it active. 

![11](/mac/se30-network/11.png)

*This should be like yours.*

Click the Sharing pane. Disable Personal File Sharing. Open Terminal. Paste this into the command line:

```
sudo defaults write /Library/Preferences/com.apple.AppleFileServer TCPQuantum -int 327680
```

Enter your password. If it is successful, nothing unusual should appear after your line:

![12](/mac/se30-network/12.jpg)

*Should be pretty easy.*

Go back to Sharing. Enable Personal File Sharing, Personal Web Sharing (if you intend to share the network connection to the Internet). Click the Internet tab. Set "Share your connection from: _____" to Airport, Firewire, USB, Bluetooth or whatever is not Ethernet. Set "To computers using" to Ethernet. (You cannot share an incoming Ethernet connection to an outgoing Ethernet connection: use a router for this instance). 

![13](/mac/se30-network/13.png)

*These settings worked.*

Go to your home folder (~/Public/Drop Box for you Unix nerds) and open the Public folder, then Drop Box. Right click or Control-click it or press Command+I for Get Info. Look down to "Ownership and Permission" and make sure that these settings are in line with what you intend to do. If you want to transfer files back and forth, "Others" should be set to "Read and Write", if you want a different setting then you may have to set it differently (or just login as a Registered User, which grants full access to the volume). 

![14](/mac/se30-network/14.png)

*Settings for Internet Sharing.*

This side is now ready. Go to your SE/30, enable OpenTransport Networking if it is not already enabled, AppleTalk to Ethernet, File Sharing should be on, TCP/IP to DHCP protocol. Your SE/30 will acquire its internal IP address as shown below from the host Mac, but external IP addresses will be the same. For instance if your external IP address on your host Mac is 204.56.127.24, then your SE/30 will also have this external address.

Open Chooser, and click AppleShare. Your host Mac should appear. Select it and click the OK button. Using a Guest login saves you from hassle concerning passwords and usernames. 

![15](/mac/se30-network/15.jpg)

*Behold! It appears!*

![16](/mac/se30-network/16.jpg)

*You only can choose Guest if the volume permits it. If using Registered User, enter the information of the OTHER computer.*

![17](/mac/se30-network/17.jpg)

*File Sharing! How long have we come since floppies?*

![18](/mac/se30-network/18.jpg)

*Copying iCab.*

You can now Internet browse and file share at the same time. Don't be surprised if it is slow -- the best the author has observed over an Internet download is 66KB/sec, and that was with an Internet connection on the host Mac that has topped 1.9MB/sec max with an average of 1MB/sec. Despite this, it sure beats floppy disks (about 12KB/sec write). This has to do with the hardware limitations of the SE/30. 

![19](/mac/se30-network/19.jpg)

*This is cool.*

![20](/mac/se30-network/20.jpg)

*You can also mount CD volumes, and should be also able to mount USB Flash drives. Yes, of course, Max Payne will run on this computer.*

##### 4.1.3 Encoutered Issues

* **System hangs before loading control panels.** This happens likely because AppleShare is unable to load correctly. Turn the machine off manually, hold down Shift while rebooting until "Extensions Disabled" appears. Head to the System 7.5.5 folder and trash the AppleShare Prep and AppleTalk Prefs files. Reboot. This can also happen if the Installer is not used to install AppleShare, in which case the system will bomb.
* **All connections are good and settings are good, but the computer does not appear in Chooser.** Try entering the IPv4 address (for instance, mine at this moment is 192.168.0.4). Usually if a computer cannot be detected the "Server IP Address" method won't work. This usually works. You will need to enter your own Internal IP address it is likely different. (It's under the Sharing pane of System Preferences.

![21](/mac/se30-network/21.jpg)

* **The connection automatically terminates after about two hours.** No solution for this issue has been found yet. It could relate to the auto-disconnect feature in OS X, however the author still encounters this issue even when it is off. We hope you don't get this whilst transferring a large file.

![22](/mac/se30-network/22.jpg)

* **The Chooser returns this dialogue box whether double-clicking on the server name or entering the Server IP Address:** Try rebooting the target computer.

![23](/mac/se30-network/23.jpg)

#### 4.2 Connecting with 6.0.8

First, a compatibility list:

* In the case of 10.0 or 10.1, please upgrade to 10.2.8. It is much more reliable and robust. (Yes this line was just copied, but it bears repeating)
* Mac OS X 10.2.8 cannot connect to the 6.0.8 computer. The target computer can however mount the OS X volume.*
* 10.3 Panther should be the same, the author only verified access with 9.2.2, 10.2.8, 10.4.0 and 10.4.11; and as such only those methods are demonstrated below. 
* Mac OS 10.4.x and above cannot initiate a connection to your 6.0.8 computer, because it cannot handle the AFP protocol.

System 6 configuration with MacTCP is nonetheless tricky, and can only connect to a 9.2.2 to (likely) 10.3 Panther Macintosh. Your configurations may vary. System 6 can initiate a file transfer with OS 9.2.2, but it cannot be detected and mounted by the 9.2.2 computer. Principally, OpenTransport and associated drivers are meant for AppleShare connection ease -- nonetheless those memory hogs came after System 6. The only way to connect computers in System 6 is via AppleTalk/LocalTalk or through MacTCP. 

##### System 9.2.2 Connection

Setup the OS 9.2.2 computer as before. The following sequence of images will hopefully communicate the message on the System 6 side.

![24](/mac/se30-network/24.png)

*These are my MacTCP 2.0.6 settings.*

![25](/mac/se30-network/25.png)

*Connected under System 6 to 9.2.2.*

It appears that under "Routing Information" should be the IP address of your router (or the Internal IP address [eg 192.168.2.4] of the host computer), under Domain Server Information, the IP address is the IP address of your Internet Service Provider's Domain Name Server (this one is shown for Charter, no idea if it is correct). Leave a period under Domain (a full stop); under IP address, let "Net" set itself, set to Class C. You set your own Internal IP address when you finish this window (see below). 

![26](/mac/se30-network/26.png)

*After those settings are set, you can set your Internal IP address.*

It does not appear in the author's case to matter whether Ethernet or EtherTalk is selected. 

##### Mac OS 10.2.8 Connection

OS X 10.3 Panther is very likely similar to this system, and should be identical. For this test the author used 10.2.8, and in order for the System 6 computer to connect to the host computer, an additional step is required.

Go to System Preferences and disable Personal File Sharing. Open NetInfo Manager (Utilities folder). Authenticate the user. Click /config/AppleFileServer/. Scroll down until you see "use_appletalk", and double-click the field next to it and change the value from 0 (false) to 1 (true). Authenticate the changes, quit and renable Personal File Sharing. AppleTalk should have already been on prior to this, but this step likely enables a backwards-compatible version of AppleTalk for use with older computers. 

![27](/mac/se30-network/27.jpg)

*Here are your settings window. This is the before image -- follow directions above.*

Head to the System 6 computer, and using Chooser, mount your volume. The only folder you can mount is your Public folder, unless you apparently use SharePoints to mount additional folders. (Changing folder permissions won't work in this case) Try to avoid handling volumes that are larger than 2GB (2048MB) because HFS cannot address more than 2GB volumes. 

![28](/mac/se30-network/28.png)

*This is the Drop Box folder. Note the file size is shown in bytes: for reference 2GB is 2,097,152KB, the max System 6 can address.*

##### OS 10.4 and Above Connection

The System 6 computer might be able to see the OS X 10.4 computer, but connection cannot be established (it will say that an error occurred). If you must transfer files, the only procedure that could work is with terminal emulation software (eg ZTerm) or FTP. 

![29](/mac/se30-network/29.png)

*This is what you see trying to connect to the 10.4 computer.*

### Part 5: File Transfer Protocol (FTP)

FTP protocol has changed little in the years since its initiation, and that is why it makes a good choice for online file transfer if the facilities exist. There are two sides, a client and a server; you will need the client if you are accessing the server and a server application if you are hosting an FTP server. Mac OS X has a built in FTP server. 

#### System 7.5.5 FTP Setup

This is easy once the computers can already file share with AppleShare, although the author did not try external FTP addresses. For an OS X machine, simply enable FTP Access under the Sharing pane. For this the author used Fetch 2.1.2, although this exact client is not required -- but it fits onto a floppy disk and runs under System 6. You can get it [here](http://www.jagshouse.com/software/WebKitPart2.sit.hqx).

Setup and operation is shown below:

![30](/mac/se30-network/30.jpg)

*This is the setup window. Enter the Internal IP address of the host computer. "/" designates the root level of the drive in UNIX terms.*

![31](/mac/se30-network/31.jpg)

*And we are hot.*

It's as simple as that. You really shouldn't have to set up the SE/30 as an FTP Server, however that doesn't mean it isn't possible. The author did not attempt any FTP server work because AppleShare was already good enough, and FTP will only be required in certain cases. There are other FTP clients (like Transmit 1.6, which would bomb) but 2.1.2 is fine. 

#### System 6.0.8 FTP Setup

This is possible under System 6, but the author has not been able to establish it under the arcane web of settings that MacTCP requires to function correctly.

### Part 6: Internet and Email

#### Web Browsers

The best browser for System 6 is likely MacWWW, which is well reputed for crashes and bombs. It's about the only one that can remotely work: don't be surprised if you get a very limited, if not corrupted view of the webpage. Use System 7 for your own sake. Some delight themselves with old school Web browsing with Lynx on a Plus with a single floppy disk and 1MB RAM. But this does not likely describe you.

For System 7, the best is iCab 2.9.9, but it is heavily loaded, bombs when trying to set the colors for the background on an SE/30, the dialogue box for Preferences is too large for the monitor, and is slow. Despite this, it does, for the most part, work:

![32](/mac/se30-network/32.jpg)

*Not too bad...*

It is really meant for a Blackbird (IIfx) or higher. You will have an easier time with mobile websites (eg: http://m.yahoo.com/) which are stripped down for handheld and mobile devices. These days with heavy JavaScript, CSS and Flash coding liberally sprayed over most websites will really bog down your SE/30. For the most part, your SE/30 should only be used to show off Internet access to your friends and doubters, since it's too slow to practically work (figure 3 minutes to send an email or load a page). MacWeb can also work, but the rendering is not as good as iCab. iCab only runs under System 7.

![33](/mac/se30-network/33.jpg)

*iCab sending an email. It took 3 minutes to restore cursor control after pressing Send.*

There are other browsers, like Netscape 2.02, has issues with JavaScript; nonetheless if it is a simple text website with few graphics, it is faster than iCab. You are free to explore this route and experiment, but don't be surprised if something doesn't work very well, simply because the modern HTML and page design has changed so drastically. Additionally, very few websites (gopher proxies can work with your machine) are designed with simplicity in mind. 

![34](/mac/se30-network/34.jpg)

*This is Netscape 2.02.*

![35](/mac/se30-network/35.jpg)

*A simple website, like this one, is the only type that will render correctly.*

#### Email Clients

An email client requires SMTP, POP3 or IMAP protocols to work correctly. If your email address is established through your ISP and you can access your email in an application like Mail, Outlook, or similar, then you have those protocols established. Free Yahoo! mail does not include POP3 protocols, however there are other free email services (like gmx.co.uk) which offer those connection protocols.

The hard part these days is that SMTP or SSL authentication is established by modern email systems, which wasn't established in the 68k days with the same degree of intensity as these days.

This section will probably be updated (if time permits) later -- the author has experimented with a number of different clients and could not get them to work in a reasonable period of time.

