---
layout: page
title: Chapter 5. Using WebSTAR Plug-Ins
---

This chapter provides information about how to install and configure WebSTAR plug-ins.

### Installing Plug-Ins

In most cases, the default WebSTAR plug-ins are automatically installed when you run the WebSTAR Installer. If you acquire 3rd party plug-ins or need to install a plug-in from the Finder, follow these instructions:

#### To install a plug-in from the Finder:

1. Quit WebSTAR
1. Drag the plug-in from its folder into the WebSTAR Plug-ins folder.
1. Allocate additional RAM to WebSTAR, if necessary.
1. Restart WebSTAR.

That's all there is to it. If you need to remove a plug-in, reverse the process.

#### To remove a plug-in from WebSTAR:

1. Quit WebSTAR
1. Drag the plug-in from the WebSTAR Plug-ins folder to a folder location somewhere else on your hard drive.
1. Deallocate additional RAM from WebSTAR, if necessary.
1. Restart WebSTAR.
1. Remove any Suffix Mappings not configured by the plug-in

The balance of this chapter describes each WebSTAR plug-in and anything you need to know in order to properly install and configure it.

### WebSTAR Auto BinHex Plug-In

The WebSTAR Auto BinHex plug-in performs on-the-fly binhexing of files and Macintosh applications by simply appending the ".hqx" suffix to the end of a URL. For instance:

```
http://your.server/file.sit.hqx
```

#### Installation Issues

The WebSTAR Installer installs the WebSTAR Auto BinHex plug-in by default. If a Finder based installation is required, you should:

* Create a ".messages" file for each directory for which you plan to allow BinHexing.It is not necessary to allocate additional RAM to WebSTAR in order to use this plug-in.If you need to remove the WebSTAR Auto BinHex plug-in:
* Remove any ".messages" files.
* Using WebSTAR Admin, check your Suffix Mapping entries to make sure that all necessary file types are defined.

> WebSTAR Auto BinHex will not allow files with a creator of "WWW(omega)" to be BinHexed and served.

> Instead of modifying existing Suffix Mappings, add duplicate Suffix Mappings, change the Action to BINHEX, and move the duplicates before the originals in the list. This allows you to easily remove the WebSTAR Auto BinHex plug-in and revert to the original Suffix Mappings.

#### Configuration

* Run the server with the WebSTAR Auto BinHex plug-in installed.
* From a web browser, connect to the URL:

```
http://your.server/pi_admin.hqx
```

Your browser displays the WebSTAR Auto BinHex configuration screen.

* Adjust any Security or Caching preferences, if necessary.
* Click the "Save" button.

### WebSTAR Byte Server Plug-In

The WebSTAR Byte Server plug-in supports byte range serving for Adobe Acrobat PDF files. Now you can use WebSTAR to serve individual pages from very large PDF files without the entire file having to be downloaded first.

#### Requirements

You need the following to install, test and use the WebSTAR Byte Server plug-in:

* Adobe Acrobat 3.0 or later which can be downloaded from:

```
http://www.adobe.com/
```

* The Acrobat "Amber" plug-in for Netscape Navigator or Microsoft Internet Explorer (part of the Acrobat 3.0 archive).
* PDF documents that are saved in the Adobe Acrobat 3.0 format.

> PDF files created with earlier versions of Acrobat cannot be byte-served.

#### Installation Issues

The WebSTAR Installer installs the WebSTAR Byte Server plug-in by default. If a Finder based installation is required, keep in mind:

* You should probably remove any existing PDF Suffix Mappings (optional, but safe) and quit WebSTAR. Then follow the installation instructions at the beginning of this chapter.If you need to remove the WebSTAR Byte Server plug-in:
* Using the WebSTAR Admin, remove all non plug-in defined Suffix Mappings with an Action of BYTE_SERVER.
* Using WebSTAR Admin, check your Suffix Mappings to make sure that all necessary file types are defined.

#### To test the plug-in:

* Run WebSTAR and WebSTAR Admin. Remove any existing PDF suffix mappings (optional, but safe), and quit WebSTAR.
* Place an Acrobat 3.0 or greater PDF document somewhere in your WebSTAR document tree. Such documents must have a .pdf suffix.
* Run WebSTAR.
* Install the Acrobat browser plug-in in your Microsoft Internet Explorer or Netscape Navigator plug-in folder. The Acrobat browser plug-in is available from:

```
http://www.adobe.com/
```

* Make sure Acrobat 3.0 or later is installed somewhere on your hard drive.
* Run your web browser and connect to your server, requesting the PDF file.

As the PDF file loads, Acrobat plug-in page controls will become active in your web browser's window. 

* Click on the forward page button, which will stop the streaming download and switch to byte range serving.

As you step forward through the document, the browser will request individual ranges of bytes from WebSTAR instead of the entire document.

### WebSTAR Data Cache Plug-In

The WebSTAR Data Cache plug-in performs web server file caching. In other words, the contents of the static files in your web site are served from memory (without accessing the disk), whenever possible. The WebSTAR Data Cache is an intelligent cache, using a frequency-based algorithm to automatically adapt to changing server loads. After installation, you can forget that it is there. Whenever you modify files that may be cached, choose WebSTAR's Flush File Info Cache command from the Options menu. This causes the WebSTAR Data Cache to be cleared along with WebSTAR's internal file information cache.

#### Installation Issues

The WebSTAR Installer installs the WebSTAR Data Cache plug-in by default. The Data Cache plug-in is not configured to run by default, it is only installed by default. If a Finder based installation is required, you need to:

* Increase the memory allocation of the server by at least 256K, or the amount you wish to cache.
* Restart the server after installation.
* Change the Action for all file types that you wish to cache to "CACHE".

> Do not add WebSTAR Data Cache Suffix Mappings for file types that require processing by other CGIs or Plug-Ins. Typically, only file types that are currently transferred as TEXT and BINARY should be cached.

> Instead of modifying existing Suffix Mappings, add duplicate Suffix Mappings, change the Action to CACHE, and move the duplicates before the originals in the list. This allows you to easily remove the WebSTAR Data Cache plug-in and revert to the original Suffix Mappings.
 
If you need to remove the WebSTAR Data Cache plug-in:

* Decrease the memory allocation of the server, if necessary.
* Using WebSTAR Admin, check your Suffix Mapping entries to make sure that all necessary file types are defined.

#### Configuration

Run the server with the WebSTAR Data Cache plug-in installed.

* From a web browser, connect to the URL:

```
http://your.server/pi_admin.cache
```

Your browser displays a screen similar to the one shown in Figure 24.
* Type the desired file cache size (in bytes) into the text box.

*WebSTAR Data Cache is pre-configured for a size of 256K.*

* Click on the Save button.
* Increase or decrease the memory allocation of the server, if necessary.
* Restart the server.

> Failure to perform step 5 may cause the server to crash.

> Selecting an optimal cache size is a matter of trial and error. A cache that is too small has no effect on performance. A cache that is too large wastes memory. Ideally, you would define a cache size that is large enough to hold all of your cached documents. When in doubt, make the cache as big as memory allows.

![Data Cache](/mac/webstar/cache.gif)

### WebSTAR Directory Indexer Plug-In

The WebSTAR Directory Indexer plug-in allows folder/directory listings to be displayed in the browser, and provides a user interface for uploading and downloading files to and from the web server.

#### Installation Issues

The WebSTAR Installer installs the WebSTAR Directory Indexer plug-in by default. The WebSTAR Directory Indexer plug-in is not configured to run by default, it is only installed by default. It is not necessary to allocate additional RAM to WebSTAR in order to use this plug-in. If you need to remove the plug-in:

* Reset your Index file to "default.html".

#### Configuration

* Using the WebSTAR Admin set the "index" page of the server to be "<indexname>.DIR" (e.g., "default.dir" or "Index.dir"). The .DIR suffix is essential to force the server to run WebSTAR Directory Indexer instead of serving a default page.
* Create a file called ".message" in each directory you want to be indexed on the web. If the .message file exists in a folder, a directory index can be returned. The contents of this file (HTML or TEXT) are displayed above the directory listing. Please see the ReadMe.

> WebSTAR Directory Indexer creates a folder called "WebSTAR_Directory_Cache" in each folder that is designated to be indexed. This folder contains cached GIF icon graphics and is not displayed in the directory index listing.

#### Follow these steps to use the configuration page:

1. Run the server with WebSTAR Directory Indexer installed.
1. From a web browser, connect to the URL: http://your.server/pi_admin.dir
1. Configure the settings as desired.
1. Click on the Save button.

> Some options configurable through the WebSTAR Directory Indexer administration page are only applicable when the Plug-Ins WebSTAR Auto BinHex and WebSTAR File Upload are installed.

### WebSTAR File Upload Plug-In

The WebSTAR File Upload plug-in allows WebSTAR to receive files sent via the HTTP Upload feature in Netscape Navigator and other browsers.

#### Installation Issues

The WebSTAR Installer installs the WebSTAR File Upload plug-in by default. The WebSTAR File Upload plug-in is not configured to run by default, it is only installed by default.

It is not necessary to allocate additional RAM to WebSTAR in order to use this plug-in. If a Finder based installation is required, keep in mind:

* You need to create a .permissions file for each directory for which you would like to allow file uploading.

> A permissions file can be any TEXT file named ".permissions" .

If you need to remove the plug-in:

* You may want to remove your .permissions files. When the WebSTAR File Upload is used in conjunction with the WebSTAR Directory Indexer Plug-In, an uploading interface is presented at the bottom of each directory listing.

### WebSTAR Image Map Plug-In

The WebSTAR Image Map plug-in allows you to use "clickable" image maps and map files without the use of an external CGI application on your web server. WebSTAR Image Map currently supports the NCSA methods of circle, poly, rect and default in the map file.

#### Installation Issues

The WebSTAR Installer installs the WebSTAR Image Map plug-in by default. It is not necessary to allocate additional RAM to WebSTAR in order to use this plug-in. If a Finder based installation is required, keep in mind:

* Using the WebSTAR Admin, check your Suffix Mappings to make sure all ".MAP" files are set to be processed by the WebSTAR Image Map plug-in.

If you need to remove the plug-in:

* Using WebSTAR Admin, check your Suffix Mappings to make sure that all necessary file types are defined.

#### Issues

* WebSTAR Image Map does not work with the WebSTAR BG server.
* It is not recommended that you use WebSTAR Image Map with CERN map files.
* WebSTAR Image Map does not currently support aliases or referencing of files through an alias.

#### Image Map Syntax

In your HTML page(s) you will need to indicate that your graphic is a clickable map. You can use the syntax below as an example:

```
<A HREF="examplemap.map"><IMG SRC="examplemap.gif" ISMAP></A>
```

Replace the examplemap.map text with any of your .map files and replace the examplemap.gif text with any of your images. NCSA has sources on the Internet which discuss how image maps work. 

### WebSTAR Java VM Plug-In

The WebSTAR Java VM plug-in gives WebSTAR the ability to run server side Java applets, called sapplets, to perform a variety of useful functions such as HTML form processing, database access, multi-user web applications which require shared space and out of band connectivity to Java applets running on the client side.

#### Installation Issues

Follow the installation instructions at the beginning of this chapter.

If a Finder based installation is required, keep in mind:

* Increase the memory allocation of the server. Please see the "About WebSTAR Java VM" document for additional information regarding memory requirements.

If you need to remove the plug-in:

* Using the WebSTAR Admin, remove all Suffix Mappings with an Action of "JAVA".
* Remove any Java applets (or sapplets) that were being used with WebSTAR Java VM.
* Decrease the memory allocation of the server, if necessary.

### WebSTAR Log Roller Plug-In

The WebSTAR Log Roller plug-in causes WebSTAR to archive the WebSTAR.log file at user-configurable intervals. The archives may contain the entire log (if the log is clear at each archiving) or the previously unarchived portion (if the log is allowed to grow indefinitely).

#### Installation Issues

Follow the installation instructions at the beginning of this chapter. The WebSTAR Log Roller plug-in is not configured to run by default, it is only installed by default.

It is not necessary to allocate additional RAM to WebSTAR in order to use this plug-in.

#### Configuration

* Run the server with WebSTAR Log Roller installed.
* From a web browser, connect to the URL:

```
http://your.server/pi_admin.roll
```

* Adjust the log rolling schedule options.
* Click the Save button.

### WebSTAR QuickSend Plug-In

WebSTAR QuickSend plug-in sends SMTP mail from the WebSTAR to a designated host using user supplied form information. There is no need for the user to configure a browser, as is necessary when using a mail-to tag.

#### Installation Issues

The WebSTAR Installer installs the WebSTAR QuickSend plug-in by default. The WebSTAR QuickSend plug-in is not configured to run by default, it is only installed by default.

It is not necessary to allocate additional RAM to WebSTAR in order to use this plug-in.

If a Finder based installation is required, you need to:

* Drop the sample HTML forms "QuickSend.html" and/or "Subscribe.html" into the WebSTAR hierarchy.

You can then access the forms and perform a trial QuickSend. See the Configuration section for information about defining a default mail host for the plug-in to talk to.

If you need to remove the plug-in:

* Remove the HTML files that are being used to send form data to the QuickSend plug-in.

#### Configuration

* Run the server with WebSTAR QuickSend installed.
* From a web browser, connect to the URL:

```
http://your.server/pi_admin.quicksend
```

Your browser displays a screen similar to the one shown in Figure 25. 

* Enter the default mail host for QuickSend to use when sending mail.
* Configure Logging to be On or Off. With logging On the client will receive an HTML page showing the protocol conversation that occurred between QuickSend and the mail host when the clients message was sent. With logging Off the client will only receive success or failure and error messages.
* Set the Timeout value. The timeout range is 30 seconds to 3 minutes with 30 second increments. The timeout value specifies the amount of time to wait for any response from the mail host before terminating the connection to the host.
* Click the Save button.

![Quicksend](/mac/webstar/quicksend.gif)

#### Additional Configurations and Considerations

QuickSend applies the following rules in using a mail host.

* If the HTML file contains a hidden form element with a name of "Host"and a value filled in with a host name, as in: 

```
<INPUT TYPE="HIDDEN" NAME="Host" VALUE="starnine.com">
```

the mail host used is the mail host in the value field -- whether or not a mail host is specified using the admin configuration page.
* If a mail host has been configured with the Admin configuration page, and no "Host" form element appears in the HTML, then the Admin configured mail host is used.
* If no host has been configured and the HTML does not contain a form "Host" element then WebSTAR QuickSend strips the host information from the To: address and attempts to connect to that system. From an administrative point of view this is the least desirable option. You are encouraged to configure site specific mail host information by adjusting the HTML's or by using WebSTAR QuickSend's Admin page. The supplied forms are only examples and can be altered or customized to suit your needs. However, WebSTAR QuickSend expects "To" and "From" name tag values within an HTML form construct.
* If a subject line and/or message body is to be present in a WebSTAR QuickSend message then "Subject" and "Body"as name tag values within an HTML form construct are also needed. Examination of the "quicksend.html""file will make this apparent.The "subscribe.html" is included as an easy way for users to subscribe or unsubscribe to designated talk lists through the web. Since the example is preconfigured with several of StarNine's talk-lists, you may want to change the HTML to reflect the lists that you want users to have subscribe and unsubscribe access to. The needed changes are obvious upon examination of the "subscribe.html" file.

> Security Issue: As of now the senders IP number is recorded in an X-Comment field RFC header constructed by WebSTAR QuickSend.
 	
### WebSTAR SSI Plug-In

The WebSTAR SSI plug-in implements and extends the "Server Side Includes" functionality as defined by the NCSA. Using WebSTAR SSI you can create dynamic web pages that include information such as the client's address, the time of day, and the number of times a page has been accessed. You can also include the contents of a separate file, or even output the results of a CGI or plug-in in a single page.

WebSTAR SSI supports the standard SSI commands:

* include: insert the contents of one HTML file into the HTML data stream.
* exec: execute a (WebSTAR) CGI application, and insert the result into the HTML data stream.
* echo: insert the value of various server-related variables into the HTML data stream.
* fsize: insert the size of a file into the HTML data stream.
* flastmod: insert the modification data of a file into the HTML data stream.
* config: configure display formats.In addition, the following extended commands are supported:
* counter: increment a named counter, and insert it into the HTML data stream.
* hide: conditionally turn OFF output of HTML until a subsequent SHOW command is encountered.
* show: conditionally turn ON the output of HTML until a subsequent HIDE command is encountered.
* echo: extended to display counter values and WebSTAR W*API variables.
* exec: extended to call registered W*API service routines.

> Sample files showing each of the WebSTAR SSI commands can be found in the Sample Files folder located inside the WebSTAR folder on the distribution media.
 	
#### Installation Issues

The WebSTAR Installer installs the WebSTAR SSI plug-in by default. The WebSTAR SSI plug-in is not configured to run by default, it is only installed by default. It is not necessary to allocate additional RAM to WebSTAR in order to use this plug-in.

If a Finder based installation is required, keep the following in mind:

* Add a Suffix Mapping for the Action SSI to define which files you want WebSTAR SSI to process. A common SSI suffix is ".shtml".

If you need to remove the plug-in:

* Using WebSTAR Admin, remove all Suffix Mappings from WebSTAR which have an Action of SSI.

#### Configuration

No initial configuration is necessary. However, counters created via the <!--#counter name="xxx"--> command may be modified as follows:

* Start the server with WebSTAR SSI installed.
* From a web browser, connect to the URL:

```
http://your.server/pi_admin.ssi
```

* Your browser displays a screen similar to the one shown in Figure 26.
* Modify or delete counter values as necessary.
* Click on the Save button.
* Restart the server.

![SSI](/mac/webstar/ssi.gif)

#### WebSTAR SSI Command Syntax

The WebSTAR SSI plug-in processes HTML files. All SSI commands are constructed as HTML comments of the following form:

```
<!--#COMMAND TAG1="VALUE1" TAG2="VALUE2"-->
```

Both tag="value" pairs are optional. The WebSTAR SSI plug-in is very forgiving about the blank spaces in commands. In general, zero or more spaces may appear between any two symbols inside the comment markers; but at least one space must appear immediately before any tag name. All commands, tags, and values are case insensitive.

If for any reason an SSI command generates an error, the appropriate error message is generated within an HTML comment and will appear at the original position of the command.

#### WebSTAR SSI Command Summary

The commands supported by the WebSTAR SSI plug-in are defined below.

> Functionality that extends the NCSA SSI specification (found at http://hoohoo.ncsa.uiuc.edu/docs/tutorials/includes.html) are in italics.

##### config

The config command allows you to customize the format of three types of values that are generated by the SSI plug-in. For example:

```
<!--#config errmsg="Sorry, an error occurred."-->
```

There are three valid tags that apply to this command: errmsg, timefmt, and sizefmt. Only one tag may be defined in each command.

* **errmsg**: The value assigned to this tag defines an error message that is to be used instead of the built-in error messages.
* **timefmt**: The value assigned to this tag defines the format of all time/date values generated by other SSI commands. The value must be a standard UNIX time format string. The default time format is "%Y/%m/%d:%H:%M:%S", (e.g., "1996/10/01:22:13:47") for which an alphabetical sorting is identical to a chronological sorting.
* **sizefmt**: The value assigned to this tag defines the format of all file size values generated by other SSI commands. Valid values for this tag are: "

"bytes": Output the file size in bytes. For example, "1,234,567 bytes".

"abbrev": Output the file size in kilobytes. For example, "1,234 K".

##### include

The include command allows you to dynamically insert other HTML files into the current HTML file. For example:

```
<!--#include virtual="/stuff/address.shtml"-->
```

All included file names must end in the suffix (e.g., ".shtml") you have defined for the WebSTAR SSI plug-in. File inclusion is only allowed three levels deep. The valid tags for this command: "virtual" and "file", define the format of the file/path name provided in the associated value. Although an SSI file accessed via a normal HTML link may be an alias, included files may not be aliases.

* **virtual**: A "virtual" type file path is a local URL that references a file within the WebSTAR folder hierarchy. Such URLs must NOT contain "http://your.host.name/". To reference a file immediately within the WebSTAR folder, the URL should begin with a slash (e.g., "/myfile.shtml").
* **file**: A "file" type file path is essentially just a Macintosh pathname. Although relative paths may be used, it is recommended that full path names be used instead (e.g., "Volume:Folder:File").
 
##### echo

According to the NCSA definition, the echo command allows you to insert various server related values into the HTML output stream. For example:

```
<!--#echo var="date_gmt"-->
```

In addition, all of the server variables defined in the W*API plug-in specification are also available, as are the counters defined by the counter command (see below). Counters displayed via the echo command are not incremented. The only valid tag for this command is "var". The associated value is one of the standard SSI variable names, *a counter variable name (defined by a previous counter command), or one of the W*API variables (e.g., piServerName, piServerPort, etc.).*

The NCSA standard SSI variables are listed below. Unless otherwise indicated, they return the value defined at: http://hoohoo.ncsa.uiuc.edu/docs/tutorials/includes.html

* DOCUMENT_NAME
* DOCUMENT_URI
* QUERY_STRING_UNESCAPED
* QUERY_STRING
* DATE_LOCAL
* DATE_GMT
* LAST_MODIFIED
* SERVER_NAME
* SERVER_SOFTWARE
* GATEWAY_INTERFACE
* SERVER_PROTOCOL
* SERVER_PORT
* REQUEST_METHOD
* PATH_INFO
* PATH_TRANSLATED
* SCRIPT_NAME
* REMOTE_HOST
* REMOTE_ADDR
* REMOTE_USER
* REMOTE_IDENT (not implemented).
* AUTH_TYPE (not implemented).
* CONTENT_TYPE
* CONTENT_LENGTH
* HTTP_ACCEPT
* HTTP_USER_AGENT
* DOCUMENT_NAME

##### fsize

The fsize command inserts the size of the indicated file into the HTML data stream. For example:

```
<!--#fsize virtual="/stuff/address.shtml"-->
```

Valid tags are the same as in the include command. The format of the output is determined by the sizefmt version of the config command. The default format is "bytes".

##### flastmod

The flastmod command inserts the last modified date of the indicated file into the HTML data stream. For example:

```
<!--#flastmod virtual="/stuff/address.shtml"-->
```

Valid tags are the same as in the include command. The format of the output is determined by the timefmt version of the config command. The default format is "%Y/%m/%d:%H:%M:%S", (e.g., "1996/10/01:22:13:47")

##### exec

The exec command inserts the results (if any) of an external CGI into the HTML data stream. For example:

```
<!--#exec cgi="/Tango" post="sales"-->
```

The tag used to invoke a CGI application is "cgi". The value assigned to this tag is a file path name in "virtual" format, as defined in the include command. An optional POST argument parameter (i.e., a URL Encoded text string) may be passed to the cgi via the "post" tag.

*In addition, the exec command may be used to extend the functionality of the SSI plug-in by calling Plug-In Service routines defined by other W*API Plug-Ins. A second tag called "param" allows you to pass a single text parameter to the service routine. For example:*

```
<!--#exec piservice="TimeOfDay"-->
```

The NCSA SSI specification also defines a "cmd" tag, that allows for the execution of UNIX Shell scripts. This tag is not implemented in this WebSTAR SSI plug-in.

##### counter

The counter command increments a named counter variable, and inserts the new value into the HTML output stream. If the counter variable name has not yet been defined a new counter variable of that name is created and assigned a value of 1. For example:

```
<!--#counter var="main_page"-->
```

The only valid tag for this command is "var", as in the echo command. The associated value is a user defined counter name (up to 32 characters). Counter variables may be modified or deleted via the WebSTAR SSI plug-in administration page <http://your.server/pi_admin.ssi>. Counter variable values are stored in the WebSTAR Settings file, and will disappear if you delete that file.

##### show and hide

The show and hide commands allow you to conditionally turn the HTML output stream on and off based on: date and time, the browser used by the client, or a random value. By default, the HTML output stream is on, so an initial <!--#show--> command is not needed. For example:

```
<!--#hide-->

<!--#show http_user_agent="Mozilla"-->

<!--#show after="1996/12/24:23:59:59"-->

<!--#hide below="10""-->
```

The tag and value, if present in the command, define a condition that must be true for the command to be effected. If the condition fails, the command has no effect. All conditions take the form of a fixed-length string comparison. The comparison is always case insensitive.

The http_user_agent tag specifies that the first N characters of the User_Agent field in the HTTP header, must match the first N characters of the value associated with this tag, where N is the length of that value. The longer the value string, the more restrictive your condition. For example, "Mozilla/3.0" is more restrictive than just "Mozilla".

The before, after, and during tags restrict the show or hide command to work only before, after, or during specific dates and times. All date/time values are specified in the default time format (e.g., 1996/12/24:23:59:59). As above, only the first N characters of the current date/time are compared with the N characters of the specified value, where N is the length of the supplied value. Thus, to show a section only during December, 1996, you might use:

```
<!--#show during="1996/12"->
```

The below, above, and exact tags restrict the show or hide command to work only when an internally generated random integer is below, above, or exactly the same as the supplied value. The random integer is generated once for each SSI file processed by the plug-in. The random value is between 1 and 99, inclusive. For example, to show a section of HTML only 60 percent of the times that the file is accessed, you would precede the HTML with the following:

```
<!--#hide--> <!--#show below="60"-->
```