#pragma once

#include "aCandlestick.h"
#include "smartCandlestick.h"
#include "Form_chartDisplay.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

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
	/// Form1 is the main form of the application that is used to load stock files into data charts on new forms
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		// Reference string used for verifying file format
		String^ refString = "\"Ticker\",\"Period\",\"Date\",\"Open\",\"High\",\"Low\",\"Close\",\"Volume\"";
	public:

	public:
		DateTime MIN_DATE = DateTime::Parse("Jan 1, 1800");
		// Form1 constructor to initialize form components
		Form1(void)
		{
			InitializeComponent();
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
	private: System::Windows::Forms::Label^ label_startDate;
	private: System::Windows::Forms::Label^ label_endDate;

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
			this->button_loadTicker = (gcnew System::Windows::Forms::Button());
			this->openFileDialog_loadStock = (gcnew System::Windows::Forms::OpenFileDialog());
			this->dateTimePicker_start = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker_end = (gcnew System::Windows::Forms::DateTimePicker());
			this->label_startDate = (gcnew System::Windows::Forms::Label());
			this->label_endDate = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button_loadTicker
			// 
			this->button_loadTicker->Location = System::Drawing::Point(612, 54);
			this->button_loadTicker->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->button_loadTicker->Name = L"button_loadTicker";
			this->button_loadTicker->Size = System::Drawing::Size(404, 87);
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
			this->openFileDialog_loadStock->Multiselect = true;
			// 
			// dateTimePicker_start
			// 
			this->dateTimePicker_start->Location = System::Drawing::Point(118, 85);
			this->dateTimePicker_start->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->dateTimePicker_start->MinDate = System::DateTime(1800, 1, 1, 0, 0, 0, 0);
			this->dateTimePicker_start->Name = L"dateTimePicker_start";
			this->dateTimePicker_start->Size = System::Drawing::Size(396, 31);
			this->dateTimePicker_start->TabIndex = 2;
			this->dateTimePicker_start->Value = System::DateTime(2021, 1, 1, 0, 0, 0, 0);
			// 
			// dateTimePicker_end
			// 
			this->dateTimePicker_end->Location = System::Drawing::Point(1100, 85);
			this->dateTimePicker_end->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->dateTimePicker_end->MinDate = System::DateTime(1800, 1, 1, 0, 0, 0, 0);
			this->dateTimePicker_end->Name = L"dateTimePicker_end";
			this->dateTimePicker_end->Size = System::Drawing::Size(396, 31);
			this->dateTimePicker_end->TabIndex = 3;
			// 
			// label_startDate
			// 
			this->label_startDate->AutoSize = true;
			this->label_startDate->Location = System::Drawing::Point(112, 54);
			this->label_startDate->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label_startDate->Name = L"label_startDate";
			this->label_startDate->Size = System::Drawing::Size(108, 25);
			this->label_startDate->TabIndex = 4;
			this->label_startDate->Text = L"Start Date";
			// 
			// label_endDate
			// 
			this->label_endDate->AutoSize = true;
			this->label_endDate->Location = System::Drawing::Point(1094, 54);
			this->label_endDate->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label_endDate->Name = L"label_endDate";
			this->label_endDate->Size = System::Drawing::Size(101, 25);
			this->label_endDate->TabIndex = 6;
			this->label_endDate->Text = L"End Date";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1612, 181);
			this->Controls->Add(this->label_endDate);
			this->Controls->Add(this->label_startDate);
			this->Controls->Add(this->dateTimePicker_end);
			this->Controls->Add(this->dateTimePicker_start);
			this->Controls->Add(this->button_loadTicker);
			this->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->Name = L"Form1";
			this->Text = L"+";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	/// <summary>
	/// This event occurs when the load ticker button is clicked.
	/// The open file dialog will open for the user to select files and a new form
	/// will be created for each seleced file containing the stock data charts.
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns></returns>
	private: System::Void button_loadTicker_Click(System::Object^ sender, System::EventArgs^ e) {
		// Open the file dialog to select a file
		System::Windows::Forms::DialogResult result = openFileDialog_loadStock->ShowDialog();
		// If the file dialog result is OK then load the data
		if (result == System::Windows::Forms::DialogResult::OK) {
			List<List<smartCandlestick^>^>^ listOfListOfCandlesticks = gcnew List<List<smartCandlestick^>^>();
			listOfListOfCandlesticks = loadStocks(openFileDialog_loadStock->FileNames); // Call the loadStocks function on the list of selected files

			for (int i = 0; i < openFileDialog_loadStock->FileNames->Length; i++) {
				// For every file name in the list of selected filenames, create a new Form_displayChart form using the selected dates, filename, and list of candlesticks
				Form_chartDisplay^ displayForm = gcnew Form_chartDisplay(openFileDialog_loadStock->FileNames[i], listOfListOfCandlesticks[i], dateTimePicker_start->Value, dateTimePicker_end->Value);
				displayForm->Show(); // Show the Form_displayChart form
			}

		}
	}

	/// <summary>
	/// Function that takes in a filename and reads it using stream reader to create a candlestick for each line in the file
	/// to add it to a list of candlesticks that will be returned.
	/// </summary>
	/// <param name="filename"></param>
	/// <param name="index"></param>
	/// <returns></returns>
	private: List<smartCandlestick^>^ loadFile(String^ filename, int index) {
		// Store the name of the path as a string for future reference
		String^ path = openFileDialog_loadStock->FileNames[index]; 

		// Declare a binding list to store all of the candlesticks
		List<smartCandlestick^>^ candlesticks = gcnew List<smartCandlestick^>();

		try {
			// Declare a file stream and stream reader to enable reading from the file selected by the user
			FileStream^ stream = gcnew FileStream(path, FileMode::Open);
			StreamReader^ reader = gcnew StreamReader(stream);

			// Read the first line of the selected file to determine if the format is correct
			String^ firstLine = reader->ReadLine();
			if (firstLine == refString) { // refString declared at the top, this is the format all selected files should be in
				// Given the correct file format, read each line of the selected file, creating candlesticks from each one
				while (!reader->EndOfStream) {
					candlesticks->Add(gcnew smartCandlestick(reader->ReadLine())); // Add smart candlestick to the list of candlesticks
				}

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

		return candlesticks; // Return the list of candlesticks

	}

	/// <summary>
	/// Function for loading the stocks using a list of file names. Returns a list of lists of candlesticks for
	/// initisalizing the stock chart forms
	/// </summary>
	/// <param name="listOfFilenames"></param>
	/// <returns></returns>
	private: List<List<smartCandlestick^>^>^ loadStocks(array<String^>^ listOfFilenames) {
		List<List<smartCandlestick^>^>^ listOfListOfCandlesticks = gcnew List<List<smartCandlestick^>^>();
		// Iterate through all of the selected file names
		for (int i = 0; i < listOfFilenames->Length; i++) {
			// Iterate through every file name in the list of file names
			List<smartCandlestick^>^ listOfCandlesticks = loadFile(listOfFilenames[i], i); // Call loadFile to get the list of candlesticks from each CSV file
			listOfListOfCandlesticks->Add(listOfCandlesticks); // Add the list of candlesticks to the list of list of candlesticks
		}
		return listOfListOfCandlesticks; // Return the list of list of candlesticks
	}

};
}
