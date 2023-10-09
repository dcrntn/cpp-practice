#include <stdlib.h>
#include <iostream>

struct node
{
    int value;
    struct node *left, *right;
};
typedef struct node nd;

nd *newNode(int newVal)
{
    nd *tempNode = (nd *)malloc(sizeof(nd));
    tempNode->value = newVal;
    tempNode->left = tempNode->right = NULL;
    return tempNode;
}

nd *insertNode(nd *node, int newVal)
{
    if (node == NULL)
        return newNode(newVal);

    // Checks if the new node needs to be on the right or left;
    if (newVal < node->value)
    {
        node->left = insertNode(node->left, newVal);
    }
    else
    {
        node->right = insertNode(node->right, newVal);
    }

    return node;
}

nd *findMin(nd *node)
{
    nd *curr = node;

    while (curr && curr->left != NULL)
        curr = curr->left;

    return curr;
}

nd *deleteNode(nd *root, int delVal)
{
    if (root == NULL)
        return root;

    // Check for the value to be deleted
    if (delVal < root->value)
    {
        root->left = deleteNode(root->left, delVal);
    }
    else if (delVal > root->value)
    {
        root->right = deleteNode(root->right, delVal);
    }
    // We have the node to delete
    else
    {
        if (root->left == NULL)
        {
            nd *tmp = root->right;
            free(root);
            return tmp;
        }
        else if (root->right == NULL)
        {
            nd *tmp = root->left;
            free(root);
            return tmp;
        }

        nd *tmp = findMin(root->right);

        root->value = tmp->value;
        root->right = deleteNode(root->right, tmp->value);
    }
    return root;
}

void inorder(nd *root)
{
    if (root != NULL)
    {
        inorder(root->left);

        std::cout << root->value << " -> ";

        inorder(root->right);
    }
}

int main()
{

    nd *root = NULL;
    root = insertNode(root, 214);
    root = insertNode(root, 51);
    root = insertNode(root, 2);
    root = insertNode(root, 412);
    root = insertNode(root, 23);
    root = insertNode(root, 52);
    root = insertNode(root, 212);
    root = insertNode(root, 12);

    std::cout << "Traversal: " << std::endl;
    inorder(root);
    std::cout << std::endl;
    root = deleteNode(root, 212);

    std::cout << "After delete traversal: " << std::endl;
    inorder(root);

    return 0;
}