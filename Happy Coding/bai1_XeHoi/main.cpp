#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class NgaySinh
{
private:
    int ngay;
    int thang;
    int nam;
public:
    void NhapNS()
    {
        fflush(stdin);
        cout<<"Nhap ngay : ";
        cin>>ngay;
        cout<<"Nhap thang : ";
        cin>>thang;
        cout<<"Nhap nam : ";
        cin>>nam;
        fflush(stdin);
    }
    void XuatNS()
    {
        cout<<"\tNgay : "<<ngay<<endl;
        cout<<"\tThang : "<<thang<<endl;
        cout<<"\tNam : "<<nam<<endl;
    }
    friend class List;
};
class CongDan
{
private:
    string CMND;
    string tenCD;
    NgaySinh ns;
    string diaChi;
public:
    void NhapCD()
    {
        cout<<"Nhap CMND : ";
        cin>>CMND;
        cout<<"Nhap tenCD : ";
        cin>>tenCD;
        ns.NhapNS();
        fflush(stdin);
        cout<<"Nhap diaChi : ";
        cin>>diaChi;
    }
    void XuatCD()
    {
        cout<<"\tCMND : "<<CMND<<endl;
        cout<<"\tTenCD : "<<tenCD<<endl;
        ns.XuatNS();
        cout<<"\tDiaChi : "<<diaChi<<endl;
    }
    friend class List;
};
class XeHoi
{
private:
    CongDan cd;
    string bienSoxe;
    string tenHXS;
public:
    void NhapXH()
    {
        cd.NhapCD();
        fflush(stdin);
        cout<<"Nhap bienSoxe : ";
        cin>>bienSoxe;
        cout<<"Nhap tenHXS : ";
        cin>>tenHXS;
    }
    void XuatXH()
    {
        cd.XuatCD();
        cout<<"\tBienSoxe : "<<bienSoxe<<endl;
        cout<<"\tTenHXS : "<<tenHXS<<endl;
    }
    friend class List;
};
/*
XeHoi *xh;
int n;
void NhapData()
{
    cout<<"Nhap so luong xe : ";
    cin>>n;
    cout<<endl;
    fflush(stdin);
    xh = new XeHoi [n];
    for(int i=0;i<n;i++)
    {
        cout<<"Xe so "<<i+1<<endl;
        xh[i].NhapXH();
        cout<<endl;
    }
}
void XuatData()
{
    for(int i=0;i<n;i++)
    {
        cout<<"Xe so "<<i+1<<endl;
        xh[i].XuatXH();
    }
}
*/
/// Cach 2 su dung lop List
class List
{
private:
    int n;
    XeHoi *xh;
public:
    void NhapData()
    {
        cout<<"Nhap so luong xe : ";
        cin>>n;
        cout<<endl;
        fflush(stdin);
        xh = new XeHoi [n];
        for(int i=0; i<n; i++)
        {
            cout<<"Xe so "<<i+1<<endl;
            xh[i].NhapXH();
            cout<<endl;
        }
    }
    void XuatData()
    {
        for(int i=0; i<n; i++)
        {
            cout<<"Xe so "<<i+1<<endl;
            xh[i].XuatXH();
        }
    }
    void DataHonDa_CDsn1985() /// Thong tin xe hoi hang honda cua cong dan sinh nam 1985
    {
        for(int i=0; i<n; i++)
        {
            ///xh[i].tenHXS.compare("HonDa")== ? // tra google tim kiem chuoi string vs compare
            if( xh[i].tenHXS == "HonDa" && xh[i].cd.ns.nam == 1985){
                cout<<"Xe so "<<i+1<<endl;
                xh[i].XuatXH();
            }
        }
    }
};
int main()
{
    cout << "Coding by Manh Quang" << endl;
    ///Cach 1
    //NhapData();
    //XuatData();
    ///Cach 2
    List L;
    L.NhapData();
    L.XuatData();
    L.DataHonDa_CDsn1985();
    return 0;
}
