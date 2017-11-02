---
layout: page
title: PowerMac 6100 Graphics Upgrades
---

![Logo](/mac/powermac6100/img/07graphics.gif) This section describes various aspects of the video subsystem of the Apple PowerMac 6100 and related machines, including upgrade options and some test results. 

The default video configuration of the 6100 series is very limited, but fortunately there are upgrade options. They are very poorly documented by Apple, but they exist. You can increase the graphics performance, get more resolutions, more colors or add video input and output by adding a video card. The following table describes the options you'll have with each of those options. The column entitled "None (640K)" describes what's provided by the built-in video which is always available, whether or not you've added an additional card:

Optional card/frame buffer size | None (640K) | PDS 7100 HPV (1MB) | PDS 7100 HPV (2MB) | PDS 8100 HPV (2MB) | PDS 8100 HPV (4MB) | PDS AV Card (2MB) | Nubus (Various)
------------------------------- | ----------- | ------------------ | ------------------ | ------------------ | ------------------ | ----------------- | --------------- 
Maximum resolution | 832x624 8 bits | 1152x870 8 bits | 1152x870 16 bits | 1152x870 16 bits | 1152x870 24/32 bits | 1152x870 16 bits | Varies
Data path | 64 bits | 64 bits | 64 bits | 64 bits | 64 bits | 32 bits | ????
Hardware acceleration | No | No | No | No | No | No | Possibly
Dual monitors | No | Yes | Yes | Yes | Yes | Yes | Yes
Video I/O | No | No | No | No | No | Yes | Possibly
Compatible w/most recent Mac OS | Yes | Yes | Yes | Yes | Yes | Yes | Unknown
Compatible w/MkLinux | Yes | Yes | Yes | Yes | Yes | Yes | No
Compatible w/Newer G3 card | Yes | Yes | Yes | Yes | Yes | Yes | No
Compatible w/Sonnet G3/G4 card | Yes | Maybe | Maybe | Maybe | Maybe | Yes | No
Compatible w/DOS card | Yes | No | No | No | No | No | No 

Each of these options has different features and tradeoffs, so this section of the site is quite a bit longer than the other sections. Thus, it's broken out into sub-pages:

* [Hardware](/mac/powermac6100/graphics/hardware.html)
* [The HPV card](/mac/powermac6100/graphics/hpv.html)
* [The Apple AV Card](/mac/powermac6100/graphics/av.html)
* [Nubus video cards](/mac/powermac6100/graphics/nubus.html)
* [Installing an upgrade card](/mac/powermac6100/graphics/install.html)
* [Test Results](/mac/powermac6100/graphics/test.html)
* [Other benefits of Expansion Cards](/mac/powermac6100/graphics/benefits.html)
* [My conclusions](/mac/powermac6100/graphics/conclusions.html) 

### Sidebar: All PDS cards are not the same

There are two different types of Processor Direct Slots (PDS), despite the unfortunate fact that Apple has used the same name repeatedly. The only two PDS video cards that will work in a 6100 are the Apple AV and the Apple HPV card. Other "PDS video cards" such as the Micro Conversions Inc. 1724PD PDS Graphics Card were made for the other Macs (Performa 6200 and 6300, plus the LCIII/630 series of non-Power Macs) only. These video cards will not work in a 6100.
