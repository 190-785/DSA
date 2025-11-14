#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t; 
	cin >> t;
	while (t--)
	{
		long long x, d; 
		cin >> x >> d;

		long long finalPos;
		if (d % 4 == 1)
			finalPos = -d; 
		else if (d % 4 == 2)
			finalPos = 1; 
		else if (d % 4 == 3)
			finalPos = d + 1; 
		else if (d % 4 == 0)
			finalPos = 0; 
		if (x % 2 == 0)
			finalPos = x + finalPos; 
		else
			finalPos = x - finalPos; 
		cout << finalPos << endl; 
	}
	return 0;
}
