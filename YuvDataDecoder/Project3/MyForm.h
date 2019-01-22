#pragma once
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<opencv2/opencv.hpp>
#include <vector>
#include <string>
#include "YuvOperations.h"
#include <msclr\marshal_cppstd.h>
using namespace std;
using namespace yops;

namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	boolean exitFlag;

	/// <summary>
	/// MyForm için özet
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Oluþturucu kodunu buraya ekle
			//
		}

	protected:
		/// <summary>
		///Kullanýlan tüm kaynaklarý temizleyin.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;


	protected:

	private:
		/// <summary>
		///Gerekli tasarýmcý deðiþkeni.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Tasarýmcý desteði için gerekli metot - bu metodun 
		///içeriðini kod düzenleyici ile deðiþtirmeyin.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(282, 161);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(183, 27);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Play";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(19, 40);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(235, 22);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(18, 85);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(235, 22);
			this->textBox2->TabIndex = 2;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"444", L"422", L"420" });
			this->comboBox1->Location = System::Drawing::Point(282, 38);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(234, 24);
			this->comboBox1->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(23, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 17);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Width";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(23, 65);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(49, 17);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Heigth";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(279, 20);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(52, 17);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Format";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(19, 162);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(183, 27);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Choose File";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(23, 125);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(63, 17);
			this->label4->TabIndex = 8;
			this->label4->Text = L"File Path";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(282, 65);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(49, 17);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Speed";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"0.5x", L"1.0x", L"1.5x" });
			this->comboBox2->Location = System::Drawing::Point(282, 83);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(232, 24);
			this->comboBox2->TabIndex = 10;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox2_SelectedIndexChanged);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"Cursor Files|*.yuv";
			this->openFileDialog1->Title = L"Select a YUV File";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(19, 195);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(183, 36);
			this->button3->TabIndex = 11;
			this->button3->Text = L"Exit";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(282, 194);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(88, 36);
			this->button4->TabIndex = 12;
			this->button4->Text = L"Pause";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(384, 194);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(81, 37);
			this->button5->TabIndex = 13;
			this->button5->Text = L"Resume";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(486, 161);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(122, 69);
			this->button6->TabIndex = 14;
			this->button6->Text = L"Save";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(637, 252);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		//system --> std
		msclr::interop::marshal_context context;
		std::string text1 = context.marshal_as<std::string>(this->textBox1->Text);
		const char *arrayText1 = text1.c_str();
		boolean flagText1 = true;

		msclr::interop::marshal_context context1;
		std::string text2 = context1.marshal_as<std::string>(this->textBox2->Text);
		const char *arrayText2 = text2.c_str();
		boolean flagText2 = true;

		for (int i = 0; i < this->textBox1->Text->Length; i++) {
			if (isdigit(*(arrayText1 + i))==0) {
				flagText1 = false;
			}
		}

		for (int i = 0; i < this->textBox2->Text->Length; i++) {
			if (isdigit(*(arrayText2 + i))==0) {
				flagText2 = false;
			}
		}

		if (flagText1 == false || flagText2 == false) MessageBox::Show("Wrong Input");
		else {

			msclr::interop::marshal_context context5;
			std::string filePath = context5.marshal_as<std::string>(this->label4->Text);
			int width = Convert::ToInt64(this->textBox1->Text);
			int heigth = Convert::ToInt64(this->textBox2->Text);
			int indexFormat = this->comboBox1->SelectedIndex;
			std::string format;
			if (indexFormat == 0) format = "444";
			if (indexFormat == 1) format = "422";
			if (indexFormat == 2) format = "420";
			int indexSpeed = this->comboBox2->SelectedIndex;
			int speed;
			if (indexSpeed == 0) speed = 30;
			if (indexSpeed == 1) speed = 20;
			if (indexSpeed == 2) speed = 10;
			YuvOps yo(filePath,"",format,width,heigth);
			YuvOps::exitFlag = true;
			YuvOps::pauseFlag = true;
			yo.saveStatus(true);
			yo.setSaveDirectory("C:\\Users\\tdenizgez\\Desktop\\Yazlab3\\"+format+"\\");
			yo.setDelay(speed);
			yo.start();
		}
	}
	
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (this->openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			msclr::interop::marshal_context context3;
			std::string filePath = context3.marshal_as<std::string>(this->openFileDialog1->FileName);
			String^ MyString = gcnew String(filePath.c_str());
			this->label4->Text = MyString;
		}	
	}

	private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		YuvOps::exitFlag = false;
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		YuvOps::pauseFlag = false;
		YuvOps::continueFlag = false;
	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		YuvOps::continueFlag = true;
	}
	private: System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}



private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {


	msclr::interop::marshal_context context5;
	std::string filePath = context5.marshal_as<std::string>(this->label4->Text);
	int width = Convert::ToInt64(this->textBox1->Text);
	int heigth = Convert::ToInt64(this->textBox2->Text);
	int indexFormat = this->comboBox1->SelectedIndex;
	std::string format;
	int frameLimit;
	if (indexFormat == 0) {
		format = "444";
		frameLimit = width * heigth;
	}
	if (indexFormat == 1) {
		format = "422";
		frameLimit = width * heigth / 2;
	}
	if (indexFormat == 2) {
		format = "420";
		frameLimit = width * heigth / 4;
	}

	FILE *f = fopen(filePath.c_str(), "rb");

	for (int frameCounter = 0; !feof(f); frameCounter++) {
		IplImage *py = cvCreateImage(cvSize(width, heigth), IPL_DEPTH_8U, 1);
		for (int i = 0; i < width*heigth; i++)
		{
			int temp = fgetc(f);
			py->imageData[i] = (unsigned char)temp;

		}
		for (int i = 0; i < frameLimit; i++)
		{
			int temp = fgetc(f);

		}
		for (int i = 0; i < frameLimit; i++)
		{
			int temp = fgetc(f);

		}
		string save = "C:\\Users\\tdenizgez\\Desktop\\Yazlab3\\" + format + "\\";
		stringstream str;

		str << frameCounter;

		const string image = save + "frame" + str.str() + ".bmp";

		cv::imwrite(image,cv::cvarrToMat(py));
		
	}




}
};

}
