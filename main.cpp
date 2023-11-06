#include "XMLResource.h"

int main() {
    const std::string path = "D:\\AppVS\\XMLResource\\xmlExample.txt";
    std::unique_ptr<XMLResource> resource = XMLResource::Create(path);

    iterator it = resource->Find(42);
    it = resource->Add("section3", 43, it);

    it = resource->Find("section1");
    bool erase = resource->Erase(it);

    resource->Save("D:\\AppVS\\XMLResource\\xmlResult.txt");
}
