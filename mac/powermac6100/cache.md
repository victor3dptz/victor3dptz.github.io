---
layout: page
title: PowerMac 6100 L2 Cache
---

![Logo](/mac/powermac6100/img/01cache.gif) This page describes the options for upgrading the Level 2 (L2) cache on the Power Mac 6100 series. It also provides a very high-level description of what cache is and what cache does. 

### Introduction

PowerMacs really get a speed boost with with Level 2 cache. Or more correctly, they incur a heavy speed penalty without one. The DRAM-based video and the early system software's heavy reliance on 680x0 emulation further increase the benefit of the cache.

Sadly, though, most models of the PowerMac 6100 series shipped without a Level 2 cache. Fortunately, prices on L2 caches have plummeted in recent years, and now there is no excuse not to have at least 256 K in your system.

You can add/increase the amount of L2 cache on your PowerMac 6100 series in two different ways:

* adding/replacing a cache SIMM
* installing a PowerPC 750-based processor upgrade card

Since option 2 is linked to the processor upgrade, I'll discuss that on a separate page. Here I'll discuss cache SIMMs.

L2 cache SIMMs are available in three sizes:

Cache size | Price | Range of speed increase
---------- | ----- | -----------------------
256 K | $15 | ~30%
512 K | ?? | ~30%
1024 K (i.e. 1 MB) | $89 | 50-80%

The exact amount of performance improvement is highly dependent on the particular application, but the number that gets kicked around most frequently is a 30% improvement for a 256 K cache vs. no cache at all.

There doesn't seem to be much incremental improvement from installing a 512 K cache, but there **does** seem to be a pretty significant boost from installing a 1 MB cache. The reason is because of the DRAM-based video system. With a 1 MB cache, the entire frame buffer can be cached, resulting in greatly improved scrolling and dragging performance.

One thing to note about cache SIMMs is that they should be removed if you later decide to add a G3 upgrade card. The large, fast backside caches on G3 processor cards obviate the need for motherboard cache, and the spurious cache overhead can actually decrease performance. Therefore, manufacturers of G3 upgrade cards recommend the removal of a cache SIMM when installing the cards.

If you aren't going to spend a lot of money on this machine, at least spend $15 and install a small L2 cache.

### How to install a cache SIMM

Installing a cache SIMM is no more difficult than installing RAM, except that it requires a bit more force and can be a trifle intimidating. 

#### Step 1: Open the computer

Turn off the computer, but leave it plugged in. If the power cord is attached to a power strip or surge protector, leave that turned on, and turn off the computer using its own power button. This is important to allow you to dissipate any static electricity and prevent you from frying any sensitive components.

Pull up on the small tabs at the back of the computer. Each of them should snap free, and the entire top of the case should rock forward. Rock it forward until it comes free of the computer, and set it aside.

Remove any residual static electricity your body may be carrying by touching the power supply (the big metal box at the back of the computer). Better yet, buy and wear an anti-static wrist strap. Also, remove any wool sweaters you may be wearing and banish the cat from the room until you're finished.

#### Step 2: Install the cache card

There are two identical slots on the left side of the motherboard. One is for the ROM SIMM, and the other is for the cache SIMM. Either SIMM can sit in either slot. You can distinguish between the cache SIMM and the ROM SIMM by looking at the chips on the SIMM. The ROM SIMM will have a xxx and say Copyright 198x, Apple Computer.

Remove any existing cache SIMM, and then install the new one. The SIMM is keyed, and it will only fit one way. Check the sections of the card and the sections of the slot to see how it fits. Install the SIMM by pressing it straight down into the slot. It will require a fair amount of force. You'll probably hear some crackling noises as the motherboard flexes, and then the SIMM will make a "**grunch**" sound as it snaps in.

#### Step 3: Close up the computer and verify the installation

Replace any DOS, video or Nubus cards that you may have removed, then replace the top cover. Tilt the cover towards you about 45 degrees, and align it with the front of the case. Slide it onto the case until the front parts appear to be engaged, then rotate the back down and press down on the tabs until they click. If they don't click, you may have it slightly misaligned. Remove it and start over.

Turn on the computer and run a cache diagnostic utility such as Newer Technology's Cache 22.

### What is Level 2 cache?

What's a cache? The abridged version is that the cache (pronounced like money--cash) is a small amount of very fast memory adjacent to the CPU that stores frequently used data and instructions. When the CPU wants information that's in the cache, it can get it much faster than if it had to go all the way through the memory bus to get to system RAM.

To make a crude biological analogy, a Level 2 cache is like your short-term memory. If need to remember something that's happened recently, you don't need to think very hard to retrieve it. If it's been a while, you may need to think about it for awhile and hunt around in your long-term memory (analogous to system RAM).

The PowerPC 601 has 32K of Level 1 cache on the chip itself. Level 1 cache operates at the full speed of the CPU, including clock-multiplication. In the Power Mac 6100 series, the PowerPC 601 is clock-doubled to 60 or 66 MHz, and the Level 1 cache operates at this speed. The Level 2 cache slot can take a 256K, 512K, or 1MB cache SIMM, which operates at the 30 or 33 MHz system bus speed. By way of comparison, Intel's Pentium Pro processor has 256K of Level 1 cache on-chip, which helps account for its speed.

The PowerPC 750, or "G3" processor has 64K of Level 1 cache and on-board cache tags for 512 K to 1 MB of Level 2 cache. What's more, the PowerPC 750 uses what's called a "backside" cache bus, which is much faster than the system bus used for traditional, or "lookaside" cache. I won't go into the gory details here, but backside cache can operate half as fast, 2/3 as fast, or even at the full speed of the processor. For these reasons, the PowerPC 750 usually is shipped with a large amount of backside cache on the processor card. The new caching architecture is the primary factor that makes the PowerPC 750 such a remarkable processor.

Earlier, I had a section on why the SRAM that's used for cache is so fast and so expensive relative to the DRAM that's used for regular system memory. My explanation was half-baked at best. But a friendly reader mailed me a much more complete and elegant explanation:

*Static memory uses 4 transistors per bit. The four transistors form a logic gate which is latched in one of two states. That's why it can be read instantly, whereas dynamic memory requires elaborate timing. SRAM is used in caches because it can be accessed at any point in the processor cycle. Back in the early days of microcomputers, the highest capacity SRAM chips were always exactly 1/4 of the size of the corresponding DRAM chips. But the timing requirements were so much easier that DRAM was for a long time considered intrinsically unreliable.*
