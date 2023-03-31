//En esta solucion usamos una solucion con un mapa anidado simulando una matriz sin embargo esto es ineficiente
//ya que toma demasiado overhead(tiempo, espacio en memoria,ancho de banda, etc)
#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n, m;

    while(cin>>n>>m){
        map<int,map<int,char>> A;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>A[i][j];
            }
        }

        for(int r = 0; r < n; r++, cout<<endl){
            for(int c = 0; c < m; c++){
                if(A[r][c] == '*'){
                    cout<<'*';
                    continue;
                }
                int ans = 0;
                for(int i = max(0, r-1); i <= min(n-1, r+1); i++){
                    for(int j = max(0, c-1); j <= min(m-1, c+1); j++){
                        if(A[i][j] == '*'){
                            ans++;
                        }
                    }
                }
                cout<<ans;
            }
        }
    }

    return 0;
}

