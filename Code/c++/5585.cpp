#include <iostream> 
using namespace std;
 
int main(void)
{
    int cost;
    int rest;
    int coins[6] = {500,100,50,10,5,1};
    int ans=0;
    int count;
    cin >>cost;
    rest = 1000-cost;
    for (int i=0; i<6; i++){
        while(rest>=coins[i]){
            count = rest/coins[i];
            rest-= (coins[i]*count);
            ans= ans+count;
        }
    }
    cout<<ans;
    return 0;
}