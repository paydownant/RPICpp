#ifndef RPP_H
#define RPP_H

using std::string;
class RPP {
    public:
        // Constructor
        RPP(string port, string path, int baudrate=115200);

        // Variables

        // Methods
        void writeData(string out);
        string readData();
        void printData();
        
    private:
        // Variables
        string port;
        string path;
        int baudrate;

        // Methods
    
};

#endif