#ifndef CONFIG_H
#define CONFIG_H

#define GAME_WIDTH 623
#define GAME_HEIGHT 1671
#define GAME_TITLE "太空大战v1.0"
#define GAME_RES_PATH "./res.qrc"
#define GAME_ICON ":/res/favicon.ico"
#define GAME_RATE 10


#define MAP_PATH ":/res/background.jpg"
#define MAP_SCROLL_SPEED 2


#define MYSHIP_PATH ":/res/myship.png"

#define BULLET_PATH ":/res/bullet1.png"
#define BULLET_SPEED 10
#define BULLET_NUM 30
#define BULLET_INTERVAL 20

#define ENEMY_PATH ":/res/enemyship(1).png"
#define ENEMY_SPEED 5
#define ENEMY_NUM 20
#define ENEMY_INTERVAL 100

#define BOOM_PATH ":/res/explosion%1.png"
#define BOOM_NUM 20
#define BOOM_MAX 4
#define BOOM_INTERVAL 5

#define SOUND_BACKGROUND ":/res/background.wav"
#define SOUND_BOOM ":/res/boom.wav"

#endif // CONFIG_H
