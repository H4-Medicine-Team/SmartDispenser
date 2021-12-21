#pragma once
#include <vector>
#include "Page.h"
class PageHandler 
{

public:
	void SetPages(std::vector<Page> pages) {
		pages = Pages;
	}
	std::vector<Page> GetPages() {
		return Pages;
	}
private:
	std::vector<Page> Pages;

};