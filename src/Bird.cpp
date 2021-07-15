#include "Bird.hpp"

Bird::Bird(){
    pos = glm::vec3(ofRandomWidth(), ofRandomHeight(), 0);
    vel = glm::vec3(ofRandom(-2, 2), ofRandom(-2, 2), 0);
}

Bird::Bird(float x, float y){
    pos = glm::vec3(x, y, 0);
    vel = glm::vec3(ofRandom(-2, 2), ofRandom(-2, 2), 0);
}
//--------------------------------------------------------------

void Bird::update(vector<Bird>& birds){
    
    sepRange = r*5;
    
    glm::vec3 posSum(0,0,0);
    glm::vec3 velSum(0,0,0);
    glm::vec3 posDiffSum(0,0,0);
    
    int cohCnt = 0;
    int aliCnt = 0;
    int sepCnt = 0;
    
    // 1. see others to calculate forces
    for(int i=0; i<birds.size(); i++){
        Bird& other = birds[i];
        if(this == &other) continue;
        
        float d = distance(pos, other.pos);
        
        if(d < sepRange){
            posDiffSum += glm::normalize(pos - other.pos) / d;
            sepCnt++;
        }
        
        if(d < aliRange){
            velSum += other.vel;
            aliCnt++;
        }
        
        if(d < cohRange){
            posSum += other.pos;
            cohCnt++;
        }
    }
    
    
    // 2. limit forces and update value
    glm::vec3 frc(0, 0, 0);
    
    if(sepCnt > 0){
        glm::vec3 sepF = glm::normalize(posDiffSum) * maxSpeed - vel;
        if(length(sepF) > maxFrc){
            sepF = glm::normalize(sepF) * maxFrc;
        }
        frc += sepF * 1.5;
    }
    
    if(aliCnt > 0){
        glm::vec3 aliF = glm::normalize(velSum) * maxSpeed - vel;
        if(length(aliF) > maxFrc){
            aliF = glm::normalize(aliF) * maxFrc;
        }
        frc += aliF;
    }
    
    if(cohCnt > 0){
        glm::vec3 cohF = glm::normalize(posSum/cohCnt - pos) * maxSpeed - vel;
        if(length(cohF) > maxFrc){
            cohF = glm::normalize(cohF) * maxFrc;
        }
        frc += cohF;
    }
    
    // 3. stay in display
    glm::vec3 center(ofGetWidth()/2, ofGetHeight()/2, 0);
    if(pos.x < 10 || ofGetWidth()-10 < pos.x || pos.y < 10 || ofGetHeight()-10 < pos.y){
        glm::vec3 centerF = (center - pos) * maxSpeed - vel;
        if(length(centerF) > maxFrc){
            centerF = glm::normalize(centerF) * maxFrc;
        }
        frc += centerF;
    }
    
    if(length(frc) > maxFrc){
        frc = glm::normalize(frc) * maxFrc;
    }
    
    vel += frc;
    
}

//--------------------------------------------------------------

void Bird::move(){
    pos += vel;
}

//--------------------------------------------------------------

void Bird::draw(){
    ofPushMatrix();
    
    ofTranslate(pos.x, pos.y);
    float angle = atan2(vel.y, vel.x);
    ofRotateZRad(angle);
    shape.draw();
    
    glPopMatrix();
}
