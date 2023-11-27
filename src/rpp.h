#ifndef RPP_H
#define RPP_H

using std::string;
class RPP {
    public:
        // Constructor
        RPP(int hub);

        // Methods
        void writeData(string out);
        bool readData(char *buffer);
        
    private:

    
};

#endif