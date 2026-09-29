#include <stdio.h>
#include <string.h>

int main() {
    // =========================
    // 1. KHAI BÁO MẢNG
    // =========================
    int MAX = 100;

    char maPhieu[100][15];
    char tenSach[100][50];
    int soNgayMuon[100];
    int tienPhat[100];

    int soLuong = 0;
    int luaChon;

    // =========================
    // MENU CHÍNH
    // =========================
    do {
        printf("\n");
        printf("============================================================\n");
        printf("       HE THONG QUAN LY MUON TRA SACH (LIBRARY_WMS)\n");
        printf("============================================================\n");
        printf("1. Them luot muon sach moi\n");
        printf("2. Hien thi danh sach muon sach\n");
        printf("3. Cap nhat so ngay muon theo Ma phieu\n");
        printf("4. Xoa luot muon sach theo Ma phieu\n");
        printf("5. Thong ke danh sach phieu muon bi phat\n");
        printf("6. Thoat chuong trinh\n");
        printf("============================================================\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {

            // ====================================================
            // CHỨC NĂNG 1: THÊM PHIẾU MƯỢN
            // ====================================================
            case 1: {
                if (soLuong >= MAX) {
                    printf("\nHe thong day, khong the them phieu muon moi!\n");
                    break;
                }

                printf("\n");
                printf("========== THEM LUOT MUON SACH MOI ==========\n");

                // Nhập mã phiếu
                char maNhap[15];
                int trungMa;

                do {
                    trungMa = 0;

                    printf("Nhap ma phieu muon: ");
                    scanf("%14s", maNhap);

                    // Tìm mã bị trùng
                    for (int i = 0; i < soLuong; i++) {
                        if (strcmp(maPhieu[i], maNhap) == 0) {
                            trungMa = 1;
                            break;
                        }
                    }

                    if (trungMa == 1) {
                        printf("Ma phieu da ton tai! Vui long nhap ma khac.\n");
                    }

                } while (trungMa == 1);

                // Lưu mã phiếu
                strcpy(maPhieu[soLuong], maNhap);

                // Xóa bộ đệm trước khi dùng fgets()
                while (getchar() != '\n');

                // Nhập tên sách
                printf("Nhap ten sach: ");
                fgets(tenSach[soLuong], 50, stdin);

                // Xóa '\n'
                if (strlen(tenSach[soLuong]) > 0 &&
                    tenSach[soLuong][strlen(tenSach[soLuong]) - 1] == '\n') {

                    tenSach[soLuong][strlen(tenSach[soLuong]) - 1] = '\0';
                }

                // Nhập số ngày mượn
                do {
                    printf("Nhap so ngay muon thuc te: ");
                    scanf("%d", &soNgayMuon[soLuong]);

                    if (soNgayMuon[soLuong] <= 0) {
                        printf("So ngay muon phai lon hon 0! Vui long nhap lai.\n");
                    }

                } while (soNgayMuon[soLuong] <= 0);

                // Tính tiền phạt
                tienPhat[soLuong] =
                    (soNgayMuon[soLuong] > 14)
                    ? (soNgayMuon[soLuong] - 14) * 5000
                    : 0;

                printf("--> Tien phat tu dong tinh: %d VNĐ\n",
                       tienPhat[soLuong]);

                // Tăng số lượng
                soLuong++;

                printf("--> Them luot muon sach thanh cong!\n");

                break;
            }

            // ====================================================
            // CHỨC NĂNG 2: HIỂN THỊ DANH SÁCH
            // ====================================================
            case 2: {
                if (soLuong == 0) {
                    printf("\nDanh sach muon sach hien dang rong!\n");
                    break;
                }

                printf("\n");
                printf("========================== DANH SACH MUON SACH ==========================\n");

                printf("%-5s | %-10s | %-35s | %-10s | %-15s\n",
                       "STT",
                       "Ma Phieu",
                       "Ten Sach",
                       "So Ngay",
                       "Tien Phat");

                printf("-------------------------------------------------------------------------------\n");

                int tongTienPhat = 0;

                for (int i = 0; i < soLuong; i++) {

                    printf("%-5d | %-10s | %-35s | %-10d | %-15d\n",
                           i + 1,
                           maPhieu[i],
                           tenSach[i],
                           soNgayMuon[i],
                           tienPhat[i]);

                    tongTienPhat += tienPhat[i];
                }

                printf("-------------------------------------------------------------------------------\n");

                printf("Tong tien phat toan he thong: %d VNĐ\n",
                       tongTienPhat);

                break;
            }

            // ====================================================
            // CHỨC NĂNG 3: CẬP NHẬT
            // ====================================================
            case 3: {
                if (soLuong == 0) {
                    printf("\nDanh sach muon sach hien dang rong!\n");
                    break;
                }

                printf("\n");
                printf("========== CAP NHAT SO NGAY MUON ==========\n");

                char maNhap[15];
                int index = -1;

                printf("Nhap ma phieu muon can cap nhat: ");
                scanf("%14s", maNhap);

                // Tìm vị trí phiếu
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maNhap) == 0) {
                        index = i;
                        break;
                    }
                }

                // Không tìm thấy
                if (index == -1) {
                    printf("Khong tim thay phieu muon co ma: %s\n",
                           maNhap);
                }
                else {
                    printf("Tim thay phieu muon cua sach: %s\n",
                           tenSach[index]);

                    printf("So ngay hien tai: %d\n",
                           soNgayMuon[index]);

                    // Nhập số ngày mới
                    do {
                        printf("Nhap so ngay muon thuc te moi: ");
                        scanf("%d", &soNgayMuon[index]);

                        if (soNgayMuon[index] <= 0) {
                            printf("So ngay muon phai lon hon 0! Vui long nhap lai.\n");
                        }

                    } while (soNgayMuon[index] <= 0);

                    // Tính lại tiền phạt
                    tienPhat[index] =
                        (soNgayMuon[index] > 14)
                        ? (soNgayMuon[index] - 14) * 5000
                        : 0;

                    printf("--> Tien phat moi: %d VNĐ\n",
                           tienPhat[index]);

                    printf("--> Cap nhat so ngay muon thanh cong!\n");
                }

                break;
            }

            // ====================================================
            // CHỨC NĂNG 4: XÓA
            // ====================================================
            case 4: {
                if (soLuong == 0) {
                    printf("\nDanh sach muon sach hien dang rong!\n");
                    break;
                }

                printf("\n");
                printf("========== XOA LUOT MUON SACH ==========\n");

                char maNhap[15];
                int index = -1;

                printf("Nhap ma phieu muon can xoa: ");
                scanf("%14s", maNhap);

                // Tìm vị trí cần xóa
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maNhap) == 0) {
                        index = i;
                        break;
                    }
                }

                // Không tìm thấy
                if (index == -1) {
                    printf("Khong tim thay phieu muon co ma: %s\n",
                           maNhap);
                }
                else {

                    // Dồn mảng
                    for (int i = index; i < soLuong - 1; i++) {

                        strcpy(maPhieu[i], maPhieu[i + 1]);

                        strcpy(tenSach[i], tenSach[i + 1]);

                        soNgayMuon[i] = soNgayMuon[i + 1];

                        tienPhat[i] = tienPhat[i + 1];
                    }

                    // Giảm số lượng
                    soLuong--;

                    printf("--> Xoa phieu muon thanh cong!\n");
                }

                break;
            }

            // ====================================================
            // CHỨC NĂNG 5: THỐNG KÊ PHIẾU BỊ PHẠT
            // ====================================================
            case 5: {
                if (soLuong == 0) {
                    printf("\nDanh sach muon sach hien dang rong!\n");
                    break;
                }

                printf("\n");
                printf("========== DANH SACH PHIEU MUON BI PHAT ==========\n");

                int coPhieuBiPhat = 0;

                printf("%-5s | %-10s | %-35s | %-10s | %-15s\n",
                       "STT",
                       "Ma Phieu",
                       "Ten Sach",
                       "So Ngay",
                       "Tien Phat");

                printf("-------------------------------------------------------------------------------\n");

                for (int i = 0; i < soLuong; i++) {

                    if (soNgayMuon[i] > 14) {

                        printf("%-5d | %-10s | %-35s | %-10d | %-15d\n",
                               i + 1,
                               maPhieu[i],
                               tenSach[i],
                               soNgayMuon[i],
                               tienPhat[i]);

                        coPhieuBiPhat = 1;
                    }
                }

                printf("-------------------------------------------------------------------------------\n");

                if (coPhieuBiPhat == 0) {
                    printf("Khong co luot muon nao bi qua han phat!\n");
                }

                break;
            }

            case 6: {
                printf("\nCam on ban da su dung LIBRARY_WMS!\n");
                printf("Thoat chuong trinh...\n");
                break;
            }
            default: {
                printf("\nLua chon khong hop le. Vui long thu lai!\n");
                break;
            }
        }
    } while (luaChon != 6);
    return 0;
}