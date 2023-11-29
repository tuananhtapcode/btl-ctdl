#include "hoadon.cpp"
#include "danhmuc_sanpham.cpp"
#include <vector>
#pragma once
using namespace std;

class CuaHang
{
private:
    vector<Danhmuc> danhSachMatHang;
    vector<HoaDon> danhSachHoaDon;

public:
    void DocFile(string tenFile)
    {
        // TODO: Đọc thông tin quản lý của cửa hàng từ file vào chương trình
        ifstream file(tenFile);
        if (file.is_open())
        {
            // Đọc danh sách mặt hàng
            int soMatHang;
            file >> soMatHang; 
            for (int i = 0; i < soMatHang; i++)
            {
                Danhmuc matHang;
                string temp;
                
                getline(file,temp);
                matHang.setMaHang(temp);
                
                getline(file,temp);
                matHang.setTen_sp(temp);
                
                getline(file,temp);
                matHang.setTen_nsx(temp);
                
                danhSachMatHang.push_back(matHang);
            }

            // Đọc danh sách hóa đơn
            int soHoaDon;
            file >> soHoaDon;
            for (int i = 0; i < soHoaDon; i++)
            {
                HoaDon hoaDon;
                string temp;
                file >> temp;
                hoaDon.setMaHoaDon(temp);
                file >> temp;
                hoaDon.setMaHang(temp);
                file >> temp;
                hoaDon.setLoaiHoaDon(temp);

                int temp1;
                file >> temp1;
                hoaDon.setSoLuong(temp1);
                
                string temp3;
                file >> temp3;
                hoaDon.setNgayMuaBan(temp3);

                double temp2;
                file >> temp2;
                hoaDon.setGiaMuaBan(temp2);

                danhSachHoaDon.push_back(hoaDon);
            }

            file.close();
            cout << "Da doc thong tin tu file thanh cong." << endl;
        }
        else
        {
            cout << "Khong the mo file." << endl;
            return;
        }
    }

    void GhiFile(string tenFile)
    {
        // TODO: Ghi thông tin quản lý của cửa hàng vào file
        ofstream file(tenFile);
        if (file.is_open())
        {
            // Ghi danh sách mặt hàng
            file << danhSachMatHang.size() << endl;
            for (auto &matHang : danhSachMatHang)
            {
                file << matHang.getMaHang() << " " << matHang.getTen_sp() << " " << matHang.getTen_nsx() << endl;
            }

            // Ghi danh sách hóa đơn
            file << danhSachHoaDon.size() << endl;
            for (auto &hoaDon : danhSachHoaDon)
            {
                file << hoaDon.getMaHoaDon() << " " << hoaDon.getMaHang() << " " << hoaDon.getLoaiHoaDon() << " " << hoaDon.getSoLuong() << " " << hoaDon.getNgayMuaBan() << " " << hoaDon.getGiaMuaBan() << endl;
            }

            file.close();
            cout << "Da ghi thong tin vao file thanh cong" << endl;
        }
        else
        {
            cout << "Khong the mo file" << endl;
            return;
        }
    }

    void NhapMatHang()
    {
        // TODO: Nhập thông tin của một mặt hàng từ người dùng
        Danhmuc matHang;
        cin.ignore();
        string temp;
        cout << "Nhap ma hang: "; getline(cin, temp); matHang.setMaHang(temp);
        cout << "Nhap ten hang: "; getline(cin,temp); matHang.setTen_sp(temp);
        cout << "Nhap nha san xuat: "; getline(cin,temp); matHang.setTen_nsx(temp);
        danhSachMatHang.push_back(matHang);
        cout << "Da them mat hang thanh cong " << endl;
    }

    void XuatDanhSachMatHang()
    {
        // TODO: Hiển thị toàn bộ danh sách các mặt hàng hiện có
        if (danhSachMatHang.empty())
        {
            cout << "Danh sach mat hang rong." << endl;
        }
        else
        {
            cout << "Danh sach mat hang: " << danhSachMatHang.size() << " mat hang" << endl;
           
            for (auto &matHang : danhSachMatHang)
            {
                cout << "Ma hang: " << matHang.getMaHang() << ", Ten hang: " << matHang.getTen_sp() << ", Nha san xuat: " << matHang.getTen_nsx() << endl;
            }
        }
    }

    void ThongKeTonKho()
    {
        // TODO: Thống kê số lượng mặt hàng tồn của mỗi mặt hàng
        if (danhSachMatHang.empty())
        {
            cout << "Danh sach mat hang rong." << endl; 
            return;
        }
        else
        {
            cout << "Thong ke so luong mat hang ton:" << endl;
            for (auto &matHang : danhSachMatHang)
            {
                int soLuongTon = 0;
                for (auto &hoaDon : danhSachHoaDon)
                {
                    if (hoaDon.getMaHang() == matHang.getMaHang())
                    {
                        if (hoaDon.getLoaiHoaDon() == "ban")
                        {
                            soLuongTon -= hoaDon.getSoLuong();
                        }
                        else if (hoaDon.getLoaiHoaDon() == "mua")
                        {
                            soLuongTon += hoaDon.getSoLuong();
                        }
                    }
                }
                cout << "Ma hang: " << matHang.getMaHang() << ", Ten hang: " << matHang.getTen_sp() << ", So luong ton: " << soLuongTon << endl;
            }
        }
    }
};

int main()
{
    CuaHang cuaHang;
    int choice;
    string tenFile = "quanlycuahang.txt";

    do
    {
        cout << "----- Quan ly cua hang ban tap hoa -----" << endl;
        cout << "1. Doc danh thong tin quan ly cua cua hang tu file vao chuong trinh" << endl;
        cout << "2. Ghi thong tin quan ly cua cua hang vao file" << endl;
        cout << "3. Nhap, xuat thong tin mot mat hang" << endl;
        cout << "4. Hien thi danh sach cac mat hang hien co" << endl;
        cout << "5. Thong ke so luong mat hang ton" << endl;
        cout << "0. Thoat" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cuaHang.DocFile(tenFile);
            break;
        case 2:
            cuaHang.GhiFile(tenFile);
            break;
        case 3:
            cuaHang.NhapMatHang();
            break;
        case 4:
            cuaHang.XuatDanhSachMatHang();
            break;
        case 5:
            cuaHang.ThongKeTonKho();
            break;
        case 0:
            cout << "Cam on da su dung chuong trinh!" << endl;
            break;
        default:
            cout << "Lua chon khong hop le, vui long chon lai: " << endl;
        }
        cout << endl;
    } while (choice != 0);

    return 0;
}