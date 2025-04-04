#include <iostream>
#include <unistd.h>
#include "myGpio.h"

int main() {
    MYGPIO led(60);      
    MYGPIO button(46);  

    led.setDirection(1);     
    button.setDirection(0);  

    
    std::cout << "Turning LED ON (GPIO60)" << std::endl;
    led.setValue(1);
    std::cout << "LED value: " << led.getValue() << std::endl;

    sleep(3);  

    std::cout << "Turning LED OFF (GPIO60)" << std::endl;
    led.setValue(0);
    std::cout << "LED value: " << led.getValue() << std::endl;
    std::cout << "Reading button input (GPIO46): " << button.getValue() << std::endl;

    return 0;
}
