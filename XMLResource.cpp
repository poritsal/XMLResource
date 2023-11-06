#include "XMLResource.h"

iterator XMLResource::begin() {
    return Elements.begin();
}

iterator XMLResource::end() {
    return Elements.end();
}

iterator XMLResource::Find(const int& val) {
    for (iterator it = begin(); it != end(); ++it) {
        if ((*it)->GetVal() == val) {
            return it;
        }
    }
    return end();
}

iterator XMLResource::Find(const std::string& tag) {
    for (iterator it = begin(); it != end(); ++it) {
        if ((*it)->GetTag() == tag) {
            return it;
        }
    }
    return end();
}

iterator XMLResource::Add(const std::string& tag, const int& value, const iterator& parent) {
    std::shared_ptr<XMLElement> node = std::make_shared<XMLElement>(tag, value, *parent);
    (*parent)->AddChild(node);

    try {
        Elements.push_back(node);
    }
    catch (...) {
        (*parent)->EraseChild(node);
        throw;
    }

    return --Elements.end();
}

bool XMLResource::Erase(iterator it) {
    if ((*it)->GetParent().expired()) {
        return false;
    }

    (*it)->ChildrenToParent();
    (*it)->GetParent().lock()->EraseChild(*it);
    Elements.erase(it);
    return true;
}

std::unique_ptr<XMLResource> XMLResource::Create(const std::string& path) {
    auto tree = std::unique_ptr<XMLResource>(new XMLResource());
    tree->Load(path);
    return tree;
}

void XMLResource::Load(const std::string& path) {
    std::ifstream input;
    input.open(path, std::ios::in);

    if (!input.is_open()) {
        throw LoadError("file open error");
    }

    std::string word;
    std::weak_ptr<XMLElement> parent;
    std::list<std::shared_ptr<XMLElement>> newElements;
    while (input >> word) {
        if (word[0] == '<' && word[word.size() - 1] == '>') {
            if (word[1] == '/') {
                if (parent.lock()->GetTag() != word.substr(2, word.size() - 3)) {
                    throw LoadError("the opening tag name does not match the closing tag");
                }
                parent = parent.lock()->GetParent();
            }
            else {
                word = word.substr(1, word.size() - 2);
                int value;

                if (!(input >> value)) {
                    throw LoadError("value type error");
                }

                std::shared_ptr<XMLElement> node = std::make_shared<XMLElement>(word, value, parent);
                if (!parent.expired()) {
                    parent.lock()->AddChild(node);
                }
                newElements.push_back(node);
                parent = node;
            }
        }
        else {
            throw LoadError("opening tag not found");
        }
    }

    Elements = newElements;
}

void XMLResource::Save(const std::string& path) {
    std::ofstream output;
    output.open(path, std::ios::out);
    if (!Elements.empty()) {
        (*Elements.begin())->Save(output);
    }
}