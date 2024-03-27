#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
    int val;
    struct node_t *left;
    struct node_t *right;
} node;

node *CreateNode(int val)
{
    node *NewNode = (node *)malloc(sizeof(node));
    NewNode->val = val;
    NewNode->left = NULL;
    NewNode->right = NULL;
    return NewNode;
}

node *insertNode(node *root, int val)
{
    if (root == NULL)
    {
        root = CreateNode(val);
    }
    else
    {
        if (root->val > val) // new val is less than root, insert left
        {
            root->left = insertNode(root->left, val);
        }
        else if (root->val < val) // insert right
        {
            root->right = insertNode(root->right, val);
        }
        else
        {
            // same value is not allow
            printf("same value is not allow.\n");
        }
    }
    return root;
}

/*delete function with 3 case:
    1. the node has NO child. //leave node
        直接刪掉就可以
    2. the node has one child.

    3. the node has two children.
        find max in left subtree or find min in right subtree
*/
node *deleteNode(node *root, int target)
{
    if (!root)
    {
        return root;
    }
    else if (target < root->val)
    { // 往左找
        root->left = deleteNode(root->left, target);
    }
    else if (target > root->val)
    { // 往右找
        root->right = deleteNode(root->right, target);
    }
    else // 找到了
    {
        // case 1 NO child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
            return root;
        }
        // case 2 1 child
        else if (root->left && root->right == NULL)
        {
            node *temp = root;
            root = root->left;
            free(temp);
            return root;
        }
        else if (root->left == NULL && root->right)
        {
            node *temp = root;
            root = root->right;
            free(temp);
            return root;
        }
        // case 3 2 children
        else if (root->left && root->right)
        {
            // find min at right subtree
            node *temp = root->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }

    return root;
}

int treeMAX(node *root)
{
    node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->val;
}

int treeMIN(node *root)
{
    node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->val;
}

int treeHeight(node *root)
{
    // 要比較左右子樹的高度
    if (!root)
    {
        return 0;
    }

    // left subtree depth
    int depth_left = treeHeight(root->left);
    // right subtree depth
    int depth_right = treeHeight(root->right);

    if (depth_left > depth_right)
        return depth_left + 1;
    else
        return depth_right + 1;
}

int searchNode(node *root, int target)
{
    if (!root)
    {
        return -1;
    }
    node *cur = root;
    while (cur)
    {
        if (cur->val > target)
        {
            cur = cur->left;
        }
        else if (cur->val < target)
        {
            cur = cur->right;
        }
        else
        {
            return cur->val;
        }
    }
    return -1;
}

void preorder(node *root)
{
    if (!root)
    {
        return;
    }
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root)
{
    if (!root)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

void postorder(node *root)
{
    if (!root)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

int main()
{
    node *root = NULL;
    /*

                10
            7       11
          3            12
             5            14
          4     6
    */

    root = insertNode(root, 10);
    insertNode(root, 7);
    insertNode(root, 3);
    insertNode(root, 5);
    insertNode(root, 4);
    insertNode(root, 6);
    insertNode(root, 11);
    insertNode(root, 12);
    insertNode(root, 14);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    printf("%d \n", searchNode(root, 7));
    printf("%d \n", searchNode(root, 3));
    printf("%d \n", searchNode(root, 12));
    printf("MAX = %d \n", treeMAX(root));
    printf("MIN = %d \n", treeMIN(root));
    printf("Height = %d \n", treeHeight(root));
    deleteNode(root, 10);
    printf("Height = %d \n", treeHeight(root));
    deleteNode(root, 4);
    deleteNode(root, 6);
    printf("Height = %d \n", treeHeight(root));
    // delete function
}