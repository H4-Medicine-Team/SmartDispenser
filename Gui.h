#pragma once
class Gui {
protected:
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
};