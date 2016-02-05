#include <bits/stdc++.h>
using namespace std;

string key, cipher, str, ptext;
int n, i, j, kn, matid, rw, cl;
char mat[5][5];
unordered_map<char, int> pos;

void create_key_matrix() {
	//Matrix creation
	matid = 0;
	for (i=0; i<kn; i++) {
		//special case for key[i] == i/j
		if ((key[i] == 'i') || (key[i] == 'j')) {
			if ((pos.find('i') == pos.end()) && (pos.find('j') == pos.end())) {
				pos.insert(make_pair(key[i], matid));
				rw = matid/5; cl = matid%5;
				mat[rw][cl] = key[i];
				matid++;
			}	
		}	
		else if (pos.find(key[i]) == pos.end()) {
			pos.insert(make_pair(key[i], matid));
			rw = matid/5; cl = matid%5;
			mat[rw][cl] = key[i];
			matid++;
		}	
	}	
	
	for (char ch='a'; ch<='z'; ch++) {
		if ((ch == 'i') || (ch == 'j')) {
			if ((pos.find('i') == pos.end()) && (pos.find('j') == pos.end())) {
				pos.insert(make_pair(ch, matid));
				rw = matid/5; cl = matid%5;
				mat[rw][cl] = ch;
				matid++;
			}	
		}
		
		else if (pos.find(ch) == pos.end()) {
			pos.insert(make_pair(ch, matid));
			rw = matid/5; cl = matid%5;
			mat[rw][cl] = ch;
			matid++;
		}
	}	
}		


void display_key_matrix() {
	cout << "\nkey matrix\n";
	for (i=0; i<5; i++) {
		for (j=0; j<5; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}	
}

void create_playfair_input() {
	int sz = str.size();
	
	for (i=0; i<(sz-1); ) {
		if (str[i] != str[i+1]) {
			ptext = ptext + str[i] + str[i+1];
			i+=2;
		}
		else {
			ptext = ptext + str[i] + 'x';
			i++;
		}
	}
	if (i == sz-1) {
		ptext = ptext + str[i] + 'x';
	}
}



void create_cipher() {
	int sz = ptext.size(), r1, c1, r2, c2, p;
	
	for (i=0; i<sz; i+=2) {
		p = pos[ptext[i]];
		r1 = p/5; c1 = p%5; 
		p = pos[ptext[i+1]];
		r2 = p/5; c2 = p%5;
		
		if (r1 == r2) { 
			c1 = (c1+1)%5; 
			c2 = (c2+1)%5;
		}	
		else if (c1 == c2) {
			r1 = (r1+1)%5; 
			r2 = (r2+1)%5;
		}	
		else {
			p = c1;
			c1 = c2;
			c2 = p;
		}
		cipher = cipher + mat[r1][c1] + mat[r2][c2];
	}
}			

void decrypt() {
	int sz = cipher.size(), r1, c1, r2, c2, p;
	string txt;
	ptext.clear();
	
	for (i=0; i<sz; i+=2) {
		p = pos[cipher[i]];
		r1 = p/5; c1 = p%5; 
		p = pos[cipher[i+1]];
		r2 = p/5; c2 = p%5;
		
		if (r1 == r2) { 
			c1 = (c1+4)%5; 
			c2 = (c2+4)%5;
		}	
		else if (c1 == c2) {
			r1 = (r1+4)%5; 
			r2 = (r2+4)%5;
		}	
		else {
			p = c1;
			c1 = c2;
			c2 = p;
		}
		txt = txt + mat[r1][c1] + mat[r2][c2];
	}
	
	//remove all x
	for (i=0; i<sz; i++) {
		if (txt[i] != 'x') {
			ptext = ptext + txt[i];
		}	
	}		
}			

int main() {
	cout << "Playfair Cipher\n\n--Encryption--\nEnter key text : ";
	cin >> key; kn = key.size();
	
	create_key_matrix();
	
	display_key_matrix();
	
	cout << "\nEnter plain text : ";
	cin >> str;
	
	create_playfair_input();
	
	create_cipher();
	
	cout << "\nCipher text : " << cipher << endl;
	
	cout << "\n--Decryption--\nEnter cipher text : ";
	cin >> cipher;
	
	decrypt();
	
	cout << "\nPlain text : " << ptext << endl;
	
	return 0;
}
