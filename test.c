#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
/*
Description:
    Given an integer array nums, return true if any value appears at least twice
    in the array, and return false if every element is distinct.

*/
struct hash_node
{
    int val;
    struct hash_node *next;
};

struct hash_node *InsertHash(struct hash_node *hash, int val)
{
    struct hash_node *newNode = (struct hash_node *)malloc(sizeof(struct hash_node));
    newNode->val = val;
    newNode->next = NULL;
    if (!hash)
    {
        hash = newNode;
    }
    else
    {
        hash = newNode;
    }
    return hash;
}

bool containsDuplicate(int *nums, int numsSize)
{
    struct hash_node *hash_table[100] = {0};
    int index = 0;
    for (int i = 0; i < numsSize; i++)
    {
        index = abs(nums[i] % 100);
        if (!hash_table[index])
            hash_table[index] = InsertHash(hash_table[index], nums[i]);
        else
        {
            // check duplicate
            struct hash_node *head = hash_table[index];
            while (head)
            {
                if (head->val == nums[i])
                    return true;
                else
                    head = head->next;
            }
            hash_table[index] = InsertHash(hash_table[index], nums[i]);
        }
    }
    return 0;
}
int main()
{
    int nums[45] = {46, -961, 788, -98, 591, -624, 247, -991, 590, 637, -693, -647, -710, -30, 268, 486,
                    -753, 140, -873, -332, 398, 62, 87, 138, -11, 607, 591, -782, 809, 148, -883, -491, -608, -432,
                    -913, 582, -799, 40, -73, 151, -942, 557, 831, 869, -870};
    containsDuplicate(nums, 45);
    return 0;
}