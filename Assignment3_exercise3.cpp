#include <iostream>
#include <stdlib.h>
using namespace std;
 
bool check_date(int day, int month){
 if ((month==2) && (day>0) && (day<30)){
 return true;
 }
 if (((month==1) || (month==3) ||(month==5) ||(month==7) ||(month==8) ||(month==10)||(month==12)) && ((day>0) && (day<32)))
 {
 return true;
 }
 if (((month==4) ||(month==6) ||(month==9) ||(month==11)) && ((day>0) && (day<31)))
 {
 return true;
 }
 return false;
}
 
 
bool check_month(int month){
 if ((month>0) && (month<13)){
  return true;
 }else{
  return false;
 }
}
 
bool check_year(int year){
 
 if ((year>999) && (year < 10000)){
 return true;
 }else{return false;
 }
 
}
bool check_leap_year(int year){
 if (((year % 4)==0) && ((year % 100)!=0)){
  return true;
 }else if ((year % 400)==0){return true;
 }else {return false;
 }
}

const char *get_day(int day, int month, int year){
  int JMD;
   JMD = (day + ((153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5) +
     (365 * (year + 4800 - ((14 - month) / 12))) +
     ((year + 4800 - ((14 - month) / 12)) / 4) - 
    ((year + 4800 - ((14 - month) / 12)) / 100) + 
    ((year + 4800 - ((14 - month) / 12)) / 400)  - 32045) % 7;
 const char *weekday[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
 return weekday[JMD];
}
 
 
main(){
 int year, month, date, x, y;
 cout << "\n[+] SEARCH PROGRAM.";
 cout << "\n[+] ENTER YEAR [YYYY] : ";
 cin >> year;
 if (check_year(year)){
  cout << "[-] CONFIRMED!";
 }else{
  cout << "\n\t [-] SYNTAX ERROR!\n";
  exit(0);
 }
 cout << "\n[+] ENTER MONTH [MM] : ";
 cin >> month;
 if (check_month(month)){
  cout << "[-] CONFIRMED!";
 }else{
  cout << "[-] SYNTAX ERROR!";
  exit(0);
 }
 cout << "\n[+] ENTER DAY [DD] : ";
 cin >> date;
 if (check_date(date, month)){
  cout << "[-] CONFIRMED!\n\n";
 }else{
  cout << "[-] SYNTAX ERROR!";
  exit(0);
 }
 cout << "[+] DAY : " << date << ", MONTH : " << month << ", YEAR : " << year << " [ ";
 if (check_leap_year(year)){
  cout << "LEAP YEAR" << " ]";
 }else{
  cout << "NOT A LEAP YEAR" << " ]";
 }
 cout << "\n[-] WEEKDAY: ";
 cout << get_day(date, month, year);
 cout << "\n\n";
}
