//
// Created by jhas on 2022/12/18.
//

#include "DisplayApp.h"

bool DisplayApp::Init() {
    if(!D3DApp::Init()) {
        return false;
    }
    if(!triangle.Init(m_pd3dDevice,m_pd3dImmediateContext)){
        return false;
    }
    return true;
}

void DisplayApp::DrawScene() {
    assert(m_pd3dImmediateContext);
    assert(m_pSwapChain);
    static float blue[4] = { 0.0f, 0.0f, 0.0f, 1.0f };  // RGBA = (0,0,255,255)
    m_pd3dImmediateContext->ClearRenderTargetView(m_pRenderTargetView, blue);
    m_pd3dImmediateContext->ClearDepthStencilView(m_pDepthStencilView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
    triangle.draw();

    m_pSwapChain->Present(0, 0);
}

DisplayApp::DisplayApp(const std::wstring &windowName, int initWidth, int initHeight) : D3DApp(windowName, initWidth,
                                                                                               initHeight) {

}
