// Copyright (C) 2014-2015 Eric Hebert (ayebear)
// This code is licensed under GPLv3, see LICENSE.txt for details.

#ifndef TILEMAPCHANGER_H
#define TILEMAPCHANGER_H

class TileMapData;
namespace ng { class TileMap; }

/*
A simplified way to change the logical and visual tilemap simultaneously.
*/
class TileMapChanger
{
    public:
        TileMapChanger(TileMapData& tileMapData, ng::TileMap& tileMap);

        // Returns true if the state of the tile changed from this call
        bool changeState(int tileId, bool state);

        // Toggles the state of a tile
        void toggleState(int tileId);

        // Derives other tile layer information
        void updateVisualTile(int tileId);

    private:
        TileMapData& tileMapData;
        ng::TileMap& tileMap;
};

#endif
