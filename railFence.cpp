#include <bits/stdc++.h>
using namespace std;

int main() {
	string str, cipher;
	int n, i, j;
	cout << "Rail Fence Cipher\n\nEncryption\nEnter text : ";
	cin >> str; n = str.size();
	for (i=0; i<n; i+=2) cipher += str[i];
	for (i=1; i<n; i+=2) cipher += str[i];
	cout << "Cipher text : " << cipher << endl;
	
	
	cout << "\nDecryption\nEnter cipher text : ";
	cin >> cipher; n = cipher.size();
	string plain(n, ' ');
	for (i=0, j=0; j<n; j+=2, i++) plain[j] = cipher[i]; 
	for (j=1; j<n; j+=2, i++) plain[j] = cipher[i]; 
	cout << "Plain text : " << plain << endl;	
	return 0;
}
