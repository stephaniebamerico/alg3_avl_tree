/* Stephanie Briere Americo
         GRR20165313         */
/* Talita Halboth Cunha Fernandes
         GRR20165399         */

#include <stdio.h>
#include <stdlib.h>
#include "AVL_Tree.h"

int getBalanceFactor (AVL_Node *node);
int maxChildrenHeight (AVL_Node *node);
AVL_Node* newNode(int key);
AVL_Node* balance (AVL_Node *node);
AVL_Node* rotateLeft (AVL_Node *node);
AVL_Node* rotateRight (AVL_Node *node);
AVL_Node* predecessor (AVL_Node *node);

/* ===== External Functions ===== */

AVL_Node* insertNode (AVL_Node *node, int key) {
    /* If the node does not exist, it creates 
       and no change in its height is required
       (sheet has height 1) */
    if (!node)
        return newNode(key);
    
    /* If the node has a key larger than the new entry, 
       it creates the new node in the left subtree. */
    if (node->key > key)
        insertNode(node->left, key);

    /* If the node has a key less than or equal 
       to the new entry, it creates the new node
       in the right subtree. */
    else
        insertNode(node->right, key);

    // Updates node height
    node->height = 1 + maxChildrenHeight(node);

    // Finally, balance the tree (if necessary)
    return balance(node);
}

AVL_Node* removeNode (AVL_Node *node, int key) {
    
    if (node == NULL)
        return (node);
    // if key is less than node's key, go to the left
    if (key < node->key) 
        node->left = removeNode (node->left, key);
    // if key is greater than node's key, go to the right
    else if (key > node->key)
        node->right = removeNode (node->right, key);
    // we are on the right node!
    else {
        //if there's 1 or 0 children
        if (node->left == NULL || node->right == NULL)
            //node <- child or NULL
            node = node->left ? node->left : node->right;
        // 2 childs
        else
        {
            // find predecessor
            AVL_Node *aux = predecessor(node);
            // node key becomes predecessor key
            node->key = aux->key;
            // delete predecessor node
            node->left = removeNode (node->left, aux->key);
        }
    }

    node->height = 1 + maxChildrenHeight(node);
    node = balance (node);
    return (node);
}

void searchNode (AVL_Node *node, int key) {
    AVL_Node * aux = node;

    while (aux) {
        if (aux == node)
          printf("%d\n", aux->key);  
        else
          printf(",%d\n", aux->key);
        
        if (aux->key == key)
            aux = NULL;
        else if (aux->key > key)
            aux = aux->left;
        else
            aux = aux->right;
    }
}

void preorder (AVL_Node *node) {
    if (node) {
        printf("(" );
        printf("%d",node->key );
        preorder(node->left);
        printf(",");
        preorder(node->right);
        printf(")");
    }
    else
        printf("()" );
}

/* ===== Internal Functions ===== */

int getBalanceFactor (AVL_Node *node) {
    if(node) {
        unsigned l, r;
        l = (node->left)  ? node->left->height  : 0;
        r = (node->right) ? node->right->height : 0;
        return (l-r);
    }

    return 0;
}

int maxChildrenHeight (AVL_Node *node) {
    if(node) {
        unsigned l, r;
        l = (node->left)  ? node->left->height  : 0;
        r = (node->right) ? node->right->height : 0;
        return (l > r) ? l : r;
    }

    return 0;
}

AVL_Node* newNode(int key) {
    // New node is initially added at leaf
    AVL_Node* node = 
        (AVL_Node*) malloc(sizeof(AVL_Node));
    node->key = key;
    node->p = NULL;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // Leaf height is 1
    return(node);
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
    if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0)
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
    else if (balanceFactor > 1 && getBalanceFactor(node->left) < 0) {
        node->left = rotateLeft(node->left);
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
    else if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0)
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
    else if (balanceFactor < -1 && getBalanceFactor(node->right) > 0) {
        node->right = rotateRight(node->right);
        node = rotateLeft(node);
    }
    return (node);
}

AVL_Node* rotateLeft (AVL_Node *node) {
    // Store the child and the grandchild
    AVL_Node *auxChild = node->right;
    AVL_Node *auxGranChild = (auxChild->left) ? auxChild->left : NULL;
    
    // Rotate left
    auxChild->left = node;
    node->right = auxGranChild;

    //  Updates height
    node->height = 1 + maxChildrenHeight (node);
    auxChild->height = 1 + maxChildrenHeight (auxChild);
    
    // Returns the new root
    return (auxChild);

}

AVL_Node* rotateRight (AVL_Node *node) {
    // Store the child and the grandchild
    AVL_Node *auxChild = node->right;
    AVL_Node *auxGrandchild = (auxChild->left) ? auxChild->left : NULL;
 
    // Rotate right
    auxChild->left = node;
    node->right = auxGrandchild;
 
    //  Updates height
    node->height = 1 + maxChildrenHeight(node);
    auxChild->height = 1 + maxChildrenHeight(node);
 
    // Returns the new root
    return auxChild;
}

AVL_Node* predecessor (AVL_Node *node) {
    AVL_Node *aux = node->left;
    while (aux->right)
        aux = aux->right;
    return (aux);
}