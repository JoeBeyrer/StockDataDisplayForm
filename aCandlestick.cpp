#include "pch.h"
#include "aCandlestick.h"
using namespace CppCLRWinFormsProject;
// Definition for the candlestick constructor
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



