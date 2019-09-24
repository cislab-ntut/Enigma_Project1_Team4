#include <iostream>
#include <string>
using namespace std;

string plugboard="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string I="EKMFLGDQVZNTOWYHXUSPAIBRCJ",I_re="UWYGADFPVZBECKMTHXSLRINQOJ";
string II="AJDKSIRUXBLHWTMCQGZNPYFVOE",II_re="AJPCZWRLFBDKOTYUQGENHXMIVS";
string III="BDFHJLCPRTXVZNYEIWGAKMUSQO",III_re="TAGBPCSDQEUFVNZHYIXJWLRKOM";
string IV="ESOVPZJAYQUIRHXLNFTGKDCMWB",IV_re="HZWVARTNLGUPXQCEJMBSKDYOIF";
string V="VZBRGITYUPSDNHLXAWMJQOFECK",V_re="QCYLXWENFTZOSMVJUDKGIARPHB";
string reflactor="YRUHQSLDPXNGOKMIEBFZCWVJAT";
string rotorI,rotorII,rotorIII,rotorI_re,rotorII_re,rotorIII_re;
char now_rotorI,now_rotorII,now_rotorIII,pt_rotorI,pt_rotorII,pt_rotorIII,I_pt='Q',II_pt='E',III_pt='V',IV_pt='J',V_pt='Z';

void set_rotorI(int in){
	switch (in){
		case 1:
			rotorI=I;
			rotorI_re=I_re;
			pt_rotorI=I_pt;
			break;
		case 2:
			rotorI=II;
			rotorI_re=II_re;
			pt_rotorI=II_pt;
			break;
		case 3:
			rotorI=III;
			rotorI_re=III_re;
			pt_rotorI=III_pt;
			break;
		case 4:
			rotorI=IV;
			rotorI_re=IV_re;
			pt_rotorI=IV_pt;
			break;
		case 5:
			rotorI=V;
			rotorI_re=V_re;
			pt_rotorI=V_pt;
			break;		
	}
}

void set_rotorII(int in){	
	switch (in){
		case 1:
			rotorII=I;
			rotorII_re=I_re;
			pt_rotorII=I_pt;
			break;
		case 2:
			rotorII=II;
			rotorII_re=II_re;
			pt_rotorII=II_pt;
			break;
		case 3:
			rotorII=III;
			rotorII_re=III_re;
			pt_rotorII=III_pt;
			break;
		case 4:
			rotorII=IV;
			rotorII_re=IV_re;
			pt_rotorII=IV_pt;
			break;
		case 5:
			rotorII=V;
			rotorII_re=V_re;
			pt_rotorII=V_pt;
			break;		
	}
}

void set_rotorIII(int in){
	switch (in){
		case 1:
			rotorIII=I;
			rotorIII_re=I_re;
			pt_rotorIII=I_pt;
			break;
		case 2:
			rotorIII=II;
			rotorIII_re=II_re;
			pt_rotorIII=II_pt;
			break;
		case 3:
			rotorIII=III;
			rotorIII_re=III_re;
			pt_rotorIII=III_pt;
			break;
		case 4:
			rotorIII=IV;
			rotorIII_re=IV_re;
			pt_rotorIII=IV_pt;
			break;
		case 5:
			rotorIII=V;
			rotorIII_re=V_re;
			pt_rotorIII=V_pt;
			break;
	}
}

void set_plugboard(){
	string plugboard_in,save[26];
	int i=6;
	for(int i=0;i!=26;i++)
		save[i]='0';
	while(i!=0){
		cout << "請輸入一對字母:";
		cin >> plugboard_in;
		if(save[plugboard_in[0]-'A']=="1"||save[plugboard_in[1]-'A']=="1"){
			cout << "輸入錯誤" << endl;
			i++;
		}
		else{
			plugboard[plugboard_in[0]-'A']=plugboard_in[1];
			plugboard[plugboard_in[1]-'A']=plugboard_in[0];
			save[plugboard_in[0]-'A']='1';
			save[plugboard_in[1]-'A']='1';
		}
		i--;
	}
}

char plugboard_c(char in){
		return plugboard[in-'A'];
}
char rotorI_c(char in,int signal){
	if (signal==0){
		in=now_rotorI+in-'A';
		if(in-'A'>=26)
			in=in-26;
		in=rotorI[in-'A'];
		in=in-now_rotorI+'A';
		if(in < 0+'A')
			in=in+26;
		return in;
	}
	else{
		in=now_rotorI+in-'A';
		if(in-'A'>=26)
			in=in-26;
		in=rotorI_re[in-'A'];
		in=in-now_rotorI+'A';
		if(in < 0+'A')
			in=in+26;
		return in;
	}
}
char rotorII_c(char in,int signal){
	if (signal==0){
		in=now_rotorII+in-'A';
		if(in-'A'>=26)
			in=in-26;
		in=rotorII[in-'A'];
		in=in-now_rotorII+'A';
		if(in < 0+'A')
			in=in+26;
		return in;
	}
	else{
		in=now_rotorII+in-'A';
		if(in-'A'>=26)
			in=in-26;
		in=rotorII_re[in-'A'];
		in=in-now_rotorII+'A';
		if(in < 0+'A')
			in=in+26;
		return in;
	}
}
char rotorIII_c(char in,int signal){
	if (signal==0){
		in=now_rotorIII+in-'A';
		if(in-'A'>=26)
			in=in-26;
		in=rotorIII[in-'A'];
		in=in-now_rotorIII+'A';
		if(in < 0+'A')
			in=in+26;
		return in;
	}
	else{
		in=now_rotorIII+in-'A';
		if(in-'A'>=26)
			in=in-26;
		in=rotorIII_re[in-'A'];
		in=in-now_rotorIII+'A';
		if(in < 0+'A')
			in=in+26;
		return in;
	}
}
char reflactor_c(char in){
	return reflactor[in-'A'];
}

int main(){
	int riI,riII,riIII;
	cout << "請由左至右輸入採用的rotor: ";
	cin >> riI >> riII >> riIII;
	cout << "請由左至右輸入rotor的起始位置: ";
	cin >> now_rotorI >> now_rotorII >> now_rotorIII;
	cout << "是否需要更改plugboard?(Y/N): ";
	char yon;
	cin >> yon;
	if(yon=='Y'){
		set_plugboard();
	}
	set_rotorI(riI);
	set_rotorII(riII);
	set_rotorIII(riIII);	
	string decode;
	cout << "請輸入: "; 
	while (cin>>decode){
		if(decode=="EXIT")
			break;
		for(int i=0;i!=decode.size();i++){
			char code=decode[i];
			if(now_rotorIII==pt_rotorIII||now_rotorII==pt_rotorII){
				now_rotorII++;
				if(now_rotorII-'A'>25)
					now_rotorII=now_rotorII-26;
			}
			if(now_rotorII==pt_rotorII+1){
				now_rotorI++;
				if(now_rotorI-'A'>25)
					now_rotorI=now_rotorI-26;
			}
			now_rotorIII++;
			if(now_rotorIII-'A'>25)
				now_rotorIII=now_rotorIII-26;

			code=plugboard_c(code);
			code=rotorIII_c(code,0);
			code=rotorII_c(code,0);
			code=rotorI_c(code,0);
			code=reflactor_c(code);
			code=rotorI_c(code,1);
			code=rotorII_c(code,1);
			code=rotorIII_c(code,1);
			code=plugboard_c(code);
			cout << code;				
		}
		cout << endl;
	}	
	return 0;
}
