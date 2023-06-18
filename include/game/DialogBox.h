#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

namespace He_ARC::rpg {
    /**
    * Base class for dialog boxes
    * @author Elisa Goloviatinski
    * @version 1.0
    */
    class DialogBox {
        private:
            int currentLine = 0;
            sf::Font font;
            string fontsrc = "res/sprites/ui/monogram.ttf";
            sf::Vector2f pos = sf::Vector2f(0, 0);
            string line;
            string fileText;
            fstream dialog;
            vector<string>textList;
            sf::Text text;
            string texturesrc = "res/sprites/ui/textbox.png";
            sf::Texture texture;
            sf::Sprite sprite;
            bool enabled = false;
            bool isFirstTime = true;
        public:
            // Constructor

            /// @brief DialogBox standard parameterized constructor
            /// @param _pos position on screen in floats
            /// @param _fileText source of textfile for dialog box
            /// @param _texturesrc source for dialog box texture
            /// @param _fontsrc font used for text
            DialogBox(sf::Vector2f _pos, string _fileText, string _texturesrc = "res/sprites/ui/textbox.png", string _fontsrc = "res/sprites/ui/monogram.ttf") : pos(_pos), fileText(_fileText), texturesrc(_texturesrc), fontsrc(_fontsrc) {
                dialog.open(fileText);
                while(getline(dialog, line) ) {  
                    textList.push_back(line);
                }
                dialog.close();
                texture.loadFromFile(texturesrc);
                sprite.setTexture(texture);
                sprite.setScale(sf::Vector2f(0.5f, 0.5f));
                sprite.setPosition(pos);
                font.loadFromFile(fontsrc);
                text.setFont(font);
                text.setCharacterSize(24);
                text.setFillColor(sf::Color::White);
                text.setPosition(pos);
            }

            // SFML Getters

            /// @brief Gets current texture.
            /// @return Current loaded texture.
            sf::Texture& getTexture() { return texture; }
            /// @brief Gets current sprite.
            /// @return Current sprite.
            sf::Sprite getSprite() const { return sprite; }
            /// @brief Gets current position in float coordinates.
            /// @return Current position.
            sf::Vector2f getPos() const { return sprite.getPosition(); }
            /// @brief Gets size of dialog box texture.
            /// @return Size of dialog box.
            sf::Vector2f getSpriteSize() const {
                return sf::Vector2f(sprite.getTexture()->getSize().x * sprite.getScale().x, sprite.getTexture()->getSize().y * sprite.getScale().y);
            }
            /// @brief Checks whether box dialogue is activated or not.
            /// @return Bool variable enabled.
            bool isEnabled() const {
                return enabled;
            }

            /// @brief Gets next line for dialog box.
            /// @return If not all lines exhasuted returns true otherwise false.
            bool getNext() {
                if (currentLine < textList.size()) {
                    stringstream words(textList[currentLine]);
                    string word;
                    string line;
                    string testLine;
                    int offset = 120;
                    while (words >> word) {
                        if (isFirstTime) {
                            offset = 200;
                        }

                        testLine = line + word + " ";
            
                        text.setString(testLine);

                        if (text.findCharacterPos(testLine.size()).x > getSpriteSize().x-offset) {
                            line += word + "\n";
                        }
                        else {
                            line = testLine;
                        }
                    }

                    text.setString(line);
                    currentLine++;
                    isFirstTime = false;
                    return true;
                }
                currentLine = 0;
                return false;
            }

            // SFML Setters

            /// @brief Sets texture to use for sprite
            /// @param src Source of texture
            void setTexture(string src) { texture.loadFromFile(src); }
            /// @brief Sets part of texture to use for sprite.
            /// @param textureRect Size of cut texture.
            void setSpriteTexture(sf::IntRect textureRect) { sprite.setTextureRect(textureRect); }
            /// @brief Sets new position in float coordinates.
            /// @param pos New position to set.
            void setPos(sf::Vector2f pos) { 
                sprite.setPosition(pos); 
                setTextPos(pos);
            } 

            /// @brief Sets position of text. Is used in setPos().
            /// @param pos Float position of text.
            void setTextPos(sf::Vector2f pos) {
                text.setPosition(pos+sf::Vector2f(70,20));
            }
            
            /// @brief Sets scale of texture.
            /// @param _size New size of texture.
            void setSpriteSize(float _size) {
                sf::Vector2f size = sf::Vector2f(_size, _size);
                sprite.setScale(size);
            }

            /// @brief Sets source of new textfile to use.
            /// @param _fileText Source of textfile.
            void setTextFile(string _fileText) {
                textList.clear();
                dialog.open(_fileText);
                while(getline(dialog, line) ) {  
                    textList.push_back(line);
                }
                dialog.close();
            }

            /// @brief Sets current line of text.
            /// @param _currentLine Current line of text.
            void setLine(int _currentLine) {
                try {
                    if ((currentLine >= 0 && currentLine <= textList.size())) {
                        currentLine = _currentLine;
                    }
                    else {
                        throw "Nonvalid value";
                    }
                }
                catch(const char* nonValid) {
                    cout << nonValid << endl;
                    currentLine = 0;
                } 
            }

            void appendText(string _text) {
                textList.push_back(_text);
            }

            /// @brief Whether to dialog box should be drawable or not.
            /// @param condtion True if enabled, false otherwise.
            void enable(bool condtion) {
                enabled = condtion;
            }

            // Methods

            /// @brief Draws dialog box's sprite and text on window.
            /// @param window Window on which to draw.
            void draw(sf::RenderWindow &window) {
                window.draw(sprite);
                window.draw(text);
            }
    };
}