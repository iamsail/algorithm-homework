#include <iostream>
using namespace std;
 bool isNumberRight(int year,int month,int day){
     if(year<0 || month <= 0 || day <= 0 || month > 12){
         return 0;
     }
     return 1;
 }
 
 bool isLeapYear(int year){
     if((year % 4 == 0) && (year%100 != 0) || (year%400==0)){
         return true;
     }
     return false;
 }
 
 bool judge(int year,int month,int day){
     bool flag;
     if(!isNumberRight(year,month,day)){return 0;}
     int monthDays[12]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
     if(!isLeapYear(year)){
         monthDays[1] = 28;
     }
     if(day > monthDays[month - 1]){
         return 0;
     }
     return 1;
 }
 
 int main() {
     int year,month,day;
     cin >> year >>month >>day;
     cout<<judge(year,month,day)<<endl;
     return 0;
 }


