// TinyXml2_Test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>  
#include "../tinyxml2/tinyxml2.h"

using namespace std;

void test1()
{
	tinyxml2::XMLDocument doc;
	doc.LoadFile("test.xml");

	tinyxml2::XMLElement *scene = doc.RootElement();
	tinyxml2::XMLElement *surface = scene->FirstChildElement("node");
	while (surface)
	{
		tinyxml2::XMLElement *surfaceChild = surface->FirstChildElement();
		const char* content;
		const tinyxml2::XMLAttribute *attributeOfSurface = surface->FirstAttribute();
	
		while (attributeOfSurface)
		{
			cout << attributeOfSurface->Name() << ":" << attributeOfSurface->Value() << " ";
			attributeOfSurface = attributeOfSurface->Next();
		}
		cout << endl;

		while (surfaceChild)
		{
			content = surfaceChild->GetText();
			surfaceChild = surfaceChild->NextSiblingElement();
			cout << content << endl;
		}
		surface = surface->NextSiblingElement();
	}
}

int main()
{
	test1();

	getchar();
    return 0;
}

