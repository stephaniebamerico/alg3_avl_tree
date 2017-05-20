/*== Stephanie Briere Americo
		GRR20165313 ==*/
/*== Talita Halboth Cunha Fernandes
		GRR20165399 ==*/

#include <stdio.h>
#include <stdlib.h>
#include "AVL_Tree"

int getBalanceFactor (AVL_Node node);

void insertNode (AVL_Node *node, int key) {

}

void removeNode (AVL_Node *node, int key) {
  
}

void searchNodePrinter (AVL_Node *node, int key) {
    AVL_Node * aux = node;

    while (aux) {
        if(aux == root)
          printf("%d\n", aux->key);  
        else
          printf(",%d\n", aux->key);
        
        if (aux->key == key)
            return aux;
        else if (aux->key > key)
            aux = aux->left;
        else
            aux = aux->right;
    }
}

AVL_Node* balance (AVL_Node *node) {
    unsigned balanceFactor = getBalanceFactor (node);
    /*
         (3)        (2)
         /    -->   / \
       (2)        (1) (3)   
       / \             / 
     (1) (?)         (?)
          |
          v
    can or not have this child 
    */
    if (balanceFactor > 1 && getBalanceFactor(node.left) >= 0)
        node = rotateLeft(node);
    /*
         (5)          (5)              (3)
         /            /                / \
       (2)           (3)             (2) (5)  
       / \     -->   / \     -->     /   /
     (1) (3)       (2) (4)         (1)  (4)
           \       /     
           (4)   (1)

    */
    else if (balanceFactor > 1 && getBalanceFactor(node.left) < 0) {
        node.left = rotateLeft(node->left);
        node = rotateRight(node);
    }
    /*
        (1)           (2)
          \           / \
          (2)  -->  (1) (3)
          / \         \
        (?) (3)       (?)
         |
         v
      can or not have this child   

    */
    else if (balanceFactor < -1 && getBalanceFactor(node.right) <= 0)
        node = rotateRight(node);
    /*
        (1)             (1)                (3)
          \               \                / \
          (4)             (3)            (1) (4) 
          / \      -->    / \       -->    \   \
        (3) (5)         (2) (4)           (2) (5)
        /                     \
       (2)                    (5)
    */
    else if (balanceFactor < -1 && getBalanceFactor(node.right) > 0) {
        node.right = rotateRight(node->right);
        node = rotateLeft(node);
    }
    return (node);
}

AVL_Node* newNode(int key) {
    AVL_Node* node = 
        (AVL_Node*) malloc(sizeof(AVL_Node));
    // New node is initially added at leaf
    node->key = key;
    node->p = NULL;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // Leaf height is 1
    return(node);
}

AVL_Node rotateLeft (AVL_Node *node) {

}

AVL_Node rotateRight (AVL_Node *node) {

}

AVL_Node* searchNode (AVL_Node *node, int key) {
    AVL_Node * aux = node;

    while (aux) {
        if (aux->key == key)
            return aux;
        else if (aux->key > key)
            aux = aux->left;
        else
            aux = aux->right;
    }

    return NULL;
}

int getBalanceFactor (AVL_Node node) {
    unsigned l, r;
    l = (node.left)  ? node.left.height  : 0;
    r = (node.right) ? node.right.height : 0;
    return (l-r);
}