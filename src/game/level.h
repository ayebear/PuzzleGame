// Copyright (C) 2014-2015 Eric Hebert (ayebear)
// This code is licensed under GPLv3, see LICENSE.txt for details.

#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <SFML/System/Vector2.hpp>
#include "configfile.h"
#include "OCS/Objects.hpp"

class TileMapData;
class TileMap;
class TileMapChanger;
class MagicWindow;

/*
This class holds the information for a level, and loads everything into memory from a file.
*/
class Level
{
    enum class LoadStatus
    {
        Error,
        Success,
        Finished
    };

    public:
        Level(const std::string& levelDir, TileMapData& tileMapData, TileMap& tileMap,
            TileMapChanger& tileMapChanger, ocs::ObjectManager& entities, MagicWindow& magicWindow);
        LoadStatus load(int level = -1);
        LoadStatus loadNext();
        void update();

    private:
        void sendStartPosition(sf::Vector2u& pos);
        void loadTileMap(cfg::File& config);
        void loadObjects(cfg::File& config);
        void loadSwitches(cfg::File& config);

        static const cfg::File::ConfigMap defaultOptions;
        static const int TOTAL_LEVELS;

        std::string levelDir;
        TileMapData& tileMapData; // Logical tile map
        TileMap& tileMap; // Visual tile map
        TileMapChanger& tileMapChanger;
        ocs::ObjectManager& entities;
        MagicWindow& magicWindow;

        int currentLevel;
};

#endif
