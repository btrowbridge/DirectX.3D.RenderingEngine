#include "pch.h"

using namespace std;
using namespace DirectX;

namespace Library
{
	RTTI_DEFINITIONS(MouseComponent)

		unique_ptr<Mouse> MouseComponent::sMouse(new DirectX::Mouse);

	Mouse* MouseComponent::Mouse()
	{
		return sMouse.get();
	}

	MouseComponent::MouseComponent(Game& game, MouseModes mode) :
		GameComponent(game)
	{
		sMouse->SetMode(static_cast<Mouse::Mode>(mode));
	}

	const Mouse::State& MouseComponent::CurrentState() const
	{
		return mCurrentState;
	}

	const Mouse::State& MouseComponent::LastState() const
	{
		return mLastState;
	}

	void MouseComponent::Initialize()
	{
		mCurrentState = sMouse->GetState();
		mLastState = mCurrentState;
	}

	void MouseComponent::Update(const GameTime& gameTime)
	{
		UNREFERENCED_PARAMETER(gameTime);

		mLastState = mCurrentState;
		mCurrentState = sMouse->GetState();
	}

	int MouseComponent::X() const
	{
		return mCurrentState.x;
	}

	int MouseComponent::Y() const
	{
		return mCurrentState.y;
	}

	int MouseComponent::Wheel() const
	{
		return mCurrentState.scrollWheelValue;
	}

	bool MouseComponent::IsButtonUp(MouseButtons button) const
	{
		return GetButtonState(mCurrentState, button) == false;
	}

	bool MouseComponent::IsButtonDown(MouseButtons button) const
	{
		return GetButtonState(mCurrentState, button);
	}

	bool MouseComponent::WasButtonUp(MouseButtons button) const
	{
		return GetButtonState(mLastState, button) == false;
	}

	bool MouseComponent::WasButtonDown(MouseButtons button) const
	{
		return GetButtonState(mLastState, button);
	}

	bool MouseComponent::WasButtonPressedThisFrame(MouseButtons button) const
	{
		return (IsButtonDown(button) && WasButtonUp(button));
	}

	bool MouseComponent::WasButtonReleasedThisFrame(MouseButtons button) const
	{
		return (IsButtonUp(button) && WasButtonDown(button));
	}

	bool MouseComponent::IsButtonHeldDown(MouseButtons button) const
	{
		return (IsButtonDown(button) && WasButtonDown(button));
	}

	void MouseComponent::SetMode(MouseModes mode)
	{
		sMouse->SetMode(static_cast<Mouse::Mode>(mode));
	}

	bool MouseComponent::GetButtonState(const Mouse::State& state, MouseButtons button) const
	{
		switch (button)
		{
		case Library::MouseButtons::Left:
			return state.leftButton;

		case Library::MouseButtons::Right:
			return state.rightButton;

		case Library::MouseButtons::Middle:
			return state.middleButton;

		case Library::MouseButtons::X1:
			return state.xButton1;

		case Library::MouseButtons::X2:
			return state.xButton2;

		default:
			throw exception("Invalid MouseButtons.");
		}
	}
}