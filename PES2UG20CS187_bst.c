// Name:Manodnya K H
// SRN:PES2UG20CS187
#include "bst.h"
#include <stdlib.h>

/*
 ** Do not use global variables.
 ** Mark any functions that you declare in this file that are not in the header as static
 ** Do not use static variables
 ** All occurences of count_ptr indicate that the number of comparison
 ** operations need to be stored in the location pointed by it
 ** The implementation can assume it is initialized to 0.
 */

// Initializes the root of the bst
void init_bst(bst_t *bst)
{
    bst = malloc(sizeof(bst_t));
}

static struct node_t *minValueNode(node_t *node)
{
    node_t *current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Inserts element key into the Binary search tree
// Stores the number of comparisons at the location
// pointed by count_ptr
void insert(bst_t *tree, int key, int *count_ptr)
{
    if (!tree->root)
    {
        init_bst(tree);
        tree->root->key = key;
    }

    if (tree->root->key < key)
    {
        insert(tree->root->right, key, count_ptr++);
    }
    else
    {
        insert(tree->root->left, key, count_ptr++);
    }
    return;
}

// Delete key from the BST
// Replaces node with in-order successor
void delete_element(bst_t *tree, int key, int *count_ptr)
{
    if (tree->root == NULL)
    {
        return;
    }
    else if (key > tree->root->key)
    {
        delete_element(tree->root->right, key, count_ptr++);
    }
    else
    {
        if (tree->root->left == NULL)
        {
            node_t *temp = tree->root->right;
            free(tree->root);
            return;
        }
        else if (tree->root->left == NULL)
        {
            free(tree->root);
            return;
        }
        bst_t *tree1;
        node_t *temp = minValueNode(tree->root->right);
        tree->root->key = temp->key;
        delete_element(tree->root->right, key, count_ptr++);
    }
    return;
}

// Searches for the element key in the bst
// Returns the element if found, else -1
int search(const bst_t *tree, int key, int *count_ptr)
{
}

// Returns the maximum element in the BST
int find_max(const bst_t *tree, int *count_ptr)
{
    if (tree->root->right==NULL)
    {
       return (tree->root);
    }else
    {
        return(find_max(tree->root->right, count_ptr++));
    }
    return(-1);
}

// Deletes all the elements of the bst
void free_bst(bst_t *bst)
{
    if (bst->root->left==NULL && bst->root->right==NULL)
    {
        free(bst->root);
        return;
    }else{
        if (bst->root->left!=NULL)
        {
            free_bst(bst->root->left);
        }
        free_bst(bst->root->left);
    }
    return;
}

// Deletes all the elements if the bst and ensures it can be used again
void clear_bst(bst_t *bst)
{
    free_bst(bst);
    free(bst);
}

