#ifndef IMGUIPRACTICE_D3DAPP_H
#define IMGUIPRACTICE_D3DAPP_H
#include <string>
#include <Windows.h>
#include <d3d11.h>
#include <cassert>
#include <imgui.h>
#include <backend/imgui_impl_win32.h>
#include <backend/imgui_impl_dx11.h>
class D3DApp {
public:
    D3DApp(const std::wstring& windowName, int initWidth, int initHeight);
    ~D3DApp();
    int Run();
    virtual bool Init();
    void OnResize();
    virtual void DrawScene() = 0;

    LRESULT MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
protected:
    bool InitMainWindow();
    bool InitDirect3D();
    void cleanPtr();
    bool InitImGui();


    HINSTANCE hinstance;
    std::wstring m_MainWndCaption;
    HWND      m_hMainWnd;        // 主窗口句柄
    bool      m_AppPaused;       // 应用是否暂停
    bool      m_Minimized;       // 应用是否最小化
    bool      m_Maximized;       // 应用是否最大化
    bool      m_Resizing;        // 窗口大小是否变化
    bool      m_Enable4xMsaa;    // 是否开启4倍多重采样
    UINT      m_4xMsaaQuality;   // MSAA支持的质量等级

    int m_ClientWidth;
    int m_ClientHeight;
    ID3D11Device* m_pd3dDevice;
    ID3D11DeviceContext* m_pd3dImmediateContext;
    IDXGISwapChain* m_pSwapChain;

    ID3D11Texture2D* m_pDepthStencilBuffer;        // 深度模板缓冲区
    ID3D11RenderTargetView* m_pRenderTargetView;   // 渲染目标视图
    ID3D11DepthStencilView* m_pDepthStencilView;   // 深度模板视图
    D3D11_VIEWPORT m_ScreenViewport;                      // 视口
};
#endif