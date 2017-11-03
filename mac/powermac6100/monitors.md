---
layout: page
title: Power Mac 6100 Monitors
---

![Logo](/mac/powermac6100/img/08monitors.gif) This page describes various aspects about monitors and the 6100. It describes what monitors work the which configurations and why. It also describes how to set up the 6100 to handle dual monitors

### Introduction

Although the 61xx Performas shipped with 15" monitors, the 6100 series can handle monitors of almost any size, from 13" all the way up to 21". In fact, it is a common misunderstanding among users that a computer can only drive monitors of a certain size. In reality, the size of the screen is almost immaterial. What matters is what resolutions are supported by the computer and the monitor. 

### Resolutions and me

This section describes how to figure out whether your computer will work with a given monitor at a given resolutions.

In order for a your computer to drive your monitor at a given resolution and bit depth, four things need to happen:

* You need a big enough frame buffer. See below
* The resolution and refresh rate need to be supported by the monitor
* The resolution and refresh rate need to be supported and the video card.
* The Mac must know that all these things are matched up:
  * The Mac should be able to tell how big its frame buffer is all by itself.
  * For on-board video or Apple video cards, the card should tell the Mac what resolutions it supports. Other cards may need the correct software driver to tell the Mac what it needs to know.
  * The monitor tells the Mac what resolutions it supports at boot time via sense codes set on the connector pins. If you're not using a monitor that was made specifically for a Mac, you probably will need an adapter to set the sense codes correctly. 

### What resolutions are supported?

Here's how to do the math: Take the total number of pixels desired (height x width) and multiply it by the required bit depth for the desired color scheme:

Bits/Pixel | # of Colors/Grays | Comment
---------- | ----------------- | -------
1 | 2 | Black and White
2 | 4 | 
4 | 16 |
8 | 256 | 
16 | 32,768 | Full color, or Thousands
24/32 | 16.7 million | True color, 24-bit, or Millions

There are a maximum of 256 shades of gray for the Mac. Any setting over 256 automatically becomes color.

256 colors requires 8 bits/pixel. Thousands of colors requires 16 bits/pixel. Millions of colors requires **32 bits/pixel**. (I emphasize this last point because Millions of colors is often referred to as 24-bit color. While millions of colors does indeed use only 24 bits for color, it also uses an additional 8 bits/pixel for the translucency mask.) Take this total number of bits, divide by 8 to get bytes, then divide by 1,048,576 to get MegaBytes. Ah heck. I won't make you do the math. Here's a table showing the bit depth/resolutions achievable with various sizes of frame buffers:

Desired Resolution | 128K | 256K | 512K | 640K | 768K | 1MB | 2MB | 4MB | 8MB
------------------ | ----- | ----- | ----- | ----- | ----- | ---- | ---- | ---- | ----
512x384 | 4 bit | 8 bit | 16 bit | 16 bit | 24/32 bit | 24/32 bit | 24/32 bit | 24/32 bit | 24/32 bit
640x400 | 4 bit | 8 bit | 16 bit | N/A | 16 bit | 24/32 bit | 24/32 bit | 24/32 bit | 24/32 bit
640x480 | 2 bit | 4 bit | 8 bit | 16 bit | 16 bit | 16 bit | 24/32 bit | 24/32 bit | 24/32 bit
640x870 | 1 bit | 2 bit | 4 bit | 8 bit | 8 bit | 8 bit | 8 bit | 8 bit | 8 bit
800x600 | 2 bit | 4 bit | 8 bit | 8 bit | 8 bit | 16 bit | 24/32 bit | 24/32 bit | 24/32 bit
832x624 | 2 bit | 4 bit | 8 bit | 8 bit | 8 bit | 16 bit | 24/32 bit | 24/32 bit | 24/32 bit
1024x768 | 1 bit | 2 bit | 4 bit | N/A | 8 bit | 8 bit | 16 bit | 24/32 bit | 24/32 bit
1152x870 | 1 bit | 2 bit | 4 bit | N/A | 4 bit | 8 bit | 16 bit | 24/32 bit | 24/32 bit
1280x1024 | N/A | 1 bit | 2 bit | N/A | 4 bit | 4 bit | 8 bit | 16 bit | 24/32 bit

* The maximum bit depth of the Portrait monitor is 8 bits.

The numbers shown reflect the maximum bit depth achievable at the desired resolution. On **most** computers, lower bit depths are also possible, but not always. For example PCI PowerMacs and the HPV card on Nubus PowerMacs do not allow bit depths **lower than** 8 bits/pixel. This can cause some problems with older games and other programs that require the monitor to be set to exactly 16 colors.

Some combinations are mathematically possible, but not achievable with currently shipping hardware. For example, the 128 K size frame buffer is available only certain PowerBooks. These PowerBooks do not all support external monitors, so the only possible resolution is that of the built-in LCD screen, 640x400. Similarly, the 640x400 resolution only applies to the LCD screen of certain PowerBooks, and the size of the frame buffer on these machines is fixed.

### Monitor adapters

There are several types of monitor adapters that may be necessary with a 6100-series machine: 

* HDI-45 to DB-15 - Allows a standard Mac monitor to attach to that funny monitor port on the motherboard
* DB-15 to VGA - Allows a standard VGA (i.e. PC-style) monitor to attach to a Mac. Often has DIP switches or a dial to set specific sense codes
* DB-15 to DB-15 - Has DIP switches or a dial to set specific sense codes for monitors that don't supply them
* S-Video to RCA - Allows standard TVs or VCRs to hook into the input and output ports on the AV card 

The HDI-45 adapter (Apple part #M2681LL/A) was supplied with all non-AV models of the 6100 series, but if you bought yours second hand or if you've lost the use of your AV card, you may not have one of these. They retail for about $45, but you can often find them for $25 or less on ebay or Usenet newsgroups.

The DIP switch or dial-type adapters allow you to tell the Mac what kind of monitor you have attached to your machine by setting "sense pins." This is necessary when using a PC-style (i.e. VGA) monitor, or when using certain older Mac-compatible monitors that don't set the sense pins properly. It is difficult to figure out what settings to use if you don't have the original documentation for your adapter.

The last type of adapter is used to connect an AV card to a TV, VCR or videocamera. Yes, you can use a television as a monitor!

### Dual Monitor setup

If you've installed a graphics expansion card in your 6100, you can then hook up two monitors simultaneously. A more detailed description of this procedure is available in the [Graphics Upgrade section](/mac/powermac6100/graphics/benefits.html).
