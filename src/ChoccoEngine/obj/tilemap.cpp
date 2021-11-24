#include <ChoccoEngine/tilemap.h>

namespace chocco {
    // constructor
    Tilemap::Tilemap(SDL_Renderer* renderer, std::string path, int clipSize, std::string name) : clipSize(clipSize), name(name) {
        baseTexture = loadTexture(renderer, path);
    }

    void Tilemap::destroy() {
        SDL_DestroyTexture(texture);
        SDL_DestroyTexture(baseTexture);
    }

    void Tilemap::loadTileMap(std::string path) {

    }

    void Tilemap::createTiles() {

    }
}
