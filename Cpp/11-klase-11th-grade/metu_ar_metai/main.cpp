#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (((n>=10) && (n<=20) || (n%10==0))||((n>=110) && (n<=120) || (n%100==0))) {
        cout <<n<< " metu"<<endl;}
    else
        cout <<n<<" metai"<<endl;
    return 0;
}
