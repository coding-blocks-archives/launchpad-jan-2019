#include <iostream>
using namespace std;

void subsequence(string str, string osf) {
	if(str.length()==0) {
		cout<<osf<<endl;
		return;
	}

	char ch = str[0];
	string ros = str.substr(1);
	subsequence(ros, osf+ch);
	subsequence(ros, osf);
}

int main(int argc, char const *argv[])
{
	/* code */
	subsequence("abc", "");
	return 0;
}
