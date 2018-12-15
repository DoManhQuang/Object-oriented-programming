#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Ngaysinh
{
private:
    int ngay;
    int thang;
    int nam;
public:
    void NhapNS()
    {
        cout<<"\tNhap Ngay : ";
        cin>>ngay;
        cout<<"\tNhap Thang : ";
        cin>>thang;
        cout<<"\tNhap Nam : ";
        cin>>nam;
    }
    void XuatNS()
    {
        cout<<ngay<<" / "<<thang<<" / "<<nam<<endl;
    }
};
class Nhanvien /// may
{
private:
    char maNV[10];
    char hoTen[20];
    Ngaysinh ns;
    //char gioiTinh[5];
    string gioiTinh;
    char noiSinh[20];
    float heSoluong; /// co the may
public:
    void NhapNV()
    {
        cout<<"Nhap Ma NV : ";
        gets(maNV);
        cout<<"Nhap Ho Va Ten : ";
        gets(hoTen);
        ns.NhapNS();
        fflush(stdin);
        cout<<"Nhap Gioi Tinh : ";
        //gets(gioiTinh);
        cin>>gioiTinh;
        cout<<"Nhap Noi Sinh : ";
        gets(noiSinh);
        cout<<"Nhap He so luong ";
        cin>>heSoluong;
        fflush(stdin);
    }
    int Tienluong()
    {
        int tienLuong = heSoluong * 1300000;
        return tienLuong;
        ///return heSoluong * 1300000;
    }
    int getHesoluong()
    {
        return heSoluong;
    }
    /**int getGioitinh()
    {
        if(strcmp(gioiTinh , "Nam")==1)
            return 1;
        return 0;
    }*/
    string getGioitinh_new()
    {
        return gioiTinh;
    }
    void XuatNS()
    {
        int luongNV = Tienluong();
        cout<<endl;
        cout<<"\tMa NV : ";
        puts(maNV);
        cout<<"\tHo Va Ten : ";
        puts(hoTen);
        cout<<"\tNgay Sinh : ";ns.XuatNS();
        fflush(stdin);
        cout<<"\tGioi Tinh : "<<gioiTinh<<endl;
        //puts(gioiTinh);
        cout<<"\tNoi Sinh : ";
        puts(noiSinh);
        cout<<"\tHe so luong : "<<heSoluong<<endl;
        cout<<"\tLuong NV : " <<luongNV;
        ///Tienluong();
    }
};

Nhanvien nv[100]; /// Khai bao mang nv[100]
///Nhanvien *nv;
int n; /// so luong nhan vien
void NhapDSNV()
{
    cout<<"Nhap So luong NV : ";
    cin>>n;
    fflush(stdin);
    ///nv = new Nhanvien[n]; /// Khai bao cap phat mang dong
    for(int i=1;i<=n;i++)
    {
        cout<<"\n";
        nv[i].NhapNV();
    }
}

void XuatDSNV()
{
    for(int i=1;i<=n;i++)
    {
        cout<<"\n";
        nv[i].XuatNS();
    }
}
void XuatDSNV_HSL_3_9() /// tao
{
    cout<<" DS Nhan vien co HSL tu 3.99"<<endl;
    for(int i=1;i<=n;i++)
    {
       /// if(nv[i].getHesoluong()>=3.99 && nv[i].getGioitinh()==1)
        if(nv[i].getHesoluong()>=3.99 && nv[i].getGioitinh_new()=="Nam")
        {
            cout<<"\n";
            nv[i].XuatNS();
        }
    }
}
int main()
{
    cout << "Coding by Manh Quang" << endl;
    NhapDSNV();
    XuatDSNV();
    XuatDSNV_HSL_3_9();
    return 0;
}
