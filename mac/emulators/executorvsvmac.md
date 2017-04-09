---
layout: page
title: Executor versus vMac
---

These two emulators have little in common. Both emulate a Macintosh and both are developed with the DJGPP GNU C compiler. but that is were the simularities end. To compare these two is comparing apples and oranges (pun intended), however a number of people have raised questions that the following might answer.

![vmac_lin.gif](/mac/emulators/vmac_lin.gif)

Executor was developed from ground zero. The developers literally started with nothing except lots of public information about the Macintosh (like the Inside Macintosh series of technical manuals). The goal was to develop a set of libraries for UNIX to ease porting of applications originally developed for the Macintosh. To have a demo of what the libraries could do, Ardi developed an environment for the libraries so that they could show Word running on a UNIX box. Development started on a PDP-11 (!) and the first beta ran on a SUN-3.

From that on the environment was developed into Executor. Ardi never used any code from Apple and has never disassembled or even looked at Apple's code. The somewhat technical term is that they are 'clean', meaning that Apple would have no legal case against them. Also the look-and-feel of Executor (when not within an application) is different from a real Mac, i.e. there is no Finder interface but a substitute (which the founder of Ardi once called 'Looser') has been put in place.

![goals.gif](/mac/emulators/goals.gif)

Executor emulates the hardware of a Macintosh with an 68040 processor without FPU and MMU (the latter being provided by the host OS), which puts it in the Quadra class. On a 486 processor the emulation is as fast as the real thing. For more specifications see below.

Ofcourse a PC has no 68040 processor so the first main task of every person trying to write an emulator is to emulate the processor. This is no mean task. Not only does one have to 'translate' every 680x0 machine instruction to i486 code, there are also issues involved like the fact that the byte-order of 16 bit words is different between the two families of processors. (The issue here is called little-endian versus big-endian, from Jonathan Swift's Gulliver's Travels where there is a war between two armies about at which end of an egg one would have to start eating.)

Executor's 68040 CPU emulator is very fast because it uses dynamic compilation, which means that for instance within a loop the instructions within the loop are translated once and not every time one single instruction is executed.

![bm.gif](/mac/emulators/bm.gif)

Within the Macintosh systems architecture ofcourse the various hardware components play an important role and Executor succeeds in emulating it to a certain extent; Executor reads Macintosh 1.44 Mb. floppies as well as SCSI harddisks, CD-ROMs and removables. There is sound support, printing and feature versions will have full serial support.

Most important is the quality of the emulation of the software that controls the hardware. There are two components to emulate here; the Macintosh Toolbox, which in a real Mac is contained in ROM and the MacOS, which loads from harddisk. The Toolbox has thousands of calls which Executor tries to emulate. Since it can never contain an exact copy of the Toolbox, since that would violate Apple's copyright, and because Ardi cannot reverse engineer the Toolbox calls because then the result would be 'dirty' meaning that Apple could probably sue them, the Toolbox calls are 'reconstructed' by examining which call is called how and what should be returned to the caller. This is a very lengthy and tedious process.

Since Apple does not distribute the ROM code, there is no other way than getting this component legally by actually buying a system. Ardi does not use any ROM component from Apple. vMac relies on you to extract the contents from the ROM of a Macintosh Plus and to transfer it to your vMac directory. The concept here is that when you own a Macintosh Plus you are entitled to do this. This has never been brought to court so there is no jurisdiction about it.

![macos8.gif](/mac/emulators/macos8.gif)

The second important software component ofcourse is the MacOS. A usage right for this can be bought from any Apple outlet. However since only System 7.1 and later are or have been commercially available and implementation of full System 7 support for emulators poses some serious challenges, an earlier version is more suitable. Earlier versions were bundled with systems so again to use for instance System 6.0.8 one has to have a Macintosh. It was Ardi's decision to also emulate the MacOS and not rely on the user to go and buy a Macintosh or a copy of the MacOS. As of now, Executor emulates System 6.0.8 almost fully and parts of System 7 functionality are present. vMac relies on the user to have a Macintosh Plus which means the user has the inherited right to legally use a copy of System 6.0.8 which then also has to be installed within the vMac directory. Again this whole concept has not been tested in court.

Before Apple licensed the MacOS to third parties, their Sofware License Agreement mentioned (article 1) "*This License allows you to use the Software on a single Apple computer ...*" and recent versions of this agreement go beyond this (article 2): "*This License allows you to install and use the Apple Software on a single **Apple-labeled** or **Apple-licensed** computer at a time.*". Although to my knowledge the legality of this phrase has not been tried in court, to me it suggests clearly that it is not allowed to use MacOS on a PC. (An interesting case would be to run vMac under DOS emulation on a Macintosh using RealPC of VirtualPC, since then it runs on an 'Apple-labeled' machine.)

Executor combines hardware, toolbox and MacOS emulation in one product. There is no separate ROM file and at this moment the 'System Folder' on the 'System' volume cannot be replaced by Apple supplied MacOS software.

vMac however, makes a clear distinction between hardware emulation and the ROM file and MacOS. As a result in theory vMac would be able to run other operating systems like BeOS or Linux. In practice vMac needs to emulate more recent hardware to make this feasible. But the groundwork has been done.

To summarize all of this one can say that Executor is an unbelievable technical feat. It emulates the Macintosh hardware, an 68040 processor, the Macintosh Toolbox and most of System 6.0.7 and it offers a Finder substitute. Errors and omissions within its emulation are to be expected. You can check whether an application has been verified to work in Ardi's compatibility database. When an application runs, and Ardi allows testing since it has a money-back quarantee, it runs it fast, very fast. Executor has reimplemented from scratch in native 80x86 code a substantial portion of the Mac OS and toolbox routines. In theory it runs any 680x0 application. With Executor you will not run into legal problems.

vMac is less of a technical feat. The processor emulation is static and therefore slow. (A project to make it faster is underway.) It also only emulates a 68000. It requires System 6.0.8 and the ROMs of a Macintosh Plus. This implies that in essence vMac emulates the hardware and serves as the 'glue' between the hardware, the ROM file and System 6.0.8, however it does a rather good job at this. Ofcourse because it uses more (an awful lot more) Apple copyrighted software, the look-and-feel are more Macintosh like. For instance the Finder is ofcourse fully supported. vMac does not allow all applications to run since a lot of serious applications require a processor later than the 68000. A fast Pentium is required to match the speed of a Macintosh plus. Whether it is legal to use Apple's MacOS and ROMs to run vMac on a PC is debatable.

![macplus.gif](/mac/emulators/macplus.gif)

There are a number of other noteworthy differences. Ardi is a commercial company and vMac is developed as freeware by a group of very competent people. There are MSDOS, WIN32S, Linux and NeXTStep versions available of Executor; vMac comes for a couple of operating systems more, like OS/2. vMac is more portable since less code has to be adapted between ports.

![executor.gif](/mac/emulators/executor.gif)

