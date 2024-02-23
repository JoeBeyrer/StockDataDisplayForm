#pragma once
#include "smartCandlestick.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace System;
using namespace System::Collections::Generic;
using namespace System::ComponentModel;



namespace CppCLRWinFormsProject {
	/// <summary>
	/// Base recognizer class utilizing global recognize function along with virtual recognizePattern function for polymorphism.
	/// Since this class contains a virtual function, it is an abstract class and must be declared as such
	/// </summary>
	ref class Recognizer abstract
	{
	public:
		// Variables for pattern name and pattern length
		String^ pattern;
		int length;
		// Function to return list of indeces for all recognized pattterns
		List<int>^ recognize(List<smartCandlestick^>^ LSCS);
		// Virtual class remains undecfined in base class - defined seperately for each child recognizer class
		virtual bool recognizePattern(List<smartCandlestick^>^ sublist) = 0;

		Recognizer();

	};

	/// <summary>
	/// Derived class for recognizing bearish patterns
	/// </summary>
	ref class bearishRecognizer : public Recognizer {
	public:
		virtual bool recognizePattern(List<smartCandlestick^>^ sublist) override;
		bearishRecognizer();
	};

	/// <summary>
	/// Derived class for recognizing bullish patterns
	/// </summary>
	ref class bullishRecognizer : public Recognizer {
	public:
		virtual bool recognizePattern(List<smartCandlestick^>^ sublist) override;
		bullishRecognizer();
	};

	/// <summary>
	/// Derived class for recognizing doji patterns
	/// </summary>
	ref class dojiRecognizer : public Recognizer {
	public:
		virtual bool recognizePattern(List<smartCandlestick^>^ sublist) override;
		dojiRecognizer();
	};

	/// <summary>
	/// Derived class for recognizing dragonfly patterns
	/// </summary>
	ref class dragonflyRecognizer : public Recognizer {
	public:
		virtual bool recognizePattern(List<smartCandlestick^>^ sublist) override;
		dragonflyRecognizer();
	};

	/// <summary>
	/// Derived class for recognizing gravestone patterns
	/// </summary>
	ref class gravestoneRecognizer : public Recognizer {
	public:
		virtual bool recognizePattern(List<smartCandlestick^>^ sublist) override;
		gravestoneRecognizer();
	};

	/// <summary>
	/// Derived class for recognizing hammer patterns
	/// </summary>
	ref class hammerRecognizer : public Recognizer {
	public:
		virtual bool recognizePattern(List<smartCandlestick^>^ sublist) override;
		hammerRecognizer();
	};

	/// <summary>
	/// Derived class for recognizing marubozu patterns
	/// </summary>
	ref class marubozuRecognizer : public Recognizer {
	public:
		virtual bool recognizePattern(List<smartCandlestick^>^ sublist) override;
		marubozuRecognizer();
	};

	/// <summary>
	/// Derived class for recognizing neutral patterns
	/// </summary>
	ref class neutralRecognizer : public Recognizer {
	public:
		virtual bool recognizePattern(List<smartCandlestick^>^ sublist) override;
		neutralRecognizer();
	};

	/// <summary>
	/// Derived class for recognizing inverse hammer patterns
	/// </summary>
	ref class inverseHammerRecognizer : public Recognizer {
	public:
		virtual bool recognizePattern(List<smartCandlestick^>^ sublist) override;
		inverseHammerRecognizer();
	};

	/// <summary>
	/// Derived class for recognizing all engulfing patterns
	/// </summary>
	ref class engulfingPatternRecognizer : public Recognizer {
	public:
		virtual bool recognizePattern(List<smartCandlestick^>^ sublist) override;
		engulfingPatternRecognizer();
	};

	/// <summary>
	/// Derived class for recognizing bullish engulfing patterns
	/// </summary>
	ref class bullishEngulfingPatternRecognizer : public Recognizer {
	public:
		virtual bool recognizePattern(List<smartCandlestick^>^ sublist) override;
		bullishEngulfingPatternRecognizer();
	};

	/// <summary>
	/// Derived class for recognizing bearish engulfing patterns
	/// </summary>
	ref class bearishEngulfingPatternRecognizer : public Recognizer {
	public:
		virtual bool recognizePattern(List<smartCandlestick^>^ sublist) override;
		bearishEngulfingPatternRecognizer();
	};


	/// <summary>
	/// Derived class for recognizing all harami patterns
	/// </summary>
	ref class haramiPatternRecognizer : public Recognizer {
	public:
		virtual bool recognizePattern(List<smartCandlestick^>^ sublist) override;
		haramiPatternRecognizer();
	};

	/// <summary>
	/// Derived class for recognizing bullish harami patterns
	/// </summary>
	ref class bullishHaramiPatternRecognizer : public Recognizer {
	public:
		virtual bool recognizePattern(List<smartCandlestick^>^ sublist) override;
		bullishHaramiPatternRecognizer();
	};

	/// <summary>
	/// Derived class for recognizing bearish harami patterns
	/// </summary>
	ref class bearishHaramiPatternRecognizer : public Recognizer {
	public:
		virtual bool recognizePattern(List<smartCandlestick^>^ sublist) override;
		bearishHaramiPatternRecognizer();
	};

	/// <summary>
	/// Derived class for recognizing peak patterns
	/// </summary>
	ref class peakRecognizer : public Recognizer {
	public:
		virtual bool recognizePattern(List<smartCandlestick^>^ sublist) override;
		peakRecognizer();
	};

	/// <summary>
	/// Derived class for recognizing valley patterns
	/// </summary>
	ref class valleyRecognizer : public Recognizer {
	public:
		virtual bool recognizePattern(List<smartCandlestick^>^ sublist) override;
		valleyRecognizer();
	};
}

