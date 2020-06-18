#include "ccallp.h"
#include <ctime>
#include <sstream>
#include <bitset>
#include <fstream>
#include <iomanip>

using namespace std;

time_t print_local_time() {
    time_t localTime = time(NULL);
    tm* t_tm = localtime(&localTime);
    cout << asctime(t_tm) << endl;
    return localTime;
}

void bitsetSort(const string& strNums) {
    stringstream ss;
    ss << strNums;
    long num;
    bitset<10000001> sortSet;
    while (ss >> num) {
        sortSet.set(num);
    }
    print_local_time();
    ofstream outFile("sortNums.txt", ios::trunc);
    for (int i=1;i < 10000001;i++) {
        if (sortSet.test(i))
            outFile << setw(7) << setfill('0') << i << '\n';
    }
    outFile.close();
}

int main() {
    
    time_t localTime = print_local_time();
    string strNums;
    create_million_num(strNums);
    cout << strNums.size() << endl;
    time_t createTime = print_local_time();
    bitsetSort(strNums);
    time_t sortTime = print_local_time();
    cout << "create used time: " << createTime - localTime << endl;
    cout << "sort used time: " << sortTime - createTime << endl;
    cout << "total used time: " << sortTime - localTime << endl;
    return 0;
}
