#include<iostream>
#include<cmath>
#include<stdio.h>
#include<math.h>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int arr1[4], arr2[4], arr3[4], arr4[4];
int sel1[4], sel2[4], sel3[4], sel4[4];
double x1 = 0, x2 = 0, x3 = 0, x4 = 0;
int bin1, bin2, bin3, bin4;
double f1, f2, f3, f4;
map<double, int>v1;
int sum;
void randGenerator(){
	int i;
	for (i = 0; i<4; i++){
		arr1[i] = rand() % 2;
		arr2[i] = rand() % 2;
		arr3[i] = rand() % 2;
		arr4[i] = rand() % 2;
	}
	sum = arr1[i] * 1000 + arr2[i] * 100 + arr3[i] * 10 + arr4[i];

	cout << "Before the Mutation:" << endl;
	for (int i = 0; i < 4; i++){
		cout << arr1[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i < 4; i++){
		cout << arr2[i] << "\t";
	}
	cout << endl;

	for (int i = 0; i < 4; i++){
		cout << arr3[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i < 4; i++){
		cout << arr4[i] << "\t";
	}
	cout << endl;



}
float myRound(float f){
	return f<0 ? ceil(f - 0.5) : floor(f + 0.5);
}
void calculateFitness(){
	for (int i = 3, j = 0; i >= 0; i--, j++){

		x1 = x1 + arr1[i] * pow(2, float(j));
		x2 = x2 + arr2[i] * pow(2, float(j));
		x3 = x3 + arr3[i] * pow(2, float(j));
		x4 = x4 + arr4[i] * pow(2, float(j));
	}
	cout << x1 << endl;


	double fit1, fit2, fit3, fit4, avg;
	fit1 = x1*x1;
	fit2 = x2*x2;
	fit3 = x3*x3;
	fit4 = x4*x4;
	avg = (fit1 + fit2 + fit3 + fit4) / 4;

	f1 = myRound(fit1 / avg);
	f2 = myRound(fit2 / avg);
	f3 = myRound(fit3 / avg);
	f4 = myRound(fit4 / avg);

	cout << f1 << endl;




}

void selection(){
	int selectionArr[4] = { f1, f2, f3, f4 };
	v1[f1] = 0;
	v1[f2] = 1;
	v1[f3] = 2;
	v1[f4] = 3;
	sort(selectionArr, selectionArr + 3);
	int i;
	for (i = 0; i<4; i++)
	{
		cout << v1[selectionArr[i]] << "\t";
	}
	cout << endl;
	




}

void crossOver(){
	if (v1[0] == 0){
		for (int i = 0; i < 4; i++){
			sel1[i] = arr1[i];
		}

	}
	else if (v1[0]==1){
		for (int i = 0; i < 4; i++){
			sel1[i] = arr2[i];
		}

	}
	else if (v1[0]==2){
		for (int i = 0; i < 4; i++){
			sel1[i] = arr3[i];
		}
	}
	else if (v1[0] == 3){
		for (int i = 0; i < 4; i++){
			sel1[i] = arr4[i];
		}
	}
	if (v1[1] == 0){
		for (int i = 0; i < 4; i++){
			sel2[i] = arr1[i];
		}

	}
	else if (v1[1] == 1){
		for (int i = 0; i < 4; i++){
			sel2[i] = arr2[i];
		}

	}
	else if (v1[1] == 2){
		for (int i = 0; i < 4; i++){
			sel2[i] = arr3[i];
		}
	}
	else if (v1[1] == 3){
		for (int i = 0; i < 4; i++){
			sel2[i] = arr4[i];
		}
	}
	if (v1[2] == 0){
		for (int i = 0; i < 4; i++){
			sel3[i] = arr1[i];
		}

	}
	else if (v1[2] == 1){
		for (int i = 0; i < 4; i++){
			sel3[i] = arr2[i];
		}

	}
	else if (v1[2] == 2){
		for (int i = 0; i < 4; i++){
			sel3[i] = arr3[i];
		}
	}
	else if (v1[2] == 3){
		for (int i = 0; i < 4; i++){
			sel3[i] = arr4[i];
		}
	}

	if (v1[3] == 0){
		for (int i = 0; i < 4; i++){
			sel4[i] = arr1[i];
		}

	}
	else if (v1[3] == 1){
		for (int i = 0; i < 4; i++){
			sel4[i] = arr2[i];
		}

	}
	else if (v1[3] == 2){
		for (int i = 0; i < 4; i++){
			sel4[i] = arr3[i];
		}
	}
	else if (v1[3] == 3){
		for (int i = 0; i < 4; i++){
			sel4[i] = arr4[i];
		}
	}
	for (int i = 0; i < 4; i++){
		cout << sel1[i] << "\t";
	}




}
void mutation(){
	int position1 = rand() % 4;
	int position2 = rand() % 4;
	int temp = 3 - position1;
	int temp2 = 3 - position2;


	for (int i = 0; i < position1; i++){
		sel1[position1] = sel2[position1 + temp];
		sel2[position1 + temp] = sel1[position1];

	}

	for (int i = 0; i < position2; i++){
		sel1[position2] = sel3[position2 + temp2];
		sel3[position2 + temp2] = sel1[position2];
	}
	for (int i = 0; i < 4; i++){
		arr1[i] = sel1[i];
		arr2[i] = sel2[i];
		arr3[i] = sel3[i];
		arr4[i] = sel4[i];
	}
}


int main(){
	randGenerator();
	for (int i = 0; i < 5; i++){
		
		calculateFitness();
		selection();
		crossOver();
		mutation();
	}
	cout << "\nAfter the mutation:" << endl;
	for (int i = 0; i < 4; i++){
		cout << arr1[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i < 4; i++){
		cout << arr2[i] << "\t";
	}
	cout << endl;

	for (int i = 0; i < 4; i++){
		cout << arr3[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i < 4; i++){
		cout << arr4[i] << "\t";
	}
	cout << endl;





}
