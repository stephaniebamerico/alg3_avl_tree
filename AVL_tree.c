/* Stephanie Briere Americo
         GRR20165313         */
/* Talita Halboth Cunha Fernandes
         GRR20165399         */

#include <stdio.h>
#include <stdlib.h>
#include "AVL_Tree"

void balance (AVL_Node *node);
AVL_Node* newNode(int key);
AVL_Node rotateLeft (AVL_Node *node);
AVL_Node rotateRight (AVL_Node *node);
int getBalanceFactor (AVL_Node node);
int maxChildrenHeight (AVL_Node node);

AVL_Node* insertNode (AVL_Node *node, int key) {
    /* If the node does not exist, it creates 
       and no change in its height is required
       (sheet has height 0) */
    if (!node)
        return newNode(key);
    
    /* If the node has a key larger than the new entry, 
       it creates the new node in the left subtree. */
    if (node->key > key)
        insertNode(node->left);

    /* If the node has a key less than or equal 
       to the new entry, it creates the new node
       in the right subtree. */
    else
        insertNode(node->right);

    // Updates node height
    node->height = 1 + maxChildrenHeight(node);
}

AVL_Node *removeNode (AVL_Node *node, int key) {
    
    if (node == NULL)
        return (node);
    // if key is less than node's key, go to the left
    if (key < node->key) 
        nodo->left = removeNode (node->left);
    // if key is greater than node's key, go to the right
    else if (key > node->key)
        node->right = removeNode (node->right);
    // we are on the right node!
    else {
        //if there's 1 or 0 children
        if (node->left == NULL || node->right == NULL)
            //node <- child or NULL
            node = node->left ? node->left : node->right;
        // 2 childs
        else
        {
            //rights 
            node->left.right = node->right;
            node = node->left;
        }
    }

}

void searchNode (AVL_Node *node, int key) {
    AVL_Node * aux = node;

    while (aux) {
        if (aux == root)
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

int getBalanceFactor (AVL_Node node) {
    unsigned l, r;
    l = (node.left)  ? node.left.height  : 0;
    r = (node.right) ? node.right.height : 0;
    return (l-r);
}

int maxChildrenHeight (AVL_Node node) {
  unsigned l, r;
    l = (node.left)  ? node.left.height  : 0;
    r = (node.right) ? node.right.height : 0;
    return (l > r) ? l : r;
}