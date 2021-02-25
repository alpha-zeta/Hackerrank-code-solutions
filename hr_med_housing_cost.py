#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the minimumLoss function below.
def minimumLoss(price):
    idx={};
    for i in range(len(price)):
        idx[price[i]]=i
    new=sorted(price,reverse=True)
    cost=10**10
    for i in range(0,len(new)-1):
        if new[i]-new[i+1]==1 and idx[new[i]]<idx[new[i+1]]:
            cost=1
            break
        elif idx[new[i]]<idx[new[i+1]] and new[i]-new[i+1]<cost:
            cost=new[i]-new[i+1]
    return(cost)
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    price = list(map(int, input().rstrip().split()))

    result = minimumLoss(price)

    fptr.write(str(result) + '\n')

    fptr.close()
