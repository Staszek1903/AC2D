#pragma once

#include "LibsAndDeclarations.h"
#include "GameStage.h"

class MenuStage : public GameStage
{
public:
	MenuStage();
	MenuStage(const MenuStage&) = delete;
	MenuStage& operator=(const MenuStage&) = delete;
	virtual ~MenuStage();

private:
	sf::Font font;
	sf::Text message;

public:
	virtual bool init() override;
	virtual bool update(float dt) override;
	virtual void input(sf::Event &) override;
	virtual void render(sf::RenderWindow &window) override;
//	virtual void draw(sf::RenderWindow &window) override;
	virtual void release() override;
};
