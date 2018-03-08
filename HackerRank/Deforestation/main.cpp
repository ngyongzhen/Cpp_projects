#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

struct Node{
    bool isWinning;
    int data;
    vector<Node*> children;
};

Node* getNewNode(int);
void constructTree(int, vector<vector<int>>);
bool traverse(Node*);

Node* root;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int testCases, nodeCount;
    cin >> testCases;
    for(int testCase = 0; testCase < testCases; testCase++){
        cin >> nodeCount;
        vector<vector<int>> edges(nodeCount-1);
        for(int i = 0; i < nodeCount - 1 ; i++){
            int input1, input2;
            cin >> input1;
            cin >> input2;
            edges[i] = vector<int>(2);
            edges[i][0] = input1;
            edges[i][1] = input2;
        }
        root = NULL;
        constructTree(nodeCount, edges);
        if(traverse(root)){
            cout << "Alice" << endl;
        }else{
            cout << "Bob" << endl;
        }
    }

    return 0;
}

void constructTree(int nodeCount, vector<vector<int>> edges){
    map<int, Node*> nodeMap;
    for(int i = 0; i < nodeCount; i++){
        nodeMap[(i+1)] = getNewNode(i+1);
    }
    root = nodeMap[1];
    for(vector<int> edge : edges){
        if(edge[0] < edge[1]){
            nodeMap[edge[0]]->children.push_back(nodeMap[edge[1]]);
        }
        else{
            nodeMap[edge[1]]->children.push_back(nodeMap[edge[0]]);
        }
    }
}

Node* getNewNode(int data){
    Node* node = new Node();
    node->data = data;
    return node;
}

bool traverse(Node* node){
    if(node->children.size() == 0){
        node->isWinning = false;
        return false;
    }
    int numOfWin = 0;
    int numOfLose = 0;
    for(Node* n : node->children){
        bool result = traverse(n);
        if(result){
            numOfWin++;
        }else{
            numOfLose++;
        }
    }
    cout << numOfWin << endl;
    cout << numOfLose << endl;
    if((numOfWin > 0 && numOfWin%2 == 1) || (numOfLose > 0 && numOfLose%2 == 1)){
        return true;
    }else{
        return false;
    }
}
