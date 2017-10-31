---
layout: page
title: PowerMac 6100 RAM Upgrades
---

![Logo](/mac/powermac6100/img/03memory.gif) This page describes the options for upgrading the RAM on the Power Mac 6100 series. 

### Introduction

The PowerMac 6100 shipped with a paltry 8 MB of RAM. This woefully inadequate for a modern computer system, especially a RISC-based system. Increasing your RAM will improve performance by reducing the system's reliance on virtual memory, and increase stability by reducing the incidence of low-memory situations.

There are 8 MB of RAM soldered onto the motherboard, and there are two SIMM slots that must be filled with matched pairs. There are 7 possible configurations of RAM for the 6100:

SIMMs | +Motherboard RAM | =Total RAM | Street price for two SIMMs
----- | ---------------- | ---------- | --------------------------
None | 8 MB | 8 MB | N/A
Two 4 MB | 8 MB | 16 MB | $24
Two 8 MB | 8 MB | 24 MB | $36
Two 16 MB | 8 MB | 40 MB | $68
Two 32 MB | 8 MB | 72 MB | $120
Two 64 MB | 8 MB | 136 MB | $110
Two 128 MB | 8 MB | 264 MB | $684
Two 256 MB | 8 MB | 520 MB | $???

The official Apple specification calls for 72 pin, non-composite, Fast Page Mode (FPM) RAM SIMMs, 80 nanoseconds or faster. You can use faster SIMMs (i.e. 60 or 70 ns), but they will not provide any speed increase.

According to Apple's Technical Info Library, EDO RAM can also be used in the 6100 series. It will not operate in EDO mode, so there will be no speed increase, but EDO RAM often is cheaper than FPM RAM, especially as FPM RAM slides into obsolescence. I am personally running two 64 MB EDO SIMMs from Thompson's Computer Warehouse right now.

I've had mixed results from readers on the 64 MB SIMMs from Thompson's. Two or three readers have reported random bus errors or other such instability with these, but many others have written to tell that their machines are running fine. I've also had scattered reports of incompatibility between RAM fromMemoryX and the Sonnet G3 card. MemoryX appears to have confirmed this, too. As always, standard troubleshooting would involve 1) removing and re-seating the SIMMs to ensure good contact or 2) swapping out the SIMMs to see if it's just a bad pair. I'll keep updating this as I get further reports.

SIMMs must be installed two at a time, in matched pairs. Therefore, if you want to go from 16 MB total RAM to 24 MB total RAM, you would have to buy two new 8 MB SIMMs and remove the 4 MB SIMMs already installed. Ideally, SIMM pairs should be the same speed, and from the same manufacturer. The prices above reflect the lowest advertised price that I was able to find in February, 2000 for a pair of SIMMs. Unused SIMMs can be re-sold in for-sale newsgroups and auction sites for a small fraction of their new value.

### How to install a RAM SIMMs

Installing RAM SIMMs is probably the easiest internal modification you can make to your Mac. 

#### Step 1: Open the computer

Turn off the computer, but leave it plugged in. If the power cord is attached to a power strip or surge protector, leave that turned on, and turn off the computer using its own power button. This is important to allow you to dissipate any static electricity and prevent you from frying any sensitive components.

Pull up on the small tabs at the back of the computer. Each of them should snap free, and the entire top of the case should rock forward. Rock it forward until it comes free of the computer, and set it aside.

Remove any residual static electricity your body may be carrying by touching the power supply (the big metal box at the back of the computer). Better yet, buy and wear an anti-static wrist strap. Also, remove any wool sweaters you may be wearing and banish the cat from the room until you're finished.

#### Step 2: Install the RAM

There are two identical RAM slots on the right side of the motherboard.

Remove any existing RAM SIMMs by bending the little metal clips outward, and rocking the top edge of the SIMM away from the socket. Once it has rotated about 45 degrees you should be able to lift it away. Remove the outermost one first, then the innermost one.

Install the new SIMMs in the reverse order. The SIMMs are keyed, and will only fit one way. Check the cutout at the corner of the SIMM and the corner of the slot to see how it fits. Install each SIMM by inserting it at about a 45 degree angle into the socket. Rotate it to vertical. It should click into place as the little metal tabs lock around the edges.

#### Step 3: Close up the computer and verify the installation

Tilt the cover towards you about 45 degrees, and align it with the front of the case. Slide it onto the case until the front parts appear to be engaged, then rotate the back down and press down on the tabs until they click. If they don't click, you may have it slightly misaligned. Remove it and start over.

Turn on the computer and check "About This Computer" from the Apple menu. The amount of RAM should match the amount you have installed plus the 8 MB of motherboard RAM.

### What about Virtual Ram (VM)?

There is a difference between physical (i.e. "real") and logical RAM. Physical RAM is the amount of RAM you have installed in your computer, either on the motherboard or with RAM SIMMs.

You can also use space on your hard drive as "virtual" memory by telling your computer to treat it as logical RAM. For example, if you have 40 MB of real RAM, but you want to keep a bunch of programs open, you can use the Memory Control Panel to tell your computer to set aside some of your disk space and pretend that you have 80 MB of RAM. The computer then creates a "map" that is 80 MB in size. 40 MB of that will always be stored in the real RAM, and the "virtual" remainder will exist only on the disk. If programs or the operating system needs anything that's stored in the "virtual" section of map, the computer will read the needed information from the disk and swap it for other, unneeded info, which then gets "paged," or written, back to the disk.

Due to some peculiarities of the Mac OS's VM system, this "swap space" on your HD needs to be as large as the total amount of RAM that you wish to use. Therefore, in the example above, you would need to allocate 80 MB of disk space to virtual memory.

Using VM has its tradeoffs. One the one hand, VM is tremendously slower than real RAM, because a hard disk is orders of magnitude slower than tiny little silicon transistors. Furthermore, using VM can eat up a fair chunk of your hard drive space. If you have 136 MB of real RAM and want to have 137 MB of VM, you need to set aside 137 MB of hard disk space.

The slowdown from VM also makes multimedia applications stutter when the system needs to page stuff in or out. QuickTime movies will stutter, and audio or video capture applications will skip. It is best to turn off VM when using these applications.

On the plus side, using VM does give you more logical RAM to work with. Due to the way native PowerPC applications use memory, turning on VM actually reduces the amount of RAM each application uses. This is explained by an Apple Tech Info Library article.

I find that a good compromise is to buy as much RAM as I can reasonably justify, and then set my total memory to 1 MB above that. This gives me the benefits of smaller RAM footprints for my applications, but requires only minimal paging in and out of the swap space on my HD.

Another tweak that works well is to set aside a dedicated partition for the swap space. I turn VM on and off several times a week as I use different types of applications. In the past, I had had a problem with the VM space getting fragmented when VM was off. This was killing performance, as paging to and from a fragmented swap file is ghastly slow. By setting aside a dedicated disk partition, I make sure that I always have a nice, contiguous part of my HD that's free for virtual memory.

RAM Doubler is a third party application that provides some additional methods of managing memory on your Mac. It can provide increased performance over the Mac OS's built-in VM scheme, but compatibility problems can crop up from time to time.
