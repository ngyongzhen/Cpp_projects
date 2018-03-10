#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> input = {3, 1, 5, 1, 16, 99, 13};
int inputSum = 24;
int maxIndex;

map<int, int> intCount;
vector<int> uniqueInt;
void findSubset(vector<int>, int);


int main()
{
    // Initial setup
    for(int i = 0; i <= input.size(); i++){

        if(intCount[input[i]] == NULL){
            intCount[input[i]] = 1;
            uniqueInt.push_back(input[i]);
        }else{
            intCount[input[i]]++;
        }
    }
    findSubset({}, 0);

    return 0;
}

void findSubset(vector<int> subset, int uniqueIntIndex){
    int sum = 0;
    for(int i : subset){
        sum += i;
    }
    if(sum == inputSum){
        for(int i : subset){
            cout << i << ", ";
        }
        cout << endl;
        cout << "TRUE" << endl;
        return;
    }else{
        if(subset.size() == input.size()){return;}
        else{
            for(int i = uniqueIntIndex; i < uniqueInt.size(); i++){
                int num = uniqueInt[i];
                if(intCount[num] > 0){
                    intCount[num]--;
                    subset.push_back(num);
                    findSubset(subset, i);
                    intCount[num]++;
                    subset.pop_back();
                }
            }
        }
    }
}
