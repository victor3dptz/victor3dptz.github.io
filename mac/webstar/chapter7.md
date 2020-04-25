---
layout: page
title: Chapter 7. Frequently Asked Questions
---

This section describes some commonly asked questions and answers.

**When I launch the WebSTAR Admin application, I can't see my WebSTAR server across the network, even though I know it is running.**

Most likely the server computer running WebSTAR does not have program linking turned on at one or more of the three possible levels. See "Turning On Program Linking" on page 35.

**I keep getting a message that says MacTCP may not be loaded when I try to launch WebSTAR. Why?**

You are trying to use WebSTAR without a valid TCP/IP connection. Make sure your IP address is correctóonce you can get out with a browser, you should be able to run WebSTAR. If you are trying to test WebSTAR locally without an Internet connection, you need to configure MacTCP or Open Transport accordingly. For more information on how to do this, look here.

**Some users are reporting that they can't access a file that's available on the server. I can access the file fine with my browser. What should I look for?**

Most likely the users' web client software is not configured properly. Check the Suffix Mapping/MIME-Type/Helper applications settings in their browser against those in WebSTAR. If this does not help, try to get a detailed description of what happens and then contact StarNine support. A list of frequently used Suffix Mappings and the corresponding MIME Types can be found here.

**Many access requests are being denied and users are seeing the message in our No Access file, but I haven't intentionally denied access to those users.**

When you first launch the WebSTAR server, all clients are allowed to access a server. But if you specify even one Allow or Deny statement, that default is reversed so that no clients are allowed to access the server without explicit permission. You may have entered one or two Allow or Deny statements and did not realize that you were excluding all other clients. See "Allow and Deny" on page 54 for ways to use this security method.

**A little while after I configured WebSTAR, it quit. What could cause this?**

WebSTAR probably ran out of memory. The most common reason for this is that it was processing too many concurrent connections. If you increased the Max Connections setting, you should also increase the WebSTAR application memory. To increase application memory, select the WebSTAR icon and choose Get Info in the Finder File menu. Then, type a higher number in the Preferred Size text field. A good rule of thumb is to add 100K for each connection beyond the default 12.

**Why does WebSTAR quit with an Out of Memory error, even though I have enough RAM allocated for my connections?**

If you have followed the suggested guidelines on RAM allocation, you should check the Read Me files for the plug-ins you have installed to see if they require extra memory. You might try starting without any plug-ins and adding them back in one-by-one to find the problem.

**Why did WebSTAR ask me for a serial number when I am already using my permanent number?**

If there is no one else on your network running another copy of WebSTAR with the same serial number, there may be a problem with your desktop file. Try running a hard drive repair utility such as Norton Disk Doctor or Disk First Aid, then rebuild your desktop with the extensions off.

**When I try to start WebSTAR, it tells me there is a problem accepting incoming connections, then quits. Why is this happening?**

Your either have another copy of WebSTAR already running on port 80, or you have another application that can act as an HTTP server, such as NetPresenz, set to serve on port 80. If it is another application, turn off the option to use HTTP or quit the program. If you are trying to run multiple copies of WebSTAR, you need to specify a different port. See "Running Multiple WebSTAR Servers" on page 82.

**Macintosh computer users on the local network can connect to my web server but PC users can't. Why?**

The first thing to check is whether the PC users have IP connectivity. If everything seems fine with TCP/IP, verify that you have not denied access to PC users based on their IP addresses. See "Allow and Deny" on page 54.

**Why can computers on my zone/segment access my WebSTAR server, but computers on other segments of our network can't?**

Again, check your Allow/Deny settings to make sure you have not denied these IP addresses access to your server. If you have not, there may be a problem with your network setup or router configuration. Also, if you are using Open Transport, be sure that the box labeled "Use 802.3" in the TCP/IP control panel is unchecked.

**What do I need to do to use WebSTAR over a dial-up connection?**

You need to get a static IP address from your Internet service provider, then you need to enter this address in your MacTCP or TCP/IP control panel and your PPP software before you can make your server available on the Internet. Your Internet service provider should also be able to help you register a domain name and maintain a DNS entry for you.

**I want to make some Macintosh files accessible through the WebSTAR server. What do I need to do?**

To make Macintosh files visible to web clients, you should create a URL link to those files in an HTML document (your home page or another HTML document). Then, you should check that a suffix mapping entry exists to return the Macintosh files appropriately. If necessary, add an entry to your suffix mapping configuration.

**How do I serve other types of files?**

You need to enter a suffix mapping for these files so that WebSTAR can recognize them and tell the browser what to do with them. A list of common suffix mappings is available on our web site here.

See "Suffix Mapping" on page 41 for more information.

**I made a change to one of my files but when I tried to load it in my browser, it hadn't changed at all. Why?**

Whenever you make a change you any of your files, make sure you use the Flush File Info Cache command on the Options menu of either WebSTAR or WebSTAR Admin. If this poses a problem because you frequently update your files, you can either us a simple script to flush the cache periodically, or turn caching off altogether (see "WebSTAR Admin Options Menu" on page 40 and "File Info Cache Size" on page 60).

**Why doesn't WebSTAR index directories automatically, like UNIX servers do?**

This is a major security hole in UNIX serversóit allows clients to access any file in a directory. WebSTAR is designed so that only files you link to or otherwise make available are visible to users. You can provide directory indexing functionality with the WebSTAR Directory Indexer plug-in included with WebSTAR, with any of the utilities listed on our web site on the Extending WebSTAR page, or by just writing a simple CGI.

**Can WebSTAR serve up a default file when a directory is accessed?**

Yes. When a URL points to a folder instead of a file, WebSTAR returns the file with the name specified in the Index field in the Misc. Settings dialog in WebSTAR Admin. See "Index" on page 62.

**Can my main index page be inside a subfolder?**

Unless you specify the path to a directory, WebSTAR will serve the Index file from the folder it is in. However, you can link from this page to a file inside a subfolder, or you can use a RAW file as your index page to redirect browsers to another page on your site (see page 48 for more information).

**Am I stuck with serving HTML files for my Index, Error, and No Access files?**

No. WebSTAR will serve any type of document with a valid suffix mapping for these three special files. CGIs and plug-ins are especially handy for handling error conditions, since they have access to information like the URL of the nonexistent file and the page that referenced that URL. This enables you to generate automatic replies to clients, rather than simply returning a generic error message.

**Why do I get a message every time I start up that says "Warning - your No Access file will be processed by an action"?**

You have either specified a CGI or plug-in as your No Access file, or your .html files are being handled by a CGI or plug-in. This is just a warning to make sure that the CGI or plug-in will not allow unauthorized access to your server; most commercial packages do handle this file correctly.

**There are entries in my log file for domain names and IP addresses to which I have specifically denied access. Are they getting in anyway?**

No. Look carefully at these entries; they should have a result of PRIV rather than OK, meaning that security was invoked for this connection. You would only need to worry if these users went on to access other files on your site, which should not be happening.

**I am trying to set up realms to protect pages served by my CGI, but it isn't working. How can I do this?**

WebSTAR will only look for a match string on the part of the URL it handles; anything after a ? or $ in a URL is passed directly to the CGI. If your CGI does not have an internal security scheme, you can just put the links to these pages inside folders that can be protected by a realm.

**How come my CGI applications don't work from my form? All I get is junk on the screen.**

You used the Open Local or Open File command from your web client running on the same computer as WebSTAR to open your form. Opening a file directly with the client, without connecting to the WebSTAR server first, means that the client is using a file URL (file:///) instead of a location URL (http://) to access the file. If you don't have a complete URL specified as the action procedure in your form, the client has no idea how to run your CGI application.

**I see a message "Error receiving results from ACGI execution. (-1701)" in an HTML page. What does it mean?**

This message means there is something wrong with your CGI. Even if it compiled correctly, the CGI is failing to return any data and WebSTAR gives up waiting for it.

**My CGI doesn't run. I get nothing in the client.**

Your CGI is failing before it returns a result to WebSTAR. Try running it interactively, using the Script Editor if it is an AppleScript. Pass dummy arguments or predefined variables to get the script to run. It also helps to use AppleScript's try...on error construct to trap errors, so something is always returned to WebSTAR.

**How do I return a complete HTML document or GIF from a CGI application?**

URL redirection is the trick. Return the "302 Found" HTTP response code and a Location: header field with a complete URL to the document you want to return. For details, see the HTTP/1.0 standard, described in "Additional Information Resources" here.

**How can I retrieve the WebSTAR Status window if it has moved off the screen?**

Launch WebSTAR and hold down the mouse button while WebSTAR starts. This will reset the WebSTAR window to its default position.