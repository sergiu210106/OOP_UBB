#include <iostream>
#include <istream>
#include <ostream>
#include <stdexcept>
#include "duration.h"
using namespace std;

class Duration{
    private:
        float value;
    public:
        Duration() : value{0} {}
        Duration(int amount, char unit)  {
            if (unit == 's')
                value = amount;
            else if (unit == 'm') 
                value = amount * 60;
            else if (unit == 'h') 
                value = amount * 3600;
        }

        float get_value() const {
            return value;
        }
        
        int get(char unit) {
            if (unit == 's')
                return value;
            else if (unit == 'm') 
                return value / 60;
            else if (unit == 'h') 
                return value / 3600;
            else
                throw invalid_argument("unit not valid");
        }

        Duration operator+(const Duration& other) const {
            return Duration(value + other.value, 's');
        }
        
        Duration operator-(const Duration& other) const {
            return Duration(value - other.value, 's');
        }
        int comp(Duration& other) const {
            if (value == other.value)
                return 0;
            if (value < other.value) 
                return -1;
            return 1;
        }

        friend ostream& operator<<(ostream& os, Duration& d) {
            os << "PT";

            float copy = d.value;
            int hours = (int) d.value / 3600;
            d.value-=hours * 3600;
            
            if (hours) 
                os << "H" << hours;
            
            int minutes = (int) d.value / 60;
            d.value -= minutes * 60;

            if (minutes)
                os << "M" << minutes;
            
            int seconds = (int) d.value;
            if  (seconds) 
                os << "S" << seconds;
            
            d.value = copy;

            return os;
        }

};
