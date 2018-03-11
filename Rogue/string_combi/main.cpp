#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

map<string, int> letterCount;
vector<string> uniqueLetters;

string input = "AABC";

void printCombi(int, string);
int main()
{
    // Setup map and unique letters
    for(char c : input){
        string letter = string(1, c);
        if(letterCount[letter] == NULL){
            letterCount[letter] = 1;
            uniqueLetters.push_back(letter);
        }else{
            letterCount[letter]++;
        }
    }

    printCombi(0, "");
    return 0;
}

void printCombi(int index, string output){
    cout << output << endl;
    if(output.length() == input.length()){
        return;
    }else{
        for(int i = index; i < uniqueLetters.size(); i++){
            string letter = uniqueLetters[i];
            if(letterCount[letter] > 0){
                output.append(letter);
                letterCount[letter]--;
                printCombi(i, output);
                output.pop_back();
                letterCount[letter]++;
            }
        }
    }
}
