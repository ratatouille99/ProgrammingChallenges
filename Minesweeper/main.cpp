//Esta es la forma mas eficiente de realizar el Buscaminas ya que reducimos drasticamente
//el overherad(tiempo, espacio, etc)
#include <iostream>

using namespace std;

int n, m;
const int NMAX = 101;

char A[NMAX][NMAX];

int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

int main(){

    cin>>n>>m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>A[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i][j] == '*'){
                cout<<'*';
                continue;
            }
            int ans = 0;

            for(int k = 0; k < 8; k++){
                int ix = i + dx[k];
                int jy = j + dy[k];

                if(ix >= 0 && ix < n && jy >= 0 && jy < m && A[ix][jy] == '*') ans++;
            }

            cout<<ans;
        }
        cout<<endl;
    }
}
