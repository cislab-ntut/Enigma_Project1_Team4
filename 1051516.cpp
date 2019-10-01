#include <iostream>
#include <string>
#include<fstream>
using namespace std;

string plugboard = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string I = "EKMFLGDQVZNTOWYHXUSPAIBRCJ", I_re = "UWYGADFPVZBECKMTHXSLRINQOJ";
string II = "AJDKSIRUXBLHWTMCQGZNPYFVOE", II_re = "AJPCZWRLFBDKOTYUQGENHXMIVS";
string III = "BDFHJLCPRTXVZNYEIWGAKMUSQO", III_re = "TAGBPCSDQEUFVNZHYIXJWLRKOM";
string IV = "ESOVPZJAYQUIRHXLNFTGKDCMWB", IV_re = "HZWVARTNLGUPXQCEJMBSKDYOIF";
string V = "VZBRGITYUPSDNHLXAWMJQOFECK", V_re = "QCYLXWENFTZOSMVJUDKGIARPHB";
string reflactor = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
string rotorI, rotorII, rotorIII, rotorI_re, rotorII_re, rotorIII_re;
char now_rotorI, now_rotorII, now_rotorIII, pt_rotorI, pt_rotorII, pt_rotorIII, I_pt = 'Q', II_pt = 'E', III_pt = 'V', IV_pt = 'J', V_pt = 'Z';
fstream fp;
string key = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void set_rotorI(int in) {
	switch (in) {
	case 1:
		rotorI = I;
		rotorI_re = I_re;
		pt_rotorI = I_pt;
		break;
	case 2:
		rotorI = II;
		rotorI_re = II_re;
		pt_rotorI = II_pt;
		break;
	case 3:
		rotorI = III;
		rotorI_re = III_re;
		pt_rotorI = III_pt;
		break;
	case 4:
		rotorI = IV;
		rotorI_re = IV_re;
		pt_rotorI = IV_pt;
		break;
	case 5:
		rotorI = V;
		rotorI_re = V_re;
		pt_rotorI = V_pt;
		break;
	}
}

void set_rotorII(int in) {
	switch (in) {
	case 1:
		rotorII = I;
		rotorII_re = I_re;
		pt_rotorII = I_pt;
		break;
	case 2:
		rotorII = II;
		rotorII_re = II_re;
		pt_rotorII = II_pt;
		break;
	case 3:
		rotorII = III;
		rotorII_re = III_re;
		pt_rotorII = III_pt;
		break;
	case 4:
		rotorII = IV;
		rotorII_re = IV_re;
		pt_rotorII = IV_pt;
		break;
	case 5:
		rotorII = V;
		rotorII_re = V_re;
		pt_rotorII = V_pt;
		break;
	}
}

void set_rotorIII(int in) {
	switch (in) {
	case 1:
		rotorIII = I;
		rotorIII_re = I_re;
		pt_rotorIII = I_pt;
		break;
	case 2:
		rotorIII = II;
		rotorIII_re = II_re;
		pt_rotorIII = II_pt;
		break;
	case 3:
		rotorIII = III;
		rotorIII_re = III_re;
		pt_rotorIII = III_pt;
		break;
	case 4:
		rotorIII = IV;
		rotorIII_re = IV_re;
		pt_rotorIII = IV_pt;
		break;
	case 5:
		rotorIII = V;
		rotorIII_re = V_re;
		pt_rotorIII = V_pt;
		break;
	}
}

void set_plugboard(char a, char b, char c, char d, char e, char f, char g, char h, char z, char j, char k, char l) {
	plugboard = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string p1 = {a,b};
	string p2 = { c,d };
	string p3 = { e,f };
	string p4 = { g,h };
	string p5 = { z,j };
	string p6 = { k,l };
	string plugboard_in, save[26];
	int i = 6;
	for (int i = 0; i != 26; i++)
		save[i] = '0';
	while (i != 0) {
		if(i==6)
			plugboard_in = p1;
		else if (i == 5)
			plugboard_in = p2;
		else if (i == 4)
			plugboard_in = p3;
		else if (i == 3)
			plugboard_in = p4;
		else if (i == 2)
			plugboard_in = p5;
		else if (i == 1)
			plugboard_in = p6;
		cout << plugboard_in<<" ";
		fp << plugboard_in << " ";
		if (save[plugboard_in[0] - 'A'] == "1" || save[plugboard_in[1] - 'A'] == "1") {
			cout << "輸入錯誤" << endl;
			i++;
		}
		else {
			plugboard[plugboard_in[0] - 'A'] = plugboard_in[1];
			plugboard[plugboard_in[1] - 'A'] = plugboard_in[0];
			save[plugboard_in[0] - 'A'] = '1';
			save[plugboard_in[1] - 'A'] = '1';
		}
		i--;
	}
	cout << endl;
	fp<<endl;
}

char plugboard_c(char in) {
	return plugboard[in - 'A'];
}
char rotorI_c(char in, int signal) {
	if (signal == 0) {
		in = now_rotorI + in - 'A';
		if (in - 'A' >= 26)
			in = in - 26;
		in = rotorI[in - 'A'];
		in = in - now_rotorI + 'A';
		if (in < 0 + 'A')
			in = in + 26;
		return in;
	}
	else {
		in = now_rotorI + in - 'A';
		if (in - 'A' >= 26)
			in = in - 26;
		in = rotorI_re[in - 'A'];
		in = in - now_rotorI + 'A';
		if (in < 0 + 'A')
			in = in + 26;
		return in;
	}
}
char rotorII_c(char in, int signal) {
	if (signal == 0) {
		in = now_rotorII + in - 'A';
		if (in - 'A' >= 26)
			in = in - 26;
		in = rotorII[in - 'A'];
		in = in - now_rotorII + 'A';
		if (in < 0 + 'A')
			in = in + 26;
		return in;
	}
	else {
		in = now_rotorII + in - 'A';
		if (in - 'A' >= 26)
			in = in - 26;
		in = rotorII_re[in - 'A'];
		in = in - now_rotorII + 'A';
		if (in < 0 + 'A')
			in = in + 26;
		return in;
	}
}
char rotorIII_c(char in, int signal) {
	if (signal == 0) {
		in = now_rotorIII + in - 'A';
		if (in - 'A' >= 26)
			in = in - 26;
		in = rotorIII[in - 'A'];
		in = in - now_rotorIII + 'A';
		if (in < 0 + 'A')
			in = in + 26;
		return in;
	}
	else {
		in = now_rotorIII + in - 'A';
		if (in - 'A' >= 26)
			in = in - 26;
		in = rotorIII_re[in - 'A'];
		in = in - now_rotorIII + 'A';
		if (in < 0 + 'A')
			in = in + 26;
		return in;
	}
}
char reflactor_c(char in) {
	return reflactor[in - 'A'];
}

int main() {
	char a, b, c, d, e, f, g, h, i, j, k, l;
	char filename[] = "Answer.txt";
	fp.open(filename, ios::out | ios::app);//開啟檔案
	if (!fp) {//如果開啟檔案失敗，fp為0；成功，fp為非0
		cout << "Fail to open file: " << filename << endl;
	}
	set_rotorI(1);
	set_rotorII(2);
	set_rotorIII(5);
	for (int key1 = 0; key1 < 26; ++key1)
	{
		for (int key2 = 0; key2 < 26; ++key2)
		{
			for (int key3 = 0; key3 < 26; ++key3)
			{
				now_rotorI = key[key1];
				now_rotorII = key[key2];
				now_rotorIII = key[key3];
				cout << now_rotorI << now_rotorII << now_rotorIII << endl;
				fp << now_rotorI << now_rotorII << now_rotorIII << endl;
				for (int m = 0; m < 26; m++)
				{
					a = m + 65;
					if (a > 79)
						break;
					for (int n = 0; n < 25; n++)
					{
						b = m + n + 66;
						if (b > 90)
							break;
						for (int o = 0; o < 24; o++)
						{
							c = m + n + o + 67;
							if (c > 90)
								break;
							for (int p = 0; p < 23; p++)
							{
								d = m + n + o + p + 68;
								if (d > 90)
									break;
								for (int q = 0; q < 22; q++)
								{
									e = m + n + o + p + q + 69;
									if (e > 90)
										break;
									for (int r = 0; r < 21; r++)
									{
										f = m + n + o + p + q + r + 70;
										if (f > 90)
											break;
										for (int s = 0; s < 20; s++)
										{
											g = m + n + o + p + q + r + s + 71;
											if (g > 90)
												break;
											for (int t = 0; t < 19; t++)
											{
												h = m + n + o + p + q + r + s + t + 72;
												if (h > 90)
													break;
												for (int u = 0; u < 18; u++)
												{
													i = m + n + o + p + q + r + s + t + u + 73;
													if (i > 90)
														break;
													for (int v = 0; v < 17; v++)
													{
														j = m + n + o + p + q + r + s + t + u + v + 74;
														if (j > 90)
															break;
														for (int w = 0; w < 16; w++)
														{
															k = m + n + o + p + q + r + s + t + u + v + w + 75;
															if (k > 90)
																break;
															for (int x = 0; x < 15; x++)
															{
																l = m + n + o + p + q + r + s + t + u + v + w + x + 76;
																if (l > 90)
																	break;
																set_plugboard(a, b, c, d, e, f, g, h, i, j, k, l);
																string decode = "IPQHUGCXZM";
																for (int l = 0; l != decode.size(); l++)
																{
																	char code = decode[l];
																	if (now_rotorIII == pt_rotorIII)
																	{
																		now_rotorII++;
																		if (now_rotorII - 'A' > 25)
																			now_rotorII = now_rotorII - 26;
																	}
																	else if (now_rotorII == pt_rotorII)
																	{
																		now_rotorI++;
																		if (now_rotorI - 'A' > 25)
																			now_rotorI = now_rotorI - 26;
																		now_rotorII++;
																		if (now_rotorII - 'A' > 25)
																			now_rotorII = now_rotorII - 26;
																	}
																	now_rotorIII++;
																	if (now_rotorIII - 'A' > 25)
																		now_rotorIII = now_rotorIII - 26;

																	code = plugboard_c(code);
																	code = rotorIII_c(code, 0);
																	code = rotorII_c(code, 0);
																	code = rotorI_c(code, 0);
																	code = reflactor_c(code);
																	code = rotorI_c(code, 1);
																	code = rotorII_c(code, 1);
																	code = rotorIII_c(code, 1);
																	code = plugboard_c(code);
																	cout << code;
																	fp << code;
																}
																cout << endl;
																fp << endl;
															}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			
		}
	}
	
	fp.close();
	return 0;
}
