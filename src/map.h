#pragma once

#include <vector>
#include <glm/glm.hpp>

struct WallRef {
	int sector_nr;
	int wall_nr;
};

struct Wall {
	glm::vec2 pos;
	WallRef	next;
};


struct Sector {
	std::vector<Wall> walls;
	float floor_height;
	float ceil_height;
};


struct Location {
	glm::vec3	pos;
	int			sector;
};


class Map {
public:
	Map();
	int find_sector(const glm::vec3& pos) const;
	void clip_move(Location& loc, const glm::vec3& mov) const;
	void find_portals();

//private:

	std::vector<Sector>	sectors;

};


extern Map map;
