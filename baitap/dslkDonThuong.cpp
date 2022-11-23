#include <stdio.h>
#include <cstdlib>
// #include <bits/stdc++.h>
// using namespace std;
// thư viện tổng quát của C/C++
// 1600205377022
// argibank
struct Node
{
  int data;
  Node *next;
};
struct List
{
  Node *head;
  Node *tail;
};
Node *getNode(int x);
int search(List l, int x);
void Init(List &l);
void addFirst(List &l, Node *pNode);
void AddTail(List &l, Node *node);
void ListAdd(List &l);
int themSau(List &l);

void Del_Head(List &l);
void Del_Tail(List &l);
void Del_All(List &l);
void Del_Node(List &l, int x);

// chu thuoc loai hex
void addListLastSosanh(List &l, int n); // so sanh tuong doi
// duyet danh sach lien ket
void printList(List l);
void sort(List &l);

int xuatBoiX(List l, int x);
int soSanh(List l1, List l2); // phuc vu cho ham addListLastSoSanh
void tachTaiX(List l, List &l1, List &l2, int x);
void gopList(List l1, List l2, List &l3);
void timMinMax(List l, int &min, int &max);
// so luong cua list
int sizeList(List l);
// tham khao
int checkDoiXung(List l); // so sanh tuyet doi

void hoanDoi(List &l1, List &l2); // === chiaChanLe
void xoaTrung(List &l);
int checkCSC(List l);
long sum(List l);
// cach 2 cua hoanDoi
void chiaChanLe(List l1, List l2, List &l3, List &l4);
int main()
{
  List l1, l2, l3, l4;
  int x, vt;
  int boi;
  Init(l1);
  Init(l2);
  Init(l3);
  Init(l4);

  // ListAdd(l1);
  // printf("size list :%d", sizeList(l1));
  // printf("Danh sach 1 vua nhap\n");
  // printList(l1);
  // printf("nhap gia tach tai");
  // scanf("%d", &x);
  // tachTaiX(l1, l2, l3, x);

  // // ListAdd(l2);
  // printf("Danh sach 2 vua nhap\n");
  // printList(l2);
  // // gopList(l1, l2, l3);
  // printf("Danh sach 3 vua nhap\n");
  // printList(l3);
  // sort(l3);
  // printf("Danh sach 3 tang dan\n");
  // printList(l3);

  // ListAdd(l1);
  // printList(l1);
  // sort(l1);
  // printList(l1);
  // xoaTrung(l1);
  // printList(l1);
  // printf("hello world\n");
  // if (checkCSC(l1) == 1)
  //   printf("Danh sach lap thanh cap so cong\n");
  // else
  //   printf("Danh sach khong lap thanh cap so cong\n");
  // printf("sau khi xoa trung");
  // printList(l1);
  // int n;
  // do
  // {
  //   printf("Nhap so phan tu cua node: ");
  //   scanf("%d", &n);
  // } while (n < 4 || n > 6);
  // printf("Nhap so phan tu cua node A: \n");
  // addListLastSosanh(l1, n);
  // printf("Nhap so phan tu cua node B: \n");
  // addListLastSosanh(l2, n);
  // int kq = soSanh(l1, l2);
  // if (kq == 1)
  //   printf("A > B\n");
  // else if (kq == -1)
  //   printf("A < B\n");
  // else if (kq == 0)
  //   printf("A = B\n");
  // int confirm = checkCSC(l1);
  // if (confirm == 1)
  // {
  //   printf("la cap so cong\n");
  // }
  // else
  // {
  //   printf("khong la cap so cong\n");
  // }
  ListAdd(l1);
  printList(l1);
  ListAdd(l2);
  chiaChanLe(l1, l2, l3, l4);
  printf("danh sasch chan\n");
  printList(l3);
  printf("danh sasch le\n");
  printList(l4);
  // printf("tach tu gia tri x: ");
  // scanf("%d", &x);
  // tachTaiX(l1, l2, l3, x);
  // printf("danh sasch 1\n");
  // printList(l2);
  // printf("danh sasch 2\n");
  // printList(l3);
}
Node *getNode(int x)
{
  Node *node = new Node();
  node->data = x;
  node->next = NULL;
  return node;
}
int search(List l, int x)
{
  Node *node = l.head;
  while (node != NULL)
  {
    if (node->data == x)
      return node->data;
    node = node->next;
  }
  return -1;
}
void Init(List &l)
{
  l.head = l.tail = NULL;
}
void addFirst(List &l, Node *pNode)
{
  if (l.head == NULL)
  {
    l.head = pNode;
    l.tail = pNode;
  }
  else
  {
    pNode->next = l.head;
    l.head = pNode;
  }
}
void AddTail(List &l, Node *node)
{
  if (l.head == NULL)
    l.head = l.tail = node;
  else
  {
    l.tail->next = node;
    l.tail = node;
  }
}
void Del_Node(List &l, int x)
{
  Node *p = new Node;
  for (Node *k = l.head; k != NULL; k = k->next)
  {
    if (k->data == x)
    {
      p->next = k->next;
      delete k;
      return;
    }
    p = k;
  }
}
void ListAdd(List &l)
{
  int n, x;
  printf("Nhap so phan tu: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    printf("a[%d]", i + 1);
    scanf("%d", &x);
    AddTail(l, getNode(x));
  }
}

// so sanh list co ca chu va so
void addListLastSosanh(List &l, int n)
{
  char x;
  for (int i = 0; i < n;)
  {
    printf("a[%d] = ", i + 1);
    fflush(stdin);
    scanf("%c", &x);
    if ((x >= '0' && x <= '9') || (x >= 'A' && x <= 'F'))
    {
      i++;
      AddTail(l, getNode(x));
    }
  }
}
void printList(List l)
{
  Node *p = l.head;
  while (p != NULL)
  {
    printf("%d  ", p->data);
    p = p->next;
  }
  printf("\n---------------------\n");
}
int themSau(List &l)
{
  int x, vt;
  printf("nhap gia tri muon them");
  scanf("%d", &x);
  printf("them sau gia tri");
  scanf("%d", &vt);
  Node *p = getNode(x);
  if (vt == l.head->data)
  {
    p->next = l.head;
    l.head = p;
  }
  else
  {
    Node *pNode = l.head;
    while (pNode != NULL && pNode->next != NULL && pNode->data != vt)
    {
      pNode = pNode->next;
    }
    if (pNode == NULL || pNode->next == NULL)
      return 0;

    p->next = pNode->next;
    pNode->next = p;
  }
  return 1;
}
void sort(List &l)
{
  Node *i = l.head, *j;
  // while tham khao
  while (i->next != NULL)
  {
    j = i->next;
    while (j != NULL)
    {
      if (i->data > j->data)
      {
        int tam = i->data;
        i->data = j->data;
        j->data = tam;
      }
      j = j->next;
    }
    i = i->next;
  }

  // nen dung for cho de
  // for (Node *i = l.first; i != l.last; i = i->link)
  // {
  //   for (Node *j = i->link; j != NULL; j = j->link)
  //   {
  //     // if (i->data < j->data) danh cho so
  //     // danh cho string
  //     if (strcmp(i->data.maSV, j->data.maSV) < 0)
  //     {
  //       SinhVien tamp = j->data;
  //       j->data = i->data;
  //       i->data = tamp;
  //     }
  //   }
  // }
}
// xoa dau dslk
void Del_Head(List &l)
{
  if (l.head == NULL)
    return;
  Node *pNode = l.head;

  // null 1  2  3 null
  l.head = l.head->next;
  delete pNode;
}
// xoa cuoi dslk
void Del_Tail(List &l)
{
  if (l.head == NULL)
    return;
  // 1
  // truong hop cho dslk co 1 gia tri duy nhat
  if (l.head->next == NULL)
  {
    Del_Head(l);
    return;
  }
  for (Node *pNode = l.head; pNode != NULL; pNode = pNode->next)
  {
    // 1 2 3 -> null
    // xoa 3
    if (pNode->next == l.tail)
    {
      pNode->next = NULL;
      l.tail = pNode; // NULL
      return;
    }
  }
}
void Del_All(List &l)
{
  if (l.head == NULL)
    return;
  if (l.head->next == NULL)
  {
    Del_Head(l);
    return;
  }
  Node *pNode = l.head;
  Node *link = NULL;
  while (pNode == NULL)
  {
    link = pNode->next;
    free(link);
    pNode = link;
  }
  l.head = NULL;
}
int xuatBoiX(List l, int x)
{
  int kt = 0;
  Node *head = l.head;
  while (head != NULL)
  {
    if (head->data % x == 0)
    {
      printf("%d ", head->data);
      kt = 1;
    }
    head = head->next;
  }
  if (kt)
    printf("\n");
  return kt;
}
int soSanh(List l1, List l2)
{
  Node *p1 = l1.head, *p2 = l2.head;
  while (p1 != NULL)
  {
    if (p1->data > p2->data)
      return 1;
    else if (p1->data < p2->data)
      return -1;
    else
      return 0;
    p1 = p1->next;
    p2 = p2->next;
  }
  return 0;
}
void tachTaiX(List l, List &l1, List &l2, int x)
{
  while (l.head != NULL)
  {
    // l  = [1,2,3,4]
    // x  = 3
    if (l.head->data > x)
      AddTail(l1, getNode(l.head->data));
    else
      AddTail(l2, getNode(l.head->data));
    l.head = l.head->next; // i++
  }
}
// int trungbincong(List l)
// {

//   int count = 0;
//   int trungbinh = 0;
//   for (Node *i = l.head; i != NULL; i = i->next)
//   {
//     trungbinh += i->data;
//     count++;
//   }
//   return trungbinh / count;
// }
void timMinMax(List l, int &min, int &max)
{
  min = l.head->data; // =1
  max = l.head->data; // =1
  Node *head = l.head->next;
  // tro den node 2(dia chi)

  // 1 2 3 4 null
  while (head != NULL)
  {
    // head = 2
    if (head->data > max)
      // max  = 2
      max = head->data;
    else if (head->data < min)
      // min = 1
      min = head->data;
    head = head->next;
    // i++
  }
  printf("\n");
}
int sizeList(List l)
{
  int count = 0;
  while (l.head != NULL)
  {
    count++;
    l.head = l.head->next;
  }
  // for (Node *n = l.head; n != NULL; n = n->next)
  // {
  //   count++
  // }
  return count;
}
int checkDoiXung(List l)
{
  List temp;
  Node *head = l.head;
  Init(temp);
  int size = sizeList(l), k;

  if (size % 2 == 0)
    k = size / 2;
  else
    k = size / 2 + 1;

  while (k--)
    l.head = l.head->next;

  while (l.head != NULL)
  {
    addFirst(temp, getNode(l.head->data));
    l.head = l.head->next;
  }

  while (temp.head != NULL)
  {
    if (temp.head->data != head->data)
      return 0;
    temp.head = temp.head->next;
    head = head->next;
  }
  return 1;
}
void hoanDoi(List &l1, List &l2)
{
  Node *p1 = l1.head, *p2 = l2.head;
  Node *pPre1, *pPre2;
  while (p1 != NULL && p2 != NULL)
  {

    // l1 = 1 2 3 4 5 6 7 8
    // l2 = 9 10 11 12 13 14 15
    // gan gia le cho l1 va chan cho l2
    while (p1->data % 2 == 0 && p1 != NULL)
    {
      pPre1 = p1;
      p1 = p1->next;
    }
    while (p2->data % 2 != 0 && p2 != NULL)
    {
      pPre2 = p2;
      p2 = p2->next;
    }
    if (p1 != NULL && p2 != NULL)
    {
      int tg = p1->data;
      p1->data = p2->data;
      p2->data = tg;
      pPre1 = p1;
      p1 = p1->next;
      pPre2 = p2;
      p2 = p2->next;
    }
  }
  while (p1 != NULL)
  {
    if (p1->data % 2 == 0)
    {
      pPre1->next = p1->next;
      AddTail(l2, getNode(p1->data));
      p1 = p1->next;
    }
    else
    {
      pPre1 = p1;
      p1 = p1->next;
    }
  }
  while (p2 != NULL)
  {
    if (p2->data % 2 != 0)
    {
      pPre2->next = p2->next;
      AddTail(l1, getNode(p2->data));
      p2 = pPre2->next;
    }
    else
    {
      pPre2 = p2;
      p2 = p2->next;
    }
  }
}
void xoaTrung(List &l)
{
  if (l.head == NULL)
    return;
  Node *p = l.head;
  while (p->next != NULL)
  {
    if (p->next->data == p->data)
    {
      if (p->next->next == NULL)
        l.tail = p;
      p->next = p->next->next;
    }
    else
      p = p->next;
    // 1 1 2 3 4
    // 1 2 3 4
  }
}

long sum(List l)
{
  Node *node = l.head;
  int sum = 0;
  while (node != NULL)
  {
    if (node->data % 2 == 0)
    {
      sum += node->data;
    }
    node = node->next;
  }
  return sum;
}
void gopList(List l1, List l2, List &l3)
{

  Node *p;
  p = l1.head;
  // while cua l1
  while (p != NULL)
  {
    AddTail(l3, p);
    p = p->next;
  }
  p = l2.head;
  // while cua l2
  while (p != NULL)
  {
    AddTail(l3, p);
    p = p->next; // i++
  }
}
void chiaChanLe(List l1, List l2, List &l3, List &l4)
{
  // l3 chan l4 le
  while (l1.head != NULL)
  {
    if (l1.head->data % 2 == 0)
    {
      AddTail(l3, getNode(l1.head->data));
    }
    else
      AddTail(l4, getNode(l1.head->data));
    l1.head = l1.head->next;
  }
  while (l2.head != NULL)
  {
    if (l2.head->data % 2 == 0)
    {
      AddTail(l3, getNode(l2.head->data));
    }
    else
      AddTail(l4, getNode(l2.head->data));
    l2.head = l2.head->next;
  }
}
int checkCSC(List l)
{

  // 1 4 7 10
  // d = 3
  Node *p = l.head; // l.head->data
  int d = p->next->data - p->data;
  p = p->next;
  while (p != NULL)
  {
    if (p->data + d != p->next->data)
      return 0;
    p = p->next;
  }
  return 1;
}
/*
Đây là bài code ngoài của chức năng check cấp số cộng chạy đc nhưng bỏ vào bài tổng quát k được
ae coi check coi bài tổng quát thử chứ t check k ra
#include <stdio.h>

struct Node
{
    int data;
    Node *pNext;
};

struct List
{
    Node *pHead;
    Node *pTail;
};

Node* getNode(int x)
{
    Node *pNode = new Node();
    pNode->data = x;
    pNode->pNext = NULL;
    return pNode;
}

void Init(List &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

void addFirst(List &l, Node *pNode)
{
    if (l.pHead == NULL)
    {
        l.pHead = pNode;
        l.pTail = pNode;
    }
    else
    {
        pNode->pNext = l.pHead;
        l.pHead = pNode;
    }
}

void addListFirst(List &l)
{
    int x;
    for (;;)
    {
        printf("x = ");
        scanf("%d", &x);
        if (x <= 0)
            break;
        addFirst(l, getNode(x));
    }
}

void duyetList(List l)
{
    Node *pHead = l.pHead;
    while (pHead != NULL)
    {
        printf("%d ", pHead->data);
        pHead = pHead->pNext;
    }
    printf("\n");
}

void sort(List &l)
{
    Node *i = l.pHead, *j;
    while (i->pNext != NULL)
    {
        j = i->pNext;
        while (j != NULL)
        {
            if (i->data > j->data)
            {
                int tam = i->data;
                i->data = j->data;
                j->data = tam;
            }
            j = j->pNext;
        }
        i = i->pNext;
    }
}

void xoaTrung(List &l)
{
    if (l.pHead == NULL)
        return;
    Node *p = l.pHead;
    while (p->pNext != NULL)
    {
        if (p->pNext->data == p->data)
        {
            if (p->pNext->pNext == NULL)
                l.pTail = p;
            p->pNext = p->pNext->pNext;
        }
        else
            p = p->pNext;
    }
}

int checkCSC(List l)
{
    Node *p = l.pHead;
    int d = p->pNext->data - p->data;
    p = p->pNext;
    while (p->pNext != NULL)
    {
        if (p->data + d != p->pNext->data)
            return 0;
        p = p->pNext;
    }
    return 1;
}

int main()
{
    List l;
    Init(l);
    printf("Nhap List\n");
    addListFirst(l);
    printf("Xuat List\n");
    duyetList(l);
    printf("Sap xep List\n");
    sort(l);
    duyetList(l);
    printf("List sau khi xoa trung\n");
    xoaTrung(l);
    duyetList(l);
    if (checkCSC(l) == 1)
        printf("Danh sach lap thanh cap so cong\n");
    else
        printf("Danh sach khong lap thanh cap so cong\n");
}
*/