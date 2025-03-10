#include <iostream> 
using namespace std;
 
int main(void)
{
    int sec_input;
    int s_sum=0;
    int ans_min;
    int ans_sec;

    for(int i=0; i<4;i++){
        cin >>sec_input;
        s_sum+=sec_input;
    }
    ans_min = s_sum/60;
    ans_sec = s_sum-ans_min*60;
    cout<< ans_min <<endl;
    cout<< ans_sec <<endl;
    return 0;
}