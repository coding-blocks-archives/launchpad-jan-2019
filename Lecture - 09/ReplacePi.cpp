#include <iostream>
using namespace std;

void replacePi(string str, string osf) {
	// BAse case
	if(str.length()==0) {
		cout<<osf<<endl;
		return;
	}
	if(str.length()==1) {
		cout<<osf+str[0]<<endl;
		return;
	}
	if(str[0]=='p' and str[1]=='i') {
		replacePi(str.substr(2), osf+"3.14");
	} else {
		replacePi(str.substr(1), osf+str[0]);
	}
}
int main(int argc, char const *argv[])
{
	/* code */
	replacePi("pi", "");
	return 0;
}
