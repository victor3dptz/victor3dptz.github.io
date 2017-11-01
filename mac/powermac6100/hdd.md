---
layout: page
title: PowerMac 6100 Hard Drive Upgrades
---

![Logo](/mac/powermac6100/img/05hdd.gif) This page describes the options for upgrading the internal hard drive on the Power Mac 6100 series.

### Introduction

As shown on the default configurations page, the 6100 shipped with a fairly small hard drive. 500 MB was a decent size back in 1995, but that was aeons ago in computer time. I filled my HD up within the first 6 months of use. From that point on, I carried on a tedious campaign of browsing through its contents, purging documents, compressing others, transferring archives off to removeable media, etc. I resisted buying a new HD because of the cost and because of the perceived complexity. I thought it would be difficult. In retrospect, it was :) But that's why I'm writing this for you.

Alternatively, you may have picked up a "stripped" 6100 that came without a hard drive. This guide will help you install one.

The internal drive bay in the 6100 can house a hard drive of the standard 3.5", 1" high (e.g. "low profile") form factor. Several manufacturers are shipping models in this form factor with sizes up to 73 GB. There are some potential issues with power supplies and heat dissipation, but I haven't had any so far with my model.

I replaced my old 500 MB hard drive with a Quantum Atlas II, 4.5 GB, 7200 rpm HD which I purchased for $255 from OtherWorld Computing. I opted for the narrow version so I could accomodate my video card. There are narrow drives up to 18 GB still being sold.

### SCSI/IDE

The 6100 natively supports only SCSI hard drives. SCSI (pronouned "scuzzy") is short for Small Computer Systems Interface, and was commercialized/popularized by Adaptec (spun out of Shugart) back in the 1980's to standardize the interface for high-bandwidth peripherals. Other types of hard drives, meaning IDE, EIDE, ATA, Ultra-ATA or UDMA are not supported and cannot be used without special adapter boards.

> #### Interesting sidebar

> I just received email from a reader who is using a $70 IDE-SCSI adapter to hook an external 30GB Ultra-ATA drive to his 6100! The retailer he bought from is currently out of stock, and the manufacturer of the bridge device, IOData, does not sell direct, but this could be a very promising development. This adapter is not intended to be used in such a small enclosure, but that's never stopped an enterprising 6100 owner before :-)

> In the words of my reader, his new drive has "been working flawlessly and booting 7.5.5, 7.6.1 or 8.6 from my 3 Mac OS partitions."

> IDE/ATA hard drives are far, far cheaper than SCSI drives, especially at the larger sizes, so even with a $70 adapter this could be great money saver, especially if you have friends or employers who are casting off old IDE/ATA drives because they are replacing them with bigger ones. I just bought a 40GB ATA hard drive for $140 for use in another computer, and prices seem to drop every day.

> That said, most users will probably have to go the SCSI route. But I'll update this section if I see anything interesting.

The SCSI bus itself has several different flavors. There's a more complete explication at Adaptec's website, but here's a short summary:

Type/Name(s) | Connector Pins | Max Speed | Compatible w/6100 |	Comments
------------ | -------------- | --------- | ----------------- | --------
SCSI, Slow SCSI | 50 | 5 MBps | Y | 8 bit SCSI. The original.
Fast SCSI | 50 | 10 MBps | Y | The original SCSI with a doubled clock rate
Wide SCSI | 68 | 10 MBps | Y w/adapter | 16-bits wide
Fast Wide SCSI | 68 | 20 MBps | Y w/adapter | 16-bit version of Fast
Ultra, Ultra (Narrow) SCSI | 50 | 20 MBps | Y | 8-bit, clocked even faster
Ultra Wide SCSI	68 | 40 MBps | Y w/adapter | 16-bit version of Ultra
Ultra2 SCSI | 68 | 80 MBps | Y w/adapter | 16-bit, with super fast clocks enabled by low-voltage differential (LVD) signalling
Ultra3 SCSI, Ultra160 | 68 | 160 MBps | Y w/adapter | 16-bit, with ridiculously fast clocks 

* All speeds quoted in MegaBytes per second (MBps), which is different from MegaBits per second (Mbps), commonly used for describing networking speeds. All these drives will operate at a maximum of 5 MBps in a 6100, due to the limitation of the SCSI bus on the computer. Max speed information is provided for reference purposes only (in case you move the drive to another machine with a faster SCSI card)
* Use in conjunction with a PDS video card requires multiple adapters and cabling.

Don't confuse the above terms with terms like "SCSI-1", "SCSI-2" and "SCSI-3." The latter terms refer to the logical protocol or command set running over the physical bus, and is not of much concern to most users since SCSI devices are backward compatible. Much of this information is from a beautiful Usenet posting by David's House of Kumquats.

### SCSI Cables and Adapters

#### Legend:

![HDD1](/mac/powermac6100/img/hdd1.gif)

#### "Standard" Configuration

![HDD2](/mac/powermac6100/img/hdd2.gif)

There are three things in your computer with SCSI connectors--the motherboard, the hard drive, and the CD-ROM--and they're all connected by a single ribbon cable. By default, they're all 50 pins, so only Narrow drives (i.e. anything without the word "wide") will work without an adapter. Buying a 50-pin drive is the easiest way to upgrade. When buying, look for "true 50-pin" drives. Anything accompanied by a note or parenthetical like "(68-50)" or "(80-68)" means that it has (and needs) an adapter. 

#### 68-Pin Drive Configuration

![HDD3](/mac/powermac6100/img/hdd3.gif)

Wide drives have 68 pins and require an adapter somewhere along the path between the drive and the motherboard. Here's one such adapter:

![HDD4](/mac/powermac6100/img/hdd4.jpg)

Placing this adapter on the drive turns it into a 50-pin drive and allows use of the existing ribbon cable, but it will add a 1/2" or so to the length of the drive. Due to the extremely tight space inside the 6100, this makes the drive too long to work with a PDS card. If you don't have a PDS card yet, then this configuration works fine.

#### 68-Pin Drive and Cable Configuration

![HDD5](/mac/powermac6100/img/hdd5.gif)

The other option is to put the reverse adapter on the motherboard connector and run Wide (68 pin) cabling from the motherboard to the hard drive. Since the cabling to the CD-ROM usually tees off this same cable, this configuration also requires another reverse adapter to connect to the CD-ROM drive (which also has a 50-pin connector) to the 68-pin cable. This configuration requires the purchase of a new cable and another adapter, but it allows one to use a PDS card (thanks Kovacs!) in conjunction with a Wide drive since it doesn't change the length of the drive. 

Note that a Wide drive will still operate in Narrow mode, since the SCSI controller is Narrow, but Wide drives are generally more available than Narrow drives, may have faster seek times, and are often cheaper (which may offset the cable/adapter costs).

There is also a special type of connector called an SCA connector for Ultra Wide drives. This is a very small, 80 pin connector that includes data and power in single connector. The intent behind this was to simplify the internal clutter inside newer machines by reducing the number of connectors. This never really became popular with consumer motherboard and SCSI card manufacturers, so SCA drives often sell for less than narrow drives, even with the included 50 pin adapter. I don't know whether the motherboard adapter trick works with SCA or not, but SCA adapters are bulky and require jumpers for setting SCSI IDs, etc. I'd recommend against an SCA drive if you ever plan to put a PDS graphics card in your machine. Then again, if you aren't going to put a graphics card in there, then SCA drives are fine.

### How to install a hard drive in a 6100

This section describes how to replace the internal hard drive of a 6100 with a larger capacity drive. Because the 6100 has only one internal HD bay, replacing the drive involves a bit of shuffling. If you don't have a CD-ROM drive you may be able to place a new hard drive in the CD-ROM bay, thus eliminating a lot of the hassle I encountered. An even simpler solution would be to attach an external hard drive. But if you're set on installing an internal drive, here's what I did:\

* Disconnected the CD-ROM drive
* Connected the new HD in its place
* Formatted and partitioned it
* Copied the entire contents of my old HD to the new drive
* Removed the old HD,
* Put the new HD in its place
* Reconnected the CD-ROM drive 

Physical installation of a hard drive is not difficult, but nor is it intuitive. The confusion arises from the fact that the drive assembly must be removed through the front of the case. But to begin at the beginning:

#### Step 1: Install your drive setup software

Since you'll be disconnecting your CD-ROM drive for a while, you'll have to install any third-party formatting software onto your old hard drive before you begin.

You can also use Apple's Drive Setup on most drives. Earlier versions, such as [Hard Disk Setup SC](/mac/soft/Apple_HD_SC_Setup_7.3.5.sea.bin) require a [minor patch](/mac/soft/HD%20SC%20Setup%207.3.5%20patcher.hqx) to work with non-Apple drives, but newer versions should work without any additional patches.

This might be a good time to install the excellent freeware control panel SCSI Probe, too. You may not need it, but then again, you might.

#### Step 2: Open the computer

Turn off the computer, but leave it plugged in. If the power cord is attached to a power strip or surge protector, leave that turned on, and turn off the computer using its own power button. This is important to allow you to dissipate any static electricity and prevent you from frying any sensitive components.

Pull up on the small tabs at the back of the computer. Each of them should snap free, and the entire top of the case should rock forward. Rock it forward until it comes free of the computer, and set it aside.

Remove any residual static electricity your body may be carrying by touching the power supply (the big metal box at the back of the computer). Better yet, buy and wear an anti-static wrist strap. Also, remove any wool sweaters you may be wearing and banish the cat from the room until you're finished.

#### Step 3: Disconnect the CD-ROM drive

Firmly but gently remove the power cable (four wires, white plastic connector) and SCSI cable (grey ribbon cable, wide rectangular connector) from the back of the CD-ROM drive by firmly, but gently, pulling them straight back towards the rear of the computer. The power connector usually is quite stiff. Note that there is another, narrow, ribbon cable going to the left side of the motherboard. It has four wires and ends in a white connector. This is the audio-output from the CD drive and can be left in place.

#### Step 4: Set the jumpers

Jumpers are little rectangular thingies that make connections between two jumper pins on a circuit board or device. Jumper pins are tall, thin, rectangular metal posts, and they come in pairs. The jumper itself slides onto the pairs of pins to make the connection. To turn a jumper "on", slide one onto the pin pair. If you need to turn a jumper "off", pull it off with a pair of needlenose pliers. If you need to turn a jumper on and you don't have one, you'll probably have to head out to your local electronics store and ask for some. They should cost pennies, if anything.

If you look at your hard drive, you will probably find jumper pins in one or more locations. They are usually labeled on the circuit board as J0, J1, etc., or in sets like S0-S7 or ID0-ID7 or something like that. A set of jumper pins will look like two rows of rectangular metal posts.

##### SCSI ID

Pick a temporary SCSI ID number for the new drive. Since you're not using your CD-ROM drive right now, its old ID is a safe number to use. Check the CD drive to be sure, but it's usually #3. Your hard drive should have come with a diagram showing the location of the SCSI ID jumpers. To pick a SCSI ID, use the following table:

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

If there's a fourth (S3) jumper, it should be off. 

##### Startup settings

Next, find and set the spin delay or Auto-Start jumper, if necessary. If your drive has a spin-delay jumper, take it off. If you drive has an Auto-Start jumper, turn it on.

##### Termination

Finally, figure out whether or not to set the termination jumper. According to the SCSI rules the first and last devices in the SCSI chain must be terminated. The internal HD in a 6100 is usually at one end of the chain, so it should probably have the termination turned on.

#### Step 5: Connect the new HD to the CD-ROM cables

Attach the power and SCSI cables (and adapter, if needed) to the new HD. All connectors are keyed and will fit only one way. You can set the new HD on top of the CD-ROM drive for the time being.

#### Step 6: Format/partition the drive and transfer your data

Turn the computer on. If you've done everything right so far, the machine should boot from your old HD as usual, and then it should attempt to mount your new HD. If your new HD was purchased from a Mac-savvy vendor, it's probably formatted as a single, large Mac volume, and will mount with no problem.

It's a from a PC vendor, or a pull from an old PC, then you may get the message, "The disk Untitled is unreadable. Do you wish to format this disk?" Press Cancel, as you probably will want to set some formatting and/or partitioning options as described later, especially if you're are not running Mac OS 8.0 or later, and the new drive is larger than 2.0 GB. **Under previous versions of the Mac OS, a PowerMac 6100 cannot boot from a partition larger than 2.0 GB, so if your drive is larger than this you _must_ partition it if you want to boot from it.**

After your Mac has finished booting, go ahead and run your third party drive setup software or Apple's Disk Setup (or Hard Disk Setup SC).

Once you've finished setting up the drive, copy over the contents of your old drive. You can use a simple drag-and-drop approach. The only downside to this approach is that some of your aliases may get broken, and you'll have to re-create them.

Once you've copied everything over, check the new copy of your System Folder. Check the icon, either in the icon view or by selecting and choosing Get Info from the File Menu. It should have an icon like

![HDD](/mac/powermac6100/img/SystemFolder.gif)

If it doesn't, it needs to be "blessed." Open the new System Folder and locate the Finder. Drag the Finder out of the System Folder (to the desktop, for example), and then drag it back in. Check the icon again. It should be blessed now.

Try to boot from new drive by selecting it in the Startup Disk Control Panel and rebooting. If it doesn't even appear as a choice in the Startup Disk Control Panel, then it may not have been blessed properly. Note also that startup items may fail or behave strangely if they used aliases.

#### Step 7: Replace the old drive

Assuming everything has worked up to this point, it's time to replace the old hard drive. First, shut down the computer. Disconnect the new HD from the SCSI and power cables, and reconnect those cables to the CD-ROM drive where they belong. Since the new drive will now be the boot drive, set it to SCSI ID 0 by removing any SCSI ID jumpers.

Disconnect the SCSI and power cables from the old hard drive. To remove the old hard drive, remove the thin metal shielding in **front** of the old drive by prying up the top edge that folds over the top of the case, then pulling that forward until it pops off.

Locate the beige plastic locking tab and push it down gently while pushing the drive forward towards the front of the case. The important (and non-obvious part) is that the drive and the plastic "sled" or carrier should slide out the **front** of the case.

Turn the drive over so you can see the screws that mount the drive to the sled. Using a **non-magnetized screwdriver**, (check if you're not sure!), gently remove the four screws. Place the sled against the new drive and replace the four screws. Do not overtighten the screws.

Slide the sled and drive back into the case until they click into place, then reattach the cables and adapter (if needed). All connectors are keyed and will fit only one way. Replace the metal shielding. Boot the computer with the new drive one last time before you close it up. Note that startup items may behave strangely if they depend on aliases that may no longer be valid.

Also, after you boot successfully, check the Startup Disk Control Panel and ensure that the new disk is selected. Since it's SCSI ID 0, it will still boot even if it's not selected, but this may help your computer boot more quickly since it won't have to hunt around for a startup disk.

#### Step 8: Close up the computer

Tilt the cover towards you about 45 degrees, and align it with the front of the case. Slide it onto the case until the front parts appear to be engaged, then rotate the back down and press down on the tabs until they click. If they don't click, you may have it slightly misaligned. Remove it and start over.

### Some notes on partitioning

Partitioning is used to divide a single, physical hard drive into multiple logical volumes that appear to the Mac OS to be separate hard drives. There are many reasons to do this, but I'll describe what I did and why.

I have 9 partitions on my 4.5 GB hard drive as follows: 

Partition type | Size | Use | Contents
-------------- | ---- | --- | --------
Mac OS HFS | 500 MB | Boot volume | System Folder and some utilities
Mac OS HFS | 100 MB | Mac VM | Virtual Memory file
Mac OS HFS+ | 50 MB | Browser cache | Netscape cache folder
Mac OS HFS+ | 1000 MB | Applications | Application programs
Mac OS HFS+ | 1500 MB | Documents | All my documents
Mac OS HFS | 500 MB | Scratch | Empty space for video capture
UNIX | 100 MB | root | Linux root volume
UNIX | 100 MB | swap | Linux swap volume
UNIX | 100 MB | usr | Linux /usr volume 

Ignoring the UNIX partitions for now, I have several different Mac OS volumes for the following reasons. The boot volume is left separate so that I can wipe it clean and install a new system any time I want to without disrupting my applications and documents. Furthermore, 6/7/8100 computers have an older ROM that can't boot from a drive bigger than 2 GB without a driver patch. This patch is installed by Drive Setup 1.6.2 and later, which is included with OS 8 and later. You can use a bigger HD on a 6100 without 8.0; you just can't boot from it. Your computer will recognize the drive just fine after the OS loads, but not before.

If you purchased a larger HD, it most likely came set up as one single, large partition. If this is so, and you're using pre-8.0, you must re-format the drive with a boot partition no larger than 2 GB. You cannot re-size the partition with your disk formatting utility; you must start from scratch.

The Documents volume is separate so that I can back up and restore documents easily. The Applications are left separate simply to keep them out of the way.

The VM volume is placed in a separate partition because the Mac OS's virtual memory system really bogs down if the virtual memory file gets fragmented. When doing audio or video work, I need to turn off virtual memory, which erases the VM file and leaves a big chunk of contiguous blank space. If I keep the VM file in a partition that gets written to by applications or by the system, there is a high likelihood that this big chunk will get written over. Then, when I turn VM back on, the system will not be able to find a contiguous space for the new VM file and performance will go to hell. I also keep a copy of my System file and Finder here. This is for emergencies--if the files on the boot volume ever get corrupted, I can boot from some other disk and restore these files without going through a complete system reinstallation.

The browser cache is a bit of a holdover from the days when Netscape Navigator was unstable and undisciplined with its cache files. When Netscape crashed, I'd often find disk errors in the cache folder. I decided to put the cache in a totally separate partition to minimize any damage to the rest of the system should Navigator decide to start doing this again.

The last volume, Scratch, is for video capture and CD burning. Both applications require a large contiguous (i.e. unfragmented) block of space to prevent errors when writing. I capture video to this space, do my edits, and then move the finished work to the Documents volume and wipe it clean. Similarly, to burn CDs I make a disk image here and burn it to disk, then wipe it clean.

This scheme is overkill. Were I to do it again, I probably would put combine the VM, Scratch and browser cache volumes into one, since the contents of any of these three volumes are temporary.

With regard to my formatting choices, I chose HFS for the boot volume and VM to minimize any potential conflicts with disk utilities and drive setup software. Not all software is fully HFS+ compliant, so I didn't want to take any chances. Furthermore, I also mount this volume as read-only in Linux, and Linux doesn't speak HFS+ yet.

I chose HFS+ for the documents, application and cache volumes for space-saving purposes. Most files take up less space with HFS+ than with HFS, especially small files like those in the browser cache. Using HFS+ minimizes the amount of wasted space on my HD.

I chose HFS for the scratch volume because this usually contains a small number of very large files, and so there is very little space penalty for using HFS. Furthermore, there may be some minor performance benefits to using HFS, and when doing video capture you need all the speed you can get.

