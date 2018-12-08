#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Phanso
{
private:
    int tuSo;
    int mauSo;
public:
    Phanso()
    {
        this->tuSo = 0;
        this->mauSo = 1;
    }
    Phanso(int tuSo , int mauSo)
    {
        this->tuSo = tuSo;
        this->mauSo = mauSo;
    }
    void Nhap();
    void Xuat();
    Phanso operator -();
    Phanso operator +(Phanso ps);
    Phanso operator -(Phanso ps);
    Phanso operator *(Phanso ps);
    Phanso operator /(Phanso ps);
    bool operator >(Phanso ps);
    bool operator <(Phanso ps);
    bool operator ==(Phanso ps);
    bool operator !=(Phanso ps);
    Phanso operator --();
    friend istream&operator>>(istream &is,Phanso &ps);
    friend ostream&operator<<(ostream &os,Phanso ps);
};
Phanso Phanso::operator-()
{
    Phanso tg;
    tg.tuSo = -this->tuSo;
    tg.mauSo = -this->mauSo;
    return tg;
}

void Phanso::Nhap()
{
    cout<<"\t Tu So : ";
    cin>>this->tuSo;
    cout<<"\t Mau So : ";
    cin>>this->mauSo;
}
void Phanso::Xuat()
{
    cout<<this->tuSo<<" / "<<this->mauSo<<endl;
}
Phanso Phanso::operator + (Phanso ps)
{
    Phanso tg;
    tg.tuSo = this->tuSo*ps.mauSo + ps.tuSo*this->mauSo;
    tg.mauSo = this->mauSo * ps.mauSo;
    return tg;
}
Phanso Phanso::operator - (Phanso ps)
{
    Phanso tg;
    tg.tuSo = this->tuSo*ps.mauSo - ps.tuSo*this->mauSo;
    tg.mauSo = this->mauSo * ps.mauSo;
    return tg;
}
Phanso Phanso::operator * (Phanso ps)
{
    Phanso tg;
    tg.tuSo = this->tuSo*ps.tuSo;
              tg.mauSo = this->mauSo * ps.mauSo;
    return tg;
}
Phanso Phanso::operator / (Phanso ps)
{
    Phanso tg;
    tg.tuSo = this->tuSo*ps.mauSo;
    tg.mauSo = this->mauSo * ps.tuSo;
    return tg;
}
bool Phanso::operator > (Phanso ps)
{
    double a = (double)this->tuSo / this->mauSo;
    double b = (double)ps.tuSo / ps.mauSo;
    return a>b;
}
bool Phanso::operator < (Phanso ps)
{
    double a = (double)this->tuSo / this->mauSo;
    double b = (double)ps.tuSo / ps.mauSo;
    return a<b;
}
bool Phanso::operator == (Phanso ps)
{
    double a = (double)this->tuSo / this->mauSo;
    double b = (double)ps.tuSo / ps.mauSo;
    return a==b;
}
bool Phanso::operator != (Phanso ps)
{
    double a = (double)this->tuSo / this->mauSo;
    double b = (double)ps.tuSo / ps.mauSo;
    return a!=b;
}
int UCLN(int a,int b)
{
    int r;
    if(a<b)
    {
        r = a;
        a = b;
        b = r;
    }
    r = a%b;
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
Phanso Phanso::operator -- ()
{
    int a = abs(this->tuSo);
    int b = abs(this->mauSo);
    int ucln = UCLN(a,b);
    this->tuSo = this->tuSo/ucln;
    this->mauSo = this->mauSo/ucln;
    return *this;
}
istream&operator>>(istream &is,Phanso &ps)
{
    cout<<"\t Tu so : ";
    is>>ps.tuSo;
    cout<<"\t Mau so : ";
    is>>ps.mauSo;
    return is;
}
ostream&operator<<(ostream &os,Phanso ps)
{
    os<<"\t Phan so : "<<ps.tuSo<<"/"<<ps.mauSo<<endl;
    return os;
}
int main()
{
    cout << "Coding by Manh Quang" << endl;
    Phanso ps1,ps2,ps3;
    freopen("data.txt","r",stdin);
    ps1.Nhap();
    ps2.Nhap();
//    ps3 = -ps1;
//    cout<<"PS 1 : "<<endl;
//    ps1.Xuat();
//    cout<<"PS 2 : "<<endl;
//    ps2.Xuat();
//    cout<<"PS 3 = - PS 1 : "<<endl;
//    ps3.Xuat();
//    ps3 = ps1 + ps2;
//    cout<<"PS3 = PS1 + PS2 :"<<ps3<<endl;
//    cout<<"PS1 / PS2 "<<ps1/ps2<<endl;
    --ps1;
    --ps2;
    ps3 = ps1+ps2;
    --ps3;
    cout<<"PS Sau khi toi gian "<<endl;
    cout<<ps1<<endl;
    cout<<ps2<<endl;
    cout<<ps3<<endl;
    return 0;
}
