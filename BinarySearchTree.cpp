#include <iostream>
#include <queue>
#include <vector>

struct Node
{
    int value;
    int level;
    Node *left;
    Node *right;
    Node(int data) : value(data), level(0), left(nullptr), right(nullptr) {}
};

class BST
{
private:
    Node *root;

public:
    // Finding Longest Branch via Recursion
    int FindLongestBranch()
    {
        std::vector<Node *> q;
        int maxLength = 0;
        q.push_back(root);

        while (!q.empty())
        {
            Node *currentNode = q.back();
            maxLength = currentNode->level;
            q.pop_back();

            if (currentNode->left != nullptr)
            {
                q.push_back(currentNode->left);
                maxLength = std::max(maxLength, currentNode->left->level);
            }
            if (currentNode->right != nullptr)
            {
                q.push_back(currentNode->right);
                maxLength = std::max(maxLength, currentNode->right->level);
            }
        }
        return maxLength;
    }

    // Node Insertion in Binary Search Tree via Loop.
    void InsertNode(int data)
    {
        Node *node = new Node(data);
        if (root == nullptr)
        {
            root = node;
            root->left = 0;
            return;
        }
        else
        {
            Node *tempNode = root;
            while (true)
            {
                if (node->value < tempNode->value)
                {
                    if (tempNode->left != nullptr)
                        tempNode = tempNode->left;
                    else
                    {
                        tempNode->left = node;
                        node->level = tempNode->level + 1;
                        break;
                    }
                }
                else
                {
                    if (tempNode->right != nullptr)
                        tempNode = tempNode->right;
                    else
                    {
                        tempNode->right = node;
                        node->level = tempNode->level + 1;
                        break;
                    }
                }
            }
        }
    }
};

int main()
{
    BST *binaryTree = new BST();
    int longBranchLength = 0;

    binaryTree->InsertNode(8);
    binaryTree->InsertNode(7);
    binaryTree->InsertNode(5);
    binaryTree->InsertNode(11);
    binaryTree->InsertNode(14);
    binaryTree->InsertNode(16);
    binaryTree->InsertNode(6);
    binaryTree->InsertNode(12);
    binaryTree->InsertNode(2);
    binaryTree->InsertNode(1);

    longBranchLength = binaryTree->FindLongestBranch();

    return 0;
}