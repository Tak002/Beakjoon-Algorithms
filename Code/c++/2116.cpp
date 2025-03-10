//제출 코드: https://www.acmicpc.net/source/91030198

#include <iostream> 
using namespace std;

int getMax(int bottomID, int dice[]);
int getOppsiteID(int upsideValue, int upperDice[]);
int sides[6][4]={
    {1,2,3,4},
    {0,2,4,5},
    {0,1,3,5},
    {0,2,4,5},
    {0,1,3,5},
    {1,2,3,4}
};
int oppisite[6]={5,3,4,1,2,0};

int main(void)
{   
    int ret=0;
    int n; cin>>n;
    int **dices = new int*[n];
    for (int i=0; i<n;i++){
        dices[i] = new int[6];
        for (int j=0; j<6; j++){
            cin>>dices[i][j];
        }
    }
    for (int i=0; i<6;i++){
        int bottomID = i;
        int upsideValue;
        int sumValue=0;

        for(int j=0; j<n-1;j++){
            sumValue+=getMax(bottomID,dices[j]);
            upsideValue = dices[j][oppisite[bottomID]];
            bottomID = getOppsiteID(upsideValue,dices[j+1]);
        }
        sumValue+=getMax(bottomID,dices[n-1]);

        if (sumValue>ret)ret=sumValue;
    }
    cout<<ret;
    return 0;
}

int getMax(int bottomID, int dice[]){
    int max=0;
    for(int i=0; i<4;i++){
        if(dice[sides[bottomID][i]]>max){
            max = dice[sides[bottomID][i]];
        }
    }
    return max;
}

int getOppsiteID(int upsideValue, int upperDice[]){
    for(int i=0; i<6;i++){
        if (upperDice[i] ==  upsideValue){
            return i;
        }
    }
    return -1;
}

