#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the isValid function below.
def isValid(s):
    res={}
    oc2={}
    for i in range(0,len(s)):
        res[s[i]]=res.get(s[i],0)+1
    num=0
    oc=[]
    maxNum=0
    maxVal=0
    for (key,val) in res.items():
        oc.append(val)
        oc2[val]=oc2.get(val,0)+1;
        if oc2[val]>maxNum:
            maxNum=oc2[val]
            maxVal=val
    dec=True;
    c=0
    for (key,val) in oc2.items():
        if key>maxVal+1:
            dec=False
            break
        elif key<maxVal:
            if oc2[key]!=1:
                dec=False
                break
            else:
                c=c+1
        elif key==maxVal+1:
            if oc2[key]>1:
                dec=False
                break
            else:
                c=c+1          
    out=""
    if dec==False or c>1:
        out="NO"
    else:
        out="YES";
    return(out);
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = isValid(s)

    fptr.write(result + '\n')

    fptr.close()
