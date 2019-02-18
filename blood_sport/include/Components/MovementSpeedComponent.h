#ifndef MOVEMENTSPEEDCOMPONENT_H_INCLUDED
#define MOVEMENTSPEEDCOMPONENT_H_INCLUDED

namespace ComponentType {

    class MovementSpeed : public Component {
    public:
        float movementSpeed;

        MovementSpeed(float speed) : movementSpeed(speed) {}

    };
}

#endif // MOVEMENTSPEEDCOMPONENT_H_INCLUDED
