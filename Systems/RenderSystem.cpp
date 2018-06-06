#include "RenderSystem.h"



RenderSystem::RenderSystem(sf::RenderWindow &window) : win(window)
{
}


void RenderSystem::update(entityx::EntityManager & en, entityx::EventManager & ev, double dt)
{
	Circle::Handle circle;
	Rectangle::Handle rect;
	Position::Handle pos;
	Rotation::Handle rot;

	for (auto entity : en.entities_with_components(circle, pos, rot)) {
		sf::CircleShape cir;
		cir.setRadius(circle->radius);
		cir.setFillColor(circle->color);
		cir.setOrigin(circle->radius, circle->radius);
		cir.setPosition(pos->pos);
		cir.setRotation(rot->rot);

		win.draw(cir);
	}

	for (auto entity : en.entities_with_components(rect, pos, rot)) {
		sf::RectangleShape rectangle;
		rectangle.setSize(rect->dimensions);
		rectangle.setFillColor(rect->color);
		rectangle.setOrigin(rect->dimensions.x / 2.0, rect->dimensions.y / 2.0);
		rectangle.setPosition(pos->pos);
		rectangle.setRotation(rot->rot);

		win.draw(rectangle);
	}

	/*****Example*****

	backgroundTexture::Handle backgroundTH;

	PolyName::Handle nameHandle;
	Transform::Handle trans;
	VertexArray::Handle vArray;

	//first render background
	for (auto entity : en.entities_with_components(backgroundTH))
	{
		sf::Sprite sprite;
		sprite.setTexture(*backgroundTH->texture);
		sprite.setPosition(backgroundTH->pos);
		sprite.setScale(backgroundTH->scale);
		sprite.setRotation(backgroundTH->rotation);
		sprite.setColor(sf::Color(255,255,255,backgroundTH->alphaTexture));

		win.draw(sprite);
	}

	for (auto entity : en.entities_with_components(vArray, trans, nameHandle))
	{
		if (ResourcesManager::getInstanceRef().textureCont.isTexture(nameHandle->name))
		{
		trans = entity.component<Transform>();
		
		sf::RenderStates renderStates;
		auto &texture = ResourcesManager::getInstanceRef().textureCont.getTexture(nameHandle->name);

		renderStates.texture = &texture;
		renderStates.transform = trans->trans;

		win.draw(vArray->vert, renderStates);
		}
		else
		{
			win.draw(vArray->vert, trans->trans);
		}
	}
	*/

}

RenderSystem::~RenderSystem()
{
}
