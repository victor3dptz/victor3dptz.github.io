---
layout: page
title: PowerMac 6100 Graphics Performance
---

![Logo](/mac/powermac6100/img/07graphics.gif) This page describes the methodology used to test the graphics performance of my Power Mac 6100 under several different hardware configurations, plus the results from MacBench and Marathon 2. It's been more than three years since I first wrote this page, and I need to update it with some current information. But here it is the way it's always been.

### Methodology

Performance in a computer is very subjective. Regardless of what the benchmark numbers tell you in terms of MHz, SPECInt, SPECfp, MIPS or what-have-you, what really matters is how fast the machine performs doing what you ask it to do. With that caveat, I evaluated my video performance two ways.

First, I ran Ziff-Davis' standard MacBench utility, version 3.0. I ran the standard Graphics Mix test with varying configurations at 8 bits and 16 bits of color depth. The base system is profiled in the legalese that follows, and is almost identical to the 6100/60 that Ziff-Davis uses as the 100% benchmark system at 8 bits. My measurements are slightly faster, which I believe results from having Virtual Memory turned off, and having a larger disk cache (256K vs. 96K).

Options added in subsequent tests were a 256K Level 2 cache from PowerLogic, the HPV card from Apple, and a 78 MHz Rocket Socket clock accelerator from Output Enablers.

Using the same configurations, I played the most excellent game, Marathon 2, and recorded the frame rates I observed.

### MacBench

**Note: The numbers 8 and 16 refer to the bit depth setting of the monitor, not the amount of RAM in the machine.** All tests were performed with 16 MB of physical RAM, extensions off, and Virtual Memory turned off.

![benchmarks](/mac/powermac6100/img/benchmarks.gif)

### Legalese

* All tests were performed using Ziff-Davis' MacBench® 3.0.
* The above graph shows Ziff-Davis' MacBench® 3.0 Graphics Mix score.
* Hardware used is Apple Power Macintosh® 6100/60 with 60-MHz PowerPC 601 CPU, 16 MB of RAM, 256K level 2 cache (when specified), 500 MB hard disk, SCSI controller, and no hardware disk cache. Clock speed is 78 MHz using Output Enablers' Rocket Socket (when specified). Virtual Memory is off.
* Base graphics system is the standard on-board video. The video card (when specified) is the Apple High Performance Video card with 1 MB VRAM. All video was output to an Apple 15 Multiple Scan Monitor.
* System Software is System 7.5.3, software disk cache is 256K, graphics resolution is 640 by 480 pixels at 8 or 16 bits color depth (as specified), and all extensions are off.
* All products used in the test were shipping versions available to the general public.
* The test was performed without independent verification by Ziff-Davis and Ziff-Davis makes no representations or warranties as to the result of the test.
* MacBench is a registered trademark of Ziff-Davis Publishing Company. 

### Marathon 2

Of course, as I said above, what really matters is how fast Marathon 2 runs. I played Marathon 2 (the excellent shareware demo version from Bungie Software) with each configuration, and noted the minimum and maximum frame rates observed. I booted my machine with all extensions off, then launched Marathon 2 with the Finder in the background. I played with the window at full size (but with the console visible), four channels of sound, and all sound features enabled.

![M2](/mac/powermac6100/img/M2hires.jpg)

While I also play DOOM, Hexen, and Descent on my machine, Marathon 2 is the only game I've got that will calculate frame rates for me. To get frame rates in Marathon 2, press **shift-?** while you're playing. The frame rate will be displayed in the lower left-hand corner. Here are the results:

Configuration | fps Low-Res 256 Colors Min/Max | fps Hi-Res Thousands Min/Max
------------- | ------------------------------ | ----------------------------
Base System | 15.38/32.43 | 4.17/ 8.45
cache | 16.22/33.33 | 4.84/11.65
HPV card | 16.35/32.43 | 6.59/14.59
cache and HPV card | 20.69/33.33 | 7.69/15.79
cache, HPV and clock chip | 25.69/33.33 | 8.48/19.67

 Note that these are the extremes of the frame rates achieved. Maximum rates were achieved when there were relatively few textures and no live bad guys in view. The minimum frame rates were observed during firefights with lots of things happening at once, and the frame rates didn't stay down that low for very long.

The average sustained frame rate was usually about halfway between the slowest and fastest, or maybe slightly faster. So in Low-Res, 256 color mode, I usually got around 25 fps or better.

Unfortunately, what the numbers can't convey is the qualitative feel of how the game plays with the various configurations. It's my personal preference, but I always play with the largest viewable area I can. I consider a sustained 25 fps to be pretty darn good, and a sustained 20 fps is acceptable. Below that, the motion is jerky enough to be distracting, and important things (like getting shot) can happen in the interstices between frames. Anywhere south of 15 fps is ridiculous, and looks like a time-lapse movie.

Unfortunately (again), what the data shows and what my anecdotal experience bears out, is that Marathon 2 doesn't run very well on my machine at its maximum settings. Sigh. All those fantastic graphics, and I'm missing out. Then again, from the test results, I'm guessing that it would take a fairly fast 604 to run well at the highest resolution.

On the plus side, the data also show that Marathon 2 runs great on my machine at a lower graphics setting. Even at Low-Res, 256 colors, Marathon 2 blows away Doom for visual impact. The graphic resolution is far less important than the frame rate and and the action. Furthermore, a stock 6100/60 can achieve an impressive 30+ fps when you're cruising around. In Marathon, this happens quite a bit as it's more puzzle-solving and exploring oriented than the shoot-em-up Doom. Kudos to Bungie for writing an engine that cranks so well on an entry level machine!


