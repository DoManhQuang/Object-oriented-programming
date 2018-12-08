#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
Bài tập 3 : Cài đặt lớp PhuongTrinh với các thuộc tính cần thiết để lưu trữ 1 phương trình bậc 3
dạng: ax3 + bx2 + cx + d = 0 (với a, b, c, d là các số thực) và các phương thức sau:
- Phương thức khởi tạo không đối và có đối.
- Phương thức xuất để hiển thị phương trình ra màn hình dạng: ax^3 + bx^2 + cx + d = 0.
- Phương thức toán tử cộng (+), cộng các hệ số tương ứng của 2 phương trình, trả về một
phương trình.
- Phương thức toán tử tăng (++) để đảo giá trị của các hệ số a, b, c, d của phương trình sao cho
a, b, c, d theo thứ tự tăng dần.
- Hàm toán tử nhập (>>) để nhập các hệ số của phương trình.
- Viết hàm main() sử dụng lớp PhuongTrinh vừa cài đặt (sinh viên sử dụng tất cả các phương
thức đã định nghĩa trong lớp).
**/
class Dathuc
{
private:
    int a ,b , c, d;
public:
    Dathuc()
    {
        this->a = 0;
        this->b = 0;
        this->c = 0;
        this->d = 0;
    }
    Dathuc(int a1 , int b1 ,int c1 ,int d1)
    {
        this->a = a1;
        this->b = b1;
        this->c = c1;
        this->d = d1;
    }
    void NhapDathuc();
    friend istream &operator>>(istream &is , Dathuc &dt);
    friend ostream &operator<<(ostream &os , Dathuc dt);
    Dathuc operator + (Dathuc dt);
    Dathuc operator ++();
};
istream &operator>>(istream &is , Dathuc &dt)
{
    cout<<"Nhap A = ";
    is>>dt.a;
    cout<<"Nhap B = ";
    is>>dt.b;
    cout<<"Nhap C = ";
    is>>dt.c;
    cout<<"Nhap D = ";
    is>>dt.d;
    return is;
}
void Dathuc::NhapDathuc()
{
    cout<<"Nhap A = ";
    cin>>a;
    cout<<"Nhap B = ";
    cin>>b;
    cout<<"Nhap C = ";
    cin>>c;
    cout<<"Nhap D = ";
    cin>>d;
}
ostream &operator<<(ostream &os , Dathuc dt)
{
    os<<dt.a<<" X^3 + "<<dt.b<<" X^2 + "<<dt.c<<" X + "<<dt.d<<" = 0 "<<endl;
    return os;
}
Dathuc Dathuc::operator+(Dathuc dt) ///Cộng 2 Đa thức
{
    this->a = a + dt.a;
    this->b = b + dt.b;
    this->c = c + dt.c;
    this->d = d + dt.d;
    return *this; /// trả về dữ liệu cho Đa thức mới .
}

Dathuc Dathuc::operator++()
/// đảo giá trị của các hệ số a, b, c, d của phương trình sao cho a, b, c, d theo thứ tự tăng dần.
{
    int a[4];
    a[0] = this->a;
    a[1] = this->b;
    a[2] = this->c;
    a[3] = this->d;

    for(int i=0;i<3;i++)
    {
        int ma = i;
        for(int j=i+1;j<4;j++)
        {
            if(a[j]<a[ma])
            {
                ma = j;
            }
        }
        if(ma!=i)
        {
            swap(a[ma],a[i]);

        }
    }
    this->a = a[0];
    this->b = a[1];
    this->c = a[2];
    this->d = a[3];
    return *this;
}
int main()
{
    cout << "Coding by Manh Quang" << endl;
    Dathuc dt1 , dt2(4,8,2,9) , dt3;
    cout<<"Khoi tao da thuc "<<dt1<<endl;
    cout<<"DT2 : "<<dt2<<endl;
    cout<<"Nhap DT1 : "<<endl;
    freopen("data.txt","r",stdin);
    cin>>dt1;
    cout<<endl<<"DT1 : "<<dt1<<endl;
    dt3 = dt1 + dt2;
    cout<<"DT3 = DT1 + DT2 : "<<dt3<<endl;
    dt3 = ++dt2;
    cout<<"DT3 = ++DT2 : "<<dt3<<endl;
    return 0;
}
