#include <iostream>
#include <string>
#include <fstream>
#include "BinaryTree.h"


using namespace std;

void Tree();

int main() {

	Tree();
}

bool CmpMark(student x, student y) {
	return x.mark < y.mark;
}

bool CmpName(student x, student y) {
	return x.name < y.name;
}

void readFile(BinTree& root) {
	ifstream fin("student.txt");
	if (!fin.is_open()) {
		cout << "<p>file not open</p>";
		return;
	}

	string x, y;
	while (fin >> x >> y) {
		student st;
		st.name = x;
		st.mark = stod(y);
		add(root, st);
	}
	fin.close();
}

void Tree() {
	int t;
	cin >> t;

	if (t == 1) {
		string s;
		cin >> s;
		BinTree sgt = nullptr;
		if (s == "name") {
			sgt = BinTree(CmpName);
		}else {
			sgt = BinTree(CmpMark);
		}

		readFile(sgt);
		show(sgt);
	}
	else {
		char c;
		cin >> c;

		BinTree sgt(CmpName);

		readFile(sgt);
		showSymbol(sgt, c);
	}
}