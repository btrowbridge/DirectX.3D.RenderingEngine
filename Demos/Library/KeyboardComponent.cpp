#include "pch.h"

using namespace std;
using namespace DirectX;

namespace Library
{
	RTTI_DEFINITIONS(KeyboardComponent)

		unique_ptr<DirectX::Keyboard> KeyboardComponent::sKeyboard(new DirectX::Keyboard);

	DirectX::Keyboard* KeyboardComponent::Keyboard()
	{
		return sKeyboard.get();
	}

	KeyboardComponent::KeyboardComponent(Game& game) :
		GameComponent(game)
	{
	}

	const DirectX::Keyboard::State& KeyboardComponent::CurrentState() const
	{
		return mCurrentState;
	}

	const DirectX::Keyboard::State& KeyboardComponent::LastState() const
	{
		return mLastState;
	}

	void KeyboardComponent::Initialize()
	{
		mCurrentState = sKeyboard->GetState();
		mLastState = mCurrentState;
	}

	void KeyboardComponent::Update(const GameTime& gameTime)
	{
		UNREFERENCED_PARAMETER(gameTime);

		mLastState = mCurrentState;
		mCurrentState = sKeyboard->GetState();
	}

	bool KeyboardComponent::IsKeyUp(Keys key) const
	{
		return mCurrentState.IsKeyUp(static_cast<DirectX::Keyboard::Keys>(key));
	}

	bool KeyboardComponent::IsKeyDown(Keys key) const
	{
		return mCurrentState.IsKeyDown(static_cast<DirectX::Keyboard::Keys>(key));
	}

	bool KeyboardComponent::WasKeyUp(Keys key) const
	{
		return mLastState.IsKeyUp(static_cast<DirectX::Keyboard::Keys>(key));
	}

	bool KeyboardComponent::WasKeyDown(Keys key) const
	{
		return mLastState.IsKeyDown(static_cast<DirectX::Keyboard::Keys>(key));
	}

	bool KeyboardComponent::WasKeyPressedThisFrame(Keys key) const
	{
		return (IsKeyDown(key) && WasKeyUp(key));
	}

	bool KeyboardComponent::WasKeyReleasedThisFrame(Keys key) const
	{
		return (IsKeyUp(key) && WasKeyDown(key));
	}

	bool KeyboardComponent::IsKeyHeldDown(Keys key) const
	{
		return (IsKeyDown(key) && WasKeyDown(key));
	}
}