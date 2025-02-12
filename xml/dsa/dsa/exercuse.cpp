#include <windows.h>
#include <string>
#include <sstream>
#include <cmath>
#include <cstdlib> // For atof()

HWND screen;
double num1 = 0.0;
double num2 = 0.0;
char op = '\0';
bool isEnteringSecondNum = false;

LRESULT CALLBACK WinProcedure(HWND, UINT, WPARAM, LPARAM);
void InitializeControls(HWND);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
    WNDCLASS wc = { 0 };
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = "CalcWindowClass";
    wc.lpfnWndProc = WinProcedure;

    if (!RegisterClass(&wc)) return -1;

    CreateWindow("CalcWindowClass", "Simple Calculator", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 300, 350, NULL, NULL, hInst, NULL);

    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0)) { // Replace NULL with 0 for UINT parameters
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

void InitializeControls(HWND hWnd) {
    screen = CreateWindow("EDIT", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT, 50, 20, 200, 30, hWnd, NULL, NULL, NULL);

    CreateWindow("BUTTON", "7", WS_VISIBLE | WS_CHILD, 50, 70, 50, 50, hWnd, (HMENU)'7', NULL, NULL);
    CreateWindow("BUTTON", "8", WS_VISIBLE | WS_CHILD, 100, 70, 50, 50, hWnd, (HMENU)'8', NULL, NULL);
    CreateWindow("BUTTON", "9", WS_VISIBLE | WS_CHILD, 150, 70, 50, 50, hWnd, (HMENU)'9', NULL, NULL);
    CreateWindow("BUTTON", "4", WS_VISIBLE | WS_CHILD, 50, 120, 50, 50, hWnd, (HMENU)'4', NULL, NULL);
    CreateWindow("BUTTON", "5", WS_VISIBLE | WS_CHILD, 100, 120, 50, 50, hWnd, (HMENU)'5', NULL, NULL);
    CreateWindow("BUTTON", "6", WS_VISIBLE | WS_CHILD, 150, 120, 50, 50, hWnd, (HMENU)'6', NULL, NULL);
    CreateWindow("BUTTON", "1", WS_VISIBLE | WS_CHILD, 50, 170, 50, 50, hWnd, (HMENU)'1', NULL, NULL);
    CreateWindow("BUTTON", "2", WS_VISIBLE | WS_CHILD, 100, 170, 50, 50, hWnd, (HMENU)'2', NULL, NULL);
    CreateWindow("BUTTON", "3", WS_VISIBLE | WS_CHILD, 150, 170, 50, 50, hWnd, (HMENU)'3', NULL, NULL);
    CreateWindow("BUTTON", "0", WS_VISIBLE | WS_CHILD, 50, 220, 50, 50, hWnd, (HMENU)'0', NULL, NULL);
    CreateWindow("BUTTON", "C", WS_VISIBLE | WS_CHILD, 100, 220, 50, 50, hWnd, (HMENU)'C', NULL, NULL);
    CreateWindow("BUTTON", "=", WS_VISIBLE | WS_CHILD, 150, 220, 50, 50, hWnd, (HMENU)'=', NULL, NULL);
    CreateWindow("BUTTON", "+", WS_VISIBLE | WS_CHILD, 200, 70, 50, 50, hWnd, (HMENU)'+', NULL, NULL);
    CreateWindow("BUTTON", "-", WS_VISIBLE | WS_CHILD, 200, 120, 50, 50, hWnd, (HMENU)'-', NULL, NULL);
    CreateWindow("BUTTON", "*", WS_VISIBLE | WS_CHILD, 200, 170, 50, 50, hWnd, (HMENU)'*', NULL, NULL);
    CreateWindow("BUTTON", "/", WS_VISIBLE | WS_CHILD, 200, 220, 50, 50, hWnd, (HMENU)'/', NULL, NULL);
}

void ExecuteCalculation() {
    double output = 0.0;
    switch (op) {
        case '+':
            output = num1 + num2;
            break;
        case '-':
            output = num1 - num2;
            break;
        case '*':
            output = num1 * num2;
            break;
        case '/':
            if (num2 != 0.0) {
                output = num1 / num2;
            } else {
                MessageBox(NULL, "Cannot divide by zero", "Error", MB_OK | MB_ICONERROR);
                return;
            }
            break;
    }

    std::ostringstream outStr;
    if (std::floor(output) == output) {
        outStr << static_cast<int>(output);
    } else {
        outStr << output;
    }
    SetWindowText(screen, outStr.str().c_str());
}

LRESULT CALLBACK WinProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_COMMAND:
            if (wp >= '0' && wp <= '9') {
                char digit[2] = { (char)wp, '\0' };
                int len = GetWindowTextLength(screen);
                if (isEnteringSecondNum) {
                    SetWindowText(screen, digit);
                    isEnteringSecondNum = false;
                } else {
                    SendMessage(screen, EM_SETSEL, len, len);
                    SendMessage(screen, EM_REPLACESEL, FALSE, (LPARAM)digit);
                }
            } else if (wp == '+' || wp == '-' || wp == '*' || wp == '/') {
                op = (char)wp;
                char buf[256];
                GetWindowText(screen, buf, sizeof(buf));
                num1 = std::atof(buf); // Replaced stod with atof
                isEnteringSecondNum = true;
            } else if (wp == '=') {
                char buf[256];
                GetWindowText(screen, buf, sizeof(buf));
                num2 = std::atof(buf); // Replaced stod with atof
                ExecuteCalculation();
                isEnteringSecondNum = true;
            } else if (wp == 'C') {
                SetWindowText(screen, "");
                num1 = num2 = 0.0;
                op = '\0';
                isEnteringSecondNum = false;
            }
            break;
        case WM_CREATE:
            InitializeControls(hWnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd, msg, wp, lp);
    }
    return 0;
}

