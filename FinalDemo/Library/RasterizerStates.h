#pragma once

#include <wrl.h>
#include <d3d11_2.h>

namespace Library
{
	class RasterizerStates
	{
	public:
		static Microsoft::WRL::ComPtr<ID3D11RasterizerState> BackCulling;
		static Microsoft::WRL::ComPtr<ID3D11RasterizerState> FrontCulling;
		static Microsoft::WRL::ComPtr<ID3D11RasterizerState> DisabledCulling;
		static Microsoft::WRL::ComPtr<ID3D11RasterizerState> Wireframe;

		static void Initialize(ID3D11Device* direct3DDevice);
		static void Shutdown();

		RasterizerStates() = delete;
		RasterizerStates(const RasterizerStates& rhs) = delete;
		RasterizerStates& operator=(const RasterizerStates& rhs) = delete;
	};
}
