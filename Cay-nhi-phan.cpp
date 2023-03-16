#include <iostream>

using namespace std;

// Dinh nghia cau truc Node cho cay nhi phan tim kiem
struct Node
{
    int data;
    int height;
    Node *left;
    Node *right;
};

// Ham tao Node moi
Node *createNode(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int getHeight(Node *root)
{
    if (root == NULL)
        return 0;
    // return 1 + max(getHeight(root->left), getHeight(root->right));
    return root->height;
}
// Ham quay trai
Node *rotateLeft(Node *node)
{
    Node *rightChild = node->right;
    node->right = rightChild->left;
    rightChild->left = node;
    // Thiet lap chieu cao
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    rightChild->height = 1 + max(getHeight(rightChild->left), getHeight(rightChild->right));
    return rightChild;
}

// Ham quay phai
Node *rotateRight(Node *node)
{
    Node *leftChild = node->left;
    node->left = leftChild->right;
    leftChild->right = node;
    // Thiet lap chieu cao
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    leftChild->height = 1 + max(getHeight(leftChild->left), getHeight(leftChild->right));
    return leftChild;
}

// Ham them Node vao cay tim kiem
Node *insert(Node *root, int value)
{
    if (root == NULL)
    { // Neu cay rong, tao Node moi cho goc cay
        return createNode(value);
    }
    if (value < root->data)
    { // Neu gia tri can them nho hon gia tri cua Node goc, them vao cay con trai
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    { // Neu gia tri can them lon hon gia tri cua Node goc, them vao cay con phai
        root->right = insert(root->right, value);
    }
    else
        return root;
    // Thiet lap chieu cao
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    // Rotate
    int valBalance = getHeight(root->left) - getHeight(root->right);
    // Kiem tra 4 TH xay ra lam cay khong deu
    // 3.1. Left left
    if (valBalance > 1 && value < root->left->data)
        return rotateRight(root);

    // 3.2. Right Right
    if (valBalance < -1 && value > root->right->data)
        return rotateLeft(root);

    // 3.3. Left Right
    if (valBalance > 1 && value > root->left->data)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // 3.4. Right Left
    if (valBalance < -1 && value < root->right->data)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
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

// Ham loai bo Node co gia tri x tren cay tim kiem
Node *xoaNode(Node *root, int x)
{
    if (root == NULL)
    { // Neu cay rong, khong lam gi ca
        return root;
    }
    if (x < root->data)
    { // Neu gia tri can xoa nho hon gia tri cua Node goc, tim va xoa Node trong cay con trai
        root->left = xoaNode(root->left, x);
    }
    else if (x > root->data)
    { // Neu gia tri can xoa lon hon gia tri cua Node goc, tim va xoa Node trong cay con phai
        root->right = xoaNode(root->right, x);
    }
    else
    { // Neu gia tri can xoa bang gia tri cua Node goc
        if (root->left == NULL && root->right == NULL)
        { // Neu Node khong co Node con, xoa Node nay
            delete root;
            root = NULL;
        }
        else if (root->left == NULL)
        { // Neu Node chi co cay con phai, thay the Node nay bang cay con phai
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        { // Neu Node chi co cay con trai, thay the Node nay bang cay con trai
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {                                                   // Neu Node co ca cay con trai va cay con phai
            Node *temp = findMinNode(root->right);          // Tim Node co gia tri nho nhat tren cay con phai
            root->data = temp->data;                        // Thay the gia tri cua Node can xoa bang gia tri cua Node tim duoc
            root->right = xoaNode(root->right, temp->data); // Xoa Node co gia tri nho nhat tren cay con phai
        }
    }
    return root;
}

// Ham tim kiem Node co gia tri x tren cay tim kiem
Node *timNode(Node *root, int x)
{
    if (root == NULL || root->data == x)
    { // Neu cay rong hoac Node hien thi co gia tri bang gia tri can tim, tro ve Node hien tai
        return root;
    }
    if (x < root->data)
    { // Neu gia tri can tim nho hon gia tri cua Node hien tai, tim tren cay con traii
        return timNode(root->left, x);
    }
    else
    { // Neu gia tri can tim lon hon gia tri cua Node hien tai, tim tren cay con phai
        return timNode(root->right, x);
    }
}

// Duyet cay nhi phan
void duyettruoc(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    cout << node->data << " ";
    duyettruoc(node->left);
    duyettruoc(node->right);
}

void duyetgiua(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    duyetgiua(node->left);
    cout << node->data << " ";
    duyetgiua(node->right);
}

void duyetsau(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    duyetsau(node->left);
    duyetsau(node->right);
    cout << node->data << " ";
}

int main()
{
    Node *root = NULL;
    int choice, value;
    while (true)
    {
        system("cls");
        cout << "\n\t\t====================MENU========================";
        cout << "\n\t\t|  1. Them Node vao cay                        |";
        cout << "\n\t\t|  2. Xoa Node khoi cay                        |";
        cout << "\n\t\t|  3. Tim Node trong cay                       |";
        cout << "\n\t\t|  4. Duyet cay theo thu tu truoc              |";
        cout << "\n\t\t|  5. Duyet cay theo thu tu giua               |";
        cout << "\n\t\t|  6. Duyet cay theo thu tu sau                |";
        cout << "\n\t\t|  7. Thoat                                    |";
        cout << "\n\t\t================================================";
        cout << "\n\t\tVui long nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\t\tNhap gia tri Node muon them: ";
            cin >> value;
            root = insert(root, value);
            break;
        case 2:
            cout << "\t\tNhap gia tri Node muon xoa: ";
            cin >> value;
            root = xoaNode(root, value);
            break;
        case 3:
            cout << "\t\tNhap gia tri Node muon tim kiem: ";
            cin >> value;
            if (timNode(root, value) == NULL)
            {
                cout << "\t\tKhong tim thay Node co gia tri " << value << " tren cay." << endl
                     << "\t\t";
                system("pause");
            }
            else
            {
                cout << "\t\tTim thay Node co gia tri " << value << " tren cay." << endl
                     << "\t\t";
                system("pause");
            }
            break;
        case 4:
            if (root == NULL)
            {
                cout << "\t\tCay nhi phan rong\n\t\t";
                system("pause");
            }
            else
            {
                cout << "\t\tCac Node tren cay theo thu tu truoc la: ";
                duyettruoc(root);
                cout << endl
                     << "\t\t";
                system("pause");
            }
            break;
        case 5:
            cout << "\t\tCac Node tren cay theo thu tu giua la: ";
            duyetgiua(root);
            cout << endl
                 << "\t\t";
            system("pause");
            break;
        case 6:
            cout << "\t\tCac Node tren cay theo thu tu sau la: ";
            duyetsau(root);
            cout << endl
                 << "\t\t";
            system("pause");
            break;
        case 7:
            cout << "\t\tXin chao!";
            exit(0);

        default:
            cout << "\t\tLua chon khong hop le, vui long chon lai." << endl
                 << "\t\t";
            system("pause");
        }
    }

    return 0;
}
