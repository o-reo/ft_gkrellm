#ifndef AWIDGET_HPP
# define AWIDGET_HPP

#include "coords.h"

class AWidget
{
private:
	AWidget(AWidget const &src);
	AWidget &operator=(AWidget const &src);
protected:
public:
	AWidget() {};
	virtual ~AWidget() {};
	virtual void displayData() {};
	virtual void setTopLeft(coords) {};
	virtual void setBottomRight(coords) {};
	virtual coords getSize() = 0;
};

#endif
