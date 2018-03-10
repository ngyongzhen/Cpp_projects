#include <iostream>
#include <BinaryTree.h>

using namespace std;

int main()
{
    vector<int> vec = {4,2,1,2,4,6,8,1,23,4,5,7,4,6,7,0};

    BinaryTree* bt = new BinaryTree(vec);
    bt->traverse();
    if(bt->isExist(22)){
        cout << "Found" << endl;
    }else{
        cout << "Missing" << endl;
    }
    delete bt;
    cout << "Terminating now" << endl;

    return 0;
}
