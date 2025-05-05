#pragma once
#include <string>
#include <iostream>

class Duration
{
private:
	int seconds;
	int minutes;
public:
	//Constructor that takes a string of the form "mm:ss" and splits it
	//into necessary fields
	Duration(std::string dur);
	//Constructor that takes number of minutes and number of seconds
	Duration(int mins, int secs) : minutes{ mins }, seconds{ secs } {};
	//copy constructor
	Duration(const Duration& other) :seconds(other.seconds), minutes(other.minutes) { 
		std::cout << "Copy duration called"; 
	}
	//const because getters do not (should not) modify
	//the current object
	int getSeconds() const;
	void setSeconds(int seconds);
	int getMinutes() const;
	void setMinutes(int minutes);

	std::string toString() const;
};