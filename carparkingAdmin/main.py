import random
import time

import login
import connection

time.sleep(3)
total = 0
space = 0
while True:
    data = connection.read()
    try:
        total = data.split('-')[0]
        space = data.split('-')[1]
    except:
        pass
    print("Total : {},Space Available : {}".format(total, space))
    time.sleep(3)
