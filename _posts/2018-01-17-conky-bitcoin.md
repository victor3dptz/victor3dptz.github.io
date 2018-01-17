---
layout: post
title: Conky config to show current Bitcoin price
---

The result will be like above:
![Conky](/linux/conky/conky.png)

Create a directory, put a script **bitcoin.py** there and make it executable:
```python
#!/usr/bin/python

import requests

bitcoin = "https://api.coinmarketcap.com/v1/ticker/bitcoin/?convert=RUB"
btc_res = requests.get(bitcoin)
btc_data = btc_res.json()[0]

file = open('/home/victor3d/.config/conky/bitcoin/bitcoin.txt','w')
file.write('$'+btc_data['price_usd']+'\n')
file.write(btc_data['percent_change_24h']+'%'+'\n')
file.write(btc_data['price_rub']+'\n')
file.write(btc_data['rank']+'\n')
file.close()
```
The script requires python-requests module, to install it on Debian type:
```shell
sudo apt-get install python-requests
```

In my examples, replace the path /home/victor3d/.config/conky/bitcoin/ to your path.

Install the [FontAwesome Font](/linux/conky/fontawesome-webfont.ttf).

To your .conkyrc add the following:
```
${hr}
${alignc}${font FontAwesome}${font} I T C O I N  ${if_match ${execi 10 awk -F . 'NR==2 {print $1}' /home/victor3d/.config/conky/bitcoin/bitcoin.txt} > 0}${color #00ff00}${font FontAwesome}${font}${execi 10 awk -F . 'NR==2 {print $1}' /home/victor3d/.config/conky/bitcoin/bitcoin.txt}%${color}${else}${color #FF0000}${font FontAwesome}${font}${execi 10 awk -F . 'NR==2 {print $1}' /home/victor3d/.config/conky/bitcoin/bitcoin.txt}%${color}${endif}
${font FontAwesome}${font} ${execi 10 awk -F . 'NR==1 {print substr($1,2)}' /home/victor3d/.config/conky/bitcoin/bitcoin.txt} ${alignr} ${font FontAwesome}${font} ${execi 10 awk -F . 'NR==3 {print $1}' /home/victor3d/.config/conky/bitcoin/bitcoin.txt}
```

Then, add to crontab bitcoin.py to update the prices hourly.
```
0 * * * * /home/victor3d/.config/conky/bitcoin/bitcoin.py
```
