#include "MyForm.h"


using namespace Project3; // Where FDWE Enter your project name

[STAThreadAttribute]
int main()
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Create the main window and run it
	Application::Run(gcnew MyForm()); //where MyForm() Enter your main form name with () [Bracket]
	return 0;
}