---
layout: page
title: Enabling Spotlight Web Search
---

*This article supersedes the discussion of mod_spotlight_apple in the Web Technologies Admin Guide.*

Mac OS X Server 10.4 no longer supports the Sherlock-based searching capability provided by the mod_sherlock_apple Apache module and the indexfolder command-line tool. The Spotlight-based mod_spotlight_apple Apache module replaces it. Like its predecessor, it allows web browsers to search the content of your website.

Note that the indexing function of Spotlight is disabled by default in Mac OS X Server 10.4. Thus if you want to provide Spotlght-based search capability for Web Service, you must take the following steps.

### Enable Spotlight indexing
To enable indexing for a volume, use the mdutil tool in Terminal. For example, to enable it on the root volume:

```shell
sudo mdutil -i on /
```

See the man page for mdutil(1) for further information. Note that there may be performance implications. Indexing must remain enabled for the Spotlight Web Search facility to operate.

### Import content
Next, import your web content into the Spotlight MetaData store. The /Library/WebServer/Documents folder is not normally monitored by the MetaData Import processes, so you will need to manually import it, both initially and whenever you want any changes to be reflected. It's a good practice to create a different folder or folders to hold the contents of your virtual hosts; you'll need to manually import and update those as well.

This is done with the mdimport command-line tool:

```shell
sudo mdimport -f /Library/WebServer/Documents/example-vhost/
```

The "-f" option is necessary to force the mdimport tool to process the contents of the specified folder. Note that it may take some time to import large volumes of content. See the man page for mdimport(1) for more detail.

A variety of mdimporter extensions are pre-installed for most common content formats. If you have custom document formats, they may not be supported.

### In Server Admin...
Enable the mod_spotlight_apple module in Server Admin's Web panel, and make sure Web Service is enabled. As always, it's a good idea to make sure the Web Performance Cache is enabled only if you have a specific need for it.

### Copy the template.spotlight file
Copy the template.spotlight file from /Library/WebServer/Documents into the Document Root of each virtual host for which you want the spotlight search to be available. You may customize the title, maximum allowed hits, and other aspects of the presentation by modifying the copy of this file.

### Access from clients
To access the search capability, instruct your web clients to append ".spotlight" to the URL for your virtual hosts, like this:

```
http://vhost1.example.com/.spotlight
```

This presents a simple search page that performs a content search on the contents of the DocumentRoot for the virtual host. Results are sorted with the most relevant hit first, although no relevance score is presented.
