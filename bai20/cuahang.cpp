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
            file.ignore();
            for (int i = 0; i < soMatHang; i++)
            {
                Danhmuc matHang;
                string temp;

                getline(file, temp);
                matHang.setMaHang(temp);

                getline(file, temp);
                matHang.setTen_sp(temp);

                getline(file, temp);
                matHang.setTen_nsx(temp);

                danhSachMatHang.push_back(matHang);
            }
            // Đọc danh sách hóa đơn
            int soHoaDon;
            file >> soHoaDon;
            file.ignore();
            for (int i = 0; i < soHoaDon; i++)
            {
                HoaDon hoaDon;
                string temp;
                getline(file, temp);
                hoaDon.setMaHoaDon(temp);
                getline(file, temp);
                hoaDon.setMaHang(temp);
                getline(file, temp);
                hoaDon.setLoaiHoaDon(temp);

                int temp1;
                file >> temp1;
                hoaDon.setSoLuong(temp1);
                file.ignore();

                string temp3;
                getline(file, temp3);
                hoaDon.setNgayMuaBan(temp3);

                double temp2;
                file >> temp2;
                hoaDon.setGiaMuaBan(temp2);
                file.ignore();

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
                file << matHang.getMaHang() << "\n"
                     << matHang.getTen_sp() << "\n"
                     << matHang.getTen_nsx() << endl;
            }
            // Ghi danh sách hóa đơn
            file << danhSachHoaDon.size() << endl;
            for (auto &hoaDon : danhSachHoaDon)
            {
                file << hoaDon.getMaHoaDon() << "\n"
                     << hoaDon.getMaHang() << "\n"
                     << hoaDon.getLoaiHoaDon() << "\n"
                     << hoaDon.getSoLuong() << "\n"
                     << hoaDon.getNgayMuaBan() << "\n"
                     << hoaDon.getGiaMuaBan() << "\n"
                     << endl;
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

    void NhapXuatMatHang()
    {
        // TODO: Nhập thông tin của một mặt hàng từ người dùng
        Danhmuc matHang;
        cin.ignore();
        string maHang;
        cout << "Nhap ma hang: ";
        getline(cin, maHang);
        matHang.setMaHang(maHang);

        string tenHang;
        cout << "Nhap ten hang: ";
        getline(cin, tenHang);
        matHang.setTen_sp(tenHang);

        string nsx;
        cout << "Nhap nha san xuat: ";
        getline(cin, nsx);
        matHang.setTen_nsx(nsx);

        bool check = false;
        int pos; //bien de luu tru dia chi mat hang can tim
        for (int i = 0; i < danhSachMatHang.size(); i++)
        {
            if (danhSachMatHang[i].getMaHang() == maHang)
            {
                cout << "Da ton tai mat hang nay trong kho \n";
                pos = i;
                check = true;
                break;
            }
        }
        if (!check)
        {
            cout << "Khong tim thay mat hang nay trong kho. \n";
            cout << "muon nhap san pham nay vao kho khong. \n";
            cout << "nhap 0 - KHONG; \t 1 - CO. \n";
            cout << "Nhap lua chon cua ban: ";
            bool yourChoice;
            cin >> yourChoice;
            if (!yourChoice)
            {
                cout << "Ban da chon khong nhap san pham vao danh sach mat hang!" << endl;
                return;
            }
            danhSachMatHang.push_back(matHang);
            cout << "Da them mat hang thanh cong " << endl;
            pos = danhSachMatHang.size() - 1; // dat pos ve dia chi cua mat hang moi vua them vao danh sach mat hang
        }

        // Hỏi người dùng có muốn mua/bán hàng không
        cout << "Ban muon mua (1) hay ban (2) hang? Nhap lua chon: ";
        int luaChon;
        cin >> luaChon;

        // Thực hiện mua/bán hàng nếu có yêu cầu
        if (luaChon == 1 || luaChon == 2)
        {
            // Tạo một hóa đơn mới
            HoaDon tempHoaDon;
            tempHoaDon.setMaHoaDon(maHang);
            tempHoaDon.setMaHang(tenHang);
            tempHoaDon.setLoaiHoaDon(luaChon == 1 ? "Mua" : "Ban");

            // Gọi hàm nhập thông tin hóa đơn
            NhapHoaDon(tempHoaDon);

            // Cập nhật danh sách hóa đơn và mặt hàng
            danhSachHoaDon.push_back(tempHoaDon);

            if (luaChon == 1)
            {
                danhSachHoaDon[pos].setSoLuong(danhSachHoaDon[pos].getSoLuong() + tempHoaDon.getSoLuong());
                return;
            }
            else if (luaChon == 2 && danhSachHoaDon[pos].getSoLuong() >= tempHoaDon.getSoLuong())
            {
                danhSachHoaDon[pos].setSoLuong(danhSachHoaDon[pos].getSoLuong() - tempHoaDon.getSoLuong());
                return;
            }
            else
            {
                cout << "Khong du so luong mat hang!" << endl;
                return;
            }
        }
    }

    void NhapHoaDon(HoaDon &hoaDon)
    {
        // TODO: Nhập thông tin cho hóa đơn từ người dùng
        cout << "Nhap so luong: ";
        cin.ignore();
        int SL;
        cin >> SL;
        hoaDon.setSoLuong(SL);

        string day;
        cin.ignore();
        cout << "Nhap ngay mua/ban: ";
        getline(cin, day);
        hoaDon.setNgayMuaBan(day);

        double cost;
        cout << "Nhap gia mua/ban: ";
        cin >> cost;
        hoaDon.setGiaMuaBan(cost);
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
                        if (hoaDon.getLoaiHoaDon() == "Ban")
                        {
                            soLuongTon -= hoaDon.getSoLuong();
                            if (soLuongTon < 0)
                            {
                                soLuongTon = 0;
                            }
                        }
                        else if (hoaDon.getLoaiHoaDon() == "Mua")
                        {
                            soLuongTon += hoaDon.getSoLuong();
                        }
                    }
                }
                cout << "Ma hang: " << matHang.getMaHang() << ", Ten hang: " << matHang.getTen_sp() << ", So luong ton: " << soLuongTon;
                cout << endl;
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
            cuaHang.NhapXuatMatHang();
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
