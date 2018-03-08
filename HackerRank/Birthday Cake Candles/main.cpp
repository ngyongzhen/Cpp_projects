#include <iostream>
#include <map>

using namespace std;

int birthdayCakeCandles(int n, vector <int> ar) {
    map<int, int> candleMap;
    int tallestHeight = 0;
    for(int i = 0; i < ar.size(); i++){
        if(ar[i] > tallestHeight){tallestHeight = ar[i];}
        candleMap[ar[i]] += 1;
    }
    return candleMap[tallestHeight];
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = birthdayCakeCandles(n, ar);
    cout << result << endl;
    return 0;
}

