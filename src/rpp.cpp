
#include <string>
#include <iostream>

#include "rpp.h"

using std::string;
RPP::RPP(string port, string path, int baudrate) {
    this->port = port;
    this->path = path;
    this->baudrate = baudrate;
}


void RPP::writeData(string out) {
    // Write data to stdout
    std::cout<<out<<std::endl;
    
}

string RPP::readData() {
    // Read data from stdin
    string data = "Test Data";

    return data;
}

void RPP::printData() {
    std::cout<<"Port: "<<this->port<<std::endl;
    std::cout<<"Path: "<<this->path<<std::endl;
    std::cout<<"Baud rate: "<<this->baudrate<<std::endl;
}