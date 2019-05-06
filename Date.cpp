#include "Date.h"

Date::Date(){

    time_t t = time(nullptr);
	struct tm* now = localtime(&t);
    day = ushort(now->tm_mday);
    month = ushort(now->tm_mon + 1);
    year = ushort(now->tm_year + 1900);
}

Date::Date(string date){
    vector<string> dateVector;
    // Perguntar ao NUNO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    /*year = ushort(stoi(date.substr(0, 4)));
    month = ushort(stoi(date.substr(5, 2)));
    day = ushort(stoi(date.substr(8, 2)));
    */
    dateVector=vectorString(date,"/");
    year=ushort(stoi(dateVector.at(0)));
    month=ushort(stoi(dateVector.at(1)));
    day=ushort(stoi(dateVector.at(2)));
}


Date::Date(unsigned year, unsigned short month, unsigned short day): year(year), month(month), day(day){

}

/*********************************
 * GET Methods
 ********************************/
unsigned short Date::getDay() const{

	return day;
}

  
unsigned short Date::getMonth() const{

	return month;
}
    
unsigned Date::getYear() const{

	return year;
}

string Date::getDate() const {
	
	return to_string(year) + "/" + to_string(month) + "/" + to_string(day);
}

/*********************************
 * SET Methods
 ********************************/

void Date::setDay(unsigned short day){
  
	this->day = day;
}

void Date::setMonth(unsigned short month){
  
	this->month = month;
}

void Date::setYear(unsigned year){

	this->year = year;
}

void Date::setDate(unsigned year, unsigned short month, unsigned short day) {

	this->year = year; this->month = month; this->day = day;
}

/*********************************
 * Other methods
 ********************************/

unsigned Date::total_days(unsigned year, unsigned short month) {

	if (month == 2) {
		return (year % 400 == 0 || year % 100 != 0) && (year % 4 == 0) ? 28 : 29;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	else {
		return 31;
	}
}

bool Date::isValid() {

	if (month >= 0 && month <= 12) {
		if (day >= 0 && day <= total_days(year, month)) {
			return true;
		}
	}
	return false;
}

bool Date::isEqualTo(const Date & date) {

	if (day == date.day && month == date.month && year == date.year) {
		return true;
	}
	return false;
}

bool Date::isNotEqualTo(const Date & date) {

	if (day != date.day || month != date.month || year != date.year) {
		return true;
	}
	return false;
}

bool Date::isAfter(const Date & date) {

	if (year == date.year) {
		if (month == date.month) {
			if (day > date.day) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (month > date.month) {
			return true;
		}
		else {
			return true;
		}
	}
	else if (year > date.year) {
		return true;
	}
	return false;
}

bool Date::isBefore(const Date & date) {

	if (year == date.year) {
		if (month == date.month) {
			if (day < date.day) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (month < date.month) {
			return true;
		}
		else {
			return true;
		}
	}
	else if (year < date.year) {
		return true;
	}
	return false;
}

/*********************************
 * Show Date
 ********************************/  

void Date::show() const {
	cout << to_string(year) + "/" + to_string(month) + "/" + to_string(day) << endl;
}

// disply a Date in a nice format
//ostream& operator<<(ostream& out, const Date & date){

//  // REQUIRES IMPLEMENTATION

//}
