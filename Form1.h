#pragma once

#include "aCandlestick.h"
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
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		// Reference string used for verifying file format
		String^ refString = "\"Ticker\",\"Period\",\"Date\",\"Open\",\"High\",\"Low\",\"Close\",\"Volume\"";
		// Declare candlesticks binding list as a public variable
		BindingList<aCandlestick^>^ candlesticks = gcnew BindingList<aCandlestick^>();
		// Declare updateCandlesticks binding list as a public variable
		BindingList<aCandlestick^>^ updateCandlesticks = gcnew BindingList<aCandlestick^>();
	private: System::Windows::Forms::Button^ button_update;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart_StockData;
	public:

	public:
		DateTime MIN_DATE = DateTime::Parse("Jan 1, 1800");
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_loadTicker;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog_loadStock;

	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_start;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_end;
	protected:





	private: System::Windows::Forms::Label^ label_startDate;

	private: System::Windows::Forms::Label^ label_endDate;
	private: System::Windows::Forms::DataGridView^ dataGridView_StockData;



	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^ title2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			this->button_loadTicker = (gcnew System::Windows::Forms::Button());
			this->openFileDialog_loadStock = (gcnew System::Windows::Forms::OpenFileDialog());
			this->chart_StockData = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->dateTimePicker_start = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker_end = (gcnew System::Windows::Forms::DateTimePicker());
			this->label_startDate = (gcnew System::Windows::Forms::Label());
			this->label_endDate = (gcnew System::Windows::Forms::Label());
			this->dataGridView_StockData = (gcnew System::Windows::Forms::DataGridView());
			this->button_update = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_StockData))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_StockData))->BeginInit();
			this->SuspendLayout();
			// 
			// button_loadTicker
			// 
			this->button_loadTicker->Location = System::Drawing::Point(1033, 50);
			this->button_loadTicker->Name = L"button_loadTicker";
			this->button_loadTicker->Size = System::Drawing::Size(200, 70);
			this->button_loadTicker->TabIndex = 0;
			this->button_loadTicker->Text = L"Load Stock Data";
			this->button_loadTicker->UseVisualStyleBackColor = true;
			this->button_loadTicker->Click += gcnew System::EventHandler(this, &Form1::button_loadTicker_Click);
			// 
			// openFileDialog_loadStock
			// 
			this->openFileDialog_loadStock->Filter = L"All Stock Files (*.csv)|*.csv|Daily Stocks|*-Day.csv|Weekly Stocks|*-Week.csv|Mon"
				L"thly Stocks|*-Month.csv";
			this->openFileDialog_loadStock->InitialDirectory = L"C:\\Users\\joebe\\source\\repos\\CppCLR_WinFormsProject1_JoeBeyrer\\CppCLR_WinFormsProj"
				L"ect1_JoeBeyrer\\x64\\Debug\\Stock Data";
			// 
			// chart_StockData
			// 
			this->chart_StockData->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			chartArea3->Name = L"stock_tickers";
			chartArea4->Name = L"stock_volumes";
			this->chart_StockData->ChartAreas->Add(chartArea3);
			this->chart_StockData->ChartAreas->Add(chartArea4);
			legend2->Name = L"Legend1";
			this->chart_StockData->Legends->Add(legend2);
			this->chart_StockData->Location = System::Drawing::Point(36, 214);
			this->chart_StockData->Name = L"chart_StockData";
			series3->ChartArea = L"stock_tickers";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Candlestick;
			series3->CustomProperties = L"PriceDownColor=LightCoral, PriceUpColor=PaleGreen";
			series3->Legend = L"Legend1";
			series3->MarkerBorderWidth = 3;
			series3->Name = L"stock_ohlc";
			series3->XValueMember = L"Date";
			series3->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Date;
			series3->YValueMembers = L"High,Low,Open,Close";
			series3->YValuesPerPoint = 4;
			series3->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Int32;
			series4->ChartArea = L"stock_volumes";
			series4->Legend = L"Legend1";
			series4->Name = L"stock_volumes";
			series4->XValueMember = L"Date";
			series4->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Date;
			series4->YValueMembers = L"Volume";
			series4->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Int64;
			this->chart_StockData->Series->Add(series3);
			this->chart_StockData->Series->Add(series4);
			this->chart_StockData->Size = System::Drawing::Size(1380, 544);
			this->chart_StockData->TabIndex = 8;
			this->chart_StockData->Text = L"chart_candlestick";
			title2->Name = L"Title1";
			title2->Text = L"Stock Data";
			this->chart_StockData->Titles->Add(title2);
			// 
			// dateTimePicker_start
			// 
			this->dateTimePicker_start->Location = System::Drawing::Point(801, 50);
			this->dateTimePicker_start->MinDate = System::DateTime(1800, 1, 1, 0, 0, 0, 0);
			this->dateTimePicker_start->Name = L"dateTimePicker_start";
			this->dateTimePicker_start->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker_start->TabIndex = 2;
			this->dateTimePicker_start->Value = System::DateTime(1990, 1, 1, 0, 0, 0, 0);
			// 
			// dateTimePicker_end
			// 
			this->dateTimePicker_end->Location = System::Drawing::Point(801, 100);
			this->dateTimePicker_end->MinDate = System::DateTime(1800, 1, 1, 0, 0, 0, 0);
			this->dateTimePicker_end->Name = L"dateTimePicker_end";
			this->dateTimePicker_end->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker_end->TabIndex = 3;
			// 
			// label_startDate
			// 
			this->label_startDate->AutoSize = true;
			this->label_startDate->Location = System::Drawing::Point(798, 34);
			this->label_startDate->Name = L"label_startDate";
			this->label_startDate->Size = System::Drawing::Size(55, 13);
			this->label_startDate->TabIndex = 4;
			this->label_startDate->Text = L"Start Date";
			// 
			// label_endDate
			// 
			this->label_endDate->AutoSize = true;
			this->label_endDate->Location = System::Drawing::Point(798, 84);
			this->label_endDate->Name = L"label_endDate";
			this->label_endDate->Size = System::Drawing::Size(52, 13);
			this->label_endDate->TabIndex = 6;
			this->label_endDate->Text = L"End Date";
			// 
			// dataGridView_StockData
			// 
			this->dataGridView_StockData->Location = System::Drawing::Point(36, 12);
			this->dataGridView_StockData->Name = L"dataGridView_StockData";
			this->dataGridView_StockData->Size = System::Drawing::Size(728, 165);
			this->dataGridView_StockData->TabIndex = 7;
			// 
			// button_update
			// 
			this->button_update->Location = System::Drawing::Point(1265, 50);
			this->button_update->Name = L"button_update";
			this->button_update->Size = System::Drawing::Size(200, 70);
			this->button_update->TabIndex = 9;
			this->button_update->Text = L"Update Stock Data";
			this->button_update->UseVisualStyleBackColor = true;
			this->button_update->Visible = false;
			this->button_update->Click += gcnew System::EventHandler(this, &Form1::button_update_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1607, 884);
			this->Controls->Add(this->button_update);
			this->Controls->Add(this->dataGridView_StockData);
			this->Controls->Add(this->label_endDate);
			this->Controls->Add(this->label_startDate);
			this->Controls->Add(this->dateTimePicker_end);
			this->Controls->Add(this->dateTimePicker_start);
			this->Controls->Add(this->chart_StockData);
			this->Controls->Add(this->button_loadTicker);
			this->Name = L"Form1";
			this->Text = L"Stock Data";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_StockData))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_StockData))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_loadTicker_Click(System::Object^ sender, System::EventArgs^ e) {
		// Open the file dialog to select a file
		System::Windows::Forms::DialogResult result = openFileDialog_loadStock->ShowDialog();

		// If the file dialog result is OK then load the data
		if (result == System::Windows::Forms::DialogResult::OK) {
			// Save the filepath of the selected file
			String^ path = openFileDialog_loadStock->FileName;

			// Set the chart name to the ticker and type of loaded stock
			chart_StockData->Titles["Title1"]->Text = Path::GetFileNameWithoutExtension(path);

			try {
				// Declare a binding list to store all of the candlesticks
				BindingList<aCandlestick^>^ candlesticks = gcnew BindingList<aCandlestick^>();

				// Declare a file stream and stream reader to enable reading from the file selected by the user
				FileStream^ stream = gcnew FileStream(path, FileMode::Open);
				StreamReader^ reader = gcnew StreamReader(stream);

				// Read the first line of the selected file to determine if the format is correct
				String^ firstLine = reader->ReadLine();
				if (firstLine == refString) { // refString declared at the top, this is the format all selected files should be in
					// Given the correct file format, read each line of the selected file, creating candlesticks from each one
					while (!reader->EndOfStream) {
						candlesticks->Add(gcnew aCandlestick(reader->ReadLine()));
					}
					// Update the candlesticks list for future reference
					updateCandlesticks = candlesticks;

					// Trigger the update button click to apply initial filtering - this will be the initial chart update when a new file is selected
					button_update_Click(sender, e);
					// Make the update button visible
					button_update->Visible = true;
					// Close the stream reader - done reading from the file
					reader->Close();
				}
				else { // Triggers if the file format is incorrect
					Console::WriteLine("Error: The selected file is not in the correct format.");
				}
			}
			catch (IOException^ e) { // Catches error in the event that an error occured during file I/O
				Console::WriteLine("Error: An I/O error occurred while reading the file. " + e->Message);
			}
		}
	}

	private: System::Void button_update_Click(System::Object^ sender, System::EventArgs^ e) {
		// Get the start and end dates from the date-time pickers
		DateTime start = dateTimePicker_start->Value;
		DateTime end = dateTimePicker_end->Value;
		// Initialize variables for charts min and max Y valuse to zero
		double minY = 0;
		double maxY = 0;

		// Create a new list containing only items within the date range
		BindingList<aCandlestick^>^ filteredCandlesticks = gcnew BindingList<aCandlestick^>();
		for each (aCandlestick ^ candlestick in updateCandlesticks) {
			if (candlestick->date >= start && candlestick->date <= end) { 
				// Add candlestick to filteredCandlesticks list if it falls within the date range
				filteredCandlesticks->Add(candlestick);
				// Update min and max Y values based on the low and high values of the candlesticks added to the list
				minY = Math::Min(minY, candlestick->low);
				maxY = Math::Max(maxY, candlestick->high);
			}
		}

		
		// Create a binding source for the filtered data to be added to the charts
		BindingSource^ bindingSource = gcnew BindingSource(filteredCandlesticks, "");

		// Set the data source for the data grid view to display the stock data from the filteredCandlesticks list
		dataGridView_StockData->DataSource = bindingSource;

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
	}
};
}
