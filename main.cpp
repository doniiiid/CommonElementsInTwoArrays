// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <stack>
#include <algorithm>
using namespace std;

stack<int> common(int arr1[], int arr2[], int size);
void print(int a[]);

int main()
{
	srand(time(NULL));
	int a1[10];
	int a2[10];
	for (int i = 0; i < 10; i++) {
		int r1 = rand() % 10;
		int r2 = rand() % 10;
		a1[i] = r1;
		a2[i] = r2;
	}
	cout << "A: ";
	print(a1);
	cout << "B: ";
	print(a2);
	stack<int> c = common(a1, a2, 10);
	
	cout << "Sorted A: ";
	print(a1);
	cout << "Sorted B: ";
	print(a2);
	cout << "Common elements: ";
	while (!c.empty()) {
		cout << c.top() << ' ';
		c.pop();
	}
	cout << endl;
	system("pause");
    return 0;
}
void print(int a[]) {
	for (int i = 0; i < 10; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}
stack<int> common(int a[], int b[], int size) {
	stack<int> tmp1;
	stack<int> tmp2;
	stack<int> com;

	sort(a, a + size);
	sort(b, b + size);
	for (int i = 0; i < 10; i++) {
		tmp1.push(a[i]);
		while (a[i] == a[i + 1])
			i++;
	}
	for (int i = 0; i < 10; i++) {
		tmp2.push(b[i]);
		while (b[i] == b[i + 1])
			i++;
	}
	int s1 = tmp1.size();
	int s2 = tmp2.size();
	int *A = new int[s1];
	int *B = new int[s2];

	for (int i = 0; i < s1; i++) {
		A[i] = tmp1.top();
		tmp1.pop();

	}
	for (int i = 0; i < s1; i++) {
		B[i] = tmp2.top();
		tmp2.pop();

	}
	for (int i = 0; i < s1; i++) {
		for (int j = 0; j < s2; j++) {
			if (A[i] == B[j])
				com.push(A[i]);
		}
	}
	return com;
}
