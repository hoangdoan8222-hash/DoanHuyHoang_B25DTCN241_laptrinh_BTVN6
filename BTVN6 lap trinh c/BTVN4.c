#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char maSach[MAX][20];
    char tenSach[MAX][100];

    int tongSoLuong[MAX];
    int dangMuon[MAX];
    float giaBia[MAX];

    int soLuong = 0;

    int luaChon;
    int i;
    int pos;
    int soLuongNhap;
    int soLuongTra;
    int soNgayQuaHan;
    int khaDung;
    int thaoTac;

    int tongBanSach;
    int tongDangMuon;

    float tongGiaTri;
    float tienPhat;

    char maNhap[20];

    do {
        printf("\n");
        printf("===========================================================\n");
        printf("           HE THONG QUAN LY KHO SACH\n");
        printf("===========================================================\n");
        printf("1. Them dau sach moi vao kho\n");
        printf("2. Hien thi danh sach kho sach\n");
        printf("3. Ghi nhan Muon / Tra sach va tinh phi phat\n");
        printf("4. Xoa dau sach khoi he thong kho\n");
        printf("5. Thong ke tong gia tri tai san kho sach\n");
        printf("0. Thoat chuong trinh\n");
        printf("===========================================================\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        while (getchar() != '\n');

        switch (luaChon) {
            case 1:
                if (soLuong >= MAX) {
                    printf("Kho sach da day, khong the them moi!\n");
                    break;
                }

                printf("\n=== THEM DAU SACH MOI ===\n");

                printf("Nhap ma sach: ");
                scanf("%19s", maNhap);

                while (getchar() != '\n');

                pos = -1;

                for (i = 0; i < soLuong; i++) {
                    if (strcmp(maSach[i], maNhap) == 0) {
                        pos = i;
                        break;
                    }
                }

                if (pos != -1) {
                    printf("Ma sach da ton tai trong he thong!\n");
                    break;
                }

                strcpy(maSach[soLuong], maNhap);

                printf("Nhap ten sach: ");
                fgets(tenSach[soLuong], 100, stdin);

                tenSach[soLuong][strcspn(tenSach[soLuong], "\n")] = '\0';

                do {
                    printf("Nhap tong so luong: ");
                    scanf("%d", &tongSoLuong[soLuong]);

                    while (getchar() != '\n');

                    if (tongSoLuong[soLuong] <= 0) {
                        printf("Tong so luong phai lon hon 0!\n");
                    }

                } while (tongSoLuong[soLuong] <= 0);

                do {
                    printf("Nhap gia bia (VNÐ): ");
                    scanf("%f", &giaBia[soLuong]);

                    while (getchar() != '\n');

                    if (giaBia[soLuong] <= 0) {
                        printf("Gia bia phai lon hon 0!\n");
                    }

                } while (giaBia[soLuong] <= 0);

                dangMuon[soLuong] = 0;

                soLuong++;

                printf("Them dau sach moi thanh cong!\n");

                break;

            case 2:
                if (soLuong == 0) {
                    printf("Kho sach hien dang rong!\n");
                    break;
                }

                printf("\n");
                printf("==============================================================================================\n");
                printf("                         DANH SACH KHO SACH\n");
                printf("==============================================================================================\n");

                printf("%-5s %-12s %-30s %-10s %-12s %-12s %-15s\n",
                       "STT",
                       "Ma Sach",
                       "Ten Sach",
                       "Tong SL",
                       "Dang Muon",
                       "Kha Dung",
                       "Gia Bia");

                printf("----------------------------------------------------------------------------------------------\n");

                for (i = 0; i < soLuong; i++) {
                    khaDung = tongSoLuong[i] - dangMuon[i];

                    printf("%-5d %-12s %-30s %-10d %-12d %-12d %.2f VNÐ\n",
                           i + 1,
                           maSach[i],
                           tenSach[i],
                           tongSoLuong[i],
                           dangMuon[i],
                           khaDung,
                           giaBia[i]);
                }

                printf("==============================================================================================\n");

                break;

            case 3:
                if (soLuong == 0) {
                    printf("Kho sach hien dang rong!\n");
                    break;
                }

                printf("\n=== GHI NHAN MUON / TRA SACH ===\n");

                printf("Nhap ma sach can thao tac: ");
                scanf("%19s", maNhap);

                while (getchar() != '\n');

                pos = -1;

                for (i = 0; i < soLuong; i++) {
                    if (strcmp(maSach[i], maNhap) == 0) {
                        pos = i;
                        break;
                    }
                }

                if (pos == -1) {
                    printf("Khong tim thay ma sach trong he thong!\n");
                    break;
                }

                printf("Tim thay sach: %s (Dang muon: %d)\n",
                       tenSach[pos],
                       dangMuon[pos]);

                do {
                    printf("Chon thao tac (1 - Muon sach, 2 - Tra sach): ");
                    scanf("%d", &thaoTac);

                    while (getchar() != '\n');

                    if (thaoTac != 1 && thaoTac != 2) {
                        printf("Lua chon khong hop le!\n");
                    }

                } while (thaoTac != 1 && thaoTac != 2);

                if (thaoTac == 1) {
                    khaDung = tongSoLuong[pos] - dangMuon[pos];

                    printf("So luong sach co the muon: %d\n", khaDung);

                    do {
                        printf("Nhap so luong muon: ");
                        scanf("%d", &soLuongNhap);

                        while (getchar() != '\n');

                        if (soLuongNhap <= 0) {
                            printf("So luong muon phai lon hon 0!\n");
                        } else if (soLuongNhap > khaDung) {
                            printf("So luong muon vuot qua so luong kha dung!\n");
                        }

                    } while (soLuongNhap <= 0 || soLuongNhap > khaDung);

                    dangMuon[pos] += soLuongNhap;

                    printf("Muon sach thanh cong: %d quyen.\n",
                           soLuongNhap);
                } else {
                    if (dangMuon[pos] == 0) {
                        printf("Sach nay hien khong co sach dang muon de tra!\n");
                        break;
                    }

                    do {
                        printf("Nhap so luong tra: ");
                        scanf("%d", &soLuongTra);

                        while (getchar() != '\n');

                        if (soLuongTra <= 0) {
                            printf("So luong tra phai lon hon 0!\n");
                        } else if (soLuongTra > dangMuon[pos]) {
                            printf("So luong tra khong duoc lon hon so luong dang muon!\n");
                        }

                    } while (soLuongTra <= 0 || soLuongTra > dangMuon[pos]);

                    do {
                        printf("Nhap so ngay qua han (0 neu dung han): ");
                        scanf("%d", &soNgayQuaHan);

                        while (getchar() != '\n');

                        if (soNgayQuaHan < 0) {
                            printf("So ngay qua han khong duoc am!\n");
                        }

                    } while (soNgayQuaHan < 0);

                    dangMuon[pos] -= soLuongTra;

                    tienPhat = soLuongTra * soNgayQuaHan * 5000;

                    printf("\n--- BIEN NHAN TRA SACH ---\n");
                    printf("Tra thanh cong: %d quyen.\n", soLuongTra);

                    if (soNgayQuaHan > 0) {
                        printf("Phat hien qua han: %d ngay.\n",
                               soNgayQuaHan);

                        printf("Tien phat qua han (5.000 VNÐ/quyen/ngay): %.0f VNÐ.\n",
                               tienPhat);
                    } else {
                        printf("Tra dung han, khong co tien phat.\n");
                    }
                }

                break;

            case 4:
                if (soLuong == 0) {
                    printf("Kho sach hien dang rong!\n");
                    break;
                }

                printf("\n=== XOA DAU SACH ===\n");

                printf("Nhap ma sach can xoa: ");
                scanf("%19s", maNhap);

                while (getchar() != '\n');

                pos = -1;

                for (i = 0; i < soLuong; i++) {
                    if (strcmp(maSach[i], maNhap) == 0) {
                        pos = i;
                        break;
                    }
                }

                if (pos == -1) {
                    printf("Khong tim thay ma sach trong he thong!\n");
                    break;
                }

                if (dangMuon[pos] > 0) {
                    printf("Sach dang cho muon, khong the xoa khoi he thong!\n");
                    break;
                }

                for (i = pos; i < soLuong - 1; i++) {
                    strcpy(maSach[i], maSach[i + 1]);
                    strcpy(tenSach[i], tenSach[i + 1]);
                    tongSoLuong[i] = tongSoLuong[i + 1];
                    dangMuon[i] = dangMuon[i + 1];
                    giaBia[i] = giaBia[i + 1];
                }

                soLuong--;

                printf("Xoa dau sach thanh cong!\n");

                break;

            case 5:
                if (soLuong == 0) {
                    printf("Kho sach hien dang rong!\n");
                    break;
                }

                tongBanSach = 0;
                tongDangMuon = 0;
                tongGiaTri = 0;

                for (i = 0; i < soLuong; i++) {
                    tongBanSach += tongSoLuong[i];
                    tongDangMuon += dangMuon[i];
                    tongGiaTri += tongSoLuong[i] * giaBia[i];
                }

                printf("\n");
                printf("===========================================================\n");
                printf("                 THONG KE KHO SACH\n");
                printf("===========================================================\n");
                printf("Tong so dau sach       : %d\n", soLuong);
                printf("Tong so ban sach       : %d\n", tongBanSach);
                printf("Tong so dang cho muon  : %d\n", tongDangMuon);
                printf("Tong gia tri tai san   : %.2f VNÐ\n", tongGiaTri);
                printf("===========================================================\n");

                break;

            case 0:
                printf("\nCam on ban da su dung he thong!\n");
                printf("Ket thuc chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le, vui long chon lai!\n");
        }

    } while (luaChon != 0);

    return 0;
}
