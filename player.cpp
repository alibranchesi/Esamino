#include <iostream>
#include <string>

class Entity{
    public:
    virtual std::string GetName(){return "Entity";}
};

class Player:public Entity{
    private:
    std::string m_Name;
    public:
    Player(const std::string& name): m_Name(name) {}
    std::string GetName(){return m_Name;}
};

void Print(Entity* entity){
    std::cout<<entity->GetName()<<'\n';
}

int main(){
    Entity* e = new Entity();
    Print(e);

    Player* p = new Player("Alice");
    Print(p);
    
}