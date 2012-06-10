#include <iostream>
#include <fstream>
#include <fcntl.h>

using namespace std;

int main() {

	int fd1;
	char* buff = new char[3];
	int wr;

	fd1 = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);

	fcntl(fd1, F_SETFL, FNDELAY);

	while(true) {
		if (fd1 == -1)
			cout << "Error connnecting" << endl;
		else {
			wr = write(fd1, "abc", 3);

			int bytes = 0;

            while(bytes = read(fd1, buff, 9) > 0) {
                cout << buff << endl;
            }
		}
	}

	close(fd1);

	return 0;
}
