/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TitleScene.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:17:02 by mbatty            #+#    #+#             */
/*   Updated: 2025/12/14 17:12:51 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TitleScene.hpp"
#include "Game.hpp"
#include "OptionsScene.hpp"

#include "ImprovedButton.hpp"
#include "ImprovedText.hpp"
#include "ImprovedBackgroundImage.hpp"
#include "ImprovedImage.hpp"
#include "ImprovedToggle.hpp"
#include "ImprovedTextField.hpp"
#include "ImprovedSlider.hpp"
#include "Quad.hpp"

void	TitleScene::onEnter()
{
	if (_loaded)
		return ;

	_loaded = true;
	TextureManager &textures = _game->getTextures();
	ShaderManager &shaders = _game->getShaders();

	// Scene decoration
	_panel.add("background", new ImprovedBackgroundImage(glm::vec2(REFERENCE_WIDTH, REFERENCE_HEIGHT), glm::vec2(0), glm::vec2(0), glm::vec2(1), 0.5, shaders.get("background"), textures.get(TX_PATH_DIRT)));

	_panel.add("icon", new ImprovedImage(
		glm::vec2(textures.get(TX_PATH_FT_MINECRAFT)->getWidth() * 0.3, textures.get(TX_PATH_FT_MINECRAFT)->getHeight() * 0.3),
		glm::vec2(0.5, 0.5), glm::vec2(0, -90), shaders.get("image"), textures.get(TX_PATH_FT_MINECRAFT)));

	// Options button to access options scene
	UIElement	*tmp = _panel.add("options", new ImprovedButton(glm::vec2(98, 20), glm::vec2(0.5), glm::vec2(-51, 40), shaders.get("image"), textures.get(TX_PATH_BUTTON_SMALL), textures.get(TX_PATH_BUTTON_SMALL_HIGHLIGHTED), textures.get(TX_PATH_BUTTON_SMALL_DISABLED)));
	_panel.add("options_text", new ImprovedText("Options", 1, glm::vec2(0.5), glm::vec2(-51, 40), shaders.get("font"), textures.get(TX_PATH_ASCII)));
	static_cast<ImprovedButton*>(tmp)->setClickFunc(
		[this]()
		{
			this->_requestScene(new OptionsScene(_game));
		});

	// Quit button to leave the game
	tmp = _panel.add("quit", new ImprovedButton(glm::vec2(98, 20), glm::vec2(0.5), glm::vec2(51, 40), shaders.get("image"), textures.get(TX_PATH_BUTTON_SMALL), textures.get(TX_PATH_BUTTON_SMALL_HIGHLIGHTED), textures.get(TX_PATH_BUTTON_SMALL_DISABLED)));
	_panel.add("quit_text", new ImprovedText("Quit game", 1, glm::vec2(0.5), glm::vec2(51, 40), shaders.get("font"), textures.get(TX_PATH_ASCII)));
	static_cast<ImprovedButton*>(tmp)->setClickFunc(
		[this]()
		{
			_game->setRunning(false);
		});
}

void	TitleScene::onExit()
{
}

void	TitleScene::processInput(float deltaTime)
{
	(void)deltaTime;
}

void	TitleScene::update(UIEvent events, float deltaTime)
{
	(void)deltaTime;

	_panel.handleEvents(events);
}

void	TitleScene::render()
{
	Window	&window = _game->getWindow();

	glDisable(GL_DEPTH_TEST);

	_panel.draw(window.getSize());
}
