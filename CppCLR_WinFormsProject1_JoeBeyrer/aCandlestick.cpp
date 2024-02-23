#include "pch.h"
#include "aCandlestick.h"
using namespace CppCLRWinFormsProject;
/// <summary>
/// Constructor that parses line from csv file to initialize as candlestick parameters
/// </summary>
/// <param name="ohlcLine"></param>
aCandlestick::aCandlestick(String^ ohlcLine) {
    // Split the line from the csv file into tokens for parsing
    array<String^>^ tokens = ohlcLine->Split(',');
    // Assign the values from the tokens
    String^ combinedDate = tokens[2]->Trim('"') + tokens[3]->Trim('"'); // Remove the quotes from the date and recombine the tokens (split by delimeter)
    DateTime::TryParse(combinedDate, tempDate);// Parse the date and temporarily store in tempDate
    date = tempDate; // Assign tempDate to the date property
    open = Double::Parse(tokens[4]); // Assign the 5th token to open
    high = Double::Parse(tokens[5]); // Assign the 6th token to high
    low = Double::Parse(tokens[6]); // Assign the 7th token to low
    close = Double::Parse(tokens[7]); // Assign the 8th token to close
    volume = Int64::Parse(tokens[8]); // Assign the 9th token to volume
}

/// <summary>
/// Constructor that uses user defined values for each field of the candlestick
/// </summary>
/// <param name="d"></param>
/// <param name="o"></param>
/// <param name="h"></param>
/// <param name="l"></param>
/// <param name="c"></param>
/// <param name="v"></param>
aCandlestick::aCandlestick(String^ d, double o, double h, double l, double c, unsigned long v) {
    DateTime::TryParse(d, tempDate);// Parse the input date d and temporarily store in tempDate
    date = tempDate; // Assign tempDate to the date property
    open = o; // Assign o to open
    high = h; // Assign h to high
    low = l; // Assign l to low
    close = c; // Assign c to close
    volume = v; // Assign v to volume
}

/// <summary>
/// This constructor takes no parameters. All values initialized to 0 (date time to default start date)
/// </summary>
aCandlestick::aCandlestick() {
    // Set all values to 0
    DateTime::TryParse("Jan 1, 1800", tempDate);// Parse the date and temporarily store in tempDate
    date = tempDate; // Assign tempDate to the date property
    open = 0.0; 
    high = 0.0;
    low = 0.0; 
    close = 0.0; 
    volume = 0;
}



