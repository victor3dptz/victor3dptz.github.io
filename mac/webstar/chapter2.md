---
layout: page
title: Chapter 2. Getting Started
---

This chapter shows you how to install the WebSTAR software and start publishing your information on the World Wide Web.

### System Requirements

WebSTAR requires System 7, MacTCP or Open Transport, and AppleScript. MacTCP and AppleScript are included with WebSTAR and will be installed automatically if they are not already present in your System. If Open Transport is present, MacTCP is not installed. Open Transport is not included in the WebSTAR distribution.

WebSTAR 2.0 also requires Apple's Thread Manager to run. The Thread Manager Extension is built into System 7.5. For earlier versions of System 7, the WebSTAR Installer automatically places the Thread Manager in the Extensions folder.

>WebSTAR 2.0 has improved compatibility with Open Transport. Always use the latest version of Open Transport (OT 1.1.1 is currently available; reliable operation with versions of OT earlier than 1.1.1 cannot be guaranteed). Apple's FTP site (ftp.support.apple.com) always has the latest version.

To access your WebSTAR server once it is running, you need a WWW client browser such as Microsoft Internet Explorer, Netscape Navigator or Mosaic. Server performance can decrease if you run a client on the same computer as the server.

### Memory Requirements
The following formula is a basic guideline for allocating WebSTAR application memory:

```
100K * Max_Connections +1100K = WebSTAR application memory
```

However, if you are running plug-ins or CGI applications, you may want to allocate more application memory to the WebSTAR server. Most sites allocate a minimum of 2.5 MB for the default 12 connections. Up to 4 MB of memory is recommended for 25 connections.If you run a browser on the same computer as the server, you will need at least 2MB of free memory, and server performance can decrease while the browser is running.See the "About WebSTAR" document on the WebSTAR distribution media for more information regarding memory allocations

### Network Requirements

The computer must have a full TCP/IP connection to a network (to publish data locally on that network) or to the Internet. That means you need to obtain an IP address and configure it in the MacTCP or TCP/IP control panels. However, for demo or development purposes, WebSTAR can be run stand-alone on a single machine.

If you are installing WebSTAR on a local TCP/IP network, contact your network administrator to obtain an IP address.

If you are connecting directly to the Internet through a service provider, you need to obtain the IP address from that provider. In addition, the service provider can usually register a domain name for you, provide Domain Name Server (DNS) services, help with configuration and security issues, and work with a telecommunications provider to establish the type of connection you need.

If you are using a modem to connect to the Internet, you can use a standard phone line. However, even if you have a 28.8 kbps modem, dial-up access can be too slow for fast transmission of images, sounds, and video. Often a higher-speed, dedicated line is recommended, such as an ISDN Basic Rate Interface (BRI) line (two 64 kbps channels), a T1 line (1.544 mpbs), or a or a T3 line (45 mbps).

To run WebSTAR on an Intranet or a LAN, you must first install MacTCP or Open Transport on the web server computer and on each client computer. On the server computer, manually assign MacTCP or TCP/IP an IP address of 192.0.1.2. Assign each client computer a different IP address such as 192.0.1.3 or 192.0.1.4. In MacTCP or TCP/IP choose a connection method (either LocalTalk, MacIP, EtherTalk or Ethernet). Although this connection method may vary depending on your networking topology, make sure the web server and each client computer use the same connection method.

Once MacTCP or the TCP/IP Control Panel is configured, launch WebSTAR on the server computer and a web browser on either the server or on one of the client computers. To access the web server you will need to enter the following address: http://192.0.1.2/.

When you connect your server to the Internet you will be assigned a different set of IP numbers from your service provider or your network administrator. Use these numbers to replace the dummy IP numbers assigned to the server and client computers.

### Upgrading from Earlier Versions

If you have an existing MacHTTP server, you can use WebSTAR to publish the same data with no problems. However, you will have to re-enter your suffix mappings, realms, passwords, and other configuration parameters by using the WebSTAR Admin application. See Configuring WebSTAR.

If you upgrade from WebSTAR 1.x, you do not need to adjust any settings.

>If you are upgrading from a previous version of WebSTAR, you should archive a copy of your current WebSTAR Settings file before using it with WebSTAR 2.0.
>WebSTAR 2.0 converts the password information stored in the 1.3 Settings file into the WebSTAR.pass file.

### Installation

To install WebSTAR, follow these steps:

1. Locate and launch the WebSTAR Installer.
1. Click Install to do an Easy Install.
1. When the install has finished, open the WebSTAR Folder on the hard disk.
1. Double-click the WebSTAR application to start it up.

You are prompted to enter your serial number.

![Serial Number](/mac/webstar/serial_number_enter.gif)

1. Type your serial number (exactly-serial number evaluation is case sensitive) and then click OK.
1. Once WebSTAR is launched, launch the WebSTAR Admin application.
1. In the "Pick a server" dialog box select your WebSTAR server and click OK.
1. Choose Realms from the Configure menu.

WebSTAR Admin displays the Realms window

![Realms window](/mac/webstar/create_add_update_admin_rlm.gif)

1. Create a new Realm with a Realm name of Administration" and a Match string of "pi_admin"
1. Click Add and then click Update

>Failure to complete steps 7 through 11 can result in a breach of server security.

You're now officially part of the World Wide Web!

Initially, the WebSTAR folder contains a default Home Page, the documentation in HTML format, and a few sample files. (No security is initially set on these files.)

### Performing a Test Access

To test that a WWW client can access the WebSTAR server, follow these steps:

1. Launch your WWW browser software, such as Microsoft Internet Explorer, Netscape Navigator or Mosaic.
1. Use the Open URL or Open Location menu command to open this URL:

```
http://webstar.computer.name/
```

where "webstar.computer.name" is the host name or IP address of the computer running WebSTAR.

Initially, you'll see the default home page, which describes how to access other sites and the WebSTAR documentation.

>If you have trouble accessing the server, you can still read the HTML-format documentation in your WWW client software. Launch the client software on the computer running WebSTAR and use the Open File command to open the file locally without going through the server.

### Setting Up a Folder Hierarchy

To set up your site, you need to organize your data in a folder hierarchy within the WebSTAR folder. If you wish, you can place aliases within the WebSTAR folder that reference folders and files in other locations. When you are moving documents into the folders that can be served by WebSTAR, you need to make decisions about who can access the files, how they should be transferred to clients, whether there are links within the documents to other local files, and so forth. Figure 3 shows a basic example folder hierarchy for serving different types of documents in WebSTAR.

![Folder hierarchy](/mac/webstar/folder_hierarchy.gif)

In this example, the Default.html document is the server's home page. This home page is an HTML document that welcomes a user and contains links to other documents available on the server. Its HTML source looks like this:

```
<HTML>
<HEAD>
<TITLE>Welcome To Your WebSTAR Home Page</TITLE>
</HEAD>

<BODY>
<IMG ALIGN=BOTTOM SRC="documentation/images/webstar.gif">
<H2>Welcome To Your WebSTAR Home Page</H2>
This is the default home page for your WebSTAR server, contained in the file "Default.html" located inside your WebSTAR folder. You can use this file as a template to create your own Home page, or replace it with your own.<BR>
<P>

<H2>WebSTAR Technical Reference and Resources</H2>

<UL>
<LI><A HREF="manual.html"><B>WebSTAR Technical Reference</B></A>
- Contains information about configuring and setting up your WebSTAR server.</LI><P><P> 

<H3>External Resources Available on the Net</H3>

<LI><A HREF="http://www.starnine.com/development/extendingwebstar.html"><B>Extending WebSTAR</B></A> - Includes a list of software and add-on products designed to increase the functionality of WebSTAR.</LI><P> 

<LI><A HREF="http://www.starnine.com/webstar/"><B>WebSTAR Home Page</B></A> - Check here often for updates to WebSTAR and information about other WebSTAR
related products from Quarterdeck/StarNine.</LI><P> 

<LI><A HREF="http://www.starnine.com/support/"><B>Technical Support</B></A> - Answers to common questions about WebSTAR.</LI><P>

<LI><A HREF="http://www.starnine.com/address-list-editor.html"><B>WebSTAR-Talk List</B></A> - A great place to exchange information with Quarterdeck/StarNine and other WebSTAR users.</LI><P> 

<LI><A HREF="http://www.starnine.com/announce-list-editor.html"><B>WebSTAR-Announce List</B></A> - Subscribe to the WebSTAR-Announce list to keep informed and notified of new WebSTAR releases.
</UL><P>

<H2>Support for Registered Users</H2>
Registered users can always obtain support directly from StarNine Technologies, Inc. by sending e-mail to <A HREF=mailto:support@starnine.com><B>support@starnine.com</B></A>. Be sure to send your support ID as part of any correspondence. 

<P>
<HR>
<TABLE BORDER=0 CELLPADDING=3>
<TR>
<TD><IMG SRC="documentation/images/starnine_logo_small.gif">
<TD>&copy 1996 StarNine Technologies, Inc., a Quarterdeck Corporation. WebSTAR is a trademark of StarNine Technolgies.
</TR>
</TABLE>

</BODY>
</HTML>
```

In this example, the home page contains links to graphics and documents contained in subfolders in the WebSTAR folder hierarchy.

For your own web site, you should create the HTML source and graphics for a home page that describes your site. If you need help, see "Additional Information Resources" on page 16. When you have created a home page, you can configure your WebSTAR server as described in "Configuring WebSTAR" on page 35.

### A Quick Tour of WebSTAR

When you launch WebSTAR, the server creates a Settings file in the same folder as the WebSTAR application and opens a Status WindowStatus Window like the one shown in Figure 4.

The Settings file stores all the server's configuration information. Since the Settings file is in the server's folder, you can run multiple copies of WebSTAR in different folders on the same computer.

WebSTAR displays the port number on which it is listening in the title bar of its Status Window. This is useful when you're running multiple copies of the server on the same computer.

The Status Window contains messages generated by the server during initialization and while serving. The Report Delay parameter in Miscellaneous SettingsMisc. Settings in the WebSTAR Admin application adjusts the frequency of updates for this window (see "Miscellaneous Settings" on page 58).

At the top of the window are two lines of information that provide statistics about incoming connections and WebSTAR memory usage. These statistics make it easier to analyze the number of connections WebSTAR enables and how much memory it needs to run efficiently.

![Webstar status](/mac/webstar/webstar_status_window.gif)

The fields at the top of the Status Window contain the following information:

* Mem: The amount of free memory currently available to WebSTAR. The amount of memory allocated for a connection may be greater than the amount used.
* Hits: The total number of connections served.
* Max: The maximum number of connections allocated to WebSTAR (concurrent incoming connections) allowed. For information on how to increase this number, see "Max Connections" on page 59.
* Current: How many connections are currently active.
* High: The "high-water mark" of simultaneous connections. Use this value to verify that you have set the maximum number of connections correctly.
* Busy: How many connections have been refused service because WebSTAR was too busy. If this value is not zero, you may need to increase the Max Connections setting. If you are on a low-speed network or have a slower computer, you may find that limiting the number of Max Connections enhances performance by keeping the server and network from getting swamped by too many requests.
* Denied: The number of clients that were denied access based on Allow/Deny securitysecurity. Realm security violations are not logged in this statistic.
* Max Mem: The maximum amount of free memory (high water mark in MB) available to WebSTAR.
* Min Mem: The "low-water mark" for memory usage.
* Up Since: The date and time when the server was last launched.

### File Menu

![File menu](/mac/webstar/File_menu.gif)

The File menu contains commands to close and open the Status Window, and to quit WebSTAR.

### Edit Menu

![Edit menu](/mac/webstar/Edit_menu.gif)

You can manipulate the text items in an open window by using the Cut and Copy commands in the Edit menu. In addition, the Edit menu contains the Serial Numbers commands.

#### Passwords

The Passwords command in the Edit menu opens a dialog box in which you can edit the passwords and user names associated with security realms for this server. You can also import and export lists of user names using this dialog box.

![Passwords](/mac/webstar/webstar_passwords.gif)

See "Add Password" on page 69 for related information.

#### Serial Numbers

The Serial Numbers command in the server's Edit menu opens a dialog box in which you can view, add, or delete serial numbers for WebSTAR software components.

![Serial Numbers](/mac/webstar/serial_number_maintenance.gif)

The buttons in the Serial Number Maintenance window let you add, delete, or get more information about a number. Except for the New button, the buttons operate on a highlighted item. The buttons provide the following functions:

* Delete

This button deletes the selected serial number. For example, you may want to delete a Demo serial number that has expired when you enter the real serial number of the product.

* New

This button opens a window where you can enter a serial number. For example, you may want to add a serial number if you purchase add-on modules in the future. Evaluation of information entered here is case sensitive.

* Get Info

This button opens a read-only window that shows the name of the product, the serial number, expiration date, and start date. If you have problems caused by running multiple copies of WebSTAR with the same serial number, you can open this dialog box to determine which number is in use for each server.

### Options Menu

![Options menu](/mac/webstar/Options_menu.gif)

Items in the Options menu let you change the behavior of the server. All selections made in this menu are saved in the server's WebSTAR Settings file and restored the next time the server is launched.

* Verbose Messages

When this option is checked, WebSTAR produces much more status information about client requests and what the program is doing internally. The information is displayed in the Status WindowStatus Window but not recorded in the log.

Many of the messages produced by checking this option pertain to low-level HTTP or TCP/IP internal state information. If you are not familiar with HTTP or TCP/IP, these messages may seem quite obscure. However, some of the verbose messages can be useful for watching the details of client requests and for troubleshooting. Verbose Messages are used most often by WebSTAR developers. Errors reported with Verbose Messages do not need to be reported to StarNine Technical Support.

>Turning on Verbose Messages causes the server to run more slowly. For normal operations, you should turn Verbose Messages off.

* Suspend Logging

When this option is checked, WebSTAR temporarily closes its log file (if a log file is specified in the Settings file), allowing you to open and examine the file with a text editor. No incoming connection data will be logged to the file while this option is enabled.

* Hide Window in Background

When this option is checked, the Status WindowStatus Window is hidden while WebSTAR is running with other applications on the same computer active in the foreground.

* Refuse New Connections

When you check this option, WebSTAR finishes servicing all currently queued clients and then refuses new client connections until the option is unchecked again. Incoming connections are still reported in the statistics area of the Status WindowStatus Window, but those connections are just "knocking at the door"ó they are not being allowed in and the clients are notified that their connection is refused. This option is useful for gracefully shutting down a server, or for allowing you to change HTML documents while the server continues to run but is temporarily refusing connections.

* Flush File Info Cache

Forces WebSTAR to flush the file info cache.

>You must flush the file info cache whenever you perform an operation on the data you are serving that changes the data stored on disk.

Flushing the file info cache also sends a message to plug-ins (including the data cache) to flush their caches as well.

* Restrict CGIs to CGI-BIN

Allows you to toggle CGI-BIN support from the server console. Setting this flag restricts the execution of CGI and ACGI apps to those contained in a folder called "cgi-bin" at the top level of the WebSTAR document tree (i.e., in the same folder as the server application.)

### Running the Background-Only Server

The background-only version of WebSTAR runs in the background, providing no access to the server's menus or other interface elements. Because there is no user interface, users cannot accidentally quit the background-only application.

Before you can use WebSTAR BG, you must first run the foreground server to enter the product's serial number. This initial launch and configuration of the foreground server creates a valid Settings file in the same folder as the WebSTAR application. WebSTAR BG cannot run properly without a preconfigured Settings file.

After launching and configuring the foreground server, you can begin using the background-only server by quitting the foreground server and launching WebSTAR BG. Both applications can reside in the same folder, but you cannot run them both at the same time. Typically, you would place an alias to WebSTAR BG in your Startup Items folder so it is launched automatically when you start your computer.

Once the WebSTAR BG application is running, you can communicate with it and configure it further by using WebSTAR Admin. To quit WebSTAR BG, select Quit WebSTAR in the WebSTAR Admin Options menu.

A WebSTAR.Messages file in the WebSTAR folder reports any errors which may have caused the WebSTAR BG application to quit unexpectedly (see "WebSTAR.Messages File" on page 69).
