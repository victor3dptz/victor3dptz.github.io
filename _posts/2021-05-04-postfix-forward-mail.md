---
layout: post
title: Forward every mail to an external address (Postfix)
---

Let say you have set up postfix so that your server can send mails. Now you want to be able to receive mails without creating a POP or an IMAP box?

Well… there is a very simple solution for that: you can configure postfix to forward all the incoming mails to your real e-mail address (on GMail, Outlook or any other provider).

A great benefit of this feature is that you can give different mail addresses to different people. For instance, if you hesitate to give your actual address to “SomeShop.com”, you could register with someshop@example.com. That way, you’ll instantly know if they sold your address and you’ll be able to filter the spam.

### Configure the DNS

Before configuring postfix, we need to make sure it can be reached from the outside. Therefore the first thing to do is to configure the MX record of you DNS zone, so that it points to your postfix server.

### Configure postfix

Append the following to /etc/postfix/main.cf

```
virtual_alias_domains = example.com
virtual_alias_maps = hash:/etc/postfix/virtual
```

Also, be sure to remove example.com from mydestination

Then create the file /etc/postfix/virtual and set the content to:

```
@example.com         example@gmail.com
```

This file defines a look-up table from local to external addresses. In our case, we only need a “catch-all” address.

Then, run:

```
sudo postmap /etc/postfix/virtual
sudo service postfix reload
```

### Test

Before trying to forward a mail from internet, you should first try to send a mail from the server itself:

```
sendmail anything@example.com
Hi it works !
Ctrl-D
```

And check you mail box, including the “spam” folder.

If you have any issue, you can look at the log files:

```
tail -f /var/log/mail.log
tail -f /var/log/mail.err
```

Then, if it works with sendmail, you can try sending a mail to anything@example.com from another mail box. Be careful though, if you send the mail from the same address it’s forwarded to, you may not receive the mail.

### Black list (optional)

You may now want to prevent spam on common mail addresses, like contact@example.com.

Create /etc/postfix/recipient_access with the following content

```
contact@example.com   REJECT
```

Then run

```
postmap /etc/postfix/recipient_access
```

Then edit /etc/postfix/main.cf and add this line:

```
smtpd_recipient_restrictions = check_recipient_access hash:/etc/postfix/recipient_access, reject_unauth_destination
```

Finally, run:

```
service postfix restart
```

Starting from now, if someone sends a mail to contact@example.com, he or she will receive an error message.