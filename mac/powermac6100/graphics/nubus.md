---
layout: page
title: Nubus Video Cards
---

![Logo](/mac/powermac6100/img/07graphics.gif)

The PowerMac 6100 series can be fitted with a 7-inch Nubus card, although it requires a special PDS-Nubus adapter. It's rumored that a 12-inch card can be used if the hard drive is moved either out of the case or to the center (CD-ROM) drive bay, but I've no confirmation of this.

This part of the site is getting pretty poorly organized, since I'm just appending reader emails to the end of it. Sorry, but I don't have enough experience with these cards to know how to organize it properly!

I don't own a Nubus card, so I can't run any tests. There may be some compatibility issues with Nubus cards, since they rely on third-party drivers that probably aren't getting updated any more. Furthermore, Nubus cards can't be used with a G3 card, with a DOS card, or with MkLinux.

I'll try to build a list of 7-inch Nubus cards that work with the 61xx, but I'll need your help. If you've got one, please run some tests and send the data to me. So far, my list is pretty pathetic. I've heard that the following cards work:

* Radius PrecisionColor Pro 24X
* Radius PrecisionColor Pro XK
* Radius 8XJ
* RasterOps Paintboard Prism
* RasterOps Paintboard Turbo XL
* Supermac Spectrum Power 1152
* Apple 24AC NuBus video card (ROM versions earlier than 1.1 work up to Mac OS 7.5.2 only) 

Nubus video cards generally require a software driver to make them work properly. I was lucky enough to have a reader send me some old Radius stuff. [Click to download](/mac/powermac6100/graphics/soft/drivers.sit.hqx) the whole Radius package which includes: 

![1](/mac/powermac6100/img/DynamicDesktop.gif) | ![2](/mac/powermac6100/img/RadiusWare.gif) | ![3](/mac/powermac6100/img/QuickColor.gif) | ![4](/mac/powermac6100/img/RadiusDSP.gif) | ![5](/mac/powermac6100/img/MrFlash.gif)
Dynamic Desktop v3.3 | Radius Ware v2.3.2 | Quick Color v3.3 | Radius DSP v2.2 | Mr.Flash v1.2.3

According to my helpful readers:

> Radiusware for NUBUS cards has 3 main components: PowerSaver, QuickColor, and Dynamic Desktop.

> Radius Powersaver has no connection with the card and does the same thing as Apple's Energy Saver control panel. It is not necessary for the card at all.

> Quickcolor is necessary for the acceleration on the card to work. Without it the cards are slugs. It is compatible with MacOS 8.6 and lower, I don't know about Mac OS 9.

> Dynamic Desktop allows keyboard shortcuts for resolution and bit depth changing. It has other functions, but is completely incompatible with any system software above Mac OS 7.6.1. It is not needed for the card to function and I eventually figured out how to use Control Strip for these functions, but I missed it.

Another reader writes:

> For your information, I discovered that the QuickColor control panel (the only item I used) "Will not work with this Macintosh" until I disabled the Apple Monitor AV extension in the OS 8.5 package. Incompatible, I guess. Perhaps this will be useful to the next inquirer. 

Here's the first email I got from a reader who has a PrecisionColor 24XK in his machine:

> I wanted millions of colors on a 17" monitor, something that the Apple video cards really couldn't provide, so i invested in a PDS-NuBus adapter and picked up a Radius PrecisionColor Pro 24XK. The combination works fine (along with a second monitor, too), but performance is atrocious. I don't know whether it's the PDS/Adapter combination that causes the hit, or the card is just slow, but in millions of colors, it dragged. Desktop pictures in System 8 were unusable, because opening and closing windows took so long. Civilization II, which requires frequent redraws of large chunks of the screen, was nearly unplayable. In addition, Linux didn't recognize the card, leading to all sorts of hideous pinks and oranges in Xwindows.

Another reader wrote the following response about the driver software:

> I have the exact same card in my PM6100. It works fine.. but then if you turn the acceleration software off it moves like a slug.

Most (if not all) Radius graphics cards need some Radius software for them to work properly, & I think this person must have been missing the QuickColor control panel. If you've got their email address & they still have the same Macintosh (though I doubt it after over two years) then I'll gladly post it to them. I also have the RadiusWare control panel, but either this doesn't work with OS 8.5.1, or it doesn't like PowerMacs.

Another reader writes the following:

> I've used a 7" Radius 24XP Precision Color Pro on my 6100 before. This card screams. It feels even faster than a PCI based ATI Xclaim! It's also bloody expensive on it's own (new or used - a new Xclaim for instance even costs less than a used 24XP), and the cost of a Nubus adapter drives it up such an upgrade even higher.

Another:

> I discovered that CRA Systems had bought up the remaining stock of the discontinued Radius PrecisionColor Pro 24XP, a QD-accelerated card with a top end of 832x624x16.7M, perfect for my NEC 4FGe monitor. They were selling it for $299, but I got a month-old used one via Usenet for $200. The tough part was finding a NuBus adapter--none of the mailorder places had them, and Apple could not give them a date when existing backorders would be filled. I finally found one locally, gathering dust in a Computer City store, for $100.

I haven't run any benchmarks, but my impression is that at 24 bits, the Radius is about as fast as DRAM was at 8 bits, or maybe a little faster. At 8 bits, it flies: I get very smooth Marathon 2 action in high resolution (how did you measure the frame rate?); at 16 bits, however, Marathon is unplayable in hi-res with everything enabled. F/A-18 (8 bits only) is butter-smooth, with zero lag behind my input.

And another:

> The Apple 24AC NuBus video card should work, but early ones sent to developers and also sold by Radius have the version 1.0 ROM which is not compatible with anything above System 7.5.2. ROM version 1.1 works through at least Mac OS 8.6. The 24AC is one of the few NuBus video cards that provides accelerated video on both 68K and PowerPC and such a wide range of System versions. 

So that's all I have for now. I doubt there will be much more input to this page, since Nubus is so old and antiquated a technology.
