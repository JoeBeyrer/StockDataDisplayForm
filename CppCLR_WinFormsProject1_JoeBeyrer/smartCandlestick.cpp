#include "pch.h"
#include "smartCandlestick.h"
using namespace CppCLRWinFormsProject;

/// <summary>
/// This method is used to calculate all higher level properties required by
/// the smart candlestick including range, top price, bottom price, body range,
/// upper tail, and lower tails
void smartCandlestick::setHigherLevelProperties() {
	range = high - low; // range is the high - the low
	topPrice = std::max(open, close); // topPrice is the maximum betrween the open and the close
	bottomPrice = std::min(open, close); // bottomPrice is the minimum betrween the open and the close
	bodyRange = topPrice - bottomPrice; // the bodyRange is the top price - the low price
	upperTail = high - topPrice; // the upperTail is the high - the top price
	lowerTail = bottomPrice - low; // the lowerTail is the bottom price - the low
}

/// <summary>
/// This method is used to calculate the patterns of a smart candlestick inscluding
/// if it is a doji, is a marubozu, is a hammer, is a gravestone, is a dragonfly,
/// is a long legged doji, is bullish, is bearish, and is neutral 
/// </summary>
void smartCandlestick::computePatterns() {
	isDoji = bodyRange <= 0.1 * range; // A candlestick is a doji if it has a very small body
	isMarubozu = bodyRange >= 0.9 * range; // A candlestick is a marubozu if it has a very large body (high and top price are similar and low and bottom price are similar)
	isHammer = bodyRange >= 0.15 * range && lowerTail >= 2.0/3.0 * range; // A hammer has a very large lower tail (distinguished from a doji)
	isInverseHammer = bodyRange >= 0.15 * range && upperTail >= 2.0 / 3.0 * range; // A hammer has a very large upper tail (distinguished from a doji)
	isGravestone = isDoji && lowerTail <= 0.08 * range; // A gravestone is a doji where the body is very close (or at) the low
	isDragonfly = isDoji && upperTail <= 0.08 * range; // A dragonfly is a doji where the body is very close (or at) the high
	isLongLegged = isDoji && (topPrice < 1.03 * (high - bodyRange / 2)) && (bottomPrice > 0.97 * (high - bodyRange / 2)); // A klong legged doji is a doji with large upper and lower tails
	isBullish = (!(isDoji) && open < close) || isDragonfly; // A candlestick is bullish if the open is greater than the close (or if it is a dragonfly)
	isBearish = (!(isDoji) && close < open) || isGravestone; // A candlestick is bearish if the close is greater than the open (or if it is a gravestone)
	isNeutral = !(isBullish) && !(isBearish); // A candlestick is neutral if it is not bearish and not bullish
	
}

/// <summary>
/// Constructor that parses line from csv file to initialize as smart candlestick parameters
/// </summary>
/// <param name="ohlcLine"></param>
smartCandlestick::smartCandlestick(String^ ohlcLine) : aCandlestick(ohlcLine) {
	setHigherLevelProperties();
	computePatterns();
}

/// <summary>
/// Constructor that uses user defined values for each field of the smart candlestick
/// </summary>
/// <param name="d"></param>
/// <param name="o"></param>
/// <param name="h"></param>
/// <param name="l"></param>
/// <param name="c"></param>
/// <param name="v"></param>
smartCandlestick::smartCandlestick(String^ d, double o, double h, double l, double c, unsigned long v) : aCandlestick(d, o, h, l, c, v) {
	setHigherLevelProperties();
	computePatterns();
}

/// <summary>
/// Constructor that takes no parameters. All values initialized to 0 (date time to default start date)
/// </summary>
smartCandlestick::smartCandlestick() : aCandlestick() {
	setHigherLevelProperties();
	computePatterns();
}
