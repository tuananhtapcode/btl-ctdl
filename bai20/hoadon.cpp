#include <iostream>
#include <fstream>


using namespace std;

class HoaDon
{
private:
    string maHoaDon;
    string maHang;
    string loaiHoaDon;
    int soLuong;
    string ngayMuaBan;
    double giaMuaBan;
public:
    HoaDon(string maHoaDon = "Unknown", string maHang = "Unknown", string loaiHoaDon = "Unknown", int soLuong = 0, string ngayMuaBan = "Unknown", double giaMuaBan = 0)
    {
        this->maHoaDon = maHoaDon;
        this->maHang = maHang;
        this->loaiHoaDon = loaiHoaDon;
        this->ngayMuaBan = ngayMuaBan;
        this->giaMuaBan = giaMuaBan;
        this->soLuong = soLuong;
    }

    string getMaHoaDon(){ return maHoaDon; }
    void setMaHoaDon(string maHoaDon){ this->maHoaDon = maHoaDon; }

    string getMaHang(){ return maHang; }
    void setMaHang(string maHang){ this->maHang = maHang; }

    string getLoaiHoaDon(){ return loaiHoaDon; }
    void setLoaiHoaDon(string loaiHoaDon){ this->loaiHoaDon = loaiHoaDon; }

    int getSoLuong(){ return soLuong; }
    void setSoLuong(int soLuong) { this->soLuong = soLuong; }

    string getNgayMuaBan(){ return ngayMuaBan; }
    void setNgayMuaBan(string ngayMuaBan) { this->ngayMuaBan = ngayMuaBan; }

    double getGiaMuaBan(){ return giaMuaBan; }
    void setGiaMuaBan(double giaMuaBan){ this->giaMuaBan = giaMuaBan; }

     friend istream &operator>>(istream &cin, HoaDon &hoaDon)
    {
        cin.ignore();
        cout << "Nhap ma hoa don: (nam-thang-ngay) ";
        getline(cin, hoaDon.maHoaDon);
        cout << "Nhap ma hang: ";
        getline(cin, hoaDon.maHang);
        cout << "Nhap loai hoa don(Mua hoac Ban): ";
        cin >> hoaDon.loaiHoaDon;
        cout << "Nhap so luong " << hoaDon.loaiHoaDon << ": ";
        cin >> hoaDon.soLuong;
        cout << "Nhap gia " << hoaDon.loaiHoaDon << ": ";
        cin >> hoaDon.giaMuaBan;
        return cin;
    }

    friend ostream &operator<<(ostream &cout, const HoaDon &hoaDon)
    {
        cout << hoaDon.maHoaDon << " - " << hoaDon.maHang << " - " << hoaDon.loaiHoaDon << " - " << hoaDon.soLuong << " - " << hoaDon.ngayMuaBan << " - " << hoaDon.giaMuaBan;
        return cout;
    }
};
