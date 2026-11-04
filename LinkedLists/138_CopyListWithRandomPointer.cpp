//A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

//Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node.
//Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state.
//None of the pointers in the new list should point to nodes in the original list.

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
private:
    map<Node*, Node*> visited;

    Node* getClonedNode(Node* node) {
        if (!node) return NULL;

        // create a new node if it has not already been copied
        if (visited.find(node) == visited.end())
            visited[node] = new Node(node->val);

        return visited[node];
    }


public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        Node* oldNode = head;

        // Create a copy of the head node and update visited
        Node* newNode = new Node(head->val);
        visited[oldNode] = newNode;

        while (oldNode) {
            newNode->random = getClonedNode(oldNode->random);
            newNode->next = getClonedNode(oldNode->next);

            // iterate to next node
            oldNode = oldNode->next;
            newNode = newNode->next;
        }

        // return the copy of the head node
        return visited[head];
    }
};
