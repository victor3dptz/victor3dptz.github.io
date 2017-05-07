---
layout: page
title: BeOS or NeXT. Did Apple Make the Wrong Choice?
---

It's hard to believe it has been four years. In early 1997, Power Computing announced that they would ship the BeOS with their clones. An upstart cloner shipping an upstart OS, if you will. This was big news, since the BeOS fixed many of the problems that faced System 7. The discussions from then sounds all too familiar now.

BeOS offered preemptive multitasking that would improve the user experience over the Mac's cooperative multitasking. BeOS had protected memory for increased stability. BeOS could easily use more than one processor at a time. BeOS had a dock. BeOS even had a Posix compatibility layer so it could run Unix programs that were recompiled for it. Whew.

But BeOS has more buzzwords that Mac OS X doesn't have.

For example, BeOS is pervasively multithreaded. Multithreading is what allows the Finder in Mac OS 8 to copy a file while you open a window and empty the Trash. BeOS automatically does the multithreading for everything. Because it is built into the system, any program for BeOS automatically makes multiple threads that can be run on separate processors. That way all programs take advantage of multiprocessing without any special programming techniques required.

BeOS also had a journaling file system. With it's file system (which is the equivalent of HFS+ on the Mac), BeOS keeps a "journal" of all the reads and writes it plans to do to the drive so it can recover if there is an error. By building this extra level of security in, it virtually eliminates the need for programs like Disk First Aid or Norton's Disk Doctor. The file system is protected from corruption, and the multithreaded input/output even protects the disk from fragmentation. Instead of building in a Disk First Aid check, like Apple did with Mac OS 8.5, Be eliminated the problem with their initial design.

Be's file system is also database-like. You could search and sort files in BeOS just like you have FileMaker Pro built into the operating system. One advantage was that over time, the properties of files could allow you to do things that the Mac OS can't do easily. For example, an MP3 collection could have your ID3 information like the artist or album name. Or your email could be viewed with it's subject or sender. Sure, your programs do that but in BeOS, the "Finder" can do that as well.

Because BeOS was written as a native operating system for the PowerPC, it's amazingly fast. When I used BeOS 4.5 on my StarMax 3000/200, it was easily twice as fast as the Mac OS on the same hardware. It boots up in 15 seconds. Applications launch almost immediately. I could do four things at once without slowing my computer down. It really made me appreciate how great the PowerPC chip was and how much the Mac OS was holding it back. The beauty of BeOS was that it was designed with a focus on performance. It almost didn't matter what your hardware was, because it would always be responsive and quick.

By designing the BeOS on a clean sheet of paper (Be never worried about backwards compatibility), they were able to make an Operating System that is technically as good as or better than Mac OS X. But here's the catch: Be did that with a fraction of the money and time that Apple invested in Mac OS X. If Apple had bought Be instead of NeXT in December 1996, we would have already had these modern features for a couple of years.

If you own a low end Power Mac with PCI, there's a good chance that it's compatible with BeOS. You won't get Mac OS X's lickable interface, but you'll get a modern architecture that will boost the performance of your computer. You can find more detailed information about BeOS at Be's website. The BeOS white paper is persuasive today in describing how an OS ought to work.
