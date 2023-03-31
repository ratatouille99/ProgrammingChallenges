#include <iostream>

typedef long long ll;

using namespace std;

int main()
{
    ll i , j, suma = 0, mayor = 0;

    while(cin>>i>>j){
        ll k = i;
        ll inicio = i, final = j;

        while(i <= j){
            while(k != 1){
                if(k % 2 == 0){
                    k /= 2;
                    suma++;
                }
                else{
                    k = (k * 3) + 1;
                    suma++;
                }
            }

            if(suma > mayor) mayor = suma;

            suma = 0;
            i++;
            k = i;
        }

        cout<<inicio<<' '<<final<<' '<<mayor + 1<<endl;
    }



    return 0;
}
