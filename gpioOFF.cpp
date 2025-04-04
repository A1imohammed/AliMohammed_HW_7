#include <fstream>
using namespace std;

int main() {
    ofstream valueFile("/sys/class/gpio/gpio60/value");
    valueFile << "0";
    valueFile.close();

    return 0;
}
