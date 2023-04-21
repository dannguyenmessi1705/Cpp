#include <bits/stdc++.h>
using namespace std;

struct NODE
{
    int number;
    NODE *Next;
};
NODE *InitNode(int data)
{
    NODE *p = new NODE;
    if (p == NULL)
    {
        return NULL;
    }
    p->number = data;
    p->Next = NULL;
    return p;
}

void printList(NODE *&head)
{
    NODE *temp = head;
    while (temp != NULL)
    {
        cout << temp->number;
        temp = temp->Next;
    }
    cout << endl;
}

NODE *ReverseList(NODE *head)
{
    NODE *prev = NULL;
    NODE *current = head;
    NODE *next = NULL;

    while (current != NULL)
    {
        next = current->Next;
        current->Next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

NODE *Multiply(NODE *&number1, int number2)
{
    NODE *result = NULL;
    NODE *tail = NULL;
    NODE *temp1 = number1;
    int carry = 0;

    while (temp1 != NULL || carry != 0)
    {
        int product = carry + (temp1 != NULL ? temp1->number * number2 : 0);
        carry = product / 10;
        product %= 10;

        NODE *newNode = InitNode(product);
        if (result == NULL)
        {
            result = tail = newNode;
        }
        else
        {
            tail->Next = newNode;
            tail = tail->Next;
        }

        if (temp1 != NULL)
        {
            temp1 = temp1->Next;
        }
    }

    return result;
}

NODE *Power(int x, int n)
{
    NODE *result = InitNode(1);
    for (int i = 0; i < n; ++i)
    {
        result = Multiply(result, x);
    }
    return result;
}

int main()
{
    int x, n;
    cout << "X = ";
    cin >> x;
    cout << "N = ";
    cin >> n;

    NODE *result = Power(x, n);
    result = ReverseList(result);
    cout << "Result of " << x << "^" << n << " = ";
    printList(result);
}