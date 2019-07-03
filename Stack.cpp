#include <iostream>

using namespace std;

class node {
public:
    int info;
    node *link;
};

node *start = NULL;

node *PUSH(node *start, int data) {
    node *temp;
    temp = new node();
    temp->info = data;
    if (start == NULL) {                                /*Empty List*/
        temp->link = NULL;
        start = temp;
        return start;
    }
    node *ptr;
    ptr = start;
    while (ptr->link != NULL)
        ptr = ptr->link;
    ptr->link = temp;
    temp->link = NULL;
    return start;

}

void display(node *start) {
    if (start == NULL) {
        cout << "Empty Stack\n";
        return;
    }
    node *ptr = start;
    while (ptr != NULL) {
        cout << ptr->info << " ";
        ptr = ptr->link;
    }
}

node *POP(node *start) {
    if (start == NULL) {
        cout << "Empty Stack\n";
        return start;
    }
    node *temp;
    if (start->link == NULL) {              /*If there is only one element in the STACK*/
        temp = start;
        start = NULL;
        delete (temp);
        return start;
    }
    node *ptr;
    ptr = start;
    while (ptr->link->link != NULL) {
        ptr = ptr->link;
    }
    temp = ptr->link;
    delete (temp);
    ptr->link = NULL;
    return start;
}

int main() {
    start = PUSH(start, 10);
    start = PUSH(start, 20);
    start = PUSH(start, 30);
    display(start);
    start = POP(start);
    start = POP(start);
    start = POP(start);
    display(start);
    return 0;
}
