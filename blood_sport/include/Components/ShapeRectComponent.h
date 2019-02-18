#ifndef SHAPERECTCOMPONENT_H_INCLUDED
#define SHAPERECTCOMPONENT_H_INCLUDED

#include "ECS.h"

namespace ComponentType {

    class ShapeRect : public Component {
    public:
        float width;
        float height;

        ShapeRect(float w, float h) : width(w), height(h) {}

    };
}
#endif // SHAPERECTCOMPONENT_H_INCLUDED
