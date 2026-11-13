//(P3620)
#include<iostream>
#include<string>
using namespace std;
int main(){
    int n,m,aid;
    string s;

    cin>>n>>s;
    m=0;
    aid=1;

    int i=0;
    while(s.length()){
        if(s[s.length()-1]>='0' && s[s.length()-1]<='9'){
            aid=s[s.length()-1]-'0';
        }
        else if(s[s.length()-1]>='A' && s[s.length()-1]<='Z'){
            aid=s[s.length()-1]-'A'+10;
        }
        else if(s[s.length()-1]>='a' && s[s.length()-1]<='z'){
            aid=s[s.length()-1]-'a'+36;
        }
        for(int j=0;j<i;j++){
            aid*=n;
        }
        m+=aid;
        s.pop_back();
        i++;
    }

    cout<<m<<endl;

    return 0;
}