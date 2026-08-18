/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) {
            return nullptr;
        }

        unordered_map<Node*, int> actualNode_index_map;
        unordered_map<int, Node*> index_copiedNode_map;

        Node* currentNode = head;
        Node* copyHead = new Node(head -> val);
        Node* currentCopyNode = copyHead;
        int currentIndex = 0;
        while(currentNode != nullptr) {
            actualNode_index_map[currentNode] = currentIndex;
            if(currentNode->next != nullptr) {
                Node* nextCopyNode = new Node(currentNode->next->val);
                currentCopyNode->next = nextCopyNode;
            }
            index_copiedNode_map[currentIndex++] = currentCopyNode;
            currentNode = currentNode->next;
            currentCopyNode = currentCopyNode->next;
        }

        currentNode = head;
        currentCopyNode = copyHead;
        while(currentNode != nullptr) {
            if(currentNode->random != nullptr) {
                int copiedRandomNodeIndex = actualNode_index_map[currentNode->random];
                currentCopyNode->random = index_copiedNode_map[copiedRandomNodeIndex];
            }
            currentNode = currentNode->next;
            currentCopyNode = currentCopyNode->next;
        }

        return copyHead;
    }
};
