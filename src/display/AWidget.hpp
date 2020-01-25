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
	AWidget() {}
	virtual ~AWidget() {}
	virtual void displayData() = 0;
	virtual void setTopLeft(coords) = 0;
	virtual void setBottomRight(coords) = 0;
	virtual coords getSize() = 0;
};

#endif
