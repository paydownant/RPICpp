#ifndef RPP_H
#define RPP_H

using std::string;
class RPP {
    public:
        // Constructor
        RPP(int max_message_length = 100);

        // Methods
        void write_data(string out);
        void write_data_timed(string out, uint64_t interval=1000000);
        string read_data();

        
    private:
        // Variables
        int max_message_length;
        uint64_t clock;

    
};

#endif