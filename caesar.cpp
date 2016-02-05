#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	int n, i;
	cout << "Caesar Cipher\n\nEncryption\nEnter text : ";
	cin >> str; n = str.size();
	for (i=0; i<n; i++) {
		str[i] = (char) ((((str[i] - 'a') + 3) % 26) + 'a');
	}
	cout << "Cipher text : " << str << endl;
	
	cout << "\nDecryption\nEnter cipher text : ";
	cin >> str; n = str.size();
	for (i=0; i<n; i++) {
		str[i] = (char) ((((str[i] - 'a') + 23) % 26) + 'a');
	}
	cout << "Plain text : " << str << endl;	
	return 0;
}	
