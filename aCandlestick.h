#pragma once

#include <stdio.h>
#include <iostream>
#include <string>
#include <ctime>
using namespace System;
namespace CppCLRWinFormsProject {
	// candlestick class definition
	ref class aCandlestick
	{
		public:
			// Define date, open, high, low, and close values for a candlestick object
			property DateTime date;
			property double open;
			property double high;
			property double low;
			property double close;
			property unsigned long volume;
			DateTime tempDate; // without this, parsing directly into date causes all dates to be 1/1/0001
			// candlestick constructor
			aCandlestick(String^ ohlcLine);

	};
}
