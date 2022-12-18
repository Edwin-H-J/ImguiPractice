//
// Created by jhas on 2022/12/16.
//

#include "Triangle.h"
#include "../utils/HLSLCompile.h"
struct Vertex {
    float x, y;
    float r, g, b;
};
const D3D11_INPUT_ELEMENT_DESC Triangle::VertexPosColor::inputLayout[2] = {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 }
};
Triangle::Triangle() {

}

Triangle::~Triangle() {
    SAFE_RELEASE(m_vertexBuffer)
    SAFE_RELEASE(m_vertexShader)
    SAFE_RELEASE(m_pixelShader)
    SAFE_RELEASE(m_inputLayout)
}

void Triangle::draw() {
    UINT stride = sizeof(VertexPosColor);	// 跨越字节数
    UINT offset = 0;						// 起始偏移量

    m_pd3dImmediateContext->IASetVertexBuffers(0, 1, &m_vertexBuffer, &stride, &offset);
    // 设置图元类型，设定输入布局
    m_pd3dImmediateContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    m_pd3dImmediateContext->IASetInputLayout(m_inputLayout);
    // 将着色器绑定到渲染管线
    m_pd3dImmediateContext->VSSetShader(m_vertexShader, nullptr, 0);
    m_pd3dImmediateContext->PSSetShader(m_pixelShader, nullptr, 0);
    m_pd3dImmediateContext->Draw(3, 0);
}

bool Triangle::Init(ID3D11Device* device,ID3D11DeviceContext* deviceContext) {
    m_pd3dDevice = device;
    m_pd3dImmediateContext = deviceContext;
    if (!InitEffect())
        return false;

    if (!InitResource())
        return false;

    return true;
}

bool Triangle::InitEffect() {
    ID3DBlob* blob;

    // 创建顶点着色器
    CreateShaderFromFile(L"HLSL\\Triangle_VS.cso", L"HLSL\\Triangle_VS.hlsl", "VS", "vs_5_0", &blob);
    m_pd3dDevice->CreateVertexShader(blob->GetBufferPointer(), blob->GetBufferSize(), nullptr, &m_vertexShader);
    // 创建并绑定顶点布局
    m_pd3dDevice->CreateInputLayout(VertexPosColor::inputLayout, ARRAYSIZE(VertexPosColor::inputLayout),
                                       blob->GetBufferPointer(), blob->GetBufferSize(), &m_inputLayout);
    blob->Release();
    blob = nullptr;
    // 创建像素着色器
    CreateShaderFromFile(L"HLSL\\Triangle_PS.cso", L"HLSL\\Triangle_PS.hlsl", "PS", "ps_5_0", &blob);
    m_pd3dDevice->CreatePixelShader(blob->GetBufferPointer(), blob->GetBufferSize(), nullptr, &m_pixelShader);

    return true;
}

bool Triangle::InitResource() {
    VertexPosColor vertices[] =
            {
                    { DirectX::XMFLOAT3(0.0f, 0.5f, 0.5f), DirectX::XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f) },
                    { DirectX::XMFLOAT3(0.5f, -0.5f, 0.5f), DirectX::XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f) },
                    { DirectX::XMFLOAT3(-0.5f, -0.5f, 0.5f), DirectX::XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f) },
            };
    // 设置顶点缓冲区描述
    D3D11_BUFFER_DESC vbd;
    ZeroMemory(&vbd, sizeof(vbd));
    vbd.Usage = D3D11_USAGE_IMMUTABLE;
    vbd.ByteWidth = sizeof vertices;
    vbd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    vbd.CPUAccessFlags = 0;
    // 新建顶点缓冲区
    D3D11_SUBRESOURCE_DATA InitData;
    ZeroMemory(&InitData, sizeof(InitData));
    InitData.pSysMem = vertices;
    m_pd3dDevice->CreateBuffer(&vbd, &InitData, &m_vertexBuffer);
    return true;
}

