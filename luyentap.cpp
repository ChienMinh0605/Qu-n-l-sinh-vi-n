#include <iostream>
#include <string>
using namespace std;

class sinhvien {
private:
    static int stt;
    string hoten, ngaysinh, mssv;
    string lop, sodienthoai;
    float gpa;
public:
    friend class lop;
    sinhvien();
    void nhap1sv();
    void xuat1sv();
};

int sinhvien::stt=0;

sinhvien::sinhvien(){
    gpa=0.0;
    hoten = "";
    ngaysinh = "";
    mssv = "";
    sodienthoai = "";
}

void sinhvien::nhap1sv(){
    cin.ignore();
    cout<<"Nhap ho ten:";
    getline(cin, hoten);
    cout<<"Nhap ma so sinh vien:"; cin>>mssv;
    cout<<"Nhap lop:"; cin>>lop;
    cout<<"Nhap ngay sinh:"; cin>>ngaysinh;
    cout<<"Nhap so dien thoai:"; cin>>sodienthoai;
}

void sinhvien::xuat1sv(){
    cout<<"--------Thong tin sinh vien----------"<<endl;
    cout<<"Ho ten: "<<hoten<<endl;
    cout<<"Ma so sinh vien: "<<mssv<<endl;
    cout<<"Hoc lop: "<<lop<<endl;
    cout<<"Ngay sinh: "<<ngaysinh<<endl;
    cout<<"So dien thoai: "<<sodienthoai<<endl;
}

class lop{
private:
    sinhvien *dssv; 
    int ssv; 
public:
    lop(int ssv);
    ~lop(); 
    void nhaplop();
    void xuatlop();
};

lop::lop(int ssv){
    this->ssv = ssv;
    dssv = new sinhvien[this->ssv];
}

lop::~lop(){
    delete[] dssv;
}

void lop::nhaplop(){
    for(int i=0;i<ssv;i++){
        cout<<"Nhap thong tin sinh vien thu "<<i+1<<endl;
        dssv[i].nhap1sv();
    }
}

void lop::xuatlop(){
    cout<<"Danh sach sinh vien lop: "<<endl;
    cout<<"STT"<<" "<<"Ma so sinh vien"<<" "<<"Ho va ten"<<endl;
    for(int i=0;i<ssv;i++){
        ++sinhvien::stt;
        cout<<dssv[i].stt<<"   "<<dssv[i].mssv<<"          "<<dssv[i].hoten<<endl;
    }
}

void nhapsosinhvien(int &ssv){
    cout<<"Nhap so sinh vien cua lop:";
    cin>>ssv;
}

int main(){
    int choice;
    cout<<"------------ Quan li sinh vien ------------"<<endl;
    cout<<"Chon yeu cau muon thuc hien:"<<endl;
    cout<<"Nhap thong tin va xuat thong sinh vien ( Nhap 1 )"<<endl;
    cout<<"Nhap thong tin va xuat danh sach lop ( Nhap 2)"<<endl;
    cout<<"Hay nhap o day:"; cin>>choice;
    switch(choice){
    case 1:
    {
    sinhvien x;
    x.nhap1sv();
    x.xuat1sv();
    break;
    }
    case 2:
    {
    int ssv;
    nhapsosinhvien(ssv);
    lop lop23KTMT2(ssv);
    lop23KTMT2.nhaplop();
    lop23KTMT2.xuatlop();
    break;
    }
    }
    return 0;
}
