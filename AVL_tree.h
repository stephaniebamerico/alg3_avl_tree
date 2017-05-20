/*== Stephanie Briere Americo
		GRR20165313 ==*/
/*== Talita Halboth Cunha Fernandes
		GRR20165399 ==*/

#ifndef __AVL_Tree__
#define __AVL_Tree__

typedef struct AVL_Node {
	int key;
    struct AVL_Node *p;
    struct AVL_Node *left;
    struct AVL_Node *right;
    // Height of the node, 
    // the count starts on the sheet 
    // and increases to the root.
    // The height of the sheet is 0.
    unsigned int height; 
} AVL_Node;

void insertNode (AVL_Node *node, int key);
void removeNode (AVL_Node *node, int key); 
AVL_Node* searchNode (AVL_Node *node, int key);

void balance (AVL_Node *node);
AVL_Node* newNode(int key);
AVL_Node rotateLeft (AVL_Node *node);
AVL_Node rotateRight (AVL_Node *node);

#endif