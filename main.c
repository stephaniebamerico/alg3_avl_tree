#include <stdio.h>
#include "AVL_Tree.h"

int main() {
    AVL_Node *root = NULL;
    char input;
    int key;

    while (scanf("%c", &input) > 0) {
        switch (input) {
            case 'i':
                scanf("%d", &key);
                root = insertNode(root, key);
                preorder(root);
                printf("\n");
                break;
            case 'r':
                scanf("%d", &key);
                root = removeNode(root, key);
                preorder(root);
                printf("\n");
                break;
            case 'b':
                scanf("%d", &key);
                searchNode(root, key);
                printf("\n");
                break;
        }
    }
}