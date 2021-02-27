#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

long long fact(int i){
	if (i <= 1) return 1;
  	else return i*fact(i-1);
}

int main(){
  	ios::sync_with_stdio(0);
  	cin.tie(0);
  	int N;
  	cin >> N;
    // now limit for n is 21 

  	cout << fact(N) << "\n";
  	return 0;
}