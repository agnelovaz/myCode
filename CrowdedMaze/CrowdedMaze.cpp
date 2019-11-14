#include <iostream>
#include <chrono>

#include "globals.h"

static const struct {
	int sizeX, sizeY;
	int answer;
	char map[10][11];
} maps[] = {
	{
		2, 2,
		2,
		"A.",
		"#a"
	},
	{
		4, 4,
		6,
		"A...",
		"###.",
		"###.",
		"###a"
	},
	{
		4, 4,
		-1,
		"A...",
		".##B",
		".##.",
		"b##a"
	},
	{
		4, 4,
		7,
		"...a",
		".##B",
		".##.",
		"b..A"
	},
	{
		4, 4,
		1,
		"Aa..",
		"..Bb",
		"Cc..",
		"..Dd"
	},
	{
		10, 10,
		9,
		"##########",
		"#A.a######",
		"##########",
		"###.B#####",
		"###.######",
		"###..b####",
		"######c###",
		"##C..#D###",
		"##....d###",
		"##########"
	},
	{
		10, 10,
		-1,
		"##########",
		"#A.b#....#",
		"#####....#",
		"###.B....#",
		"###......#",
		"###..a####",
		"######c###",
		"##C..#D###",
		"##....d###",
		"##########"
	},
	{
		10, 10,
		17,
		"aC.......b",
		".........D",
		"..........",
		"..........",
		"..........",
		"..........",
		"..........",
		"..........",
		"B.........",
		"d.......Ac"
	},
	{
		10, 10,
		34,
		"..........",
		".#.######.",
		".#...#.a..",
		".#.#..###.",
		".#..#...#.",
		".##.###.#.",
		".#...d#.#.",
		".##c#B#b#.",
		".##A#####.",
		"..D#C.....",
	},
	{
		10, 10,
		97,
		"aC.......b",
		".#####...D",
		"......##..",
		"#####...#.",
		".....##..#",
		".###...#..",
		"....##..#.",
		"###...#...",
		"B.###.####",
		"d.......Ac"
	},
	{
		10, 10,
		107,
		"AdBcCaDb..",
		"#########.",
		"..........",
		".#########",
		"..........",
		"#########.",
		"..........",
		".#########",
		".#...#....",
		"...#......",
	},
	{
		10, 10,
		-1,
		"a#.......B",
		"#A......c.",
		"..........",
		"..........",
		"..........",
		"..........",
		"..........",
		"..........",
		".d......D.",
		"C........b",
	}
};

#ifdef WIN32
int main()
#else
int main(int argc, const char * argv[])
#endif //  WIN32
{
	//Send the map to the user's implementations for solving
	for (int u = 0; u < sizeof(Users::users) / sizeof(Users::users[0]); u++)
	{
		if (!Users::users[u]) continue;
		std::cout << "User: " << Users::users[u]->getName() << std::endl;
		std::chrono::system_clock::time_point global_start = std::chrono::system_clock::now(); //Start measuring
		for (int t = 0; t < sizeof(maps) / sizeof(maps[0]); t++)
		{
			std::chrono::system_clock::time_point start = std::chrono::system_clock::now(); //Start measuring
			int res = Users::users[u]->solve(maps[t].sizeX, maps[t].sizeY, maps[t].map);
			std::chrono::duration<double> time = std::chrono::system_clock::now() - start;//End measuring

			//Check result
			if (maps[t].answer != 0 && res != maps[t].answer){
				time = std::chrono::seconds(1000);
				global_start -= std::chrono::seconds(1000);
			}

			
			std::cout << "\t Test " << t << ", Result: " << res << "\tTime: " << time.count() << std::endl;
		}
		std::chrono::duration<double> global_time = std::chrono::system_clock::now() - global_start;//End measuring
		std::cout << "\t" << Users::users[u]->getName() << "\t Total time : " << global_time.count() << std::endl << std::endl;
	}
	
	return 0;//Your program should return 0 on normal termination.
}