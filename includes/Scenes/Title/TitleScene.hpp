/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TitleScene.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:11:46 by mbatty            #+#    #+#             */
/*   Updated: 2025/12/14 17:13:00 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TITLESCENE_HPP
# define TITLESCENE_HPP

# include "Scene.hpp"
# include "UIElement.hpp"

# include "Panel.hpp"

class TitleScene : public Scene
{
	public:
		TitleScene(Game *game) : Scene(game)
		{
			_id = "TitleScene";
			_keepAlive = true;
		}
		~TitleScene() {};

		void onEnter();

		void processInput(float deltaTime);
		void update(UIEvent events, float deltaTime);
		void render();

		void onExit();

	private:
		Panel		_panel;
};

#endif
