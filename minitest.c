#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100
#define MAX_HOA_DON 20

typedef struct {
    char ma[11];
    char ten[41];
    char donViTinh[11];
    double donGia;
    int soLuong;
} SanPham;

typedef struct {
    char ma[11];
    char ten[41];
    char donViTinh[11];
    double donGia;
    int soLuong;
    double thanhTien;
} DongHoaDon;

void nhapChuoi(char chuoi[], int kichThuoc, char thongBao[]) {
    do {
        printf("%s", thongBao);

        if (fgets(chuoi, kichThuoc, stdin) == NULL) {
            chuoi[0] = '\0';
            return;
        }

        chuoi[strcspn(chuoi, "\n")] = '\0';

        if (strchr(chuoi, '\n') == NULL && !feof(stdin)) {
            int kyTu;
            while ((kyTu = getchar()) != '\n' && kyTu != EOF) {
            }
        }

        if (strlen(chuoi) == 0) {
            printf("Khong duoc de trong!\n");
        }

    } while (strlen(chuoi) == 0);
}

int nhapSoNguyen(char thongBao[]) {
    char dong[100];
    int giaTri;
    char kyTuThua;

    while (1) {
        printf("%s", thongBao);

        if (fgets(dong, sizeof(dong), stdin) == NULL) {
            return 0;
        }

        if (strchr(dong, '\n') == NULL && !feof(stdin)) {
            int kyTu;
            while ((kyTu = getchar()) != '\n' && kyTu != EOF) {
            }
        }

        if (sscanf(dong, " %d %c", &giaTri, &kyTuThua) == 1) {
            return giaTri;
        }

        printf("Du lieu khong hop le, vui long nhap lai!\n");
    }
}

double nhapSoThuc(char thongBao[]) {
    char dong[100];
    double giaTri;
    char kyTuThua;

    while (1) {
        printf("%s", thongBao);

        if (fgets(dong, sizeof(dong), stdin) == NULL) {
            return 0;
        }

        if (strchr(dong, '\n') == NULL && !feof(stdin)) {
            int kyTu;
            while ((kyTu = getchar()) != '\n' && kyTu != EOF) {
            }
        }

        if (sscanf(dong, " %lf %c", &giaTri, &kyTuThua) == 1) {
            return giaTri;
        }

        printf("Du lieu khong hop le, vui long nhap lai!\n");
    }
}

int timViTri(SanPham ds[], int n, char ma[]) {
    int i;

    for (i = 0; i < n; i++) {
        if (strcmp(ds[i].ma, ma) == 0) {
            return i;
        }
    }

    return -1;
}

void inThongTin(SanPham sp) {
    printf("\nMa san pham : %s\n", sp.ma);
    printf("Ten san pham: %s\n", sp.ten);
    printf("Don vi tinh : %s\n", sp.donViTinh);
    printf("Don gia     : %.2f VND\n", sp.donGia);
    printf("So luong ton: %d\n", sp.soLuong);
    printf("Gia tri ton : %.2f VND\n",
           sp.donGia * sp.soLuong);
}

void themSanPham(SanPham ds[], int *n) {
    SanPham sp;

    if (*n >= MAX_SIZE) {
        printf("Danh sach da day!\n");
        return;
    }

    nhapChuoi(sp.ma, sizeof(sp.ma), "Nhap ma san pham: ");

    if (strcmp(sp.ma, "0") == 0) {
        printf("Ma 0 duoc danh rieng de ket thuc ban hang!\n");
        return;
    }

    if (timViTri(ds, *n, sp.ma) != -1) {
        printf("Ma san pham da ton tai!\n");
        return;
    }

    nhapChuoi(sp.ten, sizeof(sp.ten), "Nhap ten san pham: ");
    nhapChuoi(sp.donViTinh, sizeof(sp.donViTinh),
              "Nhap don vi tinh: ");

    do {
        sp.donGia = nhapSoThuc("Nhap don gia: ");

        if (sp.donGia <= 0) {
            printf("Don gia phai lon hon 0!\n");
        }
    } while (sp.donGia <= 0);

    do {
        sp.soLuong = nhapSoNguyen("Nhap so luong ton: ");

        if (sp.soLuong < 0) {
            printf("So luong khong duoc am!\n");
        }
    } while (sp.soLuong < 0);

    ds[*n] = sp;
    (*n)++;

    printf("Them san pham thanh cong!\n");
}

void hienThiDanhSach(SanPham ds[], int n) {
    int i;

    printf("\n%-4s %-10s %-40s %-10s %12s %8s %15s\n", "STT", "Ma", "Ten san pham", "DVT", "Don gia", "SL ton", "Gia tri ton");

    printf("---------------------------------------------------------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%-4d %-10s %-40s %-10s %12.2f %8d %15.2f\n",
               i + 1,
               ds[i].ma,
               ds[i].ten,
               ds[i].donViTinh,
               ds[i].donGia,
               ds[i].soLuong,
               ds[i].donGia * ds[i].soLuong);
    }
}

void timSanPham(SanPham ds[], int n) {
    char ma[11];
    int viTri;

    nhapChuoi(ma, sizeof(ma), "Nhap ma can tim: ");

    viTri = timViTri(ds, n, ma);

    if (viTri == -1) {
        printf("Khong tim thay!\n");
    } else {
        inThongTin(ds[viTri]);
    }
}

void capNhatSanPham(SanPham ds[], int n) {
    char ma[11];
    int viTri;
    int soLuongNhap;
    double giaMoi;

    nhapChuoi(ma, sizeof(ma), "Nhap ma san pham: ");

    viTri = timViTri(ds, n, ma);

    if (viTri == -1) {
        printf("Khong tim thay san pham!\n");
        return;
    }

    inThongTin(ds[viTri]);

    do {
        giaMoi = nhapSoThuc("Nhap don gia moi: ");

        if (giaMoi <= 0) {
            printf("Don gia phai lon hon 0!\n");
        }
    } while (giaMoi <= 0);

    do {
        soLuongNhap = nhapSoNguyen("Nhap so luong nhap them: ");

        if (soLuongNhap < 0) {
            printf("So luong nhap them khong duoc am!\n");
        }
    } while (soLuongNhap < 0);

    ds[viTri].donGia = giaMoi;
    ds[viTri].soLuong += soLuongNhap;

    printf("Cap nhat thanh cong!\n");
    inThongTin(ds[viTri]);
}

void xoaSanPham(SanPham ds[], int *n) {
    char ma[11];
    int viTri;
    int i;

    nhapChuoi(ma, sizeof(ma), "Nhap ma san pham can xoa: ");

    viTri = timViTri(ds, *n, ma);

    if (viTri == -1) {
        printf("Khong tim thay san pham!\n");
        return;
    }

    for (i = viTri; i < *n - 1; i++) {
        ds[i] = ds[i + 1];
    }

    (*n)--;

    printf("Xoa san pham thanh cong!\n");
}

void banHang(SanPham ds[], int n, int *soHoaDon, double *tongDoanhThu) {
    DongHoaDon hd[MAX_HOA_DON];
    char ma[11];
    int viTri;
    int soLuongMua;
    int soDong = 0;
    int i;

    double tongTien = 0;
    double giamGia = 0;
    double tienPhaiTra;

    printf("\n========== BAN HANG ==========\n");
    printf("Nhap ma 0 de ket thuc ban hang.\n");

    while (1) {
        if (soDong >= MAX_HOA_DON) {
            printf("Hoa don da dat toi da 20 dong!\n");
            break;
        }

        nhapChuoi(ma, sizeof(ma), "Nhap ma san pham: ");

        if (strcmp(ma, "0") == 0) {
            break;
        }

        viTri = timViTri(ds, n, ma);

        if (viTri == -1) {
            printf("Ma san pham khong ton tai!\n");
        } else if (ds[viTri].soLuong == 0) {
            printf("San pham da het hang!\n");
        } else {
            soLuongMua = nhapSoNguyen("Nhap so luong mua: ");

            if (soLuongMua <= 0) {
                printf("So luong mua phai lon hon 0!\n");
            } else if (soLuongMua > ds[viTri].soLuong) {
                printf("Khong du hang trong kho!\n");
            } else {
                strcpy(hd[soDong].ma, ds[viTri].ma);
                strcpy(hd[soDong].ten, ds[viTri].ten);
                strcpy(hd[soDong].donViTinh, ds[viTri].donViTinh);
                      
                hd[soDong].donGia = ds[viTri].donGia;
                hd[soDong].soLuong = soLuongMua;
                hd[soDong].thanhTien = hd[soDong].donGia * soLuongMua;
                   
                tongTien += hd[soDong].thanhTien;

                ds[viTri].soLuong -= soLuongMua;
                soDong++;

                printf("Them vao hoa don thanh cong!\n");
            }
        }
    }

    if (soDong == 0) {
        printf("Khong co san pham nao duoc ban.\n");
        return;
    }

    if (tongTien >= 500000) {
        giamGia = tongTien * 0.10;
    }

    tienPhaiTra = tongTien - giamGia;

    printf("\n================ HOA DON ================\n");
    printf("%-10s %-40s %10s %8s %15s\n", "Ma", "Ten san pham", "Don gia", "SL", "Thanh tien");
          
    for (i = 0; i < soDong; i++) {
        printf("%-10s %-40s %10.2f %8d %15.2f\n",
               hd[i].ma,
               hd[i].ten,
               hd[i].donGia,
               hd[i].soLuong,
               hd[i].thanhTien);
    }

    printf("------------------------------------------\n");
    printf("Tong tien hang : %.2f VND\n", tongTien);
    printf("Giam gia       : %.2f VND\n", giamGia);
    printf("Tien phai tra  : %.2f VND\n", tienPhaiTra);
    printf("==========================================\n");

    (*soHoaDon)++;
    *tongDoanhThu += tienPhaiTra;

    printf("Da cap nhat ton kho va doanh thu!\n");
}

void sapHetHang(SanPham ds[], int n) {
    int i;
    int timThay = 0;

    printf("\nCac san pham co so luong ton duoi 5:\n");

    for (i = 0; i < n; i++) {
        if (ds[i].soLuong < 5) {
            inThongTin(ds[i]);
            timThay = 1;
        }
    }

    if (timThay == 0) {
        printf("Khong co san pham sap het hang!\n");
    }
}

void sapXepTheoGia(SanPham ds[], int n) {
    int i, j;
    SanPham tam;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (ds[j].donGia > ds[j + 1].donGia) {
                tam = ds[j];
                ds[j] = ds[j + 1];
                ds[j + 1] = tam;
            }
        }
    }

    printf("Sap xep theo don gia tang dan thanh cong!\n");
    hienThiDanhSach(ds, n);
}

void thongKe(SanPham ds[], int n, int soHoaDon, double tongDoanhThu) {
    int i;
    double tongGiaTriTon = 0;
    double giaCaoNhat;

    for (i = 0; i < n; i++) {
        tongGiaTriTon += ds[i].donGia * ds[i].soLuong;
    }

    printf("\n========== THONG KE ==========\n");
    printf("So mat hang             : %d\n", n);
    printf("Tong gia tri ton kho     : %.2f VND\n", tongGiaTriTon);
    printf("So hoa don da ban        : %d\n", soHoaDon);
    printf("Tong doanh thu           : %.2f VND\n", tongDoanhThu);
          
    giaCaoNhat = ds[0].donGia;

    for (i = 1; i < n; i++) {
        if (ds[i].donGia > giaCaoNhat) {
            giaCaoNhat = ds[i].donGia;
        }
    }

    printf("\nSan pham co don gia cao nhat:\n");

    for (i = 0; i < n; i++) {
        if (ds[i].donGia == giaCaoNhat) {
            inThongTin(ds[i]);
        }
    }

    printf("===============================\n");
}

void hienThiMenu() {
    printf("\n====== QUAN LY CUA HANG ======\n");
    printf("1. Them san pham\n");
    printf("2. Hien thi danh sach san pham\n");
    printf("3. Tim san pham theo ma\n");
    printf("4. Cap nhat gia / nhap them hang\n");
    printf("5. Xoa san pham\n");
    printf("6. Ban hang va in hoa don\n");
    printf("7. Danh sach san pham sap het hang\n");
    printf("8. Sap xep theo don gia tang dan\n");
    printf("9. Thong ke\n");
    printf("0. Thoat\n");
    printf("==============================\n");
}

int main() {
    SanPham ds[MAX_SIZE];
    int n = 0;
    int luaChon;

    int soHoaDon = 0;
    double tongDoanhThu = 0;

    do {
        hienThiMenu();
        luaChon = nhapSoNguyen("Chon: ");

        if (luaChon >= 2 && luaChon <= 9 && n == 0) {
            printf("Chua co san pham nao, hay chon 1 truoc.\n");
        } else {
            switch (luaChon) {
                case 1:
                    themSanPham(ds, &n);
                    break;

                case 2:
                    hienThiDanhSach(ds, n);
                    break;

                case 3:
                    timSanPham(ds, n);
                    break;

                case 4:
                    capNhatSanPham(ds, n);
                    break;

                case 5:
                    xoaSanPham(ds, &n);
                    break;

                case 6:
                    banHang(ds, n, &soHoaDon, &tongDoanhThu);
                    break;

                case 7:
                    sapHetHang(ds, n);
                    break;

                case 8:
                    sapXepTheoGia(ds, n);
                    break;

                case 9:
                    thongKe(ds, n, soHoaDon, tongDoanhThu);
                    break;

                case 0:
                    printf("Da thoat chuong trinh!\n");
                    break;

                default:
                    printf("Lua chon khong hop le!\n");
            }
        }

    } while (luaChon != 0);

    return 0;
}
