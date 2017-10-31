---
layout: page
title: PowerMac 6100 CPU Upgrades
---

![Logo](/mac/powermac6100/img/04cpu.gif) This page describes the options for upgrading the CPU on the Power Mac 6100 series.

### Introduction

Of course you've all heard by now--Newer Technology and Sonnet Technologies are shipping CPU upgrade cards for the 61xx series based on the wildly successful G3 and G4 (aka PowerPC 750 and 7400) microprocessors. Street prices range from $172-$430 depending on the speed of the card, and the resulting performance can best that of the original Power Macintosh G3's shipped by Apple in late 1997.

The latest news is from Sonnet Technologies. CPUs run at much higher clock speeds than does the rest of the system via clock multipliers. For example, my 6100 has a 30 MHz system clock, and a G3 chip that runs at 7x, or 210 MHz. The G3 chip architecture is limited to a 10x multiplier, so even a chip rated for 500MHz could only run at 300 MHz in a 6100. Until now.

Sonnet has found a way to create a separate, doubled bus on the card itself. If you then apply the chip multiplier to the doubled bus, you can get higher clock speeds. So for 6100 running with a 30 MHz system bus, a Fortissimo card would have a 60 MHz bus on the card, which (theoretically) could drive a G3 chip up to 600MHz. Of course the G3 chips aren't running that fast yet, so right now we're limited to 400 and 500 MHz G3 cards on the 6100.

Sonnet is publishing fantastic performance benchmarks for this card. While these benchmarks are probably accurate as written, they're just benchmarks. I have email from one reader who has a Fortissimo 500 MHz card in his 7100. He's very happy with it, and can't imagine using his 7100 without it now.

It seems like every time the 6100 looks like a dead end, someone comes up with another way to keep 'em viable for another couple of years!

### Options

Here is summary of the CPU upgrade cards that are currently available for the 6100:

Mfr. | Model | CPU/Speed | L2 cache/Speed | Approx.Street Price | MacBench CPU score | Compatibility with other cards
     |       |           |                |                     |                    | ------------------------------
     |       |           |                |                     |                    | AV | HPV | DOS or Nubus
---- | ----- | --------- | -------------- | ------------------- | ------------------ | -- | --- | -------------------
Sonnet | C61-G3-512-250	| G3 240-266 MHz | 512K @ 120-133 MHz | $172 | 750 | Yes | Unsupported| No
Sonnet	C61-G3-1M-266	G3 240-266 MHz	1 MB @ 120-133 MHz	$215	930	Yes	Unsupported**	No
Sonnet	C61-G3-1M-300	G3 293-300 MHz	1 MB @ 147-150 MHz	$258	1,045	Yes	Unsupported**	No
Sonnet	C61-G3-400-1M	G3 300 MHz	1 MB @ 150 MHz	$344	1,400	Yes	Unsupported**	No
Sonnet	C61-G4-360-1M	G4 270-300 MHz	1 MB @ 135-150 MHz	$430	1,300	Yes	Unsupported**	No
Sonnet	TBD	G3 390-403 MHz	1 MB @ 185-202 MHz	$399	1,400	Yes	Unsupported**	No
Sonnet	TBD	G3 480-500 MHz	1 MB @ 240-250 MHz	$499	1,610	Yes	Unsupported**	No
Newer	7MXP6100	G3 210 MHz	512K @ 105 MHz	disc.	654	Yes	Yes***	No
Newer	7MXP+6100	G3 240 MHz	1 MB @ 300 MHz	disc.	864	Yes	Yes***	No
Newer	7MXPA6100	G3 266 MHz	512K @ 133 MHz	??	810	Yes	Yes***	No
Newer	7MXPD6100	G3 300-330 MHz	1MB @ 150-165 MHz	$160	880	Yes	Yes***	No 
