#pragma once
#include <list>

class Command{
    list<string> alias;
    string name;
    int args;
    string description;
    string bRequired;
    string bImmediate;
    string fargs;
    string fdevUser;

    public:
    Command(const string alias);

}

class Target{
    string name;

    public:
    Target(const string name);
}

class Parsing{
    std::vector<Command> commands;
    std::vector<Target> targets;

    public:
    Parsing();
    void parse(int argc, char **argv);
}

