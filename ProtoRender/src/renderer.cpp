#include "renderer.h"

ProtoRenderer::Renderer::Renderer(uint32_t windowWidth, uint32_t windowHeight, std::string_view title) noexcept
	:
	window(sf::VideoMode(windowWidth, windowHeight), title.data())
{

	this->view.setCenter({});
	this->view.setSize({ static_cast<float>(windowWidth), static_cast<float>(windowHeight) });
	this->window.setView(this->view);

}

void ProtoRenderer::Renderer::clear()
{
	this->window.clear();
}

void ProtoRenderer::Renderer::draw(const mesh_t& drawable)
{
	this->window.draw(drawable, this->states);
}

bool ProtoRenderer::Renderer::pollEvent(event_t& event)
{
	return this->window.pollEvent(event);
}

sf::Vector2<int> ProtoRenderer::Renderer::getMousePosition() const
{
	return sf::Mouse::getPosition(this->window);
}

void ProtoRenderer::Renderer::setTransform(const transform_t& transform)
{
	this->states.transform = transform;
}

void ProtoRenderer::Renderer::setTexture(texture_t* texture)
{
	this->states.texture = texture;
}

void ProtoRenderer::Renderer::setCameraCoord(float x, float y)
{
	this->view.setCenter(x, y);
	this->window.setView(this->view);
}

void ProtoRenderer::Renderer::draw(const text_t& drawable)
{
	this->window.draw(drawable);
}

void ProtoRenderer::Renderer::display()
{
	this->window.display();
}
