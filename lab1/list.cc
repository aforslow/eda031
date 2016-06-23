#include <iostream>
#include "list.h"

class List {
public:
    int size;
    /* creates an empty list */
    List(){
        first = nullptr;
        size = 0;
    }
    
    /* destroys this list */
    ~List(){
        while (first != nullptr) {
            Node* t = first->next;
            delete first;
            first = t;
        }
        size = 0;
    }
    
    /* returns true if d is in the list */
    bool exists(int d) const{
        Node* n = first;
        while (n != nullptr) {
            if (n->value == d){
                return true;
            }
        }
        return false;
    }

    /* returns the size of the list */
    int size() const{
        return size;
    }

    /* returns true if the list is empty */
    bool empty() const{
        return size == 0;
    }

    /* inserts d into this list as the first element */
    void insertFirst(int d){
        Node* n = new Node(d, first);
        first = n;
    }

    /* removes the first element less than/equal to/greater than d,
 depending on the value of df. Does nothing if there is no value
 to remove. The enum values are accessed with List::DeleteFlag::LESS,
 ..., outside the class */
enum class DeleteFlag { LESS, EQUAL, GREATER };
    void remove(int d, DeleteFlag df){
        Node* n = first;
        while (n != nullptr) {
            if (n->next->value == d && df::EQUAL) {
                n->next = n->next->next;
                break;
            } else if(n->next->value < d && df::LESS){
		    n->next = n->next->next;
		    break;
	    } else if(n->next->value > d && df::GREATER){
		    n->next = n->next->next;
		    break;
	    }
            n = n->next
        }
    }

    /* prints the contents of this list */
    void print() const{
        Node* n = first;
        while (n != nullptr) {
            std::cout << n->value;
            n = n->next;
        }
    }

/* forbid copying of lists */
List(const List&) = delete;
List& operator=(const List&) = delete;

private:

/* a list node */
struct Node {
    int value; // the node value
    Node* next; // pointer to the next node, nullptr in the last node
    Node(int v, Node* n) : value(v), next(n) {}
};

Node* first; // pointer to the first node
};

