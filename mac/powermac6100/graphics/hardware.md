---
layout: page
title: PowerMac 6100 Graphics Hardware
---

![Logo](/mac/powermac6100/img/07graphics.gif) This page describes the standard hardware configuration of the Apple PowerMac 61xx Series.

### DRAM Video

On all Nubus Power Macs, DRAM-based video is available from the HDI-45 port. On the non-AV 6100 series as it shipped, DRAM-based video is the only option. The 7100 and 8100 shipped with either the Apple HPV card or the Apple AV card, so on these models the HDI-45 provides built-in support for a second monitor. On the Power Computing clones, DRAM-based video is available from a Mac-standard DB-15 connector on the motherboard. If you are searching the Web for further information about the HPV card, it is also referred to by Apple as the **VRAM Expansion Card**.

The DRAM video supports a maximum resolution of 832x624@8 bits (256 colors), or 640x480@16 bits (Thousands of colors). There is no way to get more colors or higher resolutions without adding a video card.

In a DRAM-based video scheme, ~640K of system memory is dedicated to the frame buffer. Simply put, DRAM-based video sucks. In addition to eating up RAM and being extremely slow, DRAM-based video also suffers from an inability to be upgraded. There is no way in to increase the amount of DRAM that is allocated to video. The only way to upgrade is to add a card.

Here's a question that's been asked many times on Usenet: what happens to the 640K of DRAM when the HDI-45 port is not being used? According to Apple's Technical Info library, this memory is freed up if no monitor is detected at the HDI-45 port. This is borne out by my experience. After booting with extensions off, I selected **About This Macintosh** from the **Apple Menu** and looked at the **System Software** size:

Resolution/Bit depth | System Software Size with DRAM Video | System Software Size with HPV Card | Difference
-------------------- | ------------------------------------ | -----------------------------------------------
832 x 624 @ 8 bits | 3,290K | 2,658K | 632K
640 x 480 @ 16 bits | 3,291K | 2,690K | 599K 

As you can see, the DRAM video takes up about 600-640K. It's supposed to be 640K, but the System Software size seems to fluctuate a bit depending on when you measure it, what color you're wearing, and what's the phase of the moon. So these numbers are probably consistent with 640K. [sidebar--clearly these numbers were taken a few years ago when a system took up only a few megabytes!]

### The HDI-45 Port

I'm theorizing here, since I haven't actually heard this from Apple, but the HDI-45 port appears to be the legacy of a strange experiment that never really took off--the Apple AudioVision 14 Display.

![HDI-45](/mac/powermac6100/img/HDI45.gif)

In its never-ending quest to provide user-friendliness regardless of whether or not consumers will pay the added premium for it, Apple created the AudioVision Display, a video monitor that incorporated capabilities for video out, video **in**, audio out, audio in, and the Apple Desktop Bus (ADB). Since they thought a lot of cables would be unwieldly, they also created the Integrated Desktop Cable (IDC), that carried all these signals together in a high-density, shielded cable with a 45 pin connector (the HDI-45). To ensure the success of the AudioVision display, they made the HDI-45 port a standard connector on what was then the brand new Power Mac series. A user could plug the monitor in once, and then never have to venture into the nether regions at the back of his Macintosh ever again. The AudioVision display had built-in speakers, an audio input port, a video-in port, and two ADB ports, so the user could configure and reconfigure his system from in front of the machine.

Of course, you can use the AudioVision display with non-Power Macs, too, but you'll need to buy an adapter. This part is a sort of fan-out cable that takes the IDC and splits it into its four component parts (I don't believe the video in specification was ever completed.)

There's also the adapter that goes the other way. If you own a 6100, the odds are good that you're using it right now. All non-AV models of the 6100 series shipped with this cable. You can buy it separately, but it's a bit expensive for just an adapter (Apple part #M2681LL/A, about $45 retail if you can find it). It doesn't carry the audio or ADB signals, but it does allow one to attach a standard Macintosh monitor with a DB-15 cable to the HDI-45 port.

![HDI45-DB15](/mac/powermac6100/img/HDI45-DB15.gif)

You may also be able to "roll-your-own" adapter. See Tech Info Library article #14703 for the pinouts of the HDI-45 connector. If you're savvy with a solding iron, you can probably attach a standard DB-15 connector to the motherboard in place of the HDI-45.

As you can probably tell by its conspicuous absence from store shelves and catalogs, the AudioVision Display was not a rousing success. None of the Power Macs following the original series included the HDI-45 port. But we who own 6100s are stuck with the HDI-45 connector.


