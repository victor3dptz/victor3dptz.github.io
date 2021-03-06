---
layout: page
title: Apple AV Card
---

![Logo](/mac/powermac6100/img/VideoStartup.gif) This page describes the Apple AV card, an expansion card that provides additional graphics performance plus video input and output.

### Description

The Apple AV card (Apple part #661-1023) is a PDS upgrade card that was supplied with the 6100 AV, 7100 AV and 8100 AV. It was also available as a service part from Apple, and can be obtained used on the Internet and occasionally from retailers of used and service parts. It will work fine with any machine from the 6100 series, but since there's only one slot, it will displace any other card you may have installed there (DOS, HPV or Nubus).

The "AV" moniker is somewhat of a misnomer, since there is no audio capability on the card. All audio input and output are handled on the motherboard via the standard stereo minijacks.

### Installation

Installation of the card itself is identical to the installation of the HPV card. It requires the same 90-degree PDS-PDS adapter and can be installed in a 6100 in conjunction with a G3 upgrade card from Sonnet Technology or Newer Technology.

In addition to the PDS adapter, you most probably will need the special cables for the video input and output. The card has only S-video ports, and most consumer-grade TVs and VCRs use RCA cables for input and output. If you are shopping for a used AV card, make sure your seller includes these cables, because they are expensive to buy and difficult to make. If you do need to buy them, they are Apple part #922-0816 (input) and #922-0817 (output). Although the cables look very similar to each other, the pin assignments are different, and they are not interchangeable. In fact, inadvertantly mixing the cables happens frequently enough to warrant its own Apple TIL article. On the software side, everything you need for basic functionality is included with all recent versions of the Mac OS. There are two system extensions and an application:

![1](/mac/powermac6100/img/VideoStartup.gif) | Apple Video Startup extension
![2](/mac/powermac6100/img/PowerPCMonitors.gif) | PowerPC Monitors extension
![3](/mac/powermac6100/img/AppleVideoPlayer.gif) | Apple Video Player application

The Monitors control panel (or the Monitors and Sound control panel in 8.5 and later) and the relevant control strip modules will also sense the presence of the AV card and make the additionally enabled options available to you.

Attach any video input sources and video output monitors to the S-video ports, using the RCA adapter cables if necessary. Your monitor attaches to the Mac-standard DB-15 monitor port.

Note that your built-in video port still works just fine. If you have another monitor, you can attach it and run dual monitors, which is tres cool. Alternatively, you can use the built-in video to drive your monitor and dedicate the AV card to driving a TV or VCR.

### Video Input and Output

If the Apple Video Startup and PowerPC Monitors Extension extensions are loaded at startup, video input and output will be enabled. (Without these extensions, the card will function just fine as a standard graphics card).

#### Input

To input video to your Power Mac, simply connect a video source to the S-video In port on the AV card. This can be a VCR, camcorder, DVD player, etc. The AV card will then show up as valid input in any application that handle video input.

The Apple Video Player is the free Apple application that will perform rudimentary video capture. Third party applications can also be used, and there are many available.

Video conferencing applications can also use the video input from the AV card. There are several, such as iVisit, CU-SeeMe, and ClearPhone. An older version of CU-SeeMe (aka "The Cornell version") is still available for free,, too, although it is quite out of date.

#### Output

To send video output through the S-video port to a TV or a VCR, you can use the Monitors or Monitors and Sound control panel. If you've installed your extensions correctly, you should see the following options in the control panel:

##### Monitors and Sound Control Panel (Mac OS 8.5 and later)

![Video](/mac/powermac6100/img/MonitorsAndSound.gif)

##### Monitors Control Panel (System 8.1 and earlier)

![Video](/mac/powermac6100/img/monadj.gif)

If you click the Added Options (Mac 8.5 or later) or Options (pre-8.5) button, you should get something like this:

![opts](/mac/powermac6100/img/monitoroptions.gif)

If you have the PowerPC monitors extension installed and a VCR or TV attached, the "Display Video On Television" option will become available. For details on how to work with a TV or VCR attached, read Apple's Tech Info Library article on the subject.

### Performance

For starters, the AV card **is** slow for graphics. With the AV card installed, the Mac uses a 32 bit path to video. With either DRAM-based video or the HPV card, the Mac uses a 64 bit path. This is all confirmed by Apple itself, in a Tech Info Library note. But the AV card does give you video input and increased resolutions, so some people opt for it.
 
In terms of day-to-day usage, my AV card definitely scrolls slower than the on-board video or the HPV card. The difference is noticeable, but not severe enough to make me want to switch back and forth (because I have 2 HPV cards and an AV card, and only one slot, I have toyed with the idea of swapping the cards in and out at various times).

In terms of video capture, the 6100 with an AV card is capable of doing decent amateur work that's suitable for Web pages and such. The main bottleneck for video capture won't be the AV card, it'll be the system bus and your hard drive. With my system, I can capture uncompressed, quarter screen (320 x 240), full color (24-bit) video at around 20 fps. Since the card doesn't have any compression or decompression hardware on board, I try to capture the video uncompressed, and then compress it later. I have not had good experience doing compression-on-the-fly, even with my 210 MHz G3 card installed.

Furthermore, I get the best frame rates if I capture to RAM. I use a formerly-shareware application called MyVidCap which allows me to bypass the hard drive entirely. With 136MB of RAM, I can capture about 30-45 seconds of quarter-screen video before the system has to start writing to disk and I start dropping frames.

At lower sizes, like 160 x 120, I could probably capture 30 fps and compress it on the fly, which would make my hard drive space the only limiting factor to how much video I could capture.

