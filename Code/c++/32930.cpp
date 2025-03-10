#include <iostream> 
using namespace std;
 
int main(void)
{
    int n, m, maxdistance, distance, maxpoint,ret=0;
    cin>>n>>m;
    int x=0, y=0;
    int points[200][2];
    bool empty[200]={false,};

    for(int i=0; i<n+m;i++){
        cin>>points[i][0]>>points[i][1];
    }

    for(int i=0;i<m;i++){
        maxdistance=0;
        
        for(int k=0; k<i+n;k++){
            if(!empty[k]){
                distance = (x-points[k][0])*(x-points[k][0]) + (y-points[k][1])*(y-points[k][1]);
                if(distance>maxdistance){
                    maxdistance=distance;
                    maxpoint = k;
                }
            }
        }
        empty[maxpoint] = true;
        x= points[maxpoint][0];
        y= points[maxpoint][1];
        ret +=maxdistance;
    }
    cout<<ret;
    return 0;
}