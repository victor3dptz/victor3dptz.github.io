---
layout: page
title: A/UX System Software
---

### My system

**UPDATE**: I purchased a Centris 610 motherboard on eBay to replace my non-ethernet board and I noticed it had a full 68040 33mhz chip (though runs at 20). I put together a complete system with 52mb RAM, 250mb HD, 230mb HD, and an Apple 14" monitor and installed A/UX with no trouble. I also had a PPC 601 upgrade card but I removed it because it generates quite a bit of heat even when not in use. Read the "how to install" section for info on 68040 systems and A/UX. I will also add new screenshots soon.

For this experiment, I went with a Macintosh IIci (25mhz 68030) with 20mb RAM, a 250mb SCSI HD, and an external Apple CD 600 (2x). The IIci also has a cache card. For video, I use an Apple 13" RGB display on the onboard port. 

### Screenshots

![1](/mac/aux/Picture-1.jpg)

![2](/mac/aux/Picture-2.jpg)

![3](/mac/aux/Picture-3.jpg)

![4](/mac/aux/Picture-4.jpg)

![5](/mac/aux/Picture-5.jpg)

![6](/mac/aux/Picture-6.jpg)

### How to install A/UX

this document will describe the process of installing Apple's A/UX operating system. to do this, you will need a computer with a cd-recorder, the cdrecord application (or toast for macs), and a 68k macintosh equipped with at least 16mb ram, an 80mb hd, and a cdrom.

### To burn the CD

In Windows - download the gzipped cd image from higher intellect (hotline://preterhuman.net). download cdrtools from somewhere. extract the cd image to the cdrtools folder. open a DOS window and run "cdrecord.exe --scanbus". find the three numbers representing your cd burner. insert a blank cd into the recorder and run "cdrecord.exe dev=(insert three numbers) imagename". an example for my system is "cdrecord.exe dev=1,0,0 AUX_30~1.IMA"

In MacOS - download and extract the cd image. launch toast and burn the cd image.

In Linux - use the cdrecord command syntax as seen in the windows instructions (untested as i have never burned a cd in linux) 

### To boot A/UX

Download the install floppy image from higher intellect and either rawrite it (in windows), dd it (in linux), or diskcopy it (in macos) to a 1.44mb floppy. now turn on your mac, insert the boot floppy and the A/UX cd. it should boot into the installer script.

**NOTE FOR 68040 USERS**: you will need a system enabler file on the boot disk. If you use a Quadra or Centris that uses the System Enabler 040 then your system should work. Systems that use the 065 enabler might not (I put a full 68040 in an LC 475 and A/UX wouldn't work). Enablers are available at the [Apple FTP](ftp://ftp.apple.com/) site. 

### To install A/UX

Use the buttons to select which drive to install to. then customize the to-be installed software list to match your needs. after you are done, the installation process begins. after the install you should have a bootable copy of A/UX on your hd. NOTE FOR 68040 USERS: if you successfully booted to the install program then your system should work fine, as it has already loaded the A/UX kernel for installation. If your screen goes blank during the A/UX loading phase and stops responding, your machine is incompatible.

I am currently writing a complete newbie guide to building an A/UX machine and getting standard tools working like gcc, httpd, and TCP/IP networking. 
