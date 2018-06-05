#include "RenderSystem.h"



RenderSystem::RenderSystem(sf::RenderWindow &window) : win(window)
{
}


void RenderSystem::update(entityx::EntityManager & en, entityx::EventManager & ev, double dt)
{
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
