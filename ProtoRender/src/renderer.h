#pragma once

#pragma warning(disable : 4514)

#pragma warning(push)

#pragma warning(disable : 4668)
#pragma warning(disable : 4820)
#pragma warning(disable : 4625)
#pragma warning(disable : 4514)
#pragma warning(disable : 4626)
#pragma warning(disable : 4365)

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string_view>

#pragma warning(pop)

namespace ProtoRenderer
{

	using event_t = sf::Event;
	using mesh_t = sf::VertexArray;
	using text_t = sf::Text;
	using texture_t = sf::Texture;
	using texturePtr_t = const texture_t*;
	using transform_t = sf::Transform;
	using targetTexture_t = sf::RenderTexture;

	class Renderer
	{
	public:
		explicit Renderer(uint32_t windowWidth, uint32_t windowHeight, std::string_view title) noexcept;

		Renderer(const Renderer&) noexcept = delete;
		Renderer(Renderer&&) noexcept = delete;

		Renderer& operator=(const Renderer&) noexcept = delete;
		Renderer& operator=(Renderer&&) noexcept = delete;

		[[nodiscard]] bool pollEvent(event_t& event);

		[[nodiscard]] sf::Vector2<int> getMousePosition() const;

		void setTransform(const transform_t& transform);
		void setTexture(const texture_t* texture);

		void setCameraCoord(float x, float y);
		void setCameraParameters(uint32_t width, uint32_t height);
		void setCameraCoord(targetTexture_t& target, float x, float y);
		void setCameraParameters(targetTexture_t& target, uint32_t width, uint32_t height);

		void clear();
		void draw(const mesh_t& drawable);
		void draw(const text_t& drawable);
		void draw(targetTexture_t& target, const mesh_t& drawable);

		void display();

	private:
		sf::RenderWindow window;
		sf::View view;

		sf::RenderStates states;
	};

	using rendererPtr_t = std::unique_ptr<Renderer>;

}
