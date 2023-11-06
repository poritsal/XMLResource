#include "XMLElement.h"

void XMLElement::AddChild(std::shared_ptr<XMLElement> child) {
    Children.push_back(child);
}

int XMLElement::GetVal() {
    return Value;
}

std::string XMLElement::GetTag() {
    return Tag;
}

void XMLElement::SetParent(std::weak_ptr<XMLElement> parent) {
    Parent = parent;
}

void XMLElement::EraseChild(std::shared_ptr<XMLElement> child) {
    Children.erase(std::find(Children.begin(), Children.end(), child));
}

std::weak_ptr<XMLElement> XMLElement::GetParent() {
    return Parent;
}

void XMLElement::Save(std::ofstream& file, const std::string& tab) {
    file << tab << "<" << Tag << ">" << std::endl;
    file << tab << "    " << Value << std::endl;
    for (const auto& child : Children) {
        child->Save(file, tab + "    ");
    }
    file << tab << "</" << Tag << ">" << std::endl;
}

void XMLElement::ChildrenToParent() {
    if (auto parentShared = Parent.lock()) {
        for (const auto& child : Children) {
            parentShared->AddChild(child);
            child->SetParent(Parent);
        }
    }
}