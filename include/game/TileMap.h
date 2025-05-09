#pragma once

namespace He_ARC::rpg {
    /**
    * @brief Class for a tile-based game map.
    * @author SFML tutorial, tile map example
    */
    class TileMap : public sf::Drawable, public sf::Transformable {
    private:
        /// @brief Tells how to draw tilemap.
        /// @param target Tiles vertex array.
        /// @param states Texture of tileset.
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            // apply the transform
            states.transform *= getTransform();

            // apply the tileset texture
            states.texture = &m_tileset;

            // draw the vertex array
            target.draw(m_vertices, states);
        }

        sf::VertexArray m_vertices;
        sf::Texture m_tileset;
    public:
        /// @brief Loads texture and delimits in into small squares.
        /// @param tileset Source of texture.
        /// @param tileSize Size of tile.
        /// @param tiles Array of tiles to which we want to map.
        /// @param width Width of tilemap.
        /// @param height Height of tilemap.
        /// @return If managed to load texture true, otherwise false.
        bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
        {
            const float SCALE = 4.0f;

            // load the tileset texture
            if (!m_tileset.loadFromFile(tileset))
                return false;

            // resize the vertex array to fit the level size
            m_vertices.setPrimitiveType(sf::Quads);
            m_vertices.resize(width * height * SCALE); // multiplication of 4 has been added due to tileset textures being 16 bits and too small otherwise

            // populate the vertex array, with one quad per tile
            for (unsigned int i = 0; i < width; ++i)
                for (unsigned int j = 0; j < height; ++j)
                {
                    // get the current tile number
                    int tileNumber = tiles[i + j * width];

                    // find its position in the tileset texture
                    int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
                    int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

                    // get a pointer to the current tile's quad
                    sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

                    // define its 4 corners
                    quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
                    quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                    quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
                    quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

                    // define its 4 texture coordinates
                    quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                    quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                    quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                    quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
                }

            return true;
        }
    };
}