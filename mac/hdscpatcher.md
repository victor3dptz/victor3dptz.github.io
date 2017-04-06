---
layout: page
title: HD SC Setup 7.3.5 patcher
---

This program, created with the excellent tool ResCompare, automatically patches Apple's HD SC Setup 7.3.5 so that it recognizes all SCSI drives. It will ask you where your copy of 'HD SC Setup 7.3.5' is located and then creates a patched copy, not surprisingly called 'HD SC Setup 7.3.5 (patched)'. It does not change the original.

To create a working copy of HD SC Setup 7.3.5 patcher:

* Download '[HD SC Setup 7.3.5 patcher.hqx](/mac/soft/HD%20SC%20Setup%207.3.5%20patcher.hqx)'.
* Convert the saved document from BinHex to 'HD SC Setup 7.3.5 patcher.sea'.
* Double-click on 'HD SC Setup 7.3.5 patcher.sea' to create 'HD SC Setup 7.3.5 patcher'.

For the conversion from BinHex you can use Stuffit Lite or CompactPro.

What to do:

* If you don't own ResEdit 2.1.3, you can [click here](/mac/soft/ResEdit_2.1.3.sea.bin) to download it (646 Kb).
* If you don't own HD SC Setup 7.3.5, you can [click here](/mac/soft/Apple_HD_SC_Setup_7.3.5.sea.bin) to download it (90 Kb).
* Open HD SC Setup 7.3.5 within ResEdit 2.1.3
* Open the resource called "wfwr" ID 67.
* Change this byte from "00" to "FF".
* Save HD SC Setup 7.3.5 and close ResEdit 2.1.3

When you have followed these instructions, the saved HD SC Setup 7.3.5 should be able to recognize, initialize (format and install drivers) and test your drive. 
