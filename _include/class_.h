class BLOCK
{

public:

	float rott, ii, speed_rotate, speed_b;
	float x, y;
	int live, type, rotate_start;
	bool rotate_block, rotate_where, godmode, dead;

	int Block(float, float, float, float, float, float, int);
	int RotateBlock(bool);
	int RESET();

};

BLOCK blok[48];
BLOCK player;