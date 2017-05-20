/*== Stephanie Briere Americo
		GRR20165313 ==*/
/*== Talita Halboth Cunha Fernandes
		GRR20165399 ==*/

#include <stdio.h>
#include <stdlib.h>
#include "AVL_Tree"

struct AVL_Node* newNode(int key) {
    struct AVL_Node* node = 
    		(struct AVL_Node*) malloc(sizeof(struct AVL_Node));
    // New node is initially added at leaf
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 0; // Leaf height is 0
    return(node);
}

