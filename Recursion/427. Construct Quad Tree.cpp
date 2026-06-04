/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    vector<vector<int>> grid;
    bool doesContainTheSameValues(int topLeftRow, int topLeftCol, int sideLength) {
        for(int row = topLeftRow; row < topLeftRow + sideLength; row++) {
            for(int col = topLeftCol; col < topLeftCol + sideLength; col++) {
                if(grid[row][col] != grid[topLeftRow][topLeftCol]) {
                    return false;
                }
            }
        }
        return true;
    }
    Node* constructQuardTree(int topLeftRow, int topLeftCol, int sideLength) {
        if(doesContainTheSameValues(topLeftRow, topLeftCol, sideLength)) {
           return new Node(grid[topLeftRow][topLeftCol], true); 
        }
        Node* currentNode = new Node(false, false);
        int halfLength = (sideLength >> 1);
        currentNode->topLeft = constructQuardTree(topLeftRow, topLeftCol, halfLength);
        currentNode->topRight = constructQuardTree(topLeftRow, topLeftCol + halfLength, halfLength);
        currentNode->bottomLeft = constructQuardTree(topLeftRow + halfLength, topLeftCol, halfLength);
        currentNode->bottomRight = constructQuardTree(topLeftRow + halfLength, topLeftCol + halfLength, halfLength);
        return currentNode;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        int sideLength = grid.size();
        this->grid = grid;
        return constructQuardTree(0, 0, sideLength);
    }
};