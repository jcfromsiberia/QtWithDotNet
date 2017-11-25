
#include "dotnetform.h"
#using <mscorlib.dll>

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Windows;
using namespace System::Windows::Forms;

ref class MyForm : public Form
{
   TextBox ^ textBox = gcnew TextBox();
public:
   MyForm()
   {
      Label ^ label = gcnew Label();
      label->Text = "This is .NET form!\nEnter your name";
      SuspendLayout();
      Controls->Add(label);
      textBox->Location = System::Drawing::Point(12, 32);
      textBox->Size = System::Drawing::Size(100, 20);
      Controls->Add(textBox);

      Button ^ okButton = gcnew Button();
      okButton->Text = "OK";
      okButton->Location = System::Drawing::Point(37, 58);
      okButton->Size = System::Drawing::Size(75, 23);
      okButton->UseVisualStyleBackColor = true;
      Controls->Add(okButton);

      okButton->Click += gcnew System::EventHandler(this, &MyForm::OnClick);
      this->DialogResult = ::DialogResult::No;

      ResumeLayout(false);
      PerformLayout();
   }

   property String ^ name 
   {
      String ^ get()
      {
         return textBox->Text;
      }
   }
   void OnClick(System::Object ^sender, System::EventArgs ^e);
};

std::string showDotNetForm()
{
   MyForm ^ form = gcnew MyForm();
   String ^ name = "Anonymous";
   if( form->ShowDialog() == ::DialogResult::OK)
   {
      name = form->name;
   }

   char * unmanagedName = (char*)(void*)Marshal::StringToHGlobalAnsi( name );
   std::string result( unmanagedName );
   Marshal::FreeHGlobal( IntPtr( unmanagedName ) );
   return result;
}

void MyForm::OnClick(System::Object ^sender, System::EventArgs ^e)
{
   DialogResult = ::DialogResult::OK;
   Close();
}
