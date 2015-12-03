#include <stdio.h>
#include <math.h>
#include "assignment-2.h"


int main(void)
{
	int i;
	int g = 1;
	while (g == 1) {
		printf("Conversion menu\n");
		printf("1. Convert a given Austin time to Irish time\n");
		printf("2. Convert a given Irish time to Austin time\n");
		printf("3. Convert a given USD value to EUR\n");
		printf("4. Convert a given EUR value to USD value\n");
		printf("5. Convert a given Fahrenheit temperature to Celsius\n");
		printf("6. Convert a given Celsius temperature to Fahrenheit\n");
		printf("7. Convert a given weight in kg to pounds, ounces\n");
		printf("8. Convert a given weight in pounds, ounces to kg\n");
		printf("9. Convert a given distance in km to miles\n");
		printf("10. Convert a given distance in miles to km\n");
		printf("11. Stop doing conversions and quit the program\n\n");
		printf("Enter a number from the menu (1-11) to select a specific conversion to perform or to quit:");
		scanf_s("%d", &i);
		switch (i) {
		case 1: //work
		{
			int Ahour, Amin, Ihour, Imin, day;
			printf("Please enter the Austin time, in hours and minutes, that you want to convert:");
			scanf_s("%d %d", &Ahour, &Amin);
			AuTimeToIr(Ahour, Amin, &Ihour, &Imin, &day);
			if (Amin < 10) {
				if (day == 0) {
					printf("The time in Ireland equivalent to %d:0%d in Austin is %d:0%d of the same day.\n\n", Ahour, Amin, Ihour, Imin);
				}
				else {
					printf("The time in Ireland equivalent to %d:0%d in Austin is %d:0%d of the next day.\n\n", Ahour, Amin, Ihour, Imin);
				}
			}
			else {
				if (day == 0) {
					printf("The time in Ireland equivalent to %d:%d in Austin is %d:%d of the same day.\n\n", Ahour, Amin, Ihour, Imin);
				}
				else {
					printf("The time in Ireland equivalent to %d:%d in Austin is %d:%d of the next day.\n\n", Ahour, Amin, Ihour, Imin);
				}
			}
			break;
		}
		case 2: //work
		{
			int Ahour1, Amin1, Ihour1, Imin1, day1;
			printf("Please enter the Ireland time, in hours and minutes, that you want to convert:");
			scanf_s("%d %d", &Ihour1, &Imin1);
			IrTimeToAu(Ihour1, Imin1, &Ahour1, &Amin1, &day1);
			if (Imin1 < 10) {
				if (day1 == 0) {
					printf("The time in Austin equivalent to %d:0%d in Ireland is %d:0%d of the same day.\n\n", Ihour1, Imin1, Ahour1, Amin1);
				}
				else {
					printf("The time in Austin equivalent to %d:0%d in Ireland is %d:0%d of the previous day.\n\n", Ihour1, Imin1, Ahour1, Amin1);
				}
			}
			else {
				if (day1 == 0) {
					printf("The time in Austin equivalent to %d:%d in Ireland is %d:%d of the same day.\n\n", Ihour1, Imin1, Ahour1, Amin1);
				}
				else {
					printf("The time in Austin equivalent to %d:%d in Ireland is %d:%d of the previous day.\n\n", Ihour1, Imin1, Ahour1, Amin1);
				}
			}
			break;
		}
		case 3: //work
		{
			int dollar;
			int cent;
			double euros;
			printf("Please enter the number of dollars and cents that you want to convert:");
			scanf_s("%d %d", &dollar, &cent);
			euros = USDToEUR(dollar, cent);
			if (cent < 10) {
				printf("%.2f Euros is equivalent to $%d.0%d in US Dollars.\n\n", euros, dollar, cent);
			}
			else {
				printf("%.2f Euros is equivalent to $%d.%d in US Dollars.\n\n", euros, dollar, cent);	//if you do %.2f, the values are 23.32 instead of 23.320000
			}
			break;
		}
		case 4: //work
		{
			double Euros;
			int Dollars;
			int Cents;
			printf("Please enter the number of Euros that you want to convert:");
			scanf_s("%lf", &Euros);
			EURToUSD(Euros, &Dollars, &Cents);
			if (Cents < 10) {
				printf("$%d.0%d in US Dollars is equivalent to %.2f Euros.\n\n", Dollars, Cents, Euros);
			}
			else {
				printf("$%d.%d in US Dollars is equivalent to %.2f Euros.\n\n", Dollars, Cents, Euros);
			}
			break;
		}
		case 5: // work
		{
			int ftoc;
			double ftoc1;
			printf("Please enter the temperature in fahrenheit that you want to convert:");
			scanf_s("%d", &ftoc);
			ftoc1 = fahrenheitToCelsius(ftoc);
			printf("%f Celsius is equivalent to %d Fahrenheit.\n\n", ftoc1, ftoc);
			break;
		}
		case 6: //work
		{
			double ctof;
			int ctof1;
			printf("Please enter the temperature in celsius that you want to convert:");
			scanf_s("%lf", &ctof);
			ctof1 = celsiusToFahrenheit(ctof);
			printf("%d Fahrenheit is equivalent to %f Celsius.\n\n", ctof1, ctof);
			break;
		}
		case 7: //work
		{
			int pounds1;
			int ounces1;
			double kilos1;
			printf("Please enter the number of kilograms that you want to convert:");
			scanf_s("%lf", &kilos1);
			kgToLbOz(kilos1, &pounds1, &ounces1);
			printf("%d lb %d oz is equivalent to %f kg. \n\n", pounds1, ounces1, kilos1);
			break;
		}
		case 8: //work
		{
			int pounds;
			int ounces;
			double kilos;
			printf("Please enter the number of pounds and ounces that you want to convert:");
			scanf_s("%d %d", &pounds, &ounces);
			kilos = lbOzToKg(pounds, ounces);
			printf("%f kg is equivalent to %d lb %d oz. \n\n", kilos, pounds, ounces);
			break;
		}
		case 9: //work
		{
			double ktom;
			double ktom1;
			printf("Please enter the number of kilometers that you want to convert:");
			scanf_s("%lf", &ktom);
			ktom1 = kmToMi(ktom);
			printf("%f mi is equivalent to %f km.\n\n", ktom1, ktom);
			break;
		}
		case 10: //work
		{
			double mtok;
			double mtok1;
			printf("Please enter the number of miles that you want to convert:");
			scanf_s("%lf", &mtok);
			mtok1 = miToKm(mtok);
			printf("%f km is equivalent to %f mi.\n\n", mtok1, mtok);
			break;
		}
		case 11:
			printf("Good Bye");
			g = 0;
			break;
		default:
			printf("Not a valid response. Try again\n\n");
			break;
		}
	}
	return 0;
}

/*
* 1
* AuTimeToIr : Converts a given time in Austin to the equivalent time in Ireland
* hour: hour in Austin
* minute : minute in Austin
* IrHour : pointer to where hour in Ireland will be stored
* IrMinute : pointer to where minute in Ireland will be stored
* IrDay : pointer to where day (previous, same, next) will be stored
*
* The time in Austin will be given by hour and minute. After execution, the ints pointed to
* by IrHour and IrMinute should hold the equivalent time in Ireland
* IrDay should point to an int that will have the value:
* -1 if the time in Ireland corresponds to the previous day
*  0 if the time in Ireland corresponds to the same day
*  1 if the time in Ireland corresponds to the next day
*/
void AuTimeToIr(int hour, int minute, int* IrHour, int* IrMinute, int* IrDay) {
	if ((hour + 6) > 23) {
		*IrDay = 1;
	}
	else {
		*IrDay = 0;
	}
	*IrHour = (hour + 6) % 24;
	*IrMinute = minute;
}

/*
* 2
* IrTimeToAu : Converts a given time in Ireland to the equivalent time in Austin
* hour: hour in Ireland
* minute : minute in Ireland
* AuHour : pointer to where hour in Austin will be stored
* AuMinute : pointer to where minute in Austin will be stored
* AuDay : pointer to where day (previous, same, next) will be stored
*
* The time in Ireland will be given by hour and minute. After execution, the ints pointed to
* by AuHour and AuMinute should hold the equivalent time in Austin
* AuDay should point to an int that will have the value:
* -1 if the time in Austin corresponds to the previous day
*  0 if the time in Austin corresponds to the same day
*  1 if the time in Austin corresponds to the next day
*/
void IrTimeToAu(int hour, int minute, int* AuHour, int* AuMinute, int* AuDay) {
	if ((hour - 6) < 0) {
		*AuDay = -1;
		hour = hour + 24;
	}
	else {
		*AuDay = 0;
	}
	*AuHour = (hour - 6) % 24;
	*AuMinute = minute;
}

/*
* 3
* USDToEUR : Converts a given dollar and cent amount to euros
* dollars : how many dollars
* cents : how many cents
*
* returns : equivalent value in Euros
*/
double USDToEUR(int dollars, int cents) {
	double euro;
	euro = (dollars*.74) + (cents*.01*.74);
	double euro1 = round(euro * 100) / 100;
	return euro1;
}

/*
* 4
* EURToUSD : Converts a given euro amount into dollars and cents
* euros : how many euros
* dollars : pointer to where dollar amount will be stored
* cents : pointer to where cent amount will be stored
*
* After execution, the ints pointed to by dollars and cents will hold the equivalent
* monetary amount in USD
*/
void EURToUSD(double euros, int* dollars, int* cents) {
	euros = euros * 1.36;
	double dollarvalue = trunc(euros);
	double centvalue = euros - dollarvalue;
	centvalue = centvalue * 100;
	centvalue = round(centvalue);
	int dollarvalue1 = (int)dollarvalue;
	int centvalue1 = (int)centvalue;
	*dollars = dollarvalue1;
	*cents = centvalue1;
}

/*
* 5
* fahrenheitToCelsius : Converts a temperature in Fahrenheit to Celsius
* fahrenheit : the temperature in Fahrenheit
*
* returns : the equivalent temperature in Celsius
*/
double fahrenheitToCelsius(int fahrenheit) {
	double cels;
	cels = (5.0 / 9.0)*(fahrenheit - 32);
	cels = round(cels * 100) / 100;
	return cels;
}

/*
* 6
* celsiusToFahrenheit : Converts a temperature in Celsius to Fahrenheit
* celsius : the temperature in Celsius
*
* returns : the equivalent temperature in Fahrenheit
*/
int celsiusToFahrenheit(double celsius) {
	return (int)round((((9.0 / 5.0)* celsius) + 32.0));
}

/*
* 7
* kgToLbOz : Converts a weight in kilograms to pounds and ounces
* kg : the weight in kilograms
* lb : pointer to where pound amount will be stored
* oz : pointer to where ounce amount will be stored
*
* after execution, the ints pointed to by lb and oz should hold the
* equivalent weight in pounds and ounces
*/
void kgToLbOz(double kg, int* lb, int* oz) {
	*lb = (int)trunc(((kg * 1000.00) / 453.59237));
	double remaining = (kg * 1000.00 / 453.59237) - (trunc(((kg * 1000.00) / 453.59237)));
	*oz = (int)round((remaining * 16.00));
	if ((int)round((remaining * 16.00)) == 16)
	{
		*oz = 0;
		*lb = (int)(trunc(((kg * 1000.00) / 453.59237)) + 1.00);
	}
}

/*
* 8
* lbOzToKg : Converts a weight in pounds and ounces to kilograms
* lb : pounds
* oz : ounces
*
* returns : equivalent weight in kilograms
*/
double lbOzToKg(int lb, int oz) {
	double kilo;
	kilo = ((lb * 453.59237) / 1000.00) + (((oz / 16.00)*453.59237) / 1000.00);
	kilo = round(kilo * 100) / 100;
	return kilo;
}


/*
*9
* kmToMi : Converts a distance in kilometers to miles
* km : distance in kilometers
*
* returns : equivalent distance in miles
*/
double kmToMi(double km) {
	double Mile;
	Mile = km *0.6213712;
	Mile = round(Mile * 100) / 100;
	return Mile;
}

/*
* 10
* miToKm : Converts a distance in miles to kilometers
* mi : distance in miles
*
* returns : equivalent distance in kilometers
*/
double miToKm(double mi) {
	double Kilometer;
	Kilometer = mi / 0.6213712;
	Kilometer = round(Kilometer * 100) / 100;
	return Kilometer;
}
