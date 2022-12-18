//
// Created by jhas on 2022/12/16.
//

#ifndef IMGUIPRACTICE_TRIANGLE_H
#define IMGUIPRACTICE_TRIANGLE_H
#include <d3d11.h>
#include <fstream>
#include <vector>
#include <DirectXMath.h>
#include "../utils/device_and_swap_chain_util.h"

class Triangle {
public:
    Triangle();
    ~Triangle();
    void draw();
    bool Init(ID3D11Device* device,ID3D11DeviceContext* deviceContext);
    struct VertexPosColor
    {
        DirectX::XMFLOAT3 pos;
        DirectX::XMFLOAT4 color;
        static const D3D11_INPUT_ELEMENT_DESC inputLayout[2];
    };

private:
    bool InitResource();
    bool InitEffect();
    ID3D11Device* m_pd3dDevice;
    ID3D11DeviceContext* m_pd3dImmediateContext;
    ID3D11Buffer* m_vertexBuffer = nullptr;
    ID3D11VertexShader* m_vertexShader = nullptr;
    ID3D11PixelShader* m_pixelShader = nullptr;
    ID3D11InputLayout* m_inputLayout = nullptr;

};


#endif //IMGUIPRACTICE_TRIANGLE_H
