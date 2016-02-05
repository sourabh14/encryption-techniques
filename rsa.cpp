#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define HIGH 100000			// set this as max value upto prime calculation

bool isprime[HIGH];

LL modPow(LL base, LL exp, LL modulo) {
	LL result = 1;
	while (exp>0) {
		if (exp & 1) result = (result * base)%modulo;
		base = (base*base)%modulo;
		exp >>= 1;
	}
	return result;
}

void sieve() {
	LL i, j;
	memset(isprime,1,sizeof(isprime));
	isprime[0] = 0;
	isprime[1] = 0;
	for (i=2; i*i<=HIGH; i++) {
		if (isprime[i] == 1) { 				// if it is prime
			for (j=i*2; j<=HIGH; j+=i) {
				isprime[j] = 0;				//all its multiples are marked 0
			}	
		}
	}
}	

LL calculate_e(LL phi) {
	// (1 < e < phi) and gcd(e, phi) == 1
	LL i;
	for (i=2; i<phi; i++) {
		if (isprime[i] && ((phi % i) != 0)) {
			return i;
		}
	}
	//if not found return -1
	return -1;
}		

LL ext_gcd(LL a, LL b, LL &x, LL &y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	LL x1, y1; 
	LL d = ext_gcd(b%a, a, x1, y1);
	x = y1 - (b/a) * x1;
	y = x1;
	return d;	
}	

LL mod_mult_inverse(LL a, LL m) {
	//(a*x) % m == 1
	LL x, y;
	ext_gcd(a, m, x, y);	
	if (x<0) x+=m;
	return x;
}		

int main() {
	LL p, q, n, phi, e, d, pt, ct;
	
	//calculate prime upto HIGH
	sieve();
	
	//input
	cout << "RSA algorithm\nEnter two prime numbers :\n";
	cout << "p "; cin >> p;
	cout << "q "; cin >> q;
	n = p*q;
	phi = (p-1)*(q-1);
	
	//calculate e
	e = calculate_e(phi);
	
	//calculate d
	d = mod_mult_inverse(e, phi);
	
	cout << "\npublic key (n,e): (" << n << ", " << e << ")" << endl;
	cout << "private key : " << d << endl;
	
	cout << "\n--Encryption--\nEnter any no: ";
	cin >> pt;
	cout << "Encrypted no: " << modPow(pt, e, n) <<endl;
	
	cout << "\n--Decryption--\nEnter cipher no: ";
	cin >> ct;
	cout << "Plain no: " << modPow(ct, d, n) << endl;
	
	return 0;
}	
