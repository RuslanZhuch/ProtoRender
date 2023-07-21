#include "renderer.h"

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

void ProtoRenderer::Renderer::draw(const text_t& drawable)
{
	this->window.draw(drawable);
}

void ProtoRenderer::Renderer::display()
{
	this->window.display();
}
