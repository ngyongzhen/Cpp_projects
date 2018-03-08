#include <iostream>

using namespace std;

void miniMaxSum(vector <int> arr) {
    int max = arr[0];
    int min = arr[0];
    unsigned int sumOfArr = arr[0];
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] > max){max = arr[i];}
        if(arr[i] < min){min = arr[i];}
        sumOfArr += arr[i];
    }
    cout << (sumOfArr - max) << " " << (sumOfArr - min) << endl;
}

int main() {
    vector<int> arr(5);
    for(int arr_i = 0; arr_i < 5; arr_i++){
       cin >> arr[arr_i];
    }
    miniMaxSum(arr);
    return 0;
}
