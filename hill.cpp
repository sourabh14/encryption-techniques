#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
string text, cipher;
int mat[3][3], matInv[3][3], i, j;

LL modPow(LL base, LL exp, LL modulo) {
	LL result = 1;
	while (exp>0) {
		if (exp & 1) result = (result * base)%modulo;
		base = (base*base)%modulo;
		exp >>= 1;
	}
	return result;
}		

int gcd(int a, int b) {		
	if (a == 0) return b;
	return gcd(b%a, a);
}	

bool findInverse() {
	int det=0, detInv;
	for(i=0; i<3; i++) {
		det = det + (mat[0][i]*(mat[1][(i+1)%3]*mat[2][(i+2)%3] 
								- mat[1][(i+2)%3]*mat[2][(i+1)%3]));
	}							
	
	if (gcd(det, 26) != 1) return false;		//inverse not possible
	
	detInv = modPow(det, 11, 26); 
	if (detInv < 0) detInv += 26;
	
	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			matInv[j][i] = ( (mat[(i+1)%3][(j+1)%3] * mat[(i+2)%3][(j+2)%3]) - 
							 (mat[(i+1)%3][(j+2)%3] * mat[(i+2)%3][(j+1)%3]) );
							 
			matInv[j][i] = (matInv[j][i] * detInv) % 26;
			if (matInv[j][i] < 0) matInv[j][i] += 26;					
		}
	}							
    
    return true;   
}	

string getCipher() {
	string ret(3, ' ');
	int k1=text[0]-'a', k2=text[1]-'a', k3=text[2]-'a', k;
	for (i=0; i<3; i++) {
		k = mat[i][0]*k1 + mat[i][1]*k2 + mat[i][2]*k3; 
		k %= 26;
		ret[i] = k+'a';
	}	
	return ret;
}

string getPlain() {
	string ret(3, ' ');
	int k1=cipher[0]-'a', k2=cipher[1]-'a', k3=cipher[2]-'a', k;
	for (i=0; i<3; i++) {
		k = matInv[i][0]*k1 + matInv[i][1]*k2 + matInv[i][2]*k3; 
		k %= 26;
		ret[i] = k+'a';
	}	
	return ret;
}	

int main() {
	cout << "Hill Cipher\n\n--Encryption--\nEnter 3X3 key matrix : \n";
	for (i=0; i<3; i++) for (j=0; j<3; j++) cin >> mat[i][j];
	
	if (!findInverse()) {
		cout << "\nwrong key matrix, inverse not possible\n aborted\n";
		return 0;
	}	
	
	cout << "\nEnter text(3 char) : "; cin >> text;
	cout << "Cipher text : " << getCipher() << endl;
	
	cout << "\n--Decryption--\nEnter Cipher text : "; cin >> cipher;
	cout << "Plain text : " << getPlain() << endl;
	
	return 0;
}	
