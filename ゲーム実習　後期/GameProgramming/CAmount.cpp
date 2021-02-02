#include"CAmount.h"

void CAmount::Update(){

}

void CAmount::Render(){
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
	CRectangle::Render();
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
}