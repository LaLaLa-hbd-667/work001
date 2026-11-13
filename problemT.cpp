//T - 津津的储蓄计划 (P1089)
#include<iostream>
using namespace std;
int main(){
    int x[13]={0},crash=0;
    double sum=0;
    for(int i=1;i<=12;++i){
        cin>>x[i];
    }

    for(int i=1;i<=12;++i){
        crash+=300;
        if(crash<x[i]){
            crash=0;
            sum=-i;
            break;
        }
        else {
            crash-=x[i];
            while(crash>100){
                crash-=100;
                sum+=100;
            }
        }
    }

    if(sum>=0){
        sum*=1.2;
        
    }
    sum+=crash;
    cout<<sum<<endl;

    return 0;
}