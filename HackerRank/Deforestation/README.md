Alice and Bob are playing a game with a rooted tree. The tree has  vertices and the first node, , is always the root. Here are the basic rules:

They move in alternating turns, and both players always move optimally.
During each move, a player removes an edge from the tree, disconnecting one of its leaves or branches. The leaf or branch that was disconnected from the rooted tree is removed from the game.
The first player to be unable to make a move loses the game.
Alice always makes the first move.
For example, the diagram below shows a tree of size n=7, where the root is node 1: tree-initial.png

Now, if a player removes the edge between 1 and 4, then nodes 4 and 7 become disconnected from the root and are removed from the game:

tree-removed.png

Given the structure of the tree, determine and print the winner of the game. If Alice wins, print Alice; otherwise print Bob.

Input Format

The first line contains a single integer, T, denoting the number of test cases. 
For each test case, the first line contains an integer, N, denoting the number of nodes in the tree. 
Each of the N-1 subsequent lines contains 2 space-separated integers,  and , defining an edge connecting nodes  and .

Constraints

Output Format

For each test case, print the name of the winner (i.e., Alice or Bob) on a new line.

Sample Input

1
5
1 2
3 1
3 4
4 5
Sample Output

Alice
Explanation

Test Case 0:

Alice removes the edge connecting node  to node , effectively trimming nodes  and  from the tree. Now the only remaining edges are  and . Because Bob can't remove both of them, Alice will make the last possible move. Because the last player to move wins, we print Alice on a new line.