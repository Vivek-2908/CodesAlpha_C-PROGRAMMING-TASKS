#include<iostream>
using namespace std;
int main(){
    int n;
    float grade,credit;
    float total=0,totalcredit=0;
    cout<<"Enter number of subjects:";
    cin>>n;
    for (int i= 1;i<=n;i++){
        cout<<"Enter grade point and credit of subject"<<i<<":";
        cin>>grade>>credit;
        total=total+(grade*credit);
        totalcredit=totalcredit+credit;
    }
    cout<<"CGPA="<<total/totalcredit;
    return 0;
}
