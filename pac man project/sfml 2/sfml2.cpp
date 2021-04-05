#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
#include<sstream>
#include<windows.h>
using namespace sf;
using namespace std;

void common_move(Sprite &gost, int &dir);
void chaser_move(int &x, int &y, char map[100][100], Sprite &enemy1, Sprite &pacman, bool &right, bool &left, bool &up, bool &down);
void ransom_move(int x, int y, char map[100][100], Sprite &enemy,int dir,bool &right,bool &left,bool &up,bool &down);
void ransom_move2(int x, int y, char map[100][100], Sprite &enemy, int dir, bool &right, bool &left, bool &up, bool &down);

void pass_move(int &x, int &y, char map[100][100], Sprite &enemy3);
void convert_blue(Sprite &pacman, Sprite &enemy1, Sprite &enemy2, Sprite &enemy3, Sprite &enemy4, bool &color);
void pcaman_move(Sprite &pacman, char map[100][100], Text &score, ostringstream &sscore, int x1, int y1, Sprite &enemy1, Sprite &enemy2,
	Sprite &enemy3, Sprite &enemy4, Sound &sound, int &counter_point);
void break0(int &x, int &y, char map[100][100], Sprite &enemy1, Sprite &pacman);
int counter_point = 0; bool point = false; bool _return = false; int increase;
bool lchaser = false, rchaser = false, dchaser= false, uchaser = false;//chaser
bool lpacman = false, rpacman = false, dpacman = false, upacman = false;//pacman
bool lenemy3 = false, renemy3 = false, denemy3 = false, uenemy3 = false;//enemy 3
bool lenemy2 = false, renemy2 = false, uenemy2 = false, denemy2 = false;//2 enemyb
bool lenemy4 = false, renemy4 = false, uenemy4 = false, denemy4 = false;
bool e1 = false, e2 = false, e3 = false, e4 = false;
bool direction = false, ghost2 = false;
bool food = false, enmey1_intersect = false, enmey2_intersect = false, enmey3_intersect = false, enmey4_intersect = false;
int n, t, ttime, time1, time3 = 0, ghost_return = 10, ghost = 0;
bool color = false;
int counterTIME = 0, counter_ghost = 2, ghostNUMBER = 1;
int m1 = 0; int score1 = 0; bool m5 = false, m2 = false;
bool position1 = false, position2 = false;
bool intersect_pacman = false, intersect_enemy = false;
bool ready_bool = false; int chaser_random_move = 0; bool chaser_rand = false;
int eat = 0;
int increce = 0, increase1 = 0, increase2 = 0, increase3 = 0;
bool star = false,s1=false; int ch = 0,v=0;
bool l1=false, l2=false, l3=false, l4=false;
void level3(){
	int dd, cc;    int n, x, y, x1, y1, x2, y2, x3, y3, di, x4, y4; int f = 0, e = 0;
	int time_ghost = 5, counter_chaseer = 0;     int counter_lives = 0; int counter_point = 0;
	char map[100][100] = {
		"#########################################",
		"#                                       #",
		"#                                       #",
		"#                                       #",
		"#                                       #",
		"#                                       #",
		"#                                       #",
		"#                                       #",
		"#                                       #",
		"#                                       #",
		"#                                       #",
		"#                                       #",
		"#                                       #",
		"#                                       #",
		"#                                       #",
		"#                ###**###               #",
		"#                #>>++<<#               #",
		"#                #>>++<<#               #",
		"                 ########               @",
		"#                                       #",
		"#                                       #",
		"#                                       #",
		"#                                       #",
		"#                                       #",
		"#                                       #",
		"#                                       #",
		"#                                       #",
		"#                                       #",
		"#                                       #",
		"#                                       #",
		"#                                       #",
		"#                                       #",
		"#                                       #",
		"#                                       #",
		"#                                       #",
		"#                                       #",
		"#                                       #",
		"#########################################"
	};

	RenderWindow startgame(VideoMode(1000, 700), "PAC MAN", Style::Fullscreen);

	View view2(FloatRect(0, -2, 45, 40));

	startgame.setFramerateLimit(9);
	Event event;

	Texture enemy, p1, pac, enemyc, c1, c2, w;

	pac.loadFromFile("pacman.png"); enemy.loadFromFile("evils.png"); p1.loadFromFile("plate5.png");
	c2.loadFromFile("coin2.png");  c1.loadFromFile("coin.png"); w.loadFromFile("white.png");
	Sprite enemy1(enemy), plate(p1), pacman(pac), enemy3(enemy), coin(c1), coin2(c2), enemy2(enemy), enemy4(enemy), white(w), live1(pac),
		live2(pac), live3(pac);
	plate.setTextureRect(IntRect(0, 0, 32, 10)); plate.setScale(0.0325, 0.0925); white.setScale(0.0145, 0.0200);
	pacman.setTextureRect(IntRect(0, 0, 32, 32)); pacman.setScale(0.0400, 0.0300); pacman.setPosition(1, 1);
	enemy1.setPosition(20, 14); enemy1.setScale(0.0400, 0.0400); enemy2.setPosition(20, 16); enemy2.setScale(0.0400, 0.0400);
	enemy3.setPosition(22, 16); enemy3.setScale(0.0400, 0.0400); enemy4.setPosition(18, 16); enemy4.setScale(0.0400, 0.0400);
	coin.setScale(0.0100, 0.0100); coin2.setScale(0.0100, 0.0100);
	live1.setTextureRect(IntRect(0, 0, 32, 32)); live1.setPosition(42, 1); live1.setScale(0.0800, 0.0700);
	live2.setTextureRect(IntRect(0, 0, 32, 32)); live2.setPosition(42, 4); live2.setScale(0.0800, 0.0700);
	live3.setTextureRect(IntRect(0, 0, 32, 32)); live3.setPosition(42, 7); live3.setScale(0.0800, 0.0700);
	Time ttime;     Clock clock;    Font arial;  arial.loadFromFile("arial.ttf");
	int p = 0;

	ostringstream sscore, gghost, rgost, ss, ggameover;
	sscore << "Score : " << score1; gghost << "GHOST " << counter_ghost << " : " << time_ghost;
	rgost << "GHOST: " << ghost_return; ss << "Time : " << 0;

	Text score, time1, gameover, youwin, ghost22, ghost33, ready, level3, _continue, _break;
	score.setCharacterSize(30); score.setPosition(0, -2); score.setScale(0.06, 0.06);
	score.setFont(arial); score.setString(sscore.str()); score.setFillColor(Color::Yellow);

	ghost22.setCharacterSize(30); ghost22.setPosition(15, -2); ghost22.setScale(0.06, 0.06);
	ghost22.setFillColor(Color::Yellow); ghost22.setFont(arial); ghost22.setString(gghost.str());
	ghost33.setCharacterSize(30); ghost33.setPosition(15, -2); ghost33.setScale(0.06, 0.06);
	ghost33.setFillColor(Color::Yellow); ghost33.setFont(arial); ghost33.setString(rgost.str());

	time1.setCharacterSize(30); time1.setPosition(30, -2); time1.setScale(0.06, 0.06);
	time1.setFillColor(Color::Red); time1.setFont(arial); time1.setString(ss.str());

	gameover.setCharacterSize(80); gameover.setPosition(7, 11); gameover.setScale(0.05, 0.07);
	gameover.setFillColor(Color::Red); gameover.setFont(arial); gameover.setString("G A M E  O V E R !!");

	ready.setCharacterSize(80); ready.setPosition(6, 11); ready.setScale(0.07, 0.07);
	ready.setFillColor(Color::Green); ready.setFont(arial); ready.setString("R E A D Y !!");

	level3.setCharacterSize(80); level3.setPosition(6, 1); level3.setScale(0.07, 0.07);
	level3.setFillColor(Color::Yellow); level3.setFont(arial); level3.setString("LEVEL:3");

	youwin.setCharacterSize(80); youwin.setPosition(7, 11); youwin.setScale(0.05, 0.07);
	youwin.setFillColor(Color::Green); youwin.setFont(arial); youwin.setString("Y O U  W I N");

	_break.setCharacterSize(80); _break.setPosition(1, 11); _break.setScale(0.0280, 0.05);
	_break.setFillColor(Color::Green); _break.setFont(arial); _break.setString("Press Esc button to back to the main menu");

	_continue.setCharacterSize(80); _continue.setPosition(1, 1); _continue.setScale(0.04, 0.05);
	_continue.setFillColor(Color::Green); _continue.setFont(arial); _continue.setString("Press Enter button to continue ");

	Music music;
	music.openFromFile("8d82b5_Pacman_Siren_Sound_Effect.wav");

	Sound sound, sound1, sound2, sound3;
	SoundBuffer soundbuffer, soundbuffer1, soundbuffer2;
	soundbuffer.loadFromFile("dp_superpac_wakka.wav");
	soundbuffer1.loadFromFile("pac-man-intro.wav");
	soundbuffer2.loadFromFile("kill.wav");
	sound.setBuffer(soundbuffer);
	sound1.setBuffer(soundbuffer1);
	sound2.setBuffer(soundbuffer2);
	music.setLoop(true);
	music.play();
	while (startgame.isOpen()){
		if (color == false){
			enemy1.setTextureRect(IntRect(0 * 32, 0, 32, 32));
			enemy2.setTextureRect(IntRect(4 * 32, 0, 32, 32));
			enemy3.setTextureRect(IntRect(2 * 32, 0, 32, 32));
			enemy4.setTextureRect(IntRect(6 * 32, 0, 32, 32));
		}

		startgame.setView(view2);
		srand(time(NULL));
		convert_blue(pacman, enemy1, enemy2, enemy3, enemy4, color);

		if (color == true){
			ghost++;  rgost.str("");  rgost << "GHOST: " << ghost_return; ghost33.setString(rgost.str());

			if (ghost == 11){ ghost = 0;  ghost_return--; }

			if (ghost_return == 0){
				color = false;  enmey1_intersect = false; enmey2_intersect = false;
				enmey4_intersect = false;  enmey3_intersect = false;    ghost_return = 10; increce = 0; increase1 = 0; increase2 = 0; increase3 = 0;
			}
		}

		ttime = clock.getElapsedTime();  ss.str("");  time3 = ttime.asSeconds();  ss << "Time : " << time3;   time1.setString(ss.str());
		counterTIME++;
		if (counterTIME == 11 && time_ghost != 0){
			time_ghost = time_ghost - 1;   gghost.str("");
			gghost << "GHOST " << counter_ghost << " : " << time_ghost; ghost22.setString(gghost.str()); counterTIME = 0;
		}
		while (startgame.pollEvent(event)){
			if (event.type == Event::Closed){

				startgame.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape)){
				_return = true;
				startgame.clear();
				startgame.draw(_break);
				startgame.draw(_continue);
				startgame.display();

			}
			if (Keyboard::isKeyPressed(Keyboard::Escape) && _return == true){
				startgame.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Return)){
				_return = false;
			}
			if (_return == false){
				if (Keyboard::isKeyPressed(Keyboard::Right)){ rpacman = true; lpacman = false; dpacman = false; upacman = false; }
				if (Keyboard::isKeyPressed(Keyboard::Left)){ rpacman = false; lpacman = true; dpacman = false; upacman = false; }
				else if (Keyboard::isKeyPressed(Keyboard::Up)){ rpacman = false; lpacman = false; dpacman = false; upacman = true; }
				else if (Keyboard::isKeyPressed(Keyboard::Down)){ rpacman = false; lpacman = false; dpacman = true; upacman = false; }

			}
		}
		if (_return == false){

			x1 = pacman.getPosition().x; y1 = pacman.getPosition().y;
			pcaman_move(pacman, map, score, sscore, x1, y1, enemy1, enemy2, enemy3, enemy4, sound, counter_point);

			x1 = pacman.getPosition().x;      y1 = pacman.getPosition().y;
			x = enemy1.getPosition().x;       y = enemy1.getPosition().y;
			x2 = enemy3.getPosition().x;      y2 = enemy3.getPosition().y;
			x3 = enemy2.getPosition().x;      y3 = enemy2.getPosition().y;
			x4 = enemy4.getPosition().x;      y4 = enemy4.getPosition().y;
			chaser_random_move++;
			if (chaser_random_move == 440){
				chaser_rand = true;
				chaser_random_move = 0;
			}

			if (color == false && chaser_rand == false){
				chaser_move(x, y, map, enemy1, pacman, rchaser, lchaser, uchaser, dchaser);
			}
			if (ghostNUMBER >= 3 && color == false && chaser_rand == false){ chaser_move(x3, y3, map, enemy2, pacman, renemy2, lenemy2, uenemy2, denemy2); }
			else if ((color == true || chaser_rand == true) && ghostNUMBER >= 3){ ransom_move2(x3, y3, map, enemy2, dd, renemy2, lenemy2, uenemy2, denemy2);; }


			if (color == true || chaser_rand == true){
				ransom_move2(x, y, map, enemy1, cc, rchaser, lchaser, uchaser, dchaser);
			}
			if (chaser_rand == true && chaser_random_move == 220){
				chaser_rand = false;
				chaser_random_move = 0;
			}
			dd = rand() % 4 + 1;
			cc = rand() % 4 + 1;

			if (time_ghost == 0){ ghostNUMBER++;     counter_ghost++;   time_ghost = 5; }
			if (ghostNUMBER >= 2){ ransom_move(x2, y2, map, enemy3, cc, renemy4, lenemy4, uenemy4, denemy4); }
			if (ghostNUMBER >= 4){ ransom_move(x4, y4, map, enemy4, cc, renemy3, lenemy3, uenemy3, denemy3); }


			startgame.clear();
			if (((pacman.getPosition().x == enemy1.getPosition().x&&pacman.getPosition().y == enemy1.getPosition().y) ||
				(pacman.getPosition().x == enemy2.getPosition().x&&pacman.getPosition().y == enemy2.getPosition().y) ||
				(pacman.getPosition().x == enemy3.getPosition().x&&pacman.getPosition().y == enemy3.getPosition().y) ||
				(pacman.getPosition().x == enemy4.getPosition().x&&pacman.getPosition().y == enemy4.getPosition().y)) && color == false){
				intersect_enemy = true;
			}
			if (ready_bool == false){
				startgame.draw(ready);
				startgame.draw(level3);
				sound1.play();
				startgame.display();
				Sleep(4000);
				ready_bool = true;
			}
			if ((intersect_enemy || intersect_pacman) && counter_lives == 3){
				startgame.draw(gameover);
				sound2.play();
				startgame.display();
				Sleep(4000);
				break;
			}
			if (counter_point == 412){
				point = true;
			}
			if (point){
				startgame.draw(youwin);
				startgame.display();
				Sleep(3000);
				break;
			}

			if (intersect_enemy || intersect_pacman){

				Sleep(2000);
				enemy1.setPosition(20, 14);
				enemy3.setPosition(22, 16);
				enemy2.setPosition(20, 16);
				enemy4.setPosition(18, 16);
				pacman.setPosition(1, 1);
				counter_ghost = 2;
				time_ghost = 3;
				ghostNUMBER = 1;
				counterTIME = 0;
				intersect_enemy = false;
				intersect_pacman = false;
				chaser_random_move = 0;
				counter_lives++;
			}

			for (int i = 0; i < 100; i++){
				for (int j = 0; j < 100; j++){
					if (map[i][j] == '#'){ plate.setPosition(j, i);  startgame.draw(plate); }
					else if (map[i][j] == '.'){ coin.setPosition(j, i);    startgame.draw(coin); }
					else if ((map[i][j] == '@' || map[i][j] == '3') && ghostNUMBER >= 4){ coin2.setPosition(j, i);     startgame.draw(coin2); }
					else if (map[i][j] == '*'){ white.setPosition(j, i);     startgame.draw(white); }

				}
			}

			startgame.draw(pacman);    startgame.draw(enemy1);   startgame.draw(enemy3);   startgame.draw(enemy2);
			startgame.draw(enemy4);    startgame.draw(coin);     startgame.draw(score); startgame.draw(time1);
			if (counter_ghost < 5){
				startgame.draw(ghost22);
			}

			if (color){
				startgame.draw(ghost33);
			}
			if (counter_lives == 0){
				startgame.draw(live1);
				startgame.draw(live2);
				startgame.draw(live3);
			}
			else if (counter_lives == 1){
				startgame.draw(live1);
				startgame.draw(live2);

			}
			else if (counter_lives == 2){
				startgame.draw(live1);
			}


			startgame.display();

		}
	}
}
void level2(){
	int dd, cc;    int n, x, y, x1, y1, x2, y2, x3, y3, di, x4, y4; int f = 0, e = 0;
	int time_ghost = 5, counter_chaseer = 0;     int counter_lives = 0; int counter_point = 0;
	char map[100][100] = {
		"#########################################",
		"#@........4........x x........X........@#",
		"#.########.########.#.########.########.#",
		"#.#      #.#      #.#.#      #.#      #.#",
		"#.#      #.#      #.#.#      #.#      #.#",
		"#.#      #.#      #X X#      #.#      #.#",
		"#.#      #.#      #.#.#      #.#      #.#",
		"#.########.########.#.########.########.#",
		"#2........1....X...x#x...X....x........x#",
		"#.########.####.#########.####.########.#",
		"#.#      #.#  #x...x#x...x#  #.#      #.#",
		"#.########.#  #####.#.#####  #.########.#",
		"#X....x...x#      #.#.#      #x...X....x#",
		"#.#### ### ########.#.######## ### ######",
		"#x....x...x.X......xxx......x.x...x....x#",
		"#.########.#.# # ###**### ##.#.########.#",
		"#.#      #.#.# # #>>++<<# ##.#.#      #.#",
		"#.########.#.# # #>>++<<# ##.#.########.#",
		" x........x#.# # ######## ##.#x........x@",
		"#.########.#.................#.########.#",
		"#.###### #.#.###############.#.# ######.#",
		"#X....x# #.#X...............X#.# #x....x#",
		"###### ### # ############### #.### ######",
		"#x....x...x X......X X......X.x...x....x#",
		"#.########.########.#.########.########.#",
		"#.###### #.########.#.########.# ######.#",
		"#X....x# #x        x#x        x# #x....x#",
		"######.# #.###################.# #.######",
		"#    #.# #x........x#x........x# #.#    #",
		"#    #.# #.########.#.########.# #.#    #",
		"###### ### ########.#.######## ### ######",
		"#x....x...x........X X........x...x....x#",
		"#.########.###################.########.#",
		"#.#      #.#                 #.#      #.#",
		"#.#      #.#                 #.#      #.#",
		"#.########.###################.########.#",
		"#@........x...................X........@#",
		"#########################################"
	};

	RenderWindow startgame(VideoMode(1000, 700), "PAC MAN",Style::Fullscreen);

	View view2(FloatRect(0, -2, 45, 40));

	startgame.setFramerateLimit(9);
	Event event;

	Texture enemy, p1, pac, enemyc, c1, c2, w;

	pac.loadFromFile("pacman.png"); enemy.loadFromFile("evils.png"); p1.loadFromFile("plate5.png");
	c2.loadFromFile("coin2.png");  c1.loadFromFile("coin.png"); w.loadFromFile("white.png");
	Sprite enemy1(enemy), plate(p1), pacman(pac), enemy3(enemy), coin(c1), coin2(c2), enemy2(enemy), enemy4(enemy), white(w), live1(pac),
		live2(pac), live3(pac);
	plate.setTextureRect(IntRect(0, 0, 32, 10)); plate.setScale(0.0325, 0.0925); white.setScale(0.0145, 0.0200);
	pacman.setTextureRect(IntRect(0, 0, 32, 32)); pacman.setScale(0.0400, 0.0300); pacman.setPosition(1, 1);
	enemy1.setPosition(20, 14); enemy1.setScale(0.0400, 0.0400); enemy2.setPosition(20, 16); enemy2.setScale(0.0400, 0.0400);
	enemy3.setPosition(22, 16); enemy3.setScale(0.0400, 0.0400); enemy4.setPosition(18, 16); enemy4.setScale(0.0400, 0.0400);
	coin.setScale(0.0100, 0.0100); coin2.setScale(0.0100, 0.0100);
	live1.setTextureRect(IntRect(0, 0, 32, 32)); live1.setPosition(42, 1); live1.setScale(0.0800, 0.0700);
	live2.setTextureRect(IntRect(0, 0, 32, 32)); live2.setPosition(42, 4); live2.setScale(0.0800, 0.0700);
	live3.setTextureRect(IntRect(0, 0, 32, 32)); live3.setPosition(42, 7); live3.setScale(0.0800, 0.0700);
	Time ttime;     Clock clock;    Font arial, RAVIE;  arial.loadFromFile("arial.ttf"); RAVIE.loadFromFile("RAVIE.ttf");
	int p = 0;

	ostringstream sscore, gghost, rgost, ss, ggameover;
	sscore << "Score : " << score1; gghost << "GHOST " << counter_ghost << " : " << time_ghost;
	rgost << "GHOST: " << ghost_return; ss << "Time : " << 0;

	Text score, time1, gameover, youwin, ghost22, ghost33, ready, level3,_continue, _break;
	score.setCharacterSize(30); score.setPosition(0, -2); score.setScale(0.06, 0.06);
	score.setFont(arial); score.setString(sscore.str()); score.setFillColor(Color::Yellow);

	ghost22.setCharacterSize(30); ghost22.setPosition(15, -2); ghost22.setScale(0.06, 0.06);
	ghost22.setFillColor(Color::Yellow); ghost22.setFont(arial); ghost22.setString(gghost.str());
	ghost33.setCharacterSize(30); ghost33.setPosition(15, -2); ghost33.setScale(0.06, 0.06);
	ghost33.setFillColor(Color::Yellow); ghost33.setFont(arial); ghost33.setString(rgost.str());

	time1.setCharacterSize(30); time1.setPosition(30, -2); time1.setScale(0.06, 0.06);
	time1.setFillColor(Color::Red); time1.setFont(arial); time1.setString(ss.str());

	gameover.setCharacterSize(80); gameover.setPosition(7, 11); gameover.setScale(0.05, 0.07);
	gameover.setFillColor(Color::Red); gameover.setFont(arial); gameover.setString("G A M E  O V E R !!");

	ready.setCharacterSize(80); ready.setPosition(6, 11); ready.setScale(0.07, 0.07);
	ready.setFillColor(Color::Green); ready.setFont(RAVIE); ready.setString("READY!!");

	level3.setCharacterSize(80); level3.setPosition(6, 1); level3.setScale(0.07, 0.07);
	level3.setFillColor(Color::Yellow); level3.setFont(RAVIE); level3.setString("LEVEL:3");

	youwin.setCharacterSize(80); youwin.setPosition(7, 11); youwin.setScale(0.05, 0.07);
	youwin.setFillColor(Color::Green); youwin.setFont(arial); youwin.setString("Y O U  W I N");

	_break.setCharacterSize(80); _break.setPosition(1, 11); _break.setScale(0.0280, 0.05);
	_break.setFillColor(Color::Green); _break.setFont(arial); _break.setString("Press Esc button to back to the main menu");

	_continue.setCharacterSize(80); _continue.setPosition(1, 1); _continue.setScale(0.04, 0.05);
	_continue.setFillColor(Color::Green); _continue.setFont(arial); _continue.setString("Press Enter button to continue ");

	Music music;
	music.openFromFile("8d82b5_Pacman_Siren_Sound_Effect.wav");

	Sound sound, sound1, sound2, sound3;
	SoundBuffer soundbuffer, soundbuffer1, soundbuffer2;
	soundbuffer.loadFromFile("dp_superpac_wakka.wav");
	soundbuffer1.loadFromFile("pac-man-intro.wav");
	soundbuffer2.loadFromFile("kill.wav");
	sound.setBuffer(soundbuffer);
	sound1.setBuffer(soundbuffer1);
	sound2.setBuffer(soundbuffer2);
	music.setLoop(true);
	music.play();
	while (startgame.isOpen()){
		if (color == false){
			enemy1.setTextureRect(IntRect(0 * 32, 0, 32, 32));
			enemy2.setTextureRect(IntRect(4 * 32, 0, 32, 32));
			enemy3.setTextureRect(IntRect(2 * 32, 0, 32, 32));
			enemy4.setTextureRect(IntRect(6 * 32, 0, 32, 32));
		}
		
		startgame.setView(view2);
		srand(time(NULL));
		convert_blue(pacman, enemy1, enemy2, enemy3, enemy4, color);

		if (color == true){
			ghost++;  rgost.str("");  rgost << "GHOST: " << ghost_return; ghost33.setString(rgost.str());

			if (ghost == 11){ ghost = 0;  ghost_return--; }

			if (ghost_return == 0){
				color = false;  enmey1_intersect = false; enmey2_intersect = false;
				enmey4_intersect = false;  enmey3_intersect = false;    ghost_return = 10; increce = 0; increase1 = 0; increase2 = 0; increase3 = 0;
			}
		}

		ttime = clock.getElapsedTime();  ss.str("");  time3 = ttime.asSeconds();  ss << "Time : " << time3;   time1.setString(ss.str());
		counterTIME++;
		if (counterTIME == 11 && time_ghost != 0){
			time_ghost = time_ghost - 1;   gghost.str("");
			gghost << "GHOST " << counter_ghost << " : " << time_ghost; ghost22.setString(gghost.str()); counterTIME = 0;
		}
		while (startgame.pollEvent(event)){
			if (event.type == Event::Closed){
				
				startgame.close();	
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape)){
				_return = true;
				startgame.clear();
				startgame.draw(_break);
				startgame.draw(_continue);
				startgame.display();
				
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape) && _return == true){
				startgame.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Return)){
				_return = false;
			}
			if (_return == false){
					if (Keyboard::isKeyPressed(Keyboard::Right)){ rpacman = true; lpacman = false; dpacman = false; upacman = false; }
					if (Keyboard::isKeyPressed(Keyboard::Left)){ rpacman = false; lpacman = true; dpacman = false; upacman = false; }
					else if (Keyboard::isKeyPressed(Keyboard::Up)){ rpacman = false; lpacman = false; dpacman = false; upacman = true; }
					else if (Keyboard::isKeyPressed(Keyboard::Down)){ rpacman = false; lpacman = false; dpacman = true; upacman = false; }
				
			}
		}
			if (_return == false){
				
				x1 = pacman.getPosition().x; y1 = pacman.getPosition().y;
				pcaman_move(pacman, map, score, sscore, x1, y1, enemy1, enemy2, enemy3, enemy4, sound, counter_point);

				x1 = pacman.getPosition().x;      y1 = pacman.getPosition().y;
				x = enemy1.getPosition().x;       y = enemy1.getPosition().y;
				x2 = enemy3.getPosition().x;      y2 = enemy3.getPosition().y;
				x3 = enemy2.getPosition().x;      y3 = enemy2.getPosition().y;
				x4 = enemy4.getPosition().x;      y4 = enemy4.getPosition().y;
				chaser_random_move++;
				if (chaser_random_move == 440){
					chaser_rand = true;
					chaser_random_move = 0;
				}
				
				if (color == false && chaser_rand == false){
					chaser_move(x,y,map,enemy1,pacman,rchaser,lchaser,uchaser,dchaser);
				}
				if (ghostNUMBER >= 3 && color == false && chaser_rand == false){ chaser_move(x3, y3, map, enemy2, pacman, renemy2, lenemy2, uenemy2, denemy2); }
				else if ((color == true || chaser_rand == true) && ghostNUMBER >= 3){ ransom_move2(x3, y3, map, enemy2, dd, renemy2, lenemy2, uenemy2, denemy2);; }

				
				if (color == true || chaser_rand == true){
					ransom_move2(x, y, map, enemy1, cc, rchaser, lchaser, uchaser, dchaser);
				}
				if (chaser_rand == true && chaser_random_move == 220){
					chaser_rand = false;
					chaser_random_move = 0;
				}
				dd = rand() % 4 + 1;
				cc = rand() % 4 + 1;
				
				if (time_ghost == 0){ ghostNUMBER++;     counter_ghost++;   time_ghost = 5; }
				if (ghostNUMBER >= 2){ ransom_move(x2, y2, map, enemy3, cc, renemy4, lenemy4, uenemy4, denemy4); }
				if (ghostNUMBER >= 4){ ransom_move(x4, y4, map, enemy4, cc, renemy3, lenemy3, uenemy3, denemy3); }


				startgame.clear();
				if (((pacman.getPosition().x == enemy1.getPosition().x&&pacman.getPosition().y == enemy1.getPosition().y) ||
					(pacman.getPosition().x == enemy2.getPosition().x&&pacman.getPosition().y == enemy2.getPosition().y) ||
					(pacman.getPosition().x == enemy3.getPosition().x&&pacman.getPosition().y == enemy3.getPosition().y) ||
					(pacman.getPosition().x == enemy4.getPosition().x&&pacman.getPosition().y == enemy4.getPosition().y)) && color == false){
					intersect_enemy = true;
				}
				if (ready_bool == false){
					startgame.draw(ready);
					startgame.draw(level3);
					sound1.play();
					startgame.display();
					Sleep(4000);
					ready_bool = true;
				}
				if ((intersect_enemy || intersect_pacman) && counter_lives == 3){
					startgame.draw(gameover);
					sound2.play();
					startgame.display();
					Sleep(4000);
					break;
				}
				if (counter_point == 412){
					point = true;
				}
				if (point){
					startgame.draw(youwin);
					startgame.display();
					Sleep(3000);
					break;
				}

				if (intersect_enemy || intersect_pacman){

					Sleep(2000);
					enemy1.setPosition(20, 14);
					enemy3.setPosition(22, 16);
					enemy2.setPosition(20, 16);
					enemy4.setPosition(18, 16);
					pacman.setPosition(1, 1);
					counter_ghost = 2;
					time_ghost = 3;
					ghostNUMBER = 1;
					counterTIME = 0;
					intersect_enemy = false;
					intersect_pacman = false;
					chaser_random_move = 0;
					counter_lives++;
				}

				for (int i = 0; i < 100; i++){
					for (int j = 0; j < 100; j++){
						if (map[i][j] == '#'){ plate.setPosition(j, i);  startgame.draw(plate); }
						else if (map[i][j] == '.'){ coin.setPosition(j, i);    startgame.draw(coin); }
						else if ((map[i][j] == '@' || map[i][j] == '3')&&ghostNUMBER >= 4){ coin2.setPosition(j, i);     startgame.draw(coin2); }
						else if (map[i][j] == '*'){ white.setPosition(j, i);     startgame.draw(white); }

					}
				}

				startgame.draw(pacman);    startgame.draw(enemy1);   startgame.draw(enemy3);   startgame.draw(enemy2);
				startgame.draw(enemy4);    startgame.draw(coin);     startgame.draw(score); startgame.draw(time1);
				if (counter_ghost < 5){
					startgame.draw(ghost22);
				}

				if (color){
					startgame.draw(ghost33);
				}
				if (counter_lives == 0){
					startgame.draw(live1);
					startgame.draw(live2);
					startgame.draw(live3);
				}
				else if (counter_lives == 1){
					startgame.draw(live1);
					startgame.draw(live2);

				}
				else if (counter_lives == 2){
					startgame.draw(live1);
				}


				startgame.display();

			}
		}
	}
void start_game(){
	int c = 0, counter = 1; bool information = false;
	RenderWindow start(VideoMode(1000, 700), "pacman game");
	View view2(FloatRect(0, -1, 45, 40));
	start.setFramerateLimit(10);
	Texture t1,pac,abo; Text startg, option, history, about, level1, level2, level3, level4;
	t1.loadFromFile("start.png"); pac.loadFromFile("pacman.png"); abo.loadFromFile("about.png");
	Sprite s(t1),pacman(pac),aboutt(abo);
	pacman.setPosition(330, 300); aboutt.setScale(4, 3);
	Event event;
	Font RAVIE; RAVIE.loadFromFile("RAVIE.TTF");
	startg.setCharacterSize(30); startg.setFont(RAVIE); startg.setPosition(370, 300); startg.setString("Start game");
	history.setCharacterSize(30); history.setFont(RAVIE); history.setPosition(370, 350); history.setString("History");
	option.setCharacterSize(30); option.setFont(RAVIE); option.setPosition(370, 400); option.setString("Option");
	about.setCharacterSize(30); about.setFont(RAVIE); about.setPosition(370, 450); about.setString("about");
	level1.setCharacterSize(30); level1.setFont(RAVIE); level1.setPosition(370, 300); level1.setString("Level 1");
	level2.setCharacterSize(30); level2.setFont(RAVIE); level2.setPosition(370, 350); level2.setString("Level 2");
	level3.setCharacterSize(30); level3.setFont(RAVIE); level3.setPosition(370, 400); level3.setString("level 3");
	level4.setCharacterSize(30); level4.setFont(RAVIE); level4.setPosition(370, 450); level4.setString("level 4");
	while (start.isOpen()){
		pacman.setTextureRect(IntRect(c * 32, 0, 32, 32));
		c++;
		if (c >= 7){
			c = 0;
		}
		if (star == false){
			if (counter == 1){
				startg.setFillColor(Color::Yellow);		history.setFillColor(Color::White);
				history.setFillColor(Color::White); about.setFillColor(Color::White);
			}
			else if (counter == 2){
				startg.setFillColor(Color::White);		option.setFillColor(Color::White);
				history.setFillColor(Color::Yellow); about.setFillColor(Color::White);
			}
			else if (counter == 3){
				startg.setFillColor(Color::White);		option.setFillColor(Color::Yellow);
				history.setFillColor(Color::White); about.setFillColor(Color::White);
			}
			else if (counter == 4){
				startg.setFillColor(Color::White);		option.setFillColor(Color::White);
				history.setFillColor(Color::White); about.setFillColor(Color::Yellow);
			}
		}
		else if (star){
			if (counter == 1){
				level1.setFillColor(Color::Yellow);		level3.setFillColor(Color::White);
				level2.setFillColor(Color::White); level4.setFillColor(Color::White);
			}
			else if (counter == 2){
				level1.setFillColor(Color::White);		level3.setFillColor(Color::White);
				level2.setFillColor(Color::Yellow); level4.setFillColor(Color::White);
			}
			else if (counter == 3){
				level1.setFillColor(Color::White);		level3.setFillColor(Color::Yellow);
				level2.setFillColor(Color::White); level4.setFillColor(Color::White);
			}
			else if (counter == 4){
				level1.setFillColor(Color::White);		level3.setFillColor(Color::White);
				level2.setFillColor(Color::White); level4.setFillColor(Color::Yellow);
			}
		}

		while (start.pollEvent(event)){
			if (event.type==Event::Closed){
				start.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Down)){
				if (counter <= 3){
					counter++;
					pacman.move(0, 50);
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Up)){
				if (counter >= 2){  
					counter--;
					pacman.move(0, -50);
				}
			}
		  if (Keyboard::isKeyPressed(Keyboard::Return)){
			  if (counter >= 1 && star == true && v>3){ s1 = true; }
			  else if(counter==1&&star==false){ star = true;  }
			  else if (counter == 4 && star == false && information == false){ information = true; }
			  else{ v++; }
			 

			}
		  if (Keyboard::isKeyPressed(Keyboard::Escape)){
			  if (information){ information = false; v = 1; }
			  else if (star == true){
					  information = false;  star = false;
					  star = false;
					  v = 1;
				  }
			  }
		
		}
		start.clear();
		//
		if (information == true){
			//start.setView(view2);
			start.draw(aboutt);

		}
	else if (star == false){
	     	start.draw(s);
			start.draw(startg);
			start.draw(history);
			start.draw(option);
			start.draw(about);
			start.draw(pacman);
		}
	else if (star == true){
		start.draw(s);
		start.draw(level1);
		start.draw(level2);
		start.draw(level3);
		start.draw(level4);

	
		
	}
	
	
		if (s1){
			if (counter == 1){ l1 = true; }
			else if (counter == 2){ l2 = true; }
			break;
		}
			
		start.display();
	}
	

}
void level1(){
	int dd, cc;    int n, x, y, x1, y1, x2, y2, x3, y3, di, x4, y4; int f = 0, e = 0;
	int time_ghost = 5, counter_chaseer = 0;     int counter_lives = 0; int counter_point = 0;
	char map[100][100] = {
		"######                             ######",
		"#@..x#                             #x..@#",
		"#.##.#                             #.##.#",
		"#.##.###############################.##.#",
		"#.##x......x.................x......x##.#",
		"#.#########.#################.#########.#",
		"#.#########.#################.#########.#",
		"#x.........x...x.........x...x.........x#",
		"#.#########.###.#########.###.#########.#",
		"#.#       #.# #.#       #.# #.#       #.#",
		"#.#       #.# #.#### ####.# #.#       #.#",
		"#.#       #.# #x..x# #x..x# #.#       #.#",
		"#.######### # ####.# #.#### #.#########.#",
		"#x.........x#    #.# #.#    #x.........x#",
		"#.#########.# ####.###.#### #.#########.#",
		"#.#       #.# #x..xxxxx..x# #.#       #.#",
		"#.#       #.# #.####*####.# #.#       #.#",
		"#.####### #.###.#>>>+<<<#.###.# #######.#",
		" x.....x# #x...x#>>>+<<<#x...x# #x.....x.",
		"#######.# #.###.#########.###.# # #######",
		"      #.# #.# #x..x...x..x# #.# # #      ",
		"      #.###.# ####.###.#### #.### #      ",
		"      #x...x#    #.# #.#    #x...x#      ",
		"#######.###.# ####.# #.#### #.###.#######",
		"#x.....x# #.# #x..x# #x..x# #.# #x.....x#",
		"#.####### #.# #.#### ####.# #.# #######.#",
		"#.#       #.# #.#       #.# #.#       #.#",
		"#.#########.###.#########.###.#########.#",
		"#x.........x...x...x.x...x...x.........x#",
		"########### #######.#.#######.###########",
		"#x.........x#     #.#.#     #x.........x#",
		"#.#########.#     #.#.#     #.#########.#",
		"#.#########.#######.#.#######.#########.#",
		"#.##x......x.......x#x.......x......x##.#",
		"#.##.###############################.##.#",
		"#.##.#                             #.##.#",
		"#@..x#                             #x..@#",
		"######                             ######"
	};
	int c = 0;
	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 100; j++){
			if (map[i][j] == '.')c++;
		}
	}
	RenderWindow startgame(VideoMode(1000, 700), "PAC MAN", Style::Fullscreen);

	View view2(FloatRect(0, -2, 45, 40));

	startgame.setFramerateLimit(9);
	Event event;
	CircleShape circle, circle1;
	circle.setFillColor(Color::Yellow);
	circle.setRadius(0.3);
	circle1.setFillColor(Color::Red);
	circle1.setRadius(0.3);
	Texture enemy, p1, pac, enemyc, c1, c2, w;

	pac.loadFromFile("pacman.png"); enemy.loadFromFile("evils.png"); p1.loadFromFile("block.png");
	c2.loadFromFile("coin2.png");  c1.loadFromFile("coin.png"); w.loadFromFile("white.png");
	Sprite enemy1(enemy), plate(p1), pacman(pac), enemy3(enemy), coin(c1), coin2(c2), enemy2(enemy), enemy4(enemy), white(w), live1(pac),
		live2(pac), live3(pac);
	plate.setTextureRect(IntRect(0, 0, 32, 10)); plate.setScale(0.0325, 0.0925); white.setScale(0.0145, 0.0200);
	pacman.setTextureRect(IntRect(0, 0, 32, 32)); pacman.setScale(0.0400, 0.0300); pacman.setPosition(1, 1);
	enemy1.setPosition(20, 15); enemy1.setScale(0.0400, 0.0400); enemy2.setPosition(20, 17); enemy2.setScale(0.0400, 0.0400);
	enemy3.setPosition(22, 17); enemy3.setScale(0.0400, 0.0400); enemy4.setPosition(18, 17); enemy4.setScale(0.0400, 0.0400);
	coin.setScale(0.0100, 0.0100); coin2.setScale(0.0100, 0.0100);
	live1.setTextureRect(IntRect(0, 0, 32, 32)); live1.setPosition(42, 1); live1.setScale(0.0800, 0.0700);
	live2.setTextureRect(IntRect(0, 0, 32, 32)); live2.setPosition(42, 4); live2.setScale(0.0800, 0.0700);
	live3.setTextureRect(IntRect(0, 0, 32, 32)); live3.setPosition(42, 7); live3.setScale(0.0800, 0.0700);
	Time ttime;     Clock clock;    Font arial, RAVIE;  arial.loadFromFile("arial.ttf"); RAVIE.loadFromFile("RAVIE.ttf");
	int p = 0;

	ostringstream sscore, gghost, rgost, ss, ggameover;
	sscore << "Score : " << score1; gghost << "GHOST " << counter_ghost << " : " << time_ghost;
	rgost << "GHOST: " << ghost_return; ss << "Time : " << 0;

	Text score, time1, gameover, youwin, ghost22, ghost33, ready, level3, _continue, _break;
	score.setCharacterSize(30); score.setPosition(0, -2); score.setScale(0.06, 0.06);
	score.setFont(arial); score.setString(sscore.str()); score.setFillColor(Color::	Yellow);

	ghost22.setCharacterSize(30); ghost22.setPosition(15, -2); ghost22.setScale(0.06, 0.06);
	ghost22.setFillColor(Color::Yellow); ghost22.setFont(arial); ghost22.setString(gghost.str());
	ghost33.setCharacterSize(30); ghost33.setPosition(15, -2); ghost33.setScale(0.06, 0.06);
	ghost33.setFillColor(Color::Yellow); ghost33.setFont(arial); ghost33.setString(rgost.str());

	time1.setCharacterSize(30); time1.setPosition(30, -2); time1.setScale(0.06, 0.06);
	time1.setFillColor(Color::Red); time1.setFont(arial); time1.setString(ss.str());

	gameover.setCharacterSize(80); gameover.setPosition(7, 11); gameover.setScale(0.05, 0.07);
	gameover.setFillColor(Color::Red); gameover.setFont(RAVIE); gameover.setString("GAME OVER!!");

	ready.setCharacterSize(80); ready.setPosition(6, 11); ready.setScale(0.07, 0.07);
	ready.setFillColor(Color::Green); ready.setFont(RAVIE); ready.setString("READY !!");

	level3.setCharacterSize(80); level3.setPosition(6, 1); level3.setScale(0.07, 0.07);
	level3.setFillColor(Color::Yellow); level3.setFont(RAVIE); level3.setString("LEVEL:1");

	youwin.setCharacterSize(80); youwin.setPosition(7, 11); youwin.setScale(0.05, 0.07);
	youwin.setFillColor(Color::Green); youwin.setFont(RAVIE); youwin.setString("YOU WIN");

	_break.setCharacterSize(80); _break.setPosition(1, 11); _break.setScale(0.0280, 0.05);
	_break.setFillColor(Color::Green); _break.setFont(arial); _break.setString("Press Esc button to back to the main menu");

	_continue.setCharacterSize(80); _continue.setPosition(1, 1); _continue.setScale(0.04, 0.05);
	_continue.setFillColor(Color::Green); _continue.setFont(arial); _continue.setString("Press Enter button to continue ");

	Music music;
	music.openFromFile("8d82b5_Pacman_Siren_Sound_Effect.wav");

	Sound sound, sound1, sound2, sound3;
	SoundBuffer soundbuffer, soundbuffer1, soundbuffer2;
	soundbuffer.loadFromFile("dp_superpac_wakka.wav");
	soundbuffer1.loadFromFile("pac-man-intro.wav");
	soundbuffer2.loadFromFile("kill.wav");
	sound.setBuffer(soundbuffer);
	sound1.setBuffer(soundbuffer1);
	sound2.setBuffer(soundbuffer2);
	music.setLoop(true);
	music.play();
	while (startgame.isOpen()){
		if (color == false){
			enemy1.setTextureRect(IntRect(0 * 32, 0, 32, 32));
			enemy2.setTextureRect(IntRect(4 * 32, 0, 32, 32));
			enemy3.setTextureRect(IntRect(2 * 32, 0, 32, 32));
			enemy4.setTextureRect(IntRect(6 * 32, 0, 32, 32));
		}
		startgame.setView(view2);
		srand(time(NULL));
		convert_blue(pacman, enemy1, enemy2, enemy3, enemy4, color);

		if (color == true){
			ghost++;  rgost.str("");  rgost << "GHOST: " << ghost_return; ghost33.setString(rgost.str());

			if (ghost == 11){ ghost = 0;  ghost_return--; }

			if (ghost_return == 0){
				color = false;  enmey1_intersect = false; enmey2_intersect = false;
				enmey4_intersect = false;  enmey3_intersect = false;    ghost_return = 10; increce = 0; increase1 = 0; increase2 = 0; increase3 = 0;
			}
		}

		ttime = clock.getElapsedTime();  ss.str("");  time3 = ttime.asSeconds();  ss << "Time : " << time3;   time1.setString(ss.str());
		counterTIME++;
		if (counterTIME == 11 && time_ghost != 0){
			time_ghost = time_ghost - 1;   gghost.str("");
			gghost << "GHOST " << counter_ghost << " : " << time_ghost; ghost22.setString(gghost.str()); counterTIME = 0;
		}
		while (startgame.pollEvent(event)){
			if (event.type == Event::Closed){

				startgame.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape)){
				_return = true;
				startgame.clear();
				startgame.draw(_break);
				startgame.draw(_continue);
				startgame.display();

			}
			if (Keyboard::isKeyPressed(Keyboard::Escape) && _return == true){
				startgame.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Return)){
				_return = false;
			}
			if (_return == false){
				if (Keyboard::isKeyPressed(Keyboard::Right)){ rpacman = true; lpacman = false; dpacman = false; upacman = false; }
				if (Keyboard::isKeyPressed(Keyboard::Left)){ rpacman = false; lpacman = true; dpacman = false; upacman = false; }
				else if (Keyboard::isKeyPressed(Keyboard::Up)){ rpacman = false; lpacman = false; dpacman = false; upacman = true; }
				else if (Keyboard::isKeyPressed(Keyboard::Down)){ rpacman = false; lpacman = false; dpacman = true; upacman = false; }

			}
		}
		if (_return == false){

			x1 = pacman.getPosition().x; y1 = pacman.getPosition().y;
			pcaman_move(pacman, map, score, sscore, x1, y1, enemy1, enemy2, enemy3, enemy4, sound, counter_point);

			x1 = pacman.getPosition().x;      y1 = pacman.getPosition().y;
			x = enemy1.getPosition().x;       y = enemy1.getPosition().y;
			x2 = enemy3.getPosition().x;      y2 = enemy3.getPosition().y;
			x3 = enemy2.getPosition().x;      y3 = enemy2.getPosition().y;
			x4 = enemy4.getPosition().x;      y4 = enemy4.getPosition().y;
			chaser_random_move++;
			if (chaser_random_move == 440){
				chaser_rand = true;
				chaser_random_move = 0;
			}

			if (color == false && chaser_rand == false){
				chaser_move(x, y, map, enemy1, pacman, rchaser, lchaser, uchaser, dchaser);
			}
			if (ghostNUMBER >= 3 ){ ransom_move2(x3, y3, map, enemy2, dd, renemy2, lenemy2, uenemy2, denemy2); }


			if (color == true || chaser_rand == true){
				ransom_move2(x, y, map, enemy1, cc, rchaser, lchaser, uchaser, dchaser);
			}
			if (chaser_rand == true && chaser_random_move == 220){
				chaser_rand = false;
				chaser_random_move = 0;
			}
			dd = rand() % 4 + 1;
			cc = rand() % 4 + 1;

			if (time_ghost == 0){ ghostNUMBER++;     counter_ghost++;   time_ghost = 5; }
			if (ghostNUMBER >= 2){ ransom_move(x2, y2, map, enemy3, cc, renemy4, lenemy4, uenemy4, denemy4); }
			if (ghostNUMBER >= 4){ ransom_move(x4, y4, map, enemy4, cc, renemy3, lenemy3, uenemy3, denemy3); }


			startgame.clear(Color::Blue);
			if (((pacman.getPosition().x == enemy1.getPosition().x&&pacman.getPosition().y == enemy1.getPosition().y) ||
				(pacman.getPosition().x == enemy2.getPosition().x&&pacman.getPosition().y == enemy2.getPosition().y) ||
				(pacman.getPosition().x == enemy3.getPosition().x&&pacman.getPosition().y == enemy3.getPosition().y) ||
				(pacman.getPosition().x == enemy4.getPosition().x&&pacman.getPosition().y == enemy4.getPosition().y)) && color == false){
				intersect_enemy = true;
			}
			if (ready_bool == false){
				startgame.draw(ready);
				startgame.draw(level3);
				sound1.play();
				startgame.display();
				Sleep(4000);
				ready_bool = true;
			}
			if ((intersect_enemy || intersect_pacman) && counter_lives == 3){
				startgame.draw(gameover);
				sound2.play();
				startgame.display();
				Sleep(4000);
				break;
			}
			if (counter_point == 352){
				point = true;
			}
		
			if (point){
				startgame.draw(youwin);
				startgame.display();
				Sleep(3000);
				break;
			}

			if (intersect_enemy || intersect_pacman){

				Sleep(2000);
				enemy1.setPosition(20, 15);
				enemy3.setPosition(22, 17);
				enemy2.setPosition(20, 17);
				enemy4.setPosition(18, 17);
				pacman.setPosition(1, 1);
				counter_ghost = 2;
				time_ghost = 3;
				ghostNUMBER = 1;
				counterTIME = 0;
				intersect_enemy = false;
				intersect_pacman = false;
				chaser_random_move = 0;
				counter_lives++;
			}

			for (int i = 0; i < 100; i++){
				for (int j = 0; j < 100; j++){
					if (map[i][j] == '#'){ plate.setPosition(j, i);  startgame.draw(plate); }
					else if (map[i][j] == '.'){ circle.setPosition(j*1.009, i); startgame.draw(circle); }
					else if ((map[i][j] == '@' || map[i][j] == '3') && ghostNUMBER >= 4){ circle1.setPosition(j, i);    startgame.draw(circle1); }
					else if (map[i][j] == '*'){ white.setPosition(j, i);     startgame.draw(white); }

				}
			}

			startgame.draw(pacman);    startgame.draw(enemy1);   startgame.draw(enemy3);   startgame.draw(enemy2);
			startgame.draw(enemy4);    /*startgame.draw(coin);*/     startgame.draw(score); startgame.draw(time1);
			if (counter_ghost < 5){
				startgame.draw(ghost22);
			}

			if (color){
				startgame.draw(ghost33);
			}
			if (counter_lives == 0){
				startgame.draw(live1);
				startgame.draw(live2);
				startgame.draw(live3);
			}
			else if (counter_lives == 1){
				startgame.draw(live1);
				startgame.draw(live2);

			}
			else if (counter_lives == 2){
				startgame.draw(live1);
			}


			startgame.display();

		}
	}

}
int main()
{

	if (s1 == false) { start_game(); }
	if (s1){
		if (l1){ level1(); }
		if (l2){ level2(); }
	}
	return 0;
}
void ransom_move2(int x, int y, char map[100][100], Sprite &enemy, int dir, bool &right, bool &left, bool &up, bool &down){

	if (position1){ enemy.setPosition(0, 18); position1 = false; }
	if (map[y][x] == '<'){
		left = true; right = false; up = false; down = false;
	}
	if (map[y][x] == '>'){
		left = false; right = true; up = false; down = false;
	}
	if (map[y][x] == '+'){
		left = false; right = false; up = true; down = false;
	}
	if (map[y][x] == 'x' || map[y][x] == 'X' || map[y][x] == '1' || map[y][x] == '2' || map[y][x] == '3' || map[y][x] == '4' || map[y][x] == '@'){
		if (right == true){
			if (dir == 4){
				left = false; right = true; up = false; down = false;
			}
			else if (dir == 2){
				left = false; right = false; up = true; down = false;
			}
			else if (dir == 1){
				left = false; right = false; up = false; down = true;
			}
			if (right == true && map[y][x + 1] == '#'){
				left = false; right = false; up = true; down = false;
				if (up == true && map[y - 1][x] == '#'){
					left = false; right = false; up = false; down = true;

				}
			}
			else if (up == true && map[y - 1][x] == '#'){
				left = false; right = true; up = false; down = false;
				if (right == true && map[y][x + 1] == '#'){
					left = false; right = false; up = false; down = true;

				}
			}
			else if (down == true && map[y + 1][x] == '#'){
				left = false; right = false; up = true; down = false;
				if (up == true && map[y - 1][x] == '#'){
					left = false; right = true; up = false; down = false;

				}
			}

		}
		else if (left == true){
			if (dir == 3){
				left = true; right = false; up = false; down = false;
			}
			else if (dir == 2){
				left = false; right = false; up = true; down = false;
			}
			else if (dir == 1){
				left = false; right = false; up = false; down = true;
			}
			if (left == true && map[y][x - 1] == '#'){
				left = false; right = false; up = true; down = false;
				if (up == true && map[y - 1][x] == '#'){
					left = false; right = false; up = false; down = true;

				}
			}

			else if (up == true && map[y - 1][x] == '#'){
				left = true; right = false; up = false; down = false;
				if (left == true && map[y][x - 1] == '#'){
					left = false; right = false; up = false; down = true;

				}
			}
			else if (down == true && map[y + 1][x] == '#'){
				left = false; right = false; up = true; down = false;
				if (up == true && map[y - 1][x] == '#'){
					left = true; right = false; up = false; down = false;

				}
			}




		}
		else if (up == true){
			if (dir == 4){
				left = false; right = true; up = false; down = false;
			}
			else if (dir == 3){
				left = true; right = false; up = false; down = false;
			}
			else if (dir == 2){
				left = false; right = false; up = true; down = false;
			}
			if (right == true && map[y][x + 1] == '#'){
				left = false; right = false; up = true; down = false;
				if (up == true && map[y - 1][x] == '#'){
					left = true; right = false; up = false; down = false;

				}
			}
			else if (left == true && map[y][x - 1] == '#'){
				left = false; right = true; up = false; down = false;
				if (right == true && map[y][x + 1] == '#'){
					left = false; right = false; up = true; down = false;

				}
			}
			else if (up == true && map[y - 1][x] == '#'){
				left = false; right = true; up = false; down = false;
				if (right == true && map[y][x + 1] == '#'){
					left = true; right = false; up = false; down = false;

				}
			}
		}
		else if (down == true){
			if (dir == 4){
				left = false; right = true; up = false; down = false;
			}
			else if (dir ==3){
				left = true; right = false; up = false; down = false;
			}
			else if (dir == 1){
				left = false; right = false; up = false; down = true;
			}
			if (right == true && map[y][x + 1] == '#'){
				left = true; right = false; up = false; down = false;
				if (left == true && map[y][x - 1] == '#'){
					left = false; right = false; up = false; down = true;

				}
			}
			else if (left == true && map[y][x - 1] == '#'){
				left = false; right = false; up = false; down = true;
				if (down == true && map[y + 1][x] == '#'){
					left = false; right = true; up = false; down = false;

				}
			}
			else if (down == true && map[y + 1][x] == '#'){
				left = true; right = false; up = false; down = false;
				if (left == true && map[y][x - 1] == '#'){
					left = false; right = true; up = false; down = false;

				}
			}
		}
		else if (left == false && right == false && up == false && down == false){
			if (dir == 4){
				left = false; right = true; up = false; down = false;
			}
			else if (dir == 3){
				left = true; right = false; up = false; down = false;
			}
			else if (dir == 2){
				left = false; right = false; up = true; down = false;
			}
			else if (dir == 1){
				left = false; right = false; up = false; down = true;
			}
		}
	}





	if (right&&map[y][x + 1] != '#'){

		if (x == 40 && y == 18){ position1 = true; }
		if (position1){ enemy.setPosition(0, 18); position1 = false; }
		n = 1;
		common_move(enemy, n);
	}
	if (left&&map[y][x - 1] != '#'){
		if (x == 0 && y == 18){ position2 = true; }
		if (position2){ enemy.setPosition(40, 18); position2 = false; }
		n = 2;
		common_move(enemy, n);
	}
	if (up&&map[y - 1][x] != '#'){
		n = 3;
		common_move(enemy, n);
	}
	if (down&&map[y + 1][x] != '#'){
		n = 4;
		common_move(enemy, n);
	}


}
void ransom_move(int x, int y, char map[100][100], Sprite &enemy, int dir, bool &right, bool &left, bool &up, bool &down){
	
	if (position1){ enemy.setPosition(0, 18); position1 = false;  }
	if (map[y][x] == '<'){
		left = true; right = false; up = false; down = false;
	}
	if (map[y][x] == '>'){
		left = false; right = true; up = false; down = false;
	}
	if (map[y][x] == '+'){
		left = false; right = false; up = true; down = false;
	}
	if (map[y][x] == 'x' || map[y][x] == 'X' || map[y][x] == '1' || map[y][x] == '2' || map[y][x] == '3' || map[y][x] == '4' || map[y][x] == '@'){
		if (right == true){
			if (dir == 1){
				left = false; right = true; up = false; down = false;
			}
			else if (dir == 3){
				left = false; right = false; up = true; down = false;
			}
			else if (dir == 4){
				left = false; right = false; up = false; down = true;
			}
			if (right == true && map[y][x + 1] == '#'){
				left = false; right = false; up = true; down = false;
				if (up == true && map[y - 1][x] == '#'){
					left = false; right = false; up = false; down = true;

				}
			}
			else if (up == true && map[y - 1][x] == '#'){
				left = false; right = true; up = false; down = false;
				if (right == true && map[y][x + 1] == '#'){
					left = false; right = false; up = false; down = true;

				}
			}
			else if (down == true && map[y + 1][x] == '#'){
				left = false; right = false; up = true; down = false;
				if (up == true && map[y - 1][x] == '#'){
					left = false; right = true; up = false; down = false;

				}
			}

		}
		else if (left == true){
			if (dir == 2){
				left = true; right = false; up = false; down = false;
			}
			else if (dir == 3){
				left = false; right = false; up = true; down = false;
			}
			else if (dir == 4){
				left = false; right = false; up = false; down = true;
			}
			if (left == true && map[y][x - 1] == '#'){
				left = false; right = false; up = true; down = false;
				if (up == true && map[y - 1][x] == '#'){
					left = false; right = false; up = false; down = true;

				}
			}

			else if (up == true && map[y - 1][x] == '#'){
				left = true; right = false; up = false; down = false;
				if (left == true && map[y][x - 1] == '#'){
					left = false; right = false; up = false; down = true;

				}
			}
			else if (down == true && map[y + 1][x] == '#'){
				left = false; right = false; up = true; down = false;
				if (up == true && map[y - 1][x] == '#'){
					left = true; right = false; up = false; down = false;

				}
			}




		}
		else if (up == true){
			if (dir == 1){
				left = false; right = true; up = false; down = false;
			}
			else if (dir == 2){
				left = true; right = false; up = false; down = false;
			}
			else if (dir == 3){
				left = false; right = false; up = true; down = false;
			}
			if (right == true && map[y][x + 1] == '#'){
				left = false; right = false; up = true; down = false;
				if (up == true && map[y - 1][x] == '#'){
					left = true; right = false; up = false; down = false;

				}
			}
			else if (left == true && map[y][x - 1] == '#'){
				left = false; right = true; up = false; down = false;
				if (right == true && map[y][x + 1] == '#'){
					left = false; right = false; up = true; down = false;

				}
			}
			else if (up == true && map[y - 1][x] == '#'){
				left = false; right = true; up = false; down = false;
				if (right == true && map[y][x + 1] == '#'){
					left = true; right = false; up = false; down = false;

				}
			}
		}
		else if (down == true){
			if (dir == 1){
				left = false; right = true; up = false; down = false;
			}
			else if (dir == 2){
				left = true; right = false; up = false; down = false;
			}
			else if (dir == 4){
				left = false; right = false; up = false; down = true;
			}
			if (right == true && map[y][x + 1] == '#'){
				left = true; right = false; up = false; down = false;
				if (left == true && map[y][x - 1] == '#'){
					left = false; right = false; up = false; down = true;

				}
			}
			else if (left == true && map[y][x - 1] == '#'){
				left = false; right = false; up = false; down = true;
				if (down == true && map[y + 1][x] == '#'){
					left = false; right = true; up = false; down = false;

				}
			}
			else if (down == true && map[y + 1][x] == '#'){
				left = true; right = false; up = false; down = false;
				if (left == true && map[y][x - 1] == '#'){
					left = false; right = true; up = false; down = false;

				}
			}
		}
		else if (left == false && right == false && up == false && down == false){
			if (dir == 1){
				left = false; right = true; up = false; down = false;
			}
			else if (dir == 2){
				left = true; right = false; up = false; down = false;
			}
			else if (dir == 3){
				left = false; right = false; up = true; down = false;
			}
			else if (dir == 4){
				left = false; right = false; up = false; down = true;
			}
		}
	}



	
	
	if (right&&map[y][x + 1] != '#'){
		
		if (x == 40 && y == 18){ position1 = true;  }
		if (position1){ enemy.setPosition(0, 18); position1 = false; }
		n = 1;
		common_move(enemy, n);
	}
	if (left&&map[y][x - 1] != '#'){
		if (x == 0 && y == 18){ position2 = true;  }
		if (position2){ enemy.setPosition(40, 18); position2 = false;}
		n = 2;
		common_move(enemy, n);
	}
	if (up&&map[y - 1][x] != '#'){
		n = 3;
		common_move(enemy, n);
	}
	if (down&&map[y + 1][x] != '#'){
		n = 4;
		common_move(enemy, n);
	}


}
void chaser_move(int &x, int &y, char map[100][100], Sprite &enemy1, Sprite &pacman, bool &right, bool &left, bool &up, bool &down){
	if (map[y][x] == '+'){
		left = false; right = false; down = false; up = true;
	}

	else if (map[y][x] == 'x' || map[y][x] == 'X' || map[y][x] == '1' || map[y][x] == '2' || map[y][x] == '3' || map[y][x] == '4' || map[y][x] == '@'){
		
	
		
		
		 if (pacman.getPosition().x < enemy1.getPosition().x&&pacman.getPosition().y < enemy1.getPosition().y&&rchaser == true){
			left = false; right= false; down = false; up = true;

		}
		else if (pacman.getPosition().x<enemy1.getPosition().x&&pacman.getPosition().y<enemy1.getPosition().y){
			left = true; right = false; down = false; up = false;
			
		}
		else if (pacman.getPosition().x>enemy1.getPosition().x&&pacman.getPosition().y == enemy1.getPosition().y){
			left = false; right = true; down = false; up = false;
		}
		else if (pacman.getPosition().x == enemy1.getPosition().x&&pacman.getPosition().y > enemy1.getPosition().y){
			left = false; right = false; down = true; up = false;
		}
		else if (pacman.getPosition().x == enemy1.getPosition().x&&pacman.getPosition().y < enemy1.getPosition().y){
			left = false; right = false; down = false; up = true;
		}
		else if (pacman.getPosition().x < enemy1.getPosition().x&&pacman.getPosition().y == enemy1.getPosition().y){
			left = true; right = false; down = false; up = false;
		}
		if (pacman.getPosition().x > enemy1.getPosition().x&&pacman.getPosition().y > enemy1.getPosition().y&&lchaser == true){
			left = false; right= false; down = true; up = false;

		}
		else if (pacman.getPosition().x > enemy1.getPosition().x&&pacman.getPosition().y > enemy1.getPosition().y){
			left = false; right = true; down = false; up = false;
			
		}
		if (pacman.getPosition().x < enemy1.getPosition().x&&pacman.getPosition().y > enemy1.getPosition().y&&uchaser == true){
			left = true; right = false; down = false; up = false;
		}
		else if (pacman.getPosition().x < enemy1.getPosition().x&&pacman.getPosition().y > enemy1.getPosition().y){
			left = false; right = false; down = true; up = false;
		
		}
		else if (pacman.getPosition().x > enemy1.getPosition().x&&pacman.getPosition().y < enemy1.getPosition().y){
			left = false; right = false; down = false; up = true;
		}
		
		

	}
	
	if (map[y][x] == 'x' || map[y][x] == 'X'){
		if (rchaser == true){
			if (map[y][x + 1] == '#'&&pacman.getPosition().y > enemy1.getPosition().y){
				left = false; right = false; down = true; up = false;
				if (down == true && map[y + 1][x] == '#'){
					left = true; right = false; down = false; up = false;
					if (left == true && map[y][x - 1] == '#'){
						left = false; right = false; down= false; up = true;}}}
			if (map[y][x + 1] == '#' && ((pacman.getPosition().y < enemy1.getPosition().y) || (pacman.getPosition().y == enemy1.getPosition().y))){
				left = false; right= false; down = false; up = true;
				if (up == true && map[y - 1][x] == '#'){
					left = true; right = false; down = false; up = false;
					if (left == true && map[y][x - 1] == '#'){
						left = false; right = false; down = true; up = false;}}}}
		//////////////////////////////////////////////////////////////////////////////////////////
		else if (left == true){
			if (map[y][x - 1] == '#' && ((pacman.getPosition().y < enemy1.getPosition().y) || (pacman.getPosition().y == enemy1.getPosition().y))){
				left = false; right = false; down = false; up = true;
				if (up == true && map[y - 1][x] == '#'){
					left = false; right = true; down = false; up = false;
				
					if (right == true && map[y][x + 1] == '#'){
						left = false; right = false; down = true; up = false;}}}
			if (map[y][x - 1] == '#' && pacman.getPosition().y > enemy1.getPosition().y){
				left = false; right = false; down = true; up= false;
				if (down == true && map[y + 1][x] == '#'){
					left= false; right = true; down = false; up = false;
				
					if (right == true && map[y][x + 1] == '#'){
						left = false; right = false; down = false; up = true;}}}}

		///////////////////////////////////////////////////////////////////////////////////////////////
		else if (up == true){
			if (map[y - 1][x] == '#' && ((pacman.getPosition().x > enemy1.getPosition().x) || (pacman.getPosition().x == enemy1.getPosition().x))){
				left = true; right = false; down = false; up = false;
				if (left == true && map[y][x - 1] == '#'){
					left= false; right = true; down = false; up = false;
					
					if (right == true && map[y][x + 1] == '#'){
						left = false; right = false; down = true; up = false;}}}
			if (map[y - 1][x] == '#'&&pacman.getPosition().x > enemy1.getPosition().x){
				left = false; right = true; down= false; up= false;
				
				if (right == true && map[y][x + 1] == '#'){
					left = true; right = false; down = false; up = false;
					if (left == true && map[y][x - 1] == '#'){
						left= false; right = false; down = true; up = false;}}}}
		//////////////////////////////////////////////////////////////////////////////////////////////
		else if (down == true){
			if (map[y + 1][x] == '#' &&((pacman.getPosition().x < enemy1.getPosition().x) || (pacman.getPosition().x == enemy1.getPosition().x))){
				left = true; right = false; down = false; up = false;
				if (left == true && map[y][x - 1] == '#'){
					left = false; right = true; down = false; up = false;
					
					if (right == true && map[y][x + 1] == '#'){
						left = false; right = false; down = false; up= true;}}}
			if (map[y + 1][x] == '#'&&pacman.getPosition().x > enemy1.getPosition().x){
				left = false; right = true; down = false; up = false;
				
				if (right == true && map[y][x + 1] == '#'){
					left = true; right = false; down = false; up = false;
					if (left == true && map[y][x - 1] == '#'){
						left = false; right = false; down = false; up= true;}}}}

		


	}
	
	
	if (right&&map[y][x + 1] != '#'){
		n = 1;
		if (x == 38 && y == 18){
			e1 = true;
		}
		if (e1 == true){
			enemy1.setPosition(0, 18);
			e1 = false;
		}
		common_move(enemy1, n);
	}
	
	else if (left&&map[y][x - 1] != '#'){
		n = 2;
		if (x == 0 && y == 18){
			e1 = true;
		}
		if (e1 == true){
			enemy1.setPosition(38, 18);
			e1 = false;
		}
		common_move(enemy1, n);
	}

	else if (up&&map[y - 1][x] != '#'){
		n = 3;
		common_move(enemy1, n);
	}
	if (down&&map[y + 1][x] != '#'){
		n = 4;
		common_move(enemy1, n);
	}

}
void common_move(Sprite &gost, int &dir){

	if (dir == 1){
		gost.move(1, 0);
	}
	if (dir == 2){
		gost.move(-1, 0);
	}
	if (dir == 3){
		gost.move(0, -1);
	}
	if (dir == 4){
		gost.move(0, 1);
	}


}
void convert_blue(Sprite &pacman, Sprite &enemy1, Sprite &enemy2, Sprite &enemy3, Sprite &enemy4, bool &color){
	
	if (color == true){
		if (pacman.getGlobalBounds().intersects(enemy1.getGlobalBounds())){
			enmey1_intersect = true;
			if (increase == 0){
				score1 += 200;
				increase++;
			}
		}
		if (pacman.getGlobalBounds().intersects(enemy2.getGlobalBounds())){
			enmey2_intersect = true;
			if (increase1 == 0){
				score1 += 200;
				increase1++;
			}
		}
		if (pacman.getGlobalBounds().intersects(enemy3.getGlobalBounds())){
			enmey3_intersect = true;
			if (increase2 == 0){
				score1 += 200;
				increase2++;
			}
		}
		if (pacman.getGlobalBounds().intersects(enemy4.getGlobalBounds())){
			enmey4_intersect = true;
			if (increase3 == 0){
				score1 += 200;
				increase3++;
			}
		}
		if (enmey1_intersect){
			enemy1.setTextureRect(IntRect(12 * 32, 2 * 32, 32, 32));
		}
		if (enmey2_intersect){
			enemy2.setTextureRect(IntRect(12 * 32, 2 * 32, 32, 32));
		}

		if (enmey3_intersect){
			enemy3.setTextureRect(IntRect(12 * 32, 2 * 32, 32, 32));
		}
		if (enmey4_intersect){
			enemy4.setTextureRect(IntRect(12 * 32, 2 * 32, 32, 32));
		}


		if (enmey1_intersect == false && enmey2_intersect == false && enmey3_intersect == false && enmey4_intersect == false){
			enemy1.setTextureRect(IntRect(12 * 32, 0, 32, 32));
			enemy2.setTextureRect(IntRect(12 * 32, 0, 32, 32));
			enemy3.setTextureRect(IntRect(12 * 32, 0, 32, 32));
			enemy4.setTextureRect(IntRect(12 * 32, 0, 32, 32));
		}
	}
	}

void pcaman_move(Sprite &pacman, char map[100][100], Text &score, ostringstream &sscore, int x1, int y1,Sprite &enemy1, Sprite &enemy2,
	Sprite &enemy3, Sprite &enemy4, Sound &sound, int &counter_point){
	eat++;
	if (upacman)
	{
		x1 = pacman.getPosition().x;
		y1 = pacman.getPosition().y;

		if (map[y1 - 1][x1] != '#')
		{
			pacman.move(0, -1);
		}
		if (map[y1 - 1][x1] == '.')
		{
			score1++;
			counter_point++;
			sscore.str("");
			sscore << "Score : " << score1;
			score.setString(sscore.str());
			map[y1 - 1][x1] = ' ';
			if (eat % 4 == 0){
				sound.play();
				
			}
		}
		if (map[y1 - 1][x1] == '@'&&ghostNUMBER >= 4){
			color = true;
			map[y1 - 1][x1] = 'x';
			if (y1 == 1 && x1 == 1){
				map[y1 - 1][x1] = '3';
			}
		}

		pacman.setTextureRect(IntRect(m1 * 32, 3 * 32, 32, 32));

	}
	else if (rpacman)
	{
		x1 = pacman.getPosition().x;
		y1 = pacman.getPosition().y;
		if (x1 == 39 && y1 == 18){
			m5 = true;
		}
		if (m5 == true){
			pacman.setPosition(0, 18);
			m5 = false;
		}
		if (map[y1][x1 + 1] != '#')
		{
			pacman.move(1, 0);
		}
		if (map[y1][x1 + 1] == '.')
		{
			score1++;
			counter_point++;
			sscore.str("");
			sscore << "Score : " << score1;
			score.setString(sscore.str());
			map[y1][x1 + 1] = ' ';
			if (eat % 4 == 0){
				sound.play();
				
			}
		}
		if (map[y1][x1 + 1] == '@'&&ghostNUMBER >= 4){
			color = true;
			map[y1][x1 + 1] = 'x';
			if (y1 == 1 && x1 == 1){
				map[y1][x1+1] = '3';
			}
			
		}

		pacman.setTextureRect(IntRect(m1 * 32, 0, 32, 32));

	}
	else if (dpacman)
	{
		x1 = pacman.getPosition().x;
		y1 = pacman.getPosition().y;


		if (map[y1 + 1][x1] != '#')
		{
			pacman.move(0, 1);
		}
		if (map[y1 + 1][x1] == '.')
		{
			score1++;
			counter_point++;
			sscore.str("");
			sscore << "Score : " << score1;
			score.setString(sscore.str());
			map[y1 + 1][x1] = ' ';
			if (eat % 4 == 0){
				sound.play();
			}
			
		}
		if (map[y1 + 1][x1] == '@'&&ghostNUMBER >= 4){
			color = true;
			map[y1 + 1][x1] = 'x';
			if (y1 == 1 && x1 == 1){
				map[y1 + 1][x1] = '3';
			}
		}
		pacman.setTextureRect(IntRect(m1 * 32, 32, 32, 32));

	}
	else if (lpacman)
	{
		x1 = pacman.getPosition().x;
		y1 = pacman.getPosition().y;
		if (x1 == 0 && y1 == 18){
			m2 = true;
		}
		if (m2 == true){
			pacman.setPosition(39, 18);
			m2 = false;
		}

		if (map[y1][x1 - 1] != '#')
		{
			pacman.move(-1, 0);
		}
		if (map[y1][x1 - 1] == '.')
		{
			score1++;
			counter_point++;
			sscore.str("");
			sscore << "Score : " << score1;
			score.setString(sscore.str());
			map[y1][x1 - 1] = ' ';
			if (eat % 4 == 0){
				sound.play();
			}
			
		}
		if (map[y1][x1 - 1] == '@'&&ghostNUMBER >= 4){
			color = true;
			map[y1][x1 - 1] = 'x';
			if (y1 == 1 && x1 == 1){
				map[y1][x1-1] = '3';
			}
		}
		pacman.setTextureRect(IntRect(m1 * 32, 2 * 32, 32, 32));

	}
	m1++;
	if (m1 >= 7)
		m1 = 0;
	if (((pacman.getPosition().x == enemy1.getPosition().x&&pacman.getPosition().y == enemy1.getPosition().y) ||
		(pacman.getPosition().x == enemy2.getPosition().x&&pacman.getPosition().y == enemy2.getPosition().y) ||
		(pacman.getPosition().x == enemy3.getPosition().x&&pacman.getPosition().y == enemy3.getPosition().y) ||
		(pacman.getPosition().x == enemy4.getPosition().x&&pacman.getPosition().y == enemy4.getPosition().y)) && color == false){
		intersect_pacman = true;
	}
	
	
}
