#ifndef MYGPIO_H
#define MYGPIO_H

#include <string>
#include <fstream>
using namespace std;

class MYGPIO {
private:
    int number;
    string name, path;
    void write(string path, string filename, string value);
    void write(string path, string filename, int value);
    string read(string path, string filename);
    ofstream stream;

public:
    MYGPIO(int number); 
    int getNumber();
    void setDirection(int dir);  
    string getDirection();
    void setValue(int val);      
    int getValue();
    void toggleOutput();
    void toggleOutputNumberOfTimes(int n, int delay); 
    ~MYGPIO(); 
};

#endif
