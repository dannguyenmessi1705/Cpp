#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    return root;
}

Node *findMinNode(Node *node)
{
    Node *current = node;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

Node *xoaNode(Node *root, int x)
{
    if (root == NULL)
    {
        return root;
    }
    if (x < root->data)
    {
        root->left = xoaNode(root->left, x);
    }
    else if (x > root->data)
    {
        root->right = xoaNode(root->right, x);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            Node *temp = findMinNode(root->right);
            root->data = temp->data;
            root->right = xoaNode(root->right, temp->data);
        }
    }
    return root;
}

Node *timNode(Node *root, int x)
{
    if (root == NULL || root->data == x)
    {
        return root;
    }
    if (x < root->data)
    {
        return timNode(root->left, x);
    }
    else
    {
        return timNode(root->right, x);
    }
}

void print(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    cout << node->data << " ";
    print(node->left);
    print(node->right);
}

int main()
{
    int value;
    Node *root = NULL;
    // Them node co thu tu
    cout << "Tao cay bang cach them node co thu tu: 8, 3, 5, 2, 20, 11, 30, 9, 18, 4";
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 20);
    root = insert(root, 11);
    root = insert(root, 30);
    root = insert(root, 9);
    root = insert(root, 18);
    root = insert(root, 4);
    // tim node x = 11
    cout << "\nTim node 11!!!";
    if (timNode(root, 11) == NULL)
    {
        cout << "\nKhong tim thay Node co gia tri 20 tren cay." << endl;
    }
    else
    {
        cout << "\nTim thay Node co gia tri 20 tren cay." << endl;
    }
    // Them node x = 1
    cout << "Them node 1!!!";
    root = insert(root, 1);
    // Xoa node 20
    cout << "\nXoa node 3!!!";
    root = xoaNode(root, 3);
    cout << endl;
    // Hien thi gia tri cay
    cout << "Gia tri cua cay: ";
    print(root);
    cout << endl;
    // Tim nut trai nhat cua cay ben trai
    Node *tmp = findMinNode(root->right);
    int minleft = tmp->data;
    cout << "Nut trai nhat cua cay ben phai la: " << minleft;
    return 0;
}
