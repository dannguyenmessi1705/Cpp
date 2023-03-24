#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *Next;
} typedef NODE;
struct list
{
    NODE *Head;
    NODE *Tail;
} typedef LIST;

void KhoiTaoDS(LIST &l)
{
    l.Head = NULL;
    l.Tail = NULL;
}

NODE *KhoiTaoNode(int x)
{
    NODE *p = new NODE;
    if (p == NULL)
    {
        cout << "\t\tKhong du bo nho!!";
        return NULL;
    }
    p->data = x;
    p->Next = NULL;
    return p;
}

void ThemVaoDau(LIST &l, NODE *p)
{
    if (l.Head == NULL)
    {
        l.Head = l.Tail = p;
    }
    else
    {
        p->Next = l.Head;
        l.Head = p;
    }
}
void ThemVaoCuoi(LIST &l, NODE *p)
{
    if (l.Head == NULL)
        l.Head = l.Tail = p;
    else
    {
        l.Tail->Next = p;
        l.Tail = p;
    }
}

void ThemNodePVaoSauNodeQ(LIST &l, NODE *p, int x)
{
    NODE *q = KhoiTaoNode(x);
    if (q->data == l.Head->data && l.Head->Next == NULL)
    {
        ThemVaoCuoi(l, p);
    }
    else
    {
        for (NODE *k = l.Head; k != NULL; k = k->Next)
        {
            if (q->data == k->data)
            {
                if (k->Next == NULL)
                {
                    ThemVaoCuoi(l, p);
                    break;
                }
                NODE *h = KhoiTaoNode(p->data);
                NODE *tmp = k->Next;
                h->Next = tmp;
                k->Next = h;
            }
        }
    }
}

// Ham xoa NODE dau tien
void XoaDau(LIST &l)
{
    if (l.Head == NULL)
    {
        return;
    }
    NODE *p = l.Head;
    l.Head = l.Head->Next;
    delete p;
}

void XoaCuoi(LIST &l)
{
    if (l.Head == NULL)
    {
        return;
    }
    else if (l.Head->Next == NULL)
    {
        XoaDau(l);
        return;
    }
    else
    {
        NODE *p = l.Tail;
        for (NODE *k = l.Head; k != NULL; k = k->Next)
        {
            if (k->Next == p)
            {
                k->Next = NULL;
                delete p;
                l.Tail = k;
                return;
            }
        }
    }
}

void XoaNodeSauNodeQ(LIST &l, NODE *q, int value)
{

    if (l.Head->data == q->data && l.Head->Next == NULL)
    {
        return;
    }

    for (NODE *k = l.Head; k != NULL; k = k->Next)
    {
        if (k->Next == NULL && k->data == q->data)
        {
            return;
        }
        if (k->data == q->data && k->Next->data == value)
        {
            NODE *tmp = k->Next;
            k->Next = tmp->Next;
            delete tmp;
            return;
        }
    }
}

void XuatDS(LIST l)
{
    for (NODE *k = l.Head; k != NULL; k = k->Next)
    {
        cout << k->data << " ";
    }
    cout << endl;
}

int main()
{
    LIST l;
    KhoiTaoDS(l);
    ThemVaoDau(l, KhoiTaoNode(7));
    ThemVaoDau(l, KhoiTaoNode(1));
    ThemVaoDau(l, KhoiTaoNode(3));
    ThemVaoDau(l, KhoiTaoNode(2));
    ThemVaoDau(l, KhoiTaoNode(8));
    cout << "DS ban dau: ";
    XuatDS(l);
    system("pause");
    // Them vao dau
    ThemVaoDau(l, KhoiTaoNode(10));
    cout << "DS sau khi them 10 vao dau: ";
    XuatDS(l);
    system("pause");
    // Them vao cuoi
    ThemVaoCuoi(l, KhoiTaoNode(10));
    cout << "DS sau khi them 10 vao cuoi: ";
    XuatDS(l);
    system("pause");
    // Them vao sau Node Q = 3
    ThemNodePVaoSauNodeQ(l, KhoiTaoNode(10), 3);
    cout << "DS sau khi them 10 vao sau Node 3: ";
    XuatDS(l);
    system("pause");
    // Xoa Node 8 sau Node 10
    XoaNodeSauNodeQ(l, KhoiTaoNode(10), 8);
    cout << "DS sau khi xoa Node 8 sau Node 10: ";
    XuatDS(l);
    system("pause");
    // Xoa Node 7 sau Node 1
    XoaNodeSauNodeQ(l, KhoiTaoNode(1), 7);
    cout << "DS sau khi xoa Node 7 sau Node 1: ";
    XuatDS(l);
    system("pause");
    // Xoa Node 3 sau Node 2
    XoaNodeSauNodeQ(l, KhoiTaoNode(2), 3);
    cout << "DS sau khi xoa Node 3 sau Node 2: ";
    XuatDS(l);
}