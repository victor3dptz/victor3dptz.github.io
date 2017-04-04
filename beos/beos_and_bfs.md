---
layout: page
title: BeOS and BFS
---

I'm glad that my article has generated some interest and that David Puett (BeOS or NeXT: The right choice) took the time to clarify some points that I skimmed over. I agree that I oversimplified things in my article. Still, I think some of my ideas were generally correct, even if they were oversimplified.

As far as I know, no file system completely avoids fragmentation. The example in David Puett article points to exactly the kind of situation that can lead to fragmentation -- a file that grows is more likely to get fragmented. But the BFS BeOS Filing System) does several things to reduce the likelihood of fragmentation. It's more fragmentation-resistant than fragmentation-proof.

When I use my PowerBook with the Mac OS, it will write a file in the available free space, but it seems to ignore whether there is contiguous free space. I've had a file written into 200 fragments even though there was a single chunk of free space available. If that file is a QuickTime movie, the fragmentation will result in skips or dropped frames, since the hard drive can not keep up as it is searching for the next fragment.

BeOS does things a bit differently than the Mac OS or some other OSes. When it writes a file, it tries to write it as a contiguous file. It does something called "preallocation," where it gives files room to grow and still stay contiguous. It tries to write files in 64 KB segments, because you get better throughput rates as your block size gets bigger. For example, disk benchmarking will always show random reads as slower than 1 KB reads -- and those are slower than 4 KB, and so on. Be chose 64 KB to provide a balance of size and performance. This may be the reason that the BFS can be considered high-performance. Its typical activity (reads and writes) is at a high percentage of the hardware's theoretical speed. In contrast, the classic Mac OS works at a much lower percentage -- Finder copies are much slower than my benchmark results on the same computer.

BFS also avoids the problem that HFS had of block sizes growing with the size of hard drives. On my hard drive, a 340 byte file takes up 21 KB of space. That's more than 20 KB of wasted space. Apple fixed that problem with HFS+. Like HFS+, the BFS can have a smaller block size -- it's 1 KB in the BeOS. I don't understand how the BFS can have 64 KB preallocation and a minimum block size of 1 KB -- but I'm not a programmer, so I'll just assume it's magic. The designer of the BFS explains some of these issues in a presentation he made in 1998.

In my article, I said that BeOS protects against corruption. David Puett responded that journaling will not prevent corruption. I suspect we are both overstating our points. The journaling provided in BeOS does not prevent all corruption in the BFS, but it does protect against some types of damage. When my Mac freezes while writing to the disk, it's easy for the file system to get corrupted and cause me grief.

This is one reason why people started using a RAM disk for their Netscape cache. By using a RAM disk, it decreases the chance that a Netscape crash could result in file system corruption from a partially written file. Cache files are ephemeral and frequently changing; it was safer to put them on another partition or a RAM disk to separate them from the rest of the hard drive. And RAM disks provided a lot more zip, too.

BFS can still lose information when it hits a snag. If, for example, NetPositive has three cache files in memory waiting to write when the power went out, those files would be gone. But by keeping a journal of intended reads and writes, BeOS would know if a file had not finished writing during the power outage. I still think this provides an extra level of safety or security.

As for David Puett's points about BeOS not having any applications, that sounds like the opposite side of a common Window's complaint about the Mac. PC users say that we have no applications when we have loads of programs that are real gems. No programs? Hah, I've got iCab which doesn't run on Windows. If you head over to BeBits, you'll see that there are indeed many programs for the BeOS.

But, and this is important, there are not many large commercial-grade applications. That's a function of market size. The BeOS market isn't big enough to warrant the investment. Of course, I've heard that same comment dozens of times from PC game companies when talking about the Mac. Doubtless, if Apple had bought Be, there would be many more programs than there are today because the Mac market is much bigger.

I'm not against NeXT, as you'll see in my future articles. NeXT had some great technologies long before any other OS. Still, it's taken four years for Apple to bring their next generation OS to the market. I suspect they could have brought the BeOS to market much more quickly, since they had to port NeXT to the PPC before they even got started on Rhapsody.

We'll never know what would have happened if Apple had bought Be instead. Based on the competing technologies and the intervening history, I still consider it a fair question: Did Apple make the wrong choice?
