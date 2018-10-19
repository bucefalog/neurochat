#include "Resource.h"


Resource::Resource() {

}
Resource::Resource(const std::string resource_id, const std::string &resource_class)
{
	hResource = FindResource(nullptr, resource_id.c_str(), resource_class.c_str());
	//hMemory = LoadResource(nullptr, hResource);
	printf("result: %d\n", hResource ? 1 : 0);
	//p.size_bytes = SizeofResource(nullptr, hResource);
	//p.ptr = LockResource(hMemory);
}


Resource::~Resource()
{
}

bool Resource::isValid() {
	return hResource != 0;
}


