---
layout: page
title: Chapter 4. Administering WebSTAR
---

This chapter provides some background on how WebSTAR works and discusses some general administration issues.

### Notes About HTTP Connections

The HyperText Transfer Protocol (HTTP) defines how a Web server handles connections. Unlike the File Transfer Protocol (FTP), in which a client opens a connection with a server, opens another connection to transfer data, and holds both connections open for the whole length of the session, HTTP opens a connection only for as long as needed to transfer the requested data. The connection is then closed immediately.

This method of handling connections has a few implications for the administrator of a Web server. First, there is no way for WebSTAR to keep track of where a connection leads. So, if a user requests data from your server, there is no way for the WebSTAR server itself to track which links are followed within that data, because the connection is closed once the original data is returned.

In the context of HTTP connections, you should also be aware that each separate element in a page requires its own connection. For example, a page of text requires one connection to download. If that page contains a graphic, another connection is required. So, connection information is not necessarily a reliable way of analyzing a server's activity. For example, if you have a server with 5,000 connections a day serving a text document and you add a graphic to that document, you suddenly have a server with 10,000 connections a day.

### Client and Server Aspects of URL Handling

WWW client software is responsible for constructing the full URL for a document, which contains the server's hostname and possibly a path to the folder containing the WebSTAR server. For example, this is a full URL to an HTML document:

```
http://www.abc.com/sampledoc.html
```

The portion of this URL handled by WebSTAR is:

```
/sampledoc.html
```

WebSTAR handles only URLs relative to its own position on the disk. In effect, the "root" of the WebSTAR file system starts with the folder in which it resides.

> The computer on which WebSTAR is running has an IP address, which is assigned in MacTCP or TCP/IP. Its hostname is assigned in the DNS server for your site. A machine can have more than one name. The WWW client software handles the DNS lookup to find the IP address that corresponds to the hostname in the URL.

When the WebSTAR server receives an incoming URL, it performs the steps described below.

1. First, it converts the slashes in the URL to colons to obtain a Macintosh file path.
1. The server then converts HTTP special characters (using %xx, where xx is the two-digit hex number of the special character).
1. It replaces double-colons (::) with a single colon (:) to prevent clients from accessing parent directories in the Mac OS file system.
1. It extracts the suffix of the requested file and uses it to determine the Actions to perform. If there is no suffix (or no suffix mapping specifying an Action), it examines the Macintosh file Type and Creator of the requested file and uses those fields to determine which Actions to perform.
1. It determines if the requested filename (as modified by the preceding steps) is an alias and if so, translates it to the real path for the file.
1. The server opens the file and performs the specified Action, or if no Action is specified, uses the appropriate file transfer method and default MIME type to return the data to the requesting client.

> Files served by WebSTAR cannot contain the $ character in their name.

For more information on URLs, see the URL Primer described in "Additional Information Resources" on page 16.

#### Client and Server Aspects of External Process Execution

If the suffix of an incoming URL requires execution of a plug-in, a CGI application, or an ACGI application, the WebSTAR server simply packages up the incoming request and passes it to the specified application or plug-in directly. It doesn't verify or translate the result before returning it to the client. In addition, the application or plug-in is expected to generate a complete HTTP header.

For example, if a user sends a form, the WWW client software is responsible for filling in the form before it is sent to WebSTAR. WebSTAR then packages this information and passes it to a CGI application or plug-in for processing.

When WebSTAR receives such information from a client, it passes the information to the application as parameters and returns the result to the client without modification. If the client receives erroneous data, both the client software and the CGI or plug-in itself are possible causes. It is also possible that an erroneous suffix mapping configuration could cause the server to use an inappropriate MIME type or transfer method.

If you run into problems with defaults or specific suffix mapping parameters, you can instruct users to configure their WWW clients appropriately. For example, for Microsoft Internet Explorer to "understand" Excel files, a user may need to map the .XL suffix to a specific MIME type (such as application/excel) and then map the MIME type to a Helper application that can be launched to view the document. Then, when the user sends a URL like this:

```
http://www.abc.com/bigbucks.xl
```

WebSTAR will send the file and appropriate header information containing the MIME type to the WWW client, and the client will know what is being returned and which Helper application to launch.

#### Client and Server Aspects of File Transfers

WebSTAR uses text/html as the default MIME type, unless you have configured a different default. So, if a client sends a URL requesting data and no suffix mapping or file Type mappings are found, WebSTAR assumes that the request is for an HTML document and sends it using the appropriate MIME type.

However, sometimes older WWW clients don't use the MIME type information returned by WebSTAR. In that case, in the absence of obvious information about the data it is receiving, the client resorts to using its own built-in default, for example, MacBinary. This kind of cross-purpose use of defaults can cause a client to be unable to interpret a document.

### RAW Files

RAW file types are recognized by the server before any suffix mapping is verified. If WebSTAR receives a URL request and finds a Type and Creator indicating a RAW file, it simply returns the file's contents as is. You can create RAW files that contain any kind of data.

For example, suppose you move an entire branch of your document tree to another computer. You can redirect incoming requests simply by creating a RAW file that contains a URL redirect header and new location. Replace the index file in that subdirectory with the RAW file, and client requests will retrieve the raw file, which redirects them to the new host. For more information about RAW files, see "RAW Files" on page 108.

### Folder and Filenames

Avoid spaces and special characters in any folder or filenames that WebSTAR will be serving. You must encode the special characters in filenames using the URL standard %xx encodings for each special character, where xx is the hexadecimal code for the ASCII character. For example, a space character (decimal 32, hexadecimal 20) would be encoded as %20). So, "file name" would be entered as "file%20name".

If you are using security Realms to protect certain information, you must name folders and files appropriately to assign the proper access control. For example, if a private Realm is configured with the match string private, the URLs for all folders or files within that Realm must contain that match string. See "Realms" on page 52 for details.

### Folder and File Aliases

You can use aliases to folders and files that reside outside the WebSTAR folder, including those that reside on different volumes or different machines on the network. As long as the alias resides within the WebSTAR folder, URLs will work correctly.You can also use aliases to supply required filename suffixes without renaming the original files. WebSTAR uses the name of the alias for suffix mapping, and then translates the alias to find the original file's contents.

> Although you can use aliases to original files and folders that aren't contained within the WebSTAR folder hierarchy, any URLs contained in the aliased files must still provide paths that are relative to the WebSTAR hierarchy. This is done for security purposes and isn't subject to change.

### Warnings About Plug-In and CGI Execution

WebSTAR provides access to files within its own folder hierarchy. This is an important security feature. However, if you allow the WebSTAR server to execute plug-ins or CGIs, the burden falls on the programmer to make sure that only files and folders within that folder hierarchy can be accessed.

### Warnings About Macintosh Documents

Macintosh documents, which have both a resource fork and a data fork, must be transferred as binary data and must contain all of their data in the data fork of the file. For example, you need to define suffix mappings for Excel or Word documents that ensure that those documents will be sent as binary data. See "Suffix Mapping" on page 41. The documents will not be viewable by users on machines that don't possess applications capable of reading Macintosh files.

### Creating a No Access Message

A No Access file is returned when the client has been refused access to the site because of the Allow/Deny settings. The administrator has to create the No Access messages, which should state that access was denied and perhaps explain why. For example,

```
<HTML>
<HEAD>
<TITLE>Access Denied</TITLE>
</HEAD>
<BODY>

Sorry, this site is restricted!


<P><EM>Last Edited: November 15, 1996</EM><BR> 
</BODY>
</HTML>

The No Access file can be an HTML file or even a CGI application that gives different responses based on the address of the client. For example, you might return a message to all .COM addresses such as:

<HTML>
<HEAD>
<TITLE>Access Denied</TITLE>
</HEAD>
<BODY>

Sorry, this site is restricted to educational traffic!

<P><EM>Last Edited: November 15, 1996</M ><BR> 
</BODY>
</HTML>
```

See "No Access" on page 63.

### Running Multiple WebSTAR Servers

If you want to have a WWW service that has some public and some private pages and you don't want to use security Realms, you can run multiple WebSTAR servers on a single computer. One server can be set up with no access restrictions, while another restricts access to specified hosts.

All port numbers lower than 1024 are reserved for well-known services. WebSTAR is assigned port number 80 by default. If you are running multiple servers, you need to assign a different port number for the additional servers. Although you can use any unreserved, available port numbers, the convention is to use ports in the 8000 range (such as 8001) for additional WebSTAR servers.

See "Port" on page 59 for details on specifying an alternate port number for a selected WebSTAR server. When multiple servers are set up, URLs to the alternate servers (those not using port 80) must specify the right port number. For example:

```
http://www.abc.com:8001/privatedoc.html
```

> If you want to run multiple servers on different computers, you need a unique serial number for each WebSTAR server on the network. See "About WebSTAR" on the WebSTAR distribution media for guidelines in setting up multiple servers on a network to distribute the processing load.
