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

Mfr. | Model | CPU/Speed | L2 cache/Speed | Approx.Street Price | MacBench CPU score | AV | HPV | DOS or Nubus
---- | ----- | --------- | -------------- | ------------------- | ------------------ | -- | --- | ------------
Sonnet | C61-G3-512-250	| G3 240-266 MHz | 512K @ 120-133 MHz | $172 | 750 | Yes | Unsupported | No
Sonnet | C61-G3-1M-266 | G3 240-266 MHz	| 1 MB @ 120-133 MHz | $215 | 930 | Yes | Unsupported | No
Sonnet | C61-G3-1M-300 | G3 293-300 MHz | 1 MB @ 147-150 MHz | $258 | 1,045 | Yes | Unsupported | No
Sonnet | C61-G3-400-1M | G3 300 MHz | 1 MB @ 150 MHz | $344 | 1,400 | Yes | Unsupported | No
Sonnet | C61-G4-360-1M | G4 270-300 MHz | 1 MB @ 135-150 MHz | $430 | 1,300 | Yes | Unsupported | No
Sonnet | TBD | G3 390-403 MHz | 1 MB @ 185-202 MHz | $399 | 1,400 | Yes | Unsupported | No
Sonnet | TBD | G3 480-500 MHz | 1 MB @ 240-250 MHz | $499 | 1,610 | Yes | Unsupported | No
Newer | 7MXP6100 | G3 210 MHz | 512K @ 105 MHz | disc. | 654 | Yes | Yes | No
Newer | 7MXP+6100 | G3 240 MHz | 1 MB @ 300 MHz	| disc. | 864 | Yes | Yes | No
Newer | 7MXPA6100 | G3 266 MHz | 512K @ 133 MHz | ?? | 810 | Yes | Yes | No
Newer | 7MXPD6100 | G3 300-330 MHz | 1MB @ 150-165 MHz | $160 | 880 | Yes | Yes | No 

### Performance of the Newer210 card (discontinued)

MacBench CPU scores are listed in the table above, but CPU scores are only a part of overall system performance. I ran some informal benchmarks to show real world performance. 

Task | Base Time (h:mm:ss) | Newer210 | Speed Index (Base=100%)
---- | ------------------- | -------- | -----------------------
Compress a 49 MB AIFF into an MP3 | 1:27:00 | 0:15:19 | 568%
Stuff 42.1 MB folder | 0:10:36 | 0:02:22 | 448%
Scroll through 33 page document in Word98 | 0:03:53 | 0:03:05 | 126%
Compress 36 PICTs into a QTVR .mov (Sorenson codec) | 0:03:39 | 0:00:45 | 492%
Boot | 0:02:32 | 0:01:59 | 128%
Launch Excel, Word and PowerPoint 98 | 0:01:02 | 0:00:31| 200%
Re-launch Excel, Word and PowerPoint 98 | 0:00:45 | 0:00:24 | 188%
Copy 49 MB file | 0:00:36 | 0:00:24 | 150%
Copy 3.9 MB, 36 item folder | 0:00:17 | 0:00:05 | 309% 

* Base configuration before this test was a Power Mac 6100, PPC 601 @ 60 MHz, 256K L2 cache, 40 MB RAM, VM set to 41 MB, disk cache set to 1024K, Mac OS 8.1. Hard disk is a 4.3 GB Quantum Atlas II, 7200 rpm.
* Boot time includes a ?? second FWB hard disk test which appears to be unaffected by G3 upgrade.

As you can see, certain CPU-intensive and largely cache-bound tasks are dramatically improved over my base system. Compressing an MP3, for example, is now a get-a-cup-of-coffee task instead of a go-have-lunch task. Furthermore, my base system supposedly benchmarks ~30% faster than a "stock" 6100 that has no L2 cache, so if you're upgrading from a zero cache machine, the apparent speed increase will be even more stunning. These tests bear out the MacBench CPU numbers quoted on Newer and Sonnet's marketing materials.

For other tasks that also use the disk, memory and graphics subsystems, the improvements are less dramatic. For application launching and file manipulation, the improvements were significant, but not stunning. For booting and scrolling, the improvements were marginal.

Below the stopwatch threshhold, there is the subjective feel of the machine--the snappiness of response to mouse clicks, windowing, etc. Prior to making the G3 upgrade, I had upgraded from 7.6.1 to 8.1 for application compatibility and found my machine to be so sluggish that I didn't use it much. Now, I use it everyday again. Was this worth $400 (the price of the 210 card at the time)? As with anything, it's a judgment call. For me, the answer is an unequivocal yes. For $400 and very little hassle, I have rejuvenated my machine. It's not as fast as an iMac or PowerMac G3, but it's fast enough to handle the bloated behemoths that wallow out from Redmond and Mountain View, and the UI is fast enough for my tastes. I'll get a new G4 in a year or two, but for now I'm gonna keep on truckin' with my trusty ol' 6100.

### How to install a CPU upgrade card

Short and sweet. Use a disk from the manufacturer to install an extension and/or a control panel. Shut down your Mac. Open the case, remove any existing PDS card, plug in your G3 card, close up the case. Reboot and enjoy your newfound speed.

That's pretty much the whole story if you're not going to use a PDS (aka AV or HPV) card alongside your G3 card. As noted in the table above, several of the available cards are compatible with the Apple AV and HPV cards. These cards are described at length on a separate page, but they merit a brief discussion here as it relates to installation of a G3 card.

One of the most common questions I am asked about using PDS video cards with a G3 card is, "How the heck do they fit?" I have an AV card alongside a Newer210 in my machine, and before that I had an HPV card. A picture is worth the proverbial thousand, so here you go:

![Cpu 1](/mac/powermac6100/img/cpu1.gif)

This is a picture of a Nubus video card. The HPV and AV cards use a similar (but not identical) form factor, so I can use images of a Nubus card to illustrate the concepts. In most computers, expansion cards plug in vertically, so that the card sits perpendicular to the floor.

To accommodate the 6100's flatter form factor, Apple designed adapters which allow expansion cards to sit sideways, or parallel to the floor. Note that there are three types of these adapters--one for Nubus cards, one for the DOS card, and one for PDS cards (i.e. the A/V and HPV cards) 

![Cpu 2](/mac/powermac6100/img/cpu2.gif)

The adapters consist of two parts--1) a stamped metal piece and 2) a little printed circuit board (shaded in the picture). This little board has two connectors. The expansion card plugs into the little board perpendiculary, and the adapter plugs into the PDS slot on the motherboard.

Note that this picture is of a Nubus-PDS adapter, which is slightly different than the PDS-PDS adapter. The Nubus adapter one has a Nubus connector, and it has some circuitry on it. Similarly, the DOS card has DOS circuitry on it. The PDS adapter has a PDS connector, and no circuitry.

This is important, as it is why Nubus and DOS cards cannot be used with the G3 upgrade card. The little card in a PDS adapter has no electronics on it; it's just a pass-through connector which can be replaced by a G3 card. 

![Cpu 3](/mac/powermac6100/img/cpu3.gif)

This is a picture of the Nubus-PDS adapter with a Nubus card installed. An AV or HPV card would fit in a very similar way. The geniuses over at Newer and Sonnet designed their G3 upgrade cards to have the same form factor as the little printed-circuit board on the adapter!

If you want to use a PDS card with a G3 card, but you don't have the PDS adapter, it may be possible to use the mechanical bracket from Apple DOS card adapter. I have email from one reader who has done this successfully. 

![Cpu 4](/mac/powermac6100/img/cpu4.gif)

So to use an AV or HPV card, simply replace the little printed circuit board on the adapter with the G3 card, plug the AV or HPV card into the G3 card/adapter assembly, then plug the whole shebang into the PDS slot on the motherboard.

There is an open question as to whether the adapter itself is necessary. The adapter consists of two parts, of which one is entirely replaced by the G3 card. As you can see in the illustrations above, the stamped metal piece provides only mechanical support. Without it, one still could use a PDS video card with a G3 upgrade card. The only problem would be that the video/G3 card assembly would not be well secured within the enclosure, and repeated jostling of a monitor connector attached to the video card might cause failure or intermittent connections on the card.

If you already have a A/V or HPV card installed in your 6100, then you probably already have the adapter. If you don't, though, the adapter can be expensive and/or difficult to find. Several vendors are charging up to $99 for the adapter, but I purchased mine, used, for $38 via Usenet.

As noted above, I do have email from a reader who has used the mechanical part from Apple's DOS card adapter to make this work. He had to make one minor modification, which was to file off a small post with a Dremel tool.

### Sidebar: All PDS cards are not the same

There are two different types of Processor Direct Slots (PDS), despite the unfortunate fact that Apple has used the same name repeatedly. The only two PDS video cards that will work in a 6100 are the Apple AV and the Apple HPV card. Other "PDS video cards" such as the Micro Conversions Inc. 1724PD PDS Graphics Card were made for the other Macs (Performa 6200 and 6300, plus the LCIII/630 series of non-Power Macs) only. These video cards will not work in a 6100.

### Newer compatibility with other expansion cards

As show in the table above, several of the CPU upgrades can be used in conjunction with PDS video cards. On the subject of video cards, I got the straight poop in February from none other than Newer Tech's Senior VP and CTO:

The answer is as follows:

> Apple never intended for the 6100 to use the VRAM card [aka HPV card] from a 7100 or an 8100. However, if it fits, and works, in the 6100 today it will fit and work with the G3 card installed. The form factors are slightly different. The height is the same but the length is not.

> You wondered how we fit the G3 card and the AV card in the machine. Our G3 card is the same form factor as the riser card for the AV. If the riser fits then our card fits.

> You mentioned the DOS card. Bad news dude. The DOS card will not work. If you have the version of our FAQ that is dated 2-10-98 then yoiu need to get the version that is dated 2-11-98. We just discovered that the testing that we thought was done was not. We had mistakenly believed that the card had been tested. When the engineers took a good look they discovered that the riser card for the DOS card has a lot of necessary electronics on it. There is simply no room for those electronics on our G3 card therefore we can not function with the DOS card. The good news is that with the addition of the G3 card in your box you now have enough horsepower to run Virtual PC and look pretty good. On top of that the new version (2.0) is even faster.

> If you have any other questions please let me know.

Several months later I had an extra HPV card laying around, and I offered to loan it to Newer so that they could run whatever tests they wanted. Newer's response:

> I appreciate your offer. However, it is not necessary to do any further testing. The HPV cards do in fact work quite well. We find ourselves in a somewhat unusual position. We can't come out and categorically state that the HPV cards work because Apple never stated that they work. In fact Apple often told people that they didn't work. We are concerned from a liability standpoint. Whenever people ask us we tell them that they appear to work fine but we are hesitant to make an outright statement. We allude to it and we try to help people realize that it will in fact work. I suppose there might be some boxes where it won't but we haven't seen any.

So there you have it:

* The Newer G3 Upgrade card has been fully tested to work with the AV card.
* It has not been tested with the HPV (aka VRAM Expansion) card, but it is so similar in terms of form factor and interface to the AV card that it works anyways. I personally have run both the 2 MB and 4 MB HPV cards with a Newer210 card.
* It will NOT work with the DOS card.
* It won't work with Nubus cards (because it displaces the Nubus adapter) 

### Sonnet G3 cards and HPV/AV cards

I received this email from a helpful reader who received this from someone who got it from Sonnet:

> Sonnet's official statement is that we do not support the HPV card in the 6100. If one is insistent that he uses an HPV card, he can if and only if

> 1. the customer has a new version Sonnet card, currently only C61-G3-250-512 (The 233s and 266s will never be compatible. The 300s will eventually be compatible),
> 1. the customer somehow manages to acquire an AV bracket to hold it in place (These brackets only came with the 6100AV machine--so someone wanting to replace an AV card with an HPV card would presumably have a bracket, otherwise they would have to acquire an HPV card and a 6100AV bracket.),
> 1. the customer has VRAM expansion SIMMs that are short enough (3/4" tall maximum height) to fit. (There can be no guarantee that all third party memory vendors conform to form and fit requirements for the never-intended 6100.),
> 1. the customer does not mind that a) the HPV card is longer than the AV card and rests on top of the hard drive instead of beside it, b) there is virtually no routing space for the hard drive SCSI cable, and c) everything that does not fit is forcefully crammed into too little space (You can cram it in, however), and
> 1. the customer accepts that Sonnet does not warranty this configuration.

Later, another reader cited the above message in a message to Sonnet and received the following response:

> I think maybe the information you read was older... not sure about that. Both part numbers C61-G3-1M-266 and C61-G3-512-250 will accept an AV card. Of course you realize our position of non-support on HPV cards in a 6100, but theoretically, they should work. Sonnet's website does not currently mention AV or HPV compatibility in a 6100, although they do support the AV or HPV card in a 7100 or 8100. 

Finally, I emailed Sonnet myself and received the following statement:

> All our cards work with the AV cards in the 61XX machines. We do not support the HPV card since it was never designed to go into the 61XX machines. We don't recommend it's use and it's design tends to cause crashing as well as overheating since it's bigger than the AV card. It cuts the air circulation down in a machine that is already not very well ventilated. 

### Sidebar: All PDS cards are not the same

There are two different types of Processor Direct Slots (PDS), despite the unfortunate fact that Apple has used the same name repeatedly. The only two PDS video cards that will work in a 6100 are the Apple AV and the Apple HPV card. Other "PDS video cards" such as the Micro Conversions Inc. 1724PD PDS Graphics Card were made for the other Macs (Performa 6200 and 6300, plus the LCIII/630 series of non-Power Macs) only. These video cards will not work in a 6100.

### A Blurb About Clock-Accelerators

There's a whole body of knowledge out there about clock chipping, so I won't repeat any of that here. What I will share is my limited experience. Soon after I bought my computer, I purchased a Rocket Socket from Output Enablers and installed it. I had to fiddle with the clock speed a little, and eventually settled on 78 MHz. It came with a little cooling fan that I installed in the heatsink of my CPU. It seemed to work okay, and I got a definite speed bump.

Due to problems with the original System 7.5 that shipped with my computer, I was also experiencing crashes with annoying frequency. I didn't know that the crashes were being caused by System Software bugs, and so I was trying my best to find a hardware cause. I bumped my machine up to 16 MB, which helped a little. I exchanged my Level 2 cache from PowerLogic (now PowerLogix) for another one, which didn't help much. I figured I didn't need another noisy variable in the equation, so I took out the Rocket Socket. **But I left the cooling fan in**.

Months later, Upgrade 2 for System 7.5 was released by Apple. I installed it, and voila! 99% of my crashes went away. I figured that I'd consider putting the Rocket Socket back in. I also bought the HPV card around that time. As I was installing the HPV card, I noticed that **the cooling fan wasn't working**! It was sitting in the heat sink just jiggling back and forth. This scared the hell out of me. The fan had been in for less than six months, and it had failed already. Had I kept the Rocket Socket in there, I probably would have fried my CPU, costing me hundreds of dollars to fix.

So while the benchmarks show that these clock accelerators do, indeed, supply increased performance, you're also relying on a cheap little $5.00 fan to save your expensive CPU from melting down. Given my near miss, I think I'll forgo the clock accelerator and stick with solutions that keep my machine within factory specs:)

### Clock chipping... Why some fry and other fly

#### Part One. Manufacturing Specs

CPUs are produced in mass. Obviously not all CPUs in a batch will be of equal quality and not batches will be equal. Manufacturers select a speed to designate a chip at based on what the majority of the produced chips will run successfully.

Suppose say a production of chips are going to be manufactured. A trial run of the chips give the following data of first error: (approx. bell curve)

5% | err at <60Mhz | group I
10% | err at 60-70Mhz | II
20% | err at 70-80Mhz | III
30% | err at 80-90Mhz | IV
20% | err at 90-100Mhz | V
10% | err at 100-110Mhz | VI
5% | handle beyond 110Mhz | VII 

To make the highest profit on producing the chip the manufacturer will want to sell as many usable chips as possible. This means that the manufacturer can either 1) mark each chip as being rated at its certain speed and sell all the chips as different components, or 2) determine a speed that most of the chips can live up to and sell all of the chips as "identical" components. Economies of scale dictates that the second choice is usually made.

So if we assume the production chips are marked 60Mhz and the tolerance is 15% i.e. 69Mhz. Groups I, and II fail; 85% of the chips manufactured will pass this mark. Of the passing chips 20 of 85 will fail before 80mhz.

Note--These numbers are supposed and do not represent the actual values of PPC601 60Mhz chips. They only serve to illustrate a point.

#### Part Two. 110V voltage variances

The 5V (logic) and 12V (fan, drives,etc) voltages in a powersupply are proportional to the AC line voltage. AC voltage is rated at 108V but can range from about 100V to 120V depending on the types of transformers and powerstations in your neighborhood. so output logic voltage ranges from 4.6V to 5.6V, The logic voltage range is well within the error free range for most CPUs. So it is not of much concern at normal rated clock speeds. With electrical resistance heating the circuits a 10% increase in voltage results in a 50% increase in heat. So some circuits will run hotter than others simply because of voltage. So if your voltage is higher your chips will be very hot. Combining hot chips with clock chipping is two strikes toward errors.

Also the 12V output (drive motors, fans) ranges from 11.1V to 13.33. The speed of the fan is tremendously affected by the variance in voltage. This cools the system more. I am not sure of the amount of increase in speed based on the change in voltage, I suspect it is similar to the change in heat. So it would seem with higher voltage that a faster fan would cool a hotter cpu. However this is not the case because the fan is only one component of the cooling system. The heat sinks, and design of the case do not vary with the voltage.

At lower voltage the fan only performs well enough to cool a stock system, and a clock chipped system will most likely overheat unless other cooling is implemented.

#### Part Three. Age of the chips and other components

ICs do not last forever. Supposedly 5 to 8 years is the typical life of a chip. As achip gets older it produces more heat and loses its tolerances. This is one reason why chip manufacturers don't care that most of their chips, when new, will perform 50% faster than rated. They know that in 5-10 years they will most likely still work at the rated speed.

What causes chips to age--improper nutrition? Pressure from the AARP (American Asscociation of Retired Processors)? The processors awareness that you want a 500Mhz G4. Nope none of these factor in signifigantly.

One cause of aging in chips is change in temperature. When materials of different composition change temperture they expand/contract at different rates. In the same way as a severe winter can cause loose boards in a house, changes in temperature can unset electrical components from boards, and cause slight internal damage to ICs.

Lets trace the change in temperature as a computer is used. 1) the computer is off so we will say everything is at ambient 70°F 2) the computer is turned on and after a couple of minutes the chips with the most activity have warmed up substantially and stabilized to around 150°F. -- the fan & sinks are disipating heat in a planned manner. 3) the computer is shut off. the fan stops. The airflow is dead. heat from the still hot chips disipates to whatever is around it that is cooler. A really hot chip could dissipate heat to a cooler chip and damage it.

The other cause of aging is power surges. When you turn on the computer the power supply simultaniously turns on every one of the millions of resistors in your computer. This causes a surge that causes slight damage to the chips. This is the same as a surge after a blackout. The Power comes back on and there is so much load i.e. from air conditioners in the hot summer that the powerstation produces a surge.

Regardless of whether you use clock chipping or not, if you want your computer to age as slowly as possible you should not turn it on or off. This means you can either leave your computer on all the time or leave it off all the time. Most people opt to leave their computer on all the time. This is because when the computer is off the components are more subject to changes in ambient temperature and humidity. 

#### Conclusion

Clock chipping may work for some computer for sometime. Clock Chipping may not work because of the following: 

* Tolerance for speed range on cpu is too close to actual marked speed.
* The compnents are operating off too high or too low 110V that leads to overheating and errors.
* The chips are old [and] tolerances reduced. (perhaps they aged prematurely because of clock chipping) 

If you do successfully clock chip then it would make sense that you always leave your computer on. (not your monitor though) This will greatly slow the aging of your CPU and should keep the clock chipping successful. A good voltage regulated, uninterruptable powersupply, and good surge protector would not hurt to protect your computer either.

Personal view-- I view clock chipping as unnessecary and risky. I don't have the time to evaluate all the possible causes of failure in my system if it fails. (though I do have the time to write this email?). No, maybe i do have the time. BUT I don't have the money to risk my CPU/motherboard lifespan/operability to the slight speed increase clock chipping provides. If i did have the money I would just buy a signifigantly faster computer.

Or add RAM, VideoCard, external Ramdisk, etc.

### Newer goes out of business

Newer Technology has ceased operations. We'll miss them; it was a wild ride.

After winning a Best of Show award at MacWorld in March of '98, Newer was inundated with orders for the x100 series CPU upgrades. So many, in fact, that they simply couldn't keep up with demand. Many disgruntled customers and distributors later, Newer finally caught up with demand and had the pipeline full. There were several revisions to the product, bringing faster speeds and lower prices. At one point, the low-end 233 MHz card could be had for less than $260.

But Newer didn't completely iron out its problems. Their OS 9 compatible driver for the PDS card was unexpectedly unstable, and a variety of other business problems culminated in a cash crunch that forced Newer to the brink of bankruptcy in early 2000. An 11th-hour debt-for-equity deal with one of their major suppliers saved the company and imposed some much-needed discipline. Newer stayed afloat for the rest of 2000, but then finally called it quits in 2001.

There are still options for 6100 users out there, as the retail pipeline is not completely empty yet, and there is a used market for these cards, too.

So it's a fond farewell to Newer. My Newer card is still chugging along at 210 MHz, and will probably do so for years to come. Best of luck to the staff, and here's hoping that their next products are as compelling as this one was, no matter what name is on the box.
