#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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

void set_plugboard(string plugboard_in){
	plugboard="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	plugboard[plugboard_in[0]-'A']=plugboard_in[1];
	plugboard[plugboard_in[1]-'A']=plugboard_in[0];
	plugboard[plugboard_in[2]-'A']=plugboard_in[3];
	plugboard[plugboard_in[3]-'A']=plugboard_in[2];
	plugboard[plugboard_in[4]-'A']=plugboard_in[5];
	plugboard[plugboard_in[5]-'A']=plugboard_in[4];
	plugboard[plugboard_in[6]-'A']=plugboard_in[7];
	plugboard[plugboard_in[7]-'A']=plugboard_in[6];
	plugboard[plugboard_in[8]-'A']=plugboard_in[9];
	plugboard[plugboard_in[9]-'A']=plugboard_in[8];
	plugboard[plugboard_in[10]-'A']=plugboard_in[11];
	plugboard[plugboard_in[11]-'A']=plugboard_in[10];
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
	string decode,startpoint;
	vector<string> sp;
	decode = "ZATVAWORBRQGRJSXZVNORWZBLORMEGRASLQLAFWXZYODVVTDHCIRDMNWOPNIXVKASIIIALOOSZXAMSYCQHYGPRLMSACGAWPCPAVZTMUUZCTJDVBUZAGFWMIVEZGBTLFIQDPPRZHDNKIPQHUGCXZM";
	int riI,riII,riIII;
	
	
	riI=4;
	riII=3;
	riIII=5;
	set_rotorI(riI);
	set_rotorII(riII);
	set_rotorIII(riIII);
	
	vector<string> plugboard_2;
	string save= "AB",plugboard_12;
	
	fstream out;
	out.open("out.txt",ios::out);

	startpoint = "AAA";
	while(startpoint[0]<='Z'){
		while(startpoint[1]<='Z'){
			while(startpoint[2]<='Z'){
				sp.push_back(startpoint);
				startpoint[2]++;
			}
			startpoint[2]='A';
			startpoint[1]++;
		}
		startpoint[1]='A';
		startpoint[0]++;
	}
	
	for(int i=save[0]-'A';i!=25;i++){
		for(int j=save[1]-'A';j!=26;j++){
			plugboard_2.push_back(save);
			save[1]++; 
		}
		save[0]++;
		save[1]=save[0]+1;
	}
	
	vector<string> plugboard_4;
	for(int i=0;i!=plugboard_2.size();i++){
		for(int j=i+1;j!=plugboard_2.size();j++){
			if(plugboard_2[i][0]!=plugboard_2[j][0]&&plugboard_2[i][0]!=plugboard_2[j][1]&&plugboard_2[i][1]!=plugboard_2[j][0]&&plugboard_2[i][1]!=plugboard_2[j][1]){
				plugboard_4.push_back(plugboard_2[i]+plugboard_2[j]);
			}
		}
	}
	
	vector<string> plugboard_6;
	for(int i=0;i!=plugboard_4.size();i++){
		for(int j=0;j!=plugboard_2.size();j++){
			if(plugboard_4[i][0]!=plugboard_2[j][0]&&plugboard_4[i][0]!=plugboard_2[j][1]&&plugboard_4[i][1]!=plugboard_2[j][0]&&plugboard_4[i][1]!=plugboard_2[j][1]&&
			   plugboard_4[i][2]!=plugboard_2[j][0]&&plugboard_4[i][2]!=plugboard_2[j][1]&&plugboard_4[i][3]!=plugboard_2[j][0]&&plugboard_4[i][3]!=plugboard_2[j][1]){
				plugboard_6.push_back(plugboard_4[i]+plugboard_2[j]);
			}
		}
	}
	
	char start_rotorI,start_rotorII,start_rotorIII;
	vector<char> ans;
	
	for(int k=0;k!=sp.size();k++){
	for(int i=0;i!=plugboard_6.size()-1;i++){
		for(int j=i+1;j!=plugboard_6.size();j++){
			if(plugboard_6[i][0]!=plugboard_6[j][0]&&plugboard_6[i][0]!=plugboard_6[j][1]&&plugboard_6[i][0]!=plugboard_6[j][2]&&plugboard_6[i][0]!=plugboard_6[j][3]&&plugboard_6[i][0]!=plugboard_6[j][4]&&plugboard_6[i][0]!=plugboard_6[j][5]&&
			   plugboard_6[i][1]!=plugboard_6[j][0]&&plugboard_6[i][1]!=plugboard_6[j][1]&&plugboard_6[i][1]!=plugboard_6[j][2]&&plugboard_6[i][1]!=plugboard_6[j][3]&&plugboard_6[i][1]!=plugboard_6[j][4]&&plugboard_6[i][1]!=plugboard_6[j][5]&&
			   plugboard_6[i][2]!=plugboard_6[j][0]&&plugboard_6[i][2]!=plugboard_6[j][1]&&plugboard_6[i][2]!=plugboard_6[j][2]&&plugboard_6[i][2]!=plugboard_6[j][3]&&plugboard_6[i][2]!=plugboard_6[j][4]&&plugboard_6[i][2]!=plugboard_6[j][5]&&
			   plugboard_6[i][3]!=plugboard_6[j][0]&&plugboard_6[i][3]!=plugboard_6[j][1]&&plugboard_6[i][3]!=plugboard_6[j][2]&&plugboard_6[i][3]!=plugboard_6[j][3]&&plugboard_6[i][3]!=plugboard_6[j][4]&&plugboard_6[i][3]!=plugboard_6[j][5]&&
			   plugboard_6[i][4]!=plugboard_6[j][0]&&plugboard_6[i][4]!=plugboard_6[j][1]&&plugboard_6[i][4]!=plugboard_6[j][2]&&plugboard_6[i][4]!=plugboard_6[j][3]&&plugboard_6[i][4]!=plugboard_6[j][4]&&plugboard_6[i][4]!=plugboard_6[j][5]&&
			   plugboard_6[i][5]!=plugboard_6[j][0]&&plugboard_6[i][5]!=plugboard_6[j][1]&&plugboard_6[i][5]!=plugboard_6[j][2]&&plugboard_6[i][5]!=plugboard_6[j][3]&&plugboard_6[i][5]!=plugboard_6[j][4]&&plugboard_6[i][5]!=plugboard_6[j][5]){
			   	ans.clear();
				plugboard_12=plugboard_6[i]+plugboard_6[j];
			   	now_rotorI=sp[k][0];
			   	now_rotorII=sp[k][1];
			   	now_rotorIII=sp[k][2];
			   	start_rotorI=sp[k][0];
			   	start_rotorII=sp[k][1];
			   	start_rotorIII=sp[k][2];
			   	set_plugboard(plugboard_12);
				for(int i=0;i!=decode.size();i++){
					char code=decode[i];
					if(now_rotorIII==pt_rotorIII||now_rotorII==pt_rotorII){
						now_rotorII++;
						if(now_rotorII-'A'>25)
							now_rotorII=now_rotorII-26;
					}
					if(now_rotorII==pt_rotorII){
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
					ans.push_back(code);				
				}
				if(ans[138]=='H'&&ans[139]=='E'&&ans[140]=='I'&&ans[141]=='L'&&ans[142]=='H'&&ans[143]=='I'&&ans[144]=='T'&&ans[145]=='L'&&ans[146]=='E'&&ans[147]=='R'){
					out << riI << " " <<  riII << " "  << riIII << endl;
					out << start_rotorI << " " <<  start_rotorII << " " << start_rotorIII << endl;
					out << plugboard_12 << endl;
					for(int i=0;i!=ans.size();i++){
						out << ans[i];
					}
					out << endl;
					cout << "Find it?" << endl;
				}
			}	
		}
	}
}
	return 0;
}
