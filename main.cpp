#include <imgui.h>
#include "utils/device_and_swap_chain_util.h"
#include "windows/MainWindow.h"
#include <tchar.h>
#include "utils/OpenJSONFile.h"
#include <iostream>
#include "components/ButtonGroup.h"
inline int imguiStart(WNDCLASSEXW& wc,
               HWND& hwnd
);
inline void imguiStop(
        WNDCLASSEXW& wc,
        HWND& hwnd
);
inline void handleMsg(bool& done);

int main(int, char**)
{
    WNDCLASSEXW wc = { sizeof(wc), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, L"ImGui Example", NULL };
    ::RegisterClassExW(&wc);
    HWND hwnd = ::CreateWindowW(wc.lpszClassName, L"Editor", WS_OVERLAPPEDWINDOW, 100, 100, 1280, 800, NULL, NULL, wc.hInstance, NULL);
    if(imguiStart(wc,hwnd)){
        return 1;
    }

    bool done = false;
    MainWindow mainWindow;
    while (!done)
    {
        handleMsg(done);
        if (done)
            break;

        ImGui_ImplDX11_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();
        {
            mainWindow.render();
        }
        ImGui::Render();
        const float clear_color_with_alpha[4] = {0.0,0.0,0.0,1.0};
        get_g_pd3dDeviceContext()->OMSetRenderTargets(1, get_g_mainRenderTargetView(), NULL);
        get_g_pd3dDeviceContext()->ClearRenderTargetView(*get_g_mainRenderTargetView(), clear_color_with_alpha);
        ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
        get_g_pSwapChain()->Present(1, 0);
    }
    imguiStop(wc,hwnd);
    return 0;
}
inline void handleMsg(bool& done) {
    MSG msg;
    while (::PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
    {
        ::TranslateMessage(&msg);
        ::DispatchMessage(&msg);
        if (msg.message == WM_QUIT)
            done = true;
    }
}

inline int imguiStart(WNDCLASSEXW& wc,
                HWND& hwnd
                ) {

    // Initialize Direct3D
    if (!CreateDeviceD3D(hwnd))
    {
        CleanupDeviceD3D();
        ::UnregisterClassW(wc.lpszClassName, wc.hInstance);
        return 1;
    }

    // Show the window
    ::ShowWindow(hwnd, SW_SHOWDEFAULT);
    ::UpdateWindow(hwnd);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsLight();

    // Setup Platform/Renderer backends
    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplDX11_Init(get_g_pd3dDevice(), get_g_pd3dDeviceContext());
    return 0;
}

inline void imguiStop(
            WNDCLASSEXW& wc,
            HWND& hwnd
        ) {
    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    ::DestroyWindow(hwnd);
    ::UnregisterClassW(wc.lpszClassName, wc.hInstance);
}

