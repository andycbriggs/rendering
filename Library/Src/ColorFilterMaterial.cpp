#include "ColorFilterMaterial.hpp"

#include <VertexTypes.h>

#include "Effect.hpp"
#include "EffectPass.hpp"
#include "EffectTechnique.hpp"
#include "EffectVariable.hpp"
#include "Texture2D.hpp"

using namespace std;

void ColorFilterMaterial::Initialise()
{
    mEffect = make_unique<Effect>(L"Content\\Effects\\ColorFilter.cso");

    // Create input layouts for all techniques
    // TODO: Why not just do this for everything?
    for (auto& technique : mEffect->GetTechniques())
    {
        for (auto& pass : technique->GetPasses())
        {
            CreateInputLayout(technique->GetName(), pass->GetName(), VertexPositionTexture::InputElements, VertexPositionTexture::InputElementCount);
        }
    }
}
