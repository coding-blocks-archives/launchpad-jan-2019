#include <iostream>
using namespace std;

bool isAnagram(int arr1[], int arr2[]) {
	for(int i=0;i<256;i++) {
		if(arr1[i]!=arr2[i]){
			return false;
		}
	}
	return true;
}

void printAnagramSubstring(string text, string pat) {
	int T[256] = {0};
	int P[256] = {0};
	int n = text.length(), m = pat.length();
	for(int i=0;i<m;i++) {
		T[text[i]]++;
		P[pat[i]]++;
	}
	for(int i=m;i<=n;i++) {
		if(isAnagram(T, P)) {
			cout<<(i-m)<<endl;
		}
		T[text[i-m]]--;
		T[text[i]]++;
	}
	// if(isAnagram(T, P) == true) {
	// 	cout<<(n-m)<<endl;
	// }
}


int main(int argc, char const *argv[])
{
	/* code */
	printAnagramSubstring("abcdbac", "abc");
	return 0;
}
