/*Standard input will contain the information for several trips. Each trip consists of a
line containing a positive integer n denoting the number of students on the trip. This is
followed by n lines of input, each containing the amount spent by a student in dollars
and cents. There are no more than 1000 students and no student spent more than
$10,000.00. A single line containing 0 follows the information for the last trip.*/

#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

void spent(int n);

int main()
{
    int n;

    while(cin>>n, n){
        spent(n);
    }


    return 0;
}

void spent(int n){

    double amount[n];
    int suma = 0;

    for(int i = 0; i < n; i++){
        cin>>amount[i];
        suma += (amount[i]*100);
    }

    int lowAvr = (suma/n);//900
    int highAvr = lowAvr + ((suma % n) ? 1 : 0);//calcula si hay un centavo restante

    int sumBelow = 0;
    int sumAbove = 0;

    for(int i = 0; i < n; i++){
        if((amount[i]*100) > highAvr) sumAbove += ((amount[i]*100) - highAvr);
    }

    for(int i = 0; i < n; i++){
        if((amount[i]*100) < lowAvr) sumBelow += (lowAvr - (amount[i]*100));
    }

    int result = max(sumAbove,sumBelow);

    cout<<'$'<<(result/100)<<'.'<<setw(2)<<setfill('0')<<(result%100)<<'\n';
}
