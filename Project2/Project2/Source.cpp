#include <iostream>
#include<string>
#include <stack>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
int chuyenTuNhiPhanSangThapPhan(vector<int> nhiPhan)
{
	int thapPhan = 0;
	for (int i = 0; i < nhiPhan.size();i++)
	{
		thapPhan = thapPhan + nhiPhan.at(i) * pow(2, nhiPhan.size() - 1 - i);
	}
	return thapPhan;
}
int SauKhiDiQuaSBox(vector<int> motKhoi6Bit,int i)
{
	int c[2];
	vector<int> a;
	vector<int> b;
	int S1[64] = {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
				  0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
				  4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
				  15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13
				  };
	int S2[64] = { 15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
				  3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
				  0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
				  13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9 };
	int S3[64] = {10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
				  13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
				  13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
				  1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12};
	int S4[64] = {7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
				  13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
				  10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
				  3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14};
	int S5[64] = {2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
				  14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
				  4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
				  11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3};
	int S6[64] = {12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
				  10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
				  9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
				  4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13};
	int S7[64] = { 4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
				  13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
				  1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
				  6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12 };
	int S8[64] = { 13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
				   1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
				   7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
					2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11};
		
	for (int i = 0; i < 6; i++)
	{
		if (i == 0 || i == 5) {
			a.push_back(motKhoi6Bit.at(i));
		}
		else {
			b.push_back(motKhoi6Bit.at(i));
		}
	}
		c[0] = chuyenTuNhiPhanSangThapPhan(a);
		c[1] = chuyenTuNhiPhanSangThapPhan(b);
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				if (i == c[0] && j == c[i])
				{
					return;
				}
			}
		}
	}

vector<int> ShiftLeft(vector<int> a,int LanDich)
{
	int d = a.at(0);
	int e = a.at(1);
	int c[28];
	for (int i = 0; i < 28; i++)
	{
		c[i] = a.at(i);
	}
		if (LanDich == 1)
		{
			for (int i = 0; i < 28; i++)
			{
				if (i == 27)
				{
					c[i] = d;
					break;
				}
				c[i] = c[i + 1];
			}
		}
		if (LanDich == 2)
		{
			for (int i = 0; i < 28; i++)
			{
				if (i == 26)
				{
					c[i] = d;
					continue;
				}
				if (i == 27)
				{
					c[i] = e;
					break;
				}
				c[i] = c[i + 2];
			}
		}
		for (int i = 0; i < 28; i++)
		{
			a.at(i) = c[i];
		}
		return a;
}
vector<vector<int>> Tach_Ra_2_Mang_28BitLR(int a[56])
{
	vector<vector<int>> ss;
	vector<int> LI_1;
	vector<int> RI_1;
	for (int i = 0; i < 64; i++)
	{
		if (i >= 28)
		{
			RI_1.push_back(a[i]);
			continue;
		}
		if (i < 28) {
			LI_1.push_back(a[i]);
		}
	}
	ss.push_back(LI_1);
	ss.push_back(RI_1);
	return ss;
}

vector<int> QuaP_Box(vector<int> a)//mang vao 32 bit
{
	
	int c[32];
	int b[48];
	vector<int> TraVe;
	for (int i = 0; i < 32; i++)
	{
		c[i] = a.at(i);
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			b[6*i+j+1] = c[4*i+j];
		}
		for (int j = 0; j < 6; j++)
		{
			b[6 * i] = 0;
			b[6 * i + 5] = 0;
		}
	}
	int i = 0;
	while(i<49)
	{
		if (i == 0)
		{
			b[i] = a.at(31);
			i = i + 6;
			continue;
		}
		if (i == 48)
		{
			b[47] = a.at(0);
			break;
		}
		b[i] = b[i - 2];
		b[i - 1] = b[i + 1];
		i = i + 6;

	}
	for (int i = 0; i < 48; i++)
	{
		TraVe.push_back(b[i]);
	}
	
	return TraVe;
}
vector<vector<int>> Tach_Ra_2_Mang_32BitLR(int a[64])
{
	vector<vector<int>> ss;
	vector<int> LI_1;
	vector<int> RI_1;
	for (int i = 0; i < 64; i++)
	{
		if (i >= 32)
		{
			RI_1.push_back(a[i]);
			continue;
		}
		if (i < 32) {
			LI_1.push_back(a[i]);
		}
	}
	ss.push_back(LI_1);
	ss.push_back(RI_1);
	return ss;
}
stack<int> ChuyenSangSoNhiPhan8Bit(int a)
{
	int b = 0;
	stack<int> s;
	while (a / 2 != 0)
	{
		b = a % 2;
		s.push(b);
		a = a / 2;
	}
	s.push(a);
	while (s.size() < 8)
	{
		s.push(0);
	}
	return s;
}

int main(int argc, char** argv) {
	int s_box[8];
	int roundkey[56];
	vector<vector<int>> ss1;
	vector<int> kiemTra;
	vector<int> kiemTra1;
	vector<int> LI;
	vector<int> RI;
	vector<vector<int>> ss;
	string plainText;
	ifstream infile;
	infile.open("PlaintText.txt", ios_base::in);
	getline(infile, plainText, ',');
	infile.close();
	const char* plainTextChar = plainText.c_str();
	int _64BitPlainText[64];
	for (int i = 0; i < 8; i++)
	{
		stack<int> s = ChuyenSangSoNhiPhan8Bit(int(plainTextChar[i]));
		for (int j = 0; j < 8; j++)
		{
			_64BitPlainText[8 * i + j] = s.top();
			s.pop();
		}
	}
	//Sau khi hoan vi khoi tao Intial
	int IP[64] = { 58,50,42,34,26,18,10,2,
				   60,52,44,36,28,20,12,4,
			       62,54,46,38,30,22,14,6,
			       64,56,48,40,32,24,16,8,
			       57,49,41,33,25,17,9,1,
			       59,51,43,35,27,19,11,3,
			       61,53,45,37,29,21,13,5,
			       63,55,47,39,31,23,15,7 };
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			IP[8 * i + j] = _64BitPlainText[IP[8 * i + j]-1];
		}
	}
	cout << "\nSau khi di qua Initial permutation:\n";
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << IP[8 * i + j];
		}
		cout << "\n";
	}
	ss = Tach_Ra_2_Mang_32BitLR(IP);//tao ra 2 mang LI va RI
	LI = ss.at(0);//LI
	RI = ss.at(1);//RI
	//sau khi di qua p box
	//---------------------------------------------------------
	//tao key
	
	int _64BitKey[64];
	string key;
	ifstream infile;
	infile.open("Key.txt", ios_base::in);
	getline(infile, key, ',');
	infile.close();
	const char* Key = key.c_str();
	for (int i = 0; i < 8; i++)
	{
		stack<int> s = ChuyenSangSoNhiPhan8Bit(int(Key[i]));
		for (int j = 0; j < 8; j++)
		{
			_64BitKey[8 * i + j] = s.top();
			s.pop();
		}
	}
	int ParityDrop[56] = {  57,49,41,33,25,17,9,1,
							58,50,42,34,26,18,10,2,
							59,51,43,35,27,19,11,3,
							60,52,44,36,63,55,47,39,
							31,23,15,7,62,54,46,38,
							30,22,14,6,61,53,45,37,
							29,21,13,5,28,20,12,4 };
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			ParityDrop[8 * i + j] = _64BitKey[ParityDrop[8 * i + j] - 1];
		}
	}//xong parity drop
	ss1 = Tach_Ra_2_Mang_28BitLR(ParityDrop);
	kiemTra = ss1.at(0);
	kiemTra1 = ss1.at(1);
	for (int i = 1; i <= 2; i++) {
		int Key1[48] = { 14,17,11,24,1,5,3,28,
				   15,6,21,10,23,19,12,4,
				   26,8,16,7,27,20,13,2,
				   41,52,31,37,47,55,30,40,
				   51,45,33,48,44,49,39,56,
				   34,53,46,42,50,36,29,32 };
		if (i == 1 || i == 2 || i == 9 || i == 16) {
		for (int i = 0; i < 1; i++) {
			kiemTra = ShiftLeft(kiemTra, 1);
			kiemTra1 = ShiftLeft(kiemTra1, 1);
			}
			for (int i = 0; i < 28; i++)
			{
				
					roundkey[i] = kiemTra.at(i);
				
			}
			for (int i = 0; i < 28; i++)
			{
					roundkey[28+i] = kiemTra1.at(i);
				
			}
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					Key1[8 * i + j] = roundkey[Key1[8 * i + j] - 1];
				}
			}
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					cout << Key1[8 * i + j];
				}
				cout << "\n";
			}
		}
		else {
			for (int i = 0; i < 2; i++) {
				kiemTra = ShiftLeft(kiemTra, 1);
				kiemTra1 = ShiftLeft(kiemTra1, 1);
			}
			for (int i = 0; i < 28; i++)
			{

				roundkey[i] = kiemTra.at(i);

			}
			for (int i = 0; i < 28; i++)
			{
				roundkey[28 + i] = kiemTra1.at(i);

			}
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					Key1[8 * i + j] = roundkey[Key1[8 * i + j] - 1];
				}
			}
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					cout << Key1[8 * i + j];
				}
				cout << "\n";
			}
		}
		//----------tao xong key--------------
		RI = QuaP_Box(RI);
		for (int i = 0; i < 48; i++)//Sau khi qua xor v?i key
		{
			RI.at(i) = !(RI.at(i)) * Key1[i] + RI.at(i) * !(Key[i]);
		}
		//Khi qua S-boxes
		for (int i = 1; i <=8; i++)
		{

		}
	}
	

	return 0;
}