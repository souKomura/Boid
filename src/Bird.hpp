#pragma once
#include "ofMain.h"

class Bird{
public:
    Bird();
    Bird(float x, float y);
    
    void update(vector<Bird>& birds);
    void move();
    void draw();
    
    glm::vec3 pos;
    glm::vec3 vel;
    glm::vec3 acc;
    
    static float r;
    static ofMesh shape;
    
private:
    float maxSpeed = 8;
    float maxFrc = 0.5;
    
    float sepRange = 20;
    float aliRange = 40;
    float cohRange = 40;
};
