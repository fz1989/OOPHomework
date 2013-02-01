#include "./include/ElevatorSimulateSystem.h"
#pragma once

namespace OOPGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;
	/// <summary>
	/// Form1 摘要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  KInput;
	private: System::Windows::Forms::TextBox^  KTextBox;

	protected: 

	private: System::Windows::Forms::Label^  NInput;
	private: System::Windows::Forms::TextBox^  NTextBox;

	private: System::Windows::Forms::Label^  MInput;
	private: System::Windows::Forms::TextBox^  MTextBox;

	private: System::Windows::Forms::Label^  SInput;
	private: System::Windows::Forms::TextBox^  STextBox;

	private: System::Windows::Forms::Label^  TInput;
	private: System::Windows::Forms::TextBox^  TTextBox;

	private: System::Windows::Forms::Label^  TimeOut;
	private: System::Windows::Forms::TextBox^  TimeTextBox;

	private: System::Windows::Forms::Button^  Start;
	private: System::Windows::Forms::Label^  ElevatorChoose;
	private: System::Windows::Forms::ComboBox^  ElevatorComboBox;


	private: System::Windows::Forms::Label^  FloorChoose;
	private: System::Windows::Forms::ComboBox^  FloorComboBox;

	private: System::Windows::Forms::Label^  PeopleChoose;
	private: System::Windows::Forms::ComboBox^  PeopleComboBox;
	private: System::Windows::Forms::RichTextBox^  ElevatorRichTextBox;
	private: System::Windows::Forms::RichTextBox^  FloorRichTextBox;
	private: System::Windows::Forms::RichTextBox^  PeopleRichTextBox;

	private:ElevatorSimulateSystem* pSys;
	private:int N,M,K,S,T, totTime;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;
			 /// <summary>
		/// 必需的设计器变量。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->KInput = (gcnew System::Windows::Forms::Label());
			this->KTextBox = (gcnew System::Windows::Forms::TextBox());
			this->NInput = (gcnew System::Windows::Forms::Label());
			this->NTextBox = (gcnew System::Windows::Forms::TextBox());
			this->MInput = (gcnew System::Windows::Forms::Label());
			this->MTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SInput = (gcnew System::Windows::Forms::Label());
			this->STextBox = (gcnew System::Windows::Forms::TextBox());
			this->TInput = (gcnew System::Windows::Forms::Label());
			this->TTextBox = (gcnew System::Windows::Forms::TextBox());
			this->TimeOut = (gcnew System::Windows::Forms::Label());
			this->TimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->Start = (gcnew System::Windows::Forms::Button());
			this->ElevatorChoose = (gcnew System::Windows::Forms::Label());
			this->ElevatorComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->FloorChoose = (gcnew System::Windows::Forms::Label());
			this->FloorComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->PeopleChoose = (gcnew System::Windows::Forms::Label());
			this->PeopleComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->ElevatorRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->FloorRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->PeopleRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// KInput
			// 
			this->KInput->AutoSize = true;
			this->KInput->Location = System::Drawing::Point(12, 34);
			this->KInput->Name = L"KInput";
			this->KInput->Size = System::Drawing::Size(11, 12);
			this->KInput->TabIndex = 0;
			this->KInput->Text = L"K";
			// 
			// KTextBox
			// 
			this->KTextBox->Location = System::Drawing::Point(59, 25);
			this->KTextBox->Name = L"KTextBox";
			this->KTextBox->Size = System::Drawing::Size(100, 21);
			this->KTextBox->TabIndex = 1;
			this->KTextBox->Text = L"10";
			// 
			// NInput
			// 
			this->NInput->AutoSize = true;
			this->NInput->Location = System::Drawing::Point(166, 33);
			this->NInput->Name = L"NInput";
			this->NInput->Size = System::Drawing::Size(11, 12);
			this->NInput->TabIndex = 2;
			this->NInput->Text = L"N";
			// 
			// NTextBox
			// 
			this->NTextBox->Location = System::Drawing::Point(214, 24);
			this->NTextBox->Name = L"NTextBox";
			this->NTextBox->Size = System::Drawing::Size(100, 21);
			this->NTextBox->TabIndex = 3;
			this->NTextBox->Text = L"100";
			// 
			// MInput
			// 
			this->MInput->AutoSize = true;
			this->MInput->Location = System::Drawing::Point(321, 33);
			this->MInput->Name = L"MInput";
			this->MInput->Size = System::Drawing::Size(11, 12);
			this->MInput->TabIndex = 4;
			this->MInput->Text = L"M";
			// 
			// MTextBox
			// 
			this->MTextBox->Location = System::Drawing::Point(369, 24);
			this->MTextBox->Name = L"MTextBox";
			this->MTextBox->Size = System::Drawing::Size(100, 21);
			this->MTextBox->TabIndex = 5;
			this->MTextBox->Text = L"10";
			// 
			// SInput
			// 
			this->SInput->AutoSize = true;
			this->SInput->Location = System::Drawing::Point(12, 63);
			this->SInput->Name = L"SInput";
			this->SInput->Size = System::Drawing::Size(11, 12);
			this->SInput->TabIndex = 6;
			this->SInput->Text = L"S";
			// 
			// STextBox
			// 
			this->STextBox->Location = System::Drawing::Point(59, 54);
			this->STextBox->Name = L"STextBox";
			this->STextBox->Size = System::Drawing::Size(100, 21);
			this->STextBox->TabIndex = 7;
			this->STextBox->Text = L"5";
			// 
			// TInput
			// 
			this->TInput->AutoSize = true;
			this->TInput->Location = System::Drawing::Point(169, 63);
			this->TInput->Name = L"TInput";
			this->TInput->Size = System::Drawing::Size(11, 12);
			this->TInput->TabIndex = 8;
			this->TInput->Text = L"T";
			// 
			// TTextBox
			// 
			this->TTextBox->Location = System::Drawing::Point(214, 53);
			this->TTextBox->Name = L"TTextBox";
			this->TTextBox->Size = System::Drawing::Size(100, 21);
			this->TTextBox->TabIndex = 9;
			this->TTextBox->Text = L"10";
			// 
			// TimeOut
			// 
			this->TimeOut->AutoSize = true;
			this->TimeOut->Enabled = false;
			this->TimeOut->Location = System::Drawing::Point(323, 62);
			this->TimeOut->Name = L"TimeOut";
			this->TimeOut->Size = System::Drawing::Size(29, 12);
			this->TimeOut->TabIndex = 10;
			this->TimeOut->Text = L"时间";
			// 
			// TimeTextBox
			// 
			this->TimeTextBox->Location = System::Drawing::Point(369, 53);
			this->TimeTextBox->Name = L"TimeTextBox";
			this->TimeTextBox->ReadOnly = true;
			this->TimeTextBox->Size = System::Drawing::Size(100, 21);
			this->TimeTextBox->TabIndex = 11;
			// 
			// Start
			// 
			this->Start->Location = System::Drawing::Point(495, 12);
			this->Start->Name = L"Start";
			this->Start->Size = System::Drawing::Size(75, 64);
			this->Start->TabIndex = 12;
			this->Start->Text = L"开始";
			this->Start->UseVisualStyleBackColor = true;
			this->Start->Click += gcnew System::EventHandler(this, &Form1::Start_Click);
			// 
			// ElevatorChoose
			// 
			this->ElevatorChoose->AutoSize = true;
			this->ElevatorChoose->Location = System::Drawing::Point(14, 100);
			this->ElevatorChoose->Name = L"ElevatorChoose";
			this->ElevatorChoose->Size = System::Drawing::Size(29, 12);
			this->ElevatorChoose->TabIndex = 13;
			this->ElevatorChoose->Text = L"电梯";
			// 
			// ElevatorComboBox
			// 
			this->ElevatorComboBox->FormattingEnabled = true;
			this->ElevatorComboBox->Location = System::Drawing::Point(59, 91);
			this->ElevatorComboBox->Name = L"ElevatorComboBox";
			this->ElevatorComboBox->Size = System::Drawing::Size(121, 20);
			this->ElevatorComboBox->TabIndex = 14;
			this->ElevatorComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::ElevatorComboBox_SelectedIndexChanged);
			// 
			// FloorChoose
			// 
			this->FloorChoose->AutoSize = true;
			this->FloorChoose->Location = System::Drawing::Point(212, 100);
			this->FloorChoose->Name = L"FloorChoose";
			this->FloorChoose->Size = System::Drawing::Size(29, 12);
			this->FloorChoose->TabIndex = 15;
			this->FloorChoose->Text = L"楼层";
			// 
			// FloorComboBox
			// 
			this->FloorComboBox->FormattingEnabled = true;
			this->FloorComboBox->Location = System::Drawing::Point(260, 91);
			this->FloorComboBox->Name = L"FloorComboBox";
			this->FloorComboBox->Size = System::Drawing::Size(121, 20);
			this->FloorComboBox->TabIndex = 16;
			this->FloorComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::FloorComboBox_SelectedIndexChanged);
			// 
			// PeopleChoose
			// 
			this->PeopleChoose->AutoSize = true;
			this->PeopleChoose->Location = System::Drawing::Point(400, 98);
			this->PeopleChoose->Name = L"PeopleChoose";
			this->PeopleChoose->Size = System::Drawing::Size(29, 12);
			this->PeopleChoose->TabIndex = 17;
			this->PeopleChoose->Text = L"乘客";
			// 
			// PeopleComboBox
			// 
			this->PeopleComboBox->FormattingEnabled = true;
			this->PeopleComboBox->Location = System::Drawing::Point(448, 90);
			this->PeopleComboBox->Name = L"PeopleComboBox";
			this->PeopleComboBox->Size = System::Drawing::Size(121, 20);
			this->PeopleComboBox->TabIndex = 18;
			this->PeopleComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::PeopleComboBox_SelectedIndexChanged);
			// 
			// ElevatorRichTextBox
			// 
			this->ElevatorRichTextBox->Location = System::Drawing::Point(16, 130);
			this->ElevatorRichTextBox->Name = L"ElevatorRichTextBox";
			this->ElevatorRichTextBox->ReadOnly = true;
			this->ElevatorRichTextBox->Size = System::Drawing::Size(166, 213);
			this->ElevatorRichTextBox->TabIndex = 20;
			this->ElevatorRichTextBox->Text = L"\n";
			// 
			// FloorRichTextBox
			// 
			this->FloorRichTextBox->Location = System::Drawing::Point(214, 130);
			this->FloorRichTextBox->Name = L"FloorRichTextBox";
			this->FloorRichTextBox->ReadOnly = true;
			this->FloorRichTextBox->Size = System::Drawing::Size(167, 213);
			this->FloorRichTextBox->TabIndex = 21;
			this->FloorRichTextBox->Text = L"";
			// 
			// PeopleRichTextBox
			// 
			this->PeopleRichTextBox->Location = System::Drawing::Point(402, 130);
			this->PeopleRichTextBox->Name = L"PeopleRichTextBox";
			this->PeopleRichTextBox->ReadOnly = true;
			this->PeopleRichTextBox->Size = System::Drawing::Size(167, 213);
			this->PeopleRichTextBox->TabIndex = 22;
			this->PeopleRichTextBox->Text = L"";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(582, 375);
			this->Controls->Add(this->PeopleRichTextBox);
			this->Controls->Add(this->FloorRichTextBox);
			this->Controls->Add(this->ElevatorRichTextBox);
			this->Controls->Add(this->PeopleComboBox);
			this->Controls->Add(this->PeopleChoose);
			this->Controls->Add(this->FloorComboBox);
			this->Controls->Add(this->FloorChoose);
			this->Controls->Add(this->ElevatorComboBox);
			this->Controls->Add(this->ElevatorChoose);
			this->Controls->Add(this->Start);
			this->Controls->Add(this->TimeTextBox);
			this->Controls->Add(this->TimeOut);
			this->Controls->Add(this->TTextBox);
			this->Controls->Add(this->TInput);
			this->Controls->Add(this->STextBox);
			this->Controls->Add(this->SInput);
			this->Controls->Add(this->MTextBox);
			this->Controls->Add(this->MInput);
			this->Controls->Add(this->NTextBox);
			this->Controls->Add(this->NInput);
			this->Controls->Add(this->KTextBox);
			this->Controls->Add(this->KInput);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Start_Click(System::Object^  sender, System::EventArgs^  e) {
				 totTime = 0;
				 K = Convert::ToInt32(this->KTextBox->Text,10);
				 N = Convert::ToInt32(this->NTextBox->Text,10);
				 M = Convert::ToInt32(this->MTextBox->Text,10);
				 S = Convert::ToInt32(this->STextBox->Text,10);
				 T = Convert::ToInt32(this->TTextBox->Text,10);
				 ElevatorComboBox->Items->Clear();
				 FloorComboBox->Items->Clear();
				 PeopleComboBox->Items->Clear();
				 for (int i = 1; i <= 10; i++) {
					 ElevatorComboBox->Items->Add(((Int32)i).ToString());
				 }
				 for (int i = 1; i <= 40; i++) {
					 FloorComboBox->Items->Add(((Int32)i).ToString());
				 }
				 for (int i = 1; i <= N; i++) {
					 PeopleComboBox->Items->Add(((Int32)i).ToString());
				 }
				 pSys = new ElevatorSimulateSystem(K, N, M, S, T);
				 ElevatorComboBox->SelectedIndex = 0;
				 FloorComboBox->SelectedIndex = 0;
				 PeopleComboBox->SelectedIndex = 0;
				 pSys->VS.setElevID(ElevatorComboBox->SelectedIndex);
				 pSys->VS.setFloorID(FloorComboBox->SelectedIndex + 1);
				 pSys->VS.setPeopleID(PeopleComboBox->SelectedIndex);
				 Start->Enabled = false;
				 timer1->Start();
			 }
private: System::Void ElevatorComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				 pSys->VS.setElevID(ElevatorComboBox->SelectedIndex);
				 ElevatorRichTextBox ->Text = gcnew String(pSys->VS.getElevInfo().c_str());
		 }
private: System::Void FloorComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				pSys->VS.setFloorID(FloorComboBox->SelectedIndex + 1);
				FloorRichTextBox->Text = gcnew String(pSys->VS.getFloorInfo().c_str());
		 }
private: System::Void PeopleComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				pSys->VS.setPeopleID(PeopleComboBox->SelectedIndex);
				PeopleRichTextBox->Text = gcnew String(pSys->VS.getPeopelInfo().c_str());
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			 totTime++;
			 this->TimeTextBox->Text = ((Int32)totTime).ToString();
			 if (pSys->End()) {
				timer1->Stop();
				Start->Enabled = true;
			 } else {
				 pSys->stepStart();
				ElevatorRichTextBox ->Text = gcnew String(pSys->VS.getElevInfo().c_str());
				FloorRichTextBox->Text = gcnew String(pSys->VS.getFloorInfo().c_str());
				PeopleRichTextBox->Text = gcnew String(pSys->VS.getPeopelInfo().c_str());
			 }
		 }
};
}

