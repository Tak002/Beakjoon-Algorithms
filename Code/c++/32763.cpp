#include <iostream>
using namespace std;



int main() {
    int n;
    cin >> n;
    char resp[1000];
    bool checked = false;

    for(int i=1; i<n;i++){
        cout<<"? "<<1<<" * "<<i+1<<endl;
        cin>>resp[i];

        if(!checked and (resp[i]=='+')){
            checked =true;
            cout<<"? "<<1<<" + "<<i+1<<endl;
            cin>>resp[0];
            if(resp[0]=='+')resp[0] = '+';

            else resp[0] = '-';
        }
    }

    if(!checked){
        cout<<"? "<<2<<" + "<<3<<endl;
        cin>>resp[0];
        if(resp[0]=='+')resp[0] = '-';
        else resp[0] = '+';
    }

    if(resp[0]=='-'){
        for(int i=1; i<n;i++){
            if(resp[i]=='+')resp[i]='-';
            else resp[i]='+';
        }
    }
    
    cout<<"! ";
    for(int i=0; i<n;i++){
        cout<<resp[i]<<" ";
    }
    cout<<endl;
    return 0;
}