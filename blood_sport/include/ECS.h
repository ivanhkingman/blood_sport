#ifndef ECS_H
#define ECS_H

#include <map>
#include <vector>
#include <memory>

#include <iostream>

class Component;
class Entity;

inline int generateComponentTypeID() {
    static int ID = 0;
    std::cout << "Assigned new type ID: " << ID << std::endl;
    return ID++;
}

template <typename Type>
inline int getComponentTypeID() {
    static int ID = generateComponentTypeID();
    return ID;
}

class Component {
public:
    virtual ~Component() {}
    virtual void update() {}
    void setOwner(Entity* owner) {m_owner = owner;}

private:
    Entity* m_owner;
};

class Entity {

public:
    Entity() {std::cout << "--- New entity created ---" << std::endl;}
    void update() {for(auto& i : m_components) i.second->update();}

    template <typename ComponentType, typename... TypeArgs>
    void addComponent(TypeArgs&&... args) {
        auto newComponent = new ComponentType(std::forward<TypeArgs>(args)...);
        newComponent->setOwner(this);
        std::unique_ptr<Component> componentPointer{newComponent};
        m_components[getComponentTypeID<ComponentType>()] = std::move(componentPointer);
    }

    template <typename ComponentType>
    ComponentType& getComponent() {
        auto componentPointer = m_components[getComponentTypeID<ComponentType>()].get();
        return *static_cast<ComponentType*>(componentPointer);
    }

    template <typename ComponentType>
    bool hasComponent() {
        return m_components.find(getComponentTypeID<ComponentType>()) != m_components.end();
    }

private:
    std::map<int, std::unique_ptr<Component>> m_components;
};

class EntityManager {
public:
    void update() {}

    template <typename EntityType, typename... TypeArgs>
    void addEntity(TypeArgs&&... args) {
        auto newEntity = new EntityType(std::forward<TypeArgs>(args)...);
        std::shared_ptr<Entity> entityPointer{newEntity};
        m_entities.emplace_back(std::move(entityPointer));
    }

    template <typename ComponentType>
    std::vector<Entity*> filterEntities() {
        std::vector<Entity*> filteredEntities;
        for(auto i : m_entities) {
            if(i->hasComponent<ComponentType>()) {
                filteredEntities.push_back(i.get());
            }
        }
        return filteredEntities;
    }

private:
    std::vector<std::shared_ptr<Entity>> m_entities;
};

class ECSSystem {
public:
    virtual void update() {};

};



#endif // ECS_H
