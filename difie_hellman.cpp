#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL modPow(LL base, LL exp, LL modulo) {
	LL result = 1;
	while (exp>0) {
		if (exp & 1) result = (result * base)%modulo;
		base = (base*base)%modulo;
		exp >>= 1;
	}
	return result;
}

int main() {
	int n, g, x, y, a, b;
	cout << "Diffie Hellman\nEnter public key :\n\nn(prime number) : ";
	cin >> n;
	cout << "g(prime number) : "; cin >> g;
	
	cout << "\nchoose random number for A : "; cin >> x;
	cout << "choose random number for B : "; cin >> y;
	cout << "\nSend " << (a=modPow(g, x, n)) << " to B\n";
	cout << "Send " << (b=modPow(g, y, n)) << " to A\n\n";
	cout << "Corresponding key : k1 k2 : ";
	cout << modPow(b, x, n) << "  " << modPow(a, y, n) << endl; 
	return 0;
}	
