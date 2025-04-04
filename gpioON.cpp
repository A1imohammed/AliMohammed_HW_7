#include <fstream>
using namespace std;

int main() {
    ofstream exportFile("/sys/class/gpio/export");
    exportFile << "60";
    exportFile.close();

    ofstream dirFile("/sys/class/gpio/gpio60/direction");
    dirFile << "out";
    dirFile.close();

    ofstream valueFile("/sys/class/gpio/gpio60/value");
    valueFile << "1";
    valueFile.close();

    return 0;
}
