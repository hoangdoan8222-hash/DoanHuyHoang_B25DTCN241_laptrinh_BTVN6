#include <stdio.h>
#include <string.h>

#define MAX_PHIEU 50

int main() {
    char maPhieu[MAX_PHIEU][20] = {
        "PM101",
        "PM102",
        "PM103"
    };

    int ngayQuaHan[MAX_PHIEU] = {
        0,
        3,
        5
    };

    int soLuong = 3;
    int luaChon;
    int i;
    int viTri;
    int ngayMoi;
    int tienPhat;
    char maCanTim[20];

    do {
        printf("\n--- HE THONG QUAN LY MUON TRA SACH (LIBRARY_WMS) ---\n");
        printf("1. Xem danh sach phieu muon\n");
        printf("2. Them moi phieu muon\n");
        printf("3. Cap nhat so ngay qua han\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &luaChon);

        while (getchar() != '\n');

        switch (luaChon) {

            case 1:
                printf("\n--- DANH SACH PHIEU MUON SACH ---\n");
                printf("STT | Ma Phieu | So Ngay Qua Han | Tien Phat (VND)\n");
                printf("--------------------------------------------------\n");

                for (i = 0; i < soLuong; i++) {
                    tienPhat = ngayQuaHan[i] * 5000;

                    printf("%d | %s | %d ngay | %d VND\n",
                           i + 1,
                           maPhieu[i],
                           ngayQuaHan[i],
                           tienPhat);
                }

                printf("--------------------------------------------------\n");
                printf("Tong so phieu: %d\n", soLuong);

                break;

            case 2:
                if (soLuong >= MAX_PHIEU) {
                    printf("Loi: Danh sach phieu muon da day, khong the them!\n");
                    break;
                }

                printf("Nhap ma phieu muon moi: ");
                scanf("%19s", maPhieu[soLuong]);

                while (getchar() != '\n');

                ngayQuaHan[soLuong] = 0;
                soLuong++;

                printf("Them phieu muon thanh cong!\n");
                printf("So ngay qua han ban dau: 0 ngay\n");

                break;

            case 3:
                printf("Nhap ma phieu muon can cap nhat: ");
                scanf("%19s", maCanTim);

                while (getchar() != '\n');

                viTri = -1;

                for (i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maCanTim) == 0) {
                        viTri = i;
                        break;
                    }
                }

                if (viTri == -1) {
                    printf("Khong tim thay phieu muon '%s'!\n", maCanTim);
                    break;
                }

                printf("Tim thay phieu muon '%s' tai vi tri index %d.\n",
                       maCanTim, viTri);

                do {
                    printf("Nhap so ngay qua han moi: ");
                    scanf("%d", &ngayMoi);

                    while (getchar() != '\n');

                    if (ngayMoi < 0) {
                        printf("Loi: So ngay qua han phai la so nguyen khong am!\n");
                    }

                } while (ngayMoi < 0);

                ngayQuaHan[viTri] = ngayMoi;

                printf("Cap nhat thanh cong! So ngay qua han moi cua %s la %d ngay.\n",
                       maPhieu[viTri],
                       ngayQuaHan[viTri]);

                break;

            case 0:
                printf("\nCam on ban da su dung he thong!\n");
                printf("Ket thuc chuong trinh.\n");

                break;

            default:
                printf("Lua chon khong hop le! Vui long chon lai.\n");
        }

    } while (luaChon != 0);

    return 0;
}
