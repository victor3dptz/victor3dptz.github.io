---
layout: page
title: PowerMac 6100 CD-ROM Upgrades
---

![Logo](/mac/powermac6100/img/06cd.gif) This page describes the options for upgrading the CD-ROM capabilities on the Power Mac 6100 series.

### Introduction

As shown on the default configurations page, most models of the 6100 shipped with a 2x CD-ROM drive. 2x is fine for playing audio CDs and for installing the occasional piece of software, but for playing multimedia applications and games, 2x is a bit slow.

You should be able to install any SCSI CD drive in the internal CD-ROM bay, but there are some potential issues with power supplies and heat dissipation, especially with CD-R and CD-RW drives. You cannot install any IDE, EIDE or ATAPI drive in a 6100 without a hard-to-find adapter that is occasionally stocked by an Australian distributor. I haven't yed had any reader feedback on one of these doodads.

When my original Apple 300i 2x drive died, I replaced it with the same model because I had read that there were issues around booting from a non-Apple CD drive. As it turns out, that is no longer true (see below). As it turns out, I could have bought a much faster drive for the same money. Oh well.

Most recently, I purchased an external CD-RW drive for mastering CDs. So far it has worked quite well. I've burned a few usable CDs and made a couple of coasters, too.

### How to install an internal CD drive in a 6100

This section describes how to replace/install an internal CD-ROM drive in a 6100. An even simpler solution would be to attach an external CD drive. But if you're going to install an internal drive, here's what to do:

#### Step 1: Install any necessary drivers

If you're replacing or upgrading an existing CD drive, you probably have all the necessary drivers already. If you are installing a CD drive for the first time, make sure you have recent versions of the following:

File | Most Recent Version | Function/Description
---- | ------------------- | --------------------
Apple CD/DVD ROM Driver | 1.2.2 | Provides core functionality for reading CDs from a CD-ROM drive. Also provides DVD ability on newer Macs equipped with DVD drives and decoders
Foreign File Access | 5.2 | Along with the extensions listed below, allows Macs to read other formats, such as ISO 9660, UDF, Audio, PhotoCD and High Sierra
Audio CD Access | 5.1 | Permits Macs to read Audio CDs
High Sierra File Access | 5.2 | Allows Macs High Sierra File format discs
ISO 9660 File Access | 5.2 | Allows Macs to read ISO 9660 File format discs 

Even if you don't currently have a CD-ROM drive installed, you probably have the drivers installed. Use your Extensions Manager control panel to look for the files listed above. If you still can't find them, you can re-install them from your Mac OS installation disks. If you don't feel like messing with the installer, you can use TomeViewer to extract only the necessary files.

If you are installing a third-party (i.e. non-Apple) drive, it may require a model-specific driver. The most recent version of Apple's driver should work with most SCSI CD-ROM drives, though. Some CD-RW drives will require a special driver, such as Adaptec's Toast CD Reader extension, in order to read CDs. This driver is usually included in the bundled software.

If you don't have a third-party driver, there may be other options as well. I haven't tried any of these, but some of them may enable an "unsupported" drive to work:

* A Resexcellence hack of the Apple CD driver,
* A c't hack
* An extension called CD Sunrise that provides limited (i.e. data-only) support
* Version 5.3.1 of the Apple CD driver (supplied only with Mac OS 7.6) is supposed to support any drive as well. If you have ever owned 7.6, use TomeViewer to get that extension out of the installer files. 

This might be a good time to install the excellent freeware control panel SCSI Probe, too. You may not need it, but then again, you might.

#### Step 2: Open the computer

Turn off the computer, but leave it plugged in. If the power cord is attached to a power strip or surge protector, leave that turned on, and turn off the computer using its own power button. This is important to allow you to dissipate any static electricity and prevent you from frying any sensitive components.

Pull up on the small tabs at the back of the computer. Each of them should snap free, and the entire top of the case should rock forward. Rock it forward until it comes free of the computer, and set it aside.

Remove any residual static electricity your body may be carrying by touching the power supply (the big metal box at the back of the computer). Better yet, buy and wear an anti-static wrist strap. Also, remove any wool sweaters you may be wearing and banish the cat from the room until you're finished.

#### Step 3: Disconnect the old CD-ROM drive

Remove the power cable (four wires, white plastic connector), the SCSI cable (grey ribbon cable, wide rectangular connector), and the audio cable (narrow ribbon cable, four wires) from the back of the CD-ROM drive by firmly, but gently pulling them straight back towards the rear of the computer. The power connector and the audio connectors usually are quite stiff.

#### Step 4: Set the SCSI and termination jumpers

Jumpers are little rectangular thingies that make connections between two jumper pins on a circuit board or device. Jumper pins are tall, thin, rectangular metal posts, and they come in pairs. A jumper itself slides onto the pairs of pins to make the connection. To turn a jumper "on", slide one onto the pin pair. If you turn a jumper "off", pull it off with a pair of needlenose pliers. If you need to turn a jumper on and you don't have one, you'll probably have to head out to your local electronics store and ask for some. They should cost pennies, if anything. If you look at your CD drive, you will probably find jumper pins in two rows labeled J0-J2 or something like that.

Set the SCSI ID number for the new drive. You probably want to use the same ID number as the old drive. Check the old drive to be sure, but it's usually #3. Your CD-ROM drive should have come with a diagram showing the location of the SCSI ID jumpers or switch. To pick a SCSI ID, use the following table:

ID | S2 | S1 | S0
-- | -- | -- | --
0 | Off | Off | Off
1 | Off | Off | On
2 | Off | On | Off
3 | Off | On | On
4 | On | Off | Off
5 | On | Off | On
6 | On | On | Off
7 | On | On | On 

On a 6100, the CD-ROM drive is almost always connected to the middle of the internal ribbon cable. In this case, the hard drive is the last device on this segment, and so you should turn the termination off.

If your chain is configured so that the CD-ROM drive is at the end of the chain, you'll need to turn the termination on.

Consult the documentation that came with your device to find the location of the termination jumper or switch.

#### Step 5: Replace the old drive

To remove the old drive, remove the thin metal shielding in **front** of the old drive by prying up the top edge that folds over the top of the case, then pulling that forward until it pops off.

Locate the beige plastic locking tab and lift it up gently while pushing the drive forward towards the front of the case. The drive and the plastic "sled" or carrier should slide out of the case.

Turn the drive over so you can see the screws that mount the drive to the sled. Gently remove the four screws. Place the sled against the new drive and replace the four screws. Do not overtighten the screws.

Slide the sled and drive back into the case until they click into place, then reattach the cables. All connectors are keyed and will fit only one way. The power and SCSI connectors should be fairly obvious, as they're in the middle of the daisy chain cables that run to the hard drive. The audio ribbon cables run from a little 4-pin connector on the CD drive to a matching 4-pin connector on the motherboard that is labeled "J10." Boot the computer with the new drive before you close it up, just to make sure that it works.

#### Step 6: Close up the computer

Tilt the cover towards you about 45 degrees, and align it with the front of the case. Slide it onto the case until the front parts appear to be engaged, then rotate the back down and press down on the tabs until they click. If they don't click, you may have it slightly misaligned. Remove it and start over.

### How to attach an external CD drive to a 6100

#### Step 1: Install any necessary drivers

If you already have or ever had an existing CD drive, you probably have all the necessary drivers already. If you are installing a CD drive for the first time, make sure you have recent versions of the following:

File | Most Recent Version | Function/Description
---- | ------------------- | --------------------
Apple CD/DVD ROM Driver | 1.2.2 | Provides core functionality for reading CDs from a CD-ROM drive. Also provides DVD ability on newer Macs equipped with DVD drives and decoders
Foreign File Access | 5.2 | Along with the extensions listed below, allows Macs to read other formats, such as ISO 9660, UDF, Audio, PhotoCD and High Sierra
Audio CD Access | 5.1 | Permits Macs to read Audio CDs
High Sierra File Access | 5.2 | Allows Macs High Sierra File format discs
ISO 9660 File Access | 5.2 | Allows Macs to read ISO 9660 File format discs 

Even if you don't currently have a CD-ROM drive installed, you probably have the drivers installed. Use your Extensions Manager control panel to look for the files listed above. If you still can't find them, you can re-install them from your Mac OS installation disks. If you don't feel like messing with the installer, you can use TomeViewer to extract only the necessary files.

If you are installing a third-party (i.e. non-Apple) drive, it may require a model-specific driver. The most recent version of Apple's driver should work with most SCSI CD-ROM drives, though. Some CD-RW drives will require a special driver, such as Adaptec's Toast CD Reader extension, in order to read CDs. This driver is usually included in the bundled software.

If you don't have a third-party driver, there may be other options as well. I haven't tried any of these, but some of them may enable an "unsupported" drive to work:

* A Resexcellence hack of the Apple CD driver,
* A c't hack
* An extension called CD Sunrise that provides limited (i.e. data-only) support
* Version 5.3.1 of the Apple CD driver (supplied only with Mac OS 7.6) is supposed to support any drive as well. If you have ever owned 7.6, use TomeViewer to get that extension out of the installer files. 

This might be a good time to install the excellent freeware control panel SCSI Probe, too. You may not need it, but then again, you might.

#### Step 2: Set the SCSI ID and termination

Set the SCSI ID number for the new drive. You will need to use an ID that is not being used for anything else. Two devices with the same ID will cause problems booting, and could damage the devices and/or the computer.

The internal HD is usually set to 0, an internal CD-ROM drive is usually set to 3, and a Zip drive is set to 5 or 6. Your CD-ROM drive should have come with a diagram showing the location of the jumpers, push-button switches, or the rotary switch for setting the SCSI ID.

If your CD drive is the last device on your SCSI chain (physically, not numerically), then it must be terminated. If your drive did not come with a terminator (short, fat thing with a SCSI connector), either buy a terminator or else rearrange the chain so that a terminated device is at the end.

#### Step 3: Attach the SCSI cable(s)

Most SCSI drives wil ship with a SCSI cable, but some of the lower-priced ones (like my CD-RW) do not. You need to use a SCSI cable. A 25 pin SCSI cable looks an awful lot like a parallel cable for PCs, but they are not the same.

Your Mac has a 25-pin SCSI connector, as do Zip drives and most scanners. External drives can come with 50-pin Centronics connectors or 25-pin connectors, but you can buy adapter cables that convert from one to the other.

### Some notes on Bootability

In earlier times, Macs could not boot from non-Apple-branded CD-ROM drives. Things have changed for the better. Either the OS, the CD-ROM driver or both have been re-written to permit booting from almost all drives. I don't know which are the earliest versions of the OS or the driver that permit this, but I'm trying to track it down.

There are several ways to boot from a CD: 

* Use the Startup Disk control panel to select a bootable CD
* Boot while holding down the keys Command-Option-Shift-Delete or Command-Option-Shift-Delete-#, where # is the SCSI ID of the drive from which you wish to boot
* Boot while holding down the C key 

The last option appears to work only when booting from an internal drive, at least on my machine.

### A little bit about CD-R and CD-RW drives

The 6100 series should work with any SCSI CD-R or CD-RW drive, but from everything I've read so far, you should stick with external models only. CD-R and CD-RW drives generate significantly more heat than a CD-ROM drive, and the 6100 does not have a case that is conducive to good airflow for cooling.

Personally, I have an external CD-RW drive--a Computer411-branded drive with Yamaha 4416S internals. It came fully assembled in an external drive housing with a power cable, one piece of CD-R media (worth about a buck), and a CD containing Toast version 3.5.6. PC software is included on the CD as well (EasyCD version ?.??). I chose a cheaper model that did not include a SCSI cable or terminator (I had these lying around) and saved myself about $15. A free updater to Toast 3.5.7 is available on Adaptec's website.

So far everything's gone fine. I can boot from the external drive, and it will mount CDs as long as I have the Toast CD Reader enabled. I've used the drive to make audio CDs, Mac-formatted CDs, a hybrid CD and a bootable Mac CD.

Most of the discs I've burned have worked. Some didn't quite work the first time and had to be removed and reinserted, which is a bit strange. Clearly there's some voodoo involved in burning CDs.

I've also burned a couple of coasters (CD-lingo for a useless disc). I haven't quite figured why things sometimes work and sometimes don't, but CD-R media is inexpensive enough ($1/blank CD) that it's not too big a deal. It might have had to do with conflicting drivers from CharisMac's Discribe, or with interruptions in the writing process from having virtual memory turned on.

