#include <iostream>
using namespace std;

//30분:실패, 70분:성공
//고수의 코드: https://www.acmicpc.net/source/91146399

int main() {
    int n, a; cin>>n;
    short arr[100001]={0};
    bool isRest= false;
    long long ans=0;
    long long stick=0;
    for(int i=0;i<n;i++){
        cin>>a;
        arr[a]+=1;
    }
    for(int i=100000;i>0;i--){
        bool preIsRest = isRest;
        if((arr[i]+isRest)&1 && (arr[i]>0))isRest = true;
        else isRest = false;

        if(arr[i] + preIsRest>=2){
            arr[i] = (arr[i]+preIsRest)/2;
        }
        else arr[i] = 0;

            
    }
    
    for(long long i=100000;i>0;i--){
        while(arr[i]>0){
            if(!stick)stick = i;
            else{
                ans += stick*i;
                stick=0;
            }
            arr[i]-=1;
        }
    }
    cout<<ans;
    return 0;
}