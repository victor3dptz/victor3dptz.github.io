---
layout: page
title: Chapter 3. Configuring WebSTAR
---

This chapter shows you how to use the WebSTAR Admin application and Admin web interface to configure the WebSTAR server. It covers these important configuration topics:

* Adding new Suffix Mappings to the default set of mappings
* Defining new Actions and setting up Suffix Mappings to use them
* Setting up security Realms and passwords
* Using Allow and Deny statements to restrict access to the server
* Configuring connection and performance parameters
* Specifying special files like the index file and no access files
* Defining a preprocessor and postprocessor
* Specifying log formats

The WebSTAR Admin application provides an easy interface for configuring WebSTAR using a Macintosh computer. You can use the WebSTAR Admin application to monitor one or more WebSTAR servers from a single computer on an AppleTalk network. For background on general administration issues, see "Administering WebSTAR" on page 77.

### Turning On Program Linking

Program LinkingProgram linking is a built-in Macintosh System 7 feature that lets users and applications link to programs across a network. If you are running the WebSTAR server and the WebSTAR Admin application on separate computers, the computer running the WebSTAR server must have program linking turned on, or WebSTAR Admin will be unable to see the WebSTAR server on the network.

Program linking has three levels of control:

* System level
* Application level
* User level

All three levels of control must be set for program linking to be on. If any one of these levels is not set, the WebSTAR Admin application will be unable to see the WebSTAR server across the network.

>If program linking is not enabled, you must run WebSTAR Admin on the server computer.

#### Enabling Program Linking at the System Level

To enable program linking at the system level, open the Sharing Setup control panel and click the Start button in the Program Linking area of the dialog box.

![Sharing setup](/mac/webstar/sharing_setup.gif)

Clicking the Start button in the Program Linking area turns on program linking.

#### Enabling Program Linking at the Application Level

To use WebSTAR Admin, program linking must also be allowed in the WebSTAR application, as it is by default.

To check that WebSTAR allows remote program linking, select the WebSTAR icon in the Finder and choose Sharing from the File menu. The "Allow remote program linking" option should be checked. If for any reason it is not checked, check it now.

![Program Linking](/mac/webstar/program_linking.gif)

#### Enabling Program Linking at the User Level

Allow user to link to programsWhen you select a server in the WebSTAR Admin application, you are prompted to supply a user name and password to access the remote server. This is an important security feature.

To use WebSTAR Admin, the user profile for that name and password must also have program linking turned on.

To turn on program linking in the user's profile, open the Users & Groups control panel and then double-click on a user icon.

![User Program Linking](/mac/webstar/user_program_linking.gif)

Check "Allow user to link to programs on this Macintosh" in the Program Linking area of the dialog box to enable program linking for this user.

### Launching the WebSTAR Admin Application

After turning on program linking, launch WebSTAR by double-clicking it. Then, double-click the WebSTAR Admin application on any computer on the AppleTalk network.

A Chooser-like dialog box opens, where you select a WebSTAR server. (You may need to select a zone and computer name first.) Select a WebSTAR server and click OK to open the initial WebSTAR Admin Monitor window.

![Admin Application](/mac/webstar/admin_ready_to_go.gif)

The title bar of the Monitor window shows the host name of the computer or IP address where the selected server is running, as well as the port on which it is running (the port number is appended in the title bar after the colon).

In the upper-left area of the window are vertical bar graphs that indicate the current usage (number of connections) on the server. These bar graphs scroll from right to left in histogram fashion at 15 second intervals.

Each histogram contains two marks, a gray high-water line mark indicating the maximum number of users, and a black bar. The high water mark is a graphical representation of the "High" connections number (see the "High" statistic described in the next section).

#### Statistics in the Monitor Window

The Connection statistics displayed in the upper-right of the WebSTAR Admin Monitor window show the following information:

* Connections: The total number of active connections for this server.
* Listens: The number of listening processes for incoming connections.
* High: The "high-water mark" of simultaneous users. Use this value to verify that you have set the maximum number of users correctly.
* Max: The maximum number of connections allowed (concurrent incoming connections). See "Max Connections" on page 59.
* Busy: How many clients have been refused service because WebSTAR was too busy. If this value is not zero, you may need to increase the Max Users setting. See "Max Connections" on page 59
* Denied: The number of clients that were denied access based on global allow/deny security. Individual Realm security violations are not logged in this statistic.
* Timeout: The number of client connections that were terminated because the client did not respond to the server in the allowed time. See "Timeout" on page 60.
* Up Since: The date and time when the server was last launched.
* The amount of data the server has transferred (in bytes) since it was last launched.
* Version: The version number of the WebSTAR server software.

### WebSTAR Admin File Menu

![File Menu Admin](/mac/webstar/File_menu_admin.gif)

* New Monitor: This command opens a Chooser-like window in which you can select a server. When you select a WebSTAR server and click OK, the WebSTAR Admin application opens a Monitor window for that server.
* Close: Closes the frontmost active Monitor window.
* Quit: Exit the WebSTAR Admin application.

### WebSTAR Admin Edit Menu

![Admin Edit Menu](/mac/webstar/Edit_menu_admin.gif)

You can manipulate the text items in an open window by using standard Macintosh commands in the Edit menu. Some text must be selected in the window to activate the Edit menu.

### WebSTAR Admin Options Menu

![Options Admin Menu](/mac/webstar/Options_menu_admin.gif)

The Options menu always applies to the frontmost active Monitor window. This is important to remember when there are multiple Monitor windows on the screen. All selections made in this menu are saved in the server's WebSTAR Settings file and restored the next time the server is launched.

Most of the commands in this menu duplicate the commands in the WebSTAR server's Options menu (see "Options Menu" on page 30). The WebSTAR Admin Options menu contains these additional commands:

* Ignore Status Updates
* Ignore Log Updates

These are commands sent by the WebSTAR Admin application to the WebSTAR server to configure status reporting communications with that server. When checked, the WebSTAR Admin application stops requesting status or log information from the WebSTAR server whose Monitor window is active.

* Quit WebSTAR

Shut down the selected server.

### WebSTAR Admin Configure Menu

![Admin Configure Menu](/mac/webstar/configure_menu_admin.gif)

Items in the Configure menu set configuration parameters in the WebSTAR server. The Configure menu always applies to the frontmost active Monitor window. All selections made in this menu are saved in the WebSTAR Settings file and restored the next time WebSTAR is run. The commands in this menu are described in detail in the next sections.

### Suffix Mapping

Suffix mapping determines how the WebSTAR server returns data to a WWW client. It lets you specify an Action and MIME type for processing the URL and returning data, based on the filename suffix on the Macintosh file Type and Creator fields of a retrieved document.

To set up mappings based on suffixes, you have to include a filename suffix in the names of your documents. If you prefer not to rename documents, you can set up mappings based on the Macintosh file Type and Creator fields instead. If WebSTAR doesn't find a filename suffix, it examines those fields and looks for a relevant mapping.

Suffix mapping can be used for more than handling standard file or binary transfers or CGI execution. For example, suppose certain files contain Kanji characters. You can name all of those files with the same suffix and then specify the appropriate MIME type for handling 16-bit characters.

Choose Suffix Mapping in the Configure menu to open this dialog box:

![Suffix Mapping](/mac/webstar/admin_suffix_mapping.gif)

The Suffix Mapping dialog box lets you add, delete, or modify Suffix Mappings. Use the up-arrow and down-arrow to move the selection up or down. To view additional mappings, use the scroll bar at the right side of the window.

>The order of the Suffix Mapping mappings list is significant; if two mappings match a URL, WebSTAR uses the first one. Use the up and down arrows in the dialog box to change the processing order. The order of mappings with a check mark in the lock column cannot be changed.

Clicking the Edit button when a list item is selected causes the fields of the selected item to appear in the appropriate text fields and menus. (Double-clicking an item has the same effect.) Clicking the Replace button when a list item is selected replaces the selected item with the information specified in the text fields and menus.

When you click Update, the changes you have made are stored in the Settings file. If you don't want to save your changes, click Cancel.

>Suffix mapping items with a check mark in the lock column are preconfigured and automatically defined by plug-ins. These items cannot be edited.

#### How Suffix Mapping Works

The server fulfills a URL request and takes the first, best match. Suffix matches takes priority over all other fields. A match that includes Type and/or Creator in addition to suffix is stronger than a match that just includes the suffix. A match specifying only Type or Creator will be made if the URL doesn't match another entry by suffix. If a match cannot be found, the default Action and MIME type are used.

>An Asterisk, meaning in suffix mapsasterisk in a field is not a wildcard character. It is a placeholder that does not correspond to any suffixes, Macintosh file Type and Creatorfile Typefile CreatorMacintosh file Types, or Creators. In effect, the asterisk in a field removes that field from consideration as a possible match criterion. If you prefer, you could use any different character or string of characters that you know will not match any existing suffix, file Type, or file Creator.

The default Action and MIME type is:

Kind of file | Action | Suffix | Type | Creator | MIME Type
------------ | ------ | ------ | ---- | ------- | ---------
Any file with no Suffix Mapping	| BINARY | * | * | * | text/html

This default means that the server will use a text transfer and assume that it is returning HTML text. However, you can set a different default MIME type if you prefer (see "Default MIME Type" on page 65).

#### Guidelines for Adding Mappings

In practice, unless particular files need special processing, administrators usually specify "general" Suffix Mappings that use an asterisk (*) in one or more fields. For example, if you have documents created by both Excel 4.0 and Excel 5.0 that have different file Types but the same filename suffix (.XL) you can use a generalized Suffix Mapping like this:

Kind of file | Action | Suffix | Type | Creator | MIME Type
------------ | ------ | ------ | ---- | ------- | ---------
Excel 4 or 5 | BINARY | .XL | * | * | application/excel

rather than adding two entries like this:

Kind of file | Action | Suffix | Type | Creator | MIME Type
------------ | ------ | ------ | ---- | ------- | ---------
Excel 4 | BINARY | .XL | XLS4 | * | application/excel
Excel 5 | BINARY | .XL | XLS5 | * | application/excel

The first method is preferred because it is easier, requires fewer updates, and improves server performance. In addition, if Excel 6.0 documents become available, those documents would match the first, general, Suffix Mapping but would not match either of the more specific ones.

#### Predefined Suffix Mappings

Kind of file | Action | Suffix | Type | Creator | MIME Type
------------ | ------ | ------ | ---- | ------- | ---------
Text (ASCII textASCII) | TEXT | .TEXT | TEXT | * | text/plain
Text (ASCII textASCII) | TEXT | .TXT | TEXT | * | text/plain
Text (ASCII textASCII) | BINARY | .HTML | TEXT | * | text/html
Graphics | BINARY | .GIF | GIFf | * | image/gif
Graphics | BINARY | .JPG | JPEG | *| image/jpeg
Graphics | BINARY | .JPEG | JPEG | * | image/jpeg
Graphics | BINARY | .PICT | PICT | * | image/pict
Graphics | BINARY | .XBM | * | * | image/x-xbm
CGI Applications | ACGI | .ACGI | APPL | * | text/html
CGI Applications | CGI | .CGI | APPL | * | text/html
BinHex | BINARY | .HQX | TEXT | * | application/mac-binhex40
Stuffit | BINARY | .SIT | * | * | application/x-stuffit
Stuffit | BINARY | .SIT | SITD | *| application/x-stuffit
MacBinary | BINARY | .BIN | * | * | application/x-macbinary
PostScript | BINARY | .PS | * | * | application/postscript
TAR files | BINARY | .TAR | * | * | application/x-tar
ZIP compressed files | BINARY | .ZIP | * | * | application/zip
GZIP compressed files | BINARY | .GZ | * | * | application/x-gzip
PC executable | BINARY | .EXE | * | * | application/octet-stream
Microsoft Word | BINARY | .WORD | WDBN | MSWD | application/msword
Microsoft Excel | BINARY | .XL | XLS3 | * | application/excel
Adobe Acrobat (PDF) | BINARY | .PDF | PDF | * | application/pdf
Macromedia Shockwave | BINARY | .DIR | * | * | application/x-director
Macromedia Shockwave | BINARY | .DXR | * | * | application/x-director
Macromedia Shockwave | BINARY | .DCR | * | * | application/x-director
Macromedia Shockwave | BINARY | .SWA | * | * | application/x-director
RealAudio | BINARY | .RA | * | * | application/x-pn-realaudio
MIDI | BINARY | .MIDI | * | * | application/x-midi
AIFF | BINARY | .AIFF | * | * | application/x-aiff
WAV | BINARY | .WAV | * | * | application/x-wav
Quicktime Video	| BINARY | .MOV | MOOV | * | video/quicktime
Quicktime Video | BINARY | .QT | MOOV | * | video/quicktime
Quicktime Video | BINARY | .QTVR | MOOV | * | video/quicktime
Quicktime Video | BINARY | .QTC | * | * | video/x-qtc
MPEG Video | BINARY | .MPEG | * | * | video/mpeg
AVI Video | BINARY | .AVI | * | * | video/x-msvideo
JAVA Applets | BINARY | .CLASS | * | * | application/octet-stream
JAVA Scripts | BINARY | .JS | * | * | application/x-javascript
VRML | BINARY | .WRL | * | * | x-world/x-vrml

#### Adding Suffix Mappings to the Server

To add a Suffix Mapping, follow these steps:

1. In the Suffix Mapping dialog box, choose an Action to be performed from the Action pop-up list. See "Action" on page 47.
1. Specify the file suffix, file Type, and Creator. See "File Suffix, Type, and Creator" on page 48.
1. Enter the MIME Type. This information tells the requesting WWW client software what to do with the returned data. See "MIME Type" on page 49.
1. Click Add to add the mapping.
1. When you are finished adding mappings, click Update.
>If the Type and Creator values contain special characters, encode them using the %xx encoding scheme used in URLs, where xx is the hexadecimal code for the ASCII character. For example, a space character (decimal 32, hexadecimal 20) would be encoded as %20). So, "AB C" would be entered as "AB%20C".

#### Fields in a Suffix Map

##### Action

The Action pop-up list in the Suffix Mapping dialog box has these entries:

* TEXT: Return the file using the TEXT transfer method. The TEXT transfer method converts CR/LF for older browsers. 
* BINARY: Return the file using the BINARY transfer method, without modifying its contents. Only the data fork of the file is transmitted.
* CGI: Load and execute the CGI application specified in the URL. WebSTAR passes arguments to the application by using the Search Doc Apple event. The application is expected to generate a legal HTTP/1.0 header and any response information and return it to WebSTAR as the result of processing the Apple event. This result will then be transmitted to the client without modification.
* ACGI: Load and execute the ACGI application specified in the URL. WebSTAR passes arguments to the application by using the Search Doc Apple event and immediately resumes processing other requests. The application is expected to generate a legal HTTP/1.0 header and any response information and return it to WebSTAR as the result of processing the Apple event. When WebSTAR receives the event reply, it processes the result, which is then transmitted to the client without modification. See "CGI Parameters" on page 113.
* RAW: When the server recognizes a raw file, it opens the files and returns its contents directly to a client, without interpreting the data or generating headers for the file. 
* User-defined: Load and execute the plug-in, CGI or ACGI application associated with this Action, passing the URL as an argument to it. See "User-Defined Actions" on page 49.

##### File Suffix, Type, and Creator

The WebSTAR server uses a document's Suffix, Type, and Creator fields together to determine which Action to apply. The Suffix field takes precedence over Type and Creator. For example, suppose the server receives this URL, which specifies a file named "logo.map" in the server's directory:

```
http://www.site.com/logo.map
```

The server retrieves the file and then looks up .MAP in its Suffix Mapping list, where it finds this entry:

Kind of file | Action | Suffix | Type | Creator | MIME Type
------------ | ------ | ------ | ---- | ------- | ---------
Image Map file | IMAGE_MAP | .MAP | TEXT | * | text/html

The server then passes its global variables to the Image Map plug-in, runs it, and returns the result back to the browser. Or, if the server receives the following URL, which specifies a formatted Microsoft Word document:

```
http://your.site.com/mydoc
```

it retrieves the file, recognizes that there is no filename suffix, and sees that its Type is WDBN and Creator is MSWD. It then looks for a matching Suffix Mapping entry:

Kind of file | Action | Suffix | Type | Creator | MIME Type
------------ | ------ | ------ | ---- | ------- | ---------
Microsoft® Word | BINARY | .WORD | WDBN | MSWD | application/msword

The server then transfers the file back to the client using the binary transfer method and the MIME type application/msword.

##### MIME Type

MIME Type is information transmitted to the browser in the HTTP/1.0 header to indicate what type of file is being returned. This information allows clients to treat the returned data intelligently instead of using some kind of default, such as assuming that all returned data is HTML text. For example, if a client receives data with the application/excel MIME type, it can launch a Helper application to view the formatted data. See "Client and Server Aspects of File Transfers" on page 79 for related information.

>When returning content to a client's browser, CGIs and plug-ins are responsible for generating their own HTTP/1.0 headers, which should include MIME type information. For information about the proper format for HTTP headers, see the HTTP/1.0 standard referenced in "Additional Information Resources" on page 16.

### User-Defined Actions

User-defined Actions are instructions to run an application. Unlike the CGI, and ACGI Actions, which require that the URL specify the name of the script or application directly, user-defined Actions can be invoked based on the URL suffix alone.

Many people use user-defined Actions to support clickable maps or any other type of operation where a single CGI or plug-in can operate on multiple data files. For example, when an Action executes a map CGI or plug-in, all map information is passed to the one CGI or plug-in.

These Actions also allow you to hide implementation details from users. That is, the URL seen by users in a document isn't necessarily the URL that gets executed by the server.

Another use for user-defined Actions would be to create new file types and define an Action to process them appropriately. For example, suppose you have SQL files that contain SQL query statements. You can define an Action that would pass a query to an SQL database like Butler to be found in a database when an incoming URL request references a .SQL file.

User-defined Actions also allow you to swap out or change CGIs or plug-ins without having to change URLs in your documents. You simply edit the Action to point to a new script.Choose Actions in the Configure menu to open this dialog box:

![Admin Actions](/mac/webstar/admin_actions_2.gif)

The Actions dialog box lets you add, delete, or modify user-defined Actions.

> Actions with a check mark in the lock column and cannot be edited.

Clicking the Edit button when a list item is selected causes the fields of the selected item to appear in the appropriate text fields. (Double-clicking an item has the same effect.) Clicking the Replace button when a list item is selected replaces the selected item with the information specified in the text fields.

When you click Update, the changes you have made are stored in the Settings file. If you don't want to save your changes, click Cancel.

#### Defining an Action

Defining an Action requires these two parameters:

* Application: Specify the relative pathname to the script or application to be executed. Relative pathnames begin with a colon (:) and are relative to the folder containing the WebSTAR application.
* Action Name: Specify a name, which will appear in the Suffix Mappings Action menu. The name is case-insensitive.

> No spaces or Macintosh special characters are allowed in the application path or Action name. If those characters appear in a parameter, you need to encode them using the %xx encoding scheme used in URLs, where xx is the hexadecimal code for the ASCII character. For example, a space character (decimal 32, hexadecimal 20) would be encoded as %20). So, "AB C" would be entered as "AB%20C".

#### Associating an Action with a Suffix Mapping

User-defined action: how to use with Suffix Mapping. After you have defined an Action, you can use it in Suffix Mappings. When you add or change an Action, WebSTAR forces a reinterpretation of all Suffix Mappings. If it finds that a previously defined Action which was used by a mapping is now absent, that mapping is ignored (though it remains in the Settings file).

For example, the Actions dialog box shown in Figure 12: contains two user-defined Actions named CLOAK and TEST. Both of these Actions execute an ACGI and return the results as HTML text. After defining these Actions, you can integrate them into the Suffix Mapping list as follows:

* Choose Suffix Mapping in the Configure menu. 
* Select CLOAK from the Action pop-up list, and then fill in the text fields so the entry specifies the following parameters:

Kind of file | Action | Suffix | Type | Creator | MIME Type
------------ | ------ | ------ | ---- | ------- | ---------
HTML file | CLOAK | .HTML | TEXT | * | text/html

* Click Add to add the new mapping at the top of the list.

The intention is to pass all HTML requests to the NetCloak ACGI. 

* Select TEST from the Action pop-up list, and then fill in the text fields so the entry specifies the following parameters:

The intention is to pass all requests that end in .TEST to the Test ACGI.

Kind of file | Action | Suffix | Type | Creator | MIME Type
------------ | ------ | ------ | ---- | ------- | ---------
Files with TEST suffix | TEST | .TEST | TEXT | * | text/html

* Click Add, and then click Update.

### Realms

WebSTAR lets you divide your files and folders into multiple security Realms. You can then require user name/password authentication to access all files within a Realm.

A Realm encompasses all files and folders for which a URL contains a specified string of characters. Attempts to access files or folders in a particular Realm can be limited to valid user names and passwords for that Realm.

Choose Realms in the Configure menu to open this dialog box:

![Admin Realms](/mac/webstar/admin_realms.gif)

The Realms dialog box lets you add, delete, or modify security Realms.

Clicking the Edit button when a list item is selected causes the fields of the selected item to appear in the appropriate text fields. (Double-clicking an item has the same effect.) Clicking the Replace button when a list item is selected replaces the selected item with the information specified in the text fields.

When you click Update, the changes you have made are stored in the Settings file. If you don't want to save your changes, click Cancel.

#### Defining a Realm

A Realm requires these two parameters:

* Realm Name: Specify a name. The name is case-insensitive. The Realm Name is usually shown to users in the user/password dialog presented by a web browser such as Microsoft Internet Explorer or Netscape Navigator.
* Match String: Specify a text string that will be searched for in incoming URLs. It must appear in the names assigned to the actual folders and files that will be included in this Realm.Be careful that each match string you enter is unique. If there is a possibility for a URL to match more than one Realm, WebSTAR will stop searching once it matches the first Realm (based on the order in which they appear in the Realms window). If there is duplication in the match strings, the second Realm will never be matched.

> No spaces or Macintosh special characters are allowed in the application path or Action name. If those characters appear in a parameter, you need to encode them using the %xx encoding scheme used in URLs, where xx is the hexadecimal code for the ASCII character. For example, a space character (decimal 32, hexadecimal 20) would be encoded as %20). So, "AB C" would be entered as "AB%20C".

#### Example Realms

For example, suppose you want to configure your server with some files available to everyone, some files available to coworkers, and some files available to customers. You can do so by defining two Realms such as:

* Realm Name coworkers (match string work). Folders and files in this Realm may have URLs such as:

```
http://your.host/working_draft.html 
http://your.host/work-info/staff_photo.gif
http://your.host/personnel/workers_comp.html
```

* Realm Name customers (match string custom). Folders and files in this Realm may have URLs such as:

```
http://your.host/customer_data/price_list.html 
http://your.host/custom_designs.html
```

The match string can be part of a filename or folder name. WebSTAR looks for the match string anywhere in the URL, so you can control access to multiple files by placing them in a folder whose name contains a Realm's match string.

Once it has found that a file requires authentication, WebSTAR sends the appropriate response to the WWW client, along with the Realm name and a request for a user name and password for the Realm. The client shows this string to the user when it prompts for a user name and password. WebSTAR uses a combination of the user name and the Realm to look up the correct password in the WebSTAR.pass file. If the password supplied by the user matches the password found in the WebSTAR.pass file, the requested file is returned.

Most client programs retain authentication information, so the user only needs to enter it on the first access.

#### Managing a Large Number of Users

The recommended way to manage large user databases is to use the Import/Export functions in the WebSTAR application's Passwords dialog box (see "Passwords" on page 29). For example, a large site could keep as many as 10,000 or more users in a FileMaker database and the administrator makes all changes in that database. The database can then be automatically exported as a tab-delimited, CR-terminated text file in the proper format, then be imported into WebSTAR through the application's Passwords dialog box or automatically imported by WebSTAR using AppleEvents.

### Allow and Deny

WebSTAR can allow or deny client access to the entire server, as well as to individual Realms, based on a specified list of domain names or IP addresses. If WebSTAR determines that the client is not allowed access, it returns the file designated as the No Access file (see "No Access" on page 63).

Choose Allow/Deny in the Configure menu to open this dialog box:

![Admin Allow Deny](/mac/webstar/admin_allow_deny.gif)

The Allow and Deny dialog box lets you add, delete, or modify security directives (Allow or Deny statements) on a global or individual Realm basis. You can specify any number of statements. To view additional statements, use the scroll bar at the right side of the window.

Clicking the Edit button when a list item is selected causes the fields of the selected item to appear in the text field and radio button. (Double-clicking an item has the same effect.) Clicking the Replace button when a list item is selected replaces the selected item with the information specified in the text field and radio button.

When you click Update, the changes you have made are stored in the Settings file. If you don't want to save your changes, click Cancel.

#### WebSTAR Default Allow/Deny Behavior

To determine whether a client is allowed to access the server, WebSTAR evaluates the requests using the following sequence:

WebSTAR first checks the global allow/deny information.

If denied, returns the no access response.

If allowed, WebSTAR checks if a Realm exists for the requested URL.

If a Realm exists, checks if the request contains a valid username and password.

If not, checks if the Realm has allow/deny info associated with it.

If so, checks the Realm's allow/deny info.

If allow/deny info doesn't exist, or if denied, WebSTAR requires a username/password from the requester.

Finally, if the request is allowed, checks all security plug-ins until one says to deny the request.

If all security plug-ins approve, WebSTAR serves the file.

> By default, all clients are allowed to access a server. However, if you specify even one Allow or Deny statement, that default is reversed so that no clients are allowed to access the server without explicit permission.

#### Using Allow Statements

To enable access to specific hosts only, follow these steps:

* Choose "global" or a specific Realm from the pop-up menu.
* In the Match String field, specify a full IP address or hostname.

An example IP address is 198.211.33.1.

The trailing period in the IP address prevents a match with another address such as 198.211.33.10.

An example hostname is sparky.starnine.com.

* Click the Allow button.
* Click Add.
* Specify a partial IP address or domain name in the Match String field.

An example partial IP address is 198.211.33. (to specify a domain), or 1 (to allow all IP addresses that begin with "1")

An example domain name is starnine.com

* Click the Allow button.
* Click Add.
* Continue adding Allow statements for hosts and domains you want to have access to the server.
* Click Update. 

#### Using Deny Statements
If you need to allow most sites to connect to your site but restrict a handful of hosts or domains, you can bypass the default "deny all" behavior of WebSTAR by specifying an Allow * (the * is a wildcard character which means any domain name or IP address) followed by a Deny statement, as shown here:

```
Allow *|
Deny 129.166.3
```

The Allow * statement means "allow all" and operates by matching the first digit in all possible IP addresses, effectively reversing the default Deny behavior. The following Deny statement then refuses access to hosts at that specific network address.

You can also use Deny and Allow statements to allow access to specific hosts within a domain that has been denied. For example, these statements:

```
Allow 129.166. 
Deny 129.166.3 
Allow 129.166.30.1.
```

have the following effect:

* WebSTAR first initiates its Deny all default behavior.
* The first Allow statement specifies that clients with addresses that begin with 129.166 are allowed to connect to the server.
* The next Deny statement specifies that all clients with IP addresses that begin with 129.166.3 are denied access the server. See the important note that follows for more detail.
* The next Allow statement explicitly enables the host with the address 129.166.30.1. to access the server. This statement matches only one specific address.

> WebSTAR always appends a trailing period when comparing a client's IP address to the security entries. To match exactly one host, the IP address argument must end with a period. For example, the Deny statement shown in the example immediately above matches not only all hosts in the 129.166.3 subnet, but also all hosts in the 129.166.30 subnet, the 129.166.31 subnet, and so forth. If you wanted to only restrict hosts in the 129.166.3 subnet, you should add a trailing period to the IP address (129.166.3.).

### Miscellaneous Settings

To set parameters that affect WebSTAR's performance and general functioning, choose Misc. Settings in the Configure menu. This dialog box appears:

![Admin Misc Settings](/mac/webstar/admin_misc_settings.gif)

#### Connection settings

The first four parameters in the left column of the Miscellaneous Settings dialog box determine how many connections can be processed concurrently, on which port the WebSTAR server listens for connections, when connections will time out, and how often the statistics are updated in the WebSTAR Admin window.

##### Max Connections

This parameter specifies the maximum number of concurrent client connections to the WebSTAR server. The default is 12. The valid range for the Max Connections value is 4 to 50 with MacTCP; 4 to 150 with Open Transport. Using MacTCP, the last 3 connections are reserved for reporting that the server is too busy when all of the other connections are in use. When all of the designated connections are in use, incoming clients are informed that the server is too busy to handle their request.

MacTCP can handle a maximum of 64 simultaneous connections, and WebSTAR leaves 14 connections for other TCP/IP services such as FTP, E-mail, and Telnet. Thus, when WebSTAR is configured to handle 50 connections under MacTCP, 14 connections are still available for these other TCP/IP services.

The server can easily get swamped with connections if you have a slow network connection. Requests can come in faster than the server can transmit data to the clients. WebSTAR deals with this overload by refusing connections with a reply message that many clients understand to mean "try again in a few seconds," so some users won't even notice a problem.

The basic rule of thumb is to watch the WebSTAR status window (the bar graphs) and adjust the Max Connections up or down, based on your server's load and performance under that load. Don't be afraid to restrict the number of connections if your server cannot handle the load (because either the computer or your network connection is slow). It may actually help speed transfer rates.

> If KeepAliveKeepAlive is enabled, you should increase Max Connections to 3 times that of normal.

##### Port

This parameter specifies the port number WebSTAR listens to for all incoming connections. The default port is 80.

You can change this number to allow multiple WebSTAR servers to run on one computer on different ports. See "Running Multiple WebSTAR Servers" on page 82.

##### Timeout

The Timeout parameter determines the maximum amount of time (in seconds) WebSTAR will wait before dropping an inactive connection. Timeouts can occur when a CGI application takes too long to execute or when a client doesn't respond to WebSTAR, implying that the connection has been dropped. The minimum value is 15 seconds, the maximum value is 120 seconds, and the default is 60 seconds.

##### Status Report Delay

The Status Report Delay parameter sets the amount of time in seconds between status report events that appear in the upper portion of the Status Window in WebSTAR, and in the WebSTAR Admin application and Admin web interface. The minimum value is 1 second, the maximum value is 60 seconds, and the default is 15 seconds.

##### File Info Cache Size

File Info Cache Size parameter sets the number of bytes to allocate for caching file information. A value of 0 turns the File Info Cache off. The minimum setting for this field is 24k, but setting it any smaller than the default setting results in virtually no performance gain because the cache is continually being turned over as new files are loaded into the few available slots. The maximum setting is the current amount of free memory displayed in the server's status window when file info caching is disabled. Increasing the application's memory partition increases this upper bound correspondingly.

##### Buffer Size 

This parameter specifies how many bytes WebSTAR can send in a single TCP/IP write to the client. The minimum buffer size is 256, and the maximum is 10,240. The default is 3500 bytes.

With a relatively large buffer size, files take a longer time to transfer over slow connections. You can adjust the buffer size to accommodate slower connections. The smaller the buffer size, the faster WebSTAR can send a buffer of data to a slow client without slowing down all the other connections. Unfortunately, there is a point of diminishing return, where the smaller buffer begins to cause WebSTAR to spend more time thrashing through connection servicing than sending data. Usually a value between 512 and 2048 works well for slow clients. If you have a lot of high speed clients, WebSTAR performs better with larger buffer size settings like 4096 or 8192. Experiment to determine the optimum size. 

> PC-based WWW clients that use the Trumpet socket driver may experience problems with WebSTAR if the buffer size is greater than 8K. Lowering the size or reconfiguring Trumpet to allow larger incoming buffers will solve the problem.

##### KeepAlive Connections

The KeepAlive Connections parameter sets the number of connections per client to keep alive. The range is from 1ñ10 connections. A setting of 0 turns it off. The default value is 0. If enabled, make sure you increase the number of Mac Connections allowed.

##### KeepAlive Duration

The KeepAlive Duration parameter sets the number of seconds to keep alive idle client connections. The range is from 1 to 60 seconds. A setting of 0 turns it off. The default value is 0. If enabled, the recommended value is 15 seconds.

##### Use DNS

The Use DNS check box tells WebSTAR whether or not to perform a DNS lookup when a WWW client connects to the server. By default, it is turned off.When this option is checked, the WebSTAR server performs a DNS lookup, caches the hostname, and uses the hostname in reporting and logging. The advantage of performing DNS lookups is that clients' hostnames appear in the log file instead of the much more cryptic IP addresses. The disadvantage is that if a problem occurs during the lookup, the lookup has to time out before the server can proceed. This can decrease server performance if many incoming connections have unresolvable addresses or if the DNS server at your site is slow.

##### Restrict CGIs to CGI-BIN

This setting toggles UNIX-style CGI-BIN support. Checking this option restrits the execution of CGI and ACGI applications to hs ontand in a folder called "CGI-BIN" at the top level of the WebSTAR document tree (i.e., in the sam leahe server application.)

##### Special Files

With the exception of the log file, all special files can be simple HTML documents, CGI, or ACGI applications.

##### Index

An index file is the default document returned if a URL specifies the document "/" or no document at all. If you don't specify an Index filename, the default index file is named default.html. The file can be an HTML file, or a file name including suffix that causes a CGI application or plug-in to execute. Use the Index text field in the Miscellaneous Settings dialog box to designate the name for an index file for the server. The file does not need to be named "index" or "default," it can be any simple filename. The file may be an HTML file, or the name of a script or application to execute.

> The name you enter must be a simple filename. You may not specify a path or partial path as you can for other special files.

When a file with the designated name appears in the WebSTAR folder, WebSTAR will return it if a URL specifies the server alone without a specific filename. Any folder in the WebSTAR hierarchy can have an index file, as long as the file has the name you specify in the Index field. However, if you want to use a different filename for an index file in a subfolder, you can make an alias of the file and rename the alias to the Index filename.

##### Error

Use the Error text field in the Miscellaneous Settings dialog box to type the name of the file to be returned by the server if an error occurs. This is usually an information message telling the user that a requested file cannot be found. The default filename in the field is :error.html.The default error file resides in the same directory as the WebSTAR application. Relative pathnames begin with a colon (:), which indicates the current directory. So, when you type the name in the Error text field, precede it with a colon.

```
:error.html
```

##### No Access

Use the No Access text field in the Miscellaneous Settings dialog box to type the name of the file to be returned if a client is refused access based on Allow/Deny statements in the Settings file. See "Allow and Deny" on page 54 for more details. The default filename is noaccess.html.The default No Access file resides in the same directory as the WebSTAR application. Relative pathnames begin with a colon (:), which indicates the current directory. So, when you type the name in the No Access text field, precede it with a colon (e.g., :noaccess.html).

##### Log File

Use the Log File text field in the Miscellaneous Settings dialog box to type the name of the log file for the server. The default filename is WebSTAR Log. A log of all client accesses is maintained in this file. See "Log Format" on page 65 for related information.

The Log file should reside in the same directory as the WebSTAR application. Relative pathnames begin with a colon (:), which indicates the current directory. So, when you type the name in the Log File text field, precede it with a colon (e.g., :WebSTAR Log).

#### Preprocessing and Postprocessing of URLs

Designating a plug-in, CGI or ACGI application to preprocess URLs allows you to perform an Action before the server processes the URL. For example, you could implement your own security check, bypassing the security in WebSTAR in favor of a different username/password scheme. Or, you could examine every incoming request, look at the preferred language being requested by the browser, and route English requests to one machine and French to another. Another use could be to implement an alternate storage scheme for WWW data other than the Mac OS file system; for example, every URL request could be mapped into a database query.

Designating a plug-in, CGI or ACGI application to postprocess URLs allows you to perform an Action after the URL has been processed. For example, you could use a postprocessor application to implement a different form of transaction logging that keeps a summary instead of an exact log of each transaction. Or, a postprocessor could be used to support a billing scheme in the event that you want to charge for individual page accesses.

##### PreProcess
 Use the Preprocess text field in the Miscellaneous Settings dialog box to type the name of an external application to be executed before any URL is processed by the server.

Only one preprocessor application can be called by WebSTAR, although daisy-chaining is allowed. WebSTAR launches that application and sends every URL and associated WWW request for information from the WWW client to the preprocessor application before processing the client's request for data.

If the preprocessor returns any data at all to WebSTAR, WebSTAR assumes that the preprocessor has completely handled any processing necessary to deal with the requested URL. So, it skips any further URL processing and returns the data it received from the preprocessor to the client.

##### PostProcess

Use the Postprocess text field in the Miscellaneous Settings dialog box to type the name of a CGI, ACGI or plug-in to be executed after the URL is fulfilled.

As in preprocessing, only one postprocessor application can be called by WebSTAR. After WebSTAR has retrieved the file requested by a URL, it sends the file to the postprocessor application.

The postprocessor application is run after the TCP/IP connection to the client has been closed and it should not return any data to WebSTAR.

#### Default MIME Type

Configuring the default server responseWebSTAR can serve any kind of data. It is not limited to HTML documents, although it is configured "out of the box" to use text/html as the default MIME type. That means that if a URL does not match any of the defined Suffix Mappings, the server uses this default:

Kind of file | Action | Suffix | Type | Creator | MIME Type
------------ | ------ | ------ | ---- | ------- | ---------
Any file with no Suffix Mapping | BINARY | * | * | * | text/html

You can change the default MIME type by typing another valid MIME type in this field. For example, if you change the Default MIME field to text/pdf, you now have a server configured to server PDF files by default.

#### Server Name

The Server Name field specifies the name of the server returned in redirect messages (and other server responses). With this field filled in you don't have to rely on the DNS name only.

### Log Format

The Log Format command in the Configure menu lets you specify what kind of information to include in log file entries. You can choose between the WebSTAR Log Format, the Common Log Format or Extended Log Format.

The Log file is in the same folder as the WebSTAR folder and uses the name you specify in the Miscellaneous Settings dialog box. See "Log File" on page 63 for details.

Typically, WebSTAR logs messages about each transaction it performs. Each message may include the details shown in the Log Format dialog box.

![Log Format](/mac/webstar/admin_log_format_wlf.gif)

Entries in the log file are separated by tabs, and individual entries are terminated with a carriage return. This format is the standard text-only import format used by most spreadsheet applications, such as Excel, and by Macintosh database applications like FileMaker.

> To suspend logging, choose Suspend Logging in the Options menu.

You use the log format token list to set the format of messages written to the screen and the log file. First choose one of the log formats from the pop-up menu. Then, select a token in the Log Format list and click Copy to add that token to the log file (the Common Log Format uses standard tokens and are not user-selectable). The ordering of items reported can be adjusted by using the up and down arrow buttons.

> If you change from one format to another, make sure you quit WebSTAR, and clear the current log file. This is particularly important if you are using a log analysis application.

#### WebSTAR Log Format

The tokens for the WebSTAR Log Format and their interpretations are as follows:

* DATE: The current date
* TIME: The current time
* RESULT: The results of the request, which may be OK, ERR!, or PRIV.
* HOSTNAME: The name of the WWW client's computer
* URL: The requested URL path
* BYTES_SENT: The number of bytes transmitted
* AGENT: The identity of the WWW client software such as Mosaic or Netscape
* BYTES: The number of bytes transmitted (reports in Extended Log Format style)
* CONNECTION_ID: A number that is unique for each connection for this invocation of the server.
* CS-HOST: The name of the WWW clientís computer (if DNS look-ups are enabled; reports blank, "-" if DNS look-ups are disabled)
* CS-IP: The name of the WWW clientís computer (if DNS look-ups are disabled; reports blank, "-", if DNS look-ups are enabled)
* CS-METHOD: The HTTP method, usually GET or POST (reports in Extended Log Format style)
* CS-STATUS: Numeric status code returned to the client in the HTTP response header (e.g.,200, 304, etc.)
* CS-URI: The requested URL path (reports in Extended Log Format style)
* FROM: The contents of the From field in the request, usually an E-mail address if present
* METHOD: The HTTP method, usually GET or POST
* PATH_ARGS: The path arguments to the URL (text after a dollar sign)
* REFERER: The name of the document referencing this URL
* SEARCH_ARGS: The search arguments to the URL (text after a question mark)
* TRANSFER_TIME: The number of ticks required to complete the transmission
* TIME_TAKEN: The time taken to complete the transmission, reported in HH:MM:SS format
* USER: The name of remote user if authentication was required

> Not all WWW clients provide all of the information represented by all of these tokens.

#### Common Log Format (CLF)

The Common Log Format uses standard tokens that are not user-selectable. CLF is a standard used by most web servers that provides basic logging of the information necessary to do statistical analysis of server usage. Many analysis tools support this format.

#### Extended Log Format (ExLF)

ExLF is an extension of the CLF format and is configurable like the WebSTAR Log Format. The tokens for the Extended Log Format and their interpretations are as follows:

* BYTES: The number of bytes transmitted
* CS-HOST: The name of the WWW clientís computer (if DNS look-ups are enabled; reports blank, "-" if DNS look-ups are disabled)
* CS-IP: The name of the WWW clientís computer (if DNS look-ups are disabled; reports blank, "-", if DNS look-ups are enabled)
* CS-METHOD: The HTTP method, usually GET or POST
* CS-STATUS: Numeric status code returned to the client in the HTTP response header (e.g.,200, 304, etc.)
* CS-URI: The requested URL path
* DATE: The current date
* TIME: The current time
* TIME_TAKEN: The time taken to complete the transmission

#### WebSTAR.Messages File 

WebSTAR now logs all serious start-up problems it encounters to a new file, "WebSTAR.Messages." Any line in this file that begins with the string "ERR:" contains a message describing a problem that caused WebSTAR to terminate. This file is especially useful with background-only versions of WebSTAR, where post mortem information on why the server isnít launching is required and may be useful when contacting Technical Support.

### Add Password

In the WebSTAR Admin application, you can restrict incoming connections based on the IP address or domain name of the remote client, or you can assign user name/password authentication to specific files and folders. To restrict incoming connections based on the IP address or domain name of the remote client, see "Allow and Deny" on page 54. For security reasons, adding a password is the only function allowed here using WebSTAR Admin. Deleting or changing security information in any other way must be performed at the serverís console and not remotely.

To assign user name/password authentication, you need to set up your folder hierarchy with security Realms in mind (see "Realms" on page 52). Then, you can assign the user name/password authentication required to access data within a Realm. The user name/password authentication in WebSTAR is the same as the basic authentication scheme built into most WWW clients (with the exception of older versions of some browsers like MacWeb and Mosaic). For WWW clients that have built-in authentication, users only have to enter the appropriate user name and password once. The client remembers the user name and password and sends it automatically for future requests. 

> Authentication is optional. You can choose not to activate any password-based security on your server.

To add user names and passwords, choose Passwords in the Configure menu. The Add Passwords dialog box appears:

![Admin Passwords](/mac/webstar/admin_passwords_1.gif)

To assign a user name and password to a Realm, follow these steps:

1. Define at least one security Realm. See "Realms" on page 52.
1. Choose Passwords in the Configure menu to open the Add Passwords dialog box.
1. Select the Realm in the Realm pop-up.
1. Type a user name and a password in the appropriate fields.
1. The password is limited to 64 characters. When you choose a password, make sure that it does not contain Macintosh-specific characters that cannot be typed from a PC-compatible Web client.
1. Click Add. The new user name will appear in the scrolling list, along with the Realm to which it is assigned. A user name may be entered in multiple Realms, but each user name/Realm combination must be unique in this window.

User names are available immediately as soon as you add them; there is no need to stop or start the server. In addition, WebSTAR can continue to serve files while you are adding user name and password information.

### Plug-In Info

The Plug-In Info window in the Configure menu provides basic information about which plug-ins are loaded on this particular server.

![Plugin info](/mac/webstar/Plug-in_Info.gif)

### Using the WebSTAR Admin Web Interface

Similar to the WebSTAR Admin application in almost every feature and function, the WebSTAR Admin web interface has one feature that truly sets it apart from the application: you can use it anywhere, anytime and not necessarily on a Macintosh computer. It is, after all, a web browser interface for monitoring, configuring and otherwise managing your WebSTAR server from anywhere on the Internet.

#### To use the WebSTAR Admin Web Interface:

1. Launch the web browser of your choice, Microsoft Internet Explorer, Netscape Navigator or Mosaic.
1. Connect to the URL: http://your.server.com/pi_admin.admin

Your browser displays a screen similar to the one shown in Figure 19.

![Web Admin Main](/mac/webstar/Web_Admin_UI_Main.gif)

Use the buttons on the left and at the bottom of the screen to navigate to the task you wish to accomplish.

![Web Admin Monitor](/mac/webstar/Web_Admin_Monitor.gif)

#### Monitor

When you click the Monitor button, your web browser displays a screen similar to that shown in Figure 20. This Monitor screen updates every 15 seconds and shows status information similar to that in the status portion of the WebSTAR Admin application window. 

![Web Admin Settings](/mac/webstar/Web_Admin_Settings.gif)

#### Settings

When you click the Settings button, your web browser displays a screen similar to that shown in Figure 21. From Settings you can access links to screens which let you add, edit, replace or delete many of the same items found on the Configure menu in the WebSTAR Admin application (see "WebSTAR Admin Configure Menu" on page 41).

![Web Admin Controls](/mac/webstar/Web_Admin_Controls.gif)

#### Controls

When you click the Controls button, your web browser displays a screen similar to that shown in Figure 22. With Controls, you can control server operation much like you would using the Options menu in the WebSTAR Admin application (see "WebSTAR Admin Options Menu" on page 40). 

![Web Admin Plugins](/mac/webstar/Web_Admin_Plug-ins.gif)

#### Plug-Ins

When you click the Plug-Ins button, your web browser displays a screen similar to that shown in Figure 23. The Plug-Ins screen displays a list of all installed plug-ins and provides links to their configuration pages.
