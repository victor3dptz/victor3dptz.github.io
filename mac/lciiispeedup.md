---
layout: page
title: LCIII (P450) Speedup
---

This is a modification that can be performed on a LCIII (P450) to speed it up to 33MHz. The author of this file would like to remain anonymous. 

Keep in mind that this will void your warranty. Dealers or Apple may refuse to accept the board as an exchange in or out of warranty with this modification.

You should also keep in mind that the circuits on your LCIII (P450) have not been tested to guarantee they will work properly at 33MHz, so if it doesn't work correctly (especially when it gets really warmed-up) just put the resistor back. In my experience it always worked fine, but that is no guarantee.

* Get a copy of the latest version of the system enabler 308 - it's the one shipped in the Performa 46x series. Drop this file into the system folder on your LCIII (P450). Without this file once you make the following modification the system software will refuse to boot up because it won't recognize the hardware. The early version of the 308 enabler that shipped with the Performa 45x series won't recognize the hardware either.
* Or get the new version of System Enabler 003, 1.1 for the LCIII (P450)
* Or use system 7.5

1. Remove the chip-resistor in position R14 (0 ohm, jumper). It is located on the top of the main logic board near the RAM simm connector. (Since a few people have asked about this, you need to remove it with a soldering iron (or two) and the part is labeled 000.)
1. Install the chip-resistor you just removed in position R74. It is located on the bottom of the main logic board.

**Note:**

1. People seem distressed that a 33MHz LCIII (P450) only identifies itself as a Mac. This lack of name string is true of many new Macs. Apple does this to avoid the need to localize the string and can enable future release of alternate configurations without testing new software (the alternate configs are tested when the original machine is developed). The only potential problem I know of is that some developers set their hardware or software up so it must know what machine it is running on. Since Apple has already released 33MHz versions of the LCIII, commercial hardware/software should have been updated to recognize the new ID.
1. According to the manufacturer the Diimo 128k L2 cache card sold for the LCIII/P450 will not work in the P460 (LCIII@33MHz). A tech support person said that it can't keep up with the higher clock speed. This has not been verified.
