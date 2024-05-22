#include <iostream>
#include <istream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

ifstream in("1.txt");
ofstream out("2.txt");

struct date {
	int d, m, y;

};
struct people {
	string Familia;
	string positions;
	date HB;
	int Experience;
	int Zarplata;
};
date Str_to_Date(string str) {
	date x;
	string temp = str.substr(0, 2);//????
	x.d = atoi(temp.c_str());
	temp = str.substr(3, 2);//?????
	x.m = atoi(temp.c_str());
	temp = str.substr(6, 4);//???
	x.y = atoi(temp.c_str());
	return x;
}

vector<people> inFile() {//???? ?? ?????
	ifstream in("1.txt");
	vector<people> x;
	people temp;
	while (in>>temp.Familia>>temp.positions) {
		string tmp;//???? ????????
		in >> tmp;
		temp.HB = Str_to_Date(tmp);
		in >> temp.Experience>>temp.Zarplata;//????????
		x.push_back(temp);
	}
	in.close();
	return x;
}
void print(people x, ofstream& out) {//????? ? ????
	out << setw(10) << left << x.Familia;//?? ?????? ????, 10 ??????? ??? ???????
	out<<setw(15)<<left<<x.positions;
	if (x.HB.d < 10) out << '0';//????????? 0
	out<<x.HB.d<<".";
	if (x.HB.m < 10) out << '0';
	out << x.HB.m << '.';
	out << setw(6) << x.HB.y;//?? ??? 6 ???????
	out << setw(10) <<left<< x.Experience;
	out<<setw(10)<<x.Zarplata<< endl;
}

bool operator < (const people& a, const people& b) {//?????????????? ???????? < ? ??????????? ? ????????
	return a.Zarplata < b.Zarplata;
}

bool operator > (people a, people b) {//?????????????? ???????? < ? ??????????? ? ????????
	return a.Zarplata > b.Zarplata;
}

void quick_sort(vector<people>& x, int L, int R) {//??????? ??????????
	int i = L;
	int j = R;
	people k = x[(L + R) / 2];
	while (i <= j) {
		while (x[i] < k) {
			i++;
		}
		while (x[j] > k) {
			j--;
		}
		if (i <= j) {
			swap(x[i], x[j]);
			i++;
			j--;
		}
	}
	if (j > L) {
		quick_sort(x, L, j);
	}
	if (i < R) {
		quick_sort(x, i, R);
	}
}

int main() {
	vector<people> x;
	x = inFile();
	quick_sort(x, 0, x.size() - 1);
	ofstream out("2.txt");
	for (int i = 0; i < x.size(); i++)
		print(x[i], out);
	out.close();
	return 0;

}
