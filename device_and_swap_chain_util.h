//
// Created by jhas on 2022/12/10.
//
#pragma once
#include "backend/imgui_impl_win32.h"
#include "backend/imgui_impl_dx11.h"
#include <d3d11.h>

bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void CreateRenderTarget();
void CleanupRenderTarget();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
ID3D11Device*            get_g_pd3dDevice();
ID3D11DeviceContext*     get_g_pd3dDeviceContext();
IDXGISwapChain*          get_g_pSwapChain();
ID3D11RenderTargetView**  get_g_mainRenderTargetView();