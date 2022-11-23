#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <bits/stdc++.h>

using namespace std;

struct Ngay
{
  int ngay, thang, nam;
};
struct SinhVien
{
  char maSV[10];
  char hoTen[50];
  int gioiTinh;
  Ngay ngaySinh;
  char diaChi[100];
  char lop[12];
  char khoa[7];
};

struct Node
{
  SinhVien data;
  Node *link;
};
struct List
{
  Node *first;
  Node *last;
};
Node *getNode(SinhVien sv);
Node *Search(List l, char d[]);
void Init(List &l);
void AddLast(List &l, Node *new_ele);
void InsertLast(List &l, SinhVien sv);
void AddFirst(List &l, Node *new_ele);
void InsertFirst(List &l, SinhVien sv);
void InsertLast_KhongTrung(List &l, SinhVien sv);
void InsertAfter(List &l, int p, int index);

int NhapSV(SinhVien &sv);
void NhapDSSV(List &l);
void xuatSV(SinhVien sv);
void xuatDSSV(List l);

void Delete_Head(List &l);
void Delete_Tail(List &l);
void XoaSauNode_q(List &l, Node *q);
void Delete_Node(List &l, char d[]);
void InterChangeSortListByName(List &l);
void InterChangeSortListById(List &l);

void tachList(List l, List &l1, List &l2, char maLop[]);
void gopList(List l1, List l2, List &l3);
int tong(List l)
{
  int tong = 0;
  for (Node *i = l.first; i != NULL; i = i->link)
  {
    tong++;
  }
  return tong;
}
int main()
{
  List l, l1, l2, l3;
  Init(l);
  Init(l1);
  Init(l2);
  NhapDSSV(l1);
  printf("danh sach 1\n");
  xuatDSSV(l1);
  printf("tong so luong%d", tong(l1));

  // NhapDSSV(l2);
  // printf("danh sach 2\n");
  // xuatDSSV(l2);
  // Init(l3);
  // gopList(l1, l2, l3);
  // InterChangeSortListByName(l);
  // xuatDSSV(l);
  // xuatDSSV(l3);
  // InterChangeSortListById(l3);
  // xuatDSSV(l3);
  // char maLop[10];
  // printf("Nhap lop muon tachList");
  // fflush(stdin);
  // gets(maLop);
  // tachList(l, l1, l2, maLop);
  char d[100];
  // do
  // {
  //   printf("Nhap ma so sinh vien cua sinh vien ban muon xoa(bam 0 de thoat): ");
  //   fflush(stdin);
  //   gets(d);
  //   Delete_Node(l, d);
  // } while (strcmp(d, "0") != 0);

  // xuatDSSV(l);
  // printf("\n");
  // xuatDSSV(l1);
  // printf("\n");
  // xuatDSSV(l2);
  // printf("\n");
}
Node *getNode(SinhVien sv)
{
  Node *p = new Node();
  if (p == NULL)
    return NULL;

  p->data = sv;
  p->link = NULL;
  return p;
}

Node *Search(List l, char d[])
{
  Node *p;
  p = l.first;
  while (p != NULL)
  {
    if (strcmp(p->data.maSV, d) == 0)
      return p;
    p = p->link;
  }
  return NULL;
};

void Init(List &l)
{
  l.first = l.last = NULL;
}
void AddFirst(List &l, Node *new_ele)
{
  if (l.first == NULL)
  {
    l.first = new_ele;
    l.last = l.first;
  }
  else
  {
    new_ele->link = l.first;
    l.first = new_ele;
  }
}

void AddLast(List &l, Node *new_ele)
{

  if (l.first == NULL)
  {
    l.last = new_ele;
    l.first = l.last;
  }

  else
  {
    l.last->link = new_ele;
    l.last = new_ele;
  }
}

int NhapSV(SinhVien &sv)
{
  printf("ma sinh vien: ");
  fflush(stdin);
  gets(sv.maSV);
  if (strcmp(sv.maSV, "0") == 0)
    return 0;
  printf("ho va ten: ");
  gets(sv.hoTen);
  printf("gioi tinh: ");
  scanf("%d", &sv.gioiTinh);
  printf("ngay thang nam sinh:  ");
  scanf("%d%d%d", &sv.ngaySinh.ngay, &sv.ngaySinh.thang, &sv.ngaySinh.nam);
  printf("dia chi:  ");
  fflush(stdin);
  gets(sv.diaChi);
  printf("lop: ");
  gets(sv.lop);
  printf("khoa: ");
  gets(sv.khoa);
  return 1;
}

void NhapDSSV(List &l)
{
  printf("\nBat dau nhap DSSV nhap 0 de dung\n");
  SinhVien sv;
  int flag = NhapSV(sv);
  while (flag)
  {
    InsertLast_KhongTrung(l, sv);
    flag = NhapSV(sv);
  }
  printf("Ket thuc nhap DSSV\n");
}

void xuatSV(SinhVien sv)
{
  char gt[4];
  if (sv.gioiTinh == 0)
    strcpy(gt, "Nam");
  else
    strcpy(gt, "Nu");
  printf("%-10s%-20s%-15s%-d/%-d/%-10d%-10s%-8s%-10s\n", sv.maSV, sv.hoTen, gt, sv.ngaySinh.ngay, sv.ngaySinh.thang, sv.ngaySinh.nam, sv.diaChi, sv.lop, sv.khoa);
}
void xuatDSSV(List l)
{
  Node *p = l.first;
  for (int i = 0; i < 84; i++)
  {
    printf("=");
  }
  printf("\n");
  printf("%-10s%-20s%-15s%-15s%-10s%-9s%-10s", "MSSV", "Ho va Ten", "Gioi Tinh", "Ngay Sinh", "Dia Chi", "Lop", "Khoa");
  printf("\n");
  while (p)
  {
    xuatSV(p->data);
    p = p->link;
  }
}

void InsertLast_KhongTrung(List &l, SinhVien sv)
{
  if (Search(l, sv.maSV) == NULL)
    InsertLast(l, sv);
}
void InsertLast(List &l, SinhVien sv)
{
  Node *new_ele = getNode(sv);
  if (new_ele == NULL)
    return;
  AddLast(l, new_ele);
}
void InsertFirst(List &l, SinhVien sv)
{
  Node *new_ele = getNode(sv);
  if (new_ele == NULL)
    return;
  AddFirst(l, new_ele);
}
void Delete_Head(List &l)
{
  if (l.first == NULL)
  {
    return;
  }
  Node *p = l.first;
  l.first = l.first->link;
  delete p;
}
void Delete_Tail(List &l)
{
  if (l.first == NULL)
    return;
  if (l.first->link == NULL)
  {
    Delete_Head(l);
    return;
  }
  for (Node *k = l.first; k != NULL; k = k->link)
  {
    if (k->link == l.last)
    {
      delete l.first;
      k->link = NULL;
      l.last = k;
      return;
    }
  }
}
void XoaSauNode_q(List &l, Node *q)
{
  for (Node *k = l.first; k != NULL; k = k->link)
  {
    if (strcmp(k->data.maSV, q->data.maSV) == 0)
    {
      Node *g = k->link;
      k->link = g->link;
      delete g;
    }
  }
}
void Delete_Node(List &l, char d[])
{
  if (l.first == NULL)
    return;
  if (strcmp(l.first->data.maSV, d) == 0)
  {
    Delete_Head(l);
    return;
  }
  if (strcmp(l.last->data.maSV, d) == 0)
  {
    Delete_Tail(l);
    return;
  }
  Node *g = new Node;
  for (Node *k = l.first; k != NULL; k = k->link)
  {
    if (strcmp(k->data.maSV, d) == 0)
    {
      g->link = k->link;
      delete k;
      return;
    }
    g = k;
  }
}
void InterChangeSortListByName(List &l)
{
  for (Node *i = l.first; i != l.last; i = i->link)
  {
    for (Node *j = i->link; j != NULL; j = j->link)
    {
      if (strcmp(i->data.hoTen, j->data.hoTen) > 0)
      {
        SinhVien tamp = j->data;
        j->data = i->data;
        i->data = tamp;
      }
    }
  }
}
void InterChangeSortListById(List &l)
{
  for (Node *i = l.first; i != l.last; i = i->link)
  {
    for (Node *j = i->link; j != NULL; j = j->link)
    {
      if (strcmp(i->data.maSV, j->data.maSV) < 0)
      {
        SinhVien tamp = j->data;
        j->data = i->data;
        i->data = tamp;
      }
    }
  }
}

void tachList(List l, List &l1, char phuong[], char quan[])
{
  Node *p = l.first;
  while (l.first != NULL)
  {
    // malop = a
    if (stricmp(p->data.lop, phuong) == 0 && stricmp(p->data.lop, quuan) == 0)
    {
      Them_Cuoi(l1, p);
    }
    l.first = l.first->link; // i++
  }
}
void gopList(List l1, List l2, List &l3)
{
  Node *p;
  p = l1.first;
  while (p != NULL)
  {
    AddLast(l3, p);
    p = p->link;
  }
  p = l2.first;
  while (p != NULL)
  {
    AddLast(l3, p);
    p = p->link;
  }
}