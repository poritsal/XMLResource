#pragma once

#include <fstream>
#include <vector>

class XMLElement {
private:
    std::weak_ptr<XMLElement> Parent;
    std::string Tag;
    int Value;
    std::vector<std::shared_ptr<XMLElement>> Children;
public:
    XMLElement(const std::string& tag, const int& value, std::weak_ptr<XMLElement> parent) :
        Tag(tag), Value(value), Parent(parent) {};
    ~XMLElement() = default;
    void AddChild(std::shared_ptr<XMLElement> child);
    int GetVal();
    std::string GetTag();
    void SetParent(std::weak_ptr<XMLElement> new_parent);
    void EraseChild(std::shared_ptr<XMLElement> child);
    std::weak_ptr<XMLElement> GetParent();
    void Save(std::ofstream& file, const std::string& tab = "");
    void ChildrenToParent();
};