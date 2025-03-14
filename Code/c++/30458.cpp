#include <iostream>
#include <string>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    string s; cin>>s;

    bool isCharSingle[26]={false};
    int index;
    for(int i=0; i<n/2;i++){
        index =s.at(i)-97;
        isCharSingle[index] = !isCharSingle[index];
        index =s.at(n-1-i)-97;
        isCharSingle[index] = !isCharSingle[index];
    }


    for(int i=0; i<26; i++){
        if(isCharSingle[i]){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}