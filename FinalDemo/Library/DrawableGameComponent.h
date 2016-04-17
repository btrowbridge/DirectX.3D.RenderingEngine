#pragma once

#include "GameComponent.h"
#include <memory>

namespace Library
{
	class Camera;

	class DrawableGameComponent : public GameComponent
	{
		RTTI_DECLARATIONS(DrawableGameComponent, GameComponent)

	public:
		DrawableGameComponent();
		DrawableGameComponent(Game& game);
		DrawableGameComponent(Game& game, const std::shared_ptr<Camera>& camera);
		virtual ~DrawableGameComponent() = default;

		DrawableGameComponent(const DrawableGameComponent& rhs) = delete;
		DrawableGameComponent& operator=(const DrawableGameComponent& rhs) = delete;

		bool Visible() const;
		void SetVisible(bool visible);

		std::shared_ptr<Camera> GetCamera();
		void SetCamera(const std::shared_ptr<Camera>& camera);

		virtual void Draw(const GameTime& gameTime);

	protected:
		bool mVisible;
		std::shared_ptr<Camera> mCamera;
	};
}