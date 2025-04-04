#include "myGpio.h"
#include <unistd.h>
#include <iostream>
#include <fstream>

MYGPIO::MYGPIO(int number) {
    this->number = number;
    this->name = "gpio" + to_string(number);
    this->path = "/sys/class/gpio/" + name + "/";

    ofstream exportFile("/sys/class/gpio/export");
    exportFile << number;
    exportFile.close();

    usleep(100000); // Small delay for sysfs to set up
}

void MYGPIO::write(string path, string filename, string value) {
    ofstream fs(path + filename);
    fs << value;
    fs.close();
}

void MYGPIO::write(string path, string filename, int value) {
    write(path, filename, to_string(value));
}

string MYGPIO::read(string path, string filename) {
    ifstream fs(path + filename);
    string input;
    fs >> input;
    fs.close();
    return input;
}

int MYGPIO::getNumber() {
    return number;
}

void MYGPIO::setDirection(int dir) {
    if (dir == 0)
        write(path, "direction", "in");
    else
        write(path, "direction", "out");
}

string MYGPIO::getDirection() {
    return read(path, "direction");
}

void MYGPIO::setValue(int val) {
    write(path, "value", val);
}

int MYGPIO::getValue() {
    return stoi(read(path, "value"));
}

void MYGPIO::toggleOutput() {
    int current = getValue();
    setValue(current == 0 ? 1 : 0);
}

void MYGPIO::toggleOutputNumberOfTimes(int n, int delay) {
    for (int i = 0; i < n; ++i) {
        toggleOutput();
        usleep(delay * 1000); 
    }
}

MYGPIO::~MYGPIO() {
    ofstream unexportFile("/sys/class/gpio/unexport");
    unexportFile << number;
    unexportFile.close();
}
