#include "MainApp.h"

int CALLBACK wWinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ PWSTR, _In_ int)
{
	MainApp app{};
	return app.run();
}