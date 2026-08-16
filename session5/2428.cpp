/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported
###End banned keyword*/

#include <iomanip>
#include <iostream>
#include <stdio.h>
using namespace std;

struct SinhVien {
    char MASV[10];
    char HoTen[100];
    char NgaySinh[12];
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};

// ###INSERT CODE HERE -
void Nhap(SinhVien &A) {
    //
    cin.getline(A.MASV, 10);
    cin.getline(A.HoTen, 100);
    cin.getline(A.NgaySinh, 100);

    cin >> A.GioiTinh >> A.DiemToan >> A.DiemLy >> A.DiemHoa;
    A.DTB = (A.DiemToan + A.DiemLy + A.DiemHoa) / 3;
};

void Xuat(SinhVien A) {
    //
    cout << A.MASV << '\t' << A.HoTen << '\t' << A.NgaySinh << '\t'
         << A.GioiTinh << '\t' << A.DiemToan << '\t' << A.DiemLy << '\t'
         << A.DiemHoa << '\t' << setprecision(3) << A.DTB << '\n';
}

int main() {
    SinhVien A;
    Nhap(A);
    Xuat(A);
    return 0;
}
