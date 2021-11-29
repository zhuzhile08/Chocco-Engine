#include <ChoccoEngine/tilemap.h>

namespace chocco {
// functions
    void Tilemap::destroy() {
        SDL_DestroyTexture(texture);
        SDL_DestroyTexture(baseTexture);
    }

// function to load a specific line in a file
    std::string Tilemap::loadFile(std::string localPath, int row) {
        int i = 1;
        std::ofstream file;
        std::string out;
        file.open("data/tiles/" + localPath, std::fstream::out);
#ifndef ndebug
        if (file.is_open()) {
            while(i <= row) {
                file << out;
                i++;
            }
        } else std::cout << "Tilemap open file error with file " << "data/tiles/" + localPath << std::endl;
#endif
#ifndef debug
        while(i <= row) {
            file << out;
            i++;
        }
#endif
        file.close();
        return out;
    }

// this is basicly the constructor
    void Tilemap::loadTileMap(std::string path, SDL_Renderer* renderer) {   // this function HAS to be called before anything else and before putting the tilemap into a group
        name = loadFile("tile.ctm", 1);
        baseTexture = loadTexture(renderer, loadFile("tile.ctm", 2));
        size.x = stoi(loadFile("tile.ctm", 3));
        size.y = stoi(loadFile("tile.ctm", 4));
        clipSize = stoi(loadFile("tile.ctm", 5));
    }

    void Tilemap::createTiles() {

    }

// getters
    std::string Tilemap::getName() {
        return name;
    }

    SDL_Texture* Tilemap::getTexture() {
        return texture;
    }
    
    Vector2 Tilemap::getSize() {
        return size;
    }
    
    int Tilemap::getClipSize() {
        return clipSize;
    }
    
}
