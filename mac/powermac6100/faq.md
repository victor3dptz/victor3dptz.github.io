---
layout: page
title: PowerMac 6100 Upgrade FAQ
---

![Logo](/mac/powermac6100/img/15faq.gif)

### Is there any way to use USB devices with a 6100?

No. Although there are USB-serial adapters that permit the connection of a serial device to a USB port, there is no such adapter for the reverse application of a USB device to a serial port. It's not a matter of data rates; it's more a matter of intelligence. It is a practical impossibility to make a dumb protocol emulate a smarter protocol. No amount of hardware or software hacking will ever make this possible--it's like trying to program a calculator to run Quake III. Even if technically possible (and that's not likely) no one would ever be able to justify the investment to build such a device.

There are no USB cards that can installed in a 6100, either. The 6100 is based on the (obsolete) Nubus architecture, which means no manufacturer is likely to ever invest in developing such a card. I've even been told that USB relies somewhat on PCI to work properly, so it might not even be technically feasible.

It's an unfortunate reality that the 6100 will never have USB capability.

### Will the G3 upgrade cards from Newer and Sonnet work with the HPV and AV cards?

Sometimes. The Newer cards will work with both the HPV and AV cards, although they are only officially supported with the latter. The Sonnet cards depend on when they were made. Some models of Sonnet cards will work with the AV card and some won't, depending on the date of manufacture. Some will also work with the HPV card, although Sonnet almost discourages this.

### Is my Macintosh part of the 61xx family?

If your Power Mac has a four digit model number that begins with 61 then yes. Otherwise, no.

### Why don't you have information about other Macintosh models (such as the Performa 5xxx and 62xx models)?

Because I like to work with empirical data as much as possible. Since I don't have any other machines, I can't run tests or post test data that I can verify.

### How do I add VRAM to my computer?

You can't add VRAM directly to a 6100 unless you add an HPV card. Once you have an HPV card you can upgrade to either 2MB or 4MB depending on the card.

### How do I get 1024x768 on my Apple Multiple Scan 15 monitor?

It's possible to do with an adapter.

### Why can't I get this resolution that I know my monitor/video card will support?

In order for a your computer to drive your monitor at a given resolution and bit depth, four things need to happen:

* You need a big enough frame buffer. See below
* The resolution and refresh rate need to be supported by the monitor
* The resolution and refresh rate need to be supported and the video card.
* The Mac must know that all these things are so:
  * The Mac should be able to tell how big its frame buffer is all by itself.
  * For on-board video or Apple video cards, the card should tell the Mac what resolutions it supports. Other cards may need the correct software driver to tell the Mac what it needs to know.
  * The monitor tells the Mac what resolutions it supports at boot time via sense codes set on the connector pins. If you're not using a monitor that was made specifically for a Mac, you probably will need an adapter to set the sense codes correctly.

### How many colors/What resolution can I get with xx MB of VRAM?

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

The numbers shown reflect the maximum bit depth achievable at the desired resolution. On most computers, lower bit depths are also possible, but not always. For example PCI PowerMacs and the HPV card on Nubus PowerMacs do not allow bit depths lower than 8 bits/pixel. This can cause some problems with older games and other programs that require the monitor to be set to exactly 16 colors.

Some combinations are mathematically possible, but not achievable with currently shipping hardware. For example, the 128 K size frame buffer is available only certain PowerBooks. These PowerBooks do not all support external monitors, so the only possible resolution is that of the built-in LCD screen, 640x400. Similarly, the 640x400 resolution only applies to the LCD screen of certain PowerBooks, and the size of the frame buffer on these machines is fixed.

Much of the information in this table was taken from the Apple Spec Database, a freely available database from Apple that describes the specifications of every Apple Macintosh ever shipped by Apple. Note that I can't supply the specific URL for this file because it changes every time they update it. Look for a file named Apple_Spec_2-98.img.bin or something similar. This is a FileMaker Pro database, but if you don't own FileMaker Pro, you can also download a free run-time version that will work only with the Apple Spec Database.

### How can I make my Mac faster?

That's too general a question to answer specifically. Man of the upgrades on this site will make your 6100 faster, especially a CPU upgrade, more RAM, a cache card, or a graphics card.

### Which Nubus cards work in a 61xx?

I don't have a comprehensive list yet. Cards that I've been told will work are the Radius PrecisionColor 24X and XK, or the RasterOps Paintboard Turbo XL. Other 7 Nubus cards should work as well. I've been told that 12 cards will fit at well, but you have to do some shoehorning. Specifically, you need to move your hard drive into the center drive bay. If you already have a CR-ROM drive in the center bay you have to remove it.

### Will the new G3 upgrade card from Newer technology work with a Nubus or DOS card?

No. The G3 card displaces the PDS-Nubus adapter, but does not duplicate its functionality. If you want the increased color depth or use two monitors with the G3 card, you'll have to get an AV or HPV card instead. The DOS card has a simlar story--the G3 card displaces its adapter. Then again, the DOS cards for the 6100 were pokey anyways. A G3 card and VirtualPC is probably a better solution.

### How exactly does the G3 upgrade fit in with the HPV or AV card?

![1](/mac/powermac6100/img/NubusCard.gif)

This is a picture of a Nubus card. The HPV and AV cards have similar (but not identical) form factors, so I can use this series to images to illustrate. Both the HPV and the AV card were actually designed for the 7100 and 8100 form factor. As such, they are supposed to plug in vertically, so that the card sits perpendicular to the floor. 

![2](/mac/powermac6100/img/NubusAdapter.gif)

To accommodate the 6100's flatter form factor, Apple designed an "adapter" which allows the card to sit sideways, or parallel to the floor. The adapter consists of two parts--1) a stamped metal piece which is strictly a mechanical thing; there are no electronics per se on this. 2) a little printed circuit board.

This little board is smaller than the AV or HPV card, and it has two connectors. The AV, HPV or Nubus card plugs into the adapter perpendiculary, and the adapter plugs into the PDS slot on the motherboard.

Note that this picture is of a Nubus-PDS adapter, which is slightly different than the PDS-PDS adapter. This one has a different connector, and it has some circuitry on it. This is important, as it is why Nubus cards cannot be used with the G3 upgrade card. The PDS-PDS adapter has no electronics on it; it's just a pass-through connector which can be replaced by a G3 card. 

![3](/mac/powermac6100/img/CardInAdapter.gif)

This is a picture of the Nubus-PDS adapter with the card installed, but it's quite similar to the PDS-PDS adapter. The geniuses over at Newer designed their G3 upgrade card to have the same form factor as the little printed-circuit board on the adapter! 

![4](/mac/powermac6100/img/AdapterInCPU.gif)

So to use the AV or HPV card, simply replace the little printed circuit board on the adapter with the G3 card, plug the AV or HPV card into the G3 card, then plug the whole shebang into the PDS slot.

### Will the Micro Conversions Inc. 1724PD PDS Graphics Card (MacWarehouse #DRI1650) work with the 6100?

Nope. There are different types of PDS slots. The Micro Conversions flavor works with the Performa 6200 and 6300 series, but not the 6100 series.

### Will the 8100-version of the HPV card work in a 6100 with 4 MB of VRAM?

Yup. I have confirmation from a reader who has it installed in his machine.

### Does adding VRAM to an HPV card increase the speed?

Nope. Adding VRAM allows increased resolutions and/or increased color depth, but does not increase the speed of the card or of your computer.

### The hard drive's ribbon cable gets in the way of the HPV card. What do I do?

I certainly won't say this is the "right" thing to do, but I kinda folded it over diagonally so it makes a 90-degree bend, then squashed the HPV card on top of it. It's a tight fit, but it's been working like this for 2 years now.

### Is there any way to increase the amount of memory allocated to video with the stock (i.e. motherboard) video?

Nope. That was the question that inspired the whole effort behind this website. From everything I researched (and there was a lot of that,) it cannot be done. The only options are to install a video card.

