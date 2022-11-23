#include <stdio.h>
#include <string.h>
#define MAX 20
struct SINHVIEN
{
  char hoten[30], MaSV[12];
};
void nhap_N_SinhVien(SINHVIEN dssv[], int &n);
void nhap1SinhVien(SINHVIEN &sv);
void xuat_N_SinhVien(SINHVIEN dssv[], int n);
void xuat1SinhVien(SINHVIEN sv);
void timSV(SINHVIEN dssv[], int n);
void sapGiamDTB(SINHVIEN dssv[], int n);
void sapTangHoTen(SINHVIEN dssv[], int n);
void sapTangMa(SINHVIEN dssv[], int n)
{
  SINHVIEN tam;
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
      if (stricmp(dssv[i].MaSV, dssv[j].MaSV) > 0)
      {
        tam = dssv[i];
        dssv[i] = dssv[j];
        dssv[j] = tam;
      }
}

// dung khi danh sach da sap xep
int BinarySearch(SINHVIEN dssv[], int n, char ma[])
{

  int left, right, mid;
  left = 0;
  right = n - 1;
  while (left <= right)
  {
    mid = (left + right) / 2;
    if (stricmp(dssv[mid].MaSV, ma) == 0)
      return mid; // tìm thấy x, trả về mid là vị trí của x trong mảng A
    if (stricmp(dssv[mid].MaSV, ma) > 0)
      right = mid - 1; // Giới hạn khoảng tìm kiếm lại là nửa khoảng trước
    else if (stricmp(dssv[mid].MaSV, ma) < 0)
      left = mid + 1; // Giới hạn khoảng tìm kiếm lại là nửa khoảng sau
  }
  return -1;
}
void xoa1SV(SINHVIEN dssv[], int &n)
{
  char maSV[12];
  int vt;
  printf("\nNhap ma SV can xoa: ");
  fflush(stdin);
  gets(maSV);
  vt = BinarySearch(dssv, n, maSV);
  if (vt == -1)
    printf("Khong tm thay SV can xoa\n");
  else // tim thay tai vt
  {
    // tien hanh xoa
    for (int i = vt; i < n - 1; i++)
      dssv[i] = dssv[i + 1];
    n--;
  }
}
// hàm tìm kiếm nãy chỉ sử dụng tối ưu khi chưa sắp xếp
int timMaSV(SINHVIEN dssv[], int n, char maSV[])
{
  for (int i = 0; i < n; i++)
    if (stricmp(dssv[i].MaSV, maSV) == 0)
    {
      return i;
    }
  return -1;
}
// tìm kiếm nhị phân dưới đây chỉ được dùng khi đã được sắp xếp và tối ưu nhất

int main()
{
  SINHVIEN dssv[MAX];
  int n, x, a = 10;
  nhap_N_SinhVien(dssv, n);
  printf("Ds sinh vien vua nhap:\n");
  xuat_N_SinhVien(dssv, n);
  sapTangMa(dssv, n);
  xuat_N_SinhVien(dssv, n);
  char ma[12];
  printf("Nhap ma can tim: ");
  fflush(stdin);
  gets(ma);
  int vitri = BinarySearch(dssv, n, ma);
  if (vitri == -1)
    printf("khong tim thay: %s", ma);
  else
    printf(" tim thay: %s", ma);
  xoa1SV(dssv, n);
  xuat_N_SinhVien(dssv, n);
}
void nhap_N_SinhVien(SINHVIEN dssv[], int &n)
{
  printf("Nhap so sinh vien: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    nhap1SinhVien(dssv[i]);
}
void nhap1SinhVien(SINHVIEN &sv)
{
  printf("Nhap MaSV: ");
  fflush(stdin);
  gets(sv.MaSV);
  printf("Nhap ho ten: ");
  gets(sv.hoten);
}
void xuat_N_SinhVien(SINHVIEN dssv[], int n)
{
  int i;
  for (i = 1; i <= 34; i++)
    printf("-");
  printf("\n");
  printf("|%-5s|%-15s|%-10s|\n", "STT", "HO TEN", "MA SV");
  for (i = 1; i <= 34; i++)
    printf("-");
  printf("\n");
  for (i = 0; i < n; i++)
  {
    printf("|%-5d", i + 1);
    xuat1SinhVien(dssv[i]);
  }
}
//-----------------------
void xuat1SinhVien(SINHVIEN sv)
{
  printf("|%-15s|%-10s|\n", sv.hoten, sv.MaSV);
  for (int i = 1; i <= 34; i++)
    printf("-");
  printf("\n");
}

void timSV(SINHVIEN dssv[], int n)
{
  char ma[12];
  int i, co = 0;
  printf("Nhap ma can tim: ");
  fflush(stdin);
  gets(ma);
  for (i = 0; i < n; i++)
    if (stricmp(dssv[i].MaSV, ma) == 0)
    {
      co = 1;
      printf("Hoten : %s\n", dssv[i].hoten);
      printf("Ma SV : %s\n", dssv[i].MaSV);
      break;
    }
  if (co == 0)
    printf("Khong tim thay SV co ma: %s\n", ma);
}

void sapTangHoTen(SINHVIEN dssv[], int n)
{
  SINHVIEN tam;
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
      if (stricmp(dssv[i].hoten, dssv[j].hoten) > 0)
      {
        tam = dssv[i];
        dssv[i] = dssv[j];
        dssv[j] = tam;
      }
}
