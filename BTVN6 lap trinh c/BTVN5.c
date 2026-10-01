#include <stdio.h>
#include <string.h>

#define MAX 50

int main() {
    char dsMaPhieu[MAX][20];
    char dsMaSV[MAX][20];

    int dsSoNgay[MAX];
    double dsTienPhat[MAX];
    int dsTrangThai[MAX];

    int soLuong = 0;

    int luaChon;
    int i;
    int pos;
    int soNgayMoi;
    int thaoTac;

    char maNhap[20];

    double tongDaThu;
    double tongNo;

    do {
        printf("\n");
        printf("====================================================================\n");
        printf("          HE THONG QUAN LY PHI PHAT (LIBRARY_WMS)\n");
        printf("====================================================================\n");
        printf("1. Them moi phieu phat qua han\n");
        printf("2. Hien thi danh sach & Thong ke tai chinh\n");
        printf("3. Cap nhat phieu phat\n");
        printf("4. Xoa phieu phat (Da thanh toan)\n");
        printf("5. Thoat\n");
        printf("--------------------------------------------------------------------\n");
        printf("Chon chuc nang (1-5): ");
        scanf("%d", &luaChon);

        while (getchar() != '\n');

        switch (luaChon) {
            case 1:
                if (soLuong >= MAX) {
                    printf("Danh sach phieu phat da day, khong the them!\n");
                    break;
                }

                printf("\n--- THEM MOI PHIEU PHAT ---\n");

                printf("Nhap ma phieu muon: ");
                scanf("%19s", maNhap);

                while (getchar() != '\n');

                pos = -1;

                for (i = 0; i < soLuong; i++) {
                    if (strcmp(dsMaPhieu[i], maNhap) == 0) {
                        pos = i;
                        break;
                    }
                }

                if (pos != -1) {
                    printf("Ma phieu da ton tai trong he thong!\n");
                    break;
                }

                strcpy(dsMaPhieu[soLuong], maNhap);

                printf("Nhap ma sinh vien: ");
                scanf("%19s", dsMaSV[soLuong]);

                while (getchar() != '\n');

                do {
                    printf("Nhap so ngay qua han: ");
                    scanf("%d", &dsSoNgay[soLuong]);

                    while (getchar() != '\n');

                    if (dsSoNgay[soLuong] <= 0) {
                        printf("So ngay qua han phai lon hon 0!\n");
                    }

                } while (dsSoNgay[soLuong] <= 0);

                if (dsSoNgay[soLuong] <= 7) {
                    dsTienPhat[soLuong] = dsSoNgay[soLuong] * 5000;
                } else {
                    dsTienPhat[soLuong] =
                        (7 * 5000) + ((dsSoNgay[soLuong] - 7) * 10000);
                }

                dsTrangThai[soLuong] = 0;

                printf("\n[Thanh cong] Da them phieu phat %s.\n",
                       dsMaPhieu[soLuong]);

                printf("Tien phat: %.1f VNÐ.\n",
                       dsTienPhat[soLuong]);

                printf("Trang thai: Chua thanh toan.\n");

                soLuong++;

                break;

            case 2:
                if (soLuong == 0) {
                    printf("Danh sach phi phat dang rong!\n");
                    break;
                }

                printf("\n");
                printf("================================================================================\n");
                printf("                    DANH SACH PHI PHAT THU VIEN\n");
                printf("================================================================================\n");

                printf("%-5s %-15s %-15s %-12s %-18s %-15s\n",
                       "STT",
                       "Ma Phieu",
                       "Ma SV",
                       "So Ngay",
                       "Tien Phat (VNÐ)",
                       "Trang Thai");

                printf("--------------------------------------------------------------------------------\n");

                tongDaThu = 0;
                tongNo = 0;

                for (i = 0; i < soLuong; i++) {
                    if (dsTrangThai[i] == 1) {
                        printf("%-5d %-15s %-15s %-12d %-18.1f %-15s\n",
                               i + 1,
                               dsMaPhieu[i],
                               dsMaSV[i],
                               dsSoNgay[i],
                               dsTienPhat[i],
                               "Da thanh toan");

                        tongDaThu += dsTienPhat[i];
                    } else {
                        printf("%-5d %-15s %-15s %-12d %-18.1f %-15s\n",
                               i + 1,
                               dsMaPhieu[i],
                               dsMaSV[i],
                               dsSoNgay[i],
                               dsTienPhat[i],
                               "Chua thanh toan");

                        tongNo += dsTienPhat[i];
                    }
                }

                printf("================================================================================\n");
                printf("Tong tien phat da thu      : %.1f VNÐ\n", tongDaThu);
                printf("Tong tien phat con no      : %.1f VNÐ\n", tongNo);
                printf("================================================================================\n");

                break;

            case 3:
                if (soLuong == 0) {
                    printf("Danh sach phi phat dang rong!\n");
                    break;
                }

                printf("\n--- CAP NHAT PHIEU PHAT ---\n");

                printf("Nhap ma phieu muon can cap nhat: ");
                scanf("%19s", maNhap);

                while (getchar() != '\n');

                pos = -1;

                for (i = 0; i < soLuong; i++) {
                    if (strcmp(dsMaPhieu[i], maNhap) == 0) {
                        pos = i;
                        break;
                    }
                }

                if (pos == -1) {
                    printf("Khong tim thay ma phieu nay trong he thong!\n");
                    break;
                }

                printf("\nPhieu: %s\n", dsMaPhieu[pos]);
                printf("Ma sinh vien: %s\n", dsMaSV[pos]);
                printf("So ngay qua han: %d\n", dsSoNgay[pos]);
                printf("Tien phat: %.1f VNÐ\n", dsTienPhat[pos]);

                printf("\n1. Cap nhat lai so ngay qua han\n");
                printf("2. Xac nhan thanh toan tien phat\n");
                printf("Chon thao tac: ");
                scanf("%d", &thaoTac);

                while (getchar() != '\n');

                switch (thaoTac) {
                    case 1:
                        do {
                            printf("Nhap so ngay qua han moi: ");
                            scanf("%d", &soNgayMoi);

                            while (getchar() != '\n');

                            if (soNgayMoi <= 0) {
                                printf("So ngay qua han phai lon hon 0!\n");
                            }

                        } while (soNgayMoi <= 0);

                        dsSoNgay[pos] = soNgayMoi;

                        if (dsSoNgay[pos] <= 7) {
                            dsTienPhat[pos] = dsSoNgay[pos] * 5000;
                        } else {
                            dsTienPhat[pos] =
                                (7 * 5000) +
                                ((dsSoNgay[pos] - 7) * 10000);
                        }

                        printf("Cap nhat so ngay va tien phat thanh cong!\n");
                        printf("So ngay qua han moi: %d\n",
                               dsSoNgay[pos]);
                        printf("Tien phat moi: %.1f VNÐ\n",
                               dsTienPhat[pos]);

                        break;

                    case 2:
                        if (dsTrangThai[pos] == 1) {
                            printf("Phieu nay da duoc thanh toan truoc do!\n");
                        } else {
                            dsTrangThai[pos] = 1;

                            printf("Xac nhan thanh toan thanh cong!\n");
                            printf("Phieu %s da chuyen sang trang thai Da thanh toan.\n",
                                   dsMaPhieu[pos]);
                        }

                        break;

                    default:
                        printf("Lua chon khong hop le!\n");
                }

                break;

            case 4:
                if (soLuong == 0) {
                    printf("Danh sach phi phat dang rong!\n");
                    break;
                }

                printf("\n--- XOA PHIEU PHAT ---\n");

                printf("Nhap ma phieu muon can xoa: ");
                scanf("%19s", maNhap);

                while (getchar() != '\n');

                pos = -1;

                for (i = 0; i < soLuong; i++) {
                    if (strcmp(dsMaPhieu[i], maNhap) == 0) {
                        pos = i;
                        break;
                    }
                }

                if (pos == -1) {
                    printf("Khong tim thay ma phieu nay trong he thong!\n");
                    break;
                }

                if (dsTrangThai[pos] == 0) {
                    printf("Khong the xoa phieu phat CHUA thanh toan de tranh meo mo so sach tai chinh!\n");
                    break;
                }

                for (i = pos; i < soLuong - 1; i++) {
                    strcpy(dsMaPhieu[i], dsMaPhieu[i + 1]);
                    strcpy(dsMaSV[i], dsMaSV[i + 1]);

                    dsSoNgay[i] = dsSoNgay[i + 1];
                    dsTienPhat[i] = dsTienPhat[i + 1];
                    dsTrangThai[i] = dsTrangThai[i + 1];
                }

                soLuong--;

                printf("Xoa phieu phat thanh cong!\n");

                break;

            case 5:
                printf("\nCam on ban da su dung he thong!\n");
                printf("Ket thuc chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le, vui long chon lai!\n");
        }

    } while (luaChon != 5);

    return 0;
}
