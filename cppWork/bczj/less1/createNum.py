#!/bin/bash
#coding=utf-8

import random
import time

def printLocalTime():
    strTime = time.strftime('%Y-%M-%d %H:%M:%S', time.localtime(time.time()))
    print strTime
    return strTime

def createMillionNum():
    print "creat start: "
    print time.strftime('%Y-%M-%d %H:%M:%S', time.localtime(time.time()))
    Nums = random.sample(range(1, 9999999), 1000000)
    print(max(Nums))
    strNums = ''
    for i in Nums:
        strNums += '%06d\n' % i
    print "creat finished: "
    print time.strftime('%Y-%M-%d %H:%M:%S', time.localtime(time.time()))
    with open('Nums.txt', 'w+') as f:
        f.write(strNums)
        f.close()
    print "write finished: "
    print time.strftime('%Y-%M-%d %H:%M:%S', time.localtime(time.time()))
    return strNums

if __name__=="__main__":
    print 'start'
    printLocalTime()
    createMillionNum()
