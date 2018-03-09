#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

int dfs(int,int);
// We will only use vector starting from 1 (Node 1 = root) all the way to 500
// Therefore 501 slots are needed
vector<vector<int>> edges(501);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int testCases, nodeCount;
    cin >> testCases;
    for(int testCase = 0; testCase < testCases; testCase++){
        cin >> nodeCount;
        for(int i = 0; i < nodeCount; i++){
            edges[i+1].clear();
        }
        for(int i = 0; i < nodeCount - 1 ; i++){
            int input1, input2;
            cin >> input1;
            cin >> input2;

            edges[input1].push_back(input2);
            edges[input2].push_back(input1);

        }
        if(dfs(1, -1) == 0){
            // No edges, first to go loses (bob is second)
            cout << "Bob" << endl;
        }else{
            cout << "Alice" << endl;
        }
    }

    return 0;
}

// Returns the number of edges in the single stalk
int dfs(int nodeIndex, int parent){
    int stalk = 0;
    for(int child : edges[nodeIndex]){
        // Prevents infinite loop since we added the edge in both ways
        // x -> y and y -> x
        if(child != parent){
            // +1 to include the child's vertex to parent
            int childStalk = dfs(child, nodeIndex)+1;
            // Using XOR, the excess branches are replaced with a single stalk
            // The resulting value is essentially the number of edges in this single stalk
            stalk ^= childStalk;
        }
    }
    return stalk;
}
