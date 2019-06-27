#include <iostream>
#include <stdlib.h>

using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;
};

node *root = NULL;

node *create_node() {
    node *newNode = new node();
    cout << "Enter Data:-\n";
    cin >> newNode->data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insert_node() {
    node *temp = root, *p = create_node();

    if (root == NULL) {
        root = p;
        return;
    }

    while (1) {
        char ch;
        cout << "Left or Right of " << temp->data << " : ";
        cin >> ch;

        if (ch == 'r' || ch == 'R') {
            if (temp->right == NULL) {
                temp->right = p;
                cout << "\tNode Inserted\n";
                break;
            }
            temp = temp->right;
        }

        if (ch == 'l' || ch == 'L') {
            if (temp->left == NULL) {
                temp->left = p;
                cout << "\tNode Inserted\n";
                break;
            }
            temp = temp->left;
        }
    }
}

void PreOrder(node *temp) {
    if (temp != NULL) {
        cout << " " << temp->data;
        PreOrder(temp->left);
        PreOrder(temp->right);
    }
}

void PostOrder(node *temp) {
    if (temp != NULL) {
        PostOrder(temp->left);
        PostOrder(temp->right);
        cout << " " << temp->data;
    }
}

void InOrder(node *temp) {
    if (temp != NULL) {
        InOrder(temp->left);
        cout << " " << temp->data;
        InOrder(temp->right);
    }

}

int main() {
    char ch;
    while (1) {
        cout << "\tI.Insert\n\tD.Display\n\tE.Exit\n";
        cin >> ch;

        switch (ch) {
            case 'I':
                insert_node();
                break;

            case 'D':
                cout << "Preorder Display:-\n";
                PreOrder(root);
                cout << "Inorder Display:-\n";
                InOrder(root);
                cout << "Postorder Display:-\n";
                PostOrder(root);
                break;

            case 'E':
                exit(0);
        }
    }
    return 0;
}
