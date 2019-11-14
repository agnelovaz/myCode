#define MAP_SIZE 10
#define PEOPLE 4

class CrowdedMaze{
public:
	virtual const char * getName() const{ return "NONE"; }
	virtual int solve(int size_x, int size_y, const char map[10][11]){ return -1; }
};

struct Users{
	static int counter;
	static CrowdedMaze* users[100];

	static int Add(CrowdedMaze* p){
		 users[counter++] = p;
		 return counter;
	}
};

#define GEN_CLASS_TOP(c,n) \
class c : public CrowdedMaze { \
	static int dummy; \
	const char * getName() const { return n; }

#define GEN_CLASS_BOT(n) };\
int n::dummy = Users::Add(new n());