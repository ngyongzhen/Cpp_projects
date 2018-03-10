#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
using namespace std;

string input = "AABC";
void printPermu(map<string,int>, string);
// Keeps track available letter count
map<string,int> letterCount;
// List of unique letters in input
vector<string> letters;
int main()
{
    map<string,int> letterCount;
    for(char c : input){
        string s = string(1, c);
        if(letterCount[s] == NULL){
            letterCount[s] = 1;
            letters.push_back(s);
        }else{
            letterCount[s]++;
        }
    }

    printPermu(letterCount, "");

    return 0;
}

void printPermu(map<string,int> letterCount, string output){
    if(output.length() == input.length()){
        // Completed string formed
        cout << output << endl;
    }else{
        for(string l : letters){
            if(letterCount[l] > 0){
                letterCount[l]--;
                // Append first non-zero letter to output string
                stringstream ss;
                ss << output << l;

                printPermu(letterCount, ss.str());
                letterCount[l]++;
            }
        }
    }
}
