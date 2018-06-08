#include "RenderSystem.h"
#include "ResourcesManager.h"


RenderSystem::RenderSystem(sf::RenderWindow &window) : win(window)
{
}


void RenderSystem::update(entityx::EntityManager & en, entityx::EventManager & ev, double dt)
{
	auto & rM = ResourcesManager::getInstanceRef();

	Shape::Handle shape;
	SpriteShape::Handle sprite;
	CircleShape::Handle circle;
	RectangleShape::Handle rect;

	Position::Handle pos;
	Rotation::Handle rot;

	for (auto entity : en.entities_with_components(sprite, pos, rot)) {
		sf::Sprite shape;
		shape.setTexture(sprite->texture);
		shape.setPosition(pos->pos);
		shape.setRotation(rot->rot);
		shape.setOrigin(sprite->texture.getSize().x / 2.0, sprite->texture.getSize().y / 2.0);

		win.draw(shape);
	}


	for (auto entity : en.entities_with_components(shape, pos, rot)) {
		sf::Transform trans;
		trans.translate(pos->pos);
		trans.rotate(rot->rot);
		//trans.scale(sf::Vector2f(50, 50));

		sf::RenderStates state;
		state.texture = &shape->texture;
		state.transform = trans;

		win.draw(shape->v, state);
	}


	for (auto entity : en.entities_with_components(circle, pos, rot)) {
		sf::CircleShape cir;
		cir.setRadius(circle->radius);
		cir.setFillColor(circle->color);
		cir.setOrigin(circle->radius, circle->radius);
		cir.setPosition(pos->pos);
		cir.setRotation(rot->rot);
		cir.setPointCount(circle->pointCount);
		cir.setTexture(circle->texture);

		win.draw(cir);
	}

	for (auto entity : en.entities_with_components(rect, pos, rot)) {
		sf::RectangleShape rectangle;
		rectangle.setSize(rect->dimensions);
		rectangle.setFillColor(rect->color);
		rectangle.setOrigin(rect->dimensions.x / 2.0, rect->dimensions.y / 2.0);
		rectangle.setPosition(pos->pos);
		rectangle.setRotation(rot->rot);
		rectangle.setTexture(rect->texture);

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
