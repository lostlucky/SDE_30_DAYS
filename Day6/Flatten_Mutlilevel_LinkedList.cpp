/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return NULL;
        Node* nextNode = head -> next, *childNode = flatten(head -> child);
        head -> next = childNode;
        if(childNode) childNode -> prev = head;
        head -> child = NULL;
        Node* t = head;
        while(t -> next) t = t -> next;
        nextNode = flatten(nextNode);
        t -> next = nextNode;
        if(nextNode) nextNode -> prev = t;
        return head;
    }
};
