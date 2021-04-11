#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int main(){

int Index;


int stop = 0;
do {
cout<<endl;
cout<<"   1. Show Local date and time\n"
        "   2. Convert Date (EC to GC)\n"
        "   3. Add n days to a Date (GC)\n"
        "   4. Date difference between two dates (GC)\n"
        "   5. Show Zemen for the Ethiopian Calender\n"
        "   6. Is Leap year (EC or GC)\n"
        "   7. The Day of the Week for a given Date (GC)\n"
        "   8. Show GC - EC Calender (Primary GC) [Bonus Program]\n"
        "   9. Exit\n";

cout<<"\nSelect a number that corresponds to the program you want access. \n";
    cin>>Index;

     if (Index==9){
        cout <<"thanks for using the program "<<endl;
system("CLS");
    }
do {
    stop = 0;
    if (Index <= 0 || Index >= 10){
    cout<<"Wrong input. Read the prompt properly and Try again.\n";
    stop++;
    }
} while(stop != 0);

if(Index == 1){

    cout << " Current Date is : ";
    system("date /T");
    cout << " Current Time is : ";
    system("time /T");
    cout<<endl;
}

if(Index == 2){

int day, month, year, error = 0;
int gregorial_month_days_length[] = { 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31 };
int ethiopian_month_days_length[] = { 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 5 };
int month_days_difference[13] = { 10, 10, 9, 9, 8, 7, 9, 8, 8, 7, 7, 6, 5 };
bool leapYear_EC, leapYear_GC;

string gregorian_month[] = {
                                  "Sep", "Oct", "Nov", "Dec", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug"
                            };

do{
    cout<<endl;
    cout<< "Enter the Date in Ethiopian Calender.\n\n";
    cout<<"Day: ";
    cin>>day;
    cout<<"Month(ex. For Meskerem write 1): ";
    cin>>month;
    cout<<"Year: ";
    cin>>year;

if ((year+1) % 400 == 0)

	leapYear_EC = true;

	if ((year+1) % 100 == 0)
	leapYear_EC = false;

    if ((year+1) % 4 == 0)
	leapYear_EC = true;

else{
		leapYear_EC = false;

}

    if (leapYear_EC == true){

        ethiopian_month_days_length[12] = 6;
}

    if (year % 400 == 0)

	leapYear_GC = true;

	if (year % 100 == 0)
	leapYear_GC = false;

    if (year % 4 == 0)
	leapYear_GC = true;

else{
		leapYear_GC = false;

}

    if (leapYear_GC == true){

        for(int i = 0; i <= 5; i++){

        month_days_difference[i] += 1;
        }
        gregorial_month_days_length[5] = 29;
}

error=0;

    if (month <=0 || month > 13){

        cout<<"There is no such month.\nPlease enter corresponding integers for the month of the Ethiopian Calender from 1 to 13.\n";
        error++;
    }

    if ((0 < month <= 13) && (day > ethiopian_month_days_length[month - 1])){

        cout<<"There is no such day in this month.\n";
        error++;
    }

    if (year < 0 || year > 9999){

        cout<<"Sorry! This converter supports neither negative years or any year beyond the year 9999.\nBetter luck next time.\n";
        error++;
    }

}while (error != 0);


if (month <5 && month != 13){
    if (month == 4 && day >= 23){
        year += 8;
    }
    else {
    year += 7;
}}
else {
    year += 8;
}

    day = day + month_days_difference [month - 1];

if(day > gregorial_month_days_length[month -1]){

    day = day - gregorial_month_days_length[month -1];
    month++;
}

if (month >=13){

    month = 1;

}

else{
    month = month;
}

    cout<<endl<<day<<" "<<gregorian_month[month-1]<<", "<<year<<endl;

cin.get();
cin.ignore();
}

if(Index == 3){

int days_in_months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int day, month, year, addyears, leftoverdays;
int x;
int error = 0;
bool leapYear_GC;
    cout<<endl;
    cout<< "This program adds n days to a date for the Gregorain Calender.\n\n";

do {
 	cout<<"Day: ";
	cin>> day;
	cout<<"Month (ex: For February write 2): ";
	cin>> month;
	cout<<"Year: ";
	cin>> year;

error = 0;

if(month < 1 || month > 12){
    cout<<"There is no such month. Enter an integer from 1 to 12 for the corresponding month.\n";
    error++;
}
if (year < 1 || year > 9999){
    cout<<"This program neither accepts negative years nor any year above the year 9999. Better Luck Next time\n";
    error++;
}
if (year % 400 == 0)

	leapYear_GC = true;

	if (year % 100 == 0)
	leapYear_GC = false;

    if (year % 4 == 0)
	leapYear_GC = true;

else{
		leapYear_GC = false;
}


if (month == 2 && day > 29 && leapYear_GC == true){
    cout<<"There is no such day. Enter a valid day for the month.\n";
    error++;
}

else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30){
    cout<<"There is no such day. Enter a valid day for the month.\n";
    error++;
}

else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31){
    cout<<"There is no such day. Enter a valid day for the month.\n";
    error++;
}
else if(month == 2 && day > 28 && leapYear_GC == false){
    cout<<"There is no such day. Enter a valid day for the month.\n";
    error++;
}

}while (error!=0);

cout<<"Please Enter the number of days you wish to add.\n";
cin>>x;

if(leapYear_GC == true){
    days_in_months[1] = 29;
}

int temp;
temp = year;

leapYear_GC? addyears = x / 366 : addyears = x / 365;
leapYear_GC? leftoverdays = x % 366 : leftoverdays = x % 365;
year = year + addyears;

for (int i = 0; i <= leftoverdays; i++){

    if (day < days_in_months[month - 1]){

        day ++;
    }
    else if (day == days_in_months[month-1]) {

        if (month < 12){

            day = 1;
            month ++;
        }
        if (month == 12){

            day = 1;
            month = 1;
            year++;
        }

    }
}

day--;

if (day == 0){

    if (month != 1){
        month--;
        day = 1;
        year--;

    }

    if(month == 1 && year > temp){

    month--;
    day = days_in_months[month-1];
    year--;

    }
}

cout<<"\nThe Date (after addition) is: " << day << ", " << month  << ", " << year<<endl;

cin.get();
cin.ignore();

}

if(Index == 4){
int days_in_months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int first_day, second_day;
int first_month, second_month;
int first_year, second_year;
int years_difference, days_difference;
int months_total;
int regular_year = 365;
int error = 0;
bool leapYear_GC1, leapYear_GC2;
string gregorian_month[12] = {
                                 "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December",
                            };

cout<<endl;
cout<<"This Program Calculates the difference between 2 Dates "<<endl;
cout<<endl;
cout<<"Please enter the date by day, month, year."<<endl;
cout<<endl;

do{
    error = 0;

cout<<"\nFirst date: "<<endl;
cout<<"\nDay: ";
cin>>first_day;

cout<<"Month: ";
cin>>first_month;

cout<<"Year: ";
cin>>first_year;

    if (first_year % 400 == 0)

	leapYear_GC1 = true;

	if (first_year % 100 == 0)
	leapYear_GC1 = false;

    if (first_year % 4 == 0)
	leapYear_GC1 = true;

else{
		leapYear_GC1 = false;

}

    if (leapYear_GC1 == true){

        days_in_months[1] = 29;
}

    if (first_month <= 0 || first_month > 13){
    cout<<"\nThere is no such month.\nPlease enter corresponding integers for the month of the Gregorian Calender from 1 to 13.\n";
    error++;
    }

    if ((0 < first_month <= 12) && (first_day > days_in_months[first_month - 1])){
    cout<<"\nThere is no such day in this month.\nYou can only enter an integer from 1 to " <<days_in_months[first_month - 1]
        <<" for the month of "<<gregorian_month[first_month - 1]<<" for the year of "<< first_year<<endl;
    error++;
    }

    if (first_year < 1 || first_year > 5500){
    cout<<"\nSorry! This program supports neither negative years nor any year beyond the year 5500.\nTry to enter a valid year this time around.\n";
    error++;
    }
}while(error != 0);

do {

    error = 0;

cout<<"\nSecond Date: "<<endl;
cout<<"\nDay: ";
cin>>second_day;

cout<<"Month: ";
cin>>second_month;

cout<<"Year: ";
cin>>second_year;

if (second_year % 400 == 0)

	leapYear_GC2 = true;

	if (second_year % 100 == 0)
	leapYear_GC2 = false;

    if (second_year % 4 == 0)
	leapYear_GC2 = true;

    else{
		leapYear_GC2 = false;

}
    if (leapYear_GC2 == true){

        days_in_months[1] = 29;
}


if (second_month <= 0 || second_month > 13){
    cout<<"\nThere is no such month.\nPlease enter corresponding integers for the month of the Gregorian Calender from 1 to 13.\n";
    error++;
    }

    if ((0 < second_month <= 12) && (second_day > days_in_months[second_month - 1])){
    cout<<"\nThere is no such day in this month.\nYou can only enter an integer from 1 to " <<days_in_months[second_month - 1]
        <<" for the month of "<<gregorian_month[second_month - 1]<<" for the year of "<< second_year<<endl;
    error++;
    }

    if (second_year < 1 || second_year > 5500){
    cout<<"\nSorry! This converter supports neither negative years nor any year beyond the year 5500.\nTry to enter a valid year this time around.\n";
    error++;
    }
}while(error != 0);


if(first_year == second_year){

        years_difference = 0;
}

else{

    if(leapYear_GC1 == true){

        if(leapYear_GC2 == true){

            if(first_year > second_year){

                    years_difference = (first_year - second_year) * (regular_year) + 2;
            }
            else{

                    years_difference = (second_year - first_year) * (regular_year) + 2;
            }

            if(second_month > first_month){

                if(days_in_months[first_month - 1] > days_in_months[1]){

                        --years_difference;
                }
            }
        }

        else{

            if(first_year > second_year){

                    years_difference = (first_year - second_year) * (regular_year) + 1;
        }

            else{

                    years_difference = (second_year - first_year) * (regular_year) + 1;
            }
            if(first_month > second_month){

                if(days_in_months[second_month - 1] > days_in_months[1]){

                    --years_difference;
                }
            }
        }
    }

    else{

            if(first_year > second_year){

                years_difference = (first_year - second_year) * (regular_year);
            }
            else{

                years_difference = (second_year - first_year) * (regular_year);
            }
    }
    }


if(first_month == second_month){

        months_total = 0;
}

else{

    if(first_month > second_month){

                int months_total_temp = 0;

            for(int i = (first_month - 1); i > (second_month - 1); i--){

                months_total_temp += days_in_months[i];
            }
months_total = months_total_temp;

    }

    else{
                int months_total_temp = 0;

            for(int i = (first_month - 1); i < (second_month - 1); i++){

                months_total_temp += days_in_months[i];

            }
months_total = months_total_temp;

    }
}


int days_total;

if (first_day == second_day){

        days_difference = 0;
        days_total = (years_difference + months_total) - days_difference;
}

else{

    if(first_day > second_day){

            days_difference = first_day - second_day;
            days_total = (years_difference + months_total) - days_difference;
    }
    else{

            days_difference = second_day - first_day;
            days_total = (years_difference + months_total) + days_difference;
    }
}

if(first_year == second_year){

    }
else{

    if(first_year > second_year){

        for(int i = (second_year + 1); i < first_year; i++){

            if(i % 4 == 0 && i % 100 != 0 || i % 400 == 0){

                    ++days_total;
                }
        }
    }
    else{

        for(int i = (first_year + 1); i < second_year; i++){

            if(i % 4 == 0 && i % 100 != 0 || i % 400 == 0){

                    ++days_total;
            }
        }
    }
}
cout<<"\nThe difference (in days) is: "<<days_total <<" days"<<endl;

cin.get();
cin.ignore();
}

if(Index == 5){

int year, error = 0, remainder;

    cout<<endl;
    cout<<"Enter a year from the Ethiopian calender.\n";

do{
error = 0;
    cin>>year;
    if (year < 0 || year > 5500){
    cout<<"Sorry! This program supports neither negative years or any year beyond the year 3000.\nTry to enter a year from the Ethiopian calender.\n";
    error++;
    }

}while (error != 0);

 remainder = (5500 + year) % 4;

if(remainder == 0)

    cout<<"The year "<<year<<" is Zemene Yohannes\n";

else if(remainder == 1)

    cout<<"The year "<<year<<" is Zemene Mateos\n";

else if(remainder == 2)

    cout<<"The year "<<year<<" is Zemene Markos\n";

else if(remainder == 3)

    cout<<"The year "<<year<<" is Zemene Lukas\n";

cin.get();
cin.ignore();
}

if(Index == 6){

int index;
int error = 0;
bool leapYear_GC, leapYear_EC;

    cout<<endl;
    cout<<"This program checks to see if a given year is a leap year or not for both Gregorian &Ethiopian Calenders.\n"
          " 1. Check Leap Year for the Ethiopian Calender\n"
          " 2. Check Leap Year for the Gregorian Calender\n";
    cout<<"\nNow Enter your preferred option [1 or 2]\n";

do{

cin>>index;
error = 0;


if(index == 1){

    cout<<"\nNow Enter a year from the Ethiopian Calender\n";

    int year;

        do{
            error = 0;
            cin>>year;
            if (year < 0 || year > 3000){
            cout<<"Sorry! This program supports neither negative years nor any year beyond the year 3000.\nTry to enter a year from the Ethiopian calender.\n";
            error++;
        }
            }while (error != 0);



    if ((year+1) % 400 == 0)

	leapYear_EC = true;

	if ((year+1) % 100 == 0)

	leapYear_EC = false;

    if ((year+1) % 4 == 0)

	leapYear_EC = true;

else{
    leapYear_EC = false;

}

if (leapYear_EC == true){
    cout<<endl<<year<<" is a leap year.\n";
}
else{
    cout<<endl<<year<<" isn't a leap year.\n";
}

cin.get();
cin.ignore();
}

else if(index == 2){

    cout<<"\nNow Enter a year from the Gregorian Calender \n";

    int year;

        do{
            error = 0;
            cin>>year;

            if (year < 0 || year > 9999){
            cout<<"Sorry! This program supports neither negative years or any year beyond the year 9999.\nTry to enter a year from the Ethiopian calender.\n\n";
            error++;
            }

}while (error != 0);


    if (year % 400 == 0)

	leapYear_GC = true;

	if (year % 100 == 0)
	leapYear_GC = false;

    if (year % 4 == 0)
	leapYear_GC = true;

else{
		leapYear_GC = false;
}

if (leapYear_GC == true){
    cout<<endl<<year<<" is a leap year.\n";
}
else{
    cout<<endl<<year<<" isn't a leap year.\n";
}

cin.get();
cin.ignore();
}

else{

cout<< "Invalid input. Enter 1 for EC and 2 for GC. Try again.\n";
error++;

}

}while (error != 0);
}

if(Index == 7){

int diff[]={0,3,2,5,0,3,5,1,4,6,2,4};
int day, month, year, week_day, leapYear_GC;
int error = 0;

   cout<<"Enter The date in the Gregorian Calender\n"<<endl;

do{

    cout<<"Day: ";
	cin>> day;

	cout<<"Month (ex: For February write 2): ";
	cin>> month;

	cout<<"Year: ";
	cin>> year;

    error = 0;

    if(month < 1 || month > 12){

        cout<<"There is no such month. Enter an integer from 1 to 12 for the corresponding month.\n";
        error++;
    }
    if (year < 1 || year > 9999){

        cout<<"This program neither accepts negative years nor any year above the year 9999. Better Luck Next time\n";
        error++;
    }
    if (year % 400 == 0)

        leapYear_GC = true;

        if (year % 100 == 0)
        leapYear_GC = false;

        if (year % 4 == 0)
        leapYear_GC = true;

    else{
            leapYear_GC = false;
    }


    if (month == 2 && day > 29 && leapYear_GC == true){

        cout<<"There is no such day. Enter a valid day for the month.\n";
        error++;
    }

    else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30){

        cout<<"There is no such day. Enter a valid day for the month.\n";
        error++;
    }

    else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31){

        cout<<"There is no such day. Enter a valid day for the month.\n";
        error++;
    }

    else if(month == 2 && day > 28 && leapYear_GC == false){

        cout<<"There is no such day. Enter a valid day for the month.\n";
        error++;
    }

}while(error != 0);


    year -= month;

    week_day = (year + (year/4) - (year/100) + (year/400) + diff[month-1] + day) % 7;


    switch(week_day){
        case 1:
            cout<<"The day is Monday"<<endl;
        break;
        case 2:
            cout<<"The day is Tuesday"<<endl;
        break;
        case 3:
            cout<<"The day is Wednesday"<<endl;
        break;
        case 4:
            cout<<"The day is Thursday"<<endl;
        break;
        case 5 :
            cout<<"The day is Friday"<<endl;
        break;
        case 6:
            cout<<"The day is Saturday"<<endl;
        break;
        case 7:
            cout<<"The day is Sunday"<<endl;
        break;}
    }

if(Index == 8){
int Day, Month, Year, year, day, month, week = 2, temp, Temp, Count, j, temp_week, i, max;
bool leapYear_GC, leapYear_EC;
int error;
string zemen;
cout<<"\nThis Program Displays the Ethiopian Calender & Gregorian Calender (Primary Ethiopian Calender)\n";

do{

error = 0;

    cout<<"\nEnter a year from the Ethiopian Calender :  ";
    cin>>year;
    if (year < 0 || year > 5500){
        cout<<"\nSorry! This converter supports neither negative years nor any year beyond the year 5500.\nTry to enter a valid year this time around.\n";
        error++;
    }
}while(error != 0);

int remainder;
remainder = (5500 + year) % 4;

if(remainder == 0)
    zemen = " YOHANNES ";

else if(remainder == 1)
    zemen = " MATEOS ";

else if(remainder == 2)
    zemen = " MARKOS ";

else if(remainder == 3)
    zemen = " LUKAS ";

	temp = year;
	week += ((year / 4) * 2 + (year - (year / 4) ));
	week = week%7;

if(year%4 == 0){
	Day = 12;
}

else
	Day= 11;
    day = month = 1;
    Year = year + 7;
    Month = 9;


while(temp == year){

    switch(month) {
        case 1:
            cout<<endl<<zemen<<endl<<endl;
            cout<<"\n MESKEREM "<<year<<"\t\t\t SEPTEMBER/OCTOBER "<<Year; break;
        case 2:
            cout<<zemen<<endl<<endl;
            cout<<" TIKIMT "<<year<<"\t\t\t OCTOBER/NOVEMBER "<<Year; break;
        case 3:
            cout<<zemen<<endl<<endl;
            cout<<"\n HIDAR "<<year<<"\t\t\t NOVEMBER/DECEMBER "<<Year; break;
        case 4:
            cout<<endl<<zemen<<endl<<endl;
            cout<<" TAHSAS "<<year<<"\t\t\t DECEMBER/JANUARY "<<Year<<" - "<<Year + 1; break;
        case 5:
            cout<<zemen<<endl<<endl;
            cout<<"\n TIR "<<year<<"\t\t\t JANUARY/FEBRUARY "<<Year ; break;
        case 6:
            cout<<zemen<<endl<<endl;
            cout<<" YEKATIT "<<year<<"\t\t\t FEBRUARY/MARCH "<<Year ; break;
        case 7:
            cout<<zemen<<endl<<endl;
            cout<<"\n MEGABIT "<<year<<"\t\t\t MARCH/APRIL "<<Year ; break;
        case 8:
            cout<<endl<<zemen<<endl<<endl;
            cout<<" MIYAZIYA "<<year<<"\t\t\t APRIL/MAY "<<Year ; break;
        case 9:
            cout<<zemen<<endl<<endl;
            cout<<"\n GINBOT "<<year<<"\t\t\t MAY/JUNE "<<Year ; break;
        case 10:
            cout<<zemen<<endl<<endl;
            cout<<"\n SENE "<<year<<"\t\t\t JUNE/JULY "<<Year ; break;
        case 11:
            cout<<endl<<zemen<<endl<<endl;
            cout<<" HAMLE "<<year<<"\t\t\t JULY/AUGUST "<<Year ; break;
        case 12:
            cout<<zemen<<endl<<endl;
            cout<<"\n NEHASE "<<year<<"\t\t\t AUGUST/SEPTEMBER "<<Year ; break;
        case 13:
            cout<<zemen<<endl<<endl;
            cout<<" PAGUME "<<year<<"\t\t\t SEPTEMBER "<<Year ; break;
    }
	cout<<endl;
    cout<<"_______________________________________________________________"<<endl;
    cout<<"   EHU   |"<<"   SEG  |"<<"   MAK  |"<<"   REB  |"<<"   HAM  |"<<"   ARB   |"<<"  QID  |"<<endl;

	if ((year+1) % 4 == 0)
		leapYear_EC = true;
	else
		leapYear_EC = false;

	if(Year%4 == 0){

        if(Year % 100 == 0){

            if(Year % 400 == 0){
			leapYear_GC = true;
		}
			else
			leapYear_GC = false;
		}
		else{
            leapYear_GC = true;
		}
	}
	else{
        leapYear_GC = false;
	}

	Temp = month;
	Count = 1;

	for(int i = 0; i < 6 && temp == year; i++) {
		cout<<"_______________________________________________________________"<<endl;
		if(week > 7)
            {week = week % 7;}
		j = 0;
		max = 30, temp_week = week;
		if(leapYear_EC && month == 13)
            {max = 6;}
		else if (!leapYear_EC && month == 13)
            {max = 5;}

	if(i == 0) {
		if(week > 7)
            {week = week%7;}

		for( ; j < week; j++){
			cout<<setw(9)<<"|";
		}
	}
	for( ; j < 7; j++) {

		if(Temp != month)
            break;
		if(week > 7)
            week = week % 7;

		cout.setf(ios::right);

		cout<<setw(8)<< day <<"|";

		 	if(day == 30) {

 				day = 1;
 				month++;
 			}
			else if(month == 13 && leapYear_EC && day == 6) {

				month = day = 1;
				year++;
			}
			else if(month == 13 && !leapYear_EC && day == 5) {

				month = day = 1;
				year++;
			}
			else{

                day++;
            }

			week++;
	}

	j = 0;
	week = temp_week;
	cout<<endl;

	if(i==0){
		if(week > 7){
            week = week%7;
        }
		for( ; j < week; j++) {
			cout<<setw(9)<<"|";
		}
	}

	for( ;j < 7; j++) {

		if(Count > max)

            break;
            Count++;

		if(week > 7){

			week = week%7;
        }

		cout.setf(ios::left,ios::adjustfield);
		cout<<setw(8)<<Day<<"|";

        if((Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10) && Day == 31){

            Month++;
            Day = 1;
        }

        else if((Month == 4 || Month == 6 || Month == 9 || Month == 11) && Day == 30) {

            Month++;
            Day = 1;
        }

        else if(Month == 12 && Day == 31) {

            Year++;
            Month = Day = 1;
        }

        else if(leapYear_GC && Month == 2 && Day == 29) {

            Month++;
            Day = 1;
        }
        else if(!leapYear_GC && Month == 2 && Day == 28) {

            Month++;
            Day = 1;
        }
        else{
            Day++;
        }

        week++;
	}

	cout<<endl;
	}
}
cin.get();
cin.ignore();
}
system("pause");
system("CLS");

}while(Index!=9);

return 0;
}
