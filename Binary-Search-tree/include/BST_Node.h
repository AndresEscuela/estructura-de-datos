#pragma once


typedef struct BSTNode
{
    int element;
    struct BSTNode* ptr_leftNode;
    struct BSTNode* ptr_rigthNode;
} BST_Node;

BST_Node* getPtr_InitializedNode(int);
