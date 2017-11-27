---
layout: page
title: Macintosh KOI8-R
---

This page is intended for Macintosh users to help them to use KOI8-R documents on the Internet.

"Mac Russian format" on this page means Russian coding in native Russian MacOS format.
This table shows all characters of the Russian MacOS between 0x20 and 0xFF:

How do you work with KOI8-R on the Macintosh? There are two possible ways:

1. Use an application to translate KOI8-R documents to MacOS format. 
1. Use KOI8-R fonts and a special keyboard layout.

![1](/mac/koi8/1.gif)

I recommend the first solution for the following reasons:

* All KOI8-R fonts that you can get on the Net look ugly on screen while a lot of high quality Cyrillic fonts are available for the Mac from font manufacturers like Adobe, ParaGraph or others in PostScript and TrueType formats. If you already have MacRussian fonts you can use them in Internet applications like in any other application.
* For input in KOI8-R format a suitable keyboard layout is needed. However, yet another keyboard icon in the keyboard menu is not really comfortable for work.
* All Russian (native or localized) programs use MacRussian coding. No Russian dictionary or spelling checker on the Macintosh will work with KOI8-R.
* MacRussian format is the standard for Russian text in the MacOS world. Thus, using MacRussian documents with multiple applications is far easier than exchanging KOI8-R documents.

If you are still looking for Russian fonts and keyboard layouts for the Macintosh, check out "Cyrillic Text" or "Cyrillic and Different Software" about installing information. Some TrueType fonts and Russian System 7 instalation is in Russian Mac System 7.0.1 directory on official Apple ftp sites.

One problem with translating from KOI8-R to MacRussian and back is caused by different character codes used for non-letter symbols. The KOI8-R character set has some semigraphics symbols which are not present in the MacRussian character set (The Mac had real graphics from its birth on :). These symbols are not translated.

This document descript using translations KOI8-R documents to MacRussian format and back for apps:

* Eudora
* NewsWatcher
* Netscape
* NCSA Telnet

![eudora](/mac/koi8/eudora.gif)

Eudora is a very popular Macintosh EMail client application. It is available in two releases: Eudora Pro (commercial product) and Eudora Light (free). Both versions work native on both 68K and PowerPC Macintosh computers. You can download latest release of Eudora Lite from Eudora web server.

Both versions of Eudora support "EudoraTables," a special addition file to support different character sets. For KOI8-R support you can to download this file from Kiarchive or from info-mac and its mirrors from dir info-mac/comm/_Internet/mail/edr, Filename:eudora-cyrillic-111.hqx.

Install EudoraTables by simply copying it to the "Eudora Folder" in your System folder. The next time you launch Eudora, any Russian font you have installed can be used to translate letters from and to KOI8-R!

**Translating incoming messages**

After you received message in KOI8-R format, select it in your "In" window or open the message window. Then select change:Transliteration:"MacCyrillic -> ISO-IR-111/KOI8" in theMessage menu as shown.

![2](/mac/koi8/2.gif)

The text will then be translated from KOI8-R format to MacRussian and can be used in any Macintosh program, including localized Russian applications. If you want set this translation by default, press Shift key when select this menu. Default settings showed in menu by outline font.

**Translating outgoing messages**

To translate a message from Mac Russian to KOI8-R format you need to select"MacCyrillic <- ISO-IR-111/KOI8" from the Message menu. Do this before sending a message you have written in MacRussian format. 

![3](/mac/koi8/3.gif)

If the outgoing message is created by replying to a recieved KOI8-R message, this translation is performed automatically. If you want set this translation by default, press Shift key when select this menu. Default settings showed in menu by outline font.

![newswatcher](/mac/koi8/newswatcher.gif)

NewsWatcher is a popular free NetNews client for the MacOS that is very easy to use. Russian native newsgroups (like Relcom groups) use KOI8-R coding in the articles. Other version of NewWatcher, named like YetAnother NewsWatcher support Eudora-like translation tables. For adding new translation table, you need add apropriate file (Cyrillic KOI-8 for KOI-8R translation) with translation table to YA-NewsWatcher Tables folder in your System:Preferences folder. After first program start you need set KOI-8 table in Preferences:Transliterations dialog. **Atention! In YA-NewsWatcher used ISO-IR-111 translation table, what is compatible with KOI-8R coding.**

To work with KOI8-R translation you need to specify any Mac Russian font in the YA-NewsWatcher preferences:

![newswatcher](/mac/koi8/newswatcher2.gif)

If you want to print from NewsWatcher, set the Print Font in the following preferences area, too. If your system does not have Cyrillic script installed then font names may be not displayed correctly. Don't worry about it, selected fonts shown under this menu show REAL results.

Also you need set this translate option in Subject, Article and Message in Newsgroup Settings dialog for correct translating outgoing messages and arcticle names:

![newswatcher](/mac/koi8/newswatcher3.gif)

While NewsWatcher now is a part of Internet Explorer, then 'lonely application' its not more supported. Ya-NewsWatcher 2.4.0 is a last release of this program, development has beed discontinued. NewsWatcher what included in Internet Explorer 3.0 package do NOT support translation tables.

If you don't need multiple-language support, another NewsWatcher clone, named [MT-NewsWatcher](http://www.santafe.edu/~smfr/mtnw/) (Multi- threated NewsWatcher) by Simon Fraser, may be best choise. MT-NewsWatcher had some useful features, like Multi-threating, Filtering, Speech Recognition and other. Muti-threating allow the MT-NewsWatcher to perform lengthy operations in separate threads, enabling user make other operations in same time. MT-NewsWatcher threads 6 operations (checking for new articles, fetching articles, fetching group headers, searching, opening article references, extracting binaries) with limit of 20 threads and 8 network connections in same time. For MT-NewsWatcher you need System 7.1 or above with Threated manager installed (included in System 7.5 and later). You can download MT-NewsWatcher 2.3.5 from Kiarchive or from MT-NewsWatcher home. Current version (2.3.5) had ISO 8859-1 translation only. For KOI-8 translaton, you need install small patch. After patch instalation you need set appropriate russian fonts only. Next versions of MT-NewsWatcher will support translation tables, then don't install patch on MT-NewsWatcher versions later 2.3.5.

![netscape](/mac/koi8/netscape.gif)

Netscape 2.0 does not support any Russian coding. Since Netscape is not free and can be downloaded from Netscape Communications' authorized sites only, it's illegal to upload patched version to some archive sites with strict uploading policy (e.g. to Relcom Company's own Kiarchive). However, such patches may be available to download from Info-Mac and it's mirror sites. Read documentation within this file before installation.

Netscape 3.X and 4.X had 4 russian code tables (ISO8859-5, Cyrillic Mac, Win 1251,KOI-8-R), but only Win 1251 -> Mac translation work good(Mac -> Mac work too :-). KOI-8R and ISO8859-5 translations don't work correctly. Then you need install patch for Netscape. These patches is available from info-mac or his mirrors from dir info-mac/comm/_Internet/web/ntscp, file name - netscape-30-baltic-cyrillic.hqx (for Netscape 3.X) and netscape-40-baltic-cyrillic.hqx (For Netscape 4.X). (use this link for download patch from ftp.funet.fi info-mac mirror).

For view KOI8-R web pages you need set any russian fonts (Macintosh font, not KOI-8!) in Netscape preferences:

![netscape](/mac/koi8/netscape2.gif)

And choose needed decoding in menu (KOI-8 in this example). To enter russian text with you need have to install a Russian keyboard layout, too.

![netscape](/mac/koi8/netscape3.gif)

Some russian Web servers (Relcom, for example) used now automatic decoding to client-native character table. Then you don't need switch to KOI-8 translation on Netscape Navigator versions greater than 2.x.

If you want have more info about adding auto-translation to Apache Web Server, readHTTP server for Russia page. This page is for Web admins, not for usual Mac user.

![telnet](/mac/koi8/telnet.gif)

NCSA Telnet 2.7b4 is a last version of NCSA Telnet for Macintosh. Program is available from info-mac or its mirrors from dir info-mac/comm/_Internet file:ncsa-telnet-27b4.hqx It support various terminal translations. For adding KOI-8R translation support to NCSA Telnet 2.7b4, you need install small patch. This path simply add KOI-8R translation to exist NCSA Telnet 2.7b4 tables.

For setting KOI-8 translation table you need choose this table in connection settings preferences:

![telnet](/mac/koi8/telnet2.gif)

You need set russian font in terminal preferences too:

![telnet](/mac/koi8/telnet3.gif)

Warning! Only mospaced fonts (like Geneva, Courier or any "Typewriter like") is accessible by NCSA Telnet. Proportional fonts (like Times and lots others) can't be used in NCSA Telnet.

While NCSA Telnet is no longer supported by NCSA, version 2.7b4 is a last release. You can download [NCSA Telnet 2.7b5](/mac/koi8/2.7b5src.sit.hqx) from NCSA server, but its a same version with one different - 2.7b5 is a source code for Telnet 2.7b4.

BetterTelnet is a enhanced version of NCSA Telnet. It fixes many bugs and have some useful additions include KOI8 support. You can download BetterTelnet 1.2.2 from Kiarchive or look on BetterTelnet Web page for more recent version. Setting KOI-8 translation for BetterTelnet is like for NCSATelnet.

![mac](/mac/koi8/mac.gif)
