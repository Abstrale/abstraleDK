
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

LRESULT CALLBACK WindowProc(
    HWND hwnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam
) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            TextOutA(
                hdc, 30, 30,
                "Mon premier logiciel en C !", 27
            );

            EndPaint(hwnd, &ps);
            return 0;
        }
    }

    return DefWindowProcA(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
) {
    (void)hPrevInstance;
    (void)lpCmdLine;

    const char CLASS_NAME[] = "MonLogicielC";

    WNDCLASSA wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);

    if (!RegisterClassA(&wc))
        return 1;

    HWND hwnd = CreateWindowExA(
        0,
        CLASS_NAME,
        "Mon logiciel natif",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        800, 500,
        NULL, NULL, hInstance, NULL
    );

    if (!hwnd)
        return 1;

    ShowWindow(hwnd, nCmdShow);

    MSG msg;
    while (GetMessageA(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }

    return 0;
}
