#include <iostream>
#include <fstream>
#include <fcntl.h>

using namespace std;

#define BUFF_SIZE 3

int main() {

	int fd1;
	char* buff = new char[3*BUFF_SIZE];
	int wr;

	fd1 = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);

	fcntl(fd1, F_SETFL, FNDELAY);

	while(true) {
		if (fd1 == -1)
			cout << "Error connnecting" << endl;
		else {
			wr = write(fd1, "000", BUFF_SIZE);

			int bytes = 0;

            while(bytes = read(fd1, buff, 3*BUFF_SIZE) > 0) {
                cout << buff << endl;
            }
		}
	}

	close(fd1);

	return 0;
}
