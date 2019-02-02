#ifndef MOVEMENTSPEEDCOMPONENT_H_INCLUDED
#define MOVEMENTSPEEDCOMPONENT_H_INCLUDED

class MovementSpeedComponent : public Component {
public:
    float movementSpeed;

    MovementSpeedComponent(float speed) : movementSpeed(speed) {}

    void update() override {}

};

#endif // MOVEMENTSPEEDCOMPONENT_H_INCLUDED
