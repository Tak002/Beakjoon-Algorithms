#include <iostream> 
using namespace std;
 
int main(void)
{
    long n; cin>>n;
    long m; cin>>m;
    long long a;
    long long ans=1;
    for(int i=0; i<n;i++){
        cin>>a;
        a= a%m;
        ans = (ans * a)%m;
    }
    cout<<ans;
    return 0;
}