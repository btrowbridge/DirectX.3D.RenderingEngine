#pragma once

#include "Light.h"

namespace Library
{
	class PointLight : public Light
	{
		RTTI_DECLARATIONS(PointLight, Light)

	public:
		PointLight(Game& game);
		virtual ~PointLight() = default;

		DirectX::XMFLOAT3& Position();
		DirectX::XMVECTOR PositionVector() const;
		FLOAT Radius() const;

		virtual void SetPosition(float x, float y, float z);
		virtual void SetPosition(DirectX::FXMVECTOR position);
		virtual void SetPosition(const DirectX::XMFLOAT3& position);
		virtual void SetRadius(float value);

		static const float DefaultRadius;

	protected:
		DirectX::XMFLOAT3 mPosition;
		float mRadius;
	};
}
