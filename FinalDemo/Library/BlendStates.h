#pragma once

#include <wrl.h>
#include <d3d11_2.h>

namespace Library
{
	class BlendStates
	{
	public:
		static Microsoft::WRL::ComPtr<ID3D11BlendState> AlphaBlending;
		static Microsoft::WRL::ComPtr<ID3D11BlendState> MultiplicativeBlending;

		static void Initialize(ID3D11Device* direct3DDevice);
		static void Shutdown();

		BlendStates() = delete;
		BlendStates(const BlendStates& rhs) = delete;
		BlendStates& operator=(const BlendStates& rhs) = delete;
	};
}