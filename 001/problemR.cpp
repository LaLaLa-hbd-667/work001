//(P3613)
#include<iostream>
#include<vector>
using namespace std;

vector<int> cupboard[100005];

void setin(){
    int i,j,x;
    cin>>i>>j>>x;
    if(j>=cupboard[i].size()){
        cupboard[i].resize(j+1,0);
    }
    cupboard[i][j]=x;
}

void setout(){
    int i,j;
    cin>>i>>j;
    cout<<cupboard[i][j]<<endl;

}


int main(){
    int n,q;
    cin>>n>>q;
    int b;
    for(int i=1;i<=q;++i){
        cin>>b;
        if(b==1){
            setin();
        }
        else {
            setout();
        }
    }


    return 0;
}