#include <iostream> 
#include <set>
using namespace std;
 
int main(void)
{
    int n; cin>>n;
    int m; cin>>m;
    int classId;
    set<int>::iterator iter;
    set<int> *setClass = new set<int>[m];
    set<int> *setStudent = new set<int>[n];

    int *max_n = new int[m];
    for (int i=0; i< m; i++){
        cin>>max_n[i];
    }
    for(int j=0; j<2; j++){
        for(int i=0; i<n; i++){
            cin>>classId;
            while(classId!=-1){
                setClass[classId-1].insert(i);
                cin>>classId;
            }
        }
        for(int i=0; i<m;i++){
            if(setClass[i].size()<=max_n[i]){
                for(iter = setClass[i].begin(); iter!=setClass[i].end();iter++){
                    setStudent[*iter].insert(i);
                }
                
            }
        }
    }
    for(int i=0; i<n;i++){
        if(setStudent[i].size()==0){
            cout<<"망했어요"<<endl;
        }
        else{
            for(iter = setStudent[i].begin(); iter!=setStudent[i].end();iter++){
            cout<<*iter + 1<<" ";
            }
            cout<<endl;
        }
    }
}