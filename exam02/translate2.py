#!/usr/bin/env python2.7                                                        

import re
import requests


r = requests.get('http://yld.me/aJt?raw=1')
text = str(r.text).rstrip()
text = text.split('\n')

for line in text:
   print ''.join(x for x in line if re.findall('[0-9]{3}-[0-9]{3}-[0-9]{3}[13579]',line))
