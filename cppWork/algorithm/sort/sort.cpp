#include <iostream>
#include <stdio.h>
#include <vector>
#include <ctime>
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

time_t print_cur_time() {
    
    time_t curTime = time(NULL);
    cout << ctime(&curTime) << endl;
    return curTime;
}

void max_heap_maintain(vector<int>& vNums, int nPosition, int nSize);

void heap_sort(vector<int>& vNums);
void direct_insertion_sort(vector<int>& vNums, int nGap);
void direct_insert(vector<int>& vNums, int nValue); 
void shell_sort(vector<int>& vNums);
void quick_sort(vector<int>& vNums, int nLeftPos, int nRightPos);
void bucket_sort(vector<int>& vNums);
void merge_sort(vector<int>& vNums, int nLeftPos, int nRightPos);
void radix_sort(vector<int>& Nums); 

int main() {
    vector<int> vNums;
    srand(time(NULL));

    int nSize;
    cin >> nSize;

    for (auto i = 0; i < nSize; i++) {
        vNums.push_back(rand()%10000000);
    }

    cout << "start: ";
    time_t startTime = print_cur_time();
    radix_sort(vNums);
    //merge_sort(vNums, 0, vNums.size()-1);
    cout << "finished: ";
    time_t finishedTime = print_cur_time();
    cout << "total time: " << finishedTime - startTime << endl;
    
     /*
    for (auto num:vNums) {
        cout << setw(10) << setfill('0') << num << endl;
    }
    //*/
    
    return 0;
}

void max_heap_maintain(vector<int>& vNums, int nPosition, int nSize) {
    
    /*递归版
    //叶子节点，返回
    if (nSize <= nPosition) {
        return;
    }

    //记录左右子树位置
    int nLeftSon = nPosition * 2 + 1;
    int nRightSon = nPosition * 2 + 2;
    int nMaxPos = nPosition;
 
    //找到最大数位置
    if (nSize > nLeftSon) {
        nMaxPos = vNums[nMaxPos] >= vNums[nLeftSon] ? nMaxPos : nLeftSon;
    }
    if (nSize > nRightSon) {
        nMaxPos = vNums[nMaxPos] >= vNums[nRightSon] ? nMaxPos : nRightSon;
    }

    //当前位置不是最大数交换，继续维护子树
    if (nPosition != nMaxPos) {
        swap(vNums[nPosition], vNums[nMaxPos]);
        max_heap_maintain(vNums, nMaxPos, nSize);
    }
    */
    
    //*迭代版
    int nCurPos = nPosition;
    int nLeftSon, nRightSon, nMaxPos;
    while (nCurPos < nSize/2) {
        nMaxPos = nCurPos;
        nLeftSon = nCurPos * 2 + 1;
        nRightSon = nCurPos * 2 + 2;
        if (nLeftSon < nSize) {
            nMaxPos = vNums[nMaxPos] >= vNums[nLeftSon] ? nMaxPos : nLeftSon;
        }
        if (nRightSon < nSize) {
            nMaxPos = vNums[nMaxPos] >= vNums[nRightSon] ? nMaxPos : nRightSon;
        }
        if (nMaxPos == nCurPos) {
            break;
        }
        swap(vNums[nMaxPos], vNums[nCurPos]);
        nCurPos = nMaxPos;
   }
}

void heap_sort(vector<int>& vNums) {
    int nSize = vNums.size();    

    //创建大顶堆，从后往前
    for (int i = nSize/2 - 1; i >= 0; i--) {
        max_heap_maintain(vNums, i, nSize);
    }
    
    //开始排序
    while (--nSize) {
        swap(vNums[0], vNums[nSize]);
        max_heap_maintain(vNums, 0, nSize);
    }
}

//改进版直接插入排序，适用于shell排序
void direct_insertion_sort(vector<int>& vNums, int nGap = 1) {
    
    int nSize = vNums.size();
    
    for (int i = nGap; i < nSize; i++) {
        if (vNums[i] < vNums[i-nGap]) {
            int nTmp = vNums[i];
            int j;
            for (j = i-nGap; j >= 0; j -= nGap) {
                if (vNums[j] > nTmp) {
                    vNums[j+nGap] = vNums[j];
                    continue;
                }
                break;
            }
            vNums[j+nGap] = nTmp;
        }
    }
}

//在一个有序序列插入一个值并保持序列的有序性(直接插入排序)
void direct_insert(vector<int>& vNums, int nValue) {
    
    vNums.push_back(nValue);
    int nPos;
    for (nPos=vNums.size()-1;nPos > 0;nPos--) {
        if (vNums[nPos-1] > nValue) {
            vNums[nPos] = vNums[nPos-1];
        }
    }
    vNums[nPos] = nValue;
}

void shell_sort(vector<int>& vNums) {
    
    int nSize = vNums.size();

    //两种高效增序序列
    //1.n*3+1 序列
    int nIncrement = 1;
    while (nIncrement <= nSize/3) {
        nIncrement = nIncrement * 3 + 1;
    }
    
    //2.(9*4^k-9*2^k+1)与(4^k-3*2^k+1)综合序列, 效率比前一种搞40%-60%
    //*
    vector<int> vIncrements;
    for (int i = 0;; i++) {
        int nTmp1 = 9 * pow(4, i) - 9 * pow(2, i) + 1;
        int nTmp2 = pow(4, i) - 3 * pow(2, i) + 1;
        if (nTmp2 > nSize/3) {
            break;
        }
        if (nTmp1 <= nSize/3) {
            vIncrements.push_back(nTmp1);
        }
        if (nTmp2 <= nSize/3 && nTmp2 > 0) {
            vIncrements.push_back(nTmp2);
        }
    }
    sort(vIncrements.begin(), vIncrements.end());
    //*/
    
    /*
    while (nIncrement > 0) {
        direct_insertion_sort(vNums, nIncrement);
        nIncrement = (nIncrement - 1) / 3;
    }
    //*/
    
    //*
    for (int i = vIncrements.size()-1; i >= 0; i--) {
        direct_insertion_sort(vNums, vIncrements[i]);
    }
    //*/
}

void quick_sort(vector<int>& vNums, int nLeftPos, int nRightPos) {
    
    //递归版
    /*
    if (nLeftPos >= nRightPos) {
        return;
    }
    
    int nKey = vNums[nLeftPos];
    int nLeft = nLeftPos;
    int nRight = nRightPos;
    while (nLeftPos < nRightPos) {
        while (vNums[nRightPos] >= nKey && nLeftPos < nRightPos) {
                nRightPos--;
        }
        vNums[nLeftPos] = vNums[nRightPos];
        while (vNums[nLeftPos] <= nKey && nLeftPos < nRightPos) {
            nLeftPos++;
        }
        vNums[nRightPos] = vNums[nLeftPos];
    }
    vNums[nLeftPos] = nKey;
    
    quick_sort(vNums, nLeft, --nLeftPos);
    quick_sort(vNums, ++nRightPos, nRight);
    //*/
    
    //迭代版
    //*
    vector<int> vPosition;
    vPosition.push_back(nLeftPos);
    vPosition.push_back(nRightPos);
    int nLeft, nRight, nKey;
    while (!vPosition.empty()) {
        nRight = vPosition.back();
        nRightPos = nRight;
        vPosition.pop_back();
        nLeft = vPosition.back();
        nLeftPos = nLeft;
        vPosition.pop_back();
        if (nLeft >= nRight) {
            continue;
        }

        nKey = vNums[nLeft];
        while (nLeft < nRight) {
            while (vNums[nRight] >= nKey && nLeft < nRight) {
                nRight--;
            }
            vNums[nLeft] = vNums[nRight];
            while (vNums[nLeft] <= nKey && nLeft < nRight) {
                nLeft++;
            }
            vNums[nRight] = vNums[nLeft];
        }
        vNums[nLeft] = nKey;

        vPosition.push_back(++nRight);
        vPosition.push_back(nRightPos);
        vPosition.push_back(nLeftPos);
        vPosition.push_back(--nLeft);
    }
    //*/
}

//桶排序的稳定性取决于每个桶内所用排序算法 
//映射函数为常用的f=array[i]/k, k ^ 2 = size;
void bucket_sort(vector<int>& vNums) {
    
    int nBucketNum = sqrt(vNums.size()) + 1;
    vector<vector<int> > vBuckets(nBucketNum, vector<int>());
    int nValue;
    while (!vNums.empty()) {
        nValue = vNums.back();
        vNums.pop_back();
        //direct_insert(vBuckets[nValue/nBucketNum], nValue);
        vBuckets[nValue/nBucketNum].push_back(nValue);
    }
    for (auto &bucket:vBuckets) {
        if (bucket.empty()) {
            continue;
        }
        quick_sort(bucket, 0, bucket.size()-1);
        vNums.insert(vNums.end(), bucket.begin(), bucket.end());
        vector<int>().swap(bucket);
    }
}

void merge_sort(vector<int>& vNums, int nLeftPos, int nRightPos) {
    
    //递归实现
    //*
    if (nLeftPos >= nRightPos) {
        return;
    }

    int nSize = nRightPos - nLeftPos + 1;
    int nMidPos = (nLeftPos + nRightPos) / 2;
    
    merge_sort(vNums, nLeftPos, nMidPos);
    merge_sort(vNums, ++nMidPos, nRightPos);
    
    vector<int> vMergeNums;
    int nLeft = nLeftPos;
    int nRight = nMidPos;
    
    while (nLeft < nMidPos && nRight <= nRightPos) {
        if (vNums[nLeft] > vNums[nRight]) {
            vMergeNums.push_back(vNums[nRight]);
            nRight++;
        }
        else {
            vMergeNums.push_back(vNums[nLeft]);
            nLeft++;
        }
    }
    
    while (nLeft < nMidPos) {
        vMergeNums.push_back(vNums[nLeft++]);
    }
    while (nRight <= nRightPos) {
        vMergeNums.push_back(vNums[nRight++]);
    }
    
    for (int i = 0; i < nSize; i++) {
        vNums[nLeftPos + i] = vMergeNums[i];
    }
    
    //迭代实现可以参考快速排序
}

void radix_sort(vector<int>& vNums) {
    
    //rand生成随机数最大值为RAND_MAX
    int nMaxNum = RAND_MAX;
    int nMaxLen = 1;
    while (nMaxNum /= 10) {
        nMaxLen++;
    }
    
    vector<vector<int> > vBuckets(10);
    int nPosition = 0;
    for (int i = 0; i < nMaxLen; i++) {
        for (auto num : vNums) {
            nPosition = (int)(num / pow(10, i)) % 10;
            vBuckets[nPosition].push_back(num);
        }
        vector<int>().swap(vNums);
        for (auto &bucket : vBuckets) {
            for (auto num : bucket) {
                vNums.push_back(num);
            }
            vector<int>().swap(bucket);
        }
    }
} 
