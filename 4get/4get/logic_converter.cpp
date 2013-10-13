#include "logic_converter.h"

Converter::Converter(){}

int Converter::convertStringToInt(string str)
{
	int strInt;
	stringstream stringer(str);
	stringer >> strInt;
	return strInt;
}

Status Converter::convertStringToStatus(string str)
{
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	if(isEqual(str, "completed"))
		return completed;
	else if(isEqual(str, "incomplete"))
		return incomplete;
	else if(isEqual(str, "overdued"))
		return overdued;
	else 
		return statusNone;
}
RepeatType Converter::convertStringToRepeatType(string str)
{
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	if(isEqual(str, "daily"))
		return daily;
	else if(isEqual(str, "weekly"))
		return weekly;
	else if(isEqual(str, "fortnightly"))
		return fortnightly;
	else if(isEqual(str, "monthly"))
		return monthly;
	else if(isEqual(str, "annually"))
		return annually;
	else
		return repeatNone;
}
Priority Converter::convertStringToPriority(string str)
{
	if(isEqual(str, "high"))
		return high;
	else
		return normal;
}
tm* Converter::convertStringToTm(string str)  //this function work for dates that are eg. 02/02/13
{
	tm* Time;
	Time = new tm;
	Time = NULL;
	if(str.empty())
	{
		return Time;
	}
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	if(str[2] == '/')
	{
		char DELIMITER = '/';
		int day, month, year;
		istringstream stm(str);
		stm >> day >> DELIMITER;
		stm >> month >> DELIMITER;
		stm >> year;
		if(year < 100)
		{
			year += 2000;
		}
		
		Time ->tm_mday = day;
		Time ->tm_mon = month;
		Time ->tm_year = year;

		return Time;
	}
	else if(str[1] == ':'|| str[2] == ':')
	{
		int hour, mins;
		char DELIMITER = ':';
		char DELIMITER_MINS = 'a';
		istringstream stm(str);
		stm >> hour>> DELIMITER;
		stm >> mins >> DELIMITER_MINS;

		Time ->tm_hour = hour;
		Time->tm_min = mins;

		return Time;
	}
}
bool Converter::isEqual(string str1, const string str2)
{
	if(str1 == str2)
		return true;
	return false;
}
