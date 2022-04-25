#ifndef TEST1_ENTITY_H
#define TEST1_ENTITY_H


class Entity {
private:
public:
    float dx, dy, frame, speed, x, y, speed_animation, move_timer = 0;
    int  width, width_attack, height, height_attack, health, height_simple, damage = 0;
    bool dir, is_attack = false, is_ground = false,life=true;

    String name;
    Texture texture;
    Sprite sprite;
    Entity(float X, float Y, int W,int H, String Name){
        width = W;
        height = H;
        x = X;
        y = Y;
        name = Name;
        texture.loadFromFile("C:\\Users\\Honor MagicBook Pro\\CLionProjects\\test1\\texture\\" + Name);
        sprite.setTexture(texture);

    }
     void InteractWorld(int dir) {
        for (int i = ((y) / SIZE_OF_BLOCK); i < ((y + height) / SIZE_OF_BLOCK); i++) {
            for (int j = (x / SIZE_OF_BLOCK); j < ((x+ width) / SIZE_OF_BLOCK) ; j++) {
                if (TileMap[i][j] == '1') {
                    if (dy > 0 && dir == 1) {
                        y = ((i) * SIZE_OF_BLOCK) - height ;
                        dy = 0;
                        is_ground = true;
                        count_jump = 0;
                    }
                    if (dy < 0 && dir == 1) {
                        y = (i * SIZE_OF_BLOCK) + SIZE_OF_BLOCK;
                        dy = 0;
                    }
                    if (dx > 0 && dir == 0) {
                        x = (j * SIZE_OF_BLOCK) - width;
                        dx = 0;
                    }
                    if (dx < 0 && dir == 0) {
                        x = (j * SIZE_OF_BLOCK) + SIZE_OF_BLOCK;
                        dx = 0;
                    }
                } else if (TileMap[i][j] != '1' && dir == 1){
                    is_ground = false;
                }
            }
        }
    }
};


#endif //TEST1_ENTITY_H
