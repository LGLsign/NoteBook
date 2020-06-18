#encoding=utf-8

import sys
import time

def printLocalTime():
    time1 = time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))
    print(time1)

def test(num):
    time1 = time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))
    print(time1)
    print(num)

if __name__ == "__main__":
    
    printLocalTime()
