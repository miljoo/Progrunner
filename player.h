#ifndef PLAYER_H
#define PLAYER_H


class Player
{
    public:
        Player(int _x, int _y, int _dir);
        int getY();
		int getTy();
		int getX();
		int getTx();
		int getDir();
		int getMLcounter();
		int getMRcounter();
		int getMoving();

		void setY(int i);
		void setTy(int i);
		void setX(int i);
		void setTx(int i);
		void setDir(int i);
		void setMRcounter(int i);
		void setMLcounter(int i);
		void setMoving(int i);

		void decreaseMLcounter();
		void decreaseMRcounter();
		void resetcounters();
    private:
        int x, y, tx, ty;
		int dir;
		int mlcounter;
		int mrcounter;
		int moving;
};

#endif // PLAYER_H
