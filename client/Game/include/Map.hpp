//
// Created by alex on 1/17/18.
//

#ifndef DISPLAYTESTS_MAP_HPP
#define DISPLAYTESTS_MAP_HPP

#include <vector>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "MapTile.hpp"

namespace UgandaEngine {
	class Map : public sf::Drawable {
	public:
		Map();
		~Map() = default;

		void createMap(const std::string &file);
		void loadMapTile(const std::string &file);

		void 			setBgTexture(const std::string&);

		void 			draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:
		std::vector<MapTile>	_mapTiles;
		std::vector<std::vector<MapTile> > _map;
		std::shared_ptr<sf::Texture>	_bgTexture;
		sf::Sprite		_bgSprite;
	};
}

#endif /* DISPLAYTESTS_MAP_HPP */
