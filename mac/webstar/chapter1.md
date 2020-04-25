---
layout: page
title: Chapter 1: Welcome to WebSTAR™
---

Welcome to WebSTAR, the ultimate World Wide web server! WebSTAR by the StarNine® division of Quarterdeck is the most widely used desktop web server software on the Internet today.

### About WebSTAR

WebSTAR lets you serve your own web site and publish multimedia documents to millions of web users around the world, right from your Macintosh. With WebSTAR, any file you specify can be served to the web, including GIF and JPEG images as well as QuickTime, PDF, VRML, Shockwave, Java applets and JavaScript among others. You can even publish information from a database. And since WebSTAR is a robust, PowerPC-native application providing threaded multitasking and high performance data caching, WebSTAR easily outpaces more expensive and complicated UNIX and Windows NT servers.

WebSTAR comes pre-configured and ready-to-run: just double-click and you are serving on the web. Adobe PageMill is included for easy web page creation. Extending functionality to WebSTAR is a snap through the use of drop in plug-ins and CGI applications. You can even create your own CGIs in AppleScript, C or Java!

WebSTAR's powerful remote administration capabilities let you monitor and configure your server from across the Internet or from down the hall. With built-in support for HTTP file uploads, you can now submit files to your server from anywhere on the web. WebSTAR also logs server usage information to customizable formats including the Common Log Format and the Extended Common Log Format.

Securing your site's information is made easy with WebSTAR's support for both user name and password security as well as restrictions by domain name and IP address. Handling online commerce transactions and secure data is made easier through the use of WebSTAR/SSL which encrypts the client-server data stream. (Digital ID from VeriSign required)WebSTAR comes with everything you need to create an outstanding web site including Adobe PageMill, FTP and Gopher servers, and Microsoft Internet Explorer for surfing the web.

### Some History

WebSTAR started out as MacHTTP, which has been widely used on the web for several years. WebSTAR includes these long-standing features:

* Allows you to serve information to all WWW clients that support the HTTP/1.0 standard
* Handles URL requests for text and binary documents, for example, for HTML (HyperText Markup Language) documents as well as GIFs, JPEGs, PDF, VRML (Virtual Reality Markup Language), .EXE and other binary formats
* Can execute CGI applications, and can link to other external applications (such as FileMaker Pro, AppleSearch, or HyperCard®) and return results to clients
* Since WebSTAR 1.3, even more powerful add-ons can be created by with WebSTAR's plug-in architecture using common programming languages like C and C++. WebSTAR plug-ins are actually executed as part of WebSTAR and are considerably faster and more flexible than the traditional CGI interface.
* Allows you to control access to the server by clients' domain name or IP address
* Supports complete user name/password security for all files served
* WebSTAR is PowerPC-native

### What's New in WebSTAR 2.0

WebSTAR 2.0 also provides these new features:

* Performance increases

WebSTAR 2.0 is two to three times faster than WebSTAR 1.3ó depending on computer hardware, network connection speed, and server configuration.

* Dynamic, high performance caching of content

WebSTAR 2.0 now performs dynamic web server file caching. The contents of the static files in your web site are served from memory (withoutaccessing the disk), whenever possible, eliminating HFS disk accesses for catalog info when these URLs are requested. This is an intelligent cache, using a frequency-based algorithm to automatically adapt to changing server loads.

* Direct server support for Java applets

WebSTAR now has the ability to run server side Java applets (or sapplets) to perform a variety of useful functions such as HTML form processing, database access, multi-user web applications which require shared space and out of band connectivity to Java applets running on the client side.

* Support for HTTP Keep-Alive

Part of the HTTP 1.1 specification, WebSTAR 2.0 now honors keep-alive requests from browsers that support it.

* Improved username/password support

A new username/password database performs much faster with large numbers of users and can support a substantially larger number of users (between 10,000 and 20,000 as opposed to about 2500).

* Improved Allow/Deny support

WebSTAR 2.0 adds support for allow/deny security by realm. AppleEvent, W*API, and the Admin application support has been added for manipulating allow/deny info for realms (allow/deny on a file/folder/match string basis). Individual realms may also have allow/deny info associated with them.

* Web based remote server administration

WebSTAR now supports remote web based administration of the server. Through the use of a new WebSTAR Admin plug-in, you can now administer essential server functions from any web browser on the Internet. You can monitor the server, set the number of maximum users, refuse incoming connections, set the default home page, and enable or disable server logging.

* Integrated support for Acrobat Byte Serving

Support has been added for byte range serving of Adobe Acrobat PDF files. Now you can use WebSTAR to serve individual pages from very large PDF files without requiring that the entire file be downloaded first.

* Built-in file upload capabilities

WebSTAR can now receive files sent via the HTTP Upload feature in Netscape Navigator and other browsers.

* Support for third party plug-in based security schemes

Third party plug-ins can now register as a security handler with the W*API. The plug-in receives a command message whenever WebSTAR receives a particular HTTP request to be evaluated.

* Integrated support for image maps

WebSTAR 2.0 allows you to use "clickable" image maps and map files without the use of an external CGI application on your web server.

* Supports an expanded command set for server-side includes

WebSTAR now implements and extends "Server Side Includes" functionality as defined by the NCSA. Using the WebSTAR SSI plug-in you can create web pages that include dynamic information such as the client's address, the time of day, and the number of times a page has been accessed. You can also include the contents of a separate file, page counters, or even the output of a CGI or plug-In in a single page.

* Common Log FormatCommon Log Format and Extended Common Log Format support

Common Log Format and Extended Common Log Format support is now present to emit log data in the formats used by servers on a variety of platforms.

* Additional logging support

WebSTAR's .log file can now be archived at user-configurable intervals. The archives may contain the entire log (if the log is clear at each archiving) or the previously unarchived portion (if the log is allowed to grow indefinitely).

You can specify what kind of information to include in log file entries; for example, you can easily track information about how many times a day the server is accessed, which pages have been served, and who requested them. Some of the new log properties include information about the number of bytes transmitted and how long the transmission took, the identity of the WWW client software, the user name if authentication was required, and the document referencing this URL.

* Supports UNIX style "cgi-bin" folder

With the option enabled, WebSTAR now automatically looks for a folder named "cgi-bin" within its folder hierarchy and executes any CGI applications it finds when called upon to do so. You can also restrict execution of CGIs to only those contained in the cgi-bin directory.

* On the fly binhexing of Macintosh files

WebSTAR 2.0 now performs on-the-fly binhexing of Macintosh files and applications which have the ".hqx" suffix appended at the end of a URL.

* Built-in support for display of folder contents

The WebSTAR Directory Indexer plug-in displays folder/directory listings in the browser, and provides a user interface for uploading and downloading files to and from the web server. In addition to other iconographic directory listings, the plug-in even displays the custom icon of Photoshop documents.

* Integrated support for sending SMTP mail via the web

WebSTAR 2.0 can automatically send SMTP mail to a designated host using user supplied form information.

### About This Manual

This manual describes the features of WebSTAR and how to use both the WebSTAR Admin application and Admin web interface to configure the server for publishing information on the World Wide Web. It also describes administration issues and provides useful information for writing CGI applications to work with WebSTAR.

This manual does not explain URLs or how to create HTML documents.

This manual does not explain how to write W*API plug-ins or CGI applications.