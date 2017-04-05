---
layout: page
title: Mac OS X Server and Quotas
---

There are a number of ways to handle quotas in Mac OS X Server. To enable quotas is simple enough. If you open Server Admin and then click on Share Points and then the volume, you can check the box for enable quotas on this volume. It will take awhile for the data to load once you’ve clicked save, but then it will show you how much space is in each users quota.

You’ll then notice the .quota.ops.user and .quota.user files at the root of the file system you just enabled quotas for. If you enable group quotas then you will see .quota.group and .quota.ops.group as well. Since these are not created automatically, you can create an empty shell for the .quota.ops.group with touch:

```shell
touch .quota.ops.group
```

At this point, if you attempt to look at the user quota files then you aren’t going to see anything of interest as they’re binary files. You can then use the quota, edquota and reqquota commands to manage the quota.

If you use the repquota command, you can see similar output to what you see in Server Admin, but with a little more information (here we’ll use the -a and -v options to see quotas for all volumes (the -a) and see a list of which volume each listing is for (the -v option):

```shell
repquota -av
```

Next, we can set a quota. If you have an existing user then you can set the quota for that user and then base subsequent users from that one using the edquota command. In the following example, we’ll take a look at a user called mytemplate and base the quota for a user called newuser on the one used for mytemplate:

```shell
edquota -u -p mytemplate newuser
```

Alternatively, you could replace these with the $templateuser and $newuser variable if you were scripting this:

```shell
edquota -u -p $templateuser $newuser
```

You can also enable a group quota for a specific group by using the edquota command:

```shell
edquota -g mygroupname
```

Once you’ve enabled quotas, you can check each user quota using the quota command with the -u option or the -g for groups. I like to add a -v for posterity. So you if you ended up with a user named cedge you could use:

```shell
quota -vu cedge
```
