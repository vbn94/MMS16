#include <iostream>

using namespace std;



int main()

{

    int n;

    cout << "Enter n: ";

    cin >> n;



    for (int i = 1; i <= n; i++)

    {

        for (int j = 1; j <= i; j++)

        {

            for (int k = n - i -1; k >= 0; k--)

            {

                cout << " ";

            }

             cout << "$" << " ";   

        }

        cout << endl;

    }

    return 0;

}