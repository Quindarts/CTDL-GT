#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Node
{
  int data;
  Node *pleft, *pright;
};

typedef Node *TREE;
void Init(TREE &t);
Node *themnodevaocay(TREE &t, int x);
void nhap(TREE &t, int n);
// truoc
void xuat_NLR(TREE t);
// giua
void xuat_LNR(TREE t);
// sau
void xuat_LRN(TREE t);

void xuat_NRL(TREE t);
void xuat_RNL(TREE t);
void xuat_RLN(TREE t);
bool kiemtraSNT(int x);
void soluongSNT(TREE t, int &dem); // xong
Node *timkiem(TREE t, int x);
void xuat_cay_1_con(TREE t);                 // xong
void xuat_cay_2_con(TREE t);                 // xong
void xuat_cay_0_con(TREE t);                 // xong
int timmax(TREE t);                          // xong
int timMin(TREE t);                          // xong
int level_max(TREE t);                       // xong
int level_min(TREE t);                       // xong
void thayThe(TREE &X, TREE &Y);              // xong phục vu cho xóa 2 con
void xoaNode1ConVaNodeLa(TREE &t, int x);    // xong
void Doc_file(char *tenFile, TREE &t);       // xong
void sntNhoNhat(TREE t, int &min);           // xong
void soChinhPhuongLonNhat(TREE t, int &max); // xong
bool ktSoChinhPhuong(int n);                 // xong
int demNode(TREE t);                         // xong
int demNodeLa(TREE t);                       // xong
int Max(int a, int b);                       // xong
int chieuCao(TREE t);                        // xong
int sum(TREE t);                             // xong
int demSoNodeBangX(TREE t, int x);           // xong
int main()
{
  TREE t;
  int n, count = 0;
  Init(t);
  char tenFile[20];
  printf("nhap ten file: ");
  fflush(stdin);
  gets(tenFile);
  Doc_file(tenFile, t);
  printf("truoc: ");
  xuat_NLR(t);
  printf("\n");
  printf("giua: ");
  xuat_LNR(t);
  printf("\n");
  printf("sau: ");
  xuat_LRN(t);
  printf("\n");
  printf("level cua max: %d\n", level_max(t));
  printf("level cua min: %d\n", level_min(t));
  // printf("so node: %d\n", demNode(t));
  // printf("so node la: %d\n", demNodeLa(t));
  // printf("chieu cao = %d\n", chieuCao(t));
  // int dem = 0;
  // soluongSNT(t, dem);
  // printf("\nso luong snt: %d\n", dem);
  // printf("Tong gia tri tren cay la: %d\n", sum(t));
  // printf("\nnhap gia tri x ");
  // int x;
  // scanf("%d", &x);
  // printf("\nso luong node bang x la: %d\n", demSoNodeBangX(t, x));
  // printf("cay 1 con");
  // xuat_cay_1_con(t);
  // printf("\n");
  // printf("cay 2 con");
  // xuat_cay_2_con(t);
  // printf("\n");
  // printf("cay 0 con");
  // xuat_cay_0_con(t);
  // printf("\n");
  // printf("gia tri max la: %d\n", timmax(t));
  // printf("gia tri Min la: %d\n", timMin(t));
  // int k;
  // printf("nhap gia tri can xoa: ");
  // scanf("%d", &k);
  // xoaNode1ConVaNodeLa(t, k);
  // xuat_NLR(t);
}

void Init(TREE &t)
{
  t = NULL;
}
Node *themnodevaocay(TREE &t, int x)
{
  if (t)
  {
    if (t->data == x)
      return 0;
    if (t->data > x)
      return themnodevaocay(t->pleft, x);
    else
      return themnodevaocay(t->pright, x);
  }
  t = new Node;
  if (t == NULL)
  {
    printf("Khong du bo nho!!");
    return NULL;
  }
  t->data = x;
  t->pleft = t->pright = NULL;
  return t;
}

void nhap(TREE &t, int n)
{
  int x;
  printf("nhap so node: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    printf("node %d: ", i + 1);
    scanf("%d", &x);
    themnodevaocay(t, x);
  }
}

void xuat_NRL(TREE t)
{
  if (t != NULL)
  {
    printf("%d ", t->data);
    xuat_NRL(t->pright);
    xuat_NRL(t->pleft);
  }
}
// trước
void xuat_NLR(TREE t)
{
  if (t != NULL)
  {
    printf("%d ", t->data);
    xuat_NLR(t->pleft);
    xuat_NLR(t->pright);
  }
}
// giữa
void xuat_LNR(TREE t) // các phần tử từ nhỏ đến lớn
{
  if (t != NULL)
  {
    xuat_LNR(t->pleft);
    printf("%d ", t->data);
    xuat_LNR(t->pright);
  }
}
// sau
void xuat_LRN(TREE t)
{
  if (t != NULL)
  {
    xuat_LRN(t->pleft);
    xuat_LRN(t->pright);
    printf("%d ", t->data);
  }
}

void xuat_RNL(TREE t) // giảm dần
{
  if (t != NULL)
  {
    xuat_RNL(t->pright);
    printf("%d ", t->data);
    xuat_RNL(t->pleft);
  }
}

void xuat_RLN(TREE t)
{
  if (t != NULL)
  {
    xuat_RLN(t->pright);
    xuat_RLN(t->pleft);
    printf("%d ", t->data);
  }
}

bool kiemtraSNT(int x)
{
  if (x < 2)
    return false;
  else
  {
    if (x == 2)
      return true;
    else
    {
      if (x % 2 == 0)
        return false;
      else
        for (int i = 0; i < x; i++)
          if (x % 2 == 0)
            return false;
    }
  }
  return true;
}

void soluongSNT(TREE t, int &dem)
{
  if (t != NULL)
  {
    soluongSNT(t->pright, dem);
    soluongSNT(t->pleft, dem);
    if (kiemtraSNT(t->data) == true)
    {
      printf("%d ", t->data);
      dem++;
    }
  }
}

Node *timkiem(TREE t, int x)
{
  if (t == NULL)
    return NULL;
  else
  {
    if (x < t->data)
      return timkiem(t->pleft, x);
    else if (x > t->data)
      return timkiem(t->pright, x);
    else
      return t;
  }
}

void xuat_cay_1_con(TREE t)
{
  if (t != NULL)
  {
    if ((t->pleft != NULL && t->pright == NULL) || (t->pright != NULL && t->pleft == NULL))
      printf("%d ", t->data);

    xuat_cay_1_con(t->pright);
    xuat_cay_1_con(t->pleft);
  }
}

void xuat_cay_2_con(TREE t)
{
  if (t != NULL)
  {
    if ((t->pleft != NULL && t->pright != NULL))
      printf("%d ", t->data);

    xuat_cay_2_con(t->pright);
    xuat_cay_2_con(t->pleft);
  }
}

void xuat_cay_0_con(TREE t) // node lá
{
  if (t != NULL)
  {
    if ((t->pleft == NULL && t->pright == NULL))
      printf("%d ", t->data);

    xuat_cay_0_con(t->pright);
    xuat_cay_0_con(t->pleft);
  }
}

int timmax(TREE t)
{
  if (t->pright == NULL)
    return t->data;
  return timmax(t->pright);
}

int timMin(TREE t)
{
  if (t->pleft == NULL)
    return t->data;
  return timMin(t->pleft);
}

void ThayThe(TREE &X, TREE &Y)
{
  // tìm cây theo bên phải
  if (Y->pright != NULL)
  {
    ThayThe(X, Y->pright);
  }
  else
  {
    X->data = Y->data;
    X = Y;
    Y = Y->pleft;
  }
  // tìm theo cây bên trái
  // if (Y->pleft != NULL)
  // {
  //   ThayThe(X, Y->pleft);
  // }
  // else
  // {
  //   X->data = Y->data;
  //   X = Y;
  //   Y = Y->pright;
  // }
}

void xoaNode1ConVaNodeLa(TREE &t, int x)
{
  if (t == NULL)
    return;
  else
  {
    if (x < t->data)
      xoaNode1ConVaNodeLa(t->pleft, x);
    else if (x > t->data)
      xoaNode1ConVaNodeLa(t->pright, x);
    else
    {
      Node *X = t;
      if (t->pleft == NULL)
        t = t->pright;
      else if (t->pright == NULL)
        t = t->pleft;
      else
      {
        // xóa node có 2 node con
        ThayThe(X, t->pleft);  // tim theo ben phai
        ThayThe(X, t->pright); // tim theo ben trai
      }
      delete X;
    }
  }
}

void Doc_file(char *tenFile, TREE &t)
{

  FILE *fp;
  int x;
  fp = fopen(tenFile, "r+");
  if (fp == NULL)
  {
    printf("\n Khong mo duoc ");
    exit(0);
  }
  while (!feof(fp))
  {
    fscanf(fp, "%d", &x);
    themnodevaocay(t, x);
  }
}

void sntNhoNhat(TREE t, int &min)
{
  if (t != NULL)
  {
    sntNhoNhat(t->pright, min);
    sntNhoNhat(t->pleft, min);
    if (kiemtraSNT(t->data) == true)
    {
      int min1 = timMin(t);
      min = min1;
    }
  }
}

bool ktSoChinhPhuong(int n)
{
  if (n <= 0)
    return 0;
  int s = sqrt(n);
  if (s * s == n)
    return 1;
  return 0;
}

void soChinhPhuongLonNhat(TREE t, int &max)
{
  if (t != NULL)
  {
    soChinhPhuongLonNhat(t->pleft, max);
    soChinhPhuongLonNhat(t->pright, max);
    if (ktSoChinhPhuong(t->data) == 1)
    {
      int max1 = timmax(t);
      max = max1;
    }
  }
}
// dem so luong node
int demNode(TREE t)
{
  if (t == NULL)
    return 0;
  else
    return demNode(t->pleft) + demNode(t->pright) + 1;
}
// dem so luong node la
int demNodeLa(TREE t)
{
  if (t == NULL)
    return 0;
  else if (t->pright == NULL && t->pleft == NULL)
  {
    return 1;
  }
  else
    return demNodeLa(t->pleft) + demNodeLa(t->pright);
}

int Max(int a, int b)
{
  if (a > b)
    return a;
  else
    return b;
}
// chieu cao cay
int chieuCao(TREE t)
{
  if (t == NULL)
    return 0;
  else
    // giáo trình
    return Max(chieuCao(t->pleft), chieuCao(t->pright)) + 1;

  // làm trưc tiếp
  // if (t == NULL)
  //   return 0;
  // int a = ChieuCao(t->pLeft);
  // // trả về level node
  // int b = ChieuCao(t->pRight);
  // if (a > b)
  //   return a + 1;
  // else
  //   return b + 1;
}

int sum(TREE t)
{

  if (t == NULL)
    return 0;
  else
    return sum(t->pright) + sum(t->pleft) + t->data;
}
// int sumNodeLa(TREE t)
// {
//   if (t == NULL)
//     return 0;
//   if (t->pright == NULL && t->pleft == NULL)
//     return t->data;
//   else
//     return sum(t->pright) + sum(t->pleft);
// }
int demSoNodeBangX(TREE t, int x)
{
  if (t == NULL)
    return 0;
  if (t->data == x)
    return 1 + demSoNodeBangX(t->pleft, x) + demSoNodeBangX(t->pright, x);
  else if (t->data < x)
    return demSoNodeBangX(t->pright, x);
  return demSoNodeBangX(t->pleft, x);
}
// tim level
int level_max(TREE t)
{
  if (t != NULL)
  {
    if (t->pleft == NULL)
      return t->pright ? 1 : 0;
    return level_max(t->pleft);
  }
  else
    return -1;
}

int level_min(TREE t)
{
  if (t != NULL)
  {
    if (t->pleft == NULL)
      return t->pright ? 1 : 0;
    return level_min(t->pleft);
  }
  else
    return -1;
}