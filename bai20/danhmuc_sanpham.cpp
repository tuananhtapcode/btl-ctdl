#include<iostream>

using namespace std;

class Danhmuc{
    private:
        string maHang;
        string ten_sp;
        string ten_nsx;
    public:
        Danhmuc(){
            maHang = "Unknown";
            ten_sp = "Unknown";
            ten_nsx = "Uknown";
        }
        Danhmuc(string maHang, string ten_sp, string ten_nsx) : maHang(maHang), ten_sp(ten_sp), ten_nsx(ten_nsx){}
        string getMaHang(){
            return maHang;
        }
        void setMaHang(string maHang){
            this->maHang = maHang;
        }

         string getTen_sp(){
            return ten_sp;
        }
        void setTen_sp(string ten_sp){
            this->ten_sp = ten_sp;
        }

         string getTen_nsx(){
            return ten_nsx;
        }
        void setTen_nsx(string ten_nsx){
            this->ten_nsx = ten_nsx;
        }
        
};