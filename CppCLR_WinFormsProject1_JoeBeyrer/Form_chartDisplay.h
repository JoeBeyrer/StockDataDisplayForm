#pragma once

#include "aCandlestick.h"
#include "Recognizer.h"
#include "smartCandlestick.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace CppCLRWinFormsProject {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms::DataVisualization::Charting;
	using namespace System::Globalization;


	/// <summary>
	/// Form_chartDisplay includes the charts of a single selected stock (candlestick chart and volume chart) that can
	/// be modified using selected start and end dates as well as adding annotationa using pattern selection from a combo box.
	/// </summary>
	public ref class Form_chartDisplay : public System::Windows::Forms::Form
	{
	public:
		// Variable to hold filename
		String^ filename = gcnew String("");
		// Initialize variables for charts min and max Y valuse to zero
		double minY = 0;
	private:
		// Declare list to hold all candlesticks
		List<smartCandlestick^>^ candlesticks = gcnew List<smartCandlestick^>();
		// Declare list to hold all recognizers
		List<Recognizer^>^ recognizersList = gcnew List<Recognizer^>();
	private: System::Windows::Forms::ComboBox^ comboBox_patterns;
	private: System::Windows::Forms::Label^ label_pattern;
	public:

	public:
		double maxY = 0;
	public:
		Form_chartDisplay(String^ stockFilename, List<smartCandlestick^>^ sourceCandlesticks, DateTime start, DateTime end)
		{
			InitializeComponent();

			Text = stockFilename;
			filename = stockFilename;
			chart_StockData->Titles["Title1"]->Text = Path::GetFileNameWithoutExtension(stockFilename);
			dateTimePicker_start->Value = start;
			dateTimePicker_end->Value = end;
			candlesticks = sourceCandlesticks;
			filterDates(candlesticks);
			updateCharts();
			// Add recognizers for every possible pattern selection to a list - used for quick and convenient recognizer access
			recognizersList->Add(gcnew bearishRecognizer);
			recognizersList->Add(gcnew bullishRecognizer);
			recognizersList->Add(gcnew dojiRecognizer);
			recognizersList->Add(gcnew dragonflyRecognizer);
			recognizersList->Add(gcnew gravestoneRecognizer);
			recognizersList->Add(gcnew hammerRecognizer);
			recognizersList->Add(gcnew marubozuRecognizer);
			recognizersList->Add(gcnew neutralRecognizer);
			recognizersList->Add(gcnew inverseHammerRecognizer);
			recognizersList->Add(gcnew engulfingPatternRecognizer);
			recognizersList->Add(gcnew bullishEngulfingPatternRecognizer);
			recognizersList->Add(gcnew bearishEngulfingPatternRecognizer);
			recognizersList->Add(gcnew haramiPatternRecognizer);
			recognizersList->Add(gcnew bullishHaramiPatternRecognizer);
			recognizersList->Add(gcnew bearishHaramiPatternRecognizer);
			recognizersList->Add(gcnew peakRecognizer);
			recognizersList->Add(gcnew valleyRecognizer);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form_chartDisplay()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_update;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_start;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_end;
	private: System::Windows::Forms::Label^ label_start;
	private: System::Windows::Forms::Label^ label_end;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart_StockData;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^ title1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			this->button_update = (gcnew System::Windows::Forms::Button());
			this->dateTimePicker_start = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker_end = (gcnew System::Windows::Forms::DateTimePicker());
			this->label_start = (gcnew System::Windows::Forms::Label());
			this->label_end = (gcnew System::Windows::Forms::Label());
			this->chart_StockData = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->comboBox_patterns = (gcnew System::Windows::Forms::ComboBox());
			this->label_pattern = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_StockData))->BeginInit();
			this->SuspendLayout();
			// 
			// button_update
			// 
			this->button_update->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_update->Location = System::Drawing::Point(1680, 1096);
			this->button_update->Margin = System::Windows::Forms::Padding(6);
			this->button_update->Name = L"button_update";
			this->button_update->Size = System::Drawing::Size(568, 115);
			this->button_update->TabIndex = 0;
			this->button_update->Text = L"Update Stock Data";
			this->button_update->UseVisualStyleBackColor = true;
			this->button_update->Click += gcnew System::EventHandler(this, &Form_chartDisplay::button_update_Click);
			// 
			// dateTimePicker_start
			// 
			this->dateTimePicker_start->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->dateTimePicker_start->Location = System::Drawing::Point(594, 1098);
			this->dateTimePicker_start->Margin = System::Windows::Forms::Padding(6);
			this->dateTimePicker_start->Name = L"dateTimePicker_start";
			this->dateTimePicker_start->Size = System::Drawing::Size(396, 31);
			this->dateTimePicker_start->TabIndex = 1;
			this->dateTimePicker_start->Value = System::DateTime(2021, 1, 1, 0, 0, 0, 0);
			// 
			// dateTimePicker_end
			// 
			this->dateTimePicker_end->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->dateTimePicker_end->Location = System::Drawing::Point(594, 1190);
			this->dateTimePicker_end->Margin = System::Windows::Forms::Padding(6);
			this->dateTimePicker_end->Name = L"dateTimePicker_end";
			this->dateTimePicker_end->Size = System::Drawing::Size(396, 31);
			this->dateTimePicker_end->TabIndex = 2;
			// 
			// label_start
			// 
			this->label_start->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label_start->AutoSize = true;
			this->label_start->Location = System::Drawing::Point(588, 1067);
			this->label_start->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label_start->Name = L"label_start";
			this->label_start->Size = System::Drawing::Size(114, 25);
			this->label_start->TabIndex = 3;
			this->label_start->Text = L"Start Date:";
			// 
			// label_end
			// 
			this->label_end->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label_end->AutoSize = true;
			this->label_end->Location = System::Drawing::Point(588, 1160);
			this->label_end->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label_end->Name = L"label_end";
			this->label_end->Size = System::Drawing::Size(107, 25);
			this->label_end->TabIndex = 4;
			this->label_end->Text = L"End Date:";
			// 
			// chart_StockData
			// 
			this->chart_StockData->Anchor = System::Windows::Forms::AnchorStyles::None;
			chartArea1->Name = L"stock_tickers";
			chartArea2->Name = L"stock_volumes";
			this->chart_StockData->ChartAreas->Add(chartArea1);
			this->chart_StockData->ChartAreas->Add(chartArea2);
			legend1->Name = L"Legend1";
			this->chart_StockData->Legends->Add(legend1);
			this->chart_StockData->Location = System::Drawing::Point(24, 23);
			this->chart_StockData->Margin = System::Windows::Forms::Padding(6);
			this->chart_StockData->Name = L"chart_StockData";
			series1->ChartArea = L"stock_tickers";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Candlestick;
			series1->CustomProperties = L"PriceDownColor=LightCoral, PriceUpColor=PaleGreen";
			series1->Legend = L"Legend1";
			series1->MarkerBorderWidth = 3;
			series1->Name = L"stock_ohlc";
			series1->XValueMember = L"Date";
			series1->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Date;
			series1->YValueMembers = L"High,Low,Open,Close";
			series1->YValuesPerPoint = 4;
			series1->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Int32;
			series2->ChartArea = L"stock_volumes";
			series2->Legend = L"Legend1";
			series2->Name = L"stock_volumes";
			series2->XValueMember = L"Date";
			series2->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Date;
			series2->YValueMembers = L"Volume";
			series2->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Int64;
			this->chart_StockData->Series->Add(series1);
			this->chart_StockData->Series->Add(series2);
			this->chart_StockData->Size = System::Drawing::Size(2832, 988);
			this->chart_StockData->TabIndex = 9;
			this->chart_StockData->Text = L"chart_candlestick";
			title1->Name = L"Title1";
			title1->Text = L"Stock Data";
			this->chart_StockData->Titles->Add(title1);
			// 
			// comboBox_patterns
			// 
			this->comboBox_patterns->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->comboBox_patterns->FormattingEnabled = true;
			this->comboBox_patterns->Items->AddRange(gcnew cli::array< System::Object^  >(18) {
				L"Bearish", L"Bullish", L"Doji", L"Dragonfly Doji",
					L"Gravestone Doji", L"Hammer", L"Marubozu", L"Neutral", L"Inverse Hammer", L"Engulfing", L"Bullish Engulfing", L"Bearish Engulfing",
					L"Harami", L"Bullish Harami", L"Bearish Harami", L"Peak", L"Valley", L"None"
			});
			this->comboBox_patterns->Location = System::Drawing::Point(1220, 1096);
			this->comboBox_patterns->Margin = System::Windows::Forms::Padding(6);
			this->comboBox_patterns->Name = L"comboBox_patterns";
			this->comboBox_patterns->Size = System::Drawing::Size(238, 33);
			this->comboBox_patterns->TabIndex = 10;
			this->comboBox_patterns->Text = L"None";
			// 
			// label_pattern
			// 
			this->label_pattern->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label_pattern->AutoSize = true;
			this->label_pattern->Location = System::Drawing::Point(1214, 1065);
			this->label_pattern->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label_pattern->Name = L"label_pattern";
			this->label_pattern->Size = System::Drawing::Size(185, 25);
			this->label_pattern->TabIndex = 11;
			this->label_pattern->Text = L"Choose a Pattern:";
			// 
			// Form_chartDisplay
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2866, 1490);
			this->Controls->Add(this->label_pattern);
			this->Controls->Add(this->comboBox_patterns);
			this->Controls->Add(this->chart_StockData);
			this->Controls->Add(this->label_end);
			this->Controls->Add(this->label_start);
			this->Controls->Add(this->dateTimePicker_end);
			this->Controls->Add(this->dateTimePicker_start);
			this->Controls->Add(this->button_update);
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"Form_chartDisplay";
			this->Text = L"Form_chartDisplay";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_StockData))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		/// <summary>
		/// Upon clicking the update button,, the charts will be updated using the selected date range
		/// and annotations will be added using the selected pattern type from the combo box
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		/// <returns></returns>
	private: System::Void button_update_Click(System::Object^ sender, System::EventArgs^ e) {
		// Call the "updateCharts" function to update the charts using the current state of the form elements
		updateCharts();
	}

		   /// <summary>
		   /// This function will take in a list of candlesticks and return a list of filtered candlesticks that fall between 
		   /// the user selected start and end dates. 
		   /// </summary>
		   /// <param name="listCandlesticks"></param>
		   /// <returns></returns>
	private: List<smartCandlestick^>^ filterDates(List<smartCandlestick^>^ listCandlesticks) {
		// Get the start and end dates from the date-time pickers
		DateTime start = dateTimePicker_start->Value;
		DateTime end = dateTimePicker_end->Value;

		// Create a new list containing only items within the date range
		List<smartCandlestick^>^ filteredCandlesticks = gcnew List<smartCandlestick^>();
		for each (smartCandlestick ^ candlestick in listCandlesticks) {
			if (candlestick->date >= start && candlestick->date <= end) {
				// Add candlestick to filteredCandlesticks list if it falls within the date range
				filteredCandlesticks->Add(candlestick);
				// Update min and max Y values based on the low and high values of the candlesticks added to the list
				minY = Math::Min(minY, candlestick->low);
				maxY = Math::Max(maxY, candlestick->high);
			}
		}
		return filteredCandlesticks; // Return the binding list of filtered candlesticks
	}

		   /// <summary>
		   /// This function is used to update all chart data by filtering the list of candlesticks and binding
		   /// the filtered list to the chart. Finally, the pattern annotations will be added to the chart based on
		   /// the selected annotation.
		   /// </summary>
	private: void updateCharts() {
		List<int>^ annotationIndeces = gcnew List<int>();
		// List declared to hold filtered candlesticks
		List<smartCandlestick^>^ filteredCandlesticks = gcnew List<smartCandlestick^>();
		// filter the candlesticks by the selected dates
		filteredCandlesticks = filterDates(candlesticks);
		// Get the list of candlestick indeces that need annotations using the list of candlesticks that was already filtered by date
		annotationIndeces = getAnnotationIndeces(filteredCandlesticks, comboBox_patterns->Text, comboBox_patterns->SelectedIndex);

		// Create a binding source for the filtered data to be added to the charts
		BindingList<smartCandlestick^>^ bindingCandlesticks = gcnew BindingList<smartCandlestick^>(filteredCandlesticks); // Cast filteredCandlesticks to type BindingList
		BindingSource^ bindingSource = gcnew BindingSource(bindingCandlesticks, "");

		// Clear any existing data in the chart to update with new data
		chart_StockData->Series->Clear();
		// Add the candlestick series to the stock_tickers chart area
		Series^ candlestickSeries = gcnew Series("Candlesticks"); // Create a new series for candlestick data on the chart
		candlestickSeries->ChartArea = "stock_tickers"; // Chart area where the candlestick series will be graphed
		candlestickSeries->ChartType = SeriesChartType::Candlestick; // Set the chart type to candlestick to graph open, close, high, and low values
		candlestickSeries->XValueMember = "Date"; // X-values correspond to dates
		candlestickSeries->YValueMembers = "Low,High,Open,Close"; // Y-values correspond to low, high, open, and close
		candlestickSeries->CustomProperties = "PriceDownColor=Red,PriceUpColor=Green"; // Change colors for prices going up and down
		chart_StockData->Series->Add(candlestickSeries); // Add this series to chart's series

		// Set the Y-axis range as a percentage of the low and high values (10% lower than lowest low and higher than highest high)
		chart_StockData->ChartAreas["stock_tickers"]->AxisY->Minimum = minY * 0.9;
		chart_StockData->ChartAreas["stock_tickers"]->AxisY->Maximum = maxY * 1.1;

		// Add the volume series to the 'stock_volumes' chart area
		Series^ volumeSeries = gcnew Series("Volume"); // Create a new series for volume data on the chart
		volumeSeries->ChartArea = "stock_volumes"; // Chart area where the volume series will be graphed
		volumeSeries->ChartType = SeriesChartType::Column; // Set the chart trype to bar graph for graphing volumes
		volumeSeries->XValueMember = "Date"; // X-values correspond to dates
		volumeSeries->XValueType = ChartValueType::DateTime; // Convert the X-values to DateTime format
		volumeSeries->YValueMembers = "Volume"; // Y-values correspond to volume
		chart_StockData->Series->Add(volumeSeries); // Add this series to chart's series

		// Bind the data to the chart
		chart_StockData->DataSource = bindingSource;
		chart_StockData->DataBind();

		// Add the annotations to the chart based on the list of indeces and filtered candlesticks
		addAnnotations(annotationIndeces, bindingCandlesticks);
	}

		   /// <summary>
		   /// Iterate through all candlesticks and check if they satisfy the conditions for the selected annotation.
		   /// If the conditions are satisfied, add the index of the candlestick to the list of indeces that will
		   /// be returned.
		   /// </summary>
		   /// <param name="listCandlesticks"></param>
		   /// <param name="selectedPattern"></param>
		   /// <returns></returns>
	private: List<int>^ getAnnotationIndeces(List<smartCandlestick^>^ listCandlesticks, String^ selectedPattern, int selectedIndex) {
		List<int>^ indexList = gcnew List<int>();
		// If the selected pattern is "None", we may skip this process adding no indeces to the list (remove all annotations)
		if (selectedPattern != "None") {
			// Choose a recognizer class that corresponds to the selected pattern name - recognize all of the selected pattern and add indeces to indexList
			indexList = recognizersList[selectedIndex]->recognize(listCandlesticks);
		}
		return indexList; // Return the index list
	}

		   /// <summary>
		   /// This function is used to add the selected annotations to the candlestick charts using the list of candlesticks
		   /// and the indeces of candlesticks that requires annotations.
		   /// </summary>
		   /// <param name="indices"></param>
		   /// <param name="filteredCandlesticks"></param>
	private: void addAnnotations(List<int>^ indices, BindingList<smartCandlestick^>^ filteredCandlesticks) {
		// Clear any previous annotations to avoid overlapping annotations and show only selected annotations
		chart_StockData->Annotations->Clear();

		// Iterate through all of the indeces that require annotations
		for (int i = 0; i < indices->Count; i++) {
			// Get the current index for annotation
			int index = indices[i];

			// Select the candlestick from the binding list of candlesticks for annotation
			smartCandlestick^ candlestick = filteredCandlesticks[index];

			// Create a new annotation of type Arrow Annotation
			DataVisualization::Charting::ArrowAnnotation^ annotation = gcnew DataVisualization::Charting::ArrowAnnotation();

			// Clip the annotation to the candlestick chart areas x and y axis
			annotation->ClipToChartArea = "stock_tickers";
			annotation->AxisX = chart_StockData->ChartAreas["stock_tickers"]->AxisX;
			annotation->AxisY = chart_StockData->ChartAreas["stock_tickers"]->AxisY;

			// Get the datapoint of the candlestick at the current index to set the annotation anchor
			DataVisualization::Charting::DataPoint^ point = chart_StockData->Series["Candlesticks"]->Points[index];
			annotation->AnchorDataPoint = point;
			// Set the color of the annotation to black
			annotation->ForeColor = Color::Black;
			annotation->LineColor = Color::Black;

			// Set the width to 0 (for vertical candlestick)
			annotation->Width = 0;
			annotation->Height = 6;
			annotation->LineWidth = 1;
			annotation->AxisX->IsStartedFromZero = false;
			annotation->AnchorOffsetY = 0;
			// Y value of annotation set to be at the bottom of the candlestick
			annotation->Y = point->YValues[0] - (candlestick->range / 2);

			// Add the annotation to the stock data chart
			chart_StockData->Annotations->Add(annotation);
		}
	}
	};
}