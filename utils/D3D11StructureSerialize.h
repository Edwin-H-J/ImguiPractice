//
// Created by jhas on 2022/12/12.
//

#ifndef IMGUIPRACTICE_D3D11STRUCTURESERIALIZE_H
#define IMGUIPRACTICE_D3D11STRUCTURESERIALIZE_H
#include <d3d11.h>
#include <cereal/cereal.hpp>
template<class Archive>
void serialize(Archive & archive,
               D3D11_BLEND_DESC & m)
{
    archive( CEREAL_NVP(m.AlphaToCoverageEnable), CEREAL_NVP(m.IndependentBlendEnable), CEREAL_NVP(m.RenderTarget) );
}
template<class Archive>
void serialize(Archive & archive,
               D3D11_RENDER_TARGET_BLEND_DESC & m)
{
    archive( CEREAL_NVP(m.BlendEnable),
             CEREAL_NVP(m.BlendOp),
             CEREAL_NVP(m.BlendOpAlpha),
             CEREAL_NVP(m.DestBlend),
             CEREAL_NVP(m.DestBlendAlpha),
             CEREAL_NVP(m.RenderTargetWriteMask),
             CEREAL_NVP(m.SrcBlend),
             CEREAL_NVP(m.SrcBlendAlpha)
             );
}


#endif //IMGUIPRACTICE_D3D11STRUCTURESERIALIZE_H
