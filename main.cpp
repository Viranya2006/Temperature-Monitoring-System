#include <iostream>
#include <windows.h> 
using namespace std;

int opt;
struct Temperature
{
    float day_temp = 0.0;
    float night_temp = 0.0;
    float fluctuation = 0.0;
    const float max_day_temp = 80;
    const float max_night_temp = 62;
    const float min_day_temp = 70;
    const float min_night_temp = 56;

};
Temperature temp[31];

void Display_Main_menu();
void Display_Temp();
void cal_fluctuation();
void Ana_Suitability();
void convert_to_F();

int main()
{

    Display_Main_menu();
    return 0;

}

void Display_Main_menu()
{
    system("Color B");
    cout << "\nThis is the Main Menu:" << endl;
    cout << "" << endl;
    cout << "1. ADD/Display Temperatures" << endl;
    cout << "2. Calculate Fluctuations" << endl;
    cout << "3. Analyze Suitability" << endl;
    cout << "4. Convert Temperature (centigrade to Fahrenheit)" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter Option: ";

    cin >> opt;

    switch (opt)
    {
    case 1: Display_Temp();
        break;
    case 2:cal_fluctuation();
        break;
    case 3:Ana_Suitability();
        break;
    case 4:convert_to_F();
        break;
    case 5:cout << "Exiting the Function..........Have a Nice Day!" << endl;
        break;
    default:cout << "Invalid option, please enter again" << endl;
        Display_Main_menu();
        break;
    }
}

void Display_Temp()
{
    system("Color c");

    cout << "" << endl;
    cout << "1.Input Day time Temperature for the month " << endl;
    cout << "2.Input Night time Temperature for the month " << endl;
    cout << "3.Display Day time Temperature for the month " << endl;
    cout << "4.Display Night time Temperature for the month " << endl;
    cout << "5.Main Menu" << endl;

    cout << "" << endl;

    cout << "Enter The Option:";
    cin >> opt;

    if (opt == 1)
    {
        cout << "" << endl;

        for (int i = 1; i < 31; i++)
        {
            cout << "Enter Day Time Temperature of Day " << i << endl;
            cin >> temp[i].day_temp;
        }
        cout << "" << endl;
        cout << "All temperatures stored Successfully" << endl;
        Display_Temp();
    }
    else if (opt == 2)
    {
        cout << "" << endl;

        for (int i = 1; i < 31; i++)
        {
            cout << "Enter Night Time Temperature of Day " << i << endl;
            cin >> temp[i].night_temp;
        }
        cout << "" << endl;
        cout << "All temperatures stored Successfully" << endl;
        Display_Temp();
    }
    else if (opt == 3)
    {
        cout << "" << endl;

        for (int i = 1; i < 31; i++)
        {
            cout << "Day " << i << " Temp of Daytime - " << temp[i].day_temp << " F" << endl;
        }
        Display_Temp();
    }
    else if (opt == 4)
    {
        cout << "" << endl;

        for (int i = 1; i < 31; i++)
        {
            cout << "Day " << i << " Temp of Night time - " << temp[i].night_temp << " F" << endl;
        }
        Display_Temp();
    }
    else if (opt == 5)
    {
        cout << "" << endl;

        Display_Main_menu();
    }
    else
    {
        cout << "" << endl;

        cout << "Invalid option please enter again!" << endl;
        Display_Temp();
    }


}
void cal_fluctuation()
{
    system("Color D");

    float total_day_temp = 0.0;
    float total_night_temp = 0.0;
    float average_fluctuation = 0.0;
    float average_day_temp = 0.0;
    float average_night_temp = 0.0;

    float max_day_temp = -9999.0;  // Start with a very low value
    float min_day_temp = 9999.0;   // Start with a very high value
    float max_night_temp = -9999.0; // Start with a very low value
    float min_night_temp = 9999.0;  // Start with a very high value

    for (int i = 1; i < 31; i++)
    {
        total_day_temp += temp[i].day_temp;
        total_night_temp += temp[i].night_temp;

        // Determine maximum and minimum temperatures
        if (temp[i].day_temp > max_day_temp)
        {
            max_day_temp = temp[i].day_temp;
        }
        if (temp[i].day_temp < min_day_temp)
        {
            min_day_temp = temp[i].day_temp;
        }
        if (temp[i].night_temp > max_night_temp)
        {
            max_night_temp = temp[i].night_temp;
        }
        if (temp[i].night_temp < min_night_temp)
        {
            min_night_temp = temp[i].night_temp;
        }
    }

    average_fluctuation = (total_day_temp - total_night_temp) / 30;
    average_day_temp = total_day_temp / 30;
    average_night_temp = total_night_temp / 30;

    // Options
    cout << "" << endl;

    cout << "1. Display Fluctuation" << endl;
    cout << "2. Display Max, Min, and Average temps" << endl;
    cout << "3. Main Menu" << endl;

    cout << "Enter option: ";
    cin >> opt;

    if (opt == 1) // Display daily & average fluctuation
    {
        cout << "" << endl;

        for (int i = 1; i < 31; i++)
        {
            temp[i].fluctuation = temp[i].day_temp - temp[i].night_temp;
            cout << "Day " << i << " fluctuation: " << temp[i].fluctuation << " F" << endl;
        }
        cout << "" << endl;
        cout << "Average Temperature Fluctuation for the Month: " << average_fluctuation << " F" << endl;
        cal_fluctuation();
    }
    else if (opt == 2) // Display Max, Min, and average Temp
    {
        cout << "" << endl;

        cout << "Average Day Temp: " << average_day_temp << " F" << endl;
        cout << "Average Night Temp: " << average_night_temp << " F" << endl;

        cout << "" << endl;

        cout << "Max Day Temp: " << max_day_temp << " F" << endl;
        cout << "Min Day Temp: " << min_day_temp << " F" << endl;
        cout << "Max Night Temp: " << max_night_temp << " F" << endl;
        cout << "Min Night Temp: " << min_night_temp << " F" << endl;
        cal_fluctuation();
    }
    else if (opt == 3)
    {
        cout << "" << endl;

        Display_Main_menu();
    }
    else
    {
        cout << "" << endl;

        cout << "Invalid option please enter again!" << endl;
        cal_fluctuation();
    }
}

void Ana_Suitability()
{
    system("Color E");

    cout << "" << endl;

    int suitable_days = 0;
    cout << "\nAnalyzing Suitability for Orchid Growth:" << endl;
    cout << "" << endl;

    for (int i = 1; i < 31; i++)
    {
        /*if the day time Temperature between 70 - 80 F and
        Night time Temperature between 56 - 62 F and
        fluctuation between 10 - 15 then the DAY suitable for Orchid Growth*/

        float fluctuation = 0.0;
        fluctuation = temp[i].day_temp - temp[i].night_temp;
        if (temp[i].day_temp >= 70 && temp[i].day_temp <= 80 &&
            temp[i].night_temp >= 56 && temp[i].night_temp <= 62 &&
            fluctuation >= 10 && fluctuation <= 15
            )
        {
            cout << "Day " << i << " is suitable for Orchid Growth " << endl;
            suitable_days++; // Increment suitable_days here
        }

    }
    if (suitable_days == 0)
    {
        cout << "" << endl;
        cout << "No suitable days for orchid growth." << endl;
    }
    else
    {
        // Display how many suitable Days in the month
        cout << "" << endl;
        cout << " NO of Suitable Days :" << suitable_days << " out of 30" << endl;
    }
    Display_Main_menu();
}

void convert_to_F()//convert centigrade to Fahrenheit
{
    system("Color A");

    cout << "" << endl;

    float centigrade = 0.0;
    float Fahrenheit = 0.0;

    cout << "Enter The Temperature in centigrade " << endl;
    cin >> centigrade;
    //1 centigrade = 33.8 Fahrenheit
    Fahrenheit = (centigrade * 1.8) + 32;

    cout << Fahrenheit << " F";
    Display_Main_menu();
}
