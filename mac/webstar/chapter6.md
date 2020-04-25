---
layout: page
title: Chapter 6. Plug-Ins and CGIs
---

This chapter describes how the WebSTAR server exchanges information with plug-ins and CGI applications. The information here can help you understand how the server works with plug-ins and CGIs, but it doesn't provide complete instructions for developing a plug-in or CGI application that works with WebSTAR.

### About CGIs

A CGI is any application that uses the Common Gateway Interface (CGI) standard to interact with an information server such as WebSTAR. The CGI standard defines arguments that allow the server to pass data to applications and receive data back from them.

You can develop a CGI to integrate with databases, process forms, and perform all sorts of other useful functions. CGIs can be developed and programmed in high-level scripting languages such as AppleScript or MacPerl, or in low-level languages like C, Pascal or Java. Developing an application in a low-level language requires more effort but results in much better performance than an application developed in a scripting language.

The WebSTAR server itself does not process the data it sends to the CGI application or the pages it returns to the client software or the data returned from plug-ins or CGIs that is sent to clients. The server's job is to handle connections, use the proper method to return pages and files, and handle communications between the client and CGI.

#### Asynchronous Processing

The WebSTAR server can interact with a CGI synchronously or asynchronously. If the name of the file uses the extension ".cgi", the server passes an Apple event to the application and waits for the CGI to return a result (synchronous operation). If the filename ends in ".acgi", the server passes an Apple event to the application and then continues processing other tasks until it receives a reply. Writing a CGI to be processed asynchronously is usually preferable.

#### RAW Files

RAW file types are files of type "RAW!" and creator "WWW" (the last character is omega, produced by typing option-Z) or any file with the Action RAW defined in Suffix Mapping. RAW files can be used in place of any file that needs to be moved, redirected, and so forth. When the server recognizes a RAW file, it opens the file and returns its contents directly to a client, without interpreting the data or generating headers for the file. For this reason, RAW files should contain a complete HTTP header in addition to the content.

RAW files can also be used (with help from a C program to build it) to deliver multi-part animation files that can be returned from a single file without the need for a CGI. In fact, RAW files can be used to replace a CGI if you need to take it off-line for some reason.

#### Server Push

WebSTAR 1.2 and later supports server-push, a feature that was originally introduced by the Netscape servers. Server-push allows the server to keep an HTTP connection open longer than it normally should be. This has three uses:

* to return extremely large amounts of data that couldn't otherwise be done in a single block
* to return data in pieces for a process that takes a long time (such as searching multiple databases)
* to return data at fixed intervals

WebSTAR 1.2 introduced a new Apple event parameter, the connection_ id (Kcid), which gives a unique indentifier to every connection that WebSTAR is handling. This ID is used to keep track of which connection is having data returned, since it is now possible for a connection to have data sent back more than once.

The general process for a CGI application that is going to use server-push is the same no matter what language you plan to use. First, the CGI application sends a reply to WebSTAR that contains the string <SEND_PARTIAL>. There must not be any extra characters, and the text is case sensitive. This tells WebSTAR to hold the connection open because the CGI application plans to return data in several pieces. Next, the CGI application starts sending data to WebSTAR, using a new Send Partial event. The event to use is WWWSPar and has two associated variables, the connection_id (Kcid), which is a long integer, and more (Kmor), which is a Boolean that tells whether more data is expected in the future (whether to continue holding the connection open). When the last piece of data has been returned, the CGI application returns an event with more set to false, and WebSTAR closes the connection after returning the final data.

WebSTAR offers a shortcut in responding with partial data. If WebSTAR receives a Send Partial event for a connection, it makes the assumption that the CGI application is going to use server-push. This means that it isn't strictly necessary to reply to the original WWWsdoc event unless the language you are using requires it (as AppleScript does).

If a CGI application is going to do server-push, it must run asynchronously because it will be sending events back to WebSTAR. If the CGI is run synchronously, WebSTAR halts, waiting for return data. When the CGI application tries to send an event back, WebSTAR won't be able to receive it, and both of them are locked up until the connection times out.

Since the CGI application must be asynchronous and since server-push takes much longer than normal CGI processing, it is extremely important that any CGI application doing server-push also be able to process requests in multiple threads. This is a little trickier than writing a normal threaded CGI application, because there is more information to track about each connection. It is also important that the load on a server running a server-push CGI application be reevaluated. Since server-push CGI applications hold the connection open much longer than usual, the server has more connections open at any one time, and the 50-connection limit in MacTCP could become a problem. This shouldn't be a problem using Open Transport, however.

#### AppleScript CGI Issues

If you use AppleScript to develop a CGI, save the CGI as an Application in the Script Editor and make sure you use the Keep Open and Never Show Startup Screen options.

> You must perform all HTML formatting inside the AppleScript file. WebSTAR expects your script or application to generate and return a proper HTTP/1.0 header and does no conversion on the return values from CGI and ACGI type files.

### WebSTAR Apple Events

WebSTAR includes Apple events and application properties to set all configuration parameters. For the most part, the syntax of the data sent by the AppleScript Set commands, or returned by the AppleScript Get commands is the same as the syntax for setting parameters in previous releases. Many of the application properties can be found in the Apple event dictionary for WebSTAR, viewable in the Script Editor.The event suite for WebSTAR Apple events is the same as the four-character creator code for the WebSTAR application. This is three uppercase Ws (WWW), followed by the omega character (option-Z on the keyboard). The event codes for each event are listed after each event description.

#### AppleEvent Suite

WebSTAR supports the four required Apple events, plus a custom Apple event suite for sending information to WebSTAR while it is running. The four required events don't do much, because WebSTAR doesn't open or print any documents of its own. However, the custom event suite is very useful for operating WebSTAR under script control or from a remote Macintosh. These are the events in the custom Apple event suite:

```
WebSTAR Suite: Events for communicating with the WebSTAR family of servers

DoMenu: Execute the specified menu item from the server menus. Obsolete.
DoMenu 'char'-"<menu id>, <menu item>", ex. DoMenu 4,1

Verbose Messages: Toggle Verbose Messages on or off
Verbose Messages boolean-True or False

Hide Window: Toggle hiding status window in the background
Hide Window boolean-True or False

Status Report: Return status information about the server
Status Report
Result: 'char'-returns text info about WebSTAR

Refuse Connections: Toggle incoming connections on or off
Refuse Connections boolean-True or False

Suspend Logging: Turn logging on or off
Suspend Logging boolean-True or False

add user: Add a user and password for a specific security realm 
add user 'char'-username
password 'char'-password
realm 'char'-security realm

delete user: Delete specified user from a particular security realm
delete user 'char'-username
realm 'char'-security realm

validate user: Validate that a given password is correct for a user in a specific realm
validate user 'char'-user name
password 'char'-password
realm 'char'-realm
Result: boolean-True: User is valid, False: user or password is invalid

request reporting: Request real-time status reports be sent to caller
request reporting
messages boolean-receive log messages?
status boolean-receive status info? (usage levels, etc.) 
id integer-unique ID for requestor
client_version 'char'-version of admin client ("#.#")
Result: 'char'-status of request & name and port of remote WebSTAR server

send partial: Sends partial ACGI execution results to WebSTAR for transmission to clients
send partial 'char'-data to return to the WWW client
connection integer-connection ID to return data to.
more boolean-is there more data to send?

reset stats: resets all server counters to zero
reset stats

flush cache: forces the server and appropriate plug-ins to flush cached file data
flush cache

Get_AllowDenyInfo: get allow/deny info for a specific realm
Get_AllowDenyInfo 'char'-realm name
Result: 'char'-text block containing allow/deny info for specified realm

Set_AllowDenyInfo: set allow/deny info for the specified realm
Set_AllowDenyInfo 'char'-allow/deny info
for realm 'char'-realm name

import users: import records into the user/password database
import users file specification-file spec

export users: export user database records to disk
export users file specification-file spec

Class application: WebSTAR application properties for use with Get and Set

Properties:

dump_buf_size small integer-Output buffer size for TCP/IP writes to clients. (256-10240)
pig_delay small integer-Number of ticks to run the server before relinquishing control to other apps (0-120)
maxusers small integer-Maximum number of simultaneous users. (4-50)
no_dns boolean-Toggle for domain name resolution by the server (true=off/false=on)
time_out small integer-Timeout value for idle client connections and AppleEvents in seconds (5-600)
maxlistens small integer-Maximum number of TCP/IP listens to queue up (4-50)
logging boolean-Enable/Disable logging
verbose_messages boolean-Toggle Verbose Messages on/off
refuse_connections boolean-Refuse/Allow incoming connections
default_mime_type 'char'-Default MIME type for untyped files
port small integer-TCP/IP port for server to listen on
index_file 'char'-Name of the default "index" file
error_file 'char'-Name of the error message file
log_file 'char'-Name of server log file
log_format 'char'-string of keywords for info to log
no_access_file 'char'-Name of "no access" file
pre_processor 'char'-pre-processor application name
post_processor 'char'-post-processor application name
suffix_mappings 'char'-Suffix and MIME Type mappings in text block format
access_controls 'char'-Allow/Deny access controls via IP address and domain name. Text block format
realms 'char'-Security realm entries in text block format.
actions 'char'-User-defined actions in text block format
version 'char' [r/o]-WebSTAR version number
report_delay small integer-delay between status report events (1-60 seconds)
file_info_cache_size integer-amount of memory to allocate for file info caching (0-maxmem)
keep_alive_connections small integer-number of connections per client to keep alive (0-10)
keep_alive_time small integer-seconds to keep alive idle client connections (0-60)
plugin_admin_info 'char' [r/o]-information for configuring installed plug-ins (tab separated tokens, <name> <version> <admin_URL><cr>)
server_name 'char'-name of server to return in HTTP responses instead of DNS name
cgi_bin_only boolean-flag that indicates if only CGIs inside the cgi-bin directory will be executed
```

#### CGI Parameters

If you are a C or Pascal programmer, the information in this section will make sense. If you are creating compiled AppleScript applications, see: http://www.starnine.com/development/tutorials.html

If WebSTAR receives a query (GET) from a WWW client requesting a file whose suffix mapping is CGI or ACGI, WebSTAR attempts to launch the application and communicate with it via custom Apple events. WebSTAR implements the Common Gateway Interface standard in the sdoc Apple event. The four-character Event Suite is WWW*-three uppercase Ws (WWW), followed by the omega character (option-Z on the keyboard). The four-character event code is sdoc. For example:

```
on &laqno;event WWW*sdoc»
```

The Apple event keyword codes for the parameters passed by WebSTAR to CGI and ACGI applications are listed below. You can name the variables associated with these parameters whatever you like. 

Parameter | Keyword | Data size | Description
--------- | ------- | --------- | -----------
Path Args | ---- | 1024	| Contains arguments following the dollar-sign ($) in a URL. For example, for this URL: <form action="ProcessForm.cgi$JimmyJones?14" method=post> the value "JimmyJones" is contained in this parameter. This keyword is also the direct parameter of the Apple event (keyDirectObject).
Search Args | kfor | 1024 | Contains arguments following a question mark (?) in a URL. For example, for this URL: <form action="ProcessForm.cgi$JimmyJones?14" method=post> the value "14" is contained in this parameter.
Username | user | 32 | Passes the username if authentication was required.
Password | pass | 32 | Passes the password if authentication was required.
From User | frmu | 128 | Passes the E-mail address of user (obsolete). Some older clients allow users to set a default E-mail address in the preferences and will include this address as information to WebSTAR. If found, WebSTAR puts the address information in this parameter.
Client Address | addr | 256 | Passes the domain name of the client (or the IP address if DNS look-ups are disabled).
Server Address | svnm | 256 | Passes the domain name of the server (or the server's IP address if DNS look-ups are disabled).
Server IP port | svpt | 16 | Passes the TCP/IP port the server is listening on.
Script name | scnm | 1024 | Passes the path of the CGI being executed. If the CGI is called as an ACTION, this parameter contains the file portion of the URL.
Content Type | ctyp | 64 | Passes the MIME type of Post arguments if present.
Referer | refr | 1024 | Passes the URL of the page from which this CGI was referenced. This information is useful fo telling what sites are referencing your pages. It can also be useful in a script to add a "return" link to pages on-the-fly that would return users to whatever page they came from.
User Agent | Agnt | 256 | Passes the WWW client software name and version.
Action | Kact | 1024 | Passes the action being performed by the CGI. It will contain either the name of the user-defined action or one of these strings: CGI, ACGI, PREPROCESSOR, POSTPROCESSOR, ERROR, INDEX, or NOACCESS.
Action Path | Kapt | 1024 | Passes the path to this CGI if it is executing as an action (in which case, the script name parameter contains the URL file path sent from the client).
Post Arguments | post | 32,768 | Passes arguments sent from the WWW client as part of a POST request (such as form arguments). The actual form data (returned from running the CGI) is also placed in this parameter.
Method | meth | 32 | Passes the HTTP method being requested (such as GET, CONDITIONAL_GET, POST, etc.). If the HTTP method is POST, the form data sent in the oject body of theHTTP request is returned to the server in the post_args parameter. Otherwise, this parametr is empty. If the HTTP method is GET, the form data overwrites the http_search_args parameter. If you are using a map-processing CGI, you might use the method=get argument to pass the name of the map information file that the CGI should use to process the map. The URL might look like this: /cgi/MapServe.acgi$jonsmap.map When a user clicks on the map, the client software changes this URL so that the map coordinates are added in the search arguments. The full URL transmitted to WebSTAR would look something like this: /cgi/MapServe.acgi$jonsmap.map?223,1
Client IP Address | Kcip | 32 | Passes the IP address of the client as a string, even if NO-DNS is false.
Full Request | Kfrq | 4096 | Passes the complete, unmodified HTTP request as received from the WWW client.
Connection ID | Kcid | 4 | Passes a unique long integer identifying the TCP/IP connection over which the server is communicating to the client. This number is used for sending the "Send Partial" AppleEvent to WebSTAR.

#### Example Uses of CGI Parameters

The direct parameter (----) contains the path arguments as passed from the WWW client to WebSTAR. Path arguments are the portion of a URL following a dollar sign and preceding a question mark. For example, the URL

```
http://www.abc.com/map_handler.cgi$world_map.gif?123,232
```

is interpreted as follows:

* www.abc.com is passed in svnm.
* The default port number 80 is passed in svpt.
* */map_handler.cgi is passed in the scnm parameter.
* world_map.gif is passed in the path arguments (direct) parameter.
* 123,232 is passed in the search arguments (kfor) parameter.

The HTTP method, usually GET or POST, is passed in the post parameter.

If the HTTP method is POST, the post data sent in the object body of the HTTP request is passed in the post parameter. Otherwise, this parameter is empty.

* The ctyp (content type) parameter contains the MIME type of any post argument data.

The Kact and Kapt parameters inform the application whether it is running as a CGI or an action. Both contain character strings. If the application is running as a CGI or ACGI instead of an action, Kact will contain CGI or ACGI and Kapt will contain the same path as the scnm parameter.

The Kcip parameter contains the IP address of the client as a string. It is always the IP address of the client, regardless of the No DNS setting. The Kfrq parameter contains the unmodified text of the complete request as received from the WWW client.

All other parameters are filled in from information in the HTTP/1.0 request header or from information known to the server. For more details on what each parameter means, see the Common Gateway Interface Standards document (see "Additional Information Resources" on page 16). Note that this document is a good reference for conceptual purposes onlyóthe way parameters are passed, their names, and other specifics are different on the Macintosh.

WebSTAR expects the Apple event reply's direct parameter to contain an HTTP/1.0 header and HTML text that will be transmitted to the client.

### The Send Partial Apple Event

For details about using the Send Partial event, see the excerpt about writing CGI applications from Jon Wiederspan and Chuck Shotton's book, Planning and Managing Web Sites on the Macintosh, included as a PDF file on the WebSTAR distribution media.

ACGI programmers may want to use the Send Partial event to return unlimited amounts of data. It is also used to allow time-consuming CGI operations to return results incrementally using "server push" functions available in some WWW browsers, or to send "keep alive" messages to WebSTAR to prevent the server from terminating client connections during lengthy processing.

Send the following Apple event to WebSTAR to start returning data in incremental pieces.

```
send partial: Sends partial ACGI execution results to WebSTAR for transmission to clients
send partial 'char' -- data to return to the client
connection integer -- connection ID for returning data
more boolean -- is there more data to send?
Event Class: WWWW
```

The Send Partial event (class:WWW, event:SPar) sends incremental ACGI execution results to WebSTAR for transmission to the client. The event has the parameters shown in Table 4:

Parameter | Keyword | Type/Size | Description
--------- | ------- | --------- | -----------
Direct | ---- | Char/32K | Data returned from ACGI to WebSTAR
Connection ID | Kcid | LongInteger | Identifies WebSTAR-to-client connection to use for sending incremental pieces of data
More | Kmor | Boolean | If true, specifies that more data will follow in subsequent Send Partial events. If false, WebSTAR closes the client connection.

An ACGI should use the direct parameter of the sdoc event to inform WebSTAR that it should expect additional information to arrive via the Send Partial event. The sdoc event handler should return this string:

```
<SEND_PARTIAL>
```

in the reply parameter of the original event. (The entire reply should consist of only those 14 characters.) WebSTAR will use this specific reply as an indication that it should keep the connection open with the client for the ACGI.

Once the sdoc handler has completed processing the initial event, the ACGI needs to begin the process of returning the return data to WebSTAR. The connection ID parameter (keyword Kcid) is used in the Send Partial event to tell WebSTAR which connection the ACGI wants data returned on.

WebSTAR sends the data in the direct parameter to the client. If the More flag is set to true, WebSTAR holds the connection open, awaiting more Send Partial information. If the flag is false, WebSTAR terminates the client connection.

WebSTAR returns a "noErr" (0) reply to the caller if the Send Partial event was handled properly. If the client has dropped the connection, or WebSTAR is unable to send the data, WebSTAR returns a non-zero result, the "errAEEventNotHandled" error code.

> Under no circumstances should you issue a second Send Partial event for the same connection before a preceding event sent to the same connection has completed and returned a result to your ACGI.

For more details on sending the Send Partial event to WebSTAR from an ACGI, see the excerpt about writing CGI applications from Jon Wiederspan and Chuck Shotton's book, Planning and Managing Web Sites on the Macintosh, included as a PDF file on the WebSTAR distribution media.

### Sending and Receiving Reporting Information

WebSTAR can communicate logging and status information to remote applications by using Apple events. Remote applications must "register" with WebSTAR to receive status reports and log messages when necessary.

#### Requesting Reporting Information from WebSTAR

Send the Request Reporting event to WebSTAR to begin receiving status reports or log messages:

```
request reporting: Request real-time status reports be sent to caller
request reporting
messages boolean -- receive log messages?
status boolean -- receive status info? (usage levels, etc.)
id integer -- unique ID for requestor
version string -- which version of report and log formatting is used (normally 1)
Event Class: WWWW
```

The Request Reporting event (class:WWW, event:RqRp) requests status and log information from the WebSTAR application. The event has the parameters shown in Table 5:

Parameter | Keyword | Type/Size | Description
--------- | ------- | --------- | -----------
messages | Kmsg | Boolean | Are log messages supposed to be sent by WebSTAR?
status | Ksta | Boolean | Are status reports supposed to be sent by WebSTAR?
id | Kpid | Long Integer | Unique value identifying your CGI to WebSTAR
version | Kver | Char/256 | Version of reporting protocol to use (normally "1").

To stop receiving reports and messages, send the Request Reporting event again with both boolean parameters set to false.

##### Messages

If either of the boolean parameters is true, WebSTAR begins sending the appropriate messages and reports to the CGI by using the Receive Report Apple event. Each time WebSTAR has information for your application, you will receive a new message from WebSTAR. See "Receive Report Event" on page 121 for details.If the Kmsg parameter is true, WebSTAR sends a message each time a URL request is satisfied. These log messages as well as error and informational messages are sent in the same format defined for the WebSTAR log file. You can use the Receive Report Apple event to distinguish between message types.

##### Status

If the Ksta parameter of the Request Reporting Apple event is true, WebSTAR sends a message every 15 seconds with contents identical to the result returned from WebSTAR Status Report event. Also, any time the internal message buffer in WebSTAR exceeds 8K or if an urgent message is sent, all status data is sent to all subscribing applications in the Kmsg parameter. Log entries are considered urgent messages. Verbose Message output is not.

##### ID

Each time you send the Request Reporting event, you should use the same value for the ID parameter. When WebSTAR returns messages and reports it includes this ID value, enabling you to use one CGI to talk to multiple servers or to make multiple requests to a single server, provided that you use unique IDs for each request.

#### Receive Report Event
Your ACGI must be prepared to receive the Receive Report event at any time after sending a Request Reporting event to WebSTAR. This event uses most of the same semantics as the Request Reporting Apple event, described immediately above.

```
Receive Report
Event Class: WWWW
```

The Receive Report event (class:WWW, event:Rrep) returns the requested reports from WebSTAR. The event has the parameters shown in Table 6:

Parameter | Keyword | Type/Size | Description
--------- | ------- | --------- | -----------
messages | Kmsg | Char/8192 | Log, error, or informational messages
status | Ksta | Char/8192 | WebSTAR status reports
id | Kpid | Long Integer | Unique value identifying your CGI to WebSTAR

The fields and names are guaranteed to always be in the same order and have the same name. Any new status parameters are added onto the end of the string. So, you can parse by field position rather than by field name.

##### Messages

The first Rrep message you receive from WebSTAR after sending the Request Report event is the format of the log file. This message, and all others that are log file entries, are prefixed with the option-semicolon character. The log format message begins with the token !!LOG_FORMAT and is then followed by the names of the data fields being logged in the order they are sent.

The specific syntax of the log format message is:

```
<option-semicolon character>!!LOG_FORMAT <id> <id> <id>
```

The syntax of a log entry message is:

```
<option-semicolon character><value> <value> <etc.>
```

In general, the !! token can be considered to indicate a comment or other non-URL related information that would be written to the log file. Option semicolon introduces messages that should be considered of interest to logging applications. WebSTAR will send all information that would normally have been sent to its screen and parsing for the option semicolon character is important to distinguish log information from informational or error messages written to WebSTAR's screen. Informational messages will not begin with the option-semicolon character and can be ignored if desired.

##### Status

The format of the status string is identical to the string returned from the Status Report event you can send to WebSTAR. The fields and names are guaranteed to always be in the same order and have the same name. Any new status parameters will be added onto the end of the string. So, you can parse by field position rather than by field name. Field syntax is always:

```
<ID><SPACE><VALUE><COMMA><SPACE><ID><SPACE>......,
```

So, "space" is the first token delimiter, and "comma-space" is the second.

### The WebSTAR Application Program Interface (W*API)

The WebSTAR Application Program Interface (W*API) implements a new, high performance technique for developers to extend the functionality of Macintosh web servers.

Using the Mac OS, the W*API relies on the Code Fragment Manager present on all PowerPC computers to implement a plug-in architecture that allows user-supplied modules to be loaded at start-up and be used in the same context as ACGI, logging, and administration applications. This Code Fragment Manager dependency is not true on 680x0 Macintosh computers. In that case, simple code resources are used. Rather than rely on AppleEvents, scripting solutions, and other O/S technologies, the W*API allows code that implements the plug-in to execute directly as part of the server application.

#### Theory of Operation

Plug-ins exist as code fragments, which are loaded when WebSTAR is launched. Plug-ins are sent messages by WebSTAR via arguments passed by a subroutine call to the main entry point in the code fragment. This entry point is defined within the W*API Framework Library, which passes messages to your "dispatcher" subroutine. In response to these messages, the plug-in performs the requested service, makes calls to call-back service routines provided by the W*API as needed, and returns the appropriate response to WebSTAR. Logically, plug-ins conforming to the W*API exist as subroutines that WebSTAR calls when their services are needed. However, provisions exist for giving plug-ins idle CPU time on a regular basis, so you aren't limited to performing all of your processing in the context of a single subroutine call.

This all means that plug-ins exist as part of WebSTAR's running code, can be called from threads within WebSTAR, and have access to data and services provided to the plug-in by WebSTAR. It also means that plug-in developers have to take care to cooperate with WebSTAR and other plug-ins. Complete documentation of the W*API is included in the WebSTAR API SDK found on the WebSTAR distribution media. The SDK can also be found at: ftp://ftp.starnine.com/pub/webstar_dev/wsapi_sdk.sea.hqx

#### WebSTAR API Parameter Definitions

Table 7 contains a complete listing of W*API parameters, keywords and a short description describing the value returned. While these W*API parameters are primarily for use by W*API plug-in developers, they can also be used in connection with plug-ins like WebSTAR SSI which allow W*API parameter values to be returned from the echo command. For instance:

```
<!--#echo var="piTotalConnections"-->
```

**Table 7. W*API Parameter Definitions**

Connection-related | Keyword | Read-only values
------------------ | ------- | ----------------
piPathArgKeyword | - | Path argument portion of URL
piSearchArgKeyword | kfor | Search argument portion of URL
piUserKeyword | user | Username for current authentication scheme
piPasswordKeyword | pass | Password for current authentication scheme
piFromUser | frmu | "From" header field (e-mail address when supplied)
piAddressKeyword | addr | domain name of client
piPostKeyword | post | first 24k of HTTP object body (e.g., form data, etc.)
piMethodKeyword | meth | HTTP method (e.g., GET, POST, HEAD, etc.)
piServerName | svnm | domain name of server
piServerPort | svpt | port number server is listening on
piScriptName | scnm | name of CGI or URL path if executing as an action
piContentType | ctyp | MIME type of the HTTP object body
piContentLength | CLen | data size of the HTTP object body
piRefererKeyword | refr | "Referer" HTTP header field value
piUserAgentKeyword | Agnt | "User-Agent" HTTP header field value
piActionKeyword | Kact | name of action associated with current URL request
piActionPathKeyword | Kapt | path to the CGI processing the current URL request
piClientIPAddress | Kcip | 4 byte integer containing client's IP address
piFullRequestKeyword | Kfrq | Entire HTTP request as received from the client
piFileMIMEType | Mime | MIME type of requested URL as determined by server
piServerField | SvFd | preconstructed response header field for server name
piServerDirectoryPath | SPth | local file system path to the server's document tree
piURLPhysicalPath | UPth | local file system name for the requested file
piIfModifiedSince | IfMS | true/false if file has been modified since last client req.
piURLFileRef | Pufr | server-specific reference to file in the native OS
piCurrentRealm | CRlm | name of security realm (if any) protecting requested file
piConnectionID | LCID | unique ID for this HTTP connection
piServerUniqueID | LSID | unique ID for this execution of the server

Server Status Info | Keyword | Read-only values
------------------ | ------- | ----------------
piTotalConnections | STCn | total number of connections served since start-up
piCurrentUserLevel | SCLd | current number of users connected to the server
piHighestUserLevel | SMLd | max number of users ever connected at one time
piCurrentFreeMemory | SFMm | current amount of free memory available to the server
piMinimumFreeMemory | SMFM | minimum amount of free memory ever available to server
piTotalConTimeouts | STTm | total number of connections that have timed out
piTotalConBusies | STBz | total number of connections refused because server was busy
piTotalConDenied | STDn | total number of connections denied for access violations
piTotalBytesSent | TByt | total bytes transmitted to clients
piVersionNumber | Pvrs | name and version number of server
piUpSinceDate | SUpS | date time the server was launched; Format, MM/ DD/YY:HH:MM
piPluginAdminInfo | Padm | text block containing info on each plug-in currently installed

Plug-in Info | Keyword | Read-only values
------------ | ------- | ----------------
piPluginParamInfo | Pipi | pointer to a W*API-specific data structure describing plug-in parameter semantics
piPluginParamCount | Pipc | count of the number of W*API parameters in piPluginParamInfo
piPluginDirPath | Pdph | full path to the plug-ins folder
piPluginDirFSSpec | Pdfs | platform-specific file system reference to plug-ins folder

Logging Info | Keyword | Read-only values
------------ | ------- | ----------------
piTransferResult | LTRs | result of processing URL (OK, ERR!, PRIV)
piBytesSent | LByt | bytes sent for current request
piTransferTime | LTrT | time in ticks from connection open to close Read/Write access

Global Server Settings | Keyword | Read/Write access
---------------------- | ------- | ----------------
piDumpBufSize | Dbuf | chunk size for TCP/IP output
piPigDelay | PigD | time in ticks between WaitNextEvent calls
piMaxUsers | MaxU | maximum number of simultaneous connections allowed
piNoDNS | Ndns | toggle DNS look-ups on/off (1/0)
piTimeOut | TimO | timeout in seconds for inactive connections
piMaxListens | MaxL | same value as Max Users. Should be set to the same value
piLogging | Plog | toggle log file output on/off (1/0)
piVerboseMessages | Pvrb | toggle server debugging messages on/off (1/0)
piRefuseConnections | Pcon | toggle connection refusal on/off (1/0)
piHideWindow | Phid | toggle status window hiding on/off (1/0)
piDefaultMIMEType | Pmim | default MIME types for files with no suffix mapping
piPort | Pprt | port for server to make HTTP connections on
piIndexFile | Pixf | name of file in each directory to return as a default
piErrorFile | Perf | relative path to Mac file/CGI handling file not found
piLogFile | Plgf | relative path to server log file
piNoAccessFile | Pnaf | relative path to file/CGI handling access violations
piSuffixMappings | Psuf | text block defining suffix mapping info
piAllowDeny | Pa/d | text block defining allow/deny IP security
piAllowDenyByRealm | PADr | This is an indexed value and you must use the WSAPI_GetIndexedParameter or WSAPI_SetIndexedParameter call to manipulate it. The Index is the name of the realm to get or set allow/ deny info for.
piRealms | Prlm | text block defining realm security
piActions | Pact | text block defining user-defined actions
piLogFormat | Plfm | text block defining log file format
piPreProcessor | Ppre | relative path to CGI/plug-in handling preprocessor
piPostProcessor | Ppst | relative path to CGI/plug-in handling postprocessor
piReportDelay | Prdl | amount of time in seconds between status report events
piCacheFlush | Pcfl | setting this flag indicates the server should flush any cached data
piFileInfoCacheSize | Pfic | amount of memory to allocate to file info caching
piKeepAliveConnections | Pkac | number of connections per client to keep alive
piKeepAliveTime | Pkat | seconds to keep alive idle client connections
piServerCName | Pscn | canonical name of server to be used in HTTP responses, regardless of DNS name
piCGIBinOnly | Pcbo | flag determining if CGIs will be executed from the / cgi-bin folder only
piServiceAddress | Pisa | table of registered service addresses

### Information About Plug-Ins and CGI Applications

For more information about how to develop plug-ins and CGI applications that work with WebSTAR, see

* http://www.starnine.com/development/tutorials.html
* An excerpt about writing CGI applications from Jon Wiederspan and Chuck Shotton's book, Planning and Managing Web Sites on the Macintosh, is included as a PDF file on the WebSTAR distribution media.
