
#include <fstream>
#include <iostream>
using namespace std;

int main() {

	fstream outFile;

	outFile.open ("Testing.txt", ios_base::out);

	if (outFile.good()){

		outFile << "abcdefghigstohuesth" << '\n';  // note: not endl;
		outFile << "ABCDEFGHIGJELMNOP" << '\n';  // note: not endl;
		outFile << "123456789" << '\n';  // note: not endl;
		outFile.close();
	}
	else
		cout << "Error, file did not open" << endl;



	return 0;
}

