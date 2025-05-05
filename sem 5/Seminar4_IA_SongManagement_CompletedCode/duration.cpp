#include "duration.h"
#include "utils.h"

Duration::Duration(std::string dur)
{
	auto res = StringUtils::split(dur,':');
	minutes = stoi(res[0]);
	seconds = stoi(res[1]);
}
int Duration::getSeconds()const
{
	return seconds;
}
void Duration::setSeconds(int seconds)
{
	this->seconds = seconds % 60;
	this->minutes += seconds / 60;
}
int Duration::getMinutes()const
{
	return minutes;
}
void Duration::setMinutes(int minutes)
{
	this->minutes = minutes;
}

std::string Duration::toString() const
{
	return std::to_string(this->minutes)+":"+std::to_string(this->seconds);
}
