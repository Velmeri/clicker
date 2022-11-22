#include <Windows.h>
#include <string>

int main() {
	int L = 0, R = 0, M = 0;
	while (1) {
		int preL = L, preR = R, preM = M;

		if ((GetKeyState(MKF_LEFTBUTTONDOWN) & 0x8000))
		{
			L++;
			Sleep(250);
		}
		if ((GetKeyState(MKF_RIGHTBUTTONDOWN) & 0x8000))
		{
			R++;
			Sleep(250);
		}
		if ((GetKeyState(!MK_MBUTTON) & 0x8000)) {
			M++;
			Sleep(250);
		}

		if (preL != L || preR != R || preM != M) {
			std::wstring title = L"L = " + std::to_wstring(L) + L", R = " + std::to_wstring(R) + L", M = " + std::to_wstring(M);
			SetConsoleTitleW(title.c_str());
		}
	}
	return 0;
}