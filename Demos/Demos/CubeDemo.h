#pragma once

#include <wrl.h>
#include <d3d11_2.h>
#include <DirectXMath.h>
#include <cstdint>
#include <memory>
#include "DrawableGameComponent.h"

namespace Library
{
	class Camera;
}

namespace Rendering
{
	class CubeDemo : public Library::DrawableGameComponent
	{
	public:
		CubeDemo(Library::Game& game);
		CubeDemo(Library::Game& game, const std::shared_ptr<Library::Camera>& camera);
		CubeDemo(const CubeDemo& rhs) = delete;
		CubeDemo& operator=(const CubeDemo& rhs) = delete;

		bool AnimationEnabled() const;
		void SetAnimationEnabled(bool enabled);

		virtual void Initialize() override;
		virtual void Update(const Library::GameTime& gameTime) override;
		virtual void Draw(const Library::GameTime& gameTime) override;

	private:
		struct CBufferPerObject
		{
			DirectX::XMFLOAT4X4 WorldViewProjection;

			CBufferPerObject() : WorldViewProjection() { }
			CBufferPerObject(const DirectX::XMFLOAT4X4& wvp) : WorldViewProjection(wvp) { }
		};

		static const float RotationRate;

		Microsoft::WRL::ComPtr<ID3D11VertexShader> mVertexShader;
		Microsoft::WRL::ComPtr<ID3D11PixelShader> mPixelShader;
		Microsoft::WRL::ComPtr<ID3D11InputLayout> mInputLayout;
		Microsoft::WRL::ComPtr<ID3D11Buffer> mVertexBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer> mIndexBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer> mConstantBuffer;
		DirectX::XMFLOAT4X4 mWorldMatrix;
		CBufferPerObject mCBufferPerObject;
		std::uint32_t mIndexCount;
		bool mAnimationEnabled;
	};
}
