#include "game/DialogBox.h"

namespace He_ARC::rpg {
    // Setters

    /// @brief Sets source of new textfile to use.
    /// @param _fileText Source of textfile.
    void DialogBox::setTextFile(string _fileText) {
        textList.clear();
        dialog.open(_fileText);
        while(getline(dialog, line) ) {  
            textList.push_back(line);
        }
        dialog.close();
    }
    
    /// @brief Sets current line of text.
    /// @param _currentLine Current line of text.
    void DialogBox::setLine(int _currentLine) {
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
    
    // Method

    /// @brief Draws dialog box's sprite and text on window.
    /// @param window Window on which to draw.
    void DialogBox::draw(sf::RenderWindow &window) {
        window.draw(sprite);
        window.draw(text);
    }
}