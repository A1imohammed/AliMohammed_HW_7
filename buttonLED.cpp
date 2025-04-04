#include <fstream>
#include <iostream>
#include <unistd.h>
using namespace std;

int main() {
    ofstream exportFile("/sys/class/gpio/export");
    exportFile << "60" << endl << "46";
    exportFile.close();

    ofstream dir60("/sys/class/gpio/gpio60/direction");
    dir60 << "out";
    dir60.close();

    ofstream dir46("/sys/class/gpio/gpio46/direction");
    dir46 << "in";
    dir46.close();

    string value;
    while (true) {
        ifstream buttonFile("/sys/class/gpio/gpio46/value");
        getline(buttonFile, value);
        buttonFile.close();

        ofstream ledFile("/sys/class/gpio/gpio60/value");
        ledFile << (value == "1" ? "1" : "0");
        ledFile.close();

        usleep(100000); // 0.1 sec
    }

    return 0;
}
