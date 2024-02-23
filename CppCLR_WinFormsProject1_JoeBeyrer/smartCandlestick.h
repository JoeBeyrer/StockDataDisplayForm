#pragma once
#include "aCandlestick.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <ctime>
using namespace System;
namespace CppCLRWinFormsProject {
	ref class smartCandlestick : aCandlestick
	{
		public:
			// Declare higher level properties to identify smart candlestick patterns
			property double range;
			property double topPrice;
			property double bottomPrice;
			property double bodyRange;
			property double upperTail;
			property double lowerTail;

			// Declare higher level patterns
			property bool isBullish;
			property bool isBearish;
			property bool isNeutral;
			property bool isDoji;
			property bool isMarubozu;
			property bool isHammer;
			property bool isInverseHammer;
			property bool isGravestone;
			property bool isDragonfly;
			property bool isLongLegged;

			// Functions used to compute higher level properties and patterns of smart candlesticks
			void setHigherLevelProperties();
			void computePatterns();

			//smart candlestick constructors - use candlestick constructor as a base
			smartCandlestick(String^ ohlcLine);
			smartCandlestick(String^ d, double o, double h, double l, double c, unsigned long v);
			smartCandlestick();
	};
}
