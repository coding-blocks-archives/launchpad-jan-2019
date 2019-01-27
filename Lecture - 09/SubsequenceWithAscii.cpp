#include <iostream>
#include <sstream>
using namespace std;

string itos(int i) // convert int to string
{
    stringstream s;
    s << i;
    return s.str();
}

void subsequenceWithAscii(string str, string osf) {
	if(str.length()==0) {
		cout<<osf<<endl;
		return;
	}

	char ch = str[0];
	string ros = str.substr(1);
	subsequenceWithAscii(ros, osf+ch);
	subsequenceWithAscii(ros, osf);
	subsequenceWithAscii(ros, osf+itos((int)ch));
}

int main(int argc, char const *argv[])
{
	subsequenceWithAscii("abc", "");
	return 0;
}
