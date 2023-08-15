#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

char appName[] = "MyClass";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wndClass;
    wndClass.cbClsExtra = 0;
    wndClass.cbSize = sizeof(WNDCLASSEX);
    wndClass.cbWndExtra = 0;
    wndClass.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 3);
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.hIcon = NULL;
    wndClass.hIconSm = NULL;
    wndClass.hInstance = hInstance;
    wndClass.lpfnWndProc = WindowProc;
    wndClass.lpszClassName = appName;
    wndClass.lpszMenuName = NULL;
    wndClass.style = CS_HREDRAW | CS_VREDRAW;

    if (!RegisterClassEx(&wndClass))
    {
        MessageBox(HWND_DESKTOP, "Error creating the class", "Error", MB_OK | MB_ICONASTERISK);
    }

    HWND window;
    window = CreateWindow(appName, "My Window", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT, 500, 500, HWND_DESKTOP, NULL, hInstance, NULL);

    if (!window)
    {
        MessageBox(HWND_DESKTOP, "Error creating the window", "Error", MB_OK | MB_ICONASTERISK);
    }

    ShowWindow(window, SW_SHOWNORMAL);

    MSG msg;
    while (GetMessage(&msg, 0, 0, 0))
    {
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}
