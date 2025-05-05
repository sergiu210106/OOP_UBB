#pragma once
#include "service.h"
class UI {
private:
	Service& srv;
	void showMenu();
	void addUI();
	void removeUI();
	void printAll() const;
public:
	UI(Service& srv) :srv{ srv } {};
	void run();
};