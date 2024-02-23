#include "pch.h"
#include "Recognizer.h"
using namespace CppCLRWinFormsProject;


/// <summary>
/// This function is used for all recognizer classes to add the indeces of candlesticks
/// that satisfy the selected pattern to a list that will be used for displaying annotations.
/// It will do this by iterating through the list of candlesticks that is provided.
/// </summary>
/// <param name="LSCS"></param>
/// <returns></returns>
List<int>^ Recognizer::recognize(List<smartCandlestick^>^ LSCS) {
	// Create list to store indeces of candlesticks that satisfy the pattern selected
	List<int>^ result = gcnew List<int>();
	// Iterate through all candlesticks in list of smart candlesticks provided
	for (int i = length - 1; i < LSCS->Count; i++) {
		// Create a sublist on each iteration to keep track of current sublist - sublist will be the size of the chosen pattern length
		List<smartCandlestick^>^ sublist = LSCS->GetRange(i - length + 1, length);
		// Check if the pattern is satisfied within the sublist (different for each recognizer class)
		if (recognizePattern(sublist)) {
			// If pattern satisfied, add all indeces of candlesticks in sublist to indeces list for annotations
			if (length == 3) {
				// Only annotate middle pattern if it is a 3 candlestick pattern (valley or peak)
				result->Add(i - length + 2);
			}
			else {
				for (int j = i - length + 1; j < i + 1; j++) {
					result->Add(j);
				}
			}
		}
	}
	return result;
}

/// <summary>
/// Normal recognizer constructor defaults to "None" pattern selected and 0 pattern length
/// </summary>
Recognizer::Recognizer() {
	pattern = "None";
	length = 0;
}

/// <summary>
/// Bearish constructor sets length to 1 and the pattern name to Bearish
/// </summary>
bearishRecognizer::bearishRecognizer() {
	pattern = "Bearish";
	length = 1;
}

/// <summary>
/// recognizePattern function for bearish just checks if the candlestick is bearish
/// </summary>
/// <param name="sublist"></param>
/// <returns></returns>
bool bearishRecognizer::recognizePattern(List<smartCandlestick^>^ sublist) {
	return sublist[0]->isBearish;
}

/// <summary>
/// Bullish constructor sets length to 1 and the pattern name to Bullish
/// </summary>
bullishRecognizer::bullishRecognizer() {
	pattern = "Bullish";
	length = 1;
}

/// <summary>
/// recognizePattern function for bullish just checks if the candlestick is bullish
/// </summary>
/// <param name="sublist"></param>
/// <returns></returns>
bool bullishRecognizer::recognizePattern(List<smartCandlestick^>^ sublist) {
	return sublist[0]->isBullish;
}

/// <summary>
/// doji constructor sets length to 1 and the pattern name to doji
/// </summary>
dojiRecognizer::dojiRecognizer() {
	pattern = "Doji";
	length = 1;
}

/// <summary>
/// recognizePattern function for doji just checks if the candlestick is a doji
/// </summary>
/// <param name="sublist"></param>
/// <returns></returns>
bool dojiRecognizer::recognizePattern(List<smartCandlestick^>^ sublist) {
	return sublist[0]->isDoji;
}

/// <summary>
/// dragonfly constructor sets length to 1 and the pattern name to dragonfly
/// </summary>
dragonflyRecognizer::dragonflyRecognizer() {
	pattern = "Dragonfly Doji";
	length = 1;
}

/// <summary>
/// recognizePattern function for dragonfly just checks if the candlestick is a dragonfly
/// </summary>
/// <param name="sublist"></param>
/// <returns></returns>
bool dragonflyRecognizer::recognizePattern(List<smartCandlestick^>^ sublist) {
	return sublist[0]->isDragonfly;
}

/// <summary>
/// gravestone constructor sets length to 1 and the pattern name to gravestone
/// </summary>
gravestoneRecognizer::gravestoneRecognizer() {
	pattern = "Gravestone Doji";
	length = 1;
}

/// <summary>
/// recognizePattern function for gravestone just checks if the candlestick is a gravestone
/// </summary>
/// <param name="sublist"></param>
/// <returns></returns>
bool gravestoneRecognizer::recognizePattern(List<smartCandlestick^>^ sublist) {
	return sublist[0]->isGravestone;
}

/// <summary>
/// hammer constructor sets length to 1 and the pattern name to hammer
/// </summary>
hammerRecognizer::hammerRecognizer() {
	pattern = "Hammer";
	length = 1;
}

/// <summary>
/// recognizePattern function for hammer just checks if the candlestick is a hammer
/// </summary>
/// <param name="sublist"></param>
/// <returns></returns>
bool hammerRecognizer::recognizePattern(List<smartCandlestick^>^ sublist) {
	return sublist[0]->isHammer;
}

/// <summary>
/// marubozu constructor sets length to 1 and the pattern name to marubozu
/// </summary>
marubozuRecognizer::marubozuRecognizer() {
	pattern = "Marubozu";
	length = 1;
}

/// <summary>
/// recognizePattern function for marubozu just checks if the candlestick is a marubozu
/// </summary>
/// <param name="sublist"></param>
/// <returns></returns>
bool marubozuRecognizer::recognizePattern(List<smartCandlestick^>^ sublist) {
	return sublist[0]->isMarubozu;
}

/// <summary>
/// Neutral constructor sets length to 1 and the pattern name to Neutral
/// </summary>
neutralRecognizer::neutralRecognizer() {
	pattern = "Neutral";
	length = 1;
}

/// <summary>
/// recognizePattern function for neutral just checks if the candlestick is neutral
/// </summary>
/// <param name="sublist"></param>
/// <returns></returns>
bool neutralRecognizer::recognizePattern(List<smartCandlestick^>^ sublist) {
	return sublist[0]->isNeutral;
}

/// <summary>
/// inverse hammer constructor sets length to 1 and the pattern name to inverse hammer
/// </summary>
inverseHammerRecognizer::inverseHammerRecognizer() {
	pattern = "Inverse Hammer";
	length = 1;
}

/// <summary>
/// recognizePattern function for inverse hammer just checks if the candlestick is an inverse hammer
/// </summary>
/// <param name="sublist"></param>
/// <returns></returns>
bool inverseHammerRecognizer::recognizePattern(List<smartCandlestick^>^ sublist) {
	return sublist[0]->isInverseHammer;
}


/// <summary>
/// Engulfing pattern constructor sets the pattern length to 2 and the name to engulfing
/// </summary>
engulfingPatternRecognizer::engulfingPatternRecognizer() {
	pattern = "Engulfing";
	length = 2;
}

/// <summary>
/// This function takes in a sublist of 2 candlesticks and checks if it satisfies the conditions of engulfing - if it is either bearish engulfing or bullish engulfing
/// </summary>
/// <param name="sublist"></param>
/// <returns></returns>
bool engulfingPatternRecognizer::recognizePattern(List<smartCandlestick^>^ sublist) {
	// The sublist is in reverse order, so we check if the second in the sublist is engulfed by the first
	bool isBullishEngulfing = sublist[1]->high < sublist[0]->high && sublist[1]->low > sublist[0]->low && sublist[1]->isBearish && sublist[0]->isBullish && sublist[0]->open < sublist[1]->close && sublist[0]->close > sublist[1]->open;
	bool isBearishEngulfing = sublist[1]->high < sublist[0]->high && sublist[1]->low > sublist[0]->low && sublist[1]->isBullish && sublist[0]->isBearish && sublist[1]->open > sublist[0]->close && sublist[1]->close < sublist[0]->open;
	return (isBullishEngulfing || isBearishEngulfing);
}

/// <summary>
/// Bullish Engulfing pattern constructor sets the pattern length to 2 and the name to bullish engulfing
/// </summary>
bullishEngulfingPatternRecognizer::bullishEngulfingPatternRecognizer() {
	pattern = "Bullish Engulfing";
	length = 2;
}

/// <summary>
/// This function takes in a sublist of 2 candlesticks and checks if it satisfies the conditions of bullish engulfing
/// </summary>
/// <param name="sublist"></param>
/// <returns></returns>
bool bullishEngulfingPatternRecognizer::recognizePattern(List<smartCandlestick^>^ sublist) {
	// Candlesticks in reverse order, so check if second in sublist is engulfed (bodyRange and range engulfed) by the first, if second is bearish and if first is bullish
	return (sublist[1]->high < sublist[0]->high && sublist[1]->low > sublist[0]->low && sublist[1]->isBearish && sublist[0]->isBullish && sublist[0]->open < sublist[1]->close && sublist[0]->close > sublist[1]->open);
}

/// <summary>
/// Bearish Engulfing pattern constructor sets the pattern length to 2 and the name to bearish engulfing
/// </summary>
bearishEngulfingPatternRecognizer::bearishEngulfingPatternRecognizer() {
	pattern = "Bearish Engulfing";
	length = 2;
}

/// <summary>
/// This function takes in a sublist of 2 candlesticks and checks if it satisfies the conditions of bearish engulfing
/// </summary>
/// <param name="sublist"></param>
/// <returns></returns>
bool bearishEngulfingPatternRecognizer::recognizePattern(List<smartCandlestick^>^ sublist) {
	// Candlesticks in reverse order, so check if second in sublist is engulfed (bodyRange and range engulfed) by the first, if second is bullish and if first is bearish
	return (sublist[1]->high < sublist[0]->high && sublist[1]->low > sublist[0]->low && sublist[1]->isBullish && sublist[0]->isBearish && sublist[1]->open > sublist[0]->close && sublist[1]->close < sublist[0]->open);
}

/// <summary>
/// Harami pattern constructor sets the pattern length to 2 and the name to harami
/// </summary>
haramiPatternRecognizer::haramiPatternRecognizer() {
	pattern = "Harami";
	length = 2;
}

/// <summary>
/// This function takes in a sublist of 2 candlesticks and checks if it satisfies the conditions of harami - if it is either bearish harami or bullish harami
/// </summary>
/// <param name="sublist"></param>
/// <returns></returns>
bool haramiPatternRecognizer::recognizePattern(List<smartCandlestick^>^ sublist) {
	// The sublist is in reverse order, so we check if the first in the sublist is engulfed by the second
	bool isBullishHarami = sublist[1]->high > sublist[0]->high && sublist[1]->low < sublist[0]->low && sublist[1]->isBearish && sublist[0]->isBullish && sublist[0]->open > sublist[1]->close && sublist[0]->close < sublist[1]->open;
	bool isBearishHarami = sublist[1]->high > sublist[0]->high && sublist[1]->low < sublist[0]->low && sublist[1]->isBullish && sublist[0]->isBearish && sublist[1]->open < sublist[0]->close && sublist[1]->close > sublist[0]->open;
	return (isBullishHarami || isBearishHarami);
}

/// <summary>
/// Bullish Harami pattern constructor sets the pattern length to 2 and the name to bullish harami
/// </summary>
bullishHaramiPatternRecognizer::bullishHaramiPatternRecognizer() {
	pattern = "Bullish Harami";
	length = 2;
}

/// <summary>
/// This function takes in a sublist of 2 candlesticks and checks if it satisfies the conditions of bullish harami
/// </summary>
/// <param name="sublist"></param>
/// <returns></returns>
bool bullishHaramiPatternRecognizer::recognizePattern(List<smartCandlestick^>^ sublist) {
	// Candlesticks in reverse order, so check if first in sublist is engulfed (bodyRange and range engulfed) by the second, if second is bearish and if first is bullish
	return (sublist[1]->high > sublist[0]->high && sublist[1]->low < sublist[0]->low && sublist[1]->isBearish && sublist[0]->isBullish && sublist[0]->open > sublist[1]->close && sublist[0]->close < sublist[1]->open);
}

/// <summary>
/// Bearish Harami pattern constructor sets the pattern length to 2 and the name to bearish harami
/// </summary>
bearishHaramiPatternRecognizer::bearishHaramiPatternRecognizer() {
	pattern = "Bearish Harami";
	length = 2;
}

/// <summary>
///  This function takes in a sublist of 2 candlesticks and checks if it satisfies the conditions of bearish harami
/// </summary>
/// <param name="sublist"></param>
/// <returns></returns>
bool bearishHaramiPatternRecognizer::recognizePattern(List<smartCandlestick^>^ sublist) {
	// Candlesticks in reverse order, so check if first in sublist is engulfed (bodyRange and range engulfed) by the second, if second is bullish and if first is bearish
	return (sublist[1]->high > sublist[0]->high && sublist[1]->low < sublist[0]->low && sublist[1]->isBullish && sublist[0]->isBearish && sublist[1]->open < sublist[0]->close && sublist[1]->close > sublist[0]->open);
}


/// <summary>
/// Peak pattern constructor sets the pattern length to 3 and the name to peak
/// </summary>
peakRecognizer::peakRecognizer() {
	pattern = "Peak";
	length = 3;
}

/// <summary>
/// This function takes in a sublist of 3 candlesticks and checks if it satisfies the conditions of peak pattern
/// </summary>
/// <param name="sublist"></param>
/// <returns></returns>
bool peakRecognizer::recognizePattern(List<smartCandlestick^>^ sublist) {
	// Checks if middle candlestick has the highest high
	return (sublist[1]->high > sublist[0]->high && sublist[1]->high > sublist[2]->high);
}

/// <summary>
/// Valley pattern constructor sets the pattern length to 3 and the name to valley
/// </summary>
valleyRecognizer::valleyRecognizer() {
	pattern = "Valley";
	length = 3;
}

/// <summary>
/// This function takes in a sublist of 3 candlesticks and checks if it satisfies the conditions of valley pattern
/// </summary>
/// <param name="sublist"></param>
/// <returns></returns>
bool valleyRecognizer::recognizePattern(List<smartCandlestick^>^ sublist) {
	//// Checks if middle candlestick has the lowest low
	return (sublist[1]->low < sublist[0]->low && sublist[1]->low < sublist[2]->low);
}
