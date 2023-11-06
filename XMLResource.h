#pragma once

#include "XMLElement.h"
#include <memory>
#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>

struct LoadError : public std::exception {
	using std::exception::exception;
};

using iterator = std::list<std::shared_ptr<XMLElement>>::iterator;
class XMLResource {
private:
	XMLResource() = default;
	std::list<std::shared_ptr<XMLElement>> Elements;
public:
	XMLResource(XMLResource const&) = delete;
	XMLResource(XMLResource&&) = delete;
	XMLResource& operator=(XMLResource const&) = delete;
	XMLResource& operator=(XMLResource&&) = delete;
	static std::unique_ptr<XMLResource> Create(const std::string& path);
	void Save(const std::string& path);
	void Load(const std::string& path);
	iterator Add(const std::string& tag, const int& value, const iterator& parent);
	iterator Find(const int& val);
	iterator Find(const std::string& tag);
	bool Erase(iterator it);
	iterator begin();
	iterator end();
};

