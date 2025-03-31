#ifndef DURATION_H
#define DURATION_H

#include <iostream>
#include <stdexcept>

class Duration {
private:
    float value;

public:
    Duration();
    Duration(int amount, char unit);

    float get_value() const;
    int get(char unit);
    Duration& operator+(Duration& other);
    Duration& operator-(Duration& other);
    int comp(Duration& other) const;
    friend std::ostream& operator<<(std::ostream& os, Duration& d);
};

#endif
